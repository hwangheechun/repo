#pragma once
#include "GameNode.h"

class Scene : public GameNode
{
	// Ÿ�ϸ� & ����ȭ/������ȭ
public:
	Scene();
	virtual ~Scene() override;

	HRESULT Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

protected:
	wstring _nextScene;
};

