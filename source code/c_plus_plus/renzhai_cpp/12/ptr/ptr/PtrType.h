#pragma once

//���ü���
class FRefCounter
{
public:
	FRefCounter()
		:SharedCount(0)
		,WeakCount(0)
	{

	}

	int SharedCount;
	int WeakCount;
};