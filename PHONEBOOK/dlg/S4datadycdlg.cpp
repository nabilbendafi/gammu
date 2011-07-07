// S6DataDycDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\phonebook.h"
#include "S4DataDycDlg.h"
#include "NS4AddressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CS4DataDycDlg dialog

CS4DataDycDlg::CS4DataDycDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(IDD_DATA_DYC_S4, pParent)
{
	//{{AFX_DATA_INIT(CS4DataDycDlg)
	//}}AFX_DATA_INIT
	m_hFont = NULL;
	m_strAddress_ext.Empty();
	m_strAddress_Street.Empty();
	m_strAddress_City.Empty();
	m_strAddress_State.Empty();
	m_strAddress_Zip.Empty();
	m_strAddress_Country.Empty();
}
CS4DataDycDlg::~CS4DataDycDlg()
{
	if(m_hFont)
		::DeleteObject(m_hFont);
}

void CS4DataDycDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CS4DataDycDlg)
	DDX_Control(pDX, IDC_S6_COMBO3, m_cb3);
	DDX_Control(pDX, IDC_S6_EDIT3, m_ed3);
	DDX_Control(pDX, IDOK, m_rbnOK);
	DDX_Control(pDX, IDCANCEL, m_rbnCancel);
	DDX_Control(pDX, IDC_SC_TITLE, m_scTitle);
	DDX_Control(pDX, IDC_SC_STORAGE, m_scStorage);
	DDX_Control(pDX, IDC_SC_LASTNAME, m_scLastName);
	DDX_Control(pDX, IDC_SC_FIRSTNAME, m_scFirstName);
	DDX_Control(pDX, IDC_SC_DEFAULT, m_scDefault);
	DDX_Control(pDX, IDC_SC_NUMBER11, m_scNum11);
	DDX_Control(pDX, IDC_SC_NUMBER10, m_scNum10);
	DDX_Control(pDX, IDC_SC_NUMBER9, m_scNum9);
	DDX_Control(pDX, IDC_SC_NUMBER8, m_scNum8);
	DDX_Control(pDX, IDC_SC_NUMBER7, m_scNum7);
	DDX_Control(pDX, IDC_SC_NUMBER6, m_scNum6);
	DDX_Control(pDX, IDC_SC_NUMBER5, m_scNum5);
	DDX_Control(pDX, IDC_SC_NUMBER4, m_scNum4);
	DDX_Control(pDX, IDC_SC_NUMBER3, m_scNum3);
	DDX_Control(pDX, IDC_SC_NUMBER2, m_scNum2);
	DDX_Control(pDX, IDC_SC_NUMBER1, m_scNum1);
	DDX_Control(pDX, IDC_SC_S6DOT11, m_scDot11);
	DDX_Control(pDX, IDC_SC_S6DOT10, m_scDot10);
	DDX_Control(pDX, IDC_SC_S6DOT9, m_scDot9);
	DDX_Control(pDX, IDC_SC_S6DOT8, m_scDot8);
	DDX_Control(pDX, IDC_SC_S6DOT7, m_scDot7);
	DDX_Control(pDX, IDC_SC_S6DOT6, m_scDot6);
	DDX_Control(pDX, IDC_SC_S6DOT5, m_scDot5);
	DDX_Control(pDX, IDC_SC_S6DOT4, m_scDot4);
	DDX_Control(pDX, IDC_SC_S6DOT3, m_scDot3);
	DDX_Control(pDX, IDC_SC_S6DOT2, m_scDot2);
	DDX_Control(pDX, IDC_SC_S6DOT1, m_scDot1);
	DDX_Control(pDX, IDC_S6_EDIT10, m_ed10);
	DDX_Control(pDX, IDC_S6_EDIT9, m_ed9);
	DDX_Control(pDX, IDC_S6_EDIT8, m_ed8);
	DDX_Control(pDX, IDC_S6_EDIT7, m_ed7);
	DDX_Control(pDX, IDC_S6_EDIT6, m_ed6);
	DDX_Control(pDX, IDC_S6_EDIT5, m_ed5);
	DDX_Control(pDX, IDC_S6_EDIT4, m_ed4);
	DDX_Control(pDX, IDC_ED_LASTNAME, m_edLastName);
	DDX_Control(pDX, IDC_ED_FIRSTNAME, m_edFirstName);
	DDX_Control(pDX, IDC_S6_COMBO10, m_cb10);
	DDX_Control(pDX, IDC_S6_COMBO9, m_cb9);
	DDX_Control(pDX, IDC_S6_COMBO8, m_cb8);
	DDX_Control(pDX, IDC_S6_COMBO7, m_cb7);
	DDX_Control(pDX, IDC_S6_COMBO6, m_cb6);
	DDX_Control(pDX, IDC_S6_COMBO5, m_cb5);
	DDX_Control(pDX, IDC_S6_COMBO4, m_cb4);
	DDX_Control(pDX, IDC_S6_CHECK4, m_ch4);
	DDX_Control(pDX, IDC_S6_CHECK10, m_ch10);
	DDX_Control(pDX, IDC_S6_CHECK9, m_ch9);
	DDX_Control(pDX, IDC_S6_CHECK8, m_ch8);
	DDX_Control(pDX, IDC_S6_CHECK7, m_ch7);
	DDX_Control(pDX, IDC_S6_CHECK6, m_ch6);
	DDX_Control(pDX, IDC_S6_CHECK5, m_ch5);
	DDX_Control(pDX, IDC_RD_SIM, m_rdSIM);
	DDX_Control(pDX, IDC_RD_PHONE, m_rdME);
	DDX_Control(pDX, IDC_COMBO_DEFAULT, m_cbDefault);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CS4DataDycDlg, CBaseDlg)
	//{{AFX_MSG_MAP(CS4DataDycDlg)
	ON_CONTROL_RANGE(BN_CLICKED,IDC_S6_CHECK4,IDC_S6_CHECK11,OnCheckBtn)
	ON_BN_CLICKED(IDC_RD_SIM, OnRdSim)
	ON_BN_CLICKED(IDC_RD_PHONE, OnRdMobile)
	ON_CBN_SELCHANGE(IDC_S6_COMBO3, OnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_S6_COMBO4, OnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_S6_COMBO5, OnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_S6_COMBO6, OnSelchangeCombo6)
	ON_CBN_SELCHANGE(IDC_S6_COMBO7, OnSelchangeCombo7)
	ON_CBN_SELCHANGE(IDC_S6_COMBO8, OnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_S6_COMBO9, OnSelchangeCombo9)
	ON_CBN_SELCHANGE(IDC_S6_COMBO10, OnSelchangeCombo10)
	ON_CBN_DROPDOWN(IDC_S6_COMBO11, OnDropdownS6Combo8)
	ON_CBN_DROPDOWN(IDC_S6_COMBO10, OnDropdownS6Combo10)
	ON_CBN_DROPDOWN(IDC_S6_COMBO9, OnDropdownS6Combo9)
	ON_EN_SETFOCUS(IDC_S6_EDIT9, OnSetfocusS6Edit9)
	ON_EN_SETFOCUS(IDC_S6_EDIT10, OnSetfocusS6Edit10)
	ON_EN_SETFOCUS(IDC_S6_EDIT8, OnSetfocusS6Edit8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CS4DataDycDlg message handlers


void CS4DataDycDlg::OnCheckBtn(UINT nID) 
{
	int nIndex = nID-IDC_S6_CHECK4;
	BOOL bEnable = false;
	CCheckEx2* pCheck = (CCheckEx2*)GetDlgItem(nID);
	if(pCheck->GetCheck()) bEnable = TRUE;
	else  bEnable = FALSE;
	{
		CComboBox *pCombox = (CComboBox*)GetDlgItem(IDC_S6_COMBO4+nIndex);
		CMyEdit *pEdit = (CMyEdit*)GetDlgItem(IDC_S6_EDIT4+nIndex);
		pCombox->EnableWindow(bEnable);
		pEdit->EnableWindow(bEnable);
	}
	if(nIndex >=4)
	{
		switch(nIndex)
		{
		case 4:
			UpdateTextComboBox(&m_cb9,&m_cb10,&m_cb8);
			break;
		case 5:
			UpdateTextComboBox(&m_cb8,&m_cb10,&m_cb9);
			break;
		case 6:
			UpdateTextComboBox(&m_cb9,&m_cb8,&m_cb10);
			break;
		}
	}

	xSetDefaultCombo();	
	xSetSupportColumnLength();

}


void CS4DataDycDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CBaseDlg::OnCancel();
}

