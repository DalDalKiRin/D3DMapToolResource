#pragma once



// MFCMenuFormView 폼 뷰입니다.

class MFCMenuFormView : public CFormView
{
	DECLARE_DYNCREATE(MFCMenuFormView)

protected:
	MFCMenuFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~MFCMenuFormView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMENUFORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


