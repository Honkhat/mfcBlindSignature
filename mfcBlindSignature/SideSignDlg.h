#pragma once


// CSideSignDlg �Ի���

class CSideSignDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideSignDlg)

public:
	CSideSignDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSideSignDlg();

// �Ի�������
	enum { IDD = IDD_DLG_SIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeERecvfile();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioConfig();
	afx_msg void OnBnClickedRadioSign();
};
