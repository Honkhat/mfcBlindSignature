#pragma once


// CSideSignDlg 对话框

class CSideSignDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideSignDlg)

public:
	CSideSignDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSideSignDlg();

// 对话框数据
	enum { IDD = IDD_DLG_SIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeERecvfile();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioConfig();
	afx_msg void OnBnClickedRadioSign();
};
