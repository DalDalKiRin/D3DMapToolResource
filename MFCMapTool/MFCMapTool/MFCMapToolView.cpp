
// MFCMapToolView.cpp : CMFCMapToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCMapTool.h"
#endif

#include "MFCMapToolDoc.h"
#include "MFCMapToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMapToolView

IMPLEMENT_DYNCREATE(CMFCMapToolView, CView)

BEGIN_MESSAGE_MAP(CMFCMapToolView, CView)
END_MESSAGE_MAP()

// CMFCMapToolView ����/�Ҹ�

CMFCMapToolView::CMFCMapToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCMapToolView::~CMFCMapToolView()
{
}

BOOL CMFCMapToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCMapToolView �׸���

void CMFCMapToolView::OnDraw(CDC* /*pDC*/)
{
	CMFCMapToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFCMapToolView ����

#ifdef _DEBUG
void CMFCMapToolView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMapToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMapToolDoc* CMFCMapToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMapToolDoc)));
	return (CMFCMapToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMapToolView �޽��� ó����