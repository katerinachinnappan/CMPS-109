//Katerina Chinnappan
//CMPS 109
//problem 1

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
enum classroom{
    class1,
    class2,
    class3,
    class4,
    class5,
    class6,
    class7,
    class8

};
class Student{
    private:
        int exit;
        int totalStudents;
		unsigned int *roomSize;
		unsigned int *classRoom;

    public:
        int studentID;
        Student(int total, int num);
        void reservation(int seat, classroom classR);
        int checkIn(int studentID, classroom classR);
        int seatsAvailable();
        void setID(int id);
        void leaveRoom(int seat, classroom classR);
        bool isEmpty(int seat);
        int isTotal(int id, bool availability, classroom classR);
        ~Student();
};

#endif
