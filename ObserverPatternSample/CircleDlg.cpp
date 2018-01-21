// CircleDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "CircleDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CircleDlg ダイアログ

IMPLEMENT_DYNAMIC(CircleDlg, CDialogEx)

CircleDlg::CircleDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	//▼--------追加部分------------▼
	this->figure = figure;
	this->figure->addObserver(this);
	//▲--------追加部分------------▲
}

CircleDlg::~CircleDlg()
{
	//▼--------追加部分------------▼
	this->figure->deleteObserver(this);
	//▲--------追加部分------------▲
}

void CircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CircleDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CircleDlg メッセージ ハンドラー


//▼--------追加部分------------▼
void CircleDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	int x = figure->getX();
	int y = figure->getY();
	int size = figure->getSize();
	dc.Ellipse(x, y, x + size, y + size);
    CDialog::OnPaint();				   // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。
}

void  CircleDlg::update()
{
	//再描画
	InvalidateRect(NULL, TRUE);
}
//▲--------追加部分------------▲
