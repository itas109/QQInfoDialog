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

#if !defined(AFX_SHOWINFODLG_H__273027B9_8244_4624_BC2B_44491EA67BE8__INCLUDED_)
#define AFX_SHOWINFODLG_H__273027B9_8244_4624_BC2B_44491EA67BE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowInfoDlg.h : header file
//
#include "resource.h" //IDD_DIALOG_SHOWINFO��ͷ�ļ�


//���嶯������
#define AW_CENTER            0x00000010    // ��ʹ����AW_HIDE��־����ʹ���������ص������������ڣ���δʹ��AW_HIDE��־����ʹ����������չ����չ������
#define AW_HOR_POSITIVE      0x00000001	   // ����������ʾ���ڡ��ñ�־�����ڹ��������ͻ���������ʹ�á���ʹ��AW_CENTER��־ʱ���ñ�־��������
#define AW_HOR_NEGATIVE      0x00000002
#define AW_VER_POSITIVE      0x00000004	   // �Զ�������ʾ���ڡ��ñ�־�����ڹ��������ͻ���������ʹ�á���ʹ��AW_CENTER��־ʱ���ñ�־��������
#define AW_VER_NEGATIVE      0x00000008    // ����������ʾ���ڡ��ñ�־�����ڹ��������ͻ���������ʹ�á���ʹ��AW_CENTER��־ʱ���ñ�־��������

#define AW_HIDE              0x00010000    // ���ش��ڣ�ȱʡ����ʾ����
#define AW_ACTIVATE          0x00020000    // ����ڡ���ʹ����AW_HIDE��־����ʹ�������־
#define AW_SLIDE             0x00040000	   // ʹ�û������͡�ȱʡ��Ϊ�����������͡���ʹ��AW_CENTER��־ʱ�������־�ͱ�����
#define AW_BLEND             0x00080000    // ʵ�ֵ���Ч����ֻ�е�hWndΪ���㴰�ڵ�ʱ��ſ���ʹ�ô˱�־

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
	//���DLG�ı䣬�˴��޸�Ϊ��Ҫ��ʾ��DLG��IDD GX 20150826
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
