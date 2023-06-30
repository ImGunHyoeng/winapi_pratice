#pragma once
class CObject
{
private:
	Vec2 m_ptPos;
	Vec2 m_ptScale;
public:
	void SetPos(Vec2 _vPos) { m_ptPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_ptScale = _vScale; }

	Vec2 GetPos() { return m_ptPos; }
	Vec2 GetScale() { return m_ptScale; }
public:
	CObject();
	virtual ~CObject();
};

