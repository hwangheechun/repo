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

class BackGround : public Scene
{
public:
	BackGround();
	virtual ~BackGround() override;

	HRESULT Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	Image* _background;
protected:
	wstring _nextScene;
};

