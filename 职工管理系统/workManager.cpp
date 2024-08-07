#include"workManager.h"

//构造函数
WorkManager::WorkManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if(!ifs.is_open()){

		std::cout<<"文件不存在"<<endl;
		//初始化属性
		//初始化职工人数
		this->m_EmpNum = 0;
		//初始化职工数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但是数据为空
	char ch;
	ifs >> ch;
	if(ifs.eof()){
		cout << "文件为空" << endl;
		//初始化属性
		//初始化职工人数
		this->m_EmpNum = 0;
		//初始化职工数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在，且记录数据
	int num = this->getEmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->initEmp();
	/*for(int i = 0; i < this->m_EmpNum; i++){
		cout << "职工编号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
	}


void WorkManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "*****  Welcome to Employee Management System  *****" << endl;
	cout << "********  0. Exit the system  ********" << endl;
	cout << "********  1. Add employee information  ********" << endl;
	cout << "********  2. Show employee information  ********" << endl;
	cout << "********  3. Delete employee information  ********" << endl;
	cout << "********  4. Modify employee information  ********" << endl;
	cout << "********  5. Find employee information  ********" << endl;
	cout << "********  6. Sort employee information  ********" << endl;
	cout << "********  7. Clear all employee information  ********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}
void WorkManager::exitSystem()
{
	cout << "Exit the system" << endl;
	system("pause");
	exit(0);
}
void WorkManager::addEmp()
{
	cout << "请输入添加职工数量： " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
				//添加新空间大小=原来大小+新添加大小
		Worker ** newSpace = new Worker*[this->m_EmpNum + addNum];
		//将原来空间下数据存放到新空间下
		if(this->m_EmpArray != NULL){
			for(int i = 0; i < this->m_EmpNum; i++){
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for(int i = 0; i < addNum; i++){
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i+1 << "个新职工编号： " << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "个新职工姓名： " << endl;
			cin >> name;
			cout << "请选择该职工岗位： " << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;
			Worker * worker = NULL;
			switch(dSelect){
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = this->m_EmpNum + addNum;
		//更新职工信息后，保存到文件中
		this->save();
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;

}else{
	cout << "输入数据有误" << endl;
}
	system("pause");
	system("cls");
}
void WorkManager::showEmp()
{
	cout << "Show employee information" << endl;
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or record is empty" << endl;
	}
	else
	{
	for(int i = 0; i < this->m_EmpNum; i++){
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
	
}
int WorkManager::isExist(int id)
{
	int index = -1;
	for(int i = 0; i < this->m_EmpNum; i++){
		if(this->m_EmpArray[i]->m_Id == id){
			index = i;
			break;
		}
	}
	return index;
}
void WorkManager::delEmp()
{
	cout << "Delete employee information" << endl;
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or record is empty" << endl;
	}
	else
	{
		cout << "Please enter the employee number you want to delete: " << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if(index != -1){
			for(int i = index; i < this->m_EmpNum - 1; i++){
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "Delete successfully" << endl;
			}else{
			cout << "The employee does not exist" << endl;
			}

	}
	system("pause");
	system("cls");


}
void WorkManager::modEmp()
{
	cout << "Modify employee information" << endl;
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or record is empty" << endl;
	}
	else
	{
		cout << "Please enter the employee number you want to modify: " << endl;
		int id;
		cin >> id;
		int ret = this->isExist(id);
		if(ret != -1){
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "Find the employee, please enter the new employee number: " << endl;
			cin >> newId;
			cout << "Please enter the new employee name: " << endl;
			cin >> newName;
			cout << "Please select the new employee position: " << endl;
			cout << "1. Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> dSelect;
			Worker * worker = NULL;
			switch(dSelect){
				case 1:
					worker = new Employee(newId, newName, dSelect);
					break;
				case 2:
					worker = new Manager(newId, newName, dSelect);
					break;
				case 3:
					worker = new Boss(newId, newName, dSelect);
					break;
				default:
					break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "Modify successfully" << endl;
			this->save();
		}else{
			cout << "The employee does not exist" << endl;
		}
	}
}
void WorkManager::findEmp()
{
	cout << "Find employee information" << endl;
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or record is empty" << endl;
	}
	else
	{
		cout << "Please select the way to search: " << endl;
		cout << "1. By employee number" << endl;
		cout << "2. By employee name" << endl;
		int select = 0;
		cin >> select;
		if(select == 1){
			int id;
			cout << "Please enter the employee number you want to search: " << endl;
			cin >> id;
			int ret = isExist(id);
			if(ret != -1){
				cout << "Find successfully" << endl;
				this->m_EmpArray[ret]->showInfo();
			}else{
				cout << "The employee does not exist" << endl;
			}
		}else if(select == 2){
			string name;
			cout << "Please enter the employee name you want to search: " << endl;
			cin >> name;
			bool flag = false;
			for(int i = 0; i < this->m_EmpNum; i++){
				if(this->m_EmpArray[i]->m_Name == name){
					cout << "Find successfully" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if(flag == false){
				cout << "The employee does not exist" << endl;
			}
		}else{
			cout << "Input error" << endl;
		}
	}
}
void WorkManager::sortEmp()
{
	cout << "Sort employee information" << endl;
	if (this->m_FileIsEmpty) {
		cout << "File does not exist or record is empty" << endl;
	}
	else
	{
		cout << "Please select the way to sort: " << endl;
		cout << "1. Ascending by employee number" << endl;
		cout << "2. Descending by employee number" << endl;
		int select = 0;
		cin >> select;
		for(int i = 0; i < this->m_EmpNum; i++){
			int minOrMax = i;
			for(int j = i+1; j < this->m_EmpNum; j++){
				if(select == 1){//Ascending
					if(this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id){
						minOrMax = j;
					}
				}else{//Descending
					if(this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
						minOrMax = j;
					}
				}
			}
			if(i != minOrMax){
				Worker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "Sort successfully" << endl;
		this->save();
		this->showEmp();
	
}
}
void WorkManager::cleanFile()
{
	cout << "Clear all employee information" << endl;
	cout << "Are you sure you want to clear all employee information?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	int select = 0;
	cin >> select;
	if(select == 1){
		ofstream ofs(FILENAME, ios::trunc);//打开方式为清空
		ofs.close();
		if(this->m_EmpArray != NULL){
			for(int i = 0; i < this->m_EmpNum; i++){
				if(this->m_EmpArray[i] != NULL){
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "Clear successfully" << endl;
	}
}
//获取文件中的职工人数
int WorkManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while(ifs >> id && ifs >> name && ifs >> dId){
		num++;
	}
	ifs.close();
	return num;
}
//初始化员工
void WorkManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while(ifs >> id && ifs >> name && ifs >> dId){
		Worker * worker = NULL;
		if(dId == 1){
			worker = new Employee(id, name, dId);
		}else if(dId == 2){
			worker = new Manager(id, name, dId);
		}else{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}


//析构函数
WorkManager::~WorkManager()
{
	if(this->m_EmpArray != NULL){
		for(int i = 0; i < this->m_EmpNum; i++){
			if(this->m_EmpArray[i] != NULL){
				delete this->m_EmpArray[i];

			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for(int i = 0; i < this->m_EmpNum; i++){
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

