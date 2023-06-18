#include "pch.h"
#include "CKeyMgr.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'Z',
	'X',
	'C',
	'V',
	'B',

	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE
};

CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{

}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; i++)//라스트의 크기만큼 돌아야한다
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE,false });
	}
	//m_vecKey[(int)KEY::LEFT].eState;
	//m_vecKey[(int)KEY::LEFT].bPrev;//이렇게 상태를 확인할수 있다.
}

void CKeyMgr::update()
{
	for (int i = 0; i < (int)KEY::LAST; i++)//라스트의 크기만큼 돌아야한다
	{
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)//0번을 왼쪽으로 했는데 키 타입이랑 접점이 없다. 키의 입력을 받는것
		{
			if (m_vecKey[i].bPrevPush)
			{
				m_vecKey[i].eState = KEY_STATE::HOLD;
			}
			else
			{
				m_vecKey[i].eState = KEY_STATE::TAP;
			}
			m_vecKey[i].bPrevPush = true;
		}
		//키가 안눌림
		else
		{
			if (m_vecKey[i].bPrevPush)//이전에 눌림
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;//막 떼짐
			}
			else
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
			m_vecKey[i].bPrevPush = false;
		}
	}
}
 
