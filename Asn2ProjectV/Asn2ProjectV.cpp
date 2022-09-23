// Asn2ProjectV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
