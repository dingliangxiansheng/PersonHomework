#include"DArry.hpp"
#include<string>

void test01()
{
	DArry<int>a(5);
	a.Push_back(3);
	a.Push_back(6);
	a.Push_back(7);
	a.Print();
	cout << "����Ϊ:" << a.getCapacity() << endl;

	DArry<int>b(a);
	b.Print();
	b.Pop_back();
	b.Print();
}

	// �����Զ�����������
class Person
{
public:
    Person(){}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};

//��ӡ�Զ��庯��
void PersonPrint(DArry<Person>&P)
{
	for (int i = 0; i < P.getSize(); i++)
	{
		cout << "������" << P[i].m_Name << "  "
			<< "����" << P[i].m_Age << endl;
	}
}

void test02()
{
	Person p1("����", 8);
	Person p2("����", 9);
	Person p3("����", 10);

	DArry<Person>P(10);
	P.Push_back(p1);
	P.Push_back(p2);
	P.Push_back(p2);

	PersonPrint(P);
	cout << "����Ϊ��" << P.getCapacity() << endl;
	cout << "��СΪ:" << P.getSize() << endl;


}

int main()
{ 
	// test01();

	test02();

	system("pause");
	return 0;
}