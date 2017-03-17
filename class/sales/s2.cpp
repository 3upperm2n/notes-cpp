#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Sales_data 
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
	// constructer
	Sales_data() = default; // inline
	Sales_data(const string&s) : bookNo(s) {}
	Sales_data(const string&s, unsigned n, double p) : 
		bookNo(s), units_sold(n), revenue(p * n) {}
	Sales_data(istream &is) {
		read(is, *this);	
	}

	// func
	string isbn() { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	double avg_price () const {
		return units_sold ? revenue / units_sold : 0;
	}

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
}

// 
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

//-------------------------//
// class member func
//-------------------------//


Sales_data &combine(const Sales_data& myData) {
	units_sold += myData.units_sold;
	revenue += myData.revenue;
	return *this; 	// return the object
}

//-------------------------//
// read func
//-------------------------//
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

//-------------------------//
// print func
//-------------------------//
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
		<< item.avg_price(); 

	return os;
}


int main()
{
	Sales_data total;

	if(read(cin, total)) { 								// read input 1
		Sales_data trans;			// read input 2
		while(read(cin, trans)) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);	// isbn same, update the total
			} else {
				print(cout, total) << endl;	 // print input 1
				total = trans;	// handle the next input
			}
		
		}
		print(cout, total) << endl; // print the last input
	
	} else {
		cerr << "No data ?!" << endl;	
	}


	return 0;
}
