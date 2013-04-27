#pragma once


// CSideAskRecv 对话框

class CSideAskRecv : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskRecv)

public:
	CSideAskRecv(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSideAskRecv();

// 对话框数据
	enum { IDD = IDD_DLG_SIDEASK_RECV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
