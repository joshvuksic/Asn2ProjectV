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
	ifstream file ("StudentData.txt");
	string line;
	STUDENT_DATE temp;

	if (file.is_open()) {
		while (getline(file, line, ',')) {
			temp.lastName = line;
			getline(file, line);

			temp.firstName = line;
			student.push_back(temp);
		}
	}
	else {
		cout << "Unable to open file" << endl;
		return 0;
	}
	
#ifdef _DEBUG
	for (int i = 0; i < student.size(); i++) {
		cout << student[i].lastName << ", " << student[i].firstName << endl;
	}
#endif // _DEBUG

	file.close();
	return 1;
}
