//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
<<<<<<< HEAD
=======
enum {Manual, Automatico};
>>>>>>> 51a5dad62957c52457a884e2cabe2abaf12da1b3
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TShape *Shape3;
	TButton *Button1;
	TProgressBar *ProgressBar1;
	TShape *Shape5;
	TShape *Shape6;
	TTimer *Timer1;
	TRadioGroup *RadioGroup1;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TLabel *Label2;
	TEdit *Edit1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TShape *Shape4;
	TLabel *Label6;
	TProgressBar *ProgressBar2;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TMainMenu *Menu;
	TMenuItem *Abrirtesting1;
	TMenuItem *Abrirtesting2;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);




private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif