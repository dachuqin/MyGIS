; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAtlasView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Atlas.h"
LastPage=0

ClassCount=11
Class1=CAtlasApp
Class2=CAtlasDoc
Class3=CAtlasView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_POLYGONSTYLE_DIALOG
Class5=CAboutDlg
Resource2=CG_IDR_POPUP_ATLAS_VIEW
Class6=DataTransDlg
Resource3=IDD_LAYERCTRLDLG_DIALOG
Class7=CSplashWnd
Resource4=CG_IDR_POPUP_MAIN_FRAME
Class8=CLayerCtrlDlg
Resource5=IDR_MAINFRAME
Class9=CLayerAttri
Resource6=IDR_TOOLBAR_VIEW
Class10=CPOLYGONSTYLE
Class11=CLAYERSHOW
Resource7=IDD_ABOUTBOX
Resource8=IDD_DATATRANSDLG_DIALOG
Resource9=IDD_LAYERATTRI_DIALOG
Resource10=IDD_LAYERSHOW_DIALOG

[CLS:CAtlasApp]
Type=0
HeaderFile=Atlas.h
ImplementationFile=Atlas.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CAtlasApp

[CLS:CAtlasDoc]
Type=0
HeaderFile=AtlasDoc.h
ImplementationFile=AtlasDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_FILE_SAVEBMP

[CLS:CAtlasView]
Type=0
HeaderFile=AtlasView.h
ImplementationFile=AtlasView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_MENU_ANNO


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENU_ANNO
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Atlas.cpp
ImplementationFile=Atlas.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVEBMP
Command4=ID_MENU_DATATRANS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_APP_EXIT
Command9=ID_MENU_ZOOMIN
Command10=ID_MENU_ZOOMOUT
Command11=ID_MENU_PAN
Command12=ID_MENU_FULLMAP
Command13=ID_MENU_ZOOMIN_BYRECT
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_MENU_LAYERMANAGE
Command17=ID_MENU_DISTANCE
Command18=ID_MENU_AREA
Command19=ID_APP_ABOUT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DATATRANSDLG_DIALOG]
Type=1
Class=DataTransDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_IMPORT,button,1342242816
Control4=IDC_BUTTON_EXPORT,button,1342242816
Control5=IDC_EDIT1,edit,1484849280
Control6=IDC_STATIC,static,1342308864
Control7=IDC_STATIC,static,1342308864
Control8=IDC_EDIT_IMPORT,edit,1350631552
Control9=IDC_EDIT_EXPORT,edit,1350631552
Control10=IDC_PROGRESS1,msctls_progress32,1350565888
Control11=IDC_STATIC,static,1342308864

[CLS:DataTransDlg]
Type=0
HeaderFile=DataTransDlg.h
ImplementationFile=DataTransDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=DataTransDlg
VirtualFilter=dWC

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

[DLG:IDD_LAYERCTRLDLG_DIALOG]
Type=1
Class=CLayerCtrlDlg
ControlCount=10
Control1=IDC_Layer_LIST,listbox,1352728835
Control2=IDC_DELETE_LAYER,button,1342242817
Control3=IDC_DOWN_Layer,button,1342242817
Control4=IDC_STATIC,button,1342177287
Control5=IDC_ADD_LAYER,button,1342373889
Control6=IDC_Edit,button,1342242817
Control7=IDOK,button,1342242817
Control8=IDC_LAYER_INFO,button,1342242817
Control9=IDC_UP_Layer,button,1342373889
Control10=IDC_STATIC,button,1342177287

[CLS:CLayerCtrlDlg]
Type=0
HeaderFile=LayerCtrlDlg.h
ImplementationFile=LayerCtrlDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_UP_Layer
VirtualFilter=dWC

[DLG:IDD_LAYERATTRI_DIALOG]
Type=1
Class=CLayerAttri
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_Layer_Name,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_CHECK1,button,1342373891
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_Layer_Style,button,1342242816
Control10=IDOK,button,1342242816
Control11=IDCANCEL,button,1342242816

[CLS:CLayerAttri]
Type=0
HeaderFile=LayerAttri.h
ImplementationFile=LayerAttri.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLayerAttri

[DLG:IDD_POLYGONSTYLE_DIALOG]
Type=1
Class=CPOLYGONSTYLE
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDGE_STYLE,combobox,1344340226
Control6=IDC_EDGE_WIDTH,combobox,1344340226
Control7=IDC_EDGE_COLOR,edit,1350633600
Control8=IDC_FILL_COLOR,edit,1350633600
Control9=IDC_SEL_EDGE_COLOR,button,1342242816
Control10=IDC_SEL_FILL_COLOR,button,1342242816
Control11=IDOK,button,1342242816
Control12=IDCANCEL,button,1342242816

[CLS:CPOLYGONSTYLE]
Type=0
HeaderFile=POLYGONSTYLE.h
ImplementationFile=POLYGONSTYLE.cpp
BaseClass=CDialog
Filter=D
LastObject=CPOLYGONSTYLE
VirtualFilter=dWC

[CLS:CLAYERSHOW]
Type=0
HeaderFile=LAYERSHOW.h
ImplementationFile=LAYERSHOW.cpp
BaseClass=CDialog
Filter=D
LastObject=CLAYERSHOW

[DLG:IDD_LAYERSHOW_DIALOG]
Type=1
Class=CLAYERSHOW
ControlCount=1
Control1=IDC_LAYERTREE,SysTreeView32,1350631471

[TB:IDR_TOOLBAR_VIEW]
Type=1
Class=?
Command1=ID_MENU_ZOOMIN
Command2=ID_MENU_ZOOMOUT
Command3=ID_MENU_FULLMAP
Command4=ID_MENU_PAN
Command5=ID_MENU_DISTANCE
CommandCount=5

[MNU:CG_IDR_POPUP_MAIN_FRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_MENU_ZOOMOUT
Command3=ID_MENU_ZOOMOUT
Command4=ID_MENU_PAN
Command5=ID_MENU_FULLMAP
Command6=ID_MENU_DISTANCE
Command7=ID_MENU_AREA
CommandCount=7

[MNU:CG_IDR_POPUP_ATLAS_VIEW]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
CommandCount=3

