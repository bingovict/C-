#include"manager.h"
using namespace std;
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "ID: " << this->m_Id
		<< "\tName: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tDuty: Manage employees" << endl;
}
string Manager::getDeptName()
{
	return string("Manager");
}
