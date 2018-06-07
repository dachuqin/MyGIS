# Microsoft Developer Studio Project File - Name="Atlas" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Atlas - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Atlas.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Atlas.mak" CFG="Atlas - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Atlas - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Atlas - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Atlas - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Atlas - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Shlwapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Atlas - Win32 Release"
# Name "Atlas - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Atlas.cpp
# End Source File
# Begin Source File

SOURCE=.\Atlas.rc
# End Source File
# Begin Source File

SOURCE=.\AtlasDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\AtlasView.cpp
# End Source File
# Begin Source File

SOURCE=.\DataTransDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoAnno.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoLayer.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoLine.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoMap.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoObject.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoPoint.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoPolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\LayerAttri.cpp
# End Source File
# Begin Source File

SOURCE=.\LayerCtrlDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LAYERSHOW.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\POLYGONSTYLE.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="D:\实习\final+\final\Atlas\AppFace.h"
# End Source File
# Begin Source File

SOURCE=.\Atlas.h
# End Source File
# Begin Source File

SOURCE=.\AtlasDoc.h
# End Source File
# Begin Source File

SOURCE=.\AtlasView.h
# End Source File
# Begin Source File

SOURCE=.\DataTransDlg.h
# End Source File
# Begin Source File

SOURCE=.\GeoAnno.h
# End Source File
# Begin Source File

SOURCE=.\GeoLayer.h
# End Source File
# Begin Source File

SOURCE=.\GeoLine.h
# End Source File
# Begin Source File

SOURCE=.\GeoMap.h
# End Source File
# Begin Source File

SOURCE=.\GeoObject.h
# End Source File
# Begin Source File

SOURCE=.\GeoPoint.h
# End Source File
# Begin Source File

SOURCE=.\GeoPolygon.h
# End Source File
# Begin Source File

SOURCE=.\LayerAttri.h
# End Source File
# Begin Source File

SOURCE=.\LayerCtrlDlg.h
# End Source File
# Begin Source File

SOURCE=.\LAYERSHOW.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\POLYGONSTYLE.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Atlas.ico
# End Source File
# Begin Source File

SOURCE=.\res\Atlas.rc2
# End Source File
# Begin Source File

SOURCE=.\res\AtlasDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\BITMAP1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00003.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\juli.bmp
# End Source File
# Begin Source File

SOURCE=.\res\manyou.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pan.bmp
# End Source File
# Begin Source File

SOURCE=.\res\query.bmp
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=".\res\tab6[1].bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\wuhandaxue.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zoomin.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zoomout.bmp
# End Source File
# Begin Source File

SOURCE=".\res\大智慧.ico"
# End Source File
# Begin Source File

SOURCE=".\res\图形1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\武大.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Atlas : {72ADFD6C-2C39-11D0-9903-00A0C91BC942}
# 	1:23:CG_IDR_POPUP_MAIN_FRAME:108
# 	1:23:CG_IDR_POPUP_ATLAS_VIEW:109
# End Section
# Section Atlas : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:103
# 	2:21:SplashScreenInsertKey:4.0
# End Section
