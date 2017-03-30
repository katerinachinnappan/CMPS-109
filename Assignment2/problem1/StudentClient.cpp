//Katerina Chinnappan
//CMPS 109
//problem 1
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Student.h"
using namespace std;

//default constructor
Student::Student(int total, int num)
{
    exit = total;
    totalStudents = total;
    roomSize = (unsigned int*)calloc(total, sizeof(unsigned int));
    classRoom = (unsigned int*)calloc(9, sizeof(unsigned int));
}
//set student id
void Student::setID(int id)
{
    studentID = id;
}
int Student::checkIn(int studentID, classroom classR) {
	if (0 <= studentID && studentID < totalStudents) {
		if (seatsAvailable() < 1) {
			cout<<"No seats currently available"<<endl;
		}
		else {//if student id matches, throw warning
			if (this->studentID == studentID) {
				cout<<"Warning: Seat "<<studentID<<" is currently occupied"<<endl;
			} else {//otherwise, reserve
				reservation(studentID, classR);
			}
		}
	} else {
	    cout<<"Cannot find student in seat "<<studentID<<" of total seats "<<totalStudents<<" or seat number out of range" <<endl;
	}
	return 0;
}
int Student::seatsAvailable()
{
	return exit;
}

void Student::reservation(int seat, classroom classR)
{
    setID(seat);
    roomSize[seat];
    //decrement capacity
	exit--;
	//increment students
	classRoom[seat]++;
	cout<<"Seat "<<seat<<" is now reserved in classroom "<<classR<<endl;
}
void Student::leaveRoom(int seat, classroom classR)
{
	if(this->studentID == seat)
    {
        roomSize[seat];
        //increment capacity
        exit++;
        //decrement students
        classRoom[seat]--;
        cout<<"Seat "<<seat<<" is now available in classroom "<<classR<<endl;

    }
    else
    {
        cout<<"Seat "<<seat<<" is currently unoccupied"<<endl;
    }
}
int Student::isTotal(int id, bool availability, classroom classR)
{
    //if true, return student amount in a classroom
    if(availability)
        cout<<"There is/are "<<classRoom[id]<<" student(s) in classroom "<<classR<<endl;
        return classRoom[id];
}

int main() {
    int capacity,num;
    classroom classR;
    cout<<"Enter total number of students"<<endl;
    cin>>capacity;
	Student *myClass = new Student(capacity, num);

    cout<<"Reserving seat 257: "<<endl;
    classR = class1;
    myClass->checkIn(257, classR);//error
    cout<<"Reserving seat 3 in classroom 1: "<<endl;
    classR = class2;
	myClass->checkIn(3, classR);//check in seat 3
	cout<<"Reserving seat 198 in classroom1: "<<endl;
	classR = class2;
    myClass->checkIn(198, classR);//check in seat 198
    cout<<"Reserving seat 198 again: "<<endl;
    myClass->checkIn(198, classR);//error
    cout<<"Exit from seat 253 in classroom 2: "<<endl;
    classR = class2;
    myClass->leaveRoom(253, classR);//error
    cout<<"Exit from seat 198 in classroom 1: "<<endl;
    myClass->leaveRoom(198, classR);//leave class 1 from seat 198

    cout<<"\n";
    cout<<myClass->isTotal(3, true, classR)<<endl;//check how many students in class1
    cout<<"Update available seats: "<<endl;
    cout<<"Number of available seats: "<<myClass->seatsAvailable()<<" of total "<<capacity;

}
