
// ObserverPatternSample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CObserverPatternSampleApp:
// このクラスの実装については、ObserverPatternSample.cpp を参照してください。
//

class CObserverPatternSampleApp : public CWinApp
{
public:
	CObserverPatternSampleApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CObserverPatternSampleApp theApp;
