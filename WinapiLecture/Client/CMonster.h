#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{
private:

    Vec2    m_vCenterPos;
    float   m_fSpeed;
    float   m_fMaxDistance;
    int     m_iDir;//방향 양수 :오른쪽 음수:왼쪽

public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }

    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
public:
    virtual void update();
public:
    CMonster();
    ~CMonster();
};

