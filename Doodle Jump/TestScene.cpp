#include "stdafx.h"
#include "TestScene.h"

TestScene::~TestScene()
{
}

HRESULT TestScene::Init()
{
	// OBJECTMANAGER->AddObject(Ground~~~)

    return S_OK;
}

void TestScene::Release()
{
	// OBJECTMANAGER ���� �ش�
}

void TestScene::Update()
{
	Scene::Update();

	// ������ �޼��� �Ǿ���
	bool bTest = false;
	if (bTest) {
		SCENEMANAGER->ChangeScene(_nextScene);
	}
}

void TestScene::Render()
{
	Scene::Render();
}
