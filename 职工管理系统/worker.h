#pragma once
#include <iostream>
using namespace std;
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;//纯虚函数
	//获取岗位名称
	virtual string getDeptName() = 0;
	//保存个人信息
	int m_Id;
	string m_Name;
	int m_DeptId;

	
};
