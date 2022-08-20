// FtpCtl.cpp : Implementation of the CFtpCtrl ActiveX Control class.

#include "stdafx.h"
#include "Ftp.h"
#include "FtpCtl.h"
#include "FtpPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CFtpCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CFtpCtrl, COleControl)
	//{{AFX_MSG_MAP(CFtpCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CFtpCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CFtpCtrl)
	DISP_PROPERTY_EX(CFtpCtrl, "ConnectTimeout", GetConnectTimeout, SetConnectTimeout, VT_I4)
	DISP_PROPERTY_EX(CFtpCtrl, "DataReceiveTimeOut", GetDataReceiveTimeOut, SetDataReceiveTimeOut, VT_I4)
	DISP_PROPERTY_EX(CFtpCtrl, "DataSendTimeout", GetDataSendTimeout, SetDataSendTimeout, VT_I4)
	DISP_PROPERTY_EX(CFtpCtrl, "UserName", GetUserName, SetUserName, VT_BSTR)
	DISP_PROPERTY_EX(CFtpCtrl, "Password", GetPassword, SetPassword, VT_BSTR)
	DISP_PROPERTY_EX(CFtpCtrl, "HostName", GetHostName, SetHostName, VT_BSTR)
	DISP_PROPERTY_EX(CFtpCtrl, "ErrorInfo", GetErrorInfo, SetNotSupported, VT_BSTR)
	DISP_FUNCTION(CFtpCtrl, "GetFile", GetFile, VT_BOOL, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CFtpCtrl, "PutFile", PutFile, VT_BOOL, VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CFtpCtrl, "RemoveFile", RemoveFile, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CFtpCtrl, "FindFile", FindFile, VT_BSTR, VTS_BSTR)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CFtpCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CFtpCtrl, COleControl)
	//{{AFX_EVENT_MAP(CFtpCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CFtpCtrl, 1)
	PROPPAGEID(CFtpPropPage::guid)
END_PROPPAGEIDS(CFtpCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CFtpCtrl, "FTP.FtpCtrl.1",
	0xe9b4b1c5, 0xeb75, 0x11d2, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CFtpCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DFtp =
		{ 0xe9b4b1c3, 0xeb75, 0x11d2, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };
const IID BASED_CODE IID_DFtpEvents =
		{ 0xe9b4b1c4, 0xeb75, 0x11d2, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwFtpOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CFtpCtrl, IDS_FTP, _dwFtpOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::CFtpCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CFtpCtrl

BOOL CFtpCtrl::CFtpCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_FTP,
			IDB_FTP,
			afxRegApartmentThreading,
			_dwFtpOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("Ftp.lic");

static const WCHAR BASED_CODE _szLicString[] =
	L"Copyright (c) 1999 BHM";


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::CFtpCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

BOOL CFtpCtrl::CFtpCtrlFactory::VerifyUserLicense()
{
	return TRUE;
//	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
//		_szLicString);
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::CFtpCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CFtpCtrl::CFtpCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::CFtpCtrl - Constructor

CFtpCtrl::CFtpCtrl()
{
	InitializeIIDs(&IID_DFtp, &IID_DFtpEvents);

	m_nConnectTimeout = 5000;
	m_nDataReceiveTimeout = m_nDataSendTimeout = 60000;
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::~CFtpCtrl - Destructor

CFtpCtrl::~CFtpCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::OnDraw - Drawing function

void CFtpCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillSolidRect(&rcBounds, RGB(125, 125, 0));
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::DoPropExchange - Persistence support

void CFtpCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
	PX_Long(pPX, "ConnectTimeOut", m_nConnectTimeout, 5000);
	PX_Long(pPX, "DataReceiveTimeOut", m_nDataReceiveTimeout, 60000);
	PX_Long(pPX, "DataSendTimeOut", m_nDataSendTimeout, 60000);
	PX_String(pPX, "UserName", m_strUserName, "");
	PX_String(pPX, "Password", m_strPassword, "");
	PX_String(pPX, "HostName", m_strHostName, "");
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::OnResetState - Reset control to default state

void CFtpCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	m_strErrorInfo.Empty();
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl::AboutBox - Display an "About" box to the user

void CFtpCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_FTP);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CFtpCtrl message handlers

BOOL CFtpCtrl::GetFile(LPCTSTR strRemoteName, LPCTSTR strLocalName) 
{
	m_strErrorInfo.Empty();

	if (!SetSessionOptions())
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
		return FALSE;
	}

	CFtpConnection * pConn = NULL;

	try
	{
		pConn = m_ftpSession.GetFtpConnection(m_strHostName, m_strUserName,
			m_strPassword);
	}
	catch(CInternetException * pEx)
	{
		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);
		m_strErrorInfo = szErr;
		pEx->Delete();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif

		return FALSE;
	}

	BOOL bRet = pConn->GetFile(strRemoteName, strLocalName, FALSE);
	if (!bRet)
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
	}

	pConn->Close();
	delete pConn;
	pConn = NULL;
#ifdef _DEBUG
	if (bRet)
		AfxMessageBox("Download Ok");
#endif
	
	return bRet;
}

