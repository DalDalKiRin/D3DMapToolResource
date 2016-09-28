
// MainFrm.cpp : CMainFrame 클래스의 구현
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

//CMFCMapToolView 에서 선언된 g_pView를 전역으로 사용하겠다.
extern CMFCMapToolView* g_pView;

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

//툴 경계선 LOCK걸기
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
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
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
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	//return m_wndSplitter.Create(this,
	//	2, 2,               // TODO: 행 및 열의 개수를 조정합니다.
	//	CSize(10, 10),      // TODO: 최소 창 크기를 조정합니다.
	//	pContext);

	//============================================================================
	CRect rect;
	GetClientRect(&rect); //클라이언트 전체 크기정보를 렉트에 담음

	if (!m_wndSplitter.CreateStatic(this, 1, 2)) //this == 메인프레임
		return FALSE;

	//가로 길이
	int nSizeX = rect.right - rect.left;
	int nMenuSize = nSizeX / 4; //가로길이의 1/6

	//뷰 나누기
	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMFCMapToolView), CSize(nSizeX - nMenuSize, 0),pContext)) //this == 메인프레임
		return FALSE;
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(MFCMenuFormView), CSize(nMenuSize, 0),pContext)) //this == 메인프레임
		return FALSE;
	//CMFCMapToolView* g_pView;

	g_pView = (CMFCMapToolView*)m_wndSplitter.GetPane(0, 0);

}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	//툴 타이틀명 바꾸기
	cs.style &= ~FWS_ADDTOTITLE; //제목없음 - 이름 의형식 중, 제목없음이 빠짐
	
	SetTitle(_TEXT("엘린 매드니스 MapTool ⓒ김병진,김선주")); //타이틀명 정의
	return TRUE;
}

// CMainFrame 진단

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


// CMainFrame 메시지 처리기

