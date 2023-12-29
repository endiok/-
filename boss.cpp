#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->Id = id;
	this->Name = name;
	this->dId = did;
}
void Boss::ShowInfo() {
	cout << "EMP's Id: " << this->Id << "\tEMP's Name: " << this->Name << "\tEMP's dId: " << this->GetdId() << endl;
}
string Boss::GetdId() {
	return string("Boss");
}
