#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// http://www.bogotobogo.com/cplusplus/C11/C11_initializer_list.php

class MyVec 
{
	public:
		MyVec(initializer_list<int> v) {
			for (auto item: v) {
				iVec.push_back(item);
			}
		}

		void print() {
			for (auto item: iVec) {
				cout << item<< " ";
			}
			cout << endl;
		}
	private:
		vector<int> iVec;
};

int main()
{
	// old
	vector<int> v;
	v.push_back(99);
	v.push_back(88);

	for(auto i : v) {
		cout << i << " ";
	}	cout << endl;


	// c++11
	vector<int> v1={99, 88};
	for(auto i : v1) {
		cout << i << " ";
	}	cout << endl;

	// use initilizer_list in a class
	MyVec ivec = {99, 88};
	ivec.print();


	return 0;
}
