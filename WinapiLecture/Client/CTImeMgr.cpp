#include "pch.h"
#include "CTImeMgr.h"

CTImeMgr::CTImeMgr():m_llCurCount(),m_llPreqquency()
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
	QueryPerformanceFrequency(&m_llPreqquency);//얼마나 자주 반복되는지

}

void CTImeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);
	m_llCurCount.QuadPart - m_llPrevCount.QuadPart;//실제 large integer의 값이다. 이걸 통해서 하면은 한프레임의 차이값을 알수 있다.
	m_llPrevCount = m_llCurCount;

}