BOOL CFtpCtrl::PutFile(LPCTSTR strRemoteName, LPCTSTR strLocalName)
{
	m_strErrorInfo.Empty();

	if (!SetSessionOptions())
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
		return FALSE;
	}

	CFtpConnection * pConn = NULL;

	try
	{
		pConn = m_ftpSession.GetFtpConnection(m_strHostName, m_strUserName,
			m_strPassword);
	}
	catch(CInternetException * pEx)
	{
		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);
		m_strErrorInfo = szErr;
		pEx->Delete();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif

		return FALSE;
	}

	BOOL bRet = pConn->PutFile(strLocalName, strRemoteName);
	if (!bRet)
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
	}

	pConn->Close();
	delete pConn;
	pConn = NULL;
#ifdef _DEBUG
	if (bRet)
		AfxMessageBox("Upload Ok");
#endif

	return bRet;
}

BOOL CFtpCtrl::RemoveFile(LPCTSTR strRemoteName) 
{
	m_strErrorInfo.Empty();

	if (!SetSessionOptions())
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
		return FALSE;
	}

	CFtpConnection * pConn = NULL;

	try
	{
		pConn = m_ftpSession.GetFtpConnection(m_strHostName, m_strUserName,
			m_strPassword);
	}
	catch(CInternetException * pEx)
	{
		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);
		m_strErrorInfo = szErr;
		pEx->Delete();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif

		return FALSE;
	}

	BOOL bRet = pConn->Remove(strRemoteName);
	if (!bRet)
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
	}

	pConn->Close();
	delete pConn;
	pConn = NULL;
#ifdef _DEBUG
	if (bRet)
		AfxMessageBox("Deletion Ok");
#endif

	return bRet;
}

BSTR CFtpCtrl::FindFile(LPCTSTR strFindName) 
{
	m_strErrorInfo.Empty();

	CString strResult;

	if (!SetSessionOptions())
	{
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
		
		strResult = "Error";
		return strResult.AllocSysString();
	}

	CFtpConnection * pConn = NULL;

	try
	{
		pConn = m_ftpSession.GetFtpConnection(m_strHostName, m_strUserName,
			m_strPassword);
	}
	catch(CInternetException * pEx)
	{
		TCHAR szErr[1024];
		pEx->GetErrorMessage(szErr, 1024);
		m_strErrorInfo = szErr;
		pEx->Delete();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif
	
		strResult = "Error";
		return strResult.AllocSysString();
	}

	CFtpFileFind ftpFind(pConn);

	BOOL bContinue = ftpFind.FindFile(strFindName);
	if (!bContinue)
	{
		// the directory is empty; just close up and return.
		ftpFind.Close();
		pConn->Close();
		delete pConn;
		pConn = NULL;
		FormatSysErrorMsg();
#ifdef _DEBUG
		AfxMessageBox(m_strErrorInfo);
#endif

		return strResult.AllocSysString();
	}

	CString strFileName;
	while (bContinue)
	{
		// FindNextFile muxt be called before info can be gleaned from ftpFind
		try
		{
			bContinue = ftpFind.FindNextFile();
			strFileName = ftpFind.GetFileName();
		}
		catch(CInternetException * pEx)
		{
			TCHAR szErr[1024];
			pEx->GetErrorMessage(szErr, 1024);
			m_strErrorInfo = szErr;
			pEx->Delete();
	#ifdef _DEBUG
			AfxMessageBox(m_strErrorInfo);
	#endif
	
			strResult = "Error";
			return strResult.AllocSysString();
		}

		if (!ftpFind.IsDirectory())
		{
			strResult += strFileName;
			strResult += ' ';
		}
	}

	ftpFind.Close();
	pConn->Close();
	delete pConn;
	pConn = NULL;
#ifdef _DEBUG
	AfxMessageBox("Finding Ok");
#endif
	return strResult.AllocSysString();
}

