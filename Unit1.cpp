//---------------------------------------------------------------------------

#include <vcl.h>
#include "Process.h"
#include "Process.cpp"
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

double CaudalBomba = 0;
bool Control = AUTOMATICO;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex == 1){
		CheckBox1->Visible = 0;
		Label1->Visible = 0;
		Label2->Visible = 0;
		Control = AUTOMATICO;
	} else {
		CheckBox1->Visible = 1;
		Label1->Visible = 1;
		Label2->Visible = 1;
        Control = MANUAL;
	}
}
//---------------------------------------------------------------------------
bool sistemaInicado = false;
void __fastcall TForm1::Button1Click(TObject *Sender)
{

if (sistemaInicado) {
	sistemaInicado = false;
	Button1->Caption = "Inicializar sistema";
}
else {
	sistemaInicado = true;
	Button1->Caption = "Parar sistema";
	process_init();
	Timer1->Enabled = true;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	ProgressBar1->Position = process_read_humidity();
	Label6->Caption = process_read_humidity();

	if (process_read_water_tank())
		Shape5->Brush->Color = clRed;
	else
		Shape5->Brush->Color = clGreen;

	ProgressBar2->Position = CaudalBomba;
	Label8->Caption = CaudalBomba;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
		process_write_valve(VALVULA_ON);
	else
		process_write_valve(VALVULA_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	// Assuming TEdit1 is your TEdit control

	UnicodeString text = Edit1->Text;
	if (text == "") {
          return;
	}
	double NewCaudalBomba = text.ToDouble();

	if (NewCaudalBomba >= 0 && NewCaudalBomba <= 10) {
		CaudalBomba = NewCaudalBomba;
		process_analogOutput(CaudalBomba);
		Label13->Visible = false;
	}
	else {
		Label13->Visible = true;
	}

}
//---------------------------------------------------------------------------

