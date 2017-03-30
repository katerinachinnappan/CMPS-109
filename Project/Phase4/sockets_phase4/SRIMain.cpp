#include "SRIMain.h"

SRIMain::SRIMain(TCPSocket * p_tcpSocket) {
	char fileName[1024];
        int readIn;

	SRI* sri = new SRI();

	string input;

	while (true) {
		memset (fileName,0,1024);
		readIn = p_tcpSocket->readFromSocket(fileName,1021);

		if(readIn > 0){

			input = fileName;

			if (input == "QUIT") break;
			else sri->load(input);

		}

	}

	delete(sri);

}
