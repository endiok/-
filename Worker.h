#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	virtual void ShowInfo()=0;
	virtual string GetdId() = 0;

	int Id;
	string Name;
	int dId;
};
