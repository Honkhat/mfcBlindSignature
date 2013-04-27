// BlindSignTool.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "BlindSignTool.h"
#include "afxdialogex.h"


// CBlindSignTool 对话框

IMPLEMENT_DYNAMIC(CBlindSignTool, CDialogEx)

CBlindSignTool::CBlindSignTool(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBlindSignTool::IDD, pParent)
{

}

CBlindSignTool::~CBlindSignTool()
{
}

void CBlindSignTool::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABSIDE, m_tabSide);
}


BEGIN_MESSAGE_MAP(CBlindSignTool, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABSIDE, &CBlindSignTool::OnTcnSelchangeTabside)
END_MESSAGE_MAP()


// CBlindSignTool 消息处理程序


BOOL CBlindSignTool::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//密钥配置应该只对签名方可见
	m_tabSide.InsertItem(0,L"签名请求方");
	m_tabSide.InsertItem(1,L"签名方");

	m_dlgSideAsk.Create(IDD_DLG_ASK,GetDlgItem(IDC_TABSIDE));
	m_dlgSideSign.Create(IDD_DLG_SIGN,GetDlgItem(IDC_TABSIDE));

	CRect rect;
	m_tabSide.GetClientRect(&rect);

	rect.top+=20;
	m_dlgSideAsk.MoveWindow(&rect);
	m_dlgSideSign.MoveWindow(&rect);

	m_dlgSideAsk.ShowWindow(true);
	m_dlgSideSign.ShowWindow(false);

	m_tabSide.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CBlindSignTool::OnTcnSelchangeTabside(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel=m_tabSide.GetCurSel();
	switch(nCurSel)
	{
	case 0:
		m_dlgSideAsk.ShowWindow(true);
		m_dlgSideSign.ShowWindow(false);
		break;
	case 1:
		m_dlgSideAsk.ShowWindow(false);
		m_dlgSideSign.ShowWindow(true);
		break;
	}
	*pResult = 0;
}
