#include<iostream>
using namespace std;
#include<list>

//���ݽṹ��
class Data
{
public:
	Data(int cofe, int exponent)  //��ֵ
	{
		m_coef = cofe;
		m_exponenet = exponent;
	}


public:
	int m_coef;   //ϵ��
	int m_exponenet;  //ָ��
};

//�Ƚϴ�С����
bool compare(const Data& d1, const Data& d2)
{
	return d1.m_exponenet < d2.m_exponenet;
}

//���������+
list<Data> operator+(list<Data>& a1, list<Data>& a2)
{
	list<Data> sum;   //����sum���ܺ�
	list<Data>::iterator it1 = a1.begin();   //ָ���һ��list�������׵�ַ
	list<Data>::iterator it2 = a2.begin();   //ָ��ڶ���list�������׵�ַ

	while (it1 != a1.end() || it2 != a2.end())  //����������������������
	{
		//����1�����������1�ڵ��ݴ���2�ڵ���,���Ƶڶ�������ʽ
		if (it1 == a1.end() && it2 != a2.end() || it1->m_exponenet > it2->m_exponenet)
		{
			// Data s(it2->m_coef, it2->m_exponenet);
			sum.push_back(*it2);
			it2++;
		}

		//����2�����������2�ڵ��ݴ���1�ڵ���,���Ƶ�һ������ʽ
		else if (it2 == a2.end() && it1 != a1.end() || it2->m_exponenet > it1->m_exponenet)
		{
			// Data s(it1->m_coef, it1->m_exponenet);
			sum.push_back(*it1);
			it1++;
		}

		//���ڵ㵱ǰ�����
		else
		{
			int sumCoef = it1->m_coef + it2->m_coef;
			if (sumCoef != 0)
			{
				Data s(sumCoef, it1->m_exponenet);
				sum.push_back(s);
			}
			it1++;
			it2++;
		}
	}
	return sum;
}

//���������-
list<Data> operator-(list<Data>& a1, list<Data>& a2)
{
	list<Data>sub;  //����sub����-
	list<Data>::iterator it1 = a1.begin();   //ָ���һ��list�������׵�ַ
	list<Data>::iterator it2 = a2.begin();   //ָ��ڶ���list�������׵�ַ

	while (it1 != a1.end() || it2 != a2.end())   //����������ִ��ѭ��
	{
		if (it1 == a1.end() && it2 != a2.end() || it1->m_exponenet > it2->m_exponenet)
		{
			Data s(-(it2->m_coef), it2->m_exponenet);
			sub.push_back(s);
			it2++;
		}
		else if (it2 == a2.end() && it1 != a1.end() || it2->m_exponenet > it1->m_exponenet)
		{
			sub.push_back(*it1);
			it1++;
		}
		else
		{
			int subCoef = it1->m_coef - it2->m_coef;
			if (subCoef != 0)
			{
				Data s(subCoef, it1->m_exponenet);
				sub.push_back(s);
			}
			it1++;
			it2++;
		}
	}
	return sub;
}

//���������*
list<Data> operator*(list<Data>& a1, list<Data>& a2)
{
	list<Data>mul;  //����mul����*
	list<Data>::iterator it1;   
	list<Data>::iterator it2;  

	for (it1 = a1.begin(); it1 != a1.end(); it1++)
	{
		for (it2 = a2.begin(); it2 != a2.end(); it2++)
		{
			int mulCoef = it1->m_coef*it2->m_coef;
			int mulExponent = it1->m_exponenet + it2->m_exponenet;
			Data s(mulCoef, mulExponent);
			mul.push_back(s);
		}
	}
	return mul;
}



//��ӡ����
void printylist(list<Data>& data)
{
	for (list<Data>::iterator it = data.begin(); it != data.end(); it++)
	{
		if (it == data.begin())
		{
			if (it->m_exponenet == 0)
			{
				cout << it->m_coef;
			}
			else if (it->m_coef == 0)
			{
				return;
			}
			else if (it->m_coef == 1)
			{
				cout << "x^" << it->m_exponenet;
			}
			else
			{
				cout << it->m_coef << "x^" << it->m_exponenet;
			}
		}
		else if (it->m_coef >0)
		{
			if (it->m_coef == 1)
			cout << " + "<< "x^" << it->m_exponenet;
			else
			cout << " + " << it->m_coef << "x^" << it->m_exponenet;
		}
		else if (it->m_coef <0)
		{
			if (it->m_coef == -1)
			{
				cout << " - " << "x^" << it->m_exponenet;
			}
			else
			{
				cout <<" "<< it->m_coef << "x^" << it->m_exponenet;
			}		
		}
	}
	cout << endl;      
}



int main()
{
	list<Data> D1;
	Data d1(1, 1);
	Data d2(2, 2);
	Data d3(1, 6);
	Data d4(1, 3);
	Data d5(1, 5);
	D1.push_back(d1);
	D1.push_back(d2);
	D1.push_back(d3);
	D1.push_back(d4);
	D1.push_back(d5);

	list<Data> D2;
	Data d21(5, 1);
	Data d22(7, 2);
	Data d23(9, 3);
	Data d24(8, 4);
	Data d25(9, 5);
	Data d26(52, 7);
	D2.push_back(d21);
	D2.push_back(d22);
	D2.push_back(d23);
	D2.push_back(d24);
	D2.push_back(d25);
	D2.push_back(d26);
	
	D1.sort(compare);
	cout << "f(x) = ";
	 printylist(D1);

	 D2.sort(compare);
	 cout << "g(x) = ";
	 printylist(D2);

	list <Data>D3 = D1 + D2;
	D3.sort(compare);
	cout << "f(x)+g(x) = ";
	printylist(D3);

	/*list <Data>D4 = D1-D2;
	D4.sort(compare);
	cout << "f(x)-g(x) = ";
	printylist(D4);

	list <Data>D5 = D1 * D2;
	D5.sort(compare);
	cout << "f(x)*g(x) = ";
	printylist(D5);*/

	system("pause");
	return 0;
}