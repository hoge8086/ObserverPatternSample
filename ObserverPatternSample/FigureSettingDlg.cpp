
// FigureSettingDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "FigureSettingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// FigureSettingDlg ダイアログ



FigureSettingDlg::FigureSettingDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OBSERVERPATTERNSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//▼--------追加部分------------▼
	this->figure = figure;
	this->figure->addObserver(this);
	//▲--------追加部分------------▲
}

FigureSettingDlg::~FigureSettingDlg()
{
	//▼--------追加部分------------▼
	this->figure->deleteObserver(this);
	//▲--------追加部分------------▲
}

void FigureSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editX);
	DDX_Control(pDX, IDC_EDIT2, editY);
	DDX_Control(pDX, IDC_EDIT3, editSize);
}

BEGIN_MESSAGE_MAP(FigureSettingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_KILLFOCUS(IDC_EDIT1, &FigureSettingDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &FigureSettingDlg::OnEnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, &FigureSettingDlg::OnEnKillfocusEdit3)
END_MESSAGE_MAP()


// FigureSettingDlg メッセージ ハンドラー

BOOL FigureSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	update();

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void FigureSettingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR FigureSettingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//▼--------追加部分------------▼
void FigureSettingDlg::OnEnKillfocusEdit1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString strX;
	editX.GetWindowTextW(strX);
	figure->setX(_ttoi(strX));
}

void FigureSettingDlg::OnEnKillfocusEdit2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString strY;
	editY.GetWindowTextW(strY);
	figure->setY(_ttoi(strY));
}


void FigureSettingDlg::OnEnKillfocusEdit3()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString strSize;
	editSize.GetWindowTextW(strSize);
	figure->setSize(_ttoi(strSize));
}

void FigureSettingDlg::update()
{
	CString strX, strY, strSize;
	strX.Format(_T("%d"), figure->getX());
	strY.Format(_T("%d"), figure->getY());
	strSize.Format(_T("%d"), figure->getSize());

	editX.SetWindowTextW(strX);
	editY.SetWindowTextW(strY);
	editSize.SetWindowTextW(strSize);
}
//▲--------追加部分------------▲
