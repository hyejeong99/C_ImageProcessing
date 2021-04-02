// CBinCtrlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "SN2018111393.h"
#include "CBinCtrlDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "SN2018111393Doc.h"
#include "SN2018111393View.h"

// CBinCtrlDlg 대화 상자

IMPLEMENT_DYNAMIC(CBinCtrlDlg, CDialog)

CBinCtrlDlg::CBinCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_binValDisp(0)
{

}

CBinCtrlDlg::~CBinCtrlDlg()
{
}

void CBinCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_binValDisp);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CBinCtrlDlg, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CBinCtrlDlg::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CBinCtrlDlg 메시지 처리기


BOOL CBinCtrlDlg::OnInitDialog() //함수 추가
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlSlider.SetRange(0, 255); //슬라이드바 값의 범위 설정
	m_ctrlSlider.SetPos(100); //현재 슬라이드바의 기본값 설정

	m_binValDisp = m_ctrlSlider.GetPos(); //현재 설정값 획득
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBinCtrlDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	
	CMainFrame *pFrame=(CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChild=(CChildFrame*)pFrame->GetActiveFrame();
	CSN2018111393Doc *pDoc=(CSN2018111393Doc*)pChild->GetActiveDocument();
	CSN2018111393View *pView=(CSN2018111393View*)pChild->GetActiveView();
	

	//slider의 현재 위치를 가져옴
	m_binValDisp = m_ctrlSlider.GetPos();
	UpdateData(FALSE);
	//슬라이드에서 설정한 이진화 계수치를 넘겨준다.
	pDoc->BinThresh(256, 256, m_binValDisp);
	pView->Invalidate(FALSE);


	*pResult = 0;
}
