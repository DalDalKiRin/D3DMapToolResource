
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

//�� ��輱�� LOCK�ɱ� ���� Ŭ���� ����
class CSplitterX : public CSplitterWnd
{
public:
	CSplitterX();
	~CSplitterX();

protected:
	afx_msg LRESULT OnNcHitTest(CPoint point);
	DECLARE_MESSAGE_MAP();
};

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
protected:
	//CSplitterWnd m_wndSplitter;
	CSplitterX m_wndSplitter; //�� ��輱 LOCK�ɱ�

public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};




