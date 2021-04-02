#pragma once


// CBinCtrlBlend 대화 상자

class CBinCtrlBlend : public CDialog
{
	DECLARE_DYNAMIC(CBinCtrlBlend)

public:
	CBinCtrlBlend(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBinCtrlBlend();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_editBlend;
	CSliderCtrl m_sliderBlend;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();
	CEdit m_editBlend1;
};
