#pragma once
#include "Worker.h"

class Employee:public Worker
{
public:
	Employee(int id, string name, int did);
	virtual void ShowInfo();
	virtual string GetdId();

};
