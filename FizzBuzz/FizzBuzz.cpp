#include <iostream>

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
	std::cout << "Hello World\n";
	return 0;
}