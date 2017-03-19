#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// construct order matters for correct initialization

/*
struct X {
	X (int i, int j): base(i), rem( base + j) {}
	int rem;
	int base;
};
*/

struct X {
	X (int i, int j): base(i), rem( base + j) {}
	int base;
	int rem;
};

int main()
{
	X test(1, 2);
	cout << test.base << ' ' << test.rem << endl;

	return 0;
}
