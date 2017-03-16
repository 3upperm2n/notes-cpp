#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void display(T &vec)
{
	for (auto i: vec)
		cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> v1(10, 1); // ten 1s
	cout << v1.size() << endl;
	display<vector<int>>(v1);


	vector<string> v2{10, "h"}; // ten hs
	//vector<string> v2(10, "h");
	cout << v2.size() << endl;
	display<vector<string>>(v2);

	vector<vector<int>> ivec;
	//vector<string> svec = ivec; 	// wrong
	//vector<vector<int>> svec = ivec; // correct

	//vector<string> svec(10, "null"); // correct
	//display<vector<string>>(svec);

	vector<int> v3(10, 42); // ten 42s
	display<vector<int>>(v3);

	vector<int> v4{10, 42}; // ten 42s
	display<vector<int>>(v3);

	vector<int> v5{10}; // one 10
	cout << v5.size() << endl;

	vector<int> v6(10); // 10 zeros
	cout << v6.size() << endl;

	return 0;
}
