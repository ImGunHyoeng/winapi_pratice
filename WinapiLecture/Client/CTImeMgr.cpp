#include "pch.h"
#include "CTImeMgr.h"
#include "CCore.h"

CTImeMgr::CTImeMgr() :m_llCurCount(), m_llFreqquency(), m_dDT(0.), m_iCallCount(), m_llPrevCount{},m_dAcc(0.),m_iFPS(0)
{

}

CTImeMgr::~CTImeMgr()
{

}

void CTImeMgr::init()
{
	//현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);

	//초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFreqquency);//얼마나 자주 반복되는지

}

void CTImeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	//실제 large integer의 값이다. 이걸 통해서 하면은 한프레임의 시간값의 차이값을 알수 있다.
	m_dDT=(float)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart)/(float)m_llFreqquency.QuadPart;//정밀하게 실수의 값으로 나눈다.

	//=1./m_dDT;//초당 프레임의 횟수 순간적으로 프레임을 그려야 하는횟수가 나온다. 이렇게 하면은 프레임의 횟수가 계속 요동을 치기에 이렇게 가면은 알기가 프레임횟수가 일정하기 않게 된다.
	//이전 카운트 값을 현재값으로 갱신(다음번에 계산을 위해서)
	m_llPrevCount = m_llCurCount;
	m_dAcc += m_dDT;//DT 누적
	++m_iCallCount;//프레임을 그려야하는 횟수가 요동을 칠것이기에 이를 1초 단위로 해서 1초에 몇번 왔다갔다 하는지를 측정해서 실행한다.

	if (m_dAcc>=1.)//1초마다 호출됨
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount= 0;;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer,L"FPS : %d, DT : %f",m_iFPS,m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