void CS4DataDycDlg::OnOK() 
{
	TCHAR szTxt[MAX_PATH];
	m_ed3.GetWindowText(szTxt,MAX_PATH);
	int iLength = _tcslen(szTxt);
	if(iLength == 0){
		if(al_GetSettingString(_T("public"),_T("IDS_ERR_NONUMBER"),theApp.m_szRes,szTxt))
			AfxMessageBox(szTxt);
		return;
	}

	CPhoneData data;
	DEQPHONEDATA deqData;
//	char szName[MAX_PATH];
//	szName[0] = '\0';
	//get sel default 
	int iSel = m_cbDefault.GetCurSel();
	m_cbDefault.GetLBText(iSel,szTxt);
	int iIndex = _ttoi(&szTxt[0]);

	memset(szTxt,0,sizeof(TCHAR) * MAX_PATH);
	//get name
	//set data type
	m_edLastName.GetWindowText(szTxt,MAX_PATH);
	if(_tcslen(szTxt) > 0)
	{
		data.SetType(PBK_Text_LastName);
		data.SetText(szTxt);
	//	wsprintf(szName,_T("%s"),szTxt);
		deqData.push_back(data);
	}

	m_edFirstName.GetWindowText(szTxt,MAX_PATH);
	if(_tcslen(szTxt) > 0)
	{
		data.SetType(PBK_Text_FirstName);
		data.SetText(szTxt);
	//	if(_tcslen(szName) == 0)
	//		wsprintf(szName,_T("%s"),szTxt);
	//	else
	//		wsprintf(szName,"%s %s",szName,szTxt);
		deqData.push_back(data);
	}
/*
	if(_tcslen(szName) > 0)
	{
		data.SetType(PBK_Text_Name);
		data.SetText(szName);
		deqData.push_back(data);
	}*/

/*	m_edCompany.GetWindowText(szTxt,MAX_PATH);
	if(_tcslen(szTxt) > 0)
	{
		data.SetType(PBK_Text_Company);
		data.SetText(szTxt);
		deqData.push_back(data);
	}*/


	CCheckEx *pCh[7] = {&m_ch4,&m_ch5,&m_ch6,&m_ch7,&m_ch8,&m_ch9,&m_ch10};
	CComboBox *pCb[7] = {&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8,&m_cb9,&m_cb10};
	CMyEdit *pEd[7] = {&m_ed4,&m_ed5,&m_ed6,&m_ed7,&m_ed8,&m_ed9,&m_ed10};

	//add default to deque
	if(iIndex == 3){	//combobox 3
		GSM_EntryType entryTye =(GSM_EntryType)(m_cb3.GetItemData(m_cb3.GetCurSel()));
		data.SetType(entryTye);
/*		switch(m_cb3.GetCurSel())
		{
		case 0:
			data.SetType(PBK_Number_General);
			break;
		case 1:
			data.SetType(PBK_Number_Mobile);
			break;
		case 2:
			data.SetType(PBK_Number_Home);
			break;
		case 3:
			data.SetType(PBK_Number_Work);
			break;
		case 4:
			data.SetType(PBK_Number_Fax);
			break;
		}*/
		m_ed3.GetWindowText(szTxt,MAX_PATH);
	}
	else{	//other
		if(pCh[iIndex - 4]->IsWindowEnabled() && pCh[iIndex - 4]->GetCheck())
		{
			GSM_EntryType entryTye =(GSM_EntryType)(pCb[iIndex - 4]->GetItemData(pCb[iIndex - 4]->GetCurSel()));
			data.SetType(entryTye);
/*
			switch(pCb[iIndex - 4]->GetCurSel())
			{
			case 0:
				data.SetType(PBK_Number_General);
				break;
			case 1:
				data.SetType(PBK_Number_Mobile);
				break;
			case 2:
				data.SetType(PBK_Number_Home);
				break;
			case 3:
				data.SetType(PBK_Number_Work);
				break;
			case 4:
				data.SetType(PBK_Number_Fax);
				break;
			}*/
			pEd[iIndex - 4]->GetWindowText(szTxt,MAX_PATH);
		}
	}
	data.SetText(szTxt);
	deqData.push_back(data);

	int defaultindex=-1;
	if(iIndex>3)
		defaultindex = iIndex-4;
	else 
		defaultindex = -1;

	int i = 0;
	for(i=0 ;i< 7 ;i++)
	{
		if( pCh[i]->GetCheck()&& i!= defaultindex)
		{
			pEd[i]->GetWindowText(szTxt,MAX_PATH);
			if(_tcslen(szTxt) > 0)
			{
				GSM_EntryType entryTye =(GSM_EntryType)(pCb[i]->GetItemData(pCb[i]->GetCurSel()));
			//	data.SetType(entryTye);
				if(entryTye == PBK_Text_Postal )
				{
						if(m_strAddress_ext.IsEmpty() == false)
						{
							data.SetType(PBK_Text_Custom1);
							data.SetText(m_strAddress_ext);
							deqData.push_back(data);
						}
						if(m_strAddress_Street.IsEmpty() == false)
						{
							data.SetType(PBK_Text_StreetAddress);
							data.SetText(m_strAddress_Street);
							deqData.push_back(data);
						}
						if(m_strAddress_City.IsEmpty() == false)
						{
							data.SetType(PBK_Text_City);
							data.SetText(m_strAddress_City);
							deqData.push_back(data);
						}
						if(m_strAddress_State.IsEmpty() == false)
						{
							data.SetType(PBK_Text_State);
							data.SetText(m_strAddress_State);
							deqData.push_back(data);
						}
						if(m_strAddress_Zip.IsEmpty() == false)
						{
							data.SetType(PBK_Text_Zip);
							data.SetText(m_strAddress_Zip);
							deqData.push_back(data);
						}
						if(m_strAddress_Country.IsEmpty() == false)
						{
							data.SetType(PBK_Text_Country);
							data.SetText(m_strAddress_Country);
							deqData.push_back(data);
						}
				}
				else
				{
					data.SetType(entryTye);
					data.SetText(szTxt);
					deqData.push_back(data);
				}
			}
		}
	}

	if(iIndex!=3)
	{
		m_ed3.GetWindowText(szTxt,MAX_PATH);
		if(_tcslen(szTxt) > 0)
		{
			GSM_EntryType entryTye =(GSM_EntryType)(m_cb3.GetItemData(m_cb3.GetCurSel()));
			data.SetType(entryTye);
			data.SetText(szTxt);
			deqData.push_back(data);
		}
	}

	for(DEQPHONEDATA::iterator iterDetain = m_deqDetainData.begin() ; iterDetain != m_deqDetainData.end() ; iterDetain++){
		deqData.push_back((*iterDetain));
	}

	m_pData->SetPhoneData(deqData);

	if(m_rdSIM.GetCheck())
		m_pData->SetStorageType(SIM_NAME);
	else
		m_pData->SetStorageType(MEMORY_NAME);

	CBaseDlg::OnOK();
}

void CS4DataDycDlg::OnRdSim() 
{
	m_rdSIM.SetCheck(1);
	m_rdME.SetCheck(0);	

	for(int i = 3 ; i < 10 ; i ++)
		xEnableControl(i,FALSE);
	m_cbDefault.EnableWindow(FALSE);
	xSetCombo2Item();
}

void CS4DataDycDlg::OnRdMobile() 
{
	m_rdSIM.SetCheck(0);
	m_rdME.SetCheck(1);	

	for(int i = 3 ; i < 10 ; i ++)
		xEnableControl(i,TRUE);
	m_cbDefault.EnableWindow(TRUE);
	xSetCombo2Item();
}

void CS4DataDycDlg::OnSelchangeCombo10() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
//	xSetDefaultCombo();	
}


void CS4DataDycDlg::OnSelchangeCombo4() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	xSetDefaultCombo();	
	
}

void CS4DataDycDlg::OnSelchangeCombo5() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	xSetDefaultCombo();	
	
}

void CS4DataDycDlg::OnSelchangeCombo6() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	xSetDefaultCombo();	
}

void CS4DataDycDlg::OnSelchangeCombo7() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	xSetDefaultCombo();	
	
}

void CS4DataDycDlg::OnSelchangeCombo8() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	
}

void CS4DataDycDlg::OnSelchangeCombo9() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	
}

BOOL CS4DataDycDlg::OnInitDialog() 
{
	CBaseDlg::OnInitDialog();
	int iSize = 0;
	TCHAR szName[MAX_PATH];
	CFont* pFont = NULL;
	if(GetProfileFont(NULL,NULL,iSize,szName))
	{
		iSize = -iSize ;
		if(m_hFont==NULL)
			m_hFont = GetFontEx(szName,iSize);
		pFont = CFont::FromHandle(m_hFont);
	}
	//profiel path 
	Tstring sProfile(theApp.m_szSkin);
	sProfile += Tstring(_T("organize\\S4DataDycDlg.ini"));
	//load static
	CStaticEx *pStaticEx[27] = {&m_scTitle,&m_scLastName,&m_scFirstName,&m_scStorage,
		&m_scNum1,&m_scNum2,&m_scNum3,&m_scNum4,&m_scNum5,&m_scNum6,&m_scNum7,&m_scNum8,&m_scNum9,&m_scNum10,&m_scNum11,
		&m_scDot1,&m_scDot2,&m_scDot3,&m_scDot4,&m_scDot5,&m_scDot6,&m_scDot7,&m_scDot8,&m_scDot9,&m_scDot10,&m_scDot11,
		&m_scDefault};
	TCHAR szScSec[27][32] = {_T("title_sc"),_T("lastname_sc"),_T("firstname_sc"),_T("storage_sc"),
		_T("num1_sc"),_T("num2_sc"),_T("num3_sc"),_T("num4_sc"),_T("num5_sc"),_T("num6_sc"),_T("num7_sc"),_T("num8_sc"),_T("num9_sc"),_T("num10_sc"),_T("num11_sc"),
		_T("dot1_sc"),_T("dot2_sc"),_T("dot3_sc"),_T("dot4_sc"),_T("dot5_sc"),_T("dot6_sc"),_T("dot7_sc"),_T("dot8_sc"),_T("dot9_sc"),_T("dot10_sc"),_T("dot11_sc"),
		_T("default_sc")};
	TCHAR szScID[27][32] = {_T(""),_T("IDS_N_LASTNAME"),_T("IDS_N_FIRSTNAME"),_T("IDS_STORAGE"),
		_T("IDS_1"),_T("IDS_2"),_T("IDS_3"),_T("IDS_4"),_T("IDS_5"),_T("IDS_6"),_T("IDS_7"),_T("IDS_8"),_T("IDS_9"),_T("IDS_10"),_T("IDS_11"),
		_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),_T("IDS_DOT"),
		_T("IDS_SETDEFAULT")};
	if(m_iMode == 0)
		_tcscpy(szScID[0],_T("IDS_NEWCONTACT"));
	else if(m_iMode == 1)
		_tcscpy(szScID[0],_T("IDS_EDITCONTACT"));
	else if(m_iMode == 2)
		_tcscpy(szScID[0],_T("IDS_VIEWCONTACT"));
	for(int i = 0 ; i < 27 ; i ++)
		GetStaticFromSetting(pStaticEx[i],szScSec[i],szScID[i],const_cast<TCHAR*>(sProfile.c_str()));

	//load button 
	CRescaleButton	*pButton[2] = {&m_rbnOK,&m_rbnCancel};
	TCHAR szBnSec[2][32] = {_T("ok"),_T("cancel")};
	TCHAR szBnID[2][32] = {_T("IDS_N_OK"),_T("IDS_CANCEL")};
	for(i = 0 ; i < 2 ; i ++)
		GetButtonFromSetting(pButton[i],szBnSec[i],szBnID[i],0,const_cast<TCHAR*>(sProfile.c_str()));

	//load checkbox
	CCheckEx2	*pCheck[7] = {&m_ch4,&m_ch5,&m_ch6,&m_ch7,&m_ch8,&m_ch9,&m_ch10};
	TCHAR szChSec[7][32] = {_T("ch4"),_T("ch5"),_T("ch6"),_T("ch7"),_T("ch8"),_T("ch9"),_T("ch10")};
	for(i = 0 ; i < 7 ; i ++){
		GetCheckFromSetting(pCheck[i],szChSec[i],0,const_cast<TCHAR*>(sProfile.c_str()));
		pCheck[i]->SetCheck(0);
	}

	//load radio
	CRadioEx	*pRadio[2] = {&m_rdSIM,&m_rdME};
	TCHAR szRdSec[2][32] = {_T("sim_rd"),_T("me_rd")};
	TCHAR szRdID[2][32] = {_T("IDS_SIMCARD"),_T("IDS_MOBILE")};
	for(i = 0 ; i < 2 ; i ++){
		GetRadioFromSetting(pRadio[i],szRdSec[i],szRdID[i],const_cast<TCHAR*>(sProfile.c_str()));
		pRadio[i]->SetCheck(0);
	}
	//set other control position and size
	CWnd *pWnd[19] = {&m_cb3,&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8,&m_cb9,&m_cb10,&m_cbDefault,
		&m_edLastName,&m_edFirstName,&m_ed3,
		&m_ed4,&m_ed5,&m_ed6,&m_ed7,&m_ed8,&m_ed9,&m_ed10};
	TCHAR szWndSec[19][32] = {_T("cb3"),_T("cb4"),_T("cb5"),_T("cb6"),_T("cb7"),_T("cb8"),_T("cb9"),_T("cb10"),_T("default_cb"),
		_T("lastname_ed"),_T("firstname_ed"),_T("ed3"),
		_T("ed4"),_T("ed5"),_T("ed6"),_T("ed7"),_T("ed8"),_T("ed9"),_T("ed10")};
	for(i = 0 ; i < 19 ; i ++){
		CRect rect;
		al_GetSettingRect(szWndSec[i],_T("rect"),const_cast<TCHAR *>(sProfile.c_str()),rect);
		pWnd[i]->MoveWindow(rect);
		if(pFont)pWnd[i]->SetFont(pFont);
	}
	
	//set group size and pos
	CRect rect;
	if(al_GetSettingRect(_T("group"),_T("rect"),const_cast<TCHAR *>(sProfile.c_str()),rect))
		GetDlgItem(IDC_GP)->MoveWindow(rect);

	//get panel color
	al_GetSettingColor(_T("panel"),_T("color"),const_cast<TCHAR *>(sProfile.c_str()),m_crBg);

	CRect rcTitle;
	CalcStaticRealRect(&m_scTitle,rcTitle);
	int iSpace = 0;
	al_GetSettingInt(_T("title_sc"),_T("space"),const_cast<TCHAR*>(sProfile.c_str()),iSpace);
	rcTitle.right += iSpace * 2;
	m_scTitle.GetWindowRect(&rect);
	ScreenToClient(&rect);
	rect.right = rect.left + rcTitle.Width();
	m_scTitle.MoveWindow(rect);

	//Set window pos
	if(al_GetSettingRect(_T("panel"),_T("rect"),const_cast<TCHAR *>(sProfile.c_str()),rect)){
		UINT uStyle = ::GetWindowLong(GetSafeHwnd(),GWL_STYLE);
		UINT uStyleEx = ::GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE);
		if(AdjustWindowRectEx(rect,uStyle,FALSE,uStyleEx)){
			MoveWindow(rect);
			CenterWindow();
		}
	}
	//set button pos and size
	CRect rc,rcBtn1,rcBtn2;
	m_rbnCancel.GetWindowRect(&rcBtn1);
	ScreenToClient(&rcBtn1);
	m_rbnOK.GetWindowRect(&rcBtn2);
	ScreenToClient(&rcBtn2);
	if(rcBtn1.Width() > rcBtn2.Width())
		rcBtn2.right = rcBtn2.left + rcBtn1.Width();
	else
		rcBtn1.right = rcBtn1.left + rcBtn2.Width();

	m_ed4.GetWindowRect(&rc);
	ScreenToClient(&rc);
	
	rcBtn1.OffsetRect(rc.right - rcBtn1.right  ,0);
	m_rbnCancel.MoveWindow(rcBtn1);

	rcBtn2.OffsetRect(rcBtn1.left - 20 - rcBtn2.right ,0);
	m_rbnOK.MoveWindow(rcBtn2);

	//Set combobox string
	xSetComboItem();
	xSetDefaultControl();
	//set title 
	TCHAR szText[MAX_PATH];
	BOOL bRet = FALSE;
	if(m_iMode == 0){	//new
		bRet = al_GetSettingString(_T("public"),_T("IDS_NEWCONTACT"),theApp.m_szRes,szText);
		xSetDefaultEnableControl();
		xSetRadioBtn();
	}
	else if(m_iMode == 1){	//edit
		bRet = al_GetSettingString(_T("public"),_T("IDS_EDITCONTACT"),theApp.m_szRes,szText);
		m_rdME.EnableWindow(FALSE);
		m_rdSIM.EnableWindow(FALSE);
		//initialize control data
		xSetDataToDlgCtrl();
	}
	else if(m_iMode == 2){	//view file
		//hide save button 
		m_rbnOK.ShowWindow(SW_HIDE);

		al_GetSettingString(_T("public"),_T("IDS_OK"),theApp.m_szRes,szText);
		m_rbnCancel.SetWindowText(szText);

		//set title
		bRet = al_GetSettingString(_T("public"),_T("IDS_VIEWCONTACT"),theApp.m_szRes,szText);
		//initialize control data
		xSetDataToDlgCtrl();

		//gray all control
		for( i = 0 ; i < 2 ; i ++){
			pRadio[i]->EnableWindow(FALSE);
			pRadio[i]->SetCheck(0);
		}
		for( i = 0 ; i < 19 ; i ++ )
			pWnd[i]->EnableWindow(FALSE);
		for( i = 0 ; i < 7 ; i ++)
			pCheck[i]->EnableWindow(FALSE);

	}
	if(bRet)
		SetWindowText(szText);

	if(((CPhoneBookApp*)afxGetApp())->m_bNotSupportSM && m_iMode != 2)
	{
		m_rdME.EnableWindow(FALSE);
		m_rdSIM.EnableWindow(FALSE);
		OnRdMobile();
	}
	xSetDefaultCombo();	
	m_cbDefault.SetCurSel(0);

	xSetSupportColumnLength();
	xSetCombo2Item();
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CS4DataDycDlg::xSetDefaultCombo()
{
	//get default combobox cur sel
	int iDefSel = m_cbDefault.GetCurSel();
	//get the cursel string
	TCHAR szText[MAX_PATH];
	m_cbDefault.GetLBText(iDefSel,szText);
	//get the first char to know which one has been selected
	TCHAR szKey = szText[0];
	int iKeySel = _ttoi(&szKey);
	//reset string
	m_cbDefault.ResetContent();

	CComboBox *pCb[5] = {&m_cb3,&m_cb4,&m_cb5,&m_cb6,&m_cb7};
	CCheckEx *pCh[4] = {&m_ch4,&m_ch5,&m_ch6,&m_ch7};

	bool bRet = false;
	for(int i = 0 ;i < 5 ; i ++){
		int iSel = pCb[i]->GetCurSel();
		pCb[i]->GetLBText(iSel,szText);
		TCHAR szFormat[MAX_PATH];
		wsprintf(szFormat,_T("%d."),i+3);
		Tstring sTxt = Tstring(szFormat) + Tstring(szText);
		if( i == 0){
			int iIndex = m_cbDefault.AddString(sTxt.c_str());
			if(iKeySel == i + 3){
				m_cbDefault.SetCurSel(iIndex);
				bRet = true;
			}
		}
		else{
			if(pCh[i - 1]->GetCheck()){
				int iIndex = m_cbDefault.AddString(sTxt.c_str());
				if(iKeySel == i + 3){
					m_cbDefault.SetCurSel(iIndex);
					bRet = true;
				}
			}
		}		
	}
	if(!bRet)
		m_cbDefault.SetCurSel(0);
}

