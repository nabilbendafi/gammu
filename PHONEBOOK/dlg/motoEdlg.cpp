// motodlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\phonebook.h"
#include "motoedlg.h"
#include "NS4AddressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMotoEDlg dialog


CMotoEDlg::CMotoEDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CMotoEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMotoEDlg)
	//}}AFX_DATA_INIT
	m_hFont = NULL;
	m_strSkinFile.Format(_T("%s"),_T("MotoEDlg.ini"));
}
CMotoEDlg::~CMotoEDlg()
{
	if(m_hFont)
		::DeleteObject(m_hFont);
}


void CMotoEDlg::DoDataExchange(CDataExchange* pDX)
{
	CBaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMotoEDlg)
	DDX_Control(pDX, IDC_LINE, m_scLine);
	DDX_Control(pDX, IDC_DP_BIRTHDAY, m_dpBirthday);
	DDX_Control(pDX, IDC_SC_NOTES, m_scNote);
	DDX_Control(pDX, IDC_SC_URL1, m_scURL1);
	DDX_Control(pDX, IDC_SC_URL2, m_scURL2);
	DDX_Control(pDX, IDC_SC_NICKNAME, m_scNickName);
	DDX_Control(pDX, IDC_SC_BIRTHDAY, m_scBirthday);
	DDX_Control(pDX, IDC_CH_BIRTHDAY, m_chBirthday);
	DDX_Control(pDX, IDC_ET_NICKNAME, m_edNickName);
	DDX_Control(pDX, IDC_ED_URL1, m_edURL1);
	DDX_Control(pDX, IDC_ED_URL2, m_edURL2);
	DDX_Control(pDX, IDC_ED_NOTE, m_edNote);
	DDX_Control(pDX, IDOK, m_rbnOK);
	DDX_Control(pDX, IDCANCEL, m_rbnCancel);
	DDX_Control(pDX, IDC_SC_PHONENO1, m_scPhone1);
	DDX_Control(pDX, IDC_SC_PHONENO2, m_scPhone2);
	DDX_Control(pDX, IDC_SC_PHONENO3, m_scPhone3);
	DDX_Control(pDX, IDC_SC_PHONENO4, m_scPhone4);
	DDX_Control(pDX, IDC_SC_PHONENO5, m_scPhone5);
	DDX_Control(pDX, IDC_SC_PHONENO6, m_scPhone6);
	DDX_Control(pDX, IDC_SC_PHONENO7, m_scPhone7);
	DDX_Control(pDX, IDC_SC_ADDRESS1, m_scAddress1);
	DDX_Control(pDX, IDC_SC_ADDRESS2, m_scAddress2);
	DDX_Control(pDX, IDC_SC_EMAIL1, m_scEmail1);
	DDX_Control(pDX, IDC_SC_EMAIL2, m_scEmail2);
	DDX_Control(pDX, IDC_SC_STORAGE, m_scStorage);
	DDX_Control(pDX, IDC_SC_FIRSTNAME, m_scFirstName);
	DDX_Control(pDX, IDC_SC_LASTNAME, m_scLastName);
	DDX_Control(pDX, IDC_SC_GROUP, m_scGroup);
	DDX_Control(pDX, IDC_ED_FIRSTNAME, m_edFirstName);
	DDX_Control(pDX, IDC_ED_LASTNAME, m_edLastName);
	DDX_Control(pDX, IDC_ED_DATA1, m_edData1);
	DDX_Control(pDX, IDC_ED_DATA2, m_edData2);
	DDX_Control(pDX, IDC_ED_DATA3, m_edData3);
	DDX_Control(pDX, IDC_ED_DATA4, m_edData4);
	DDX_Control(pDX, IDC_ED_DATA5, m_edData5);
	DDX_Control(pDX, IDC_ED_DATA6, m_edData6);
	DDX_Control(pDX, IDC_ED_DATA7, m_edData7);
	DDX_Control(pDX, IDC_ED_EMAIL1, m_edEmail1);
	DDX_Control(pDX, IDC_ED_EMAIL2, m_edEmail2);
	DDX_Control(pDX, IDC_ED_ADDRESS1, m_edAddress1);
	DDX_Control(pDX, IDC_ED_ADDRESS2, m_edAddress2);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE1, m_cbType1);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE2, m_cbType2);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE3, m_cbType3);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE4, m_cbType4);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE5, m_cbType5);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE6, m_cbType6);
	DDX_Control(pDX, IDC_CB_NUMBERTYPE7, m_cbType7);
	DDX_Control(pDX, IDC_CB_EMAILTYPE1, m_cbEmail1);
	DDX_Control(pDX, IDC_CB_EMAILTYPE2, m_cbEmail2);
	DDX_Control(pDX, IDC_CB_ADDRESSTYPE1, m_cbAddress1);
	DDX_Control(pDX, IDC_CB_ADDRESSTYPE2, m_cbAddress2);
	DDX_Control(pDX, IDC_CB_GROUP, m_cbGroup);
	DDX_Control(pDX, IDC_RD_SIM, m_rdSIM);
	DDX_Control(pDX, IDC_RD_MEMORY, m_rdME);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMotoEDlg, CBaseDlg)
	//{{AFX_MSG_MAP(CMotoEDlg)
	ON_BN_CLICKED(IDC_RD_SIM, OnRdSim)
	ON_BN_CLICKED(IDC_RD_MEMORY, OnRdMobile)
	ON_BN_CLICKED(IDC_CH_BIRTHDAY, OnChBirthday)
	ON_EN_SETFOCUS(IDC_ED_ADDRESS1, OnSetfocusAddressEdit1)
	ON_EN_SETFOCUS(IDC_ED_ADDRESS2, OnSetfocusAddressEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMotoEDlg message handlers

BOOL CMotoEDlg::OnInitDialog() 
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
	
	//get profile path
	Tstring sSkin(theApp.m_szSkin);
//	string sProfile = sSkin + string("Organize\\MotoDlg.ini");
	Tstring sProfile = sSkin + Tstring(_T("Organize\\"))+Tstring(m_strSkinFile);

	al_GetSettingString(_T("public"),_T("IDS_N_FIRSTNAME"),theApp.m_szRes,m_szFirstName);
	al_GetSettingString(_T("public"),_T("IDS_NAME"),theApp.m_szRes,m_szName);
	//Load static
	CStaticEx	*pStaticEx[4] = {&m_scFirstName,&m_scLastName,&m_scGroup,&m_scStorage};
	TCHAR szScSec[4][32] = {_T("firstname_sc"),_T("lastname_sc"),_T("group_sc"),_T("storage_sc")};
	TCHAR szScID[4][32] = {_T("IDS_N_FIRSTNAME"),_T("IDS_N_LASTNAME"),_T("IDS_N_GROUP"),_T("IDS_STORAGE")};
	for(int i = 0 ; i < 4 ; i ++)
		GetStaticFromSetting(pStaticEx[i],szScSec[i],szScID[i],const_cast<TCHAR*>(sProfile.c_str()));

	CStaticEx	*pStaticPhoneNoEx[7] = {&m_scPhone1,&m_scPhone2,&m_scPhone3,&m_scPhone4,&m_scPhone5,&m_scPhone6,&m_scPhone7};
	TCHAR szPhoneNoSec[7][32] = {_T("phoneNo1_sc"),_T("phoneNo2_sc"),_T("phoneNo3_sc"),_T("phoneNo4_sc"),_T("phoneNo5_sc"),_T("phoneNo6_sc"),_T("phoneNo7_sc")};
	for (i = 0  ; i< 7 ;i++)
	{
		TCHAR szTempText[MAX_PATH];
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_TEL_NO"),theApp.m_szRes,szText);
		wsprintf(szTempText,_T("%s %d"),szText,i+1);
		GetStaticFromSettingWithText(pStaticPhoneNoEx[i],szPhoneNoSec[i],szTempText,const_cast<TCHAR*>(sProfile.c_str()));
	}
	//load button 
	CRescaleButton	*pButton[2] = {&m_rbnOK,&m_rbnCancel};
	TCHAR szBnSec[2][32] = {_T("ok"),_T("cancel")};
	TCHAR szBnID[2][32] = {_T("IDS_N_OK"),_T("IDS_CANCEL")};
	for(i = 0 ; i < 2 ; i ++)
		GetButtonFromSetting(pButton[i],szBnSec[i],szBnID[i],0,const_cast<TCHAR*>(sProfile.c_str()));

	//load radio
	CRadioEx	*pRadio[2] = {&m_rdSIM,&m_rdME};
	TCHAR szRdSec[2][32] = {_T("sim_rd"),_T("memory_rd")};
	TCHAR szRdID[2][32] = {_T("IDS_SIMCARD"),_T("IDS_MOBILE")};
	for(i = 0 ; i < 2 ; i ++){
		GetRadioFromSetting(pRadio[i],szRdSec[i],szRdID[i],const_cast<TCHAR*>(sProfile.c_str()));
		pRadio[i]->SetCheck(0);
	}
	
	//new Control ******************************************* ++++
	CStaticEx	*pStaticEx2[3] = {&m_scNickName/*,&m_scEmail,&m_scAddress,&m_scURL*/,&m_scBirthday,&m_scNote};
	TCHAR szScSec2[3][32] = {_T("nickname_sc")/*,"email_sc","address_sc","url_sc"*/,_T("birthday_sc"),_T("note_sc")};
	TCHAR szScID2[3][32] = {_T("IDS_NICKNAME")/*,"IDS_EMAIL","IDS_A_ADDRESS","IDS_HOMEPAGE"*/,_T("IDS_N_BIRTHDAY"),_T("IDS_N_NOTE")};

	for(i = 0 ; i < 3 ; i ++)
		GetStaticFromSetting2(pStaticEx2[i],szScSec2[i],szScID2[i],const_cast<TCHAR*>(sProfile.c_str()));

	CStaticEx	*pStaticEmailEx[2] = {&m_scEmail1,&m_scEmail2};
	TCHAR szEmailSec[2][32] = {_T("email1_sc"),_T("email2_sc")};
	for (i = 0  ; i< 2 ;i++)
	{
		TCHAR szTempText[MAX_PATH];
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_N_EMAIL"),theApp.m_szRes,szText);
		wsprintf(szTempText,_T("%s %d"),szText,i+1);
		GetStaticFromSettingWithText(pStaticEmailEx[i],szEmailSec[i],szTempText,const_cast<TCHAR*>(sProfile.c_str()));
	}
	if((m_scEmail2.GetStyle()& WS_VISIBLE) == false)
	{
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_N_EMAIL"),theApp.m_szRes,szText);
		m_scEmail1.SetWindowText(szText);
	}

	CStaticEx	*pStaticURLEx[2] = {&m_scURL1,&m_scURL2};
	TCHAR szURLSec[2][32] = {_T("url1_sc"),_T("url2_sc")};
	for (i = 0  ; i< 2 ;i++)
	{
		TCHAR szTempText[MAX_PATH];
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_N_URL"),theApp.m_szRes,szText);
		wsprintf(szTempText,_T("%s %d"),szText,i+1);
		GetStaticFromSettingWithText(pStaticURLEx[i],szURLSec[i],szTempText,const_cast<TCHAR*>(sProfile.c_str()));
	}
	if((m_scURL2.GetStyle()& WS_VISIBLE) == false)
	{
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_N_URL"),theApp.m_szRes,szText);
		m_scURL1.SetWindowText(szText);
	}

	CStaticEx	*pStaticAddressEx[2] = {&m_scAddress1,&m_scAddress2};
	TCHAR szAddressSec[2][32] = {_T("address1_sc"),_T("address2_sc")};
	for (i = 0  ; i< 2 ;i++)
	{
		TCHAR szTempText[MAX_PATH];
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_ADDRESS"),theApp.m_szRes,szText);
		wsprintf(szTempText,_T("%s %d"),szText,i+1);
		GetStaticFromSettingWithText(pStaticAddressEx[i],szAddressSec[i],szTempText,const_cast<TCHAR*>(sProfile.c_str()));
	}
	if((m_scAddress2.GetStyle()& WS_VISIBLE) == false)
	{
		TCHAR szText[MAX_PATH];
		al_GetSettingString(_T("public"),_T("IDS_ADDRESS"),theApp.m_szRes,szText);
		m_scAddress1.SetWindowText(szText);
	}



	CWnd *pEDWnd[6] = {&m_edNickName,&m_edURL1,&m_edURL2,&m_edNote,&m_dpBirthday,&m_scLine};
	TCHAR szEDWndSec[6][32] = {_T("nickname_ed"),_T("url1_ed"),_T("url2_ed"),_T("note_ed"),_T("birthday_dp"),_T("line")};
	for(i = 0 ; i < 6 ; i ++){
		CRect rect;
		if(	al_GetSettingRect(szEDWndSec[i],_T("rect"),const_cast<TCHAR *>(sProfile.c_str()),rect))
			pEDWnd[i]->MoveWindow(rect);
		else
			pEDWnd[i]->ShowWindow(SW_HIDE);

		if(pFont) pEDWnd[i]->SetFont(pFont);
	}
	CCheckEx2	*pCheck[1] = {&m_chBirthday};
	TCHAR szChSec[1][32] = {_T("birthday_ch")};
	for(i = 0 ; i < 1 ; i ++){
		GetCheckFromSetting2(pCheck[i],szChSec[i],0,const_cast<TCHAR*>(sProfile.c_str()));
		pCheck[i]->SetCheck(0);
	}

	//new Control ******************************************* ----

	//set other control position and size
	CWnd *pWnd[25] = {&m_edFirstName,&m_edLastName,&m_cbType1,&m_cbType2,&m_cbType3,&m_cbType4,&m_cbType5,&m_cbType6,&m_cbType7,
		&m_edData1,&m_edData2,&m_edData3,&m_edData4,&m_edData5,&m_edData6,&m_edData7,
		&m_cbEmail1,&m_cbEmail2,&m_edEmail1,&m_edEmail2,&m_cbAddress1,&m_cbAddress2,&m_edAddress1,&m_edAddress2,&m_cbGroup};
	TCHAR szWndSec[25][32] = {_T("firstname_ed"),_T("lastname_ed"),_T("type1_cb"),_T("type2_cb"),_T("type3_cb"),_T("type4_cb"),_T("type5_cb"),_T("type6_cb"),_T("type7_cb"),
		_T("data1_ed"),_T("data2_ed"),_T("data3_ed"),_T("data4_ed"),_T("data5_ed"),_T("data6_ed"),_T("data7_ed"),
		_T("email1_cb"),_T("email2_cb"),_T("email1_ed"),_T("email2_ed"),_T("address1_cb"),_T("address2_cb"),_T("address1_ed"),_T("address2_ed"),_T("group_cb")};
	for(i = 0 ; i < 25 ; i ++){
		CRect rect;
		if(al_GetSettingRect(szWndSec[i],_T("rect"),const_cast<TCHAR *>(sProfile.c_str()),rect))
			pWnd[i]->MoveWindow(rect);
		else
			pWnd[i]->ShowWindow(SW_HIDE);

		if(pFont) pWnd[i]->SetFont(pFont);
	}

	m_edData1.SetNumFlag(true);
	m_edData2.SetNumFlag(true);
	m_edData3.SetNumFlag(true);
	m_edData4.SetNumFlag(true);
	m_edData5.SetNumFlag(true);
	m_edData6.SetNumFlag(true);
	m_edData7.SetNumFlag(true);
	m_edEmail1.SetNumFlag(false);
	m_edEmail2.SetNumFlag(false);

	//Get background color
	al_GetSettingColor(_T("panel"),_T("color"),const_cast<TCHAR*>(sProfile.c_str()),m_crBg);

	//Set window pos
	CRect rect;
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

//	CRect rcLine,rcClient;
//	GetClientRect(&rcClient);
//	m_scLine.GetWindowRect(&rcLine);
//	ScreenToClient(&rcLine);
//	rcLine.left = rcClient.left;
//	rcLine.right = rcClient.right;
//	int nW = rcLine.Height();
//	rcLine.top = rcClient.bottom - rcBtn2.Height() -20;
//	rcLine.bottom = rcLine.top+nW;
//	m_scLine.MoveWindow(rcLine);


	if(rcBtn1.Width() > rcBtn2.Width())
		rcBtn2.right = rcBtn2.left + rcBtn1.Width();
	else
		rcBtn1.right = rcBtn1.left + rcBtn2.Width();

/*	if(m_edStreet1.GetStyle() & WS_VISIBLE)
	{
		m_edStreet1.GetWindowRect(&rc);
	}
	else*/
		m_scLine.GetWindowRect(&rc);
	ScreenToClient(&rc);
	
	rcBtn1.OffsetRect(rc.right - rcBtn1.right  ,0);
	m_rbnCancel.MoveWindow(rcBtn1);

	rcBtn2.OffsetRect(rcBtn1.left - 20 - rcBtn2.right ,0);
	m_rbnOK.MoveWindow(rcBtn2);

	xSetRadioBtn();
	//set title 
	TCHAR szText[MAX_PATH];
	BOOL bRet = FALSE;
	if(m_iMode == 0){	//new
		bRet = al_GetSettingString(_T("public"),_T("IDS_NEWCONTACT"),theApp.m_szRes,szText);
	}
	else if(m_iMode == 1){	//edit
		bRet = al_GetSettingString(_T("public"),_T("IDS_EDITCONTACT"),theApp.m_szRes,szText);
		m_rdME.EnableWindow(FALSE);
		m_rdSIM.EnableWindow(FALSE);
	}
	else if(m_iMode == 2){	//view file
		//hide save button 
		m_rbnOK.ShowWindow(SW_HIDE);

		al_GetSettingString(_T("public"),_T("IDS_OK"),theApp.m_szRes,szText);
		m_rbnCancel.SetWindowText(szText);

		//set title
		bRet = al_GetSettingString(_T("public"),_T("IDS_VIEWCONTACT"),theApp.m_szRes,szText);
		xEnableControl(ENABLE_VIEW);
	}
	if(bRet)
		SetWindowText(szText);
	
	xSetComboItem();
	xSetDataToDlgCtrl();
	//Set combobox string

	m_edFirstName.SetFocus();
	if(m_iIsME)
		m_scFirstName.SetWindowText(m_szFirstName);
	else
		m_scFirstName.SetWindowText(m_szName);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMotoEDlg::OnRdSim() 
{
	m_rdME.SetCheck(FALSE);
	m_rdSIM.SetCheck(TRUE);
	m_cbType1.SetCurSel(0);
	m_cbType1.EnableWindow(FALSE);
	xEnableControl(ENABLE_SIM);
}

void CMotoEDlg::OnRdMobile() 
{
	m_rdME.SetCheck(TRUE);
	m_rdSIM.SetCheck(FALSE);
	m_cbType1.EnableWindow(TRUE);
	xEnableControl(ENABLE_ME);
}


void CMotoEDlg::OnOK() 
{
	TCHAR szTxt[MAX_PATH],szTxt1[MAX_PATH],szTxt2[MAX_PATH],szTxt3[MAX_PATH],szTxt4[MAX_PATH],szTxt5[MAX_PATH],szTxt6[MAX_PATH],szTxt7[MAX_PATH];
	m_edData1.GetWindowText(szTxt1,MAX_PATH);
	m_edData2.GetWindowText(szTxt2,MAX_PATH);
	m_edData3.GetWindowText(szTxt3,MAX_PATH);
	m_edData4.GetWindowText(szTxt4,MAX_PATH);
	m_edData5.GetWindowText(szTxt5,MAX_PATH);
	m_edData6.GetWindowText(szTxt6,MAX_PATH);
	m_edData7.GetWindowText(szTxt7,MAX_PATH);
	int iLength = _tcslen(szTxt1)+_tcslen(szTxt2)+_tcslen(szTxt3)+_tcslen(szTxt4)+_tcslen(szTxt5)+_tcslen(szTxt6)+_tcslen(szTxt7);
	if(iLength == 0){
		if(al_GetSettingString(_T("public"),_T("IDS_ERR_NONUMBER"),theApp.m_szRes,szTxt))
			AfxMessageBox(szTxt);
		return;
	}

	if( !xCheckEmailData() )
		return;

	DEQPHONEDATA deqData;
	CPhoneData data;
	//name
	if(m_edFirstName.GetWindowText(szTxt,MAX_PATH) > 0){
		data.SetType(PBK_Text_FirstName);
		data.SetText(szTxt);
		deqData.push_back(data);
	}
	if(m_edLastName.GetWindowText(szTxt,MAX_PATH) > 0){
		data.SetType(PBK_Text_LastName);
		data.SetText(szTxt);
		deqData.push_back(data);
	}
	//check type
	CWnd *pDataEdWnd[7] = {&m_edData1,&m_edData2,&m_edData3,&m_edData4,&m_edData5,&m_edData6,&m_edData7};
	CComboBox *pDataTypeCbWnd[7] = {&m_cbType1,&m_cbType2,&m_cbType3,&m_cbType4,&m_cbType5,&m_cbType6,&m_cbType7};
	for(int i=0 ; i<7 ;i++)
	{
		if(pDataEdWnd[i]->GetWindowText(szTxt,MAX_PATH)>0)
		{
			switch(pDataTypeCbWnd[i]->GetCurSel()){
			case 0:		//mobile
				data.SetType(PBK_Number_Mobile);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 1:		//home
				data.SetType(PBK_Number_Home);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 2:		//company
				data.SetType(PBK_Number_Work);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 3:		//fax
				data.SetType(PBK_Number_Fax);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 4:		//pager
				data.SetType(PBK_Number_Pager);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 5:		//general
				data.SetType(PBK_Number_General);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			}
		}
	}
	CWnd *pEmailEdWnd[2] = {&m_edEmail1,&m_edEmail2};
	CComboBox *pEmailTypeCbWnd[2] = {&m_cbEmail1,&m_cbEmail2};
	for( i=0 ;i<2;i++)
	{
		if(pEmailEdWnd[i]->GetWindowText(szTxt,MAX_PATH)>0)
		{
			switch(pEmailTypeCbWnd[i]->GetCurSel()){
			case 0:		//personal
				data.SetType(PBK_Text_Email_Home);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 1:		//work
				data.SetType(PBK_Text_Email_Work);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			case 2:		//other
				data.SetType(PBK_Text_Email);
				data.SetText(szTxt);
				deqData.push_back(data);
				break;
			}
		}	
	}
	//group
	///-------------------------------------------
	data.SetType(PBK_Caller_Group);			
	data.SetNumber(m_cbGroup.GetCurSel()+1);
	deqData.push_back(data);
	//detain data
	for(DEQPHONEDATA::iterator iter = m_deqDetainData.begin() ; iter != m_deqDetainData.end() ; iter ++){
		deqData.push_back(*iter);
	}

	///for new Data  ++
	//birthday
	if(m_scBirthday.GetStyle() & WS_VISIBLE)
	{
		if( m_chBirthday.GetCheck() )	{
			COleDateTime tm;
			m_dpBirthday.GetTime(tm);
			data.SetType(PBK_Date);
			data.SetDate(tm);
			deqData.push_back(data);
		}
	}
	//NickName
	if(m_edNickName.GetStyle() & WS_VISIBLE)
	{
		if(m_edNickName.GetWindowText(szTxt,MAX_PATH) > 0 ){
			data.SetType(PBK_Text_Nickname);
			data.SetText(szTxt);
			deqData.push_back(data);
		}
	}
//Address
	TCHAR szAddress[MAX_PATH*10];
	if(m_edAddress1.GetStyle() & WS_VISIBLE && m_edAddress1.GetWindowText(szAddress,MAX_PATH) > 0)
	{
		int nCurSel = m_cbAddress1.GetCurSel();
		switch(nCurSel)
		{
		case 0:
			data.SetType(PBK_Text_Postal_Home);
			break;
		case 1:
			data.SetType(PBK_Text_Postal_Work);
			break;
		case 2:
			data.SetType(PBK_Text_Postal);
			break;
		}
		TCHAR szStreet1[MAX_PATH],szStreet2[MAX_PATH], szCity[MAX_PATH], szState[MAX_PATH], szZIP[MAX_PATH], szCountry[MAX_PATH];
		MotoSpriteAddress( 
			szAddress, 
			szStreet1, 
			szStreet2, 
			szCity,
			szState,
			szZIP, 
			szCountry );

		CString strAddress;
		strAddress.Format(_T("%s;%s;%s;%s;%s;%s"),szStreet2,szStreet1,szCity,szState,szZIP,szCountry);

		data.SetText(strAddress);
		deqData.push_back(data);
	}
	if(m_edAddress2.GetStyle() & WS_VISIBLE && m_edAddress2.GetWindowText(szAddress,MAX_PATH) > 0)
	{
		int nCurSel = m_cbAddress2.GetCurSel();
		switch(nCurSel)
		{
		case 0:
			data.SetType(PBK_Text_Postal_Home);
			break;
		case 1:
			data.SetType(PBK_Text_Postal_Work);
			break;
		case 2:
			data.SetType(PBK_Text_Postal);
			break;
		}
		TCHAR szStreet1[MAX_PATH],szStreet2[MAX_PATH], szCity[MAX_PATH], szState[MAX_PATH], szZIP[MAX_PATH], szCountry[MAX_PATH];
		MotoSpriteAddress( 
			szAddress, 
			szStreet1, 
			szStreet2, 
			szCity,
			szState,
			szZIP, 
			szCountry );

		CString strAddress;
		strAddress.Format(_T("%s;%s;%s;%s;%s;%s"),szStreet2,szStreet1,szCity,szState,szZIP,szCountry);

		data.SetText(strAddress);
		deqData.push_back(data);
	}
/*	TCHAR szStreet1[MAX_PATH],szStreet2[MAX_PATH], szCity[MAX_PATH], szState[MAX_PATH], szZIP[MAX_PATH], szCountry[MAX_PATH];
	szStreet1[0] = szStreet2[0] = szCity[0] = szState[0] = szZIP[0] = szCountry[0] ='\0';
	//street1
	if(m_edStreet1.GetStyle() & WS_VISIBLE)
		m_edStreet1.GetWindowText(szStreet1,MAX_PATH);
	if(m_edStreet2.GetStyle() & WS_VISIBLE)
		m_edStreet2.GetWindowText(szStreet2,MAX_PATH);
	if(m_edState.GetStyle() & WS_VISIBLE)
		m_edState.GetWindowText(szState,MAX_PATH);
	if(m_edZip.GetStyle() & WS_VISIBLE)
		m_edZip.GetWindowText(szZIP,MAX_PATH);
	if(m_edCity.GetStyle() & WS_VISIBLE)
		m_edCity.GetWindowText(szCity,MAX_PATH);
	if(m_edCountry.GetStyle() & WS_VISIBLE)
		m_edCountry.GetWindowText(szCountry,MAX_PATH);
	if( _tcslen(szStreet1) > 0 || _tcslen(szStreet2) > 0  || _tcslen(szState) > 0 ||  _tcslen(szZIP) > 0 || 
		_tcslen(szCity) > 0 || _tcslen(szCountry) > 0 )
	{
		int nCurSel = m_cbAddress.GetCurSel();
		switch(nCurSel)
		{
		case 0:
			data.SetType(PBK_Text_Postal_Home);
			break;
		case 1:
			data.SetType(PBK_Text_Postal_Work);
			break;
		case 2:
			data.SetType(PBK_Text_Postal);
			break;
		}
		MotoMargeAddress( szTxt, szStreet2, szStreet1, szCity, szState , szZIP, szCountry );
		data.SetText(szTxt);
		deqData.push_back(data);
	}*/
	///for new Data  ---
	if(m_edURL1.GetStyle() & WS_VISIBLE)
	{
		if(m_edURL1.GetWindowText(szTxt,MAX_PATH) > 0 ){
			data.SetType(PBK_Text_URL);
			data.SetText(szTxt);
			deqData.push_back(data);
		}
	}
	if(m_edURL2.GetStyle() & WS_VISIBLE)
	{
		if(m_edURL2.GetWindowText(szTxt,MAX_PATH) > 0 ){
			data.SetType(PBK_Text_URL);
			data.SetText(szTxt);
			deqData.push_back(data);
		}
	}
	if(m_edNote.GetStyle() & WS_VISIBLE)
	{
		if(m_edNote.GetWindowText(szTxt,MAX_PATH) > 0 ){
			data.SetType(PBK_Text_Note);
			data.SetText(szTxt);
			deqData.push_back(data);
		}
	}
	
	m_pData->SetPhoneData(deqData);

	if(m_rdSIM.GetCheck())
		m_pData->SetStorageType(SIM_NAME);
	else
		m_pData->SetStorageType(MEMORY_NAME);

	CBaseDlg::OnOK();
}

void CMotoEDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CBaseDlg::OnCancel();
}


