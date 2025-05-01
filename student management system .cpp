#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore(); // clear buffer
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

class StudentManager {
private:
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentManager() {
        count = 0;
    }

    void addStudent() {
        if (count < MAX_STUDENTS) {
            cout << "--- Add Student ---\n";
            students[count].input();
            count++;
            cout << "Student added successfully!\n";
        } else {
            cout << "Student limit reached.\n";
        }
    }

    void displayStudents() {
        if (count == 0) {
            cout << "No student records found.\n";
        } else {
            cout << "--- Student List ---\n";
            for (int i = 0; i < count; i++) {
                students[i].display();
            }
        }
    }

    void searchStudent(int rollNo) {
        for (int i = 0; i < count; i++) {
            if (students[i].rollNo == rollNo) {
                cout << "--- Student Found ---\n";
                students[i].display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int rollNo) {
        for (int i = 0; i < count; i++) {
            if (students[i].rollNo == rollNo) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice, rollNo;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Delete Student\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayStudents();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                manager.searchStudent(rollNo);
                break;
            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                manager.deleteStudent(rollNo);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
