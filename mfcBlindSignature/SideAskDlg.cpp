// SideAskDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "SideAskDlg.h"
#include "afxdialogex.h"


// CSideAskDlg 对话框

IMPLEMENT_DYNAMIC(CSideAskDlg, CDialogEx)

CSideAskDlg::CSideAskDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSideAskDlg::IDD, pParent)
{

}

CSideAskDlg::~CSideAskDlg()
{
}

void CSideAskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SIDEASK, m_tabSideAsk);
}


BEGIN_MESSAGE_MAP(CSideAskDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SIDEASK, &CSideAskDlg::OnTcnSelchangeTabSideask)
END_MESSAGE_MAP()


// CSideAskDlg 消息处理程序


BOOL CSideAskDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tabSideAsk.InsertItem(0,L"发送模式");
	m_tabSideAsk.InsertItem(1,L"接收模式");

	m_dlgSideAskSend.Create(IDD_DLG_SIDEASK_SEND,GetDlgItem(IDC_TAB_SIDEASK));
	m_dlgSideAskRecv.Create(IDD_DLG_SIDEASK_RECV,GetDlgItem(IDC_TAB_SIDEASK));

	CRect rect;
	m_tabSideAsk.GetClientRect(&rect);
	rect.top+=20;

	m_dlgSideAskSend.MoveWindow(&rect);
	m_dlgSideAskRecv.MoveWindow(&rect);

	m_dlgSideAskSend.ShowWindow(true);
	m_dlgSideAskRecv.ShowWindow(false);

	m_tabSideAsk.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSideAskDlg::OnTcnSelchangeTabSideask(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel=m_tabSideAsk.GetCurSel();
	switch(nCurSel)
	{
	case 0:
		m_dlgSideAskSend.ShowWindow(true);
		m_dlgSideAskRecv.ShowWindow(false);
		break;
	case 1:
		m_dlgSideAskSend.ShowWindow(false);
		m_dlgSideAskRecv.ShowWindow(true);
		break;
	}
	*pResult = 0;
}
