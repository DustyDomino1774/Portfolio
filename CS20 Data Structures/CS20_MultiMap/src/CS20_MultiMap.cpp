//============================================================================
// Name        : CS20_MultiMap.cpp
// Author      : Dominic London
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

#include "EmployeeSalary.hpp"
#include "Employee.hpp"
using namespace std;

int main() {

	string aNameA = "Bill";
	string aNameB = "Sue";
	string aNameC = "Brent";

	multimap<int, EmployeeSalary*> myMultiMap;
	multimap<int, EmployeeSalary*>::iterator singleIter;
	pair<multimap<int, EmployeeSalary*>::iterator,
	multimap<int,EmployeeSalary*>::iterator> rangeIter;

	map<int, Employee*> myMap;


	EmployeeSalary* a1 = new EmployeeSalary();
	Employee* A1 = new Employee();
	a1->ID = 100;
	a1->salary = 10000;
	A1->ID = 100;
	A1->name = aNameA;
	myMultiMap.insert(pair<int, EmployeeSalary*>(a1->ID,a1));
	myMap.insert(pair<int, Employee*>(A1->ID,A1));

	EmployeeSalary* a2 = new EmployeeSalary();
	Employee* A2 = new Employee();
	a2->ID = 100;
	a2->salary = 12000;
	A2->ID = 100;
	A2->name = aNameA;
	myMultiMap.insert(pair<int, EmployeeSalary*>(a2->ID,a2));
	myMap.insert(pair<int, Employee*>(A2->ID,A2));

	EmployeeSalary* a3 = new EmployeeSalary();
	Employee* A3 = new Employee();
	a3->ID = 100;
	a3->salary = 100000;
	A3->ID = 100;
	A3->name = aNameA;
	myMultiMap.insert(pair<int, EmployeeSalary*>(a3->ID,a3));
	myMap.insert(pair<int, Employee*>(A3->ID,A3));

	EmployeeSalary* b1 = new EmployeeSalary();
	Employee* B1 = new Employee();
	b1->ID = 200;
	b1->salary = 30000;
	B1->ID = 200;
	B1->name = aNameB;
	myMultiMap.insert(pair<int, EmployeeSalary*>(b1->ID,b1));
	myMap.insert(pair<int, Employee*>(B1->ID,B1));

	EmployeeSalary* b2 = new EmployeeSalary();
	Employee* B2 = new Employee();
	b2->ID = 200;
	b2->salary = 50000;
	B2->ID = 200;
	B2->name = aNameB;
	myMultiMap.insert(pair<int, EmployeeSalary*>(b2->ID,b2));
	myMap.insert(pair<int, Employee*>(B2->ID,B2));

	EmployeeSalary* c1 = new EmployeeSalary();
	Employee* C1 = new Employee();
	c1->ID = 300;
	c1->salary = 85000;
	C1->ID = 300;
	C1->name = aNameC;
	myMultiMap.insert(pair<int, EmployeeSalary*>(c1->ID,c1));
	myMap.insert(pair<int, Employee*>(C1->ID,C1));

	cout << aNameA << ": " << myMultiMap.count(100) << " pay records" << endl;
	cout << aNameB << ": " << myMultiMap.count(100) << " pay records" << endl;
	cout << aNameC << ": " << myMultiMap.count(100) << " pay records" << endl;
	cout << endl;

	double totalPay = 0;
	rangeIter = myMultiMap.equal_range(100);

	map<int, Employee*>::iterator iter;

	for (iter = myMap.begin();
			iter != myMap.end();
			++iter)
	{
		cout <<"ID: " <<(iter)->first << " Name: " << iter->second->name << endl;
		rangeIter = myMultiMap.equal_range(iter->first);

		for(singleIter = rangeIter.first;
				singleIter != rangeIter.second;
				++singleIter)
		{
			cout << "Salary: "<< (singleIter)->second->salary << endl;
		}
	}

	double avgPay = totalPay/myMultiMap.count(100);
	cout << "Bill's average raise: " << avgPay << endl;

	for (iter = myMap.begin();
			iter != myMap.end();
			++iter)
	{
		delete iter->second;
	}

	for(singleIter = myMultiMap.begin();
			singleIter != myMultiMap.end();
			++singleIter)
	{
		delete singleIter->second;

	}



	cout << "End of program." << endl; // prints !!!Hello World!!!
	return 0;
}
