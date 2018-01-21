// TextDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "TextDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// TextDlg �_�C�A���O

IMPLEMENT_DYNAMIC(TextDlg, CDialogEx)

TextDlg::TextDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	//��--------�ǉ�����------------��
	this->figure = figure;
	this->figure->addObserver(this);
	//��--------�ǉ�����------------��

}

TextDlg::~TextDlg()
{
	//��--------�ǉ�����------------��
	this->figure->deleteObserver(this);
	//��--------�ǉ�����------------��
}

void TextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_TEXT, text);
}


BEGIN_MESSAGE_MAP(TextDlg, CDialogEx)
END_MESSAGE_MAP()

// TextDlg ���b�Z�[�W �n���h���[

BOOL TextDlg::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO: �����ɏ�������ǉ����Ă�������

	update();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}

//��--------�ǉ�����------------��
void TextDlg::update()
{
	int x = figure->getX();
	int y = figure->getY();
	int size = figure->getSize();

	if (font.GetSafeHandle())
		font.DeleteObject();

	//�����T�C�Y�X�V
	font.CreateFont(size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, //** �t�H���g�ύX
			SHIFTJIS_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
			DEFAULT_PITCH,_T("�l�r �o�S�V�b�N"));
	text.SetFont(&font);

	//�}�`�T�C�Y�X�V
	CString  str;
	text.GetWindowText( str);
	CClientDC dc(&text);
	CFont *f_old = dc.SelectObject(&font);
	CSize  csize = dc.GetTextExtent(str, str.GetLength());
	dc.SelectObject( f_old);

	text.MoveWindow(x, y, x + csize.cx, y + csize.cy);
	UpdateData(FALSE);
}
//��--------�ǉ�����------------��
