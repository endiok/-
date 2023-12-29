#pragma once
#include "Worker.h"
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	virtual void ShowInfo();
	virtual string GetdId();

};