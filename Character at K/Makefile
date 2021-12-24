CC = g++ # compiler on linux

all: CharacterAtK.cpp # requires .cpp file
	@$(CC) CharacterAtK.cpp -o CharacterAtK # compiled C++ program is CharacterAtK. @ will suppress the echo

run: all
	@./CharacterAtK # compiles the program and runs it program

test: all
	@./out_test | ./CharacterAtK # runs the program by providing it with the sample input from out_test file

clean:
	@rm -rf CharacterAtK # clears the output