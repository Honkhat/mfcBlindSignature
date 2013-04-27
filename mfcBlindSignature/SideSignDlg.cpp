// SideSignDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "SideSignDlg.h"
#include "afxdialogex.h"


// CSideSignDlg 对话框

IMPLEMENT_DYNAMIC(CSideSignDlg, CDialogEx)

CSideSignDlg::CSideSignDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSideSignDlg::IDD, pParent)
{

}

CSideSignDlg::~CSideSignDlg()
{
}

void CSideSignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSideSignDlg, CDialogEx)
//	ON_EN_CHANGE(IDC_E_RECVFILE, &CSideSignDlg::OnEnChangeERecvfile)
	ON_BN_CLICKED(IDC_RADIO_CONFIG, &CSideSignDlg::OnBnClickedRadioConfig)
	ON_BN_CLICKED(IDC_RADIO_SIGN, &CSideSignDlg::OnBnClickedRadioSign)
END_MESSAGE_MAP()




BOOL CSideSignDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//default:SignMode
	CheckRadioButton(IDC_RADIO_CONFIG,IDC_RADIO_SIGN,IDC_RADIO_SIGN);
	//make the stuff invisible
	GetDlgItem(IDC_BTN_RANDGEN)->EnableWindow(false);
	GetDlgItem(IDC_BTN_RANDGEN)->ShowWindow(false);
	GetDlgItem(IDC_SE_TOOLE)->ShowWindow(false);
	GetDlgItem(IDC_E_TOOLE)->EnableWindow(false);
	GetDlgItem(IDC_E_TOOLE)->ShowWindow(false);
	GetDlgItem(IDC_SE_TOOLD)->ShowWindow(false);
	GetDlgItem(IDC_E_TOOLD)->EnableWindow(false);
	GetDlgItem(IDC_E_TOOLD)->ShowWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSideSignDlg::OnBnClickedRadioConfig()
{
	//make the stuff unenable and invisible
	GetDlgItem(IDC_E_RECVFILE)->EnableWindow(false);
	GetDlgItem(IDC_E_RECVFILE)->ShowWindow(false);
	GetDlgItem(IDC_BTN_RECVMD5)->EnableWindow(false);
	GetDlgItem(IDC_BTN_RECVMD5)->ShowWindow(false);
	GetDlgItem(IDC_E_SIGN)->EnableWindow(false);
	GetDlgItem(IDC_E_SIGN)->ShowWindow(false);
	GetDlgItem(IDC_BTN_SIGN)->EnableWindow(false);
	GetDlgItem(IDC_BTN_SIGN)->ShowWindow(false);
	GetDlgItem(IDC_BTN_SENDBACK)->EnableWindow(false);
	GetDlgItem(IDC_BTN_SENDBACK)->ShowWindow(false);
	//make own mode visible
	GetDlgItem(IDC_BTN_RANDGEN)->EnableWindow(true);
	GetDlgItem(IDC_BTN_RANDGEN)->ShowWindow(true);
	GetDlgItem(IDC_SE_TOOLE)->ShowWindow(true);
	//GetDlgItem(IDC_E_TOOLE)->EnableWindow(true);
	GetDlgItem(IDC_E_TOOLE)->ShowWindow(true);
	GetDlgItem(IDC_SE_TOOLD)->ShowWindow(true);
	//GetDlgItem(IDC_E_TOOLD)->EnableWindow(true);
	GetDlgItem(IDC_E_TOOLD)->ShowWindow(true);
}


void CSideSignDlg::OnBnClickedRadioSign()
{
	//MAKE THE STUFF INVISIBLE
	GetDlgItem(IDC_BTN_RANDGEN)->EnableWindow(false);
	GetDlgItem(IDC_BTN_RANDGEN)->ShowWindow(false);
	GetDlgItem(IDC_SE_TOOLE)->ShowWindow(false);
	GetDlgItem(IDC_E_TOOLE)->EnableWindow(false);
	GetDlgItem(IDC_E_TOOLE)->ShowWindow(false);
	GetDlgItem(IDC_SE_TOOLD)->ShowWindow(false);
	GetDlgItem(IDC_E_TOOLD)->EnableWindow(false);
	GetDlgItem(IDC_E_TOOLD)->ShowWindow(false);
	//make own mode visible
	//GetDlgItem(IDC_E_RECVFILE)->EnableWindow(true);
	GetDlgItem(IDC_E_RECVFILE)->ShowWindow(true);
	GetDlgItem(IDC_BTN_RECVMD5)->EnableWindow(true);
	GetDlgItem(IDC_BTN_RECVMD5)->ShowWindow(true);
	//GetDlgItem(IDC_E_SIGN)->EnableWindow(false);
	GetDlgItem(IDC_E_SIGN)->ShowWindow(true);
	GetDlgItem(IDC_BTN_SIGN)->EnableWindow(true);
	GetDlgItem(IDC_BTN_SIGN)->ShowWindow(true);
	GetDlgItem(IDC_BTN_SENDBACK)->EnableWindow(true);
	GetDlgItem(IDC_BTN_SENDBACK)->ShowWindow(true);
}
