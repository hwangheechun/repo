﻿#pragma once

#define PI 3.14159f
#define PI2 PI * 2

//각도별 회전프레임 셋팅을 편하게 하기 위한 매크로
#define PI8 float(PI / 8.0f)
#define PI16 float(PI / 16.0f)
#define PI32 float(PI / 32.0f)
#define PI64 float(PI / 64.0f)
#define PI128 float(PI / 128.0f)


#define FLOAT_EPSILON 0.001f	// 앱실론 - 실수의 가장 작은 단위
#define FLOAT_EQUAL(f1, f2) (fabs(f1 - f2) <= FLOAT_EPSILON)	// 두 실수가 같은지 비교
#define FLOAT_TO_INT(f1) static_cast<int>(f1 + FLOAT_EPSILON)	// 실수형을 정수형으로

namespace UTIL
{
	float GetDistance(Vector2 start, Vector2 end);
	float GetDistance(float startX, float startY, float endX, float endY);

	float GetAngle(Vector2 start, Vector2 end);
	float GetAngle(float x1, float y1, float x2, float y2);
}