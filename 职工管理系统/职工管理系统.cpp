#include<iostream>
using namespace std;
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	////ʵ���������߶���
	//worker* worker = null;
	//worker = new employee(1, "����", 1);
	//worker->showinfo();
	//delete worker;
	////ʵ����manager����
	//worker* worker2 = null;
	//worker2 = new manager(2, "����", 2);
	//worker2->showinfo();
	//delete worker2;
	////ʵ����boss����
	//worker* worker3 = null;
	//worker3 = new boss(3, "����", 3);
	//worker3->showinfo();
	//delete worker3;

	WorkManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "please enter your choice: " << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 0://exit the system
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();//����Ա��
			break;
		case 2:
			wm.showEmp();//��ʾԱ��
			break;
		case 3:
			wm.delEmp();//ɾ��Ա��
			break;
		case 4:
			wm.modEmp();//�޸�Ա��
			break;
		case 5:
			wm.findEmp();//����Ա��
			break;
		case 6:
			wm.sortEmp();//����Ա��
			break;
		case 7:
			wm.cleanFile();//����ļ�
			break;
		default:
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}