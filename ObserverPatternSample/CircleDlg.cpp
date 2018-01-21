// CircleDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "CircleDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CircleDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CircleDlg, CDialogEx)

CircleDlg::CircleDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	//��--------�ǉ�����------------��
	this->figure = figure;
	this->figure->addObserver(this);
	//��--------�ǉ�����------------��
}

CircleDlg::~CircleDlg()
{
	//��--------�ǉ�����------------��
	this->figure->deleteObserver(this);
	//��--------�ǉ�����------------��
}

void CircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CircleDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CircleDlg ���b�Z�[�W �n���h���[


//��--------�ǉ�����------------��
void CircleDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	int x = figure->getX();
	int y = figure->getY();
	int size = figure->getSize();
	dc.Ellipse(x, y, x + size, y + size);
    CDialog::OnPaint();				   // �`�惁�b�Z�[�W�� CDialogEx::OnPaint() ���Ăяo���Ȃ��ł��������B
}

void  CircleDlg::update()
{
	//�ĕ`��
	InvalidateRect(NULL, TRUE);
}
//��--------�ǉ�����------------��
