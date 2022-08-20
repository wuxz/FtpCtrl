// FtpPpg.cpp : Implementation of the CFtpPropPage property page class.

#include "stdafx.h"
#include "Ftp.h"
#include "FtpPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CFtpPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CFtpPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CFtpPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CFtpPropPage, "FTP.FtpPropPage.1",
	0xe9b4b1c6, 0xeb75, 0x11d2, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// CFtpPropPage::CFtpPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CFtpPropPage

BOOL CFtpPropPage::CFtpPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_FTP_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CFtpPropPage::CFtpPropPage - Constructor

CFtpPropPage::CFtpPropPage() :
	COlePropertyPage(IDD, IDS_FTP_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CFtpPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CFtpPropPage::DoDataExchange - Moves data between page and properties

void CFtpPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CFtpPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CFtpPropPage message handlers
