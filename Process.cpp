//---------------------------------------------------------------------------

#pragma hdrstop

#include "Process.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


#include "Process.h"
#include <vcl.h>
//#include "NIDAQmx.h"
#define SS_FALSE_DAQ
#include "SimSeny/ss_nidaqmx.h"

//Define task to manage digital input port (P0)
TaskHandle input_sensor_task;
// digital outputs mirror
unsigned short int ultima_salida_digital=0xFF;
// digital actuator task
TaskHandle actuator_task;

// analog sensor task
TaskHandle humidity_sensor_task;

//
TaskHandle analog_output_task;


// process error reporting ---------------------------------------------
void process_error(int32 code, char *suffix) {
 AnsiString msg;
 char buff[200]; // buffer for the error message
 msg = "Error: ";
 msg = msg + suffix;
 msg = msg + "\n";
 msg = msg + "In: ";
 DAQmxGetErrorString (code, buff, 200); // get the error message
 msg = msg + buff;
 ShowMessage(msg);
 exit(1); // force the end of the application
}
// process initialization ----------------------------------------------
void process_init(void) {
	int32 daq_error;
	// digital sensor preparation
	// first, create an empty task
	daq_error = DAQmxCreateTask("sensor task",&input_sensor_task);

	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->1");
		// now, add channels to the task. In this example, add a complete port
		daq_error = DAQmxCreateDIChan(input_sensor_task, "DevX/port0","",DAQmx_Val_ChanForAllLines);

	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->2");

    // -- actuators task preparation
	daq_error = DAQmxCreateTask("actuator task", &actuator_task);

	if (daq_error != 0) process_error(daq_error,"process_init()");

	// task for reading complete port
	daq_error = DAQmxCreateDOChan (actuator_task, "DevX/port1","",DAQmx_Val_ChanForAllLines);

	// -- temperature sensor preparation
	daq_error = DAQmxCreateTask("temperature task",&humidity_sensor_task);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->temperature_1");

	daq_error = DAQmxCreateAIVoltageChan(humidity_sensor_task,"DevX/ai0","",DAQmx_Val_RSE, 0.0, 5.0, DAQmx_Val_Volts, NULL);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->temperature_2");


    //Configurar la salida analógica AO0
	daq_error = DAQmxCreateTask("Salida Analógica AO0",&analog_output_task);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->Digital Output 1");
	daq_error = DAQmxCreateAOVoltageChan(analog_output_task, "DevX/ao0", "", 0, 5.0,DAQmx_Val_Volts, NULL);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->Digital Output 2");
}
// read humidity sensor -----------------------------------------------
double process_read_humidity_sensor(void) {
	int32 daq_error;
	float64 voltage;
	// Read volts from temperature analog sensor
	daq_error = DAQmxReadAnalogScalarF64(humidity_sensor_task, 1.0, &voltage, NULL);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_read_temperature()");
	return voltage;
}
// write led actuator ------------------------------------------------
//0->on, 1->off
void process_write_valve_actuator(TStatusValve state) {
	int32 daq_error;
	if (state == VALVE_ON) {
		// Encender Led poniendo el bit P1.0 a valor "0"
		ultima_salida_digital = ultima_salida_digital & ~0x01;
	} else {
		// Apagar Led poniendo el bit P1.0 a valor "1”
		ultima_salida_digital = ultima_salida_digital | 0x01;
	}
	daq_error = DAQmxWriteDigitalScalarU32 (actuator_task, true, 0.0,ultima_salida_digital, NULL);

	if (daq_error != 0) process_error(daq_error,"process_write_led()");
}

// read water and return state ------------------------------------
TStatusTank process_read_tank_sensor(void) {
	int32 daq_error;
	uInt32 data_read;
	// task is started automatically, it is not necessary to start one
	// DAQmxStartTask() optional here

	daq_error = DAQmxReadDigitalScalarU32 (input_sensor_task, 0.0, &data_read, NULL);
	if (daq_error != 0)
		process_error(daq_error,"Error en input_read_overflow()");

	// DAQmxStopTask() optional

	if ((data_read & 0x01) == 0) //digital sensor at bit 0
		return(TANK_OK);
	 else
		return(TANK_LOW);
}
//--------------------------------------------------------------------

// Función para escribir en la salida analógica AO0 el voltaje especificado
void process_write_pump_flow_actuator(double flow)
{
    double volts = flow / 2 ;//Q = k · volts -> k = 2;

	if (volts > 5)
		volts = 5;
	else if (volts < 0)
		volts = 0;

	int32 daq_error;
	// Escribimos el voltaje especificado en la salida analógica AO0
	daq_error = DAQmxWriteAnalogScalarF64(analog_output_task, TRUE, 0, volts, NULL);
	if (daq_error != 0)
		process_error(daq_error,"Error en process_init()->process_analogOutput()");
}

