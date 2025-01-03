//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
#include "Process.h"

enum {MANUAL, AUTOMATICO};
float CaudalBomba(void);

TTime ObtenerLaHora(void);

float LeerHumedad(void);

TStatusValve ControlarValvula(void);

int BombaManual(double Caudal);

double roundToDecimals(double value, int decimals);

int humedadMax = 70;
int humedadMin = 40;
bool Control = AUTOMATICO;
TStatusValve Valvula = VALVE_OFF;
void ControlarValvula(TStatusValve estado);

#endif

