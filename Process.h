//- Process.h ---------------------------------------------------------
#ifndef processH
#define processH


// Tanque de agua
enum {HIGH_WATER, LOW_WATER};
int process_read_water_tank(void);


// Valvula
enum {VALVULA_ON, VALVULA_OFF};
void process_write_valve(int state);


//Funci�n para inicializar la tarjeta
void process_init(void);
// Funci�n para leer el estado en que se encuentra el sensor digital
int process_read_sensor(void);
// Para dar mayor claridad al programa
enum {LED_ON, LED_OFF};

// Funci�n para obtener el valor de la temperatura
double process_read_temperature(void);


void process_analogOutput(double out_volts);
#endif
//---------------------------------------------------------------------