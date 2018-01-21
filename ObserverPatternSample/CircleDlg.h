#pragma once

#include "Observer.h"
#include "Figure.h"
// CircleDlg �_�C�A���O

class CircleDlg : public CDialogEx, /* �ǉ��� */ public Observer 
{
	DECLARE_DYNAMIC(CircleDlg)

public:
	CircleDlg(Figure *figure, CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CircleDlg();
	//��--------�ǉ�����------------��
	void update();
	//��--------�ǉ�����------------��

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	//��--------�ǉ�����------------��
	Figure *figure;
	//��--------�ǉ�����------------��
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
