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

public:
	CScene();
	~CScene();
};

