#include "pch.h"
#include "CSceneMgr.h"
#include "CScene_Start.h"



CSceneMgr::CSceneMgr():m_arrScene{}, m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	//씬 전부 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if(nullptr!=m_arrScene[i])
			delete m_arrScene[i];//씬이 할당되어있을때 삭제
	}
}

void CSceneMgr::init()
{
	//씬 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	/*m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CScene_Tool;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = new CScene_Stage01;
	m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = new CScene_Stage02;*/

	//현재 씬 지정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
	
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}
