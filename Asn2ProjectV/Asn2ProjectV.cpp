// Asn2ProjectV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define master 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATE {
	string firstName;
	string lastName;
	string email;
};

int main()
{
#ifdef master
	cout << "running master" << endl;
#endif 
	#ifndef master
	cout << "running pre-release" << endl;
#endif

	vector<STUDENT_DATE> student;
#ifdef master
	ifstream file ("StudentData.txt");
#endif
#ifndef master
	ifstream file("StudentData_Emails.txt");
#endif
	string line;
	STUDENT_DATE temp;

	if (file.is_open()) {
		while (getline(file, line, ',')) {
			temp.lastName = line;
			
	#ifndef master
			getline(file, line, ',');
			temp.firstName = line;
			getline(file, line);
			temp.email = line;
	#endif
#ifdef master
			getline(file, line);
			temp.firstName = line;
#endif
			student.push_back(temp);

		}
	}
	else {
		cout << "Unable to open file" << endl;
		return 0;
	}
	
#ifdef _DEBUG
	for (int i = 0; i < student.size(); i++) {
		cout << student[i].lastName << ", " << student[i].firstName;
#ifdef master
		cout << endl;
#endif
#ifndef master
		cout << ", " << student[i].email << endl;
#endif

	}
#endif // _DEBUG

	file.close();
	return 1;
}
