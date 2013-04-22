// HelpImpFile.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "HelpImpFile.h"
#include "afxdialogex.h"


// HelpImpFile 对话框

IMPLEMENT_DYNAMIC(HelpImpFile, CDialogEx)

HelpImpFile::HelpImpFile(CWnd* pParent /*=NULL*/)
	: CDialogEx(HelpImpFile::IDD, pParent)
{

}

HelpImpFile::~HelpImpFile()
{
}

void HelpImpFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HelpImpFile, CDialogEx)
END_MESSAGE_MAP()


// HelpImpFile 消息处理程序
