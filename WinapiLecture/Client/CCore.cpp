#include "pch.h"
#include "CCore.h"
#include "CTImeMgr.h"
#include "CKeyMgr.h"
#include "CObject.h"
//CCore * CCore::g_C_inst = nullptr;

CObject g_cobj;
int CCore:: init(HWND _hWnd,POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	
	
	////결과값이 HRESULT를 줘서 해당하는것이 실패인지 아닌지 알려줌
	//HRESULT hr=S_OK;
	//if (FAILED(hr))//음수가 나오면 참의 결과가 나온다
	//{
	//
	//}
	////E_FAIL;//16진수의 값의 첫값이 최상위가 1이기에 음수
	//return S_OK;//0의 값을 반환
	
	//해상도에 맞게 윈도우 크기 조정
	RECT rt = {0,0,m_ptResolution.x,m_ptResolution.y};
	//WS_OVERLAPPEDWINDOW는 비트의 값으로써 해당
	AdjustWindowRect(&rt,WS_OVERLAPPEDWINDOW,true);//원하는 해상도로 가져올수 있도록 도와주는함수
	rt.right - rt.left;//커진값만큼 더해진다
	rt.bottom - rt.top;
	SetWindowPos(m_hWnd,nullptr,100,100,rt.right - rt.left, rt.bottom - rt.top,0);//c의 기준으로 만들었다는것을 볼수 있다. 객체의 지정을 해야지만 사용이 가능한식 이런것은 윈도우의 창과 그런것도 포함한것 윈도우의 버전에서마다 윈도우의 크기가 다르다

	m_hDC = GetDC(m_hWnd);//내부적으로 DC가 만들어짐 Draw Context

	//이중 버퍼링 용도의 비트맵과 DC 를 만든다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);//비트맵을 만드는데 지금 가르키고 있는것과의 호환성을 고려해서 만든것이다. 비트맵을 만들어서 핸들로 조작한다.
	m_memDC = CreateCompatibleDC(m_hDC);


	HBITMAP hOldBit=(HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	//Manager 초기화
	CTImeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();


	g_cobj.SetPos(Vec2{ (float)(m_ptResolution.x / 2),(float)(m_ptResolution.y / 2) });
	g_cobj.SetScale(Vec2{ 100,100 });

	
	

	return S_OK;
}

void CCore::progress()
{
	CTImeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();

	update();

	render();
	

}

void CCore::update()
{
	//static int callcount = 0;
	//++callcount;

	//static int iPrevCount = GetTickCount();
	//int iCurCount = GetTickCount();
	//if (iCurCount - iPrevCount > 1000)
	//{
	//	iPrevCount = iCurCount;
	//	callcount = 0;
	//}
	////물체의 변경점을 측정하는곳
	Vec2 vPos = g_cobj.GetPos();
	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT)==KEY_STATE::TAP)//한번의 키만 입력된 경우
	{
		//vPos.x -= 100.f*DeltaTime;
		vPos.x -= 100 * fDT;//CTImeMgr::GetInst()->GetfDT();//각 프레임만큼의 해당 작업을 완료한다는 개념이다.
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP)
	{
		vPos.x+= 100 *CTImeMgr::GetInst()->GetfDT();
	}
	g_cobj.SetPos(vPos);
}

void CCore::render()
{
	//화면 Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	
	//그리기
	Vec2 vPos = g_cobj.GetPos();
	Vec2 vScale = g_cobj.GetScale();
	Rectangle(m_memDC, int(vPos.x - vScale.x / 2.f)
					, int(vPos.y-vScale.y/2.f)
					, int(vPos.x + vScale.x / 2.f)
					, int(vPos.y+vScale.y/2.f));

	//bitblt는 항상 고정값이기에 이후에 프레임 드랍이 잘 일어나지 않는다.
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_memDC, 0, 0, SRCCOPY);//하나하나 복사해서 넘김
}

CCore::CCore() : m_hWnd(0), m_ptResolution{},m_hDC(0),m_hBit(0),m_memDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);//호환성으로 만든것은 이렇게 지우라고 레퍼런스 문서에 기재되어있음
	DeleteObject(m_hBit);
}
