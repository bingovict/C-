#include"boss.h"
using namespace std;
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "ID: " << this->m_Id
		<< "\tName: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tDuty: Manage employees" << endl;
}
string Boss::getDeptName()
{
	return string("Boss");
}
