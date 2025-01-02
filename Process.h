//- Process.h ---------------------------------------------------------
#ifndef processH
#define processH

//Función para inicializar la tarjeta
void process_init(void);

// Tanque de agua
enum TStatusTank {TANK_OK, TANK_LOW};
TStatusTank process_read_tank_sensor(void);  // ¿Hay agua suficiente en tanque?


// Valvula
enum TStatusValve {VALVE_ON, VALVE_OFF};
void process_write_valve_actuator(TStatusValve state);  // activar o desactivar la valvula


void process_write_pump_flow_actuator(double flow);  //Starting at flow Q, the pump will be activated with the volts necessary for its operation.

double process_read_humidity_sensor(void); // reads humidity

// Función para leer el estado en que se encuentra el sensor digital
//int process_read_sensor(void);
// Para dar mayor claridad al programa
//enum {LED_ON, LED_OFF};

// Función para obtener el valor de la temperatura
//double process_read_temperature(void);


//void process_analogOutput(double out_volts);
#endif
//---------------------------------------------------------------------
