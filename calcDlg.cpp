
// calcDlg.cpp : ʵ���ļ�
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


// CcalcDlg �Ի���




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


// CcalcDlg ��Ϣ�������

BOOL CcalcDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalcDlg::OnPaint()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
