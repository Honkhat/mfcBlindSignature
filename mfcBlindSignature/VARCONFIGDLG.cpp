// VARCONFIGDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "VARCONFIGDLG.h"
#include "afxdialogex.h"


// VARCONFIGDLG �Ի���

IMPLEMENT_DYNAMIC(VARCONFIGDLG, CDialogEx)

VARCONFIGDLG::VARCONFIGDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(VARCONFIGDLG::IDD, pParent)
{

}

VARCONFIGDLG::~VARCONFIGDLG()
{
}

void VARCONFIGDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(VARCONFIGDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &VARCONFIGDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// VARCONFIGDLG ��Ϣ�������


void VARCONFIGDLG::OnBnClickedOk()
{
	//��ȡ�����ϵ���ֵ
	CString cstr;
	wchar_t WcharArr[10]={0};
	char CharArr[10]={0};

	GetDlgItemText(IDC_E_RANDDIGITS,cstr);
	if(!cstr.IsEmpty())
	{
		memcpy(WcharArr,cstr.GetString(),10);
		WideCharToMultiByte(CP_ACP,0,WcharArr,-1,CharArr,10,NULL,NULL);
		m_iRandDigits=atoi(CharArr);
		if(m_iRandDigits<64)
		{
			MessageBox(L"ָ�������λ��̫С!(���>64)",L"����",MB_OK);
			return;
		}
	}
	else
	{
		MessageBox(L"�����ֵλ������Ϊ��!",L"����",MB_OK);
		return;
	}

	GetDlgItemText(IDC_E_BLINDFACTOR,cstr);
	if(!cstr.IsEmpty())
	{
		memcpy(WcharArr,cstr.GetString(),10);
		WideCharToMultiByte(CP_ACP,0,WcharArr,-1,CharArr,10,NULL,NULL);
		m_k=atoi(CharArr);
		if(m_k<10)
		{
			MessageBox(L"ָ����ä������̫С!(һ�����10)",L"����",MB_OK);
			return;
		}
	}
	else
	{
		MessageBox(L"ä�����Ӳ���Ϊ��!",L"����",MB_OK);
		return;
	}
	CDialogEx::OnOK();
}
