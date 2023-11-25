#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "DepartmentHead.h"

#include "Object.h"
#include "Division.h"
#include "Department.h"
#include "Faculty.h"
#include "StudentsGroup.h"

using namespace std;

void GetFacultyStudentsGroupsCount(Faculty* faculty) {
	int count = 0;
	
	Department* tmpDep = faculty->GetDepBegin();
	while (tmpDep != NULL) {
		StudentsGroup* tmpStudGroup = tmpDep->GetStudGroupBegin();
		while (tmpStudGroup != NULL) {
			count++;
			tmpStudGroup = tmpStudGroup->GetNext();
		}
		tmpDep = tmpDep->GetNext();
	}

	cout << "��������� " << faculty->GetName() << " ����� " << count << " ����������(��/��/��) �����(�/�)" << endl;
}
void GetDepartmentStudentsGroupsCount(Department* department) {
	int count = 0;
	StudentsGroup* tmp = department->GetStudGroupBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "������� " << department->GetName() << " ����� " << count << " ����������(��/��/��) �����(�/�)" << endl;
}
void GetDepartmentTeachersCount(Department* department) {
	int count = 0;
	Teacher* tmp = department->GetTeacherBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "������� " << department->GetName() << " ����� " << count << " ������������(�/��)" << endl;
}
void GetFacultyDepartmentsCount(Faculty* faculty) {
	int count = 0;
	Department* tmp = faculty->GetDepBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "��������� " << faculty->GetName() << " ����� " << count << " ������(�/�)" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Person::SetCount(5);

	cout << "���������� ������ ����� ���������� count �� 5: " << Person::GetCount() << endl << endl;

	Person::SetCount(0);

	Teacher person1("�������� ���� ����������", 17);
	DepartmentHead person2("������� ������� �������", 15);
	
	cout << "���������� ������: " << Person::GetCount() << endl << endl;

	DepartmentHead person3 ("�������� ������ �����������", 20);
	DepartmentHead person4 ("��������� ������� ��������", 20);
	cout << "���������� ������: " << Person::GetCount() << endl << endl;

	//DepartmentHead person5 = DepartmentHead("���5", 15, "���.���.");

	person2.Show();
	person3.Show();
	person4.Show();
	//person5.Show();

	Person::ShowList();
	DepartmentHead::ShowList();


	Student person5("�������� ��������� ��������", 4);
	Student person6("������ ��������� �����", 4, &person5);

	StudentsGroup stg1("���-20-2�", &person5);
	stg1.Show();

	Student person7("������ ���� ��������", 4);
	Student person8("����������� ��������� �������������", 4, &person7);

	StudentsGroup stg2("���-20-1�", &person7, &stg1);

	Teacher person9("������� ���� ������������", 8);
	Teacher person10("������������� ������ ���������", 11, &person9);

	Department dep1("����", &person2, &stg1, &person9);
	dep1.Show();

	Department dep2("��", &person3, &stg2, NULL, &dep1);
	Department dep3("���", &person4, NULL, NULL, &dep1);

	Faculty fac1("����", &person1, &dep1);
	fac1.Show();

	GetFacultyDepartmentsCount(&fac1);
	GetDepartmentStudentsGroupsCount(&dep1);
	GetDepartmentTeachersCount(&dep1);
	GetFacultyStudentsGroupsCount(&fac1);
}