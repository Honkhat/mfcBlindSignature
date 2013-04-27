#pragma once
#include "afxcmn.h"
//hj added
#include "SideAskSendDlg.h"
#include "SideAskRecv.h"

// CSideAskDlg 对话框

class CSideAskDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskDlg)

public:
	CSideAskDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSideAskDlg();

// 对话框数据
	enum { IDD = IDD_DLG_ASK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSideAsk;
	CSideAskSendDlg m_dlgSideAskSend;
	CSideAskRecv    m_dlgSideAskRecv;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabSideask(NMHDR *pNMHDR, LRESULT *pResult);
};
