//---------------------------------------------------------------------------

#ifndef InterfazH
#define InterfazH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.WinXPickers.hpp>
#include <Vcl.Imaging.pngimage.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
  __published: // IDE-managed Components
    TShape* Shape1;
    TShape* Shape3;
    TButton* Button1;
    TProgressBar* ProgressBar1;
    TShape* Shape5;
    TShape* Shape6;
    TTimer* Timer1;
    TRadioGroup* RadioGroup1;
    TLabel* Label1;
    TCheckBox* CheckBox1;
    TLabel* Label2;
    TEdit* Edit1;
    TLabel* Label3;
    TLabel* Label4;
    TLabel* Label5;
    TShape* Shape4;
    TLabel* Label6;
    TProgressBar* ProgressBar2;
    TLabel* Label7;
    TLabel* Label9;
    TLabel* Label10;
    TLabel* Label11;
    TLabel* Label12;
    TLabel* Label13;
    TLabel* Label14;
    TLabel* Label15;
    TTimePicker* TimePicker1;
    TLabel* Label16;
    TCheckBox* CheckBox2;
	TButton *Button2;
	TLabel *Lalbel7;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *Edit2;
	TEdit *Edit3;
	TImage *Image1;
    void __fastcall RadioGroup1Click(TObject* Sender);
    void __fastcall Button1Click(TObject* Sender);
    void __fastcall Timer1Timer(TObject* Sender);
    void __fastcall CheckBox1Click(TObject* Sender);
    void __fastcall CheckBox2Click(TObject* Sender);
    void __fastcall Edit1Change(TObject* Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall TimePicker1Change(TObject *Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif

