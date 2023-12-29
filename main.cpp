#include <iostream>
#include "WorkManage.h"

using namespace std;

int main() {
	WorkManage wm;
	int select = 0;
	do
	{
		wm.menu();
		cout << "Please Enter Your Select:" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			wm.Exit();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.DelEmp();
			break;
		case 4:
			wm.FindEmp();
			break;
		case 5:
			wm.SortEmp();
			break;
		case 6:
			wm.ModEmp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	} while (select);
	system("pause");
	return 0;
}
