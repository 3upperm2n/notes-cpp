// * http://thbecker.net/articles/auto_and_decltype/section_01.html

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// the trailing return type syntax
template<typename T, typename S>
auto multiply(T lhs, S rhs) -> decltype(lhs * rhs) {
  return lhs * rhs;
}

// http://thbecker.net/articles/auto_and_decltype/section_06.html
struct S {
  S(){m_x = 42;}
  int m_x;
};

const S foo();
const int& foobar();
vector<int> vect = {42, 43};


int main()
{
	auto result = multiply(2, 3);
	cout << result << endl;

	auto res = multiply(2, 3.3);
	cout << res << endl;

	cout << multiply(2, 3.1) << endl;


	int x;
	const int cx = 42;
	const int& crx = x;
	const S* p = new S();

	// x is declared as an int: x_type is int.
	typedef decltype(x) x_type;

	// // auto also deduces the type as int: a is an int.
	auto a = x;

	// cx is declared as const int: cx_type is const int.
	auto b = cx;

	// crx is declared as const int&: crx_type is const int&.
	typedef decltype(crx) crx_type;

	// auto drops the reference and the const qualifier: c is an int.
	auto c = crx;

	// S::m_x is declared as int: m_x_type is int
	//
	// Note that p->m_x cannot be assigned to. It is effectively
	// constant because p is a pointer to const. But decltype goes
	// by the declared type, which is int.
	//
	typedef decltype(p->m_x) m_x_type;
	
	// auto sees that p->m_x is const, but it drops the const
	// qualifier. Therefore, d is an int.
	//
	auto d = p->m_x;

	//------------------------------------
	// http://thbecker.net/articles/auto_and_decltype/section_07.html
	//------------------------------------

	// (x) has type int, and decltype adds references to lvalues.
	// Therefore, x_with_parens_type is int&.
	//
	typedef decltype((x)) x_with_parens_type;

	// x is declared as an int: x_type is int.
	typedef decltype(x) x_type;


	// foo() is declared as returning const S. The type of foo()
	// is const S. Since foo() is a prvalue, decltype does not
	// add a reference. Therefore, foo_type is const S.
	//
	// Note: we had to use the user-defined type S here instead of int,
	// because C++ does not allow us to return a basic type as const.
	// (Ok, it does allow it, but the const would be ignored.)
	//
	typedef decltype(foo()) foo_type;

	// The type of vect.begin() is std::vector<int>::iterator.
	// Since vect.begin() is a prvalue, no reference
	// is added. Therefore, iterator_type is
	// std::vector<int>::iterator.
	typedef decltype(vect.begin()) iterator_type;

	// auto also deduces the type as std::vector<int>::iterator,
	// so iter has type std::vector<int>::iterator.
	auto iter = vect.begin();


	return 0;
}
