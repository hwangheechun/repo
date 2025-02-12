#include "stdafx.h"
#include "Platform.h"
#include <string>


Platform::Platform()
	//: _gauge(0.f)
{
	Init();
}

Platform::~Platform()
{
}

void Platform::Init()
{
	_name = L"Platform";
	_position = Vector2(WINSIZEX / 2, WINSIZEY - 20);
	_size = Vector2(WINSIZEX, 15);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_gravity = 1.0f;
}

void Platform::Release()
{
}

void Platform::Update()
{

}

void Platform::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 1.0f);		// 라인
}

PlatformBlock::PlatformBlock()
{
	//Init();
	Init(rand() % 1401 - 700);
}

PlatformBlock::~PlatformBlock()
{

}

void PlatformBlock::Init()
{
	//srand((unsigned int)time(NULL));

	_name = L"Block";
	_position = Vector2(700, 600);
	_size = Vector2(175, 25);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_gravity = 1.0f;
}

void PlatformBlock::Init(int a)
{
	_name = L"PlatformBlock";
	_position = Vector2(rand() % 301 + 156, a * 3);
	//_position = Vector2(rand() % 501 + 312, 600);
	//_position = Vector2(700, 600);
	_size = Vector2(175, 25);
	_rect = RectMakePivot(_position, _size, Pivot::Center);	// 히트박스
	_gravity = 1.0f;

	//_blockImage = IMAGEMANAGER->AddImage(L"Doodle", L"Resources/doodle_left.png");

	//_blockAnimation = new Animation();
	//_blockAnimation->Init(_blockImage->GetWidth(), _blockImage->GetHeight(), _blockImage->GetFrameSize().x, _blockImage->GetFrameSize().y);
	//_blockAnimation->SetPlayFrame(0, 1, false, true);
	//_blockAnimation->SetFPS(10);	// 조정하면서 살펴보기
	//_blockAnimation->Start();		// 이거 안 하면 시작 안 함
}

void PlatformBlock::Release()
{
}

void PlatformBlock::Update()
{
	//_blockAnimation->FrameUpdate(TIMEMANAGER->GetElapsedTime());
}

void PlatformBlock::Render()
{
	_D2DRenderer->FillRectangle(_rect, D2DRenderer::DefaultBrush::White);			// 채우기
	_D2DRenderer->DrawRectangle(_rect, D2DRenderer::DefaultBrush::Black, 2.0f);		// 라인
	//_D2DRenderer->RenderText(200, 200, L"블록 위치 : " + to_wstring(GetPosition().x) + L" " + to_wstring(GetPosition().y), 30);
	//_blockImage->AniRender(_rect.GetCenter() + Vector2(0, -15), _blockAnimation, 2.0f);
}

void PlatformBlock::Move(Vector2 moveDirection, float speed)
{
	_position += moveDirection * speed * TIMEMANAGER->GetElapsedTime();	// == deltaTime
	_rect = RectMakePivot(_position, _size, Pivot::Center);
}