void CMotoEDlg::xEnableControl(int iState)
{
	CWnd *pWnd[31] = {&m_edFirstName,&m_edLastName,&m_cbType1,&m_cbType2,&m_cbType3,&m_cbType4,&m_cbType5,&m_cbType6,&m_cbType7,
		&m_edData1,&m_edData2,&m_edData3,&m_edData4,&m_edData5,&m_edData6,&m_edData7,
		&m_cbEmail1,&m_cbEmail2,&m_edEmail1,&m_edEmail2,&m_cbAddress1,&m_cbAddress2,&m_edAddress1,&m_edAddress2,&m_cbGroup ,//};
		&m_dpBirthday,&m_chBirthday,&m_edNickName,&m_edURL1,&m_edURL2,&m_edNote};
	if(iState == ENABLE_SIM){
		pWnd[0]->EnableWindow(TRUE);
		pWnd[1]->EnableWindow(FALSE);
		pWnd[2]->EnableWindow(FALSE);
		for(int i = 3 ; i < 31 ; i ++){
			pWnd[i]->EnableWindow(FALSE);
		}
		pWnd[9]->EnableWindow(TRUE);
		m_scFirstName.SetWindowText(m_szName);
	}
	else if(iState == ENABLE_ME){
		for(int i = 0 ; i < 31 ; i ++){
			pWnd[i]->EnableWindow(TRUE);
		}
		m_scFirstName.SetWindowText(m_szFirstName);
	}
	else if(iState == ENABLE_VIEW){
		for(int i = 0 ; i < 31 ; i ++){
			pWnd[i]->EnableWindow(FALSE);
		}
		m_rdSIM.EnableWindow(FALSE);
		m_rdME.EnableWindow(FALSE);
		m_scFirstName.SetWindowText(m_szFirstName);
	}
	OnChBirthday();
}

