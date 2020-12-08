#include<iostream>
using namespace std;
#include<map>

//map自身有两个数据，所以把map的key定义为指数    把value定义为系数

//重载运算符+
map<int, int> operator+(map<int, int>& mp1, map<int, int>& mp2)
{
	map<int, int>sum;   //接受两者的和
	map<int, int>::iterator it1 = mp1.begin();
	map<int, int>::iterator it2 = mp2.begin();
	while (it1 != mp1.end() || it2 != mp2.end())
	{
		if (it1 == mp1.end() && it2 != mp2.end() || it1->first > it2->first)
		{
			sum.insert(pair<int, int>(it2->first, it2->second));
			it2++;
		}
		else if (it2 == mp2.end() && it1 != mp1.end() || it1->first < it2->first)
		{
			sum.insert(pair<int, int>(it1->first, it1->second));
			it1++;
		}

		else
		{
			int sumCoef = it1->second + it2->second;
			if (sumCoef != 0)
			{
				sum.insert(pair<int, int>(it1->first, sumCoef));
			}
			it1++;
			it2++;
		}

	}
	return sum;
}


//重载运算符-
map<int, int> operator-(map<int, int>& mp1, map<int, int>& mp2)
{
	map<int, int>sub;   //接受两者的差
	map<int, int>::iterator it1 = mp1.begin();
	map<int, int>::iterator it2 = mp2.begin();
	while (it1 != mp1.end() || it2 != mp2.end())
	{
		if (it1 == mp1.end() && it2 != mp2.end() || it1->first > it2->first)
		{
			sub.insert(pair<int, int>(it2->first, -(it2->second)));
			it2++;
		}
		else if (it2 == mp2.end() && it1 != mp1.end() || it1->first < it2->first)
		{
			sub.insert(pair<int, int>(it1->first, it1->second));
			it1++;
		}

		else
		{
			int sumCoef = it1->second - it2->second;
			if (sumCoef != 0)
			{
				sub.insert(pair<int, int>(it1->first, sumCoef));
			}
			it1++;
			it2++;
		}

	}
	return sub;
}


//重载运算符*
map<int, int> operator*(map<int, int>& mp1, map<int, int>& mp2)
{
	map<int, int>mul;   //接受两者的乘积

	for (map<int, int>::iterator it1 = mp1.begin(); it1 != mp1.end(); it1++)
	{
		for (map<int, int>::iterator it2 = mp2.begin(); it2 != mp2.end(); it2++)
		{
			int mulcoef = it1->second*it2->second;  //系数
			int mulexponenet = it1->first + it2->first;  //指数

			if (mul.find(mulexponenet) == mul.end())
				mul[mulexponenet] = 0;	
			mul[mulexponenet] += mulcoef;
			if (mul[mulexponenet] == 0)
			{
				mul.erase(mulexponenet);
			}
		}
	}
	return mul;
	
}

//打印函数
void printy(map<int, int>& mp)
{
	map<int, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
		if (it == mp.begin())
		{
			if (it->second == 1)
			{
				cout << "x^" << it->first << " ";
			}

			else if (it->second == -1)
			{
				cout << "-" << "x^" << it->first << " ";
			}

			else
			{
				cout << it->second << "x^" << it->first << " ";
			}
		}
		else
		{
			if (it->second > 0)
			{
				if (it->second == 1)
				{
					cout << " + " << "x^" << it->first << " ";
				}
				else
				{
					cout << " + " << it->second << "x^" << it->first << " ";
				}
			}

			if (it->second < 0)
			{
				if (it->second == -1)
				{
					cout << " - " << "x^" << it->first << " ";
				}
				else
				{
					cout << it->second << "x^" << it->first << " ";
				}
			}
		}
	cout << endl;
}








int main()
{

	map<int, int>mp1;
	mp1.insert(pair<int, int>(1, 10));
	mp1.insert(pair<int, int>(2, 20));
	/*mp1.insert(pair<int, int>(3, 30));
	mp1.insert(pair<int, int>(4, 40));
	mp1.insert(pair<int, int>(5, 50));*/
	cout << "f(x)=";
	printy(mp1);

	map<int, int>mp2;
	mp2.insert(pair<int, int>(1, 10));
	mp2.insert(pair<int, int>(3, 20));
	mp2.insert(pair<int, int>(2, 30));
	/*mp2.insert(pair<int, int>(4, 40));
	mp2.insert(pair<int, int>(6, 50));
	mp2.insert(pair<int, int>(5, 60));*/
	cout << "g(x)=";
	printy(mp2);

	map<int, int>sumMp;
	sumMp = mp1 + mp2;
	cout << "f(x)+g(x)=";
	printy(sumMp);

	map<int, int>subMp;
	subMp = mp1 - mp2;
	cout << "f(x)-g(x)=";
	printy(subMp);    

	map<int, int>mulMp;
	mulMp = mp1 * mp2;
	cout << "f(x)*g(x)=";
	printy(mulMp);



	system("pause");
	return 0;
}