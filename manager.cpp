#include "manager.h"

Manager::Manager(int id, string name, int did) {
	this->Id = id;
	this->Name = name;
	this->dId = did;
}
void Manager::ShowInfo() {
	cout << "EMP's Id: " << this->Id << "\tEMP's Name: " << this->Name << "\tEMP's dId: " << this->GetdId() << endl;
}
string Manager::GetdId() {
	return string("Manager");
}