CMotoEDlg::xSetComboItem()
{
	//set group combo item
	int iCount = 0;
	TCHAR szTxt[MAX_PATH];
	//get group count
	::SendMessage(afxGetMainWnd()->GetSafeHwnd(),WM_CARDPANEL_GROUPCOUNT,reinterpret_cast<WPARAM>(&iCount),0);
	if(iCount > 0){
		for(int i = 1 ; i <= iCount ; i ++){
			//get group item
			::SendMessage(afxGetMainWnd()->GetSafeHwnd(),WM_CARDPANEL_GETGROUP,i,reinterpret_cast<WPARAM>(szTxt));
			//add to combo
			m_cbGroup.AddString(szTxt);
		}
		m_cbGroup.SetCurSel(0);
	}

	//set type item
	TCHAR szType[6][32]={_T("IDS_M_MOBILE"),_T("IDS_M_HOME"),_T("IDS_M_COMPANY"),_T("IDS_M_FAX"),_T("IDS_M_BBCALL")
		,_T("IDS_N_OTHER")};
	for(int i = 0 ; i < 6 ; i ++){
		if(al_GetSettingString(_T("public"),szType[i],theApp.m_szRes,szTxt))
			m_cbType1.AddString(szTxt);
			m_cbType2.AddString(szTxt);
			m_cbType3.AddString(szTxt);
			m_cbType4.AddString(szTxt);
			m_cbType5.AddString(szTxt);
			m_cbType6.AddString(szTxt);
			m_cbType7.AddString(szTxt);
	}
	m_cbType1.SetCurSel(0);
	m_cbType2.SetCurSel(1);
	m_cbType3.SetCurSel(2);
	m_cbType4.SetCurSel(3);
	m_cbType5.SetCurSel(4);
	m_cbType6.SetCurSel(5);
	m_cbType7.SetCurSel(0);

	//Email Type
	TCHAR szTypeTxt[4][MAX_PATH];
	szTypeTxt[0][0] = szTypeTxt[1][0] = szTypeTxt[2][0] = szTypeTxt[3][0] ='\0';
	TCHAR szTextType[4][32]={_T("IDS_M_PERSONAL"),_T("IDS_M_WORK"),_T("IDS_N_OTHER"),_T("IDS_HOME")};
	for( i = 0 ; i < 4 ; i ++)
		al_GetSettingString(_T("public"),szTextType[i],theApp.m_szRes,szTypeTxt[i]);
	
	m_cbEmail1.AddString(szTypeTxt[0]);
	m_cbEmail1.AddString(szTypeTxt[1]);
	m_cbEmail1.AddString(szTypeTxt[2]);
	m_cbEmail1.SetCurSel(0);

	m_cbEmail2.AddString(szTypeTxt[0]);
	m_cbEmail2.AddString(szTypeTxt[1]);
	m_cbEmail2.AddString(szTypeTxt[2]);
	m_cbEmail2.SetCurSel(1);

	m_cbAddress1.AddString(szTypeTxt[3]);
	m_cbAddress1.AddString(szTypeTxt[1]);
	m_cbAddress1.AddString(szTypeTxt[2]);
	m_cbAddress1.SetCurSel(0);

	m_cbAddress2.AddString(szTypeTxt[3]);
	m_cbAddress2.AddString(szTypeTxt[1]);
	m_cbAddress2.AddString(szTypeTxt[2]);
	m_cbAddress2.SetCurSel(1);

}

