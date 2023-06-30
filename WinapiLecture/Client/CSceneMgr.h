#pragma once

class CScene;
class CSceneMgr
{
	SINGLE(CSceneMgr);
private:
	CScene*			m_arrScene[(UINT)SCENE_TYPE::END];//모든 씬 종류
	CScene*			m_pCurScene;//현재씬

public:
	void init();
	void update();
	void render(HDC _dc);
};

