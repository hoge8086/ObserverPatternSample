
// FigureSettingDlg.h : ヘッダー ファイル
//

#pragma once

#include "Observer.h"
#include "Figure.h"
#include "afxwin.h"

// FigureSettingDlg ダイアログ
class FigureSettingDlg : public CDialogEx, /* 追加→ */ public Observer 
{
// コンストラクション
public:
	FigureSettingDlg(Figure *figure, CWnd* pParent = NULL);	// 標準コンストラクター
	~FigureSettingDlg();


// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBSERVERPATTERNSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

// 実装
protected:
	//▼--------追加部分------------▼
	Figure *figure;
	//▲--------追加部分------------▲
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//▼--------追加部分------------▼
	CEdit editX;
	CEdit editY;
	CEdit editSize;
	void update();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnEnKillfocusEdit3();
	//▲--------追加部分------------▲
};
