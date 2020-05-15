CC=g++
CCFLAGS=-std=c++11

main: main.cpp State.cpp Transition.cpp
	$(CC) -c main.cpp -o bin/main.o $(CCFLAGS)
	$(CC) -c State.cpp -o ./bin/state.o $(CCFLAGS)
	$(CC) -c Transition.cpp -o ./bin/transition.o $(CCFLAGS)
	$(CC) -o main bin/main.o bin/state.o bin/transition.o $(CCFLAGS)

run:
	./main

clean:
	rm main
	rm bin/*.o

