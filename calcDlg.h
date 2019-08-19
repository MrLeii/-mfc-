
// calcDlg.h : ͷ�ļ�
//

#pragma once
#include "complex.h"

// CcalcDlg �Ի���
class CcalcDlg : public CDialogEx
{
// ����
public:
	CcalcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_imag;
	double m_imag1;
	double m_imag2;
	double m_real;
	double m_real1;
	double m_real2;
	Complex ComplexA,ComplexB,ComplexC;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedClean();
	
};
