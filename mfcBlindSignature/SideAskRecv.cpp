// SideAskRecv.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "SideAskRecv.h"
#include "afxdialogex.h"


// CSideAskRecv 对话框

IMPLEMENT_DYNAMIC(CSideAskRecv, CDialogEx)

CSideAskRecv::CSideAskRecv(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSideAskRecv::IDD, pParent)
{

}

CSideAskRecv::~CSideAskRecv()
{
}

void CSideAskRecv::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSideAskRecv, CDialogEx)
END_MESSAGE_MAP()


// CSideAskRecv 消息处理程序
