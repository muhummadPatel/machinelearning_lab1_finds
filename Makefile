CPP=g++
CPPFLAGS=-std=c++11 -g
EXE_NAME=findS

$(EXE_NAME): findS.cpp
	$(CPP) -o $(EXE_NAME) findS.cpp $(CPPFLAGS)

clean:
	rm -f *.o $(EXE_NAME)