CMotoEDlg::xSetDataToDlgCtrl()
{
	TCHAR szDataText[MAX_PATH];
	int iNumber = 0,iAddress = 0,iEmail = 0,iURL = 0;
	szDataText[0] ='\0';
	CString strName;
	strName.Empty();
	CComboBox *pPhoneCombo[7] = {&m_cbType1,&m_cbType2,&m_cbType3,&m_cbType4,&m_cbType5,&m_cbType6,&m_cbType7};
	CMyEdit *pPhoneEdit[7] = {&m_edData1,&m_edData2,&m_edData3,&m_edData4,&m_edData5,&m_edData6,&m_edData7};

	CComboBox *pEmailCombo[2] = {&m_cbEmail1,&m_cbEmail2};
	CMyEdit *pEmailEdit[2] = {&m_edEmail1,&m_edEmail2};

	CComboBox *pAddressCombo[2] = {&m_cbAddress1,&m_cbAddress2};
	CMyEdit *pAddressEdit[2] = {&m_edAddress1,&m_edAddress2};

	CEdit *pURLEdit[2] = {&m_edURL1,&m_edURL2};

	if(m_pData){
		//get data deq
		DEQPHONEDATA *pdeqData; 
		pdeqData = m_pData->GetPhoneData();
		for(DEQPHONEDATA::iterator iter = pdeqData->begin() ; iter != pdeqData->end() ; iter ++){
			if((*iter).GetType() == PBK_Text_Name){		//full name
				strName.Format(_T("%s"),((*iter).GetText()));
			}
			else if((*iter).GetType() == PBK_Text_FirstName){		//name
				m_edFirstName.SetWindowText((*iter).GetText());
			}
			else if((*iter).GetType() == PBK_Text_LastName){		//name
				m_edLastName.SetWindowText((*iter).GetText());
			}
			else if((*iter).GetType() == PBK_Number_General && iNumber < 7){	//general
				pPhoneCombo[iNumber]->SetCurSel(5);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Number_Mobile && iNumber < 7){	//mobile
				pPhoneCombo[iNumber]->SetCurSel(0);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Number_Fax && iNumber < 7){	//fax
				pPhoneCombo[iNumber]->SetCurSel(3);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Number_Pager && iNumber < 7){	//B.B. Call
				pPhoneCombo[iNumber]->SetCurSel(4);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Number_Work && iNumber < 7){	//company
				pPhoneCombo[iNumber]->SetCurSel(2);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Number_Home && iNumber < 7){	//home
				pPhoneCombo[iNumber]->SetCurSel(1);
				pPhoneEdit[iNumber]->SetWindowText((*iter).GetText());
				iNumber ++;
			}
			else if((*iter).GetType() == PBK_Caller_Group){		//group
				if(strcmp(m_pData->GetStorageType(),SIM_NAME) == 0)
					m_cbGroup.SetCurSel(0);
				else
					m_cbGroup.SetCurSel((*iter).GetNumber()-1);
			}
			//email
			else if((*iter).GetType() == PBK_Text_Email_Home && iEmail <2){	//email
				pEmailCombo[iEmail]->SetCurSel(0);
				pEmailEdit[iEmail]->SetWindowText((*iter).GetText());
				iEmail ++;

			}
			else if((*iter).GetType() == PBK_Text_Email_Work&& iEmail <2){	//email
				pEmailCombo[iEmail]->SetCurSel(1);
				pEmailEdit[iEmail]->SetWindowText((*iter).GetText());
				iEmail ++;
			}
			else if((*iter).GetType() == PBK_Text_Email&& iEmail <2){	//email
				pEmailCombo[iEmail]->SetCurSel(2);
				pEmailEdit[iEmail]->SetWindowText((*iter).GetText());
				iEmail ++;
			}
//////////
			else if((*iter).GetType() == PBK_Text_Nickname){	//nickname
				m_edNickName.SetWindowText((*iter).GetText());
			}
			else if(((*iter).GetType() == PBK_Text_Postal ||(*iter).GetType() == PBK_Text_Postal_Work ||
				(*iter).GetType() == PBK_Text_Postal_Home) && iAddress <2)
			{	//Postal other
				TCHAR szStreet1[MAX_PATH],szStreet2[MAX_PATH], szCity[MAX_PATH], szState[MAX_PATH], szZIP[MAX_PATH], szCountry[MAX_PATH];
				MotoSpriteAddress( 
					(*iter).GetText(), 
					szStreet2, 
					szStreet1, 
					szCity,
					szState,
					szZIP, 
					szCountry );

				CString strAddress;
				strAddress.Format(_T("%s;%s;%s;%s;%s;%s"),szStreet1,szStreet2,szCity,szState,szZIP,szCountry);
				pAddressEdit[iAddress]->SetWindowText(strAddress);

				if((*iter).GetType() == PBK_Text_Postal) pAddressCombo[iAddress]->SetCurSel(2);
				else if((*iter).GetType() == PBK_Text_Postal_Work)pAddressCombo[iAddress]->SetCurSel(1);
				else if((*iter).GetType() == PBK_Text_Postal_Home)pAddressCombo[iAddress]->SetCurSel(0);
				iAddress++;

			}

			else if((*iter).GetType() == PBK_Date){		//birthday
				COleDateTime tm;
				(*iter).GetTime(tm);
				m_dpBirthday.SetTime(tm);
				m_chBirthday.SetCheck(1);
				if(m_iMode!=2)
					m_dpBirthday.EnableWindow(true);
			}		
			else if((*iter).GetType() == PBK_Text_URL && iURL <2){
				pURLEdit[iURL]->SetWindowText((*iter).GetText());
				iURL++;
			}
			else if((*iter).GetType() == PBK_Text_Note){
				m_edNote.SetWindowText((*iter).GetText());
			}
/////////
			else{	//others
				m_deqDetainData.push_back((*iter));
			}
		}
		CString strFirstName,strLastName;
		strFirstName.Empty();
		strLastName.Empty();
		m_edFirstName.GetWindowText(strFirstName);
		m_edLastName.GetWindowText(strLastName);
		if(strFirstName.IsEmpty() && strLastName.IsEmpty() && strName.IsEmpty()== false)
		{
			m_edFirstName.SetWindowText(strName);
		}
	}

}

