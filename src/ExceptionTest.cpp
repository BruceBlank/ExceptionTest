//============================================================================
// Name        : ExceptionTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
using namespace std;

class ExceptA : public exception {

};

class ExceptB {

};

void func1() {
	cout << "In func1" << endl;
	throw ExceptA();
}

void func2() throw (std::bad_exception, ExceptA){
	cout << "In func2" << endl;
	throw ExceptB();
}

void my_unexpected ()
{
    if (!std::uncaught_exception())
        std::cerr << "my_unexpected called\n";
    throw; // now its a bad_exception
}

int main() {
	cout << "BEGIN" << endl;

	// try func1
	try{
		func1();
	}
	catch(const ExceptA &){
		cout << "ExceptA caught!" << endl;
	}

	// try func2 with new unexpected handler
	std::unexpected_handler oldhandler = std::set_unexpected(my_unexpected);
	try{
		func2();
	}
	catch(ExceptA){
		cout << "ExceptA caught!" << endl;
	}
	catch(std::bad_exception){
		cout << "Bad Exception caught" << endl;
	}

	// try func2 with old unexpected handler
	std::set_unexpected(oldhandler);
	try{
		func2();
	}
	catch(ExceptA){
		cout << "ExceptA caught!" << endl;
	}
	catch(std::bad_exception){
		cout << "Bad Exception caught" << endl;
	}

	cout << "END" << endl;
	return 0;
}
