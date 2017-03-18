#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// size_type need to go with containers
// it is like size_t, but more dynamic and tolerable on the data size

class Screen
{
public:
	typedef string::size_type pos;
	
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

	char get() const { return contents[cursor];	}	// implicit inline
	inline char get(pos ht, pos wd) const;			// explicit inline
	Screen &move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};

char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];
}

inline
Screen& Screen::move(pos r, pos c) 
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

int main()
{

	return 0;
}
