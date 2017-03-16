// http://www.dev-hq.net/c++/20--function-pointers

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void one() {cout << "one\n";}
void two() {cout << "two\n";}

void add(int a, int b) { cout << a + b << endl;}
void mul(int a, int b) { cout << a * b << endl;}


class Number
{
	public:
		int i;
		Number() { i = 0; }
		int addone() { return i+1; }
		int addtwo() { return i+2; }
};



class Employee
{
	public:
		Employee() {
			// init with a function pointer		
			money = &Employee::Cal_wage;
		}

		void promote() {
			money = &Employee::Cal_highwage;
		}

		double Pay(double hours) {
			return (this->*money)(hours); // pointer to Cal_wage
		}

	private:
		double (Employee::*money) (double hours);
		double Cal_wage(double hours) {
			return hours * 10;
		}
		double Cal_highwage(double hours) {
			return hours * 20;
		}
};

int main()
{
	//----------------//
	// example 1
	//----------------//
	void (*fptr)();

	fptr = &one;   // works: it is preferred
	//fptr = one; // works
	fptr();

	fptr = two;
	fptr();

	//----------------//
	// example 2
	//----------------//
	void (*ptr) (int, int);

	ptr = &add;
	ptr(11, 3);

	ptr = &mul;
	ptr(3, 5);

	//----------------//
	// example 3
	//----------------//
	void (*ptr_array[2]) (int, int);

	ptr_array[0] = add;
	ptr_array[1] = mul;

	ptr_array[0](1, 3);
	ptr_array[1](3, 7);

	//----------------//
	// example 4
	//----------------//
	Number num;
	int (Number::*num_ptr)(); // pointer to member functions

	num_ptr = &Number::addone; // ptr to func one ()
	cout << (num.*num_ptr)() << endl;

	num_ptr = &Number::addtwo; // ptr to func two ()
	cout << (num.*num_ptr)() << endl;

	//----------------//
	// example 5
	//----------------//
	Employee waiter;
	cout << waiter.Pay(10) << endl;

	waiter.promote();
	cout << waiter.Pay(10) << endl;

	return 0;
}

