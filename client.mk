INC_DIR=-I
LIB_DIR=-L
LIB=

CC=g++ -g
CFLAGS=-Wall
EXE=client

all:
	$(CC) $(CFLAGS) $(EXE).cpp -o $(EXE) $(INC_DIR) $(LIB_DIR) $(LIB)

clean:
	rm -rf *.o $(EXE).so