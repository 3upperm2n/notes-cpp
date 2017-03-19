### friend
let function to access the private member of the class

Inside a class, you can make **friend** with another class , or with the member function of another class.

### mutable
**mutable** data member, can never be **const**, even used inside the const member function.

### typedef
you can define the data type and used in the class

```c++
typedef double Money

class Account {
public:
	Money balance() { return bal; }

private:
	Money bal;
};

```
