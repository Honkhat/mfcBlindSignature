#pragma once


// VARCONFIGDLG �Ի���

class VARCONFIGDLG : public CDialogEx
{
	DECLARE_DYNAMIC(VARCONFIGDLG)

public:
	VARCONFIGDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~VARCONFIGDLG();

// �Ի�������
	enum { IDD = IDD_DIG_VARCONFIG };
	//hj added
	int m_iRandDigits;
	int m_k;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