BOOL CMotoEDlg::xCheckEmailData()
{
	CString str,str2;
	TCHAR szText[MAX_PATH];

	m_edEmail1.GetWindowText(str);
	m_edEmail2.GetWindowText(str2);
	if(str.GetLength()<=0 && str2.GetLength()<=0) return TRUE;
	if(str.GetLength()>0)
	{
		int nPos = str.Find('@');
		if(nPos==-1 || nPos==0 || nPos==str.GetLength()-1)	
		{
				al_GetSettingString(_T("public"), _T("IDS_ERR_EMAIL"), theApp.m_szRes, szText);
				AfxMessageBox(szText);
				return FALSE;
		}
		nPos = str.Find(' ');
		if(nPos!=-1 )	{
			al_GetSettingString(_T("public"), _T("IDS_ERR_EMAIL"), theApp.m_szRes, szText);
			AfxMessageBox(szText);
			return FALSE;
		}
	}
	if(str2.GetLength()>0)
	{
		int nPos = str2.Find('@');
		if(nPos==-1 || nPos==0 || nPos==str2.GetLength()-1)	
		{
				al_GetSettingString(_T("public"), _T("IDS_ERR_EMAIL"), theApp.m_szRes, szText);
				AfxMessageBox(szText);
				return FALSE;
		}
		nPos = str2.Find(' ');
		if(nPos!=-1 )	{
			al_GetSettingString(_T("public"), _T("IDS_ERR_EMAIL"), theApp.m_szRes, szText);
			AfxMessageBox(szText);
			return FALSE;
		}
	}

	return TRUE;
}

