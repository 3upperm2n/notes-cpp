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


	return 0;
}
