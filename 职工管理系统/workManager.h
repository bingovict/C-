#pragma once//防止头文件重复包含
#include <iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
#include<fstream>
using namespace std;
#define FILENAME "empFile.txt"
class WorkManager
{
public:
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray;
	WorkManager();
	void showMenu();
	void exitSystem();
	
	void addEmp();
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	int getEmpNum();
	void initEmp();
	void showEmp();
	int isExist(int id);
	void delEmp();
	void modEmp();
	void findEmp();
	void sortEmp();
	void cleanFile();

	//析构函数
	~WorkManager();

	
};
