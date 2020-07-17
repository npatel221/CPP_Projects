CC = g++ # compiler on linux

all: URLSorter.cpp # requires .cpp file
	@$(CC) URLSorter.cpp -o URLSorter # compiled C++ program is URLSorter. @ will suppress the echo

run: all
	@./URLSorter # compiles the program and runs it program

test: all
	@./out_test | ./URLSorter # runs the program by providing it with the sample input from out_test file

clean:
	@rm -rf URLSorter # clears the output