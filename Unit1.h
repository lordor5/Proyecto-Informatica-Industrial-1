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
	TScrollBar *ScrollBar1;
	TLabel *Label1;
	TImage *Image1;
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
	void __fastcall RadioGroup1Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
