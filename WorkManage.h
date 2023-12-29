#pragma once
#include <iostream>
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

using namespace std;

#define FILENAME "test.txt"

class WorkManage
{
public:
	WorkManage();

	~WorkManage();

	int GetEmpNum();
	int MemberNum;
	Worker** Array;
	bool m_FileIsEmpty;

	void AddEmp();
	void ShowEmp();
	void DelEmp();
	void FindEmp();
	void SortEmp();
	void ModEmp();
	void Clean_File();

	void menu();

	void Exit();

	void Emp_Init();
	int FindIdExist(int id);
	void save();
};
