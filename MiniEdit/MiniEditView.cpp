
// MiniEditView.cpp: реализация класса CMiniEditView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MiniEdit.h"
#endif

#include "MiniEditDoc.h"
#include "MiniEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMiniEditView

IMPLEMENT_DYNCREATE(CMiniEditView, CEditView)

BEGIN_MESSAGE_MAP(CMiniEditView, CEditView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMiniEditView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMiniEditView

CMiniEditView::CMiniEditView() noexcept
{
	// TODO: добавьте код создания

}

CMiniEditView::~CMiniEditView()
{
}

BOOL CMiniEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Разрешить перенос слов

	return bPreCreated;
}


// Печать CMiniEditView


void CMiniEditView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMiniEditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка CEditView по умолчанию
	return CEditView::OnPreparePrinting(pInfo);
}

void CMiniEditView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Начало печати CEditView по умолчанию
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMiniEditView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Завершение печати CEditView по умолчанию
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CMiniEditView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMiniEditView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CMiniEditView

#ifdef _DEBUG
void CMiniEditView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMiniEditView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMiniEditDoc* CMiniEditView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniEditDoc)));
	return (CMiniEditDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMiniEditView
