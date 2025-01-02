//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
#include "Process.h"

enum {MANUAL, AUTOMATICO};
int CaudalBomba(void);

UnicodeString ObtenerLaHora(void);

int LeerHumedad(void);

TStatusValve ControlarValvula(void);

int BombaManual(double Caudal);

#endif