long CFtpCtrl::GetConnectTimeout() 
{
	return m_nConnectTimeout;
}

void CFtpCtrl::SetConnectTimeout(long nNewValue) 
{
	if (nNewValue > 0)
	{
		m_nConnectTimeout = nNewValue;
		SetModifiedFlag();
		BoundPropertyChanged(dispidConnectTimeout);
	}
}

long CFtpCtrl::GetDataReceiveTimeOut() 
{
	return m_nDataReceiveTimeout;
}

void CFtpCtrl::SetDataReceiveTimeOut(long nNewValue) 
{
	if (nNewValue > 0)
	{
		m_nDataReceiveTimeout = nNewValue;
		SetModifiedFlag();
		BoundPropertyChanged(dispidDataReceiveTimeOut);
	}
}

long CFtpCtrl::GetDataSendTimeout() 
{
	return m_nDataSendTimeout;
}

void CFtpCtrl::SetDataSendTimeout(long nNewValue) 
{
	if (nNewValue > 0)
	{
		m_nDataSendTimeout = nNewValue;
		SetModifiedFlag();
		BoundPropertyChanged(dispidDataSendTimeout);
	}
}

BOOL CFtpCtrl::SetSessionOptions()
{
	if (!m_ftpSession.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, 
		m_nConnectTimeout * 1000))
		return FALSE;

	if (!m_ftpSession.SetOption(INTERNET_OPTION_DATA_SEND_TIMEOUT, 
		m_nDataSendTimeout * 1000))
		return FALSE;

	if (!m_ftpSession.SetOption(INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, 
		m_nDataReceiveTimeout * 1000))
		return FALSE;

	return TRUE;
}

BSTR CFtpCtrl::GetUserName() 
{
	return m_strUserName.AllocSysString();
}

void CFtpCtrl::SetUserName(LPCTSTR lpszNewValue) 
{
	m_strUserName = lpszNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidUserName);
}

BSTR CFtpCtrl::GetPassword() 
{
	return m_strPassword.AllocSysString();
}

void CFtpCtrl::SetPassword(LPCTSTR lpszNewValue) 
{
	m_strPassword = lpszNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidPassword);
}

BSTR CFtpCtrl::GetHostName() 
{
	return m_strHostName.AllocSysString();
}

void CFtpCtrl::SetHostName(LPCTSTR lpszNewValue) 
{
	m_strHostName = lpszNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidHostName);
}

BSTR CFtpCtrl::GetErrorInfo() 
{
	return m_strErrorInfo.AllocSysString();
}

void CFtpCtrl::FormatSysErrorMsg()
{
	TCHAR * lpMsgBuf = "";

	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS, NULL, GetLastError(), MAKELANGID(
		LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf, 0, NULL );// Process any inserts in lpMsgBuf.
	
	m_strErrorInfo = lpMsgBuf;
	
	// Free the buffer.
	LocalFree(lpMsgBuf);
}
