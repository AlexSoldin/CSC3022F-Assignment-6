CC=g++
CCFLAGS=-std=c++11

main: main.cpp pca.cpp
	$(CC) -c pca.cpp -o bin/pca.o $(CCFLAGS)
	$(CC) -c main.cpp -o bin/main.o $(CCFLAGS)
	$(CC) -o main bin/main.o bin/pca.o $(CCFLAGS)

run:
	./main

clean:
	rm main
	rm bin/*.o

