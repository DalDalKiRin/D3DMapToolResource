// MFCMenuFormView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCMapTool.h"
#include "MFCMenuFormView.h"


// MFCMenuFormView

IMPLEMENT_DYNCREATE(MFCMenuFormView, CFormView)

MFCMenuFormView::MFCMenuFormView()
	: CFormView(IDD_MFCMENUFORMVIEW)
{

}

MFCMenuFormView::~MFCMenuFormView()
{
}

void MFCMenuFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MFCMenuFormView, CFormView)
END_MESSAGE_MAP()


// MFCMenuFormView �����Դϴ�.

#ifdef _DEBUG
void MFCMenuFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MFCMenuFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// MFCMenuFormView �޽��� ó�����Դϴ�.
