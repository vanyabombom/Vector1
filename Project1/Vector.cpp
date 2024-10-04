#include "Vector.h"
#include<iostream>
#include<Windows.h>
using namespace std;

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}
Vector::Vector(int s)
{
	size = s;
	arr = new int[size] {0};
}
Vector::~Vector()
{
	cout << "Destructor\n";
	delete[]arr;
	size = 0;
	
}
Vector::Vector(const Vector& obj)
{
	cout << "Copy constructor\n";
	this->size = obj.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}
Vector::Vector(initializer_list<int> list)
{
	size = list.size();               
	arr = new int[size];              

	int index = 0;
	for (auto i = list.begin(); i != list.end(); i++)  
	{
		arr[index++] = *i;          
	}
}
void Vector::InputRand()
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%41 - 20; // [-20 +20]
	}
}
void Vector::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a)
{
	int* temp = new int[size + 1];  // ñîäàåì íîâûé ìàññèâ (òåê ðàçìåð +1)

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; // êîïèðóåì òåêóùèå çíà÷åíèÿ ñòàðîãî ìàññèâà â íîâûé ìàññèâ
	}
	temp[size] = a; // èíèöèàëèçàöèÿ ïîñëåäíåãî ýëåìåíòà ïàðàìåòðîì ìåòîäà

	delete[] arr; // óäàëåíèå ñòàðîãî ìàññèâà!

	arr = temp; // ïåðåíàïðàâëÿåì óêàçàòåëü â îáúåêòå íà íîâûé äèí. ìàññèâ
	size++;

}

int Vector::PopBack()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; // äîñòàåì ïîñëåäíèé ýëåìåíò ñòàðîãî ìàññèâà ÄÎ óäàëåíèÿ

	delete[] arr;
	arr = temp;
	size--;

	return el;
}

Vector Vector::operator- (int a)
{
	Vector rez(size - a); // 5 - 2 = 3
	for (int i = 0; i < rez.size; i++)
	{
		rez.arr[i] = this->arr[i];
	}
	return rez;
}

Vector& Vector::operator++()
{
	int* temp = new int[size + 1];  

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i]; 
	}
	temp[size] = 0; 

	delete[] arr; 

	arr = temp; 
	size++;

	return *this;
}

Vector& Vector::operator--()
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	int el = arr[size - 1]; 

	delete[] arr;
	arr = temp;
	size--;

	return *this;
}
Vector& Vector::operator+=(int a) 
{
	int* temp = new int[size + a];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = size; i < size + a; i++)
	{
		temp[i] = 0;
	}

	delete[] arr;

	arr = temp;
	size += a;

	return *this;
}

Vector& Vector::operator-=(int a) 
{
	if (size >= a) 
	{
		int* temp = new int[size - a];
		for (int i = 0; i < size - a; i++) 
		{
			temp[i] = arr[i];
		}

		delete[] arr;

		arr = temp;
		size -= a;
	}

	return *this;
}

Vector& Vector::operator*=(int a) 
{
	for (int i = 0; i < size; i++)
	{
		arr[i] *= a;
	}

	return *this;
}


