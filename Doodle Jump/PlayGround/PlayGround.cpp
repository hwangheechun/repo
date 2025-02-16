#include "stdafx.h"
#include "PlayGround.h"
#include "IEvent.h"
#include "Bullet.h"
#include "TestScene.h"
#include <string>

HRESULT PlayGround::Init()
{
	srand((unsigned int)time(NULL));

	GameNode::Init(true);

	/*Player* player = new Player();

	OBJECTMANAGER->AddObject(ObjectType::Player, player);*/

	SCENEMANAGER->AddScene(L"TestScene", new TestScene());
	/*
	SCENEMANAGER->AddScene(L"TestScene2", new TestScene2());
	SCENEMANAGER->AddScene(L"TestScene3", new TestScene3());
	SCENEMANAGER->AddScene(L"TestScene4", new TestScene4());
	SCENEMANAGER->AddScene(L"TestScene5", new TestScene5());
	*/
	/*BackGround* background = new BackGround();
	SCENEMANAGER->AddScene(L"BackGround", background);*/

	//블록
	for (int i = 0; i < 50; i++)
	{
		PlatformBlock* block = new PlatformBlock(rand() % (WINSIZEY - 100));
		OBJECTMANAGER->AddObject(ObjectType::Block, block);
	}

	//시작 땅
	Platform* platform = new Platform();
	OBJECTMANAGER->AddObject(ObjectType::Platform, platform);

	//캐릭터
	Doodle* doodle = new Doodle();
	OBJECTMANAGER->AddObject(ObjectType::Doodle, doodle);	

	return S_OK;
}

void PlayGround::Release()
{
	OBJECTMANAGER->Release();
}

void PlayGround::Update()
{
	GameNode::Update();

	OBJECTMANAGER->Update();

	EventManager::GetInstance()->Update();
}

void PlayGround::Render()
{	
	// 백버퍼 초기화
	D2DRenderer::GetInstance()->BeginRender(D2D1::ColorF::White);
	{
		OBJECTMANAGER->Render();
	}
	D2DRenderer::GetInstance()->EndRender();
}
