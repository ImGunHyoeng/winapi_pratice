#pragma once

class CTImeMgr
{
	SINGLE(CTImeMgr);
private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFreqquency;

	double			m_dAcc;//1초 체크를 위한 누적 시간
	double			m_dDT;//프레임 사이의 시간 값
	UINT			m_iCallCount;//함수 호출 회수 체크
	UINT			m_iFPS;		//초당 호출 횟수
	// FPS
	// 1 프레임당 시간 (Delta Time)
public:
	void init();
	void update();//매프레임마다 호출
public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

