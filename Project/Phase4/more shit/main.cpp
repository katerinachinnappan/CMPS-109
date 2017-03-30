#include "common.h"
//#include "SRI.h"
#include "SRI.cpp"
#include "KnowledgeBase.cpp"
#include "RuleBase.cpp"
#include "Parser.cpp"
//#include "Threads.cpp"
//#include "KnowledgeBase.h"
//#include "RuleBase.h"

void LineIn(SRI *sriobj, string str, bool *done){
		string command;
		string rest;
		string k;
		string s;
		ofstream fstor;//create output file
		stringstream iss(str);//create ss object
		getline(iss, command, ' ');//parse first input for command
		getline(iss, k);//parses rest of string and stores in rest
		char c = str[2];
		switch(c){
		case 'L':	// if(command == "RULE")
				 cout<<"Rule entered: "<<s<<endl;
            sriobj->addRule(s);
			break;
		case 'C':	// if(command == "FACT")
				cout<<"Fact entered: "<<s<<endl; //pring the fact entered on console
            sriobj->addFact(s);
			break;
		case 'A':	// if(command == "LOAD")
				cout<<"LOADING"<<endl;
            sriobj->load(s);
			break;
		case 'O':	// if(command == "DROP")
				cout<<"DROPPING"<<endl;
            sriobj->drop(s);
			break;
		case 'F':	// if(command == "INFERENCE")
				cout<<"Issuing a query"<<endl;
            sriobj->inference(s);
			break;
		case 'M':	// if(command == "DUMP")
				 sriobj->dump(s);
            cout<<"DUMPING KB AND RB"<<endl;
			break;
		case 'I':	// if(command == "EXIT")
			*done = true;
			break;
		case ' ':
			for(int i=0; i < 80; ++i){
				cout << endl;
			}
			break;
		default:
				cout << "not a valid command" << endl;
			break;
		}
}

int main(int argc, char *argv[]){
	SRI M;
	bool done = false;
	string welcome = "\n-----------Welcome to the SIMPLE RULE-BASE INFERENCE ENGINE!------------\n\n"
			"Let's get started.\n"
			"Below are a list of user commands & what they do.\n\n"
			"	LOAD - type the file, fact or rule you'd like to load\n"
			"	FACT - define a fact to add to the Knowlegde Base (KB)\n"
			"	RULE - define a rule to add to the Rule Base (RB) \n"
			"	INFERENCE - issue a query\n"
			"	DROP - used to delete a fact from the KB and RB\n"
			"	DUMP - prints the contents of KB and RB to an .sri file\n"
			"	EXIT - exit the SRI\n";
	cout << welcome <<endl;
	if(argc == 2){
		string line;
		ifstream readInput;
		readInput.open(argv[1]);
		while(getline(readInput,line)){
			LineIn(&M, line, &done);
		}
	}
	done = false;
	while(!done){
		string inp;
		cout << "Type a command: " << endl;
		getline(cin, inp);
		LineIn(&M, inp, &done);
	}

	return 0;
}
