//Katerina Chinnappan
//CMPS 109
//Problem 2
#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED
enum color{
    white,
    blue,
    red,
    orange,
    yellow,
    green,
    black,
    purple
};
class Inventory{
    private:
        int exit;
        int productKey;
        unsigned int* product;
        color productColor;
    public:
        Inventory(int total);
        void checkIn(int id, int total, color col);
        void checkOut(int id, int total, color col);
        int checkAvailable();
        bool isEmpty(int id, int type, int total);
        int isTotal(int id, bool availability);
        void setID(int id);
        void setColor(color col);
        ~Inventory();

};


#endif // INVENOTRY_H_INCLUDED
