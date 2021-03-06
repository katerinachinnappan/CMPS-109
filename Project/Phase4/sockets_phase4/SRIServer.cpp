#include "TCPServerSocket.h"
#include "GarbageCollector.h"
#include "Connection.h"
#include "SRI.h"

int main(int argc, char** argv) {

    GarbageCollector * gC = new GarbageCollector();

//loopback Internet protocol (IP) address also referred to as the localhost. 
//The address is used to establish an IP connection to the same machine or computer being used by the end-user.
    TCPServerSocket * tcpServerSocket = new TCPServerSocket("127.0.0.1",9999,100);

	tcpServerSocket->initializeSocket();

	while (true) {

//if timeoutSec and timeoutMilli are zeros the method will behave in a blocking mode
        TCPSocket * tcpSocket = tcpServerSocket->getConnection(0,0,-1,-1);

		if (tcpSocket == NULL) break; //otherwise won't work

		gC->cleanup(); // call cleanUp

		Connection * connection = new Connection (tcpSocket); // new instance of connection object

		connection->start();

		gC->addConnection(connection);
	}

    delete(gC);
	delete(tcpServerSocket);

	return(0);
}
