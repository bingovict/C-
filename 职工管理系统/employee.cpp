#include"Employee.h"
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Employee::showInfo()
{
	cout << "ID: " << this->m_Id
		<< "\tName: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tDuty: Complete tasks assigned by the manager" << endl;
}
string Employee::getDeptName()
{
	return string("Employee");
}
