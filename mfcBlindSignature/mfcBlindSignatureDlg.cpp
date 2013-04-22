
// mfcBlindSignatureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcBlindSignature.h"
#include "mfcBlindSignatureDlg.h"
#include "afxdialogex.h"
#include "VARCONFIGDLG.h"
#include "HelpImpFile.h"
//hj added later 
#include <sstream>
#include <iomanip>
using namespace std;
#include <ShlObj.h>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//global variables
stringstream sstream;
CString cstr;
char CharArr[512]={0};

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void On32774();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_32774, &CAboutDlg::On32774)
END_MESSAGE_MAP()


// CmfcBlindSignatureDlg �Ի���




CmfcBlindSignatureDlg::CmfcBlindSignatureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcBlindSignatureDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcBlindSignatureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcBlindSignatureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CmfcBlindSignatureDlg::OnBnClickedRadioRand)
	ON_BN_CLICKED(IDC_RADIO2, &CmfcBlindSignatureDlg::OnBnClickedRadioCustom)
	ON_BN_CLICKED(IDC_BTN_GENVAR, &CmfcBlindSignatureDlg::OnBnClickedBtnGenvar)
	ON_BN_CLICKED(IDC_BTN_BLIND, &CmfcBlindSignatureDlg::OnBnClickedBtnBlind)
	ON_BN_CLICKED(IDC_BTN_CIPHER, &CmfcBlindSignatureDlg::OnBnClickedBtnCipher)
	ON_BN_CLICKED(IDC_BTN_3RECVMSG, &CmfcBlindSignatureDlg::OnBnClickedBtn3recvmsg)
	ON_BN_CLICKED(IDC_BTN_SIGNMSG, &CmfcBlindSignatureDlg::OnBnClickedBtnSignmsg)
	ON_BN_CLICKED(IDC_BTN_VERIFY, &CmfcBlindSignatureDlg::OnBnClickedBtnVerify)
	ON_BN_CLICKED(IDC_BTN_UNBLIND, &CmfcBlindSignatureDlg::OnBnClickedBtnUnblind)
	ON_BN_CLICKED(IDC_BTN_DECRY, &CmfcBlindSignatureDlg::OnBnClickedBtnDecry)
	ON_COMMAND(ID_VARCONFIG, &CmfcBlindSignatureDlg::OnVarconfig)
	ON_COMMAND(ID_OUTVAR, &CmfcBlindSignatureDlg::OnOutvar)
	ON_COMMAND(ID_INVAR, &CmfcBlindSignatureDlg::OnInvar)
	ON_COMMAND(ID_32774, &CmfcBlindSignatureDlg::On32774)
	ON_COMMAND(ID_HELP_FORMAT, &CmfcBlindSignatureDlg::OnHelpFormat)
END_MESSAGE_MAP()


// CmfcBlindSignatureDlg ��Ϣ�������

BOOL CmfcBlindSignatureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	m_hIcon=AfxGetApp()->LoadIcon(IDI_SEAL);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//Ĭ��ѡ�����ģʽ
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_k=Integer(128);
	m_RandDigits=128;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CmfcBlindSignatureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmfcBlindSignatureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CmfcBlindSignatureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcBlindSignatureDlg::OnBnClickedRadioRand()
{
	SetDlgItemText(IDC_E_D,L"");
	SetDlgItemText(IDC_E_E,L"");
	SetDlgItemText(IDC_E_P,L"");
	SetDlgItemText(IDC_E_Q,L"");
	SetDlgItemText(IDC_E_N,L"");
}


void CmfcBlindSignatureDlg::OnBnClickedRadioCustom()
{
	SetDlgItemText(IDC_E_D,L"");
	SetDlgItemText(IDC_E_E,L"");
	SetDlgItemText(IDC_E_P,L"");
	SetDlgItemText(IDC_E_Q,L"");
	SetDlgItemText(IDC_E_N,L"");
}


void CmfcBlindSignatureDlg::OnBnClickedBtnGenvar()
{
	//�����ж�ģʽ��������������ɻ��Ǹ���������Կ��
	int iRadio=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);

	//random mode
	if(iRadio==IDC_RADIO1)
	{
		m_privKey.GenerateRandomWithKeySize(m_prng,(unsigned int)m_RandDigits);
		m_n=m_privKey.GetModulus();
		m_e=m_privKey.GetPublicExponent();
		m_d=m_privKey.GetPrivateExponent();
		m_p=m_privKey.GetPrime1();
		m_q=m_privKey.GetPrime2();

		//��ʾ��������
		sstream.clear();
		sstream<<hex<<m_e;
		sstream>>CharArr;
		cstr=CharArr;
		SetDlgItemText(IDC_E_E,cstr);

		sstream.clear();
		sstream<<hex<<m_d;
		sstream>>CharArr;
		cstr.Empty();
		cstr=CharArr;
		SetDlgItemText(IDC_E_D,cstr);

		sstream.clear();
		sstream<<hex<<m_p;
		sstream>>CharArr;
		cstr.Empty();
		cstr=CharArr;
		SetDlgItemText(IDC_E_P,cstr);

		sstream.clear();
		sstream<<hex<<m_q;
		sstream>>CharArr;
		cstr.Empty();
		cstr=CharArr;
		SetDlgItemText(IDC_E_Q,cstr);

		sstream.clear();
		sstream<<hex<<m_n;
		sstream>>CharArr;
		cstr.Empty();
		cstr=CharArr;
		SetDlgItemText(IDC_E_N,cstr);
	}
	//custom mode
	else if(iRadio==IDC_RADIO2)
	{
		Integer* pInteger;
		//��ȡ��Կe��ֵ
		GetDlgItemText(IDC_E_E,cstr);
		if(cstr!="")
		{
			pInteger=new Integer(cstr.GetBuffer());
			cstr.ReleaseBuffer();
			m_e=*pInteger;
		}
		else
		{
			MessageBox(L"��Կe��ȡֵ����Ϊ��!",L"����",MB_OK);
			return;
		}
		//��ȡ˽Կd��ֵ
		cstr.Empty();
		GetDlgItemText(IDC_E_D,cstr);
		if(cstr!="")
		{
			pInteger=new Integer(cstr.GetBuffer());
			cstr.ReleaseBuffer();
			m_d=*pInteger;
		}
		else
		{
			MessageBox(L"˽Կd��ȡֵ����Ϊ��!",L"����",MB_OK);
			return;
		}
		//��ȡ������n��ֵ
		cstr.Empty();
		GetDlgItemText(IDC_E_N,cstr);
		if(cstr!="")
		{
			pInteger=new Integer(cstr.GetBuffer());
			cstr.ReleaseBuffer();
			m_n=*pInteger;
		}
		else
		{
			MessageBox(L"������n��ȡֵ����Ϊ��!",L"����",MB_OK);
			return;
		}
		//n,e,d֮����һ���򵥵ĺϷ���֤ c=m^e mod n,ͬʱ����m=c^d mod n
		Integer intClear(5);
		if(intClear == a_exp_b_mod_c(a_exp_b_mod_c(intClear,m_e,m_n),m_d,m_n))
		{
			m_privKey.Initialize(m_n,m_e,m_d);//������Ϸ����ڲ�����ִ���
			//����pֵ
			m_p=m_privKey.GetPrime1();
			sstream.clear();
			sstream<<hex<<m_p;
			sstream>>CharArr;
			cstr.Empty();
			cstr=CharArr;
			SetDlgItemText(IDC_E_P,cstr);
			//����qֵ
			m_q=m_privKey.GetPrime2();
			sstream.clear();
			sstream<<hex<<m_q;
			sstream>>CharArr;
			cstr=CharArr;
			SetDlgItemText(IDC_E_Q,cstr);
		}
		else
		{
			MessageBox(L"��Կe��˽Կd��������n����ϲ��Ϸ�!",L"����",MB_OK);
			return;
		}
	}
}


void CmfcBlindSignatureDlg::OnBnClickedBtnBlind()
{
	wchar_t WcharArr[256]={0};

	cstr.Empty();
	GetDlgItemText(IDC_E_MSG,cstr);
	if(cstr.IsEmpty())
	{
		MessageBox(L"��Ϣ����Ϊ��,�����κβ���!",L"����",MB_OK);
		return;
	}
	else
	{
		//cstring-->wchar_t
		memcpy(WcharArr,cstr.GetString(),cstr.GetLength()*2);//ע��*2;GetString:WCHAR STRING;GetBuffer:wchar_t,too
		//wchar_t-->char
		WideCharToMultiByte(CP_ACP,0,WcharArr,-1,CharArr,sizeof(CharArr),NULL,NULL);
		m_m=Integer((byte*)CharArr,strlen(CharArr));

		sstream.clear();
		sstream<<hex<<m_m;
		sstream>>CharArr;
		cstr=CharArr;
		SetDlgItemText(IDC_E_BLIND,cstr);
	}
}


void CmfcBlindSignatureDlg::OnBnClickedBtnCipher()
{
	m_fm=m_m;
	m_mb=a_exp_b_mod_c(m_k,m_e,m_n);
	m_mb=m_mb*m_fm;
	m_mb=m_mb%m_n;
	//��ʾ��������

	sstream.clear();
	sstream<<hex<<m_mb;
	sstream>>CharArr;
	cstr=CharArr;
	SetDlgItemText(IDC_E_CIPHER,cstr);
}


void CmfcBlindSignatureDlg::OnBnClickedBtn3recvmsg()
{
	sstream.clear();
	sstream<<hex<<m_mb;
	sstream>>CharArr;
	cstr=CharArr;
	SetDlgItemText(IDC_E_3RECVMSG,cstr);
}


void CmfcBlindSignatureDlg::OnBnClickedBtnSignmsg()
{
	m_ss=a_exp_b_mod_c(m_mb,m_d,m_n);
	//��ʾ������
	sstream.clear();
	sstream<<hex<<m_ss;
	sstream>>CharArr;
	cstr=CharArr;
	SetDlgItemText(IDC_E_SIGNMSG,cstr);
}


void CmfcBlindSignatureDlg::OnBnClickedBtnVerify()
{
	if(m_fm%m_n == a_exp_b_mod_c(m_s,m_e,m_n))
	{
		cstr="�����֤�ɹ�!";
	}
	else
	{
		cstr="�����֤ʧ��!";
	}
	SetDlgItemText(IDC_E_VERIFY,cstr);
}


void CmfcBlindSignatureDlg::OnBnClickedBtnUnblind()
{
	m_s=a_exp_b_mod_c(m_fm,m_d,m_n);
	//UpdateData(false)
	sstream.clear();
	sstream<<hex<<m_s;
	sstream>>CharArr;
	cstr=CharArr;
	SetDlgItemText(IDC_E_UNBLIND,cstr);
}


void CmfcBlindSignatureDlg::OnBnClickedBtnDecry()
{
	string recovered;
	size_t req=m_fm.MinEncodedSize();
	recovered.resize(req);
	m_fm.Encode((byte*)recovered.data(),recovered.size());
	//��ʾ������
	cstr=recovered.c_str();
	SetDlgItemText(IDC_E_DECRY,cstr);
}


void CmfcBlindSignatureDlg::OnVarconfig()
{
	//����VARCONFIGDLG
	VARCONFIGDLG dlg;
	if(IDOK==dlg.DoModal())
	{
		m_RandDigits=dlg.m_iRandDigits;
		m_k=Integer(dlg.m_k);
	}
}


void CmfcBlindSignatureDlg::OnOutvar()
{
	//�����������ļ�
	wchar_t szSaveFile[MAX_PATH]={0};//������Ҫ��ȡҪ���ܵ��ļ���+�������ܣ���
	OPENFILENAME SaveFile={0};
	SaveFile.lStructSize=sizeof(OPENFILENAME);
	SaveFile.lpstrFile=szSaveFile;
	SaveFile.nMaxFile=MAX_PATH;
	SaveFile.lpstrFilter=L"Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	SaveFile.lpstrDefExt=L".txt";
	SaveFile.nFilterIndex=1;
	SaveFile.Flags=OFN_OVERWRITEPROMPT|OFN_CREATEPROMPT;
	if(::GetSaveFileName(&SaveFile))
	{
		//�����ж��Ƿ�ɵ�����Чֵ
		if(m_e.IsZero()||m_d.IsZero()||m_n.IsZero())
		{
			MessageBox(L"��Կ��(e,d)����������Ϊ0!",L"����",MB_OK);
			return;
		}
		//������д�뵽�ļ�
		ofstream fout(szSaveFile,ios::out);
		fout.clear();
		fout<<"p: "<<hex<<m_p<<"\n";
		fout<<"q: "<<hex<<m_q<<"\n";
		fout<<"n: "<<hex<<m_n<<"\n";
		fout<<"e: "<<hex<<m_e<<"\n";
		fout<<"d: "<<hex<<m_d<<"\n";
		fout<<"k: "<<hex<<m_k<<"\n";
		fout.close();
		MessageBox(L"���������ɹ�!",L"����",MB_OK);
	}
}


