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

	cout << "Факультет " << faculty->GetName() << " имеет " << count << " студенческ(ую/ие/их) групп(у/ы)" << endl;
}
void GetDepartmentStudentsGroupsCount(Department* department) {
	int count = 0;
	StudentsGroup* tmp = department->GetStudGroupBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "Кафедра " << department->GetName() << " имеет " << count << " студенческ(ую/ие/их) групп(у/ы)" << endl;
}
void GetDepartmentTeachersCount(Department* department) {
	int count = 0;
	Teacher* tmp = department->GetTeacherBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "Кафедра " << department->GetName() << " имеет " << count << " преподавател(я/ей)" << endl;
}
void GetFacultyDepartmentsCount(Faculty* faculty) {
	int count = 0;
	Department* tmp = faculty->GetDepBegin();
	while (tmp != NULL) {
		count++;
		tmp = tmp->GetNext();
	}

	cout << "Факультет " << faculty->GetName() << " имеет " << count << " кафедр(у/ы)" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Person::SetCount(5);

	cout << "Количество персон после увеличения count до 5: " << Person::GetCount() << endl << endl;

	Person::SetCount(0);

	Teacher person1("Максимов Петр Викторович", 17);
	DepartmentHead person2("Столбов Валерий Юрьевич", 15);
	
	cout << "Количество персон: " << Person::GetCount() << endl << endl;

	DepartmentHead person3 ("Абдулаев Абдула Рамазанович", 20);
	DepartmentHead person4 ("Матвеенко Валерий Павлович", 20);
	cout << "Количество персон: " << Person::GetCount() << endl << endl;

	//DepartmentHead person5 = DepartmentHead("Имя5", 15, "Мех.Мат.");

	person2.Show();
	person3.Show();
	person4.Show();
	//person5.Show();

	Person::ShowList();
	DepartmentHead::ShowList();


	Student person5("Топорков Александр Игоревич", 4);
	Student person6("Ефимов Александр Ильич", 4, &person5);

	StudentsGroup stg1("ЦТУ-20-2б", &person5);
	stg1.Show();

	Student person7("Иванов Иван Иванович", 4);
	Student person8("Александров Александр Александрович", 4, &person7);

	StudentsGroup stg2("ЦТУ-20-1б", &person7, &stg1);

	Teacher person9("Ильиных Глеб Валентинович", 8);
	Teacher person10("Сахабутдинова Ляйсан Рамилевна", 11, &person9);

	Department dep1("ВММБ", &person2, &stg1, &person9);
	dep1.Show();

	Department dep2("ВМ", &person3, &stg2, NULL, &dep1);
	Department dep3("ДПМ", &person4, NULL, NULL, &dep1);

	Faculty fac1("ФПММ", &person1, &dep1);
	fac1.Show();

	GetFacultyDepartmentsCount(&fac1);
	GetDepartmentStudentsGroupsCount(&dep1);
	GetDepartmentTeachersCount(&dep1);
	GetFacultyStudentsGroupsCount(&fac1);
}