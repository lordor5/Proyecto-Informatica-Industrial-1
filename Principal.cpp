//---------------------------------------------------------------------------

#pragma hdrstop

#include "Principal.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void loop()
{
    //ENCENDER el control Automatico del riego
    if (LeerHumedad() < 40) {
        //EstadoValvula = VALVE_ON;
        //process_write_valve_actuator(EstadoValvula);
        //Label8->Caption = 10;
        //ProgressBar2->Position = 10;
    }
    //APAGAR el control Automatico del riego
    else if (LeerHumedad() > 70)
    {
        //process_write_pump_flow_actuator(CaudalBomba);
        //ProgressBar2->Position = CaudalBomba;
        //EstadoValvula = VALVE_OFF;
		//process_write_valve_actuator(EstadoValvula);
    }
}
