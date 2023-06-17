#pragma once

class CTImeMgr
{
	SINGLE(CTImeMgr);
private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llPreqquency;
	// FPS
	// 1 프레임당 시간 (Delta Time)
public:
	void init();
	void update();//매프레임마다 호출
};

