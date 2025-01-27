#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    string className;
    vector<string> attendanceRecord;

    // Default constructor
    Student() {}

    // Parameterized constructor
    Student(string n, int roll, string c) {
        name=n;
        rollNumber=roll;
        className=c;
    }

    void markAttendance(string status){
        attendanceRecord.push_back(status);

    }
    void viewAttendance(){
        
        if(attendanceRecord.empty()){
            cout<<"No attendance records available for Roll No: "<<rollNumber<<endl;
            return;
        }
        cout<<"Attendance record for Roll number:"<<rollNumber<<endl;
        for(size_t i=0;i<attendanceRecord.size();++i){
            cout<<i+1<<" ."<<attendanceRecord[i]<<"\n";
        }
    }
};

class AttendanceSystem {
private:
    unordered_map<int, Student> students;

public:
    // Method declaration
    //add a new student
    void addStudent(string name, int rollNumber, string className){
        if(students.find(rollNumber) != students.end()){
             cout << "Error: Student with Roll No: " << rollNumber << " already exists in database.\n";
            return;
        }
        students[rollNumber]=Student(name,rollNumber,className);
        cout<<"Student added:"<<name<<" ,Roll No:"<<rollNumber;
    }

   //mark attendance for a student
    void markAttendance(int rollNumber, string status){
        if(students.find(rollNumber)==students.end()){
            cout << "Error: Student with Roll No: " << rollNumber << " does not exist.\n";
            return;
        }
        if (status != "Present" && status != "Absent" && status != "Late") {
            cout << "Error: Invalid attendance status. Use 'Present', 'Absent', or 'Late'.\n";
            return;
        }
        students[rollNumber].markAttendance(status);
        cout<<"Attendance marked for Roll No: "<<rollNumber<<" as "<<status<<"\n";
    }

    void viewAttendance(int rollNumber){
        if(students.find(rollNumber)==students.end()){
            cout << "Error: Student with Roll No: " << rollNumber << " does not exist.\n";
            return;
        }
        students[rollNumber].viewAttendance();
    }

    void removeStudent(int rollNumber){
        if(students.find(rollNumber)==students.end()){
            cout << "Error: Student with Roll No: " << rollNumber << " does not exist.\n";
            return;
        }
        students.erase(rollNumber);
        cout<<"Student with Roll No: " << rollNumber << " removed successfully.\n";
    }
};

int main() {
    AttendanceSystem system;
    int choice;
    int rollNumber;
    string name, className, status;

    while (true) {
        cout << "\n----- Student Attendance Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. View Attendance\n";
        cout << "4. Remove Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter class name: ";
                cin.ignore();
                getline(cin, className);
                // Call system.addStudent(name, rollNumber, className);
                system.addStudent(name, rollNumber, className);
                break;

            case 2:
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter attendance status (Present, Absent, Late): ";
                cin >> status;
                // Call system.markAttendance(rollNumber, status);
                system.markAttendance(rollNumber, status);
                break;

            case 3:
                cout << "Enter roll number: ";
                cin >> rollNumber;
                // Call system.viewAttendance(rollNumber);
                system.viewAttendance(rollNumber);
                break;

            case 4:
                cout << "Enter roll number: ";
                cin >> rollNumber;
                // Call system.removeStudent(rollNumber);
                 system.removeStudent(rollNumber);
                break;

            case 5:
                cout << "Exiting the system.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
