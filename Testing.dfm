object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Testing'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 144
    Top = 116
    Width = 22
    Height = 15
    Caption = 'Null'
  end
  object Shape1: TShape
    Left = 144
    Top = 168
    Width = 30
    Height = 25
    Shape = stCircle
  end
  object Label2: TLabel
    Left = 172
    Top = 116
    Width = 10
    Height = 15
    Caption = '%'
  end
  object Button2: TButton
    Left = 16
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Iniciar Sistema'
    TabOrder = 0
  end
  object Button3: TButton
    Left = 16
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Humedad'
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button1: TButton
    Left = 16
    Top = 168
    Width = 106
    Height = 25
    Caption = 'Agua en el tanque'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button4: TButton
    Left = 16
    Top = 224
    Width = 106
    Height = 25
    Caption = 'Encender bomba'
    TabOrder = 3
    OnClick = Button1Click
  end
end
