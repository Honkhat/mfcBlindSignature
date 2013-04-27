// SideAskSendDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "SideAskSendDlg.h"
#include "afxdialogex.h"


// CSideAskSendDlg 对话框

IMPLEMENT_DYNAMIC(CSideAskSendDlg, CDialogEx)

CSideAskSendDlg::CSideAskSendDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSideAskSendDlg::IDD, pParent)
{

}

CSideAskSendDlg::~CSideAskSendDlg()
{
}

void CSideAskSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSideAskSendDlg, CDialogEx)
END_MESSAGE_MAP()


// CSideAskSendDlg 消息处理程序
