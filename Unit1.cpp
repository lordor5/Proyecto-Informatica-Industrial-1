//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
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
ScrollBar1->Visible = 0;
Label1->Visible = 0;
Label2->Visible = 0;



} else {
CheckBox1->Visible = 1;
ScrollBar1->Visible = 1;
Label1->Visible = 1;
Label2->Visible = 1;



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
}

}
//---------------------------------------------------------------------------



