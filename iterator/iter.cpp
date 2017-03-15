#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

/*
 notes

 in c++11, there is cbegin and cend, for constant iterator

 */
int main()
{
	//----------------//
	// example 1
	//----------------//
	string s("some string");
	cout << s << endl;

	if(s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}

	cout << s << endl;

	//----------------//
	// example 2
	//----------------//
	for(auto it = s.begin(); it!=s.end() && !isspace(*it); it++) {
		*it = toupper(*it);	
	}
	cout << s << endl;

	for(auto it = s.begin(); it!=s.end(); it++) {
		if(!isspace(*it))
			*it = toupper(*it);	
	}
	cout << s << endl;

	//----------------//
	// example 3
	//----------------//
	for(auto i: s)
		cout << i << " ";
	cout<< endl;

	for(auto i: s) {
		if(!isspace(i))
			i = tolower(i);	
		cout << i << endl;
	}
	cout << s << endl;

	//----------------//
	// example 4
	//----------------//

	vector<int> array(10, 2);
	for (auto i: array)
		cout << i <<  " ";
	cout << endl;

	for(auto it=array.begin(); it!=array.end(); it++) {
		*it = (*it) * (*it);
	}
	for (auto i: array)
		cout << i <<  " ";
	cout << endl;



	// using iterator for binary search, but the array needs to be sorted already


	return 0;
}
