/*
**	FILENAME			ShowInfoDlg.h
**
**	PURPOSE				这个类可以友好的弹出提示窗口，并且不占用主窗口的焦点。
**						提示信息字体的大小和颜色等可以设置
**						默认弹出框在桌面可用区域的右下角
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

	// 获得桌面大小
	CRect rectWorkArea;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWorkArea, SPIF_SENDCHANGE);  
	// 获得对话框大小
	CRect rectDlg;
	GetWindowRect(&rectDlg);
	int nW = rectDlg.Width();
	int nH = rectDlg.Height();
	// CWnd::SetWindowPos See from MSDN
	//工作区域右下角显示
	//SWP_NOACTIVATE 窗口置顶不激活
	SetWindowPos(&CWnd::wndTopMost, rectWorkArea.right-nW-5, rectWorkArea.bottom-nH-5, nW, nH, SWP_NOACTIVATE); // 窗口置顶不激活
	
	//字体及大小
	m_font.CreatePointFont(180,"宋体");

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
		// 声明函数
		MYFUNC* AnimateWindow;	
		AnimateWindow = (MYFUNC*)::GetProcAddress(hInst, "AnimateWindow");
		AnimateWindow(this->GetSafeHwnd(), 200, AW_HIDE | AW_BLEND);
		FreeLibrary(hInst);	
		*/
		CDialog::OnOK();

		//这种方式会受到时间的影响 因为定时器有延时
		//CMainFrame *pMainFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;//当前程序的主窗口的指针
		//::SetActiveWindow(pMainFrame->m_hWnd);//激活主窗口程序，把焦点还给主窗口

		KillTimer(KILL_SHOW_DLG);
	}
		
	CDialog::OnTimer(nIDEvent);
}

void ShowInfoDlg::ShowDlg(CString str, int showType/* =1 */, int showTimeMS /* = 500 */)
{
	//只改变字体大小和字体类型
	//this->GetDlgItem(IDC_STATIC_TIP)->SetFont(&m_font);
	//窗体文字
	this->GetDlgItem(IDC_STATIC_TIP)->SetWindowText(_T(str));
	
	ShowType(showType);
	SetTimer(KILL_SHOW_DLG, showTimeMS, NULL);
}

void ShowInfoDlg::ShowType(int nType /* = 1 */)
{
	if (1 == nType)
	{
		// 淡入、淡出
		// CenterWindow();		// 对话框处于中心位置
		HINSTANCE hInst = LoadLibrary("User32.DLL");	// 导入动态链接库User32.DLL
		typedef BOOL(WINAPI MYFUNC(HWND hwnd, DWORD dwTime, DWORD dwFlags));//dwTime动画持续的时间（标准200ms）	
		// 声明函数
		MYFUNC* AnimateWindow;
		AnimateWindow = (MYFUNC*)::GetProcAddress(hInst, "AnimateWindow");
		AnimateWindow(this->m_hWnd, 300, AW_BLEND);
		FreeLibrary(hInst);		
	}
	else if (2 == nType)
	{
		// 从下向上
		HINSTANCE hInst = LoadLibrary("user32.dll");
		typedef UINT(WINAPI* PMYFUNC)(HWND hwnd, DWORD dwTime,DWORD dwFlags);
		// 声明函数
		PMYFUNC pAnimateWindow;	
		if(NULL != hInst)
		{
			pAnimateWindow = (PMYFUNC)::GetProcAddress(hInst, "AnimateWindow");
			pAnimateWindow(GetSafeHwnd(), 300, AW_SLIDE | AW_VER_NEGATIVE);
			FreeLibrary(hInst);
		}		
	}
	
	//Sleep会使CPU暂停 尽量不使用该函数
	//DLG显示时间
	//Sleep(showTimeMS);
}


HBRUSH ShowInfoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TIP)
	{
		//pDC->SetBkMode(TRANSPARENT);//字体背景透明

		pDC->SetTextColor(RGB(255,0,0));//字体颜色

		pDC->SelectObject(&m_font);//字体大小

	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