void CMotoEDlg::OnChBirthday() 
{
	// TODO: Add your control notification handler code here
	if(m_chBirthday.GetCheck())	
		m_dpBirthday.EnableWindow(TRUE);
	else
		m_dpBirthday.EnableWindow(FALSE);
	
}
void CMotoEDlg::EditAddress(CMyEdit* pEdit)
{
	CString strAddress;
	pEdit->GetWindowText(strAddress);
	TCHAR szStreet1[MAX_PATH],szStreet2[MAX_PATH], szCity[MAX_PATH], szState[MAX_PATH], szZIP[MAX_PATH], szCountry[MAX_PATH];

	szStreet1[0] = szStreet2[0] =szCity[0]=szState[0]=szZIP[0]=szCountry[0] ='\0';
	if(strAddress.GetLength() > 0)
	{
		MotoSpriteAddress( 
			strAddress, 
			szStreet1, 
			szStreet2, 
			szCity,
			szState,
			szZIP, 
			szCountry );
	}

	CNS4AddressDlg addressDlg;
	addressDlg.SetAddress(szStreet1,szStreet2,szCity,
		szState,szZIP,szCountry);
	if(addressDlg.DoModal() == IDOK)
	{
		CString strAddress2;
		strAddress2.Format(_T("%s;%s;%s;%s;%s;%s"),addressDlg.m_strExt,addressDlg.m_strStreet,addressDlg.m_strCity,
			addressDlg.m_strState,addressDlg.m_strZip,addressDlg.m_strCountry);
		
		pEdit->SetWindowText(strAddress2);
	}
	SetFocus();



}

void CMotoEDlg::OnSetfocusAddressEdit1() 
{
	// TODO: Add your control notification handler code here
	static bInAddressdlg = false;
	if( !bInAddressdlg)
	{
		bInAddressdlg = true;
		EditAddress(&m_edAddress1);
	}
	bInAddressdlg= false;
}
void CMotoEDlg::OnSetfocusAddressEdit2() 
{
	// TODO: Add your control notification handler code here
	static bInAddressdlg = false;
	if( !bInAddressdlg)
	{
		bInAddressdlg = true;
		EditAddress(&m_edAddress2);
	}
	bInAddressdlg= false;
}