void CmfcBlindSignatureDlg::OnInvar()
{
	//���ļ��������
	wchar_t szOpenFile[MAX_PATH]={0};

	OPENFILENAME OpenFile={0};
	OpenFile.lStructSize=sizeof(OpenFile);
	OpenFile.lpstrFile=szOpenFile;
	OpenFile.nMaxFile=MAX_PATH;
	OpenFile.lpstrFilter=L"Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	OpenFile.nFilterIndex=1;
	if(::GetOpenFileName(&OpenFile))
	{
		//���ļ��������
		ifstream fin(szOpenFile,ios::in);
		string str;
		basic_string <char>::size_type idx_p,idx_q,idx_n,idx_e,idx_d,idx_k;
		CString cstr;
		bool bFound=false;

		while(getline(fin,str))
		{
			//�����жϸ������ĸ�����
			idx_p=str.find("p:",0);
			idx_q=str.find("q:",0);
			idx_n=str.find("n:",0);
			idx_e=str.find("e:",0);
			idx_d=str.find("d:",0);
			idx_k=str.find("k:",0);

			if(-1 != idx_p)
			{
				idx_p=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_p+1,str.length()-idx_p-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_P,cstr);
				m_p=Integer(str.c_str());
				continue;
			}
			
			//��ȡqֵ
			if(-1 != idx_q)
			{
				idx_q=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_q+1,str.length()-idx_q-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_Q,cstr);
				m_q=Integer(str.c_str());
				continue;
			}
			
			//��ȡnֵ
			if(-1 != idx_n)
			{
				idx_n=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_n+1,str.length()-idx_n-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_N,cstr);
				m_n=Integer(str.c_str());
				continue;
			}
			
			//��ȡeֵ
			if(-1 != idx_e)
			{
				idx_e=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_e+1,str.length()-idx_e-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_E,cstr);
				m_e=Integer(str.c_str());
				continue;
			}

			//��ȡdֵ
			if(-1 != idx_d)
			{
				idx_d=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_d+1,str.length()-idx_d-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_D,cstr);
				m_d=Integer(str.c_str());
				continue;
			}
			
			//��ȡkֵ
			if(-1 != idx_k)
			{
				idx_k=str.rfind(" ",10);//��಻�ܳ���8���ո�
				str=str.substr(idx_k+1,str.length()-idx_k-1);
				cstr=str.c_str();
				m_k=Integer(str.c_str());
				continue;
			}
			
		}
		fin.close();
		//check if validate
		Integer intClear(5);
		if(intClear == a_exp_b_mod_c(a_exp_b_mod_c(intClear,m_e,m_n),m_d,m_n))
		{
			MessageBox(L"��ϲ,���������Ч!",L"����",MB_OK);
		}
		else
		{
			MessageBox(L"���,���������Ч!",L"����",MB_OK);
			SetDlgItemText(IDC_E_P,L"");
			SetDlgItemText(IDC_E_Q,L"");
			SetDlgItemText(IDC_E_N,L"");
			SetDlgItemText(IDC_E_E,L"");
			SetDlgItemText(IDC_E_D,L"");
		}
	}
}





void CmfcBlindSignatureDlg::On32774()
{
	//File-->Exit
	OnOK();
}


void CmfcBlindSignatureDlg::OnHelpFormat()
{
	//popup the HelpImpFile Dialog
	HelpImpFile dlg;
	dlg.DoModal();
}
