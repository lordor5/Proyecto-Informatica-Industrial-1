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

double CaudalBombaActual = 0;
bool Control = AUTOMATICO;
double CaudalSolicitado;
//TStatusValve EstadoValvula = VALVE_OFF;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroup1Click(TObject* Sender)
{
    if (RadioGroup1->ItemIndex == 1) {
        CheckBox1->Visible = 0;
        CheckBox2->Visible = 0;
        Label1->Visible = 0;
        Label2->Visible = 0;
        Control = AUTOMATICO;
        Edit1->Visible = 0;
    } else {
        CheckBox1->Visible = 1;
        CheckBox2->Visible = 1;
        Label1->Visible = 1;
        Label2->Visible = 1;
        Control = MANUAL;
        Edit1->Visible = 1;
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject* Sender)
{
    Label15->Caption = ObtenerLaHora();

    //Leer la humedad del terreno y mostrarla
    int humedad = LeerHumedad();
    ProgressBar1->Position = humedad;
    Label6->Caption = humedad;

    //Leer el tanque de agua
    if (process_read_tank_sensor() == TANK_LOW)
        Shape5->Brush->Color = clRed;
    else
        Shape5->Brush->Color = clGreen;

    if (Control == AUTOMATICO) {
        CaudalBombaActual = CaudalBomba();
    }

    if (CaudalBombaActual == -1) {
        Label8->Caption = "Hay poca agua \r\n en el tanque";
    } else {
        Label8->Caption = CaudalBombaActual;
    }
    ProgressBar2->Position = CaudalBombaActual;

    //Valvula
    if (CaudalBombaActual > 0)
        Shape6->Brush->Color = clGreen;
    else
        Shape6->Brush->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject* Sender)
{
    if (Edit1->Text == "") {
        Label13->Visible = 1;
        CheckBox1->Checked = 0;
        return;
    }

    if (CheckBox1->Checked) {
        int res = BombaManual(CaudalSolicitado);

        if (res == -1) {
            Label8->Caption = "Hay poca agua \r\n en el tanque";
            CheckBox1->Checked = 0;
            return;
        }
        CaudalBombaActual = CaudalSolicitado;
    } else {
        int res = BombaManual(CaudalSolicitado);

        if (res == -1) {
            Label8->Caption = "Hay poca agua \r\n en el tanque";
            CheckBox1->Checked = 0;
            return;
        }
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
    if (text == "") {
        return;
    }
    CaudalSolicitado = text.ToDouble();

    if (CaudalSolicitado >= 0 && CaudalSolicitado <= 10) {
        Label13->Visible = false;
    } else {
        Label13->Visible = true;
    }
}
//---------------------------------------------------------------------------

