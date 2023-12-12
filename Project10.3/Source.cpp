#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct  Students
{
    string name;
    int grade1;
    int grade2;
    int grade3;
};

void createFile(const string& filename, const Students& students) 
{
    ofstream file(filename, ios::app);
    if (!file) 
    {
        cerr << "Cannot create file." << endl;
        return;
    }
    file << students.name << "," << students.grade1 << "," << students.grade2 << "," << students.grade3 << endl;
    file.close();
}

void displayFile(const string& filename) 
{
    ifstream file(filename);
    if (!file) 
    {
        cerr << "Cannot open file" << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        cout << line << endl;
    }

    file.close();
}

void addStudent(const string& filename, const Students& students) 
{
    ofstream file(filename, ios::app);
    if (!file) 
    {
        cerr << "Cannot open file for appending." << endl;
        return;
    }

    file << students.name << "," << students.grade1 << "," << students.grade2 << "," << students.grade3 << endl;

    file.close();
}

int main() 
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    Students students;
    int n;
    cout << "N: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter students name: ";
        cin >> students.name;
        cout << "Enter grade1: ";
        cin >> students.grade1;
        cout << "Enter grade2: ";
        cin >> students.grade2;
        cout << "Enter grade3: ";
        cin >> students.grade3;
        createFile(filename, students);
    }

    int choice;
    do {
        cout << "Menu:\n1. Display file content\n2. Add student\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            displayFile(filename);
            break;
        case 2: 
        {
            Students newStudent;
            cout << "Enter students name: ";
            cin >> newStudent.name;
            cout << "Enter grade1: ";
            cin >> newStudent.grade1;
            cout << "Enter grade2: ";
            cin >> newStudent.grade2;
            cout << "Enter grade3: ";
            cin >> newStudent.grade3;

            addStudent(filename, newStudent);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
