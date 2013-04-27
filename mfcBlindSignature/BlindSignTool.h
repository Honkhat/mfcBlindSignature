#pragma once
#include "afxcmn.h"
#include "SideAskDlg.h"
#include "SideSignDlg.h"
// CBlindSignTool 对话框

class CBlindSignTool : public CDialogEx
{
	DECLARE_DYNAMIC(CBlindSignTool)

public:
	CBlindSignTool(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBlindSignTool();

// 对话框数据
	enum { IDD = IDD_DLG_TOOL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSide;
	CSideAskDlg m_dlgSideAsk;
	CSideSignDlg m_dlgSideSign;
//	virtual void PreInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabside(NMHDR *pNMHDR, LRESULT *pResult);
};
