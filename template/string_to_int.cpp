#include <iostream>
#include <sstream>

using namespace std;

/* 
	CONVERT STRING TO INT
	stringstream is stream like cin , cout i.e 
	cin >> x ;means from cin >>to>> x		ss >> val ;means from ss to val
	cout << x ;means from cout <<to<< x		ss << val ;means from val to ss

*/

int main() {
	// string ticket = "2029";
	// int ticketNumber=stoi(ticket);

	// cout << "Ticket number: " << ticketNumber;

	string s;
	cin >> s;
	
	stringstream ss(s);

	int val;
	// convert here
	ss >> val;
	cout << val << '\n';


}
//OR use stoi(string)