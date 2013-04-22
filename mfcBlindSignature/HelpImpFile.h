#pragma once


// HelpImpFile 对话框

class HelpImpFile : public CDialogEx
{
	DECLARE_DYNAMIC(HelpImpFile)

public:
	HelpImpFile(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HelpImpFile();

// 对话框数据
	enum { IDD = IDD_DLG_FILEFORMAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
