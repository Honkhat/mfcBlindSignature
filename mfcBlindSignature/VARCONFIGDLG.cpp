// VARCONFIGDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "VARCONFIGDLG.h"
#include "afxdialogex.h"


// VARCONFIGDLG 对话框

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


// VARCONFIGDLG 消息处理程序


void VARCONFIGDLG::OnBnClickedOk()
{
	//获取界面上的数值
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
			MessageBox(L"指定的随机位数太小!(最好>64)",L"警告",MB_OK);
			return;
		}
	}
	else
	{
		MessageBox(L"随机数值位数不可为空!",L"错误",MB_OK);
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
			MessageBox(L"指定的盲化因子太小!(一般大于10)",L"警告",MB_OK);
			return;
		}
	}
	else
	{
		MessageBox(L"盲化因子不可为空!",L"错误",MB_OK);
		return;
	}
	CDialogEx::OnOK();
}
