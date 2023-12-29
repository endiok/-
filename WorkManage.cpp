#include "WorkManage.h"

WorkManage::WorkManage() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open()) {
		cout << "file not exist" << endl;
		this->Array = NULL;
		this->MemberNum = 0;
		this->m_FileIsEmpty = true;
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "Empty file" << endl;
		this->Array = NULL;
		this->MemberNum = 0;
		this->m_FileIsEmpty = true;
		return;
	}

	this->MemberNum = this->GetEmpNum();
	this->Array = new Worker* [this->MemberNum];
	this->Emp_Init();

	ifs.close();
}
WorkManage::~WorkManage() {
	if (Array != NULL) {
		for (int i = 0; i < this->MemberNum; i++) {
			if (Array[i] != NULL) {
				delete Array[i];
				this->Array[i] = NULL;
			}
		}
		delete[] Array;
		Array = NULL;
	}
	this->MemberNum = 0;
}
void WorkManage::Emp_Init() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker;
		if (did == 1) {
			worker = new Employee(id,name,did);
		}
		else if (did == 2) {
			worker = new Manager(id,name,did);
		}
		else {
			worker = new Boss(id,name,did);
		}
		this->Array[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkManage::menu() {
	cout << "*********************************************" << endl;
	cout << "**********   0.Exit the Pragram   ***********" << endl;
	cout << "**********   1. Add EMP's Info    ***********" << endl;
	cout << "**********   2.    Show All       ***********" << endl;
	cout << "**********   3. Del EMP's INfo    ***********" << endl;
	cout << "**********   4. Find EMP's INfo   ***********" << endl;
	cout << "**********   5.    Sort All       ***********" << endl;
	cout << "**********   6. Mod EMP's INfo    ***********" << endl;
	cout << "**********   7. Del All File      ***********" << endl;
	cout << "*********************************************" << endl;
}

void WorkManage::Exit() {
	cout << "Welcome" << endl;
	system("pause");
	exit(0);
}
int WorkManage::GetEmpNum() {
	int count = 0;
	ifstream ifs;
	int id;
	string name;
	int did;
	ifs.open(FILENAME,ios::in);
	while (ifs >> id && ifs >> name && ifs >> did) {
		count++;
	}
	ifs.close();
	return count;
}
void WorkManage::AddEmp() {
	int input;
	cout << "Enter the Nums of the guys You Want to Add:" << endl;
	cin >> input;
	if (input > 0) {
		int newSize = this->MemberNum + input;
		Worker** newSpace = new Worker * [newSize];
		int id=0;
		string name="";
		int did=0;
		for (int i = 0; i < this->MemberNum; i++) {
			newSpace[i] = this->Array[i];
		}
		for (int i = 0; i < input; i++) {
			cout << "Please Enter the " << i + 1 << " People's id" << endl;
			while (1) {
				cin >> id;
				if (FindIdExist(id)!=-1) {
					cout << "Id already exist,Please Enter again" << endl;
				}
				else {
					break;
				}
			}
			cout << "Please Enter the " << i + 1 << " People's name" << endl;
			cin >> name;
			Worker* worker = NULL;
			cout << "Please Enter the " << i + 1 << " People's did" << endl;
			cout << "1.Employee" << "\t2.Manager" << "\t3.Boss" << endl;
			cin >> did;
			switch (did)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "Error input" << endl;
				break;
			}
			newSpace[this->MemberNum + i] = worker;
		}
		delete[] this->Array;
		this->Array = newSpace;
		this->MemberNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "Add Successfully" << endl;
		this->save();
	}
	else {
		cout << "Error input" << endl;
	}
	system("pause");
	system("cls");
}

int WorkManage:: FindIdExist(int id) {
	for (int i = 0; i < this->MemberNum; i++) {
		if (this->Array[i]->Id == id) {
			return i;
		}
	}
	return -1;
}

void WorkManage::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (ofs.is_open()) {
		for (int i = 0; i < this->MemberNum; i++) {
			ofs << this->Array[i]->Id << " "
				<< this->Array[i]->Name << " "
				<< this->Array[i]->dId << " " << endl;
		}
	}
	else {
		cout << "Fail to Save" << endl;
	}
	ofs.close();
}
void WorkManage::ShowEmp() {
	if (this->MemberNum == 0) {
		cout << "FILE NOT EXIST OR EMPTY" << endl;
	}
	else {
		for (int i = 0; i < this->MemberNum; i++) {
			this->Array[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkManage::DelEmp() {
	if (MemberNum == 0) {
		cout << "FILE NOT EXIST OR EMPTY" << endl;
	}
	else {
		int id;
		cout << "Please Enter The guy's Id" << endl;
		cin >> id;
		int ret = FindIdExist(id);
		if (ret == -1) {
			cout << "Not exist" << endl;
		}
		else {
			for (int i = ret; i < this->MemberNum - 1; i++) {
				this->Array[i] = this->Array[i + 1];
			}
			this->MemberNum--;
			this->save();
			cout << "Del Successfully" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManage::FindEmp() {
	if (this->MemberNum==0) {
		cout << "FILE NOT EXIST OR EMPTY" << endl;
	}
	else {
		int id = 0;
		cout << "Please Enter the guy's Id" << endl;
		cin >> id;
		int ret = FindIdExist(id);
		if (ret == -1) {
			cout << "Not exist" << endl;
		}
		else {
			this->Array[ret]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkManage::SortEmp() {
	if (this->MemberNum == 0) {
		cout << "FILE NOT EXIST OR EMPTY" << endl;
	}
	else {
		int select = 0;
		cout << "1.UP SORT  2.DOWN SORT" << endl;
		cin >> select;
		if (select == 1) {
			for (int i = 0; i < this->MemberNum - 1; i++) {
				int min = i;
				for (int j = i + 1; j < this->MemberNum; j++) {
					if (this->Array[i]->Id > this->Array[j]->Id) {
						min = j;
					}
				}
				Worker* tmp = this->Array[i];
				this->Array[i] = this->Array[min];
				this->Array[min] = tmp;
			}
		}
		else if (select == 2) {
			for (int i = 0; i < this->MemberNum - 1; i++) {
				int max = i;
				for (int j = i + 1; j < this->MemberNum; j++) {
					if (this->Array[i]->Id < this->Array[j]->Id) {
						max = j;
					}
				}
				Worker* tmp = this->Array[i];
				this->Array[i] = this->Array[max];
				this->Array[max] = tmp;
			}
		}
		if (select != 1 && select != 2) {
			cout << "Error Select" << endl;
		}
		else {
			this->save();
			cout << "Sort Successfully" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManage::ModEmp() {
	if (this->MemberNum == 0) {
		cout << "FILE NOT EXIST OR EMPTY" << endl;
	}
	else {
		int id;
		cout << "Please Enter the guy's Id" << endl;
		cin >> id;
		int ret = FindIdExist(id);
		if (ret == -1) {
			cout << "Not exist" << endl;
		}
		else
		{
			int newid;
			string newname;
			int newdid;
			cout << "Please Enter the new id" << endl;
			while (1) {
				cin >> newid;
				if (FindIdExist(newid) != -1) {
					cout << "Id already exist,Please Enter again" << endl;
				}
				else {
					break;
				}
			}
			cout << "Please Enter the new name" << endl;
			cin >> newname;
			Worker* worker = NULL;
			cout << "Please Enter the new did" << endl;
			cout << "1.Employee" << "\t2.Manager" << "\t3.Boss" << endl;
			cin >> newdid;
			switch (newdid)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				cout << "Error input" << endl;
				break;
			}
			delete this->Array[ret];
			this->Array[ret] = worker;
			this->save();
			cout << "Modify Successfully" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManage::Clean_File() {
	int select = 0;
	cout << "ARE YOU SURE TO CLEAN ALL?" << endl;
	cout << "      1.Yes     2.No      " << endl;
	cin >> select;
	if (select == 1) {
		ofstream ofs;
		ofs.open(FILENAME,ios::trunc);
		ofs.close();
		if (this->Array != NULL) {
			for (int i = 0; i < this->MemberNum; i++) {
				if (this->Array[i] != NULL) {
					delete this->Array[i];
					this->Array[i] = NULL;
				}
			}
			delete[] this->Array;
			this->Array = NULL;
			this->MemberNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "Clean successfully" << endl;
	}
	system("pause");
	system("cls");
}
