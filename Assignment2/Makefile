GPP      = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: problem1 problem2 problem3

problem1: StudentClient.o 
	${GPP} StudentClient.o  -o StudentClient

problem2: InventoryClient.o 
	${GPP} InventoryClient.o  -o InventoryClient

problem3: HeapClient.o 
	${GPP} HeapClient.o  -o HeapClient

%.o: %.cpp
	${GPP} -c $<

clean:
	- rm *.o StudentClient InventoryClient HeapClient

# Dependencies

StudentClient.o: StudentClient.cpp Student.h
InventoryClient.o: InventoryClient.cpp Inventory.h
HeapClient.o: HeapClient.cpp Hap.h
