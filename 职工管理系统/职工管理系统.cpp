#include<iostream>
using namespace std;
#include"workManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	////实例化管理者对象
	//worker* worker = null;
	//worker = new employee(1, "张三", 1);
	//worker->showinfo();
	//delete worker;
	////实例化manager对象
	//worker* worker2 = null;
	//worker2 = new manager(2, "李四", 2);
	//worker2->showinfo();
	//delete worker2;
	////实例化boss对象
	//worker* worker3 = null;
	//worker3 = new boss(3, "王五", 3);
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
			wm.addEmp();//增加员工
			break;
		case 2:
			wm.showEmp();//显示员工
			break;
		case 3:
			wm.delEmp();//删除员工
			break;
		case 4:
			wm.modEmp();//修改员工
			break;
		case 5:
			wm.findEmp();//查找员工
			break;
		case 6:
			wm.sortEmp();//排序员工
			break;
		case 7:
			wm.cleanFile();//清空文件
			break;
		default:
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}