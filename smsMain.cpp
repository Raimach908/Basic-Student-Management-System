#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
using namespace std;
#include "smsDefinitions.cpp"
int main()
{
    system("cls");
    cout <<"****************************************************************************************************************************************************************\n";
    cout <<"\n\t\t\t\t\t\t         **************************************      \n";
    cout <<"\n\t\t\t\t\t\t          Welcome to Student Management System      \n";
    cout <<"\n\t\t\t\t\t\t         **************************************    \n\n";

    int choice = 0;
    Student std1; // Declare the student object outside the switch statement
    while (choice >= 0 && choice <= 6)
    {
        cout << "\n\n\t1) Add student \n";
        cout << "\t2) Show all records \n";
        cout << "\t3) Remove student \n";
        cout << "\t4) Edit student details\n";
        cout << "\t5) How many total students?\n";
        cout << "\t6) Exit\n";

        cout << "\n\tPlease select one option.... ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            int noStudents = 0;
            while (noStudents <= 0)
            {
                cout << "\n\tHow many students do you want to add? ";
                cin >> noStudents;
            }
            for (int i = 0; i < noStudents; i++)
            {
                std1.addStudent(i);
            }
            if (noStudents == 1)
                cout << "\tStudent added successfully";
            else
                cout << "\tStudents added successfully";
            break;
        }
        case 2:
        {
            system("cls");
            std1.showRecords();
            break;
        }
        case 3:
        {
            int admit_no;
            cout << "\n\tEnter admission no which is given by institute: ";
            cin >> admit_no;
            std1.removeStudent(admit_no);
            break;
        }
        case 4:
        {
            system("cls");
            char admit_no;
            cout << "\n\tEnter admission no which is given by institute: ";
            cin >> admit_no;
            std1.editStudentDetail(admit_no);
            break;
        }
        case 5:
        {
            std1.No_Of_Students();
            break;
        }
        case 6:
        {
            cout << "\n\tPress any key to exit.... ";
            _getch();
            return 0;
        }
        default:
        {
            cout << "\tInvalid input. Please try again." << endl;
            break;
        }
        }
        cout << "\n\tPress any key to continue...";
        _getch();
        system("cls");
    }
    cout << "\n****************************************************************************************************************************************************************\n";
    return 0;
}

