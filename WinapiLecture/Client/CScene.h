#pragma once
class CObject;//컴파일에 영향을 잘 주지 않기 위해서 이렇게 진행 헤더로 하면은 컴파일러의 계속적인 확인이 필요함

class CScene
{

private:
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END];//벡터마다 해당하는 그룹의 값이 들어가야함
	wstring				m_strName;//씬 이름

public:
	void SetName(const wstring& _stName) { m_strName = m_strName; }
	const wstring& GetName() { return m_strName; }

	virtual void Enter() = 0;//해당 씬에 진입 시 호출

	virtual void Exit() = 0;//해당 씬에 탈출 시 호출
	void update();
	void render(HDC _dc);
protected:
	void AddObject(CObject* _pobj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pobj);
	}

public:
	CScene();
	virtual ~CScene();//상속을 할시에 무조건 해야할것
};

