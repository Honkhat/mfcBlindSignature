
// mfcBlindSignature.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CmfcBlindSignatureApp:
// �йش����ʵ�֣������ mfcBlindSignature.cpp
//

class CmfcBlindSignatureApp : public CWinApp
{
public:
	CmfcBlindSignatureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CmfcBlindSignatureApp theApp;