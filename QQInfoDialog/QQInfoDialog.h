
// QQInfoDialog.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CQQInfoDialogApp:
// �йش����ʵ�֣������ QQInfoDialog.cpp
//

class CQQInfoDialogApp : public CWinApp
{
public:
	CQQInfoDialogApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CQQInfoDialogApp theApp;