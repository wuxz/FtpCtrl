#if !defined(AFX_FTPPPG_H__E9B4B1D5_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_FTPPPG_H__E9B4B1D5_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// FtpPpg.h : Declaration of the CFtpPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CFtpPropPage : See FtpPpg.cpp.cpp for implementation.

class CFtpPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CFtpPropPage)
	DECLARE_OLECREATE_EX(CFtpPropPage)

// Constructor
public:
	CFtpPropPage();

// Dialog Data
	//{{AFX_DATA(CFtpPropPage)
	enum { IDD = IDD_PROPPAGE_FTP };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CFtpPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPPPG_H__E9B4B1D5_EB75_11D2_A7FE_0080C8763FA4__INCLUDED)
