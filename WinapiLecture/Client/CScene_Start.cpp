#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"

void CScene_Start::Enter()
{
	//Object 추가
	CObject* pObj = new CObject;
	pObj->SetPos(Vec2(640.f,384.f));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::DEFAULT);
	//m_arrObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);
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
