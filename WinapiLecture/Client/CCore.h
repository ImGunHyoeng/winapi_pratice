#pragma once

//class CCore//프로그램에 포인터로 동적할당 
//{
//private:
//	int m_i;
//	static CCore* g_C_inst;
//	
//	//static int m_s;//클래스 내부에서 접근가능
//public:
//	//코어를 만들어서 반환해주는 함수를 하나 만든다.
//	//정적 멤버
//	static CCore* GetInstace()//멤버함수는 객체가 있어야 함수를 호출할수 있다.
//	{
//		//최초 호출 된 경우
//		//데이터 영역에 포인터 생성 (초기화는 단 한번만 진행)
//		
//		if (nullptr == g_C_inst)
//		{
//			g_C_inst = new CCore;
//		}
//		//2번 이상 호출된 경우 그냥 진행하면된다
//		
//		return g_C_inst;
//	}
//	static void Release()
//	{
//		if(nullptr!=g_C_inst)
//		{
//			delete g_C_inst;
//			g_C_inst = nullptr;
//		}
//	}
//private:
//	CCore();//생성자와 소멸자를 프라이빗으로 선언 이렇게하면 일반적으로 객체를 생성할수 없다.
//	~CCore();
//};

class CCore//데이터 영역에 객체 넣기
{
public :
	SINGLE(CCore);
private:
	HWND m_hWnd;			//메인 윈도우 핸들
	POINT m_ptResolution;	//메인 윈도우 해상도
	HDC		m_hDC;			//메인 윈도우에 Draw 할 DC
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();

};


