#pragma once



// MFCMenuFormView �� ���Դϴ�.

class MFCMenuFormView : public CFormView
{
	DECLARE_DYNCREATE(MFCMenuFormView)

protected:
	MFCMenuFormView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


