
// QQInfoDialogDlg.h : ͷ�ļ�
//

#pragma once

#include "ShowInfoDlg.h"

extern ShowInfoDlg showinfodlg;


// CQQInfoDialogDlg �Ի���
class CQQInfoDialogDlg : public CDialogEx
{
// ����
public:
	CQQInfoDialogDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_QQINFODIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
