#include"DArray.h"

DArray::DArray() //默认构造函数
{
	cout << "默认构造函数调用" << endl;

	m_pData = nullptr;
	m_Size = 0;
	
}

DArray::DArray(int nSize, double dValue)  //使用默认值设置数组
{
	m_Size = nSize;
	m_pData = new double[m_Size];

	//给每个元素赋值
	for (int i = 0; i < m_Size; i++)
	{
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray& arr)  //拷贝构造
{
	this->m_pData = new double[arr.m_Size];
	this->m_Size = arr.m_Size;
	for (int i = 0; i < this->m_Size; i++)
	{
		this->m_pData[i] = arr.m_pData[i];
	}
}



void DArray::Print()  //打印数组元素
{
	if (m_pData == NULL)
	{
		cout << "没有数据" << endl;
	}
	for (int i = 0; i < m_Size; i++)
	{
		cout << "pData" << "[" << i << "]" << "=" << m_pData[i] << endl;
	}
}

int DArray::GetSize() // 得到数组大大小
{
	cout << "数组的大小为：" << m_Size << endl;
	return m_Size;
}

void DArray::SetSize(int nSize) // 重新设置数组的大小
{
	if (m_Size == nSize)
	{
		return;
	}

	if (m_Size < nSize)
	{
		double *pData = new double[nSize];

		//先前参数迁移
		for (int i = 0; i < m_Size; i++)
		{
			pData[i] = m_pData[i];
		}
		//后面参数默认为 0
		for (int i = m_Size; i < nSize; i++)
		{
			pData[i] = 0;
		}
		delete[] m_pData;
		m_Size = nSize;
		m_pData = pData;
	}

	if (m_Size > nSize)
	{
		double *pData = new double[nSize];
		//参数迁移
		for (int i = 0; i < nSize; i++)
		{
			pData[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = pData;
		m_Size = nSize;

	}
}

void DArray::InsertAt(int nIndex, double dValue) // 在某个索引处插入一个新元素
{
	if (nIndex<0 || nIndex>m_Size)
	{
		cout << "输入有误" << endl;
		return;
	}

	double *pData = new double[m_Size + 1];
	//参数迁移
	for (int i = 0; i < nIndex; i++)
	{
		pData[i] = m_pData[i];
	}
	pData[nIndex] = dValue;
	for (int i = nIndex; i < m_Size; i++)
	{
		pData[i + 1] = m_pData[i];
	}
	delete[]m_pData;
	m_pData = pData;
	m_Size++;
}

void DArray::DeleteAt(int nIndex) // 删除某个索引上的元素
{
	if (nIndex<0 || nIndex>m_Size)
	{
		cout << "输入有误" << endl;
	}

	double *pData = new double[m_Size - 1];
	//参数迁移
	for (int i = 0; i < nIndex; i++)
	{
		pData[i] = m_pData[i];
	}
	for (int i = nIndex; i < m_Size; i++)
	{
		pData[i] = m_pData[i + 1];
	}
	delete[]m_pData;
	m_pData = pData;
	m_Size--;
}

void DArray::PushBack(double dValue) // 在数组的末尾添加一个新元素
{
	double *pData = new double[m_Size + 1];
	for (int i = 0; i < m_Size; i++)
	{
		pData[i] = m_pData[i];
	}
	pData[m_Size] = dValue;
	delete[]m_pData;
	m_pData = pData;
	m_Size++;
}

DArray& DArray::operator=(DArray& acopy)  //重载运算符=
{
	if (m_pData != NULL)
	{
		delete[]m_pData;
	}
	m_Size = acopy.m_Size;
	m_pData = new double(m_Size);
	for (int i = 0; i <m_Size; i++)
	{
		m_pData[i] = acopy.m_pData[i];
	}
	return *this;
}

double& DArray::operator[](int nIndex) // 重载[]，以索引的方式返回
{
	return this->m_pData[nIndex];
}

DArray::~DArray()  //析构函数
{
	cout << "析构函数调用" << endl;
	if (m_pData != NULL)
	{
		delete[]m_pData;
		m_pData = NULL;
		m_Size = 0;
	}
}