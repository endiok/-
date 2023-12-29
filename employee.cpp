#include "employee.h"
#include <iostream>
#include <string>
using namespace std;
Employee::Employee(int id, string name,int did) {
	this->Id = id;
	this->Name = name;
	this->dId = did;
}
void Employee::ShowInfo() {
	cout << "EMP's Id: " << this->Id << "\tEMP's Name: " << this->Name << "\tEMP's dId: " << this->GetdId() << endl;
}
string Employee::GetdId() {
	return string("Employee");
}
