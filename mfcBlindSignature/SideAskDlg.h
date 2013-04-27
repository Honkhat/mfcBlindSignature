#pragma once
#include "afxcmn.h"
//hj added
#include "SideAskSendDlg.h"
#include "SideAskRecv.h"

// CSideAskDlg �Ի���

class CSideAskDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskDlg)

public:
	CSideAskDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSideAskDlg();

// �Ի�������
	enum { IDD = IDD_DLG_ASK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabSideAsk;
	CSideAskSendDlg m_dlgSideAskSend;
	CSideAskRecv    m_dlgSideAskRecv;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTabSideask(NMHDR *pNMHDR, LRESULT *pResult);
};
