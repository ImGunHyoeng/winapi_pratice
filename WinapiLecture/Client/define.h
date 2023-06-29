#pragma once

//매크로로 생성
//#define Add(a,b) (a+b)
////매크로를 함수처럼
#define SINGLE(type) public :\
						static type* GetInst()\
						{\
							static type mgr;\
							return &mgr;\
						}\
					private:\
						type();\
						~type();
//이렇게 자료형을 넣으면 해당하는 것을 single톤으로서 생성해주겠다는 뜻을 가짐

#define fDT CTImeMgr::GetInst()->GetfDT()
#define	DT CTImeMgr::GetInst()->GetDT()

enum class GROUP_TYPE
{
	DEFAULT,

	PLAYER,

	MISSILE,

	MONSTER,

	END=32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,
	END,
};