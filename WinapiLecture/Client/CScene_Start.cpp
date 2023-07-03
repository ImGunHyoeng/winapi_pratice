#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"
#include "CPlayer.h"

void CScene_Start::Enter()
{
	//Object 추가
	CObject* pObj = new CPlayer;
	pObj->SetPos(Vec2(640.f,384.f));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::DEFAULT);
	//m_arrObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);

//	pObj = new CObject;//객체를 만드는것이 불가능해야한다. 부모의 클래스가 객체가 되어서는 안된다. 순수 가상으로 막음
	//Monster Object 추가
	//pObj =new 
}

void CScene_Start::Exit()
{
}

CScene_Start::CScene_Start()
{

}

CScene_Start::~CScene_Start()
{

}
