#pragma once


// CSideAskRecv �Ի���

class CSideAskRecv : public CDialogEx
{
	DECLARE_DYNAMIC(CSideAskRecv)

public:
	CSideAskRecv(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSideAskRecv();

// �Ի�������
	enum { IDD = IDD_DLG_SIDEASK_RECV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
