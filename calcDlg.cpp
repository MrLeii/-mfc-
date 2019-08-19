
// calcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"
#include "Complex.h"
#include "complex"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcDlg 对话框




CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_imag = 0.0;
	m_imag1 = 0.0;
	m_imag2 = 0.0;
	m_real = 0.0;
	m_real1 = 0.0;
	m_real2 = 0.0;
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IMAG, m_imag);
	DDX_Text(pDX, IDC_IMAG1, m_imag1);
	DDX_Text(pDX, IDC_IMAG2, m_imag2);
	DDX_Text(pDX, IDC_REAL, m_real);
	DDX_Text(pDX, IDC_REAL1, m_real1);
	DDX_Text(pDX, IDC_REAL2, m_real2);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CcalcDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &CcalcDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MULTIPLY, &CcalcDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalcDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_CLEAN, &CcalcDlg::OnBnClickedClean)
END_MESSAGE_MAP()


// CcalcDlg 消息处理程序

BOOL CcalcDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CcalcDlg::OnPaint()
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
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

Complex ComplexCal(Complex ComplexA,Complex ComplexB,int CalSign)
{
	Complex ComplexC;
	switch(CalSign)
	{
	case 1:
		ComplexC = ComplexA+ComplexB;
		break;
	case 2:  ComplexC = ComplexA - ComplexB;
		break;
	case 3: ComplexC = ComplexA * ComplexB;
		break;
	case 4: ComplexC = ComplexA /= ComplexB;
		break;
	default:break;
	}
	return ComplexC;

	
}

void CcalcDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	ComplexA.setComplex(m_real1,m_imag1);
	ComplexB.setComplex(m_real2,m_imag2);
	ComplexC = ComplexCal(ComplexA,ComplexB,1);
	m_real =  ComplexCal(ComplexA,ComplexB,1).real();
	m_imag =  ComplexCal(ComplexA,ComplexB,1).imag();
	/*m_real = m_real1 + m_real2;
	m_image = m_image1 + m_image2;*/
	UpdateData(false);
}


void CcalcDlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	ComplexA.setComplex(m_real1,m_imag1);
	ComplexB.setComplex(m_real2,m_imag2);
	/*m_real = m_real1 - m_real2;
	m_image = m_image1 - m_image2;*/
	m_real =  ComplexCal(ComplexA,ComplexB,2).real();
	m_imag =  ComplexCal(ComplexA,ComplexB,2).imag();
	
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedMultiply()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	ComplexA.setComplex(m_real1,m_imag1);
	ComplexB.setComplex(m_real2,m_imag2);
	/*m_real = m_real1 * m_real2 - m_image1 * m_image2;
	m_image = m_real1 * m_image2 + m_image1 * m_real2;*/
	m_real =  ComplexCal(ComplexA,ComplexB,3).real();
	m_imag =  ComplexCal(ComplexA,ComplexB,3).imag();;

	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	ComplexA.setComplex(m_real1,m_imag1);
	ComplexB.setComplex(m_real2,m_imag2);
	/*m_real = (m_real1 * m_real2 + m_image1 * m_image2) / (m_real1 * m_real1 + m_real2 * m_real2);
	m_image = (m_image1 * m_real2 - m_real1 * m_image2) / (m_real1 * m_real1 + m_real2 * m_real2);*/
	m_real =  ComplexCal(ComplexA,ComplexB,4).real();
	m_imag =  ComplexCal(ComplexA,ComplexB,4).imag();
	
	UpdateData(FALSE);
}


void CcalcDlg::OnBnClickedClean()
{
	// TODO: 在此添加控件通知处理程序代码
}
