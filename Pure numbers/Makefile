CC = g++ # compiler on linux

all: Purenumbers.cpp # requires .cpp file
	@$(CC) Purenumbers.cpp -o Purenumbers # compiled C++ program is Purenumbers. @ will suppress the echo

run: all
	@./Purenumbers # compiles the program and runs it program

test: all
	@./out_test | ./Purenumbers # runs the program by providing it with the sample input from out_test file

clean:
	@rm -rf Purenumbers # clears the output