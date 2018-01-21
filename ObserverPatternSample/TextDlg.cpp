// TextDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "TextDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// TextDlg ダイアログ

IMPLEMENT_DYNAMIC(TextDlg, CDialogEx)

TextDlg::TextDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	//▼--------追加部分------------▼
	this->figure = figure;
	this->figure->addObserver(this);
	//▲--------追加部分------------▲

}

TextDlg::~TextDlg()
{
	//▼--------追加部分------------▼
	this->figure->deleteObserver(this);
	//▲--------追加部分------------▲
}

void TextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT, text);
}


BEGIN_MESSAGE_MAP(TextDlg, CDialogEx)
END_MESSAGE_MAP()

// TextDlg メッセージ ハンドラー

BOOL TextDlg::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO: ここに初期化を追加してください

	update();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

//▼--------追加部分------------▼
void TextDlg::update()
{
	int x = figure->getX();
	int y = figure->getY();
	int size = figure->getSize();

	if (font.GetSafeHandle())
		font.DeleteObject();

	//文字サイズ更新
	font.CreateFont(size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, //** フォント変更
			SHIFTJIS_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
			DEFAULT_PITCH,_T("ＭＳ Ｐゴシック"));
	text.SetFont(&font);

	//図形サイズ更新
	CString  str;
	text.GetWindowText( str);
	CClientDC dc(&text);
	CFont *f_old = dc.SelectObject(&font);
	CSize  csize = dc.GetTextExtent(str, str.GetLength());
	dc.SelectObject( f_old);

	text.MoveWindow(x, y, x + csize.cx, y + csize.cy);
	UpdateData(FALSE);
}
//▲--------追加部分------------▲
