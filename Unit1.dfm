object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 831
  ClientWidth = 1422
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Shape1: TShape
    Left = 32
    Top = 72
    Width = 257
    Height = 724
    Shape = stRoundRect
  end
  object Shape3: TShape
    Left = 632
    Top = 299
    Width = 345
    Height = 497
    Shape = stRoundRect
  end
  object Shape5: TShape
    Left = 848
    Top = 48
    Width = 41
    Height = 41
    Brush.Color = clRed
    Shape = stCircle
  end
  object Shape6: TShape
    Left = 848
    Top = 112
    Width = 41
    Height = 41
    Brush.Color = clRed
    Shape = stCircle
  end
  object Label1: TLabel
    Left = 712
    Top = 328
    Width = 187
    Height = 41
    Caption = 'Modo Manual'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -30
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Image1: TImage
    Left = 672
    Top = 588
    Width = 281
    Height = 181
  end
  object Label2: TLabel
    Left = 672
    Top = 480
    Width = 74
    Height = 15
    Caption = 'Flujo Deseado'
    Visible = False
  end
  object Label3: TLabel
    Left = 111
    Top = 184
    Width = 28
    Height = 15
    Caption = '100%'
  end
  object Label4: TLabel
    Left = 111
    Top = 746
    Width = 16
    Height = 15
    Caption = '0%'
  end
  object Label5: TLabel
    Left = 48
    Top = 112
    Width = 230
    Height = 32
    Caption = 'Humedad del terreno'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Shape4: TShape
    Left = 336
    Top = 72
    Width = 257
    Height = 724
    Shape = stRoundRect
  end
  object Label6: TLabel
    Left = 157
    Top = 464
    Width = 36
    Height = 20
    Caption = '100%'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 456
    Top = 168
    Width = 34
    Height = 15
    Caption = 'Label7'
  end
  object Label8: TLabel
    Left = 456
    Top = 738
    Width = 34
    Height = 23
    Caption = 'Label7'
  end
  object Label9: TLabel
    Left = 368
    Top = 450
    Width = 34
    Height = 15
    Caption = 'Label7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 32
    Top = 24
    Width = 161
    Height = 33
    Caption = 'Inicializar sistema'
    TabOrder = 0
  end
  object ProgressBar1: TProgressBar
    Left = 72
    Top = 184
    Width = 33
    Height = 577
    Orientation = pbVertical
    Position = 60
    TabOrder = 1
  end
  object RadioGroup1: TRadioGroup
    Left = 744
    Top = 184
    Width = 185
    Height = 66
    Caption = 'Modo de funcionamiento'
    ItemIndex = 1
    Items.Strings = (
      'Manual'
      'Automoatico')
    TabOrder = 2
    OnClick = RadioGroup1Click
  end
  object ScrollBar1: TScrollBar
    Left = 672
    Top = 533
    Width = 281
    Height = 20
    PageSize = 0
    TabOrder = 3
    Visible = False
  end
  object CheckBox1: TCheckBox
    Left = 672
    Top = 389
    Width = 145
    Height = 28
    Caption = 'Abrir v'#225'vula'
    TabOrder = 4
    Visible = False
  end
  object Edit1: TEdit
    Left = 1072
    Top = 106
    Width = 193
    Height = 23
    TabOrder = 5
    Text = 'Edit1'
  end
  object ProgressBar2: TProgressBar
    Left = 417
    Top = 168
    Width = 33
    Height = 585
    Orientation = pbVertical
    Position = 30
    TabOrder = 6
  end
  object Timer1: TTimer
    Left = 1008
    Top = 48
  end
end
