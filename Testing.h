//---------------------------------------------------------------------------

#ifndef TestingH
#define TestingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Unit1.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

extern bool sistemaInicado;

class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button2;
	TButton *Button3;
	TLabel *Label1;
	TButton *Button1;
	TShape *Shape1;
	TLabel *Label2;
	TButton *Button4;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
