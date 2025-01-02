//---------------------------------------------------------------------------

#pragma hdrstop

#include "Data.h"
#include "Process.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


bool Control = AUTOMATICO;
TStatusValve EstadoValvula = VALVE_OFF;

int humedadMax = 70;
int humedadMin = 40;

// Algoritmo PID
int CaudalBomba() {

	if (process_read_tank_sensor() == TANK_LOW) {
		return -1;
	}

	int CaudalBomba = -0.3*LeerHumedad()+22;

	if (CaudalBomba > 10)
		CaudalBomba = 10;
	else if (CaudalBomba < 0)
		CaudalBomba = 0;

	return CaudalBomba;
}

UnicodeString ObtenerLaHora(void) {
	TDateTime now = TDateTime::CurrentDateTime();
	UnicodeString timeStr = now.FormatString("hh:nn:ss");
	return timeStr ;
}

int LeerHumedad(void) {
	//Convert volts to %
	int humudity = process_read_humidity_sensor() * 20.0;

	if (humudity < 0) {
		return 0;
	} else if (humudity > 100) {
		return 100;
	}
	return humudity;
}

int BombaManual(double Caudal) {
	if (process_read_tank_sensor() == TANK_LOW) {
		return -1;
	}
	process_write_pump_flow_actuator(Caudal);

    return 1;
}