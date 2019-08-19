
// calcDlg.h : 头文件
//

#pragma once
#include "complex.h"

// CcalcDlg 对话框
class CcalcDlg : public CDialogEx
{
// 构造
public:
	CcalcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
