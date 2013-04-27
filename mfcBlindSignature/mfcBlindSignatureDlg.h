
// mfcBlindSignatureDlg.h : 头文件
//

#pragma once

//添加Crypto++库中用到的头文件
#include <rsa.h>
using CryptoPP::RSA;
#include <integer.h>
using CryptoPP::Integer;
#include <osrng.h>
using CryptoPP::AutoSeededRandomPool;
//hj added
#include "VARCONFIGDLG.h"
#include "HelpImpFile.h"
#include "BlindSignTool.h"

// CmfcBlindSignatureDlg 对话框
class CmfcBlindSignatureDlg : public CDialogEx
{
// 构造
public:
	CmfcBlindSignatureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCBLINDSIGNATURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
//定义用到的一些变量hj
public:
	AutoSeededRandomPool m_prng;
	Integer m_p,m_q,m_n,m_e,m_d;
	Integer m_m,m_fm,m_k,m_mb,m_ss,m_s;
	RSA::PrivateKey m_privKey;
	unsigned int m_RandDigits;
	//RSA::PublicKey m_pubKey;//not necessary.
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadioRand();
	afx_msg void OnBnClickedRadioCustom();
	afx_msg void OnBnClickedBtnGenvar();
	afx_msg void OnBnClickedBtnBlind();
	afx_msg void OnBnClickedBtnCipher();
	afx_msg void OnBnClickedBtn3recvmsg();
	afx_msg void OnBnClickedBtnSignmsg();
	afx_msg void OnBnClickedBtnVerify();
	afx_msg void OnBnClickedBtnUnblind();
	afx_msg void OnBnClickedBtnDecry();
	afx_msg void OnVarconfig();
	afx_msg void OnOutvar();
	afx_msg void OnInvar();
	afx_msg void On32774();
	afx_msg void OnHelpFormat();
	afx_msg void OnSigntool();
};