/*
void CS4DataDycDlg::SetMode(int iMode)
{
	m_iMode = iMode;
}

void CS4DataDycDlg::SetData(CCardPanel *pData)
{
	m_pData = pData;
}

void CS4DataDycDlg::SetIsME(int iFlag)
{
	m_iIsME = iFlag;
}
*/
void CS4DataDycDlg::xSetDataToDlgCtrl()
{
	//set name
/*	TCHAR szName[MAX_PATH];
	memset(szName,0,sizeof(TCHAR) * MAX_PATH);
	m_pData->GetName(szName);
	m_edName.SetWindowText(szName);*/
	CString strName;
	strName.Empty();
	DEQPHONEDATA *pDeqData = m_pData->GetPhoneData();
/*	int nType[10] ={PBK_Number_General,PBK_Number_Home,PBK_Number_Work,PBK_Number_Mobile,PBK_Number_Mobile_Home,PBK_Number_Mobile_Work,
			PBK_Number_Fax,PBK_Number_Fax_Home,PBK_Number_Fax_Work,PBK_Number_Pager};
	int nComboIndex[10] ={0,1,2,3,4,5,6,7,8,9};
	int nType2[11] ={PBK_Text_JobTitle,PBK_Text_Email,PBK_Text_Email_Home,PBK_Text_Email_Work,
		PBK_Text_URL,PBK_Text_URL_Home,PBK_Text_URL_Work,PBK_Text_Note,PBK_Text_Postal,PBK_Text_Postal_Home,PBK_Text_Postal_Work};
	int nComboIndex2[11] ={0,1,2,3,4,5,6,7,8,9,10};*/
	int i =0;
	bool bFindType = false;
	GSM_EntryType cb3entryType = PBK_Text_Company;
	//set data to control
	CCheckEx *pAddressCh = NULL;
	CComboBox *pAddressCb = NULL;
	CMyEdit *pAddressEdit = NULL;
	int iNumber = 0,iData = 0;
	for(DEQPHONEDATA::iterator iter = pDeqData->begin() ; iter != pDeqData->end() ; iter ++){
		CCheckEx *pCh = NULL;
		CComboBox *pCb = NULL;
		CMyEdit *pEdit = NULL;
		bool bDetain = false;
		bFindType = false;
		if((*iter).GetType() == PBK_Text_FirstName){	//first name
			m_edFirstName.SetWindowText((*iter).GetText());
			bFindType = true;
		}
		else if((*iter).GetType() == PBK_Text_LastName){	//last name
			m_edLastName.SetWindowText((*iter).GetText());
			bFindType = true;
		}
		if((*iter).GetType() == PBK_Text_Name){		//full name
			strName.Format(_T("%s"),(char *)((*iter).GetText()));
		}
	/*	else if((*iter).GetType() == PBK_Text_Company){	//company
				m_edCompany.SetWindowText((*iter).GetText());
			bFindType = true;
		}*/
		for(i = 0 ; i<m_cb3.GetCount() && !bFindType ;i++)
		{
			if((*iter).GetType() ==(GSM_EntryType)(m_cb3.GetItemData(i)) && iNumber < 5)
			{
				//get control
				xGetUnusedControl(iNumber,&pCh,&pCb,&pEdit);
				iNumber ++;
				//set data
				if(pCb)
					pCb->SetCurSel(i);
				else
					bDetain = true;
				bFindType = true;
				
			}
		}

		for(i = 0 ; i<m_cb8.GetCount() && !bFindType;i++)
		{
			 if((*iter).GetType() == (GSM_EntryType)(m_cb8.GetItemData(i)) && iData < 3)
			 {
				//get control
				xGetUnusedControl(iData + 5,&pCh,&pCb,&pEdit);
				iData ++;
				//set data
				if(pCb)
					pCb->SetCurSel(i);
				else
					bDetain = true;
				bFindType = true;
			}	
		}
		if(bFindType == false)
		{
			if((*iter).GetType() == PBK_Text_Custom1 && m_strAddress_ext.IsEmpty())
			{	
				m_strAddress_ext.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			else if((*iter).GetType() == PBK_Text_StreetAddress && m_strAddress_Street.IsEmpty())
			{	
				m_strAddress_Street.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			else if((*iter).GetType() == PBK_Text_City && m_strAddress_City.IsEmpty())
			{	
				m_strAddress_City.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			else if((*iter).GetType() == PBK_Text_State && m_strAddress_State.IsEmpty())
			{	
				m_strAddress_State.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			else if((*iter).GetType() == PBK_Text_Zip && m_strAddress_Zip.IsEmpty())
			{	
				m_strAddress_Zip.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			else if((*iter).GetType() == PBK_Text_Country && m_strAddress_Country.IsEmpty())
			{	
				m_strAddress_Country.Format(_T("%s"),(char *)((*iter).GetText()));
				bFindType = true;
			}
			if(bFindType)
			{
				if(pAddressCh == NULL)
				{
					int j =0;
					for(j = 0 ; j<m_cb8.GetCount() ;j++)
					{
						 if(PBK_Text_Postal == (GSM_EntryType)(m_cb8.GetItemData(j)) && iData < 3)
						 {
							//get control
							xGetUnusedControl(iData + 5,&pAddressCh,&pAddressCb,&pAddressEdit);
							iData ++;
							if(pAddressCb)
								pAddressCb->SetCurSel(j);
							else
								bDetain = true;
							break;
						}	
					}
				}
			}

		}
		if(bFindType == false)
		{
		//keep other type data
			 if((*iter).GetType() != PBK_Text_Name && (*iter).GetType() != PBK_Text_LastName && (*iter).GetType() != PBK_Text_FirstName)
				m_deqDetainData.push_back((*iter));
		}
			
		if(bDetain)
		{
			m_deqDetainData.push_back((*iter));
		}

		if(pEdit)
		{
		/*	if((*iter).GetType() == PBK_Text_Postal || (*iter).GetType() == PBK_Text_Postal_Home || (*iter).GetType() == PBK_Text_Postal_Work)
			{
				CString strTemp;
				strTemp.Format(_T("%s"),(*iter).GetText());
				if(pEdit == &m_ed9)
					m_strAddress9.Format(_T("%s"),strTemp);
				else if(pEdit == &m_ed10)
					m_strAddress10.Format(_T("%s"),strTemp);
				else if(pEdit == &m_ed8)
					m_strAddress8.Format(_T("%s"),strTemp);
				strTemp.Replace(_T("\\;"),_T(";"));
				pEdit->SetWindowText(strTemp);
			}
			else*/
				pEdit->SetWindowText((*iter).GetText());
		}
		if(pCh)
			pCh->SetCheck(1);
	}
	if(pAddressCh)
	{
		pAddressCh->SetCheck(1);
		if(pAddressEdit)
		{
			CString strAddress;
			strAddress.Format(_T("%s,%s,%s,%s,%s,%s"),m_strAddress_ext,m_strAddress_Street,m_strAddress_City,m_strAddress_State,
			m_strAddress_Zip,m_strAddress_Country);
			pAddressEdit->SetWindowText(strAddress);
		}
	}
	
	xSetDefaultEnableControl();
	xSetRadioBtn();
	if(m_edLastName.GetStyle()& WS_VISIBLE)
	{
		CString strFirstName,strLastName;
		strFirstName.Empty();
		strLastName.Empty();
		m_edFirstName.GetWindowText(strFirstName);
		m_edLastName.GetWindowText(strLastName);
		if(strFirstName.IsEmpty() && strLastName.IsEmpty() && strName.IsEmpty()== false)
		{
			m_edLastName.SetWindowText(strName);
		}
	}
}

void CS4DataDycDlg::xSetComboItem()
{
	//set group combo item
	int iCount = 0;
	TCHAR szProfile[MAX_PATH];

	int nCount = 0;
	int i,index;
	TCHAR szkey[MAX_PATH];
	TCHAR szStringID[MAX_PATH];
	TCHAR szComboString[MAX_PATH];
	TCHAR szEntry[MAX_PATH];
	GSM_EntryType entryType;
	wsprintf(szProfile,_T("%s%s_%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"),theApp.m_szPhone);
	if(al_IsFileExist(szProfile) == FALSE)
	{
		wsprintf(szProfile,_T("%s%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"));
	}


	CComboBox *pCombo[5] = {&m_cb3,&m_cb4,&m_cb5,&m_cb6,&m_cb7};
	if(al_GetSettingInt(_T("NumberCombo"),_T("Count"),szProfile,nCount) && nCount>0)
	{
		for(i = 1; i<=nCount ;i++)
		{
			wsprintf(szkey,_T("stringID%d"),i);
			al_GetSettingString(_T("NumberCombo"),szkey,szProfile,szStringID);
			wsprintf(szkey,_T("EntryType%d"),i);
			al_GetSettingString(_T("NumberCombo"),szkey,szProfile,szEntry);
			
			if(EntryTypeString2EntryType(szEntry,&entryType)==false)
				entryType = PBK_Number_General;

			al_GetSettingString(_T("public"),szStringID,theApp.m_szRes,szComboString);
			for(int j = 0 ;j < 5 ;j++)
			{
				index = pCombo[j]->AddString(szComboString);
				pCombo[j]->SetItemData(index,entryType);
			}
		}

	}
	CComboBox *pTextCombo[3] = {&m_cb8,&m_cb9,&m_cb10};

	if(al_GetSettingInt(_T("TextCombo"),_T("Count"),szProfile,nCount) && nCount>0)
	{
		for(i = 1; i<=nCount ;i++)
		{
			wsprintf(szkey,_T("stringID%d"),i);
			al_GetSettingString(_T("TextCombo"),szkey,szProfile,szStringID);
			wsprintf(szkey,_T("EntryType%d"),i);
			al_GetSettingString(_T("TextCombo"),szkey,szProfile,szEntry);
			
			if(EntryTypeString2EntryType(szEntry,&entryType)==false)
				entryType = PBK_Text_Email;

			al_GetSettingString(_T("public"),szStringID,theApp.m_szRes,szComboString);
			for(int j = 0 ;j <3 ;j++)
			{
				index = pTextCombo[j]->AddString(szComboString);
				pTextCombo[j]->SetItemData(index,entryType);
			}
		}

	}
/*
	//set combo text
	TCHAR szText[10][MAX_PATH];
	TCHAR szTxtSec[10][32] = {"IDS_GENERAL","IDS_HOME","IDS_OFFICE","IDS_MOBILE","IDS_MOBILE_HOME","IDS_MOBILE_BUSINESS",
			"IDS_FAX","IDS_FAX_HOME","IDS_FAX_BUSINESS","IDS_N_PAGER"};
	int nType[10] ={PBK_Number_General,PBK_Number_Home,PBK_Number_Work,PBK_Number_Mobile,PBK_Number_Mobile_Home,PBK_Number_Mobile_Work,
			PBK_Number_Fax,PBK_Number_Fax_Home,PBK_Number_Fax_Work,PBK_Number_Pager};
	//get string from language resource
	for(int i = 0 ; i < 10 ; i ++){
		al_GetSettingString(_T("public"),szTxtSec[i],theApp.m_szRes,szText[i]);
	}
	//add these to first 5 combo box
	CComboBox *pCombo[5] = {&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8};
	for( i = 0 ; i < 5 ; i ++)
	{
		for(int j = 0 ; j < 10 ; j ++)
		{
			int nIndex = pCombo[i]->AddString(szText[j]);
			pCombo[i]->SetItemData(nIndex,nType[j]);
		}


	}

	TCHAR szText2[11][MAX_PATH];
	TCHAR szTxtSec2[11][32] = {"IDS_N_JPBTITLE","IDS_EMAIL3","IDS_EMAIL_HOME","IDS_EMAIL_BUS",
		"IDS_WEBADDRESS","IDS_WEBADDRESS_HOME","IDS_WEBADDRESS_BUS","IDS_NOTE","IDS_ADDRESS","IDS_ADDRESS_HOME","IDS_ADDRESS_BUS"};
	int nType2[11] ={PBK_Text_JobTitle,PBK_Text_Email,PBK_Text_Email_Home,PBK_Text_Email_Work,
		PBK_Text_URL,PBK_Text_URL_Home,PBK_Text_URL_Work,PBK_Text_Note,PBK_Text_Postal,PBK_Text_Postal_Home,PBK_Text_Postal_Work};
	//set text id
	for(i = 0 ; i < 11 ; i ++){
		memset(szText2[i],0,sizeof(TCHAR) * MAX_PATH);
		al_GetSettingString(_T("public"),szTxtSec2[i],theApp.m_szRes,szText2[i]);
	}

	pCombo[0] = &m_cb9;
	pCombo[1] = &m_cb10;
	pCombo[2] = &m_cb11;
	//add string to last 3 combo box
	for(i = 0 ; i < 3 ; i ++)
	{
		for(int j = 0 ; j < 11 ; j ++)
		{
			int nIndex = pCombo[i]->AddString(szText2[j]);
			pCombo[i]->SetItemData(nIndex,nType2[j]);
		}
	}
*/
}

void CS4DataDycDlg::xGetUnusedControl(int iIndex, CCheckEx **pCh, CComboBox **pCb, CMyEdit **pEdit)
{
	switch(iIndex){
	case 0:
		*pCh = NULL;
		*pCb = &m_cb3;
		*pEdit = &m_ed3;
		break;
	case 1:	//combo3
		*pCh = &m_ch4;
		*pCb = &m_cb4;
		*pEdit = &m_ed4;
		break;
	case 2:	//combo3
		*pCh = &m_ch5;
		*pCb = &m_cb5;
		*pEdit = &m_ed5;
		break;
	case 3:	//combo4
		*pCh = &m_ch6;
		*pCb = &m_cb6;
		*pEdit = &m_ed6;
		break;
	case 4:	//combo5
		*pCh = &m_ch7;
		*pCb = &m_cb7;
		*pEdit = &m_ed7;
		break;
	case 5:	//combo6
		*pCh = &m_ch8;
		*pCb = &m_cb8;
		*pEdit = &m_ed8;
		break;
	case 6:	//combo7
		*pCh = &m_ch9;
		*pCb = &m_cb9;
		*pEdit = &m_ed9;
		break;
	case 7:	//combo8
		*pCh = &m_ch10;
		*pCb = &m_cb10;
		*pEdit = &m_ed10;
		break;
	default :
		*pCh = NULL;
		*pCb = NULL;
		*pEdit = NULL;
		break;
	}
}

void CS4DataDycDlg::xSetDefaultControl()
{
	m_cb3.SetCurSel(0);
	m_cb4.SetCurSel(1);
	m_cb5.SetCurSel(2);
	m_cb6.SetCurSel(3);
	m_cb7.SetCurSel(4);
	m_cb8.SetCurSel(0);
	m_cb9.SetCurSel(1);
	m_cb10.SetCurSel(2);

	m_ed3.SetNumFlag(true);
	m_ed4.SetNumFlag(true);
	m_ed5.SetNumFlag(true);
	m_ed6.SetNumFlag(true);
	m_ed7.SetNumFlag(true);

	m_ed3.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed4.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed5.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed6.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed7.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed8.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed9.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);
	m_ed10.SetLimitText(GSM_PHONEBOOK_TEXT_LENGTH+1);

	xSetRadioBtn();
}


void CS4DataDycDlg::xSetDefaultEnableControl()
{
	CCheckEx *pCh[7] = {&m_ch4,&m_ch5,&m_ch6,&m_ch7,&m_ch8,&m_ch9,&m_ch10};
	CComboBox *pCb[7] = {&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8,&m_cb9,&m_cb10};
	CMyEdit *pEd[7] = {&m_ed4,&m_ed5,&m_ed6,&m_ed7,&m_ed8,&m_ed9,&m_ed10};

	for(int i = 0 ; i < 7 ; i ++){
		if(pCh[i]->GetCheck()){
			pCb[i]->EnableWindow();
			pEd[i]->EnableWindow();
		}
		else{
			pCb[i]->EnableWindow(FALSE);
			pEd[i]->EnableWindow(FALSE);
		}
	}
}
/*
void CS4DataDycDlg::xSetDefaultCombo()
{
	//get default combobox cur sel
	int iDefSel = m_cbDefault.GetCurSel();
	//get the cursel string
	TCHAR szText[MAX_PATH];
	m_cbDefault.GetLBText(iDefSel,szText);
	//get the first char to know which one has been selected
	TCHAR szKey = szText[0];
	int iKeySel = atoi(&szKey);
	//reset string
	m_cbDefault.ResetContent();

	CComboBox *pCb[5] = {&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8};
	CCheckEx *pCh[4] = {&m_ch5,&m_ch6,&m_ch7,&m_ch8};

	bool bRet = false;
	for(int i = 0 ;i < 5 ; i ++){
		int iSel = pCb[i]->GetCurSel();
		pCb[i]->GetLBText(iSel,szText);
		TCHAR szFormat[MAX_PATH];
		sprintf(szFormat,"%d.",i+2);
		string sTxt = string(szFormat) + string(szText);
		if( i == 0){
			int iIndex = m_cbDefault.AddString(sTxt.c_str());
			if(iKeySel == i + 2){
				m_cbDefault.SetCurSel(iIndex);
				bRet = true;
			}
		}
		else{
			if(pCh[i - 1]->GetCheck()){
				int iIndex = m_cbDefault.AddString(sTxt.c_str());
				if(iKeySel == i + 2){
					m_cbDefault.SetCurSel(iIndex);
					bRet = true;
				}
			}
		}		
	}
	if(!bRet)
		m_cbDefault.SetCurSel(0);
}
*/
void CS4DataDycDlg::xEnableControl(int iIndex, BOOL bFlag)
{
	if(iIndex < 0 || iIndex > 11)	//out of range
		return ;

	CCheckEx *pCh[7] = {&m_ch4,&m_ch5,&m_ch6,&m_ch7,&m_ch8,&m_ch9,&m_ch10};
	CComboBox *pCb[7] = {&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8,&m_cb9,&m_cb10};
	CEdit *pEd[7] = {&m_ed4,&m_ed5,&m_ed6,&m_ed7,&m_ed8,&m_ed9,&m_ed10};

	if(iIndex == 0){	//name
		m_edLastName.EnableWindow(bFlag);
	}
	else if(iIndex == 1){	//name
		m_edFirstName.EnableWindow(bFlag);
	}
	else if(iIndex == 2){
		m_cb3.EnableWindow(bFlag);
		m_ed3.EnableWindow(bFlag);
	}
	else{
		pCh[iIndex - 3]->EnableWindow(bFlag);
		if(bFlag == TRUE){
			if(pCh[iIndex - 3]->GetCheck()){
				pCb[iIndex - 3]->EnableWindow(bFlag);
				pEd[iIndex - 3]->EnableWindow(bFlag);
			}
		}
		else{
			pCb[iIndex - 3]->EnableWindow(bFlag);
			pEd[iIndex - 3]->EnableWindow(bFlag);
		}
	}
}

void CS4DataDycDlg::xSetSupportColumnLength()
{
	DEQPHBOUNDARY *pBoundary = m_se.GetPhBoundary();
	
	CEdit *pEd[8] = {&m_ed3,&m_ed4,&m_ed5,&m_ed6,&m_ed7,&m_ed8,&m_ed9,&m_ed10};

	for(DEQPHBOUNDARY::iterator iter = pBoundary->begin() ; iter != pBoundary->end() ; iter ++){
		if((*iter).GetType() == PBK_Text_LastName)
			m_edLastName.SetLimitText((*iter).GetBoundary());
		if((*iter).GetType() == PBK_Text_FirstName)
			m_edFirstName.SetLimitText((*iter).GetBoundary());
	//	if((*iter).GetType() == PBK_Text_Company)
//			m_edCompany.SetLimitText((*iter).GetBoundary());

		for(int i = 0 ; i < 8; i ++){
			if((*iter).GetType() == xGetComboSel(i))
				pEd[i]->SetLimitText((*iter).GetBoundary());
		}
	}
}

int CS4DataDycDlg::xGetComboSel(int iIndex)
{
	CComboBox *pCb[8] = {&m_cb3,&m_cb4,&m_cb5,&m_cb6,&m_cb7,&m_cb8,&m_cb9,&m_cb10};
	CCheckEx *pCh[8] = {NULL,&m_ch4,&m_ch5,&m_ch6,&m_ch7,&m_ch8,&m_ch9,&m_ch10};

	int iType;
	bool bCh = true;

	if(pCh[iIndex]){
		if(!pCh[iIndex]->GetCheck())
			bCh = false;
	}
	if(bCh)
	{
		iType =  pCb[iIndex]->GetItemData(iIndex);
	/*	if(iIndex < 5)
		{
			switch(pCb[iIndex]->GetCurSel()){
			case 0:
				iType = PBK_Number_General;
				break;
			case 1:
				iType = PBK_Number_Home;
				break;
			case 2:
				iType = PBK_Number_Work;
				break;
			case 3:
				iType = PBK_Number_Mobile;
				break;
			case 4:
				iType = PBK_Number_Mobile_Home;
				break;
			case 5:
				iType = PBK_Number_Mobile_Work;
				break;
			case 6:
				iType = PBK_Number_Fax;
				break;
			case 7:
				iType = PBK_Number_Fax_Home;
				break;
			case 8:
				iType = PBK_Number_Fax_Work;
				break;
			case 9:
				iType = PBK_Number_Pager;
				break;
			}
		}
		else
		{
			switch(pCb[iIndex]->GetCurSel()){
			case 0:
				iType = PBK_Text_Email;
				break;
			case 1:
				iType = PBK_Text_Postal;
				break;
			case 2:
				iType = PBK_Text_Note;
				break;
			case 3:
				iType = PBK_Text_URL;
				break;
			}
		}*/
		return iType;
	}
	else
		return -1;
}


void CS4DataDycDlg::xSetCombo2Item()
{
	if(m_rdSIM.GetCheck())
	{
		for(int i = m_cb3.GetCount()-1 ; i > 0 ; i --)
			m_cb3.DeleteString(i);
		m_cb3.SetCurSel(0);
	}
	else if(m_cb3.GetCount() <= 1)
	{
		//set combo text
		m_cb3.ResetContent();
/*
		TCHAR szText[10][MAX_PATH];
		TCHAR szTxtSec[10][32] = {"IDS_GENERAL","IDS_HOME","IDS_OFFICE","IDS_MOBILE","IDS_MOBILE_HOME","IDS_MOBILE_BUSINESS",
			"IDS_FAX","IDS_FAX_HOME","IDS_FAX_BUSINESS","IDS_PAGER"};
		int nType[10] ={PBK_Number_General,PBK_Number_Home,PBK_Number_Work,PBK_Number_Mobile,PBK_Number_Mobile_Home,PBK_Number_Mobile_Work,
				PBK_Number_Fax,PBK_Number_Fax_Home,PBK_Number_Fax_Work,PBK_Number_Pager};
		//get string from language resource
		for(int i = 0 ; i < 10 ; i ++)
		{
			al_GetSettingString(_T("public"),szTxtSec[i],theApp.m_szRes,szText[i]);
			int nIndex = m_cb3.AddString(szText[i]);
			m_cb3.SetItemData(nIndex,nType[i]);
		}
		m_cb3.SetCurSel(0);*/
		int nCount = 0;
		int i,index;
		TCHAR szkey[MAX_PATH];
		TCHAR szStringID[MAX_PATH];
		TCHAR szComboString[MAX_PATH];
		TCHAR szEntry[MAX_PATH];
		GSM_EntryType entryType;
		int iCount = 0;
		TCHAR szProfile[MAX_PATH];
		wsprintf(szProfile,_T("%s%s_%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"),theApp.m_szPhone);
		if(al_IsFileExist(szProfile) == FALSE)
		{
			wsprintf(szProfile,_T("%s%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"));
		}
		if(al_GetSettingInt(_T("NumberCombo"),_T("Count"),szProfile,nCount) && nCount>0)
		{
			for(i = 1; i<=nCount ;i++)
			{
				wsprintf(szkey,_T("stringID%d"),i);
				al_GetSettingString(_T("NumberCombo"),szkey,szProfile,szStringID);
				wsprintf(szkey,_T("EntryType%d"),i);
				al_GetSettingString(_T("NumberCombo"),szkey,szProfile,szEntry);
				
				if(EntryTypeString2EntryType(szEntry,&entryType)==false)
					entryType = PBK_Number_General;

				al_GetSettingString(_T("public"),szStringID,theApp.m_szRes,szComboString);
				index = m_cb3.AddString(szComboString);
				m_cb3.SetItemData(index,entryType);
			}

		}
		m_cb3.SetCurSel(0);

	}
	xSetDefaultCombo();
}
void CS4DataDycDlg::UpdateTextComboBox(CComboBox* pCombo1,CComboBox* pCombo2,CComboBox* pNeedUpdateCombo)
{
	int i,nCount = 0;
	TCHAR szProfile[MAX_PATH];
	wsprintf(szProfile,_T("%s%s_%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"),theApp.m_szPhone);
	if(al_IsFileExist(szProfile) == FALSE)
	{
		wsprintf(szProfile,_T("%s%s.ini"),theApp.m_szSkin,_T("organize\\S4Combo"));
	}

	int nCurSel = 0;
	bool bAddToList = true;
	int nEntryType1 = pCombo1->GetItemData(pCombo1->GetCurSel());
	int nEntryType2 = pCombo2->GetItemData(pCombo2->GetCurSel());
	int nEntryTypeNeedUpdate= pNeedUpdateCombo->GetItemData(pNeedUpdateCombo->GetCurSel());

	if(nEntryType1 == PBK_Text_Postal || nEntryType1 == PBK_Text_Postal_Home|| nEntryType1 == PBK_Text_Postal_Work ||
		nEntryType2 == PBK_Text_Postal || nEntryType2 == PBK_Text_Postal_Home|| nEntryType2 == PBK_Text_Postal_Work )
	{

		pNeedUpdateCombo->ResetContent();
		TCHAR szkey[MAX_PATH];
		TCHAR szStringID[MAX_PATH];
		TCHAR szEntry[MAX_PATH];
		TCHAR szComboString[MAX_PATH];
		GSM_EntryType entryType;
		int index;

		if(al_GetSettingInt(_T("TextCombo"),_T("Count"),szProfile,nCount) && nCount>0)
		{
			for(i = 1; i<=nCount ;i++)
			{
				wsprintf(szkey,_T("stringID%d"),i);
				al_GetSettingString(_T("TextCombo"),szkey,szProfile,szStringID);
				wsprintf(szkey,_T("EntryType%d"),i);
				al_GetSettingString(_T("TextCombo"),szkey,szProfile,szEntry);
				
				if(EntryTypeString2EntryType(szEntry,&entryType)==false)
					entryType = PBK_Text_Email;

				switch(entryType)
				{
					case PBK_Text_Postal:
						if(nEntryType1 == PBK_Text_Postal || nEntryType2 == PBK_Text_Postal)
							bAddToList = false;
						else
							bAddToList = true;
						break;
					case PBK_Text_Postal_Home:
						if(nEntryType1 == PBK_Text_Postal_Home || nEntryType2 == PBK_Text_Postal_Home)
							bAddToList = false;
						else
							bAddToList = true;
						break;
					case PBK_Text_Postal_Work:
						if(nEntryType1 == PBK_Text_Postal_Work || nEntryType2 == PBK_Text_Postal_Work)
							bAddToList = false;
						else
							bAddToList = true;
						break;
					default:
						bAddToList = true;
						break;
				}

				if(bAddToList)
				{
					al_GetSettingString(_T("public"),szStringID,theApp.m_szRes,szComboString);
					index =pNeedUpdateCombo->AddString(szComboString);
					pNeedUpdateCombo->SetItemData(index,entryType);
				}
			}

		}
		for(i = 0; i<pNeedUpdateCombo->GetCount() ;i++)
		{
			if(pNeedUpdateCombo->GetItemData(i) == nEntryTypeNeedUpdate)
			{
				nCurSel = i;
				break;
			}

		}

		pNeedUpdateCombo->SetCurSel(nCurSel);
	}
}
void CS4DataDycDlg::OnDropdownS6Combo8() 
{
	// TODO: Add your control notification handler code here
	UpdateTextComboBox(&m_cb9,&m_cb10,&m_cb8);
}

void CS4DataDycDlg::OnDropdownS6Combo10() 
{
	// TODO: Add your control notification handler code here
	UpdateTextComboBox(&m_cb9,&m_cb8,&m_cb10);
	
}

void CS4DataDycDlg::OnDropdownS6Combo9() 
{
	// TODO: Add your control notification handler code here
	UpdateTextComboBox(&m_cb10,&m_cb8,&m_cb9);
	
}

void CS4DataDycDlg::OnSetfocusS6Edit9() 
{
	// TODO: Add your control notification handler code here
	static bInAddressdlg = false;
	if( !bInAddressdlg&& IsFocusOnAddressEdit(&m_cb9))
	{
		bInAddressdlg = true;
		EditAddress(&m_ed9);
	}
	bInAddressdlg= false;
}

void CS4DataDycDlg::OnSetfocusS6Edit10() 
{
	// TODO: Add your control notification handler code here
	static bInAddressdlg = false;
	if( !bInAddressdlg&&IsFocusOnAddressEdit(&m_cb10))
	{
		bInAddressdlg = true;
		EditAddress(&m_ed10);
	}
	bInAddressdlg= false;
	
}

void CS4DataDycDlg::OnSetfocusS6Edit8() 
{
	// TODO: Add your control notification handler code here
	static bInAddressdlg = false;
	if(!bInAddressdlg  &&IsFocusOnAddressEdit(&m_cb8))
	{
		bInAddressdlg = true;
		EditAddress(&m_ed8);

	}
	bInAddressdlg= false;
	
}
BOOL CS4DataDycDlg::IsFocusOnAddressEdit(CComboBox* pCombo)
{
	int nEntryType = pCombo->GetItemData(pCombo->GetCurSel());

	if(nEntryType == PBK_Text_Postal || nEntryType == PBK_Text_Postal_Home|| nEntryType == PBK_Text_Postal_Work)
		return true;
	return false;
}
void CS4DataDycDlg::EditAddress(CMyEdit* pEdit)
{
//	CString strAddress;
//	pEdit->GetWindowText(strAddress);

	CNS4AddressDlg addressDlg;
	addressDlg.SetAddress(m_strAddress_ext,m_strAddress_Street,m_strAddress_City,
		m_strAddress_State,m_strAddress_Zip,m_strAddress_Country);
	if(addressDlg.DoModal() == IDOK)
	{
		m_strAddress_ext.Format(_T("%s"),addressDlg.m_strExt);
		m_strAddress_Street.Format(_T("%s"),addressDlg.m_strStreet);
		m_strAddress_City.Format(_T("%s"),addressDlg.m_strCity);
		m_strAddress_State.Format(_T("%s"),addressDlg.m_strState);
		m_strAddress_Zip.Format(_T("%s"),addressDlg.m_strZip);
		m_strAddress_Country.Format(_T("%s"),addressDlg.m_strCountry);
	
		CString strAddress;
		strAddress.Format(_T("%s,%s,%s,%s,%s,%s"),m_strAddress_ext,m_strAddress_Street,m_strAddress_City,m_strAddress_State,
		m_strAddress_Zip,m_strAddress_Country);
		pEdit->SetWindowText(strAddress);
	}
	SetFocus();



}




void CS4DataDycDlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	xSetSupportColumnLength();
	xSetDefaultCombo();	
}
