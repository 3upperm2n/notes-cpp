#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

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

	return 0;
}
