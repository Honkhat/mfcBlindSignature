#pragma once


// VARCONFIGDLG 对话框

class VARCONFIGDLG : public CDialogEx
{
	DECLARE_DYNAMIC(VARCONFIGDLG)

public:
	VARCONFIGDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~VARCONFIGDLG();

// 对话框数据
	enum { IDD = IDD_DIG_VARCONFIG };
	//hj added
	int m_iRandDigits;
	int m_k;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
