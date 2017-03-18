#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// size_type need to go with containers

class Screen
{
public:
	typedef string::size_type pos;
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};

int main()
{

	return 0;
}
