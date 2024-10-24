#pragma once
class Vector
{
private:
	int* arr;
	int size;
        friend ostream& operator<<(ostream& os, Vector obj);
	friend istream& operator>>(istream& is, Vector& obj);
public:
	Vector();
	~Vector();
	Vector(const Vector & obj);

	Vector(std::initializer_list<int> list);

	Vector(int s);
	void InputRand(); // èíèöèàëèçàöèÿ ñëó÷ ÷èñëàìè
	void Print();// âûâîä íà êîíñîëü

	void PushBack(int a);
	int PopBack();


	/// ïåðåãðóçêè îïåðàöèè
	Vector operator-(int a);
	Vector& operator++();
	Vector& operator--();
	Vector& operator+=(int a);
	Vector& operator-=(int a);
	Vector& operator*=(int a);
};
