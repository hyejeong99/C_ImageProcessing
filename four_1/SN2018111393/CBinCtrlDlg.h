#pragma once


// CBinCtrlDlg 대화 상자

class CBinCtrlDlg : public CDialog //다이얼로그 클래스
{
	DECLARE_DYNAMIC(CBinCtrlDlg)

public:
	CBinCtrlDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBinCtrlDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_binValDisp; //edit
	CSliderCtrl m_ctrlSlider; //slider
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
