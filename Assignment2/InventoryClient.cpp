//Katerina Chinnappan
//CMPS 109
//Problem 2
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Inventory.h"
using namespace std;

//operator << overload for color cases
ostream& operator<<(ostream& os, color c)
{
    switch(c)
    {
        case red   : os << "red";    break;
        case yellow: os << "yellow"; break;
        case green : os << "green";  break;
        case blue  : os << "blue";   break;
        case white : os << "white";  break;
        case orange: os << "orange"; break;
        case purple: os << "purple"; break;
        case black : os << "black";  break;
        default    : os.setstate(ios_base::failbit);
    }
    return os;
}
//default constructor
Inventory::Inventory(int total)
{
    exit = total;
    product = (unsigned int*)calloc(total, sizeof(unsigned int));

}
//checkIn a product ID
void Inventory::checkIn(int id, int total, color col)
{
    //if id is greater than capacity or its less than 0, pause
    if(id > total || id < 0)
    {
        cout<<"The product ID entered is out of range"<<endl;

    }
    else{
    if(isEmpty(id, 0, total))
        cout<<"Cannot insert product "<<id<<endl;
    else
    {
        cout<<"Product "<<id<<" color: "<<col<<" , is added"<<endl;
        //decrement capacity
        exit--;
        //increment stock
        product[id]++;
    }
    }

}
//set the ID
void Inventory::setID(int id)
{
    productKey = id;
}
//set the color
void Inventory::setColor(color col)
{
    productColor = col;
}
void Inventory::checkOut(int id, int total, color col)
{
    if(id > total || id < 0)
    {
         //if id is greater than capacity or its less than 0, pause
         cout<<"The product ID entered is out of range"<<endl;
    }
    //if id matches entered and color
    if(productKey == id && productColor == col)
    {
        //decrement the stock
        product[id]--;
        //increment capacity
        exit++;
        cout<<"Product "<<id<<" , color "<<col<< " is checked out"<<endl;
    }
    else
        cout<<"Product not available for checkout"<<endl;

}
bool Inventory::isEmpty(int id, int type, int total)
{
    if(type == 0)
    {
        //if product matches capacity
        if(product[id] == total)
            return true;
        else
            return false;
    }
    else if(type == 1)
    {
        //if product greater than 0
        if(product[id] > 0)
            return true;
        else
            return false;

    }
}
int Inventory::isTotal(int id, bool availability)
{
    //if true, return the stock amount of a product
    if(availability)
        cout<<"There is/are "<<product[id]<<" product of id "<<id<<endl;
    return product[id];
}
int Inventory::checkAvailable()
{
    //return the final inventory number
    return exit;
}
int main()
{
    //enter any desired capacity
    int capacity;
    cout<<"Enter total number of students"<<endl;
    cin>>capacity;

    //enum color
    color col;
    Inventory *myInventory = new Inventory(capacity);
    /****this will throw an error****/
    cout<<"Checking in product 257: "<<endl;
    col = blue;
    myInventory->checkIn(257, capacity, col);
    /****this will check in****/
    cout<<"Checking in product 3, color red: "<<endl;
    col = red;
	myInventory->checkIn(3, capacity, col);
	/****this will check in****/
	cout<<"Checking in product 198, color purple: "<<endl;
	col = purple;
    myInventory->checkIn(198, capacity, col);
    cout<<"Checking in product 198, color black: "<<endl;
    col = black;
    /****this will check in****/
    myInventory->checkIn(198, capacity, col);
    cout<<"Check out product 198, color black"<<endl;
    myInventory->setID(198);
    myInventory->setColor(col);
    /****this will check out****/
    myInventory->checkOut(198, capacity, col);
    /****this will give an error, won't check out****/
    cout<<"Check out product 15, color white"<<endl;
    myInventory->checkOut(15, capacity, col);
    cout<<endl;
    /****these will count the stock of the product id****/
    myInventory->isTotal(3, true);
    myInventory->isTotal(15, true);
    myInventory->isTotal(198, true);
    col = white;
    /****this will check in product 198 again and check updated stock****/
    cout<<"Checking in product 198, color white: "<<endl;
	myInventory->checkIn(198, capacity, col);
	myInventory->isTotal(198, true);
	/****this will return the total inventory checked in/out****/
	cout<<"Total inventory: "<<myInventory->checkAvailable();
}
