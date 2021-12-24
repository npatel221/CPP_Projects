CC = g++ # compiler on linux

all: ShoppingProblem.cpp # requires .cpp file
	@$(CC) ShoppingProblem.cpp -o ShoppingProblem # compiled C++ program is ShoppingProblem. @ will suppress the echo

run: all
	@./ShoppingProblem # compiles the program and runs it program

test: all
	@./out_test | ./ShoppingProblem # runs the program by providing it with the sample input from out_test file

clean:
	@rm -rf ShoppingProblem # clears the output