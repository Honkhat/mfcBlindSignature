#pragma once


// CSideAskSendDlg �Ի���

class CSideAskSendDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskSendDlg)

public:
	CSideAskSendDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSideAskSendDlg();

// �Ի�������
	enum { IDD = IDD_DLG_SIDEASK_SEND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
