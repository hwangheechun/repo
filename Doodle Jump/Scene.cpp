#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

HRESULT Scene::Init()
{
    return S_OK;
}

void Scene::Release()
{
}

void Scene::Update()
{
}

void Scene::Render()
{
	// 타일맵 그려 주기
}

BackGround::BackGround()
{
	Init();
}

BackGround::~BackGround()
{
	
}

HRESULT BackGround::Init()
{
	_background = IMAGEMANAGER->AddImage(L"Block", L"Resources/block_green.png");
	return S_OK;
}

void BackGround::Release()
{
}

void BackGround::Update()
{
}

void BackGround::Render()
{
	//_D2DRenderer->RenderText(10, 500, L"크aaaa기 : ", 30);
	_background->Render(Vector2(0, 0));
	// 타일맵 그려 주기
}