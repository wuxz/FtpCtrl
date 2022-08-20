#if !defined(AFX_FTP_H__E9B4B1CB_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_FTP_H__E9B4B1CB_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Ftp.h : main header file for FTP.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtpApp : See Ftp.cpp for implementation.

class CFtpApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_H__E9B4B1CB_EB75_11D2_A7FE_0080C8763FA4__INCLUDED)
