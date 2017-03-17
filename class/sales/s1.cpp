#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Sales_data {
	string isbn() const { return bookNo; }
	double avg_price() const; 
	Sales_data &combine(const Sales_data&);

	//-----------------
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

//-------------------------//
// class member func
//-------------------------//
double Sales_data::avg_price () const
{
	if(units_sold) {
		return revenue / units_sold;	
	} else {
		return 0;	
	}
}


Sales_data& Sales_data::combine(const Sales_data& myData) {
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
ostream &print(ostream &os, const Sales_data& item)
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

	/*
	Sales_data data1, data2;

	double price = 0;

	// input 1
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	// input 2
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	if(data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;

		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
	
		if( totalCnt != 0) {
			cout <<  totalRevenue / totalCnt <<  endl;
		} else {
			cout <<	"(no sales)" << endl;
		}

		return 0;
	} else {
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}
	*/

	return 0;
}
