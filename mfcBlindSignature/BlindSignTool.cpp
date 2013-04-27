// BlindSignTool.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "BlindSignTool.h"
#include "afxdialogex.h"


// CBlindSignTool �Ի���

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


// CBlindSignTool ��Ϣ�������


BOOL CBlindSignTool::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��Կ����Ӧ��ֻ��ǩ�����ɼ�
	m_tabSide.InsertItem(0,L"ǩ������");
	m_tabSide.InsertItem(1,L"ǩ����");

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
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CBlindSignTool::OnTcnSelchangeTabside(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
