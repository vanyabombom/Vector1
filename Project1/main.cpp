#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
	srand(time(0));

	Vector obj1(5); //-------------  1 2 3 4 5
	obj1.InputRand();
	obj1.Print();

	Vector obj3 = obj1 - 2;// 1 2 3    
	obj3.Print();
	obj1.Print();

	/*
	* 
	* Vector obj4 = ++obj1; // obj4 = 0 1 2 3 4 5   obj1 = 0 1 2 3 4 5
	* Vector obj5 = obj1++; // obj5 = 1 2 3 4 5     obj1 = 0 1 2 3 4 5
	*  ��� �� � ���������(obj5--, --ob5)
	* Vector obj6(3); // 1 2 3
	* obj6+=5; // 1 2 3 0 0 0 0 0
	* obj6-=5; // ���������� ��������� �� 5 ���� ���. ������ >=5,����� ������ �� ������
	* obj6*=5; // ������ ������� �������� �� 5, ���������� ������ ����� ���������
	
	*/




	


}