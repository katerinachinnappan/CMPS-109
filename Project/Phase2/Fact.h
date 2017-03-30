#ifndef FACT_H_INCLUDED
#define FACT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "KB.h"
//#include "FactType.h"
using namespace std;
class FactType;
class Fact : public KB{
    private:
        FactType *factType; //type of fact
        string params[]; //string parameters for fact
    public:
        Fact();

};




#endif // FACT_H_INCLUDED
