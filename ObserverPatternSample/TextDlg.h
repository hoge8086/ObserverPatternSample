#pragma once
#include "afxwin.h"
#include "Figure.h"

// TextDlg �_�C�A���O

class TextDlg : public CDialogEx, /* �ǉ��� */ public Observer 
{
	DECLARE_DYNAMIC(TextDlg)

public:
	TextDlg(Figure *figure, CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~TextDlg();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//��--------�ǉ�����------------��
	Figure *figure;
	//��--------�ǉ�����------------��

	DECLARE_MESSAGE_MAP()
public:
	//��--------�ǉ�����------------��
	CStatic text;
	CFont font;
	void update();
	//��--------�ǉ�����------------��
	virtual BOOL OnInitDialog();
};
