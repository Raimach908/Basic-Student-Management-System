#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
using namespace std;
#include "sms.h"
// DateOfBirth class
DateOfBirth::DateOfBirth()
{
    day = 0;
    month = 0;
    year = 0;
}
void DateOfBirth::setDay()
{
    while (day <= 0 || day > 31)
    {
        cout << "\tEnter day: ";
        cin >> day;
    }
}

void DateOfBirth::setMonth()
{
    while (month <= 0 || month > 12)
    {
        cout << "\tEnter month: ";
        cin >> month;
    }

    if (((day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) ||
        ((day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11)) || ((day <= 29) && (month == 2)))
    {
        // No changes needed
    }
    else
    {
        month = 0;
        setMonth();
    }
}

void DateOfBirth::setYear()
{
    while (year <= 0 || year > 2023)
    {
        cout << "\tEnter year: ";
        cin >> year;
    }
}

void DateOfBirth::setMonthDayYear()
{
    cout << "\tEnter date of birth (dd/mm/yyyy): " << endl;
    day = 0;
    month = 0;
    year = 0;
    setDay();
    setMonth();
    setYear();
}

void DateOfBirth::displayDOB()
{
    cout << "\t" << day << "/" << month << "/" << year;
}

// Student class
void Student::addStudent(int index)
{
    cout << "\tEnter details of student #" << index + 1 << ":-" << endl;
    admission_no = 0;
    while (admission_no <= 0)
    {
        cout << "\tEnter admission_no: ";
        cin >> admission_no;
    }
    cin.ignore();
    cout << "\tEnter full name: ";
    getline(cin, name);
    cout << "\tEnter gender (Female/Male): ";
    getline(cin, gender);
    cout << "\tEnter roll_no (e.g; bcsf21m078): ";
    getline(cin, roll_no);
    cout << "\tEnter phone_no: ";
    getline(cin, phone_no);
    cout << "\tEnter email: ";
    getline(cin, email);
    cout << "\tEnter address: ";
    getline(cin, address);
    DOB.setMonthDayYear();
    cout << endl;

    ofstream f1;
    f1.open("records.txt", ios::app);
    f1 << "\n";
    f1 << admission_no << " " << name << " " << gender << " " << roll_no << " ";
    f1 << DOB.day << " " << DOB.month << " " << DOB.year << " ";
    f1 << phone_no << " " << email << " " << address << endl;
    f1.close();
}

void Student::No_Of_Students()
{
    ifstream f1;
    string str;
    f1.open("records.txt", ios::in);
    if (f1.fail())
    {
        cout << "\tFile does not exist here" << endl;
    }
    else
    {
        int students = 0;
        while (getline(f1, str))
        {
            if ((str[0] >= 1))
            {
                students++;
            }
        }
        cout << "\n\tNumber of students: " << students << endl;
    }
    f1.close();
}

void Student::editStudentDetail(char admit_no)
{
    ifstream f1;
    ofstream temp;
    bool found = false;
    string line;
    temp.open("temp.txt", ios::out);
    f1.open("records.txt", ios::in);

    if (f1.fail())
    {
        cout << "\tFile does not exist\n";
    }
    else
    {
        while (getline(f1, line))
        {
            if (line[0] == admit_no)
            {
                found = true;
                cin.ignore();
                cout << "\tEnter new admission_no: ";
                cin >> admission_no;
                cin.ignore();
                cout << "\tEnter full name: ";
                getline(cin, name);
                cout << "\tEnter gender (Female/Male): ";
                getline(cin, gender);
                cout << "\tEnter roll_no (e.g., bcsf21m078): ";
                getline(cin, roll_no);
                cout << "\tEnter phone_no: ";
                getline(cin, phone_no);
                cout << "\tEnter email: ";
                getline(cin, email);
                cout << "\tEnter address: ";
                getline(cin, address);
                DOB.setMonthDayYear();
                cout << endl;

                temp << admission_no << " " << name << " " << gender << " " << roll_no << " ";
                temp << DOB.day << " " << DOB.month << " " << DOB.year << " ";
                temp << phone_no << " " << email << " " << address << endl;
            }
            else
            {
                temp << line << endl;
            }
        }
        f1.close();
        temp.close();
        remove("records.txt");
        rename("temp.txt", "records.txt");
        if (!found)
        {
            cout << "\tAdmission number not found." << endl;
        }
        else
        {
            cout << "\tDetails updated successfully." << endl;
        }
    }
}

void Student::removeStudent(int admit_no)
{
    ifstream f1;
    ofstream temp;
    bool found = false;
    string line;
    temp.open("temp.txt", ios::out);
    f1.open("records.txt", ios::in);

    if (f1.fail())
    {
        cout << "\tFile does not exist here\n";
    }
    else
    {
        while (getline(f1, line))
        {
            int record_admit_no;
            stringstream ss(line);
            ss >> record_admit_no;
            if (record_admit_no == admit_no)
            {
                found = true;
                // Skip storing the line, effectively removing it
            }
            else
            {
                temp << line << endl;
            }
        }

        f1.close();
        temp.close();

        remove("records.txt");
        rename("temp.txt", "records.txt");

        if (!found)
        {
            cout << "\tAdmission number not found." << endl;
        }
        else
        {
            cout << "\tStudent removed successfully." << endl;
        }
    }
}
void Student::showRecords()
{
    cout << "\n\tStudent Details:-" << endl << endl;
    ifstream f2;
    f2.open("records.txt", ios::in);
    bool found = false;
    if (f2.fail())
    {
        cout << "\tNo records found.\n";
        f2.close();
        return;
    }
    while (f2 >> admission_no)
    {
        found = true;
        cout << "\t\t ------ Admission Number " << admission_no << " -----" << endl;
        f2.ignore();
        cout << "\tFull name: ";
        getline(f2, name, ' ');
        cout << name << endl;
        cout << "\tGender: ";
        getline(f2, gender, ' ');
        cout << gender << endl;
        cout << "\tRoll_No: ";
        getline(f2, roll_no, ' ');
        cout << roll_no << endl;
        cout << "\tDate Of Birth: ";
        f2 >> DOB.day;
        f2 >> DOB.month;
        f2 >> DOB.year;
        cout << DOB.day << "/" << DOB.month << "/" << DOB.year << endl;
        f2.ignore();
        cout << "\tPhone_No: ";
        getline(f2, phone_no, ' ');
        cout << phone_no << endl;
        cout << "\tEmail: ";
        getline(f2, email, ' ');
        cout << email << endl;
        cout << "\tAddress: ";
        getline(f2, address);
        cout << address << endl << endl;
    }
    f2.close();
    if (!found)
    {
        cout << "\tRecords not found.\n";
    }
    else
    {
        cout << "\tRecords displayed successfully.";
    }
}
Student::~Student() {}