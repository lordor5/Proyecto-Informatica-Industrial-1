//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Process.h"
#include "Process.cpp"
#include "Testing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//bool sistemaInicado = false;
void __fastcall TForm2::Button2Click(TObject *Sender)
{
if (sistemaInicado) {
	sistemaInicado = false;
	Button2->Caption = "Inicializar sistema";
}
else {
	sistemaInicado = true;
	Button2->Caption = "Parar sistema";
	process_init();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
Label1->Caption = process_read_humidity();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
 if (process_read_water_tank()) {
	 Shape1->Brush->Color = clRed;
 } else {
     Shape1->Brush->Color = clGreen;
 }

}
//---------------------------------------------------------------------------