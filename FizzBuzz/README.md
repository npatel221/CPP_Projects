# FizzBuzz

### Purpose

### RUn Instructions

### Code
```cpp
#include <iostream> // For Input Output with user
#include <sstream>

// This function returns a String after checking whether the provided integer is a Fizz, Buzz, both or none
std::string check_fizz_buzz(int num)
{
	std::string return_var = ""; // Return var declaration

	bool is_fizz = (num%3) == 0; // Is the provided number a Fizz
	bool is_buzz = (num%5) == 0; // Is the provided number a Buzz

	if(is_fizz && is_buzz) // Num is a fizz and a buzz
	{
		return_var = "FizzBuzz";
	}
	else if(is_fizz) // Num is a fizz
	{
		return_var = "Fizz";
	}
	else if(is_buzz) // Num is a buzz
	{
		return_var = "Buzz";
	}
	else // Num is neither
	{
		return_var = std::to_string(num); // Convert int to string and return String that contains the num
	}

	return return_var; // Return the value
}

int main()
{
	std::string T_num, N_numbers; // Declar strings which will be inputted by the user

	// Using getline over standard cout because we need the entire line as a string
	std::getline(std::cin, T_num); // Get the number T
	std::getline(std::cin, N_numbers); // Get the T numbers of int number (N)

	int T = std::stoi(T_num); // Convert to int datatype

	int int_array [T]; // Create a int array of size T which will hold N_numbers

	// Extract Integers from the String
	std::istringstream iss (N_numbers); // Extract to int array from string
	for (int i=0; i<T; i++) // Perform extraction by looping through the entire array
	{
		int val; // temp variable
		iss >> val; // assign it to var
		int_array[i] = val; // append it to the int array
	}

	// Loop through and find the Fizz Buzz as required
	for (int i = 0; i < T; i++) // loop through all array elements in the Int Array
	{
		for (int start_num = 1; start_num <= int_array[i]; start_num++) // get a range upto and including array item
		{
			std::cout << check_fizz_buzz(start_num) << "\n"; // Prints the respective output after checking Fizz Buzz requirement	
		}
	}

	return 0; // Terminate Program after successful execution
}
```