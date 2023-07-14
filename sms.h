#include<iostream>
#include<stdlib.h>
using namespace std;

#ifndef SMS_
#define SMS_
// DateOfBirth class
class DateOfBirth
{
public:
    int day;
    int month;
    int year;
    DateOfBirth();
    void setDay();
    void setMonth();
    void setYear();
    void setMonthDayYear();
    void displayDOB();
};
// Student class
class Student
{
private:
    string name;
    string roll_no;
    string gender;
    string phone_no;
    string email;
    string address;
    int admission_no;
    int noOfStudents;
    DateOfBirth DOB;

public:
    Student()
    {
        noOfStudents = 0;
    }
    void addStudent(int index);
    void showRecords();
    ~Student();
    void No_Of_Students();
    void editStudentDetail(char admit_no);
    void removeStudent(int admit_no);
};
#endif

