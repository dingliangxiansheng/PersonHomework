#include"DArray.h"

DArray::DArray() //Ĭ�Ϲ��캯��
{
	cout << "Ĭ�Ϲ��캯������" << endl;

	m_pData = nullptr;
	m_Size = 0;
	
}

DArray::DArray(int nSize, double dValue)  //ʹ��Ĭ��ֵ��������
{
	m_Size = nSize;
	m_pData = new double[m_Size];

	//��ÿ��Ԫ�ظ�ֵ
	for (int i = 0; i < m_Size; i++)
	{
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray& arr)  //��������
{
	this->m_pData = new double[arr.m_Size];
	this->m_Size = arr.m_Size;
	for (int i = 0; i < this->m_Size; i++)
	{
		this->m_pData[i] = arr.m_pData[i];
	}
}



void DArray::Print()  //��ӡ����Ԫ��
{
	if (m_pData == NULL)
	{
		cout << "û������" << endl;
	}
	for (int i = 0; i < m_Size; i++)
	{
		cout << "pData" << "[" << i << "]" << "=" << m_pData[i] << endl;
	}
}

int DArray::GetSize() // �õ�������С
{
	cout << "����Ĵ�СΪ��" << m_Size << endl;
	return m_Size;
}

void DArray::SetSize(int nSize) // ������������Ĵ�С
{
	if (m_Size == nSize)
	{
		return;
	}

	if (m_Size < nSize)
	{
		double *pData = new double[nSize];

		//��ǰ����Ǩ��
		for (int i = 0; i < m_Size; i++)
		{
			pData[i] = m_pData[i];
		}
		//�������Ĭ��Ϊ 0
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
		//����Ǩ��
		for (int i = 0; i < nSize; i++)
		{
			pData[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = pData;
		m_Size = nSize;

	}
}

void DArray::InsertAt(int nIndex, double dValue) // ��ĳ������������һ����Ԫ��
{
	if (nIndex<0 || nIndex>m_Size)
	{
		cout << "��������" << endl;
		return;
	}

	double *pData = new double[m_Size + 1];
	//����Ǩ��
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

void DArray::DeleteAt(int nIndex) // ɾ��ĳ�������ϵ�Ԫ��
{
	if (nIndex<0 || nIndex>m_Size)
	{
		cout << "��������" << endl;
	}

	double *pData = new double[m_Size - 1];
	//����Ǩ��
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

void DArray::PushBack(double dValue) // �������ĩβ���һ����Ԫ��
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

DArray& DArray::operator=(DArray& acopy)  //���������=
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

double& DArray::operator[](int nIndex) // ����[]���������ķ�ʽ����
{
	return this->m_pData[nIndex];
}

DArray::~DArray()  //��������
{
	cout << "������������" << endl;
	if (m_pData != NULL)
	{
		delete[]m_pData;
		m_pData = NULL;
		m_Size = 0;
	}
}