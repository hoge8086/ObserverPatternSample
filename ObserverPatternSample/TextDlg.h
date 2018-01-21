#pragma once
#include "afxwin.h"
#include "Figure.h"

// TextDlg ダイアログ

class TextDlg : public CDialogEx, /* 追加→ */ public Observer 
{
	DECLARE_DYNAMIC(TextDlg)

public:
	TextDlg(Figure *figure, CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~TextDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//▼--------追加部分------------▼
	Figure *figure;
	//▲--------追加部分------------▲

	DECLARE_MESSAGE_MAP()
public:
	//▼--------追加部分------------▼
	CStatic text;
	CFont font;
	void update();
	//▲--------追加部分------------▲
	virtual BOOL OnInitDialog();
};
