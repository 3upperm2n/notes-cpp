#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int ia[4 * 7 - 14] = {};

	for (auto i : ia)
		cout << i << " ";
	cout << endl;

	constexpr size_t array_size = 10;
	int iarray[array_size];
	for (size_t ix = 0; ix <array_size; ++ix)
		iarray[ix] = ix;
	for(auto i : iarray)
		cout << i << " ";
	cout << endl;

	int my[] = {0,1,2,3,4,5,6,7,8,9};
	int *pbeg = begin(my);
	int *pend = end(my);

	while(pbeg != pend && *pbeg<=5) {
		cout << *pbeg << " ";
		++pbeg;	
	}
	cout << endl;


	string s("hello world");
	// char *str = s; // wrong
	const char *ptr = s.c_str();

	while(*ptr) {
		cout << *ptr ;
		++ptr;
	} cout << endl;


	vector<int> ivec(begin(my), end(my));
	for(auto i: ivec) {
		cout << i << " ";	
	} cout << endl;


	vector<int> subvect(my+1, my+4);
	for(auto i: subvect) {
		cout << i << " ";	
	} cout << endl;

	//-----------------------------//
	// multi dim array
	//-----------------------------//
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	constexpr size_t rowCount = 3;
	constexpr size_t colCount = 4;
	int array2d[rowCount][colCount];

	// init using for-auto
	auto count = 0;
	for(auto &row : array2d) {
		for(auto &col : row) {
			col = count; 	
			count++;
		}
	}
	// print : using auto
	for(auto &row : array2d) {
		for(auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	cout << endl;

	// print : using auto
	cout<<endl;
	cout<<endl;
	cout<<endl;
	for(auto r = array2d; r < array2d + rowCount; r++) {
		for(auto c = *r; c < *r + colCount; c++) {
			cout << *c << " ";
		}
		cout << endl;
	}	cout << endl;


	// print : using begin/end
	cout<<endl;
	cout<<endl;
	cout<<endl;
	for(auto r = begin(array2d); r != end(array2d); r++) {
		for(auto c = begin(*r); c != end(*r); c++) {
			cout << *c << " ";
		}
		cout << endl;
	}	cout << endl;


	return 0;
}
