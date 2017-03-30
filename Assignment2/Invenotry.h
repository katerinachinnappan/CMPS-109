#ifndef INVENOTRY_H_INCLUDED
#define INVENOTRY_H_INCLUDED
class Inventory{
    private:
        int exit;
        unsigned *int product;
        string color;
    public:
        Inventory(int total);
        int checkIn(int id, int total);
        void checkOut(int id);
        int checkAvailable();
        bool isEmpty(int id, int type, int total);
        void setID(int id);
        ~Inventory();

};


#endif // INVENOTRY_H_INCLUDED
