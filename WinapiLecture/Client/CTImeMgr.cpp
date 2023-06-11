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
	QueryPerformanceCounter(&m_llCurCount);
	QueryPerformanceFrequency(&m_llPreqquency);//얼마나 자주 반복되는지

}
