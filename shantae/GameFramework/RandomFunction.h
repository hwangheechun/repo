#pragma once
#include "SingletonBase.h"
#include <random>

class RandomFunction : public SingletonBase<RandomFunction>
{
private:
	std::mt19937 generator;

public:
	RandomFunction()
		: generator(static_cast<unsigned int>(std::random_device{}()))
	{}

	~RandomFunction() = default;

	// �Ű������� ���� ������ -1��ŭ ������ ������ ���� ����
	inline int GetInt(int num)
	{
		std::uniform_int_distribution<int> distribution(0, num - 1);
		return distribution(generator);
	}

	// ������ ���� ���� �������� ���� ����
	inline int GetIntFromTo(int fromNum, int toNum)
	{
		std::uniform_int_distribution<int> distribution(fromNum, toNum);
		return distribution(generator);
	}

	// 0�� 1 ������ �ε��Ҽ��� ���� ����
	inline float GetFloat(float num)
	{
		std::uniform_real_distribution<float> distribution(0.0f, num);
		return distribution(generator);
	}

	// Ư�� �������� �ε��Ҽ��� ���� ����
	inline float GetFloatFromTo(float fromNum, float toNum)
	{
		std::uniform_real_distribution<float> distribution(fromNum, toNum);
		return distribution(generator);
	}
};