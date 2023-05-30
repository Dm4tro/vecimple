#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <cctype> 
#include <map>
#include <list>
using namespace std;

class Vector
{
public:
	Vector() {
		capacity = 20;
		arr = new int[capacity];
		current = 0;
		
	}
	~Vector() {
		delete[] arr;
	}

	void push_back (int num) {
		if (capacity==current)
		{
			int* temp = new int[capacity * 2];

			for (size_t i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}

			delete[]arr;
			arr = temp;
			capacity = capacity * 2;

		}

		arr[current] = num;
		current++;

	}

	void replace_at(int pos, int num) {

		arr[pos] = num;


	}


	void print() {
		for (size_t i = 0; i <current; i++)
		{
			cout << arr[i] << " ";

		}
		cout << endl;
	}

	int get_capacity() {
		return capacity;
	}

	int get_current() {
		return current;
	}

	void add_at(int pos, int num) {
		if (capacity == current+1)
		{
			int* temp = new int[capacity * 2];

			for (size_t i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}

			delete[]arr;
			arr = temp;
			capacity = capacity * 2;

		}

		int* temp = new int[capacity];
		for (size_t i = 0; i < pos; i++)
		{
			temp[i] = arr[i];
		}
		temp[pos] = num;
		for (size_t i = pos+1; i < capacity; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}

	Vector& operator=(Vector& v1) {
		
		
		delete[] arr;
		capacity = v1.capacity;
		int* arr = new int[capacity];
		for (size_t i = 0; i < capacity; i++)
		{
			arr[i] = v1.arr[i];
		}
		current = v1.current;
		return *this;
	}

private:
	int* arr;
	int capacity;
	int current;
};




int main()
{
	Vector vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);
	vi.push_back(6);
	vi.push_back(7);


	vi.add_at(2, 111);


	vi.print();

	Vector v2;
	v2.push_back(1);

	v2.print();
	v2 = vi;
	v2.print();

    return 0;
}
