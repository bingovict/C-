#pragma once//��ֹͷ�ļ��ظ�����
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
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray;
	WorkManager();
	void showMenu();
	void exitSystem();
	
	void addEmp();
	void save();
	//�ж��ļ��Ƿ�Ϊ��
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

	//��������
	~WorkManager();

	
};
