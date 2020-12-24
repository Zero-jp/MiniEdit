
// MiniEdit.h: основной файл заголовка для приложения MiniEdit
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMiniEditApp:
// Сведения о реализации этого класса: MiniEdit.cpp
//

class CMiniEditApp : public CWinAppEx
{
public:
	CMiniEditApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMiniEditApp theApp;
