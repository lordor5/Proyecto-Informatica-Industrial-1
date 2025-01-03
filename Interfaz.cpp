//---------------------------------------------------------------------------
#include <vcl.h>
#include "Process.h"
#include "Process.cpp"
#pragma hdrstop
#include "Interfaz.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;

float CaudalBombaActual = 0;
//bool Control = AUTOMATICO;
float CaudalSolicitado = 5;
bool CambiarCaudal = false;
TTime selectedTime; //= Form1->TimePicker1->Time;
//TStatusValve EstadoValvula = VALVE_OFF;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroup1Click(TObject* Sender)
{
    if (RadioGroup1->ItemIndex == 1) {
        CheckBox1->Visible = 0;
		Label2->Visible = 0;
		Control = AUTOMATICO;
		Label1->Caption = "Modo Automatico";
		Edit1->Visible = 0;

		Edit2->Visible = 1;
		Edit3->Visible = 1;
		Label17->Visible = 1;
		Label18->Visible = 1;

		Label16->Visible = 1;
		TimePicker1->Visible = 1;
        CheckBox2->Visible = 1;
    } else {
        CheckBox1->Visible = 1;
        CheckBox2->Visible = 1;
		Label1->Visible = 1;
		Label2->Visible = 1;
		Control = MANUAL;
		Edit1->Visible = 1;
		Label1->Caption = "Modo Manual";


		Edit2->Visible = 0;
		Edit3->Visible = 0;
		Label17->Visible = 0;
		Label18->Visible = 0;

		Label16->Visible = 0;
		TimePicker1->Visible = 0;
		CheckBox2->Visible = 0;

	}

}
//---------------------------------------------------------------------------
bool sistemaInicado = false;
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    if (sistemaInicado) {
        sistemaInicado = false;
        Button1->Caption = "Inicializar sistema";
    } else {
		sistemaInicado = true;
        Button1->Caption = "Parar sistema";
		process_init();
        Timer1->Enabled = true;
        RadioGroup1->Visible = 1;
	}

    selectedTime = TimePicker1->Time;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject* Sender)
{
    Label15->Caption = ObtenerLaHora();

    //Leer la humedad del terreno y mostrarla
    float humedad = LeerHumedad();
	ProgressBar1->Position = humedad;
	Label6->Caption = roundToDecimals(humedad,2);

    //Leer el tanque de agua
	if (process_read_tank_sensor() == TANK_LOW) {
		Shape5->Brush->Color = clRed;
		CaudalBombaActual = -1;
	}
    else
        Shape5->Brush->Color = clGreen;

	if (Control == AUTOMATICO) {

		if (selectedTime < ObtenerLaHora() || CheckBox2->Checked == 1) {
			CaudalBombaActual = CaudalBomba();
			CambiarCaudal = false;
			process_write_pump_flow_actuator(CaudalBombaActual);
		}

	} else {
		if (CambiarCaudal == false) {
			CambiarCaudal = true;
			CaudalBombaActual = 0;
        }

    }

    if (CaudalBombaActual == -1) {
		Label7->Caption = "Hay poca agua \r\n en el tanque";
    } else {
		Label7->Caption = roundToDecimals(CaudalBombaActual,2);
	}
	ProgressBar2->Position = roundToDecimals(CaudalBombaActual,2);

    //Valvula
	if (CaudalBombaActual > 0) {
		Shape6->Brush->Color = clGreen;
		Valvula = VALVE_ON;
    }
	else {
		Shape6->Brush->Color = clRed;
        Valvula = VALVE_OFF;
	 }
	ControlarValvula(Valvula);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject* Sender)
{

	if (CheckBox1->Checked) {
        int res = BombaManual(CaudalSolicitado);

        if (res == -1) {
			Label7->Caption = "Hay poca agua \r\n en el tanque";
            CheckBox1->Checked = 0;
            return;
        }
        CaudalBombaActual = CaudalSolicitado;
	} else {
        CaudalBombaActual = 0;
    }
}
void __fastcall TForm1::CheckBox2Click(TObject* Sender)
{
    if (CheckBox2->Checked)
        TimePicker1->Visible = false;
    else
        TimePicker1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject* Sender)
{
    // Assuming TEdit1 is your TEdit control

	UnicodeString text = Edit1->Text;
	if (text == "")
		return;


	if (text.ToDouble() >= 0 && text.ToDouble() <= 10) {
		Label13->Visible = false;
		CaudalSolicitado = text.ToDouble();
	}
	else {
        Label13->Visible = true;
	}

	//Label17->Caption = CaudalSolicitado;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    exit(0);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit2Change(TObject *Sender)
{
	UnicodeString text = Edit2->Text;
	if (text == "") {
		return;
	}
	humedadMax = text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
	UnicodeString text = Edit3->Text;
	if (text == "") {
		return;
	}
	humedadMin = text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimePicker1Change(TObject *Sender)
{
selectedTime = TimePicker1->Time;
}
//---------------------------------------------------------------------------



