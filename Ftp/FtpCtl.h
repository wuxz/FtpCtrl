#if !defined(AFX_FTPCTL_H__E9B4B1D3_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_FTPCTL_H__E9B4B1D3_EB75_11D2_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// FtpCtl.h : Declaration of the CFtpCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl : See FtpCtl.cpp for implementation.
#include "ftpsession.h"

class CFtpCtrl : public COleControl
{
	DECLARE_DYNCREATE(CFtpCtrl)

// Constructor
public:
	CFtpCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtpCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FormatSysErrorMsg();
	CString m_strErrorInfo;
	BOOL SetSessionOptions();
	long m_nConnectTimeout, m_nDataReceiveTimeout, m_nDataSendTimeout;
	CFtpSession m_ftpSession;
	CString m_strPassword, m_strUserName, m_strHostName;

	~CFtpCtrl();

	BEGIN_OLEFACTORY(CFtpCtrl)        // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CFtpCtrl)

	DECLARE_OLETYPELIB(CFtpCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CFtpCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CFtpCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CFtpCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CFtpCtrl)
	afx_msg long GetConnectTimeout();
	afx_msg void SetConnectTimeout(long nNewValue);
	afx_msg long GetDataReceiveTimeOut();
	afx_msg void SetDataReceiveTimeOut(long nNewValue);
	afx_msg long GetDataSendTimeout();
	afx_msg void SetDataSendTimeout(long nNewValue);
	afx_msg BSTR GetUserName();
	afx_msg void SetUserName(LPCTSTR lpszNewValue);
	afx_msg BSTR GetPassword();
	afx_msg void SetPassword(LPCTSTR lpszNewValue);
	afx_msg BSTR GetHostName();
	afx_msg void SetHostName(LPCTSTR lpszNewValue);
	afx_msg BSTR GetErrorInfo();
	afx_msg BOOL GetFile(LPCTSTR strRemoteName, LPCTSTR strLocalName);
	afx_msg BOOL PutFile(LPCTSTR RemoteName, LPCTSTR strLocalName);
	afx_msg BOOL RemoveFile(LPCTSTR strRemoteName);
	afx_msg BSTR FindFile(LPCTSTR strFindName);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CFtpCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CFtpCtrl)
	dispidConnectTimeout = 1L,
	dispidDataReceiveTimeOut = 2L,
	dispidDataSendTimeout = 3L,
	dispidUserName = 4L,
	dispidPassword = 5L,
	dispidHostName = 6L,
	dispidErrorInfo = 7L,
	dispidGetFile = 8L,
	dispidPutFile = 9L,
	dispidRemoveFile = 10L,
	dispidFindFile = 11L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPCTL_H__E9B4B1D3_EB75_11D2_A7FE_0080C8763FA4__INCLUDED)
