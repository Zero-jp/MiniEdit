
// MiniEditView.h: интерфейс класса CMiniEditView
//

#pragma once


class CMiniEditView : public CEditView
{
protected: // создать только из сериализации
	CMiniEditView() noexcept;
	DECLARE_DYNCREATE(CMiniEditView)

// Атрибуты
public:
	CMiniEditDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMiniEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MiniEditView.cpp
inline CMiniEditDoc* CMiniEditView::GetDocument() const
   { return reinterpret_cast<CMiniEditDoc*>(m_pDocument); }
#endif

