// CBinCtrlBlend.cpp: 구현 파일
//

#include "pch.h"
#include "SN2018111393.h"
#include "CBinCtrlBlend.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "SN2018111393Doc.h"
#include "SN2018111393View.h"


// CBinCtrlBlend 대화 상자

IMPLEMENT_DYNAMIC(CBinCtrlBlend, CDialog)

CBinCtrlBlend::CBinCtrlBlend(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_editBlend(0)
{

}

CBinCtrlBlend::~CBinCtrlBlend()
{
}

void CBinCtrlBlend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editBlend);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderBlend);
	DDX_Control(pDX, IDC_EDIT1, m_editBlend1);
}


BEGIN_MESSAGE_MAP(CBinCtrlBlend, CDialog)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CBinCtrlBlend::OnNMCustomdrawSlider1)
	ON_EN_CHANGE(IDC_EDIT1, &CBinCtrlBlend::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CBinCtrlBlend 메시지 처리기


BOOL CBinCtrlBlend::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_sliderBlend.SetRange(0, 255); //슬라이드바 값의 범위 설정
	m_sliderBlend.SetPos(120); //현재 슬라이드바의 기본값 설정

	m_editBlend = m_sliderBlend.GetPos(); //현재 설정값 획득
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.

}


void CBinCtrlBlend::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChild = (CChildFrame*)pFrame->GetActiveFrame();
	CSN2018111393Doc *pDoc = (CSN2018111393Doc*)pChild->GetActiveDocument();
	CSN2018111393View *pView = (CSN2018111393View*)pChild->GetActiveView();


	//slider의 현재 위치를 가져옴
	m_editBlend = m_sliderBlend.GetPos();
	UpdateData(FALSE);
	//슬라이드에서 설정한 이진화 계수치를 넘겨준다.
	pDoc->ImageBlend(256, 256, m_editBlend);
	pView->Invalidate(FALSE);

	*pResult = 0;

}


void CBinCtrlBlend::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//edit box값 읽기
	CString sPos;
	m_editBlend1.GetWindowText(sPos);
	int iPos = _ttoi(sPos);

	//슬라이더 컨트롤에 설정
	m_sliderBlend.SetPos(iPos);
}
