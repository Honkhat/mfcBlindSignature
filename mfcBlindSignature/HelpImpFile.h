#pragma once


// HelpImpFile �Ի���

class HelpImpFile : public CDialogEx
{
	DECLARE_DYNAMIC(HelpImpFile)

public:
	HelpImpFile(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HelpImpFile();

// �Ի�������
	enum { IDD = IDD_DLG_FILEFORMAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
