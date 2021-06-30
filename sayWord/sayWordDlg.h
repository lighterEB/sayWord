
// sayWordDlg.h: 头文件
//

#pragma once


// CsayWordDlg 对话框
class CsayWordDlg : public CDialogEx
{
// 构造
public:
	CsayWordDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAYWORD_DIALOG };
#endif

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
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	CEdit m_edit1;
	afx_msg void OnBnClickedButton1();
	CListBox m_list;
	CEdit m_edit2;
	CComboBox m_combo1;
	CEdit m_edit3;
};
