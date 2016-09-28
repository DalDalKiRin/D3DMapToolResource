
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "MFCMapTool.h"

#include "MainFrm.h"

#include "MFCMapToolDoc.h"
#include "MFCMapToolView.h"
#include "MFCMenuFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CMFCMapToolView ���� ����� g_pView�� �������� ����ϰڴ�.
extern CMFCMapToolView* g_pView;

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

//�� ��輱 LOCK�ɱ�
BEGIN_MESSAGE_MAP(CSplitterX, CSplitterWnd)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()
CSplitterX::CSplitterX() {}
CSplitterX::~CSplitterX() {}

LRESULT CSplitterX::OnNcHitTest(CPoint point)
{
	return HTNOWHERE;
}

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	//return m_wndSplitter.Create(this,
	//	2, 2,               // TODO: �� �� ���� ������ �����մϴ�.
	//	CSize(10, 10),      // TODO: �ּ� â ũ�⸦ �����մϴ�.
	//	pContext);

	//============================================================================
	CRect rect;
	GetClientRect(&rect); //Ŭ���̾�Ʈ ��ü ũ�������� ��Ʈ�� ����

	if (!m_wndSplitter.CreateStatic(this, 1, 2)) //this == ����������
		return FALSE;

	//���� ����
	int nSizeX = rect.right - rect.left;
	int nMenuSize = nSizeX / 4; //���α����� 1/6

	//�� ������
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMFCMapToolView), CSize(nSizeX - nMenuSize, 0),pContext)) //this == ����������
		return FALSE;
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(MFCMenuFormView), CSize(nMenuSize, 0),pContext)) //this == ����������
		return FALSE;
	//CMFCMapToolView* g_pView;

	g_pView = (CMFCMapToolView*)m_wndSplitter.GetPane(0, 0);

}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	//�� Ÿ��Ʋ�� �ٲٱ�
	cs.style &= ~FWS_ADDTOTITLE; //������� - �̸� ������ ��, ��������� ����
	
	SetTitle(_TEXT("���� �ŵ�Ͻ� MapTool �ϱ躴��,�輱��")); //Ÿ��Ʋ�� ����
	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����

