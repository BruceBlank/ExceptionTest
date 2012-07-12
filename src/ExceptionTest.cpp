//============================================================================
// Name        : ExceptionTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class ExceptA {

};

class ExceptB {

};

void func1() {
	cout << "In func1" << endl;
}

void func2() {
	cout << "In func2" << endl;
}


int main() {
	cout << "BEGIN" << endl;
	func1();
	func2();

	return 0;
}
