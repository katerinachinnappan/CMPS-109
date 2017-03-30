#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <map>
#include "KB.h"
#include "FactType.h"
using namespace std;
KB::KB() :facts(), factType() {}//initialize to null
KB::KB(std::map<FactType, std::vector<Fact*>> facts, std::map<FactType, std::vector<Fact*>>::iterator myMapIterator){
    for(myMapIterator = facts.begin(); myMapIterator != facts.end(); myMapIterator++)
    {
        this->myMapIterator = myMapIterator;
    }
}
int main(){
    cout<<"KBClient test"<<endl;

}
