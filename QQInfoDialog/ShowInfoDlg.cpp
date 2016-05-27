/*
**	FILENAME			ShowInfoDlg.h
**
**	PURPOSE				���������Ѻõĵ�����ʾ���ڣ����Ҳ�ռ�������ڵĽ��㡣
**						��ʾ��Ϣ����Ĵ�С����ɫ�ȿ�������
**						Ĭ�ϵ����������������������½�
**						
**
**	CREATION DATE		2015-09-01
**	LAST MODIFICATION	2015-09-01
**
**	AUTHOR				itas109
**	Blog                blog.csdn.net/itas109
**
*/

// ShowInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ShowInfoDlg dialog


ShowInfoDlg::ShowInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ShowInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ShowInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ShowInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShowInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL ShowInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	// ��������С
	CRect rectWorkArea;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWorkArea, SPIF_SENDCHANGE);  
	// ��öԻ����С
	CRect rectDlg;
	GetWindowRect(&rectDlg);
	int nW = rectDlg.Width();
	int nH = rectDlg.Height();
	// CWnd::SetWindowPos See from MSDN
	//�����������½���ʾ
	//SWP_NOACTIVATE �����ö�������
	SetWindowPos(&CWnd::wndTopMost, rectWorkArea.right-nW-5, rectWorkArea.bottom-nH-5, nW, nH, SWP_NOACTIVATE); // �����ö�������
	
	//���弰��С
	m_font.CreatePointFont(180,"����");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


BEGIN_MESSAGE_MAP(ShowInfoDlg, CDialog)
	//{{AFX_MSG_MAP(ShowInfoDlg)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ShowInfoDlg message handlers

void ShowInfoDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == KILL_SHOW_DLG)
	{
		/*
		HINSTANCE hInst = LoadLibrary("User32.DLL");
		typedef BOOL(WINAPI MYFUNC(HWND, DWORD, DWORD));
		// ��������
		MYFUNC* AnimateWindow;	
		AnimateWindow = (MYFUNC*)::GetProcAddress(hInst, "AnimateWindow");
		AnimateWindow(this->GetSafeHwnd(), 200, AW_HIDE | AW_BLEND);
		FreeLibrary(hInst);	
		*/
		CDialog::OnOK();

		//���ַ�ʽ���ܵ�ʱ���Ӱ�� ��Ϊ��ʱ������ʱ
		//CMainFrame *pMainFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;//��ǰ����������ڵ�ָ��
		//::SetActiveWindow(pMainFrame->m_hWnd);//���������ڳ��򣬰ѽ��㻹��������

		KillTimer(KILL_SHOW_DLG);
	}
		
	CDialog::OnTimer(nIDEvent);
}

void ShowInfoDlg::ShowDlg(CString str, int showType/* =1 */, int showTimeMS /* = 500 */)
{
	//ֻ�ı������С����������
	//this->GetDlgItem(IDC_STATIC_TIP)->SetFont(&m_font);
	//��������
	this->GetDlgItem(IDC_STATIC_TIP)->SetWindowText(_T(str));
	
	ShowType(showType);
	SetTimer(KILL_SHOW_DLG, showTimeMS, NULL);
}

void ShowInfoDlg::ShowType(int nType /* = 1 */)
{
	if (1 == nType)
	{
		// ���롢����
		// CenterWindow();		// �Ի���������λ��
		HINSTANCE hInst = LoadLibrary("User32.DLL");	// ���붯̬���ӿ�User32.DLL
		typedef BOOL(WINAPI MYFUNC(HWND hwnd, DWORD dwTime, DWORD dwFlags));//dwTime����������ʱ�䣨��׼200ms��	
		// ��������
		MYFUNC* AnimateWindow;
		AnimateWindow = (MYFUNC*)::GetProcAddress(hInst, "AnimateWindow");
		AnimateWindow(this->m_hWnd, 300, AW_BLEND);
		FreeLibrary(hInst);		
	}
	else if (2 == nType)
	{
		// ��������
		HINSTANCE hInst = LoadLibrary("user32.dll");
		typedef UINT(WINAPI* PMYFUNC)(HWND hwnd, DWORD dwTime,DWORD dwFlags);
		// ��������
		PMYFUNC pAnimateWindow;	
		if(NULL != hInst)
		{
			pAnimateWindow = (PMYFUNC)::GetProcAddress(hInst, "AnimateWindow");
			pAnimateWindow(GetSafeHwnd(), 300, AW_SLIDE | AW_VER_NEGATIVE);
			FreeLibrary(hInst);
		}		
	}
	
	//Sleep��ʹCPU��ͣ ������ʹ�øú���
	//DLG��ʾʱ��
	//Sleep(showTimeMS);
}


HBRUSH ShowInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TIP)
	{
		//pDC->SetBkMode(TRANSPARENT);//���屳��͸��

		pDC->SetTextColor(RGB(255,0,0));//������ɫ

		pDC->SelectObject(&m_font);//�����С

	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
