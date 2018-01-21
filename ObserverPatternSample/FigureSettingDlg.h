
// FigureSettingDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once

#include "Observer.h"
#include "Figure.h"
#include "afxwin.h"

// FigureSettingDlg �_�C�A���O
class FigureSettingDlg : public CDialogEx, /* �ǉ��� */ public Observer 
{
// �R���X�g���N�V����
public:
	FigureSettingDlg(Figure *figure, CWnd* pParent = NULL);	// �W���R���X�g���N�^�[
	~FigureSettingDlg();


// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBSERVERPATTERNSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

// ����
protected:
	//��--------�ǉ�����------------��
	Figure *figure;
	//��--------�ǉ�����------------��
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//��--------�ǉ�����------------��
	CEdit editX;
	CEdit editY;
	CEdit editSize;
	void update();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnEnKillfocusEdit3();
	//��--------�ǉ�����------------��
};
