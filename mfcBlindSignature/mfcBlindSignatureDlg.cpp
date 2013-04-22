
// mfcBlindSignatureDlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CmfcBlindSignatureDlg 对话框




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


// CmfcBlindSignatureDlg 消息处理程序

BOOL CmfcBlindSignatureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	m_hIcon=AfxGetApp()->LoadIcon(IDI_SEAL);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//默认选择随机模式
	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	m_k=Integer(128);
	m_RandDigits=128;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfcBlindSignatureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	//首先判断模式，来决定随机生成还是个人设置密钥对
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

		//显示到界面上
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
		//获取公钥e的值
		GetDlgItemText(IDC_E_E,cstr);
		if(cstr!="")
		{
			pInteger=new Integer(cstr.GetBuffer());
			cstr.ReleaseBuffer();
			m_e=*pInteger;
		}
		else
		{
			MessageBox(L"公钥e的取值不可为空!",L"错误",MB_OK);
			return;
		}
		//获取私钥d的值
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
			MessageBox(L"私钥d的取值不可为空!",L"错误",MB_OK);
			return;
		}
		//获取大整数n的值
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
			MessageBox(L"大整数n的取值不可为空!",L"错误",MB_OK);
			return;
		}
		//n,e,d之间做一个简单的合法验证 c=m^e mod n,同时成立m=c^d mod n
		Integer intClear(5);
		if(intClear == a_exp_b_mod_c(a_exp_b_mod_c(intClear,m_e,m_n),m_d,m_n))
		{
			m_privKey.Initialize(m_n,m_e,m_d);//如果不合法，内部会出现错误
			//设置p值
			m_p=m_privKey.GetPrime1();
			sstream.clear();
			sstream<<hex<<m_p;
			sstream>>CharArr;
			cstr.Empty();
			cstr=CharArr;
			SetDlgItemText(IDC_E_P,cstr);
			//设置q值
			m_q=m_privKey.GetPrime2();
			sstream.clear();
			sstream<<hex<<m_q;
			sstream>>CharArr;
			cstr=CharArr;
			SetDlgItemText(IDC_E_Q,cstr);
		}
		else
		{
			MessageBox(L"公钥e、私钥d、大整数n的组合不合法!",L"错误",MB_OK);
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
		MessageBox(L"消息明文为空,不做任何操作!",L"警告",MB_OK);
		return;
	}
	else
	{
		//cstring-->wchar_t
		memcpy(WcharArr,cstr.GetString(),cstr.GetLength()*2);//注意*2;GetString:WCHAR STRING;GetBuffer:wchar_t,too
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
	//显示到界面上

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
	//显示至界面
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
		cstr="身份验证成功!";
	}
	else
	{
		cstr="身份验证失败!";
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
	//显示至界面
	cstr=recovered.c_str();
	SetDlgItemText(IDC_E_DECRY,cstr);
}


void CmfcBlindSignatureDlg::OnVarconfig()
{
	//弹出VARCONFIGDLG
	VARCONFIGDLG dlg;
	if(IDOK==dlg.DoModal())
	{
		m_RandDigits=dlg.m_iRandDigits;
		m_k=Integer(dlg.m_k);
	}
}


void CmfcBlindSignatureDlg::OnOutvar()
{
	//导出参数到文件
	wchar_t szSaveFile[MAX_PATH]={0};//这里需要获取要加密的文件名+“（加密）”
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
		//首先判断是否可导出有效值
		if(m_e.IsZero()||m_d.IsZero()||m_n.IsZero())
		{
			MessageBox(L"密钥对(e,d)或其他参数为0!",L"错误",MB_OK);
			return;
		}
		//将参数写入到文件
		ofstream fout(szSaveFile,ios::out);
		fout.clear();
		fout<<"p: "<<hex<<m_p<<"\n";
		fout<<"q: "<<hex<<m_q<<"\n";
		fout<<"n: "<<hex<<m_n<<"\n";
		fout<<"e: "<<hex<<m_e<<"\n";
		fout<<"d: "<<hex<<m_d<<"\n";
		fout<<"k: "<<hex<<m_k<<"\n";
		fout.close();
		MessageBox(L"导出参数成功!",L"提醒",MB_OK);
	}
}


void CmfcBlindSignatureDlg::OnInvar()
{
	//从文件导入参数
	wchar_t szOpenFile[MAX_PATH]={0};

	OPENFILENAME OpenFile={0};
	OpenFile.lStructSize=sizeof(OpenFile);
	OpenFile.lpstrFile=szOpenFile;
	OpenFile.nMaxFile=MAX_PATH;
	OpenFile.lpstrFilter=L"Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";
	OpenFile.nFilterIndex=1;
	if(::GetOpenFileName(&OpenFile))
	{
		//从文件读入参数
		ifstream fin(szOpenFile,ios::in);
		string str;
		basic_string <char>::size_type idx_p,idx_q,idx_n,idx_e,idx_d,idx_k;
		CString cstr;
		bool bFound=false;

		while(getline(fin,str))
		{
			//首先判断该行是哪个参数
			idx_p=str.find("p:",0);
			idx_q=str.find("q:",0);
			idx_n=str.find("n:",0);
			idx_e=str.find("e:",0);
			idx_d=str.find("d:",0);
			idx_k=str.find("k:",0);

			if(-1 != idx_p)
			{
				idx_p=str.rfind(" ",10);//最多不能超过8个空格
				str=str.substr(idx_p+1,str.length()-idx_p-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_P,cstr);
				m_p=Integer(str.c_str());
				continue;
			}
			
			//获取q值
			if(-1 != idx_q)
			{
				idx_q=str.rfind(" ",10);//最多不能超过8个空格
				str=str.substr(idx_q+1,str.length()-idx_q-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_Q,cstr);
				m_q=Integer(str.c_str());
				continue;
			}
			
			//获取n值
			if(-1 != idx_n)
			{
				idx_n=str.rfind(" ",10);//最多不能超过8个空格
				str=str.substr(idx_n+1,str.length()-idx_n-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_N,cstr);
				m_n=Integer(str.c_str());
				continue;
			}
			
			//获取e值
			if(-1 != idx_e)
			{
				idx_e=str.rfind(" ",10);//最多不能超过8个空格
				str=str.substr(idx_e+1,str.length()-idx_e-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_E,cstr);
				m_e=Integer(str.c_str());
				continue;
			}

			//获取d值
			if(-1 != idx_d)
			{
				idx_d=str.rfind(" ",10);//最多不能超过8个空格
				str=str.substr(idx_d+1,str.length()-idx_d-1);
				cstr=str.c_str();
				SetDlgItemText(IDC_E_D,cstr);
				m_d=Integer(str.c_str());
				continue;
			}
			
			//获取k值
			if(-1 != idx_k)
			{
				idx_k=str.rfind(" ",10);//最多不能超过8个空格
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
			MessageBox(L"恭喜,导入参数有效!",L"提醒",MB_OK);
		}
		else
		{
			MessageBox(L"糟糕,导入参数无效!",L"提醒",MB_OK);
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
