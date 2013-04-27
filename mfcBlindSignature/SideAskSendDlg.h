#pragma once


// CSideAskSendDlg 对话框

class CSideAskSendDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskSendDlg)

public:
	CSideAskSendDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSideAskSendDlg();

// 对话框数据
	enum { IDD = IDD_DLG_SIDEASK_SEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
