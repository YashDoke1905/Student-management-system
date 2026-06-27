#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int marks;

    void addStudent()
    {
        ofstream file("student.txt", ios::app);

        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        file << roll << " " << name << " " << marks << endl;
        file.close();

        cout << "Student Added Successfully.\n";
    }

    void displayStudent()
    {
        ifstream file("student.txt");

        cout << "\nStudent Records\n";

        while (file >> roll >> name >> marks)
        {
            cout << "Roll No : " << roll << endl;
            cout << "Name    : " << name << endl;
            cout << "Marks   : " << marks << endl;
            cout << "---------------------\n";
        }

        file.close();
    }

    void updateStudent()
    {
        int r;
        bool found = false;

        cout << "Enter Roll Number to Update: ";
        cin >> r;

        ifstream file("student.txt");
        ofstream temp("temp.txt");

        while (file >> roll >> name >> marks)
        {
            if (roll == r)
            {
                found = true;

                cout << "Enter New Name: ";
                cin >> name;

                cout << "Enter New Marks: ";
                cin >> marks;
            }

            temp << roll << " " << name << " " << marks << endl;
        }

        file.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (found)
            cout << "Record Updated Successfully.\n";
        else
            cout << "Student Not Found.\n";
    }

    void deleteStudent()
    {
        int r;
        bool found = false;

        cout << "Enter Roll Number to Delete: ";
        cin >> r;

        ifstream file("student.txt");
        ofstream temp("temp.txt");

        while (file >> roll >> name >> marks)
        {
            if (roll == r)
            {
                found = true;
            }
            else
            {
                temp << roll << " " << name << " " << marks << endl;
            }
        }

        file.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (found)
            cout << "Record Deleted Successfully.\n";
        else
            cout << "Student Not Found.\n";
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.updateStudent();
            break;

        case 3:
            s.deleteStudent();
            break;

        case 4:
            s.displayStudent();
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}
