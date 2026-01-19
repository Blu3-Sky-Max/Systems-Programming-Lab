#include <iostream>
#include <string>
using namespace std;
/* Author: Usman O. Olanrewaju
 * Title: Student-Registry-System 
 */ 

struct Student {
	int id;
	string name;
	int age;
};

class  StudentManager {

public:
	void addStudent(Student*& students, int& size, int id, const string& name, int age) {
		Student* newStudents = new Student[size + 1];
		for (int i = 0; i < size; ++i) {
			newStudents[i] = students[i];
		}
		newStudents[size].id = id;
		newStudents[size].name = name;
		newStudents[size].age = age;
		delete[] students;
		students = newStudents;
		++size;
	}


	void listStudents(const Student* students, int size) {
		for (int i = 0; i < size; ++i) {
			cout << "ID: " << students[i].id<<"\n" << "Name: " << students[i].name <<"\n"<< "Age: " << students[i].age<<"\n" << endl;
		}
	}

	void removeStudent(Student*& students, int& size, int id) {
		int index = -1;
		for (int i = 0; i < size; ++i) {
			if (students[i].id == id) {
				index = i;
				break;
			}
		}

		if (index == -1) {
			cout << "Student with ID " << id << " does not exist." << endl;
			return;
		}

		Student* newStudents = new Student[size - 1];
		for (int i = 0, j = 0; i < size; ++i) {
			if (i != index) {
				newStudents[j++] = students[i];
			}
		}
		delete[] students;
		students = newStudents;
		--size;
	}
};
int main() {
     StudentManager objStudentManager;
	Student* students = nullptr;
	int size = 0;
	int choice;

	do {
		cout << "Menu:\n1. Add Student\n2. List Students\n3. Remove Student\n4. Exit\nEnter your choice: ";
		cin >> choice;

		if (choice == 1) {
			int id, age;
			string name;
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Age: ";
			cin >> age;
		objStudentManager.addStudent(students, size, id, name, age);
		} else if (choice == 2) {
			objStudentManager.listStudents(students, size);
		} else if (choice == 3) {
			int id;
			cout << "Enter ID to remove: ";
			cin >> id;
		objStudentManager.removeStudent(students, size, id);
		}
	} while (choice != 4);

	delete[] students;
	
}
