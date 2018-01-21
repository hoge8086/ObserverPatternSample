
// FigureSettingDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "ObserverPatternSample.h"
#include "FigureSettingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// FigureSettingDlg �_�C�A���O



FigureSettingDlg::FigureSettingDlg(Figure *figure, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OBSERVERPATTERNSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//��--------�ǉ�����------------��
	this->figure = figure;
	this->figure->addObserver(this);
	//��--------�ǉ�����------------��
}

FigureSettingDlg::~FigureSettingDlg()
{
	//��--------�ǉ�����------------��
	this->figure->deleteObserver(this);
	//��--------�ǉ�����------------��
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


// FigureSettingDlg ���b�Z�[�W �n���h���[

BOOL FigureSettingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	update();

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void FigureSettingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR FigureSettingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��--------�ǉ�����------------��
void FigureSettingDlg::OnEnKillfocusEdit1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CString strX;
	editX.GetWindowTextW(strX);
	figure->setX(_ttoi(strX));
}

void FigureSettingDlg::OnEnKillfocusEdit2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CString strY;
	editY.GetWindowTextW(strY);
	figure->setY(_ttoi(strY));
}


void FigureSettingDlg::OnEnKillfocusEdit3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
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
//��--------�ǉ�����------------��
