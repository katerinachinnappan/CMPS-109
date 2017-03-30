#include "SRIMain.h"

SRIMain::SRIMain(TCPSocket * p_tcpSocket) {
	char fileName[1024]; // A buffer for holding the file name
    int read_bytes;

	SRI* sri = new SRI();

	string input;

	while (true) {
		memset (fileName,0,1024); // Initialize the buffer
		read_bytes = p_tcpSocket->readFromSocket(fileName,1023);

		if(read_bytes > 0){

			input = fileName;

			if (input == "QUIT") break;
			else sri->parse(input);

		}

	}

	delete(DB);

}
