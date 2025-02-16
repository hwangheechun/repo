#pragma once
#include "GameObject.h"

class Platform : public GameObject
{
public:
	Platform();
	virtual ~Platform();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	FloatRect _platform;
	float _gravity;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float angle, float speed);

	Vector2 _direction;
	Vector2 GetDirection() { return _direction; };

	FloatRect _gaugeRect;
	Vector2 GetSize() { return _size; };

	Image* _blockImage1;
};

class PlatformBlock : public GameObject
{
public:
	PlatformBlock();
	PlatformBlock(int a);
	virtual ~PlatformBlock();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render() override;

	FloatRect _block;
	float _gravity;

	void Move(Vector2 moveDirection, float speed);
	void MoveAngle(float angle, float speed);

	Vector2 _direction;
	Vector2 GetDirection() { return _direction; };

	FloatRect _gaugeRect;
	Vector2 GetSize() { return _size; };

	void Init(int a);

	Image* _blockImage;
	//Animation* _blockAnimation;
};

