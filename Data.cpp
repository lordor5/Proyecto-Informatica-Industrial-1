//---------------------------------------------------------------------------

#pragma hdrstop

#include "Data.h"
#include "Process.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "Interfaz.cpp"

#include <iostream>
#include <cmath>

TStatusValve EstadoValvula = VALVE_OFF;

// Algoritmo PID
float CaudalBomba() {

	if (process_read_tank_sensor() == TANK_LOW) {
		return -1;
	}

	double a = 10.0/(humedadMax - humedadMin); // a = 0.3
	double b = a*humedadMin + 10; //-a * humedadMin + b = 10

	//Form1->Label17->Caption = a;
	//Form1->Label18->Caption = b;

	float CaudalBomba = -a*LeerHumedad() + b;

	if (CaudalBomba > 10)
		CaudalBomba = 10;
	else if (CaudalBomba < 0)
		CaudalBomba = 0;



	process_write_pump_flow_actuator(CaudalBomba);
	return CaudalBomba;
}

TTime ObtenerLaHora(void) {
	TDateTime now = TDateTime::CurrentDateTime();
	UnicodeString timeStr = now.FormatString("hh:nn:ss");
	return timeStr ;
}

float LeerHumedad(void) {
	//Convert volts to %
	float humudity = process_read_humidity_sensor() * 20.0;

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

void ControlarValvula(TStatusValve estado) {
	process_write_valve_actuator(estado);
}
double roundToDecimals(double value, int decimals) {
	double factor = std::pow(10.0, decimals);
	//Form1->Label18->Caption = std::round(value * factor) / factor;
	return std::round(value * factor) / factor;
}
