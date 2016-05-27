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

#if !defined(AFX_SHOWINFODLG_H__273027B9_8244_4624_BC2B_44491EA67BE8__INCLUDED_)
#define AFX_SHOWINFODLG_H__273027B9_8244_4624_BC2B_44491EA67BE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowInfoDlg.h : header file
//
#include "resource.h" //IDD_DIALOG_SHOWINFO的头文件


//定义动画类型
#define AW_CENTER            0x00000010    // 若使用了AW_HIDE标志，则使窗口向内重叠，即收缩窗口；若未使用AW_HIDE标志，则使窗口向外扩展，即展开窗口
#define AW_HOR_POSITIVE      0x00000001	   // 自左向右显示窗口。该标志可以在滚动动画和滑动动画中使用。当使用AW_CENTER标志时，该标志将被忽略
#define AW_HOR_NEGATIVE      0x00000002
#define AW_VER_POSITIVE      0x00000004	   // 自顶向下显示窗口。该标志可以在滚动动画和滑动动画中使用。当使用AW_CENTER标志时，该标志将被忽略
#define AW_VER_NEGATIVE      0x00000008    // 自下向上显示窗口。该标志可以在滚动动画和滑动动画中使用。当使用AW_CENTER标志时，该标志将被忽略

#define AW_HIDE              0x00010000    // 隐藏窗口，缺省则显示窗口
#define AW_ACTIVATE          0x00020000    // 激活窗口。在使用了AW_HIDE标志后不能使用这个标志
#define AW_SLIDE             0x00040000	   // 使用滑动类型。缺省则为滚动动画类型。当使用AW_CENTER标志时，这个标志就被忽略
#define AW_BLEND             0x00080000    // 实现淡出效果。只有当hWnd为顶层窗口的时候才可以使用此标志

#define KILL_SHOW_DLG        1000

/////////////////////////////////////////////////////////////////////////////
// ShowInfoDlg dialog

class ShowInfoDlg : public CDialog
{
// Construction
public:
	void ShowDlg(CString str, int showType=1, int showTimeMS = 2000);
	ShowInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ShowInfoDlg)
	//如果DLG改变，此处修改为需要显示的DLG的IDD GX 20150826
	enum { IDD = IDD_DIALOG_SHOWINFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShowInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ShowInfoDlg)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush* m_Brush;
	CFont m_font;

	void ShowType(int nType = 1);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWINFODLG_H__273027B9_8244_4624_BC2B_44491EA67BE8__INCLUDED_)
