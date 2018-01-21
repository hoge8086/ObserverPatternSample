#pragma once

#include "Observer.h"
#include "Figure.h"
// CircleDlg ダイアログ

class CircleDlg : public CDialogEx, /* 追加→ */ public Observer 
{
	DECLARE_DYNAMIC(CircleDlg)

public:
	CircleDlg(Figure *figure, CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CircleDlg();
	//▼--------追加部分------------▼
	void update();
	//▲--------追加部分------------▲

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	//▼--------追加部分------------▼
	Figure *figure;
	//▲--------追加部分------------▲
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
