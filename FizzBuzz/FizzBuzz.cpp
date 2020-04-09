#include <iostream> // For Input Output with user

// This function returns a String after checking whether the provided integer is a Fizz, Buzz, both or none
std::string check_fizz_buzz(int num)
{
   std::string return_var = ""; // Return var declaration

   bool is_fizz = (num % 3) == 0; // Is the provided number a Fizz
   bool is_buzz = (num % 5) == 0; // Is the provided number a Buzz

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
   int T; // Declare the number of testcases as T

   std::cin >> T; // Get the value of T from the user

   // Check if the value of T is outside the range of 1 <= T <= 10, if outside exit the program with error code.
   if ((T < 1) || (T > 10))
   {
      return 1; // Exit the program and halt execution with error code
   }

   int num[T]; // Declare array of type int to hold integers

   // Add integers to the array from the user input
   for (int i = 0; i < T; i++)
   {
      std::cin >> num[i]; // add elements to the array
   }

   // Loop through and find the Fizz Buzz as required
   for (int i = 0; i < T; i++) // loop through all array elements in the Int Array
   {
      for (int start_num = 1; start_num <= num[i]; start_num++) // get a range upto and including array item
      {
         std::cout << check_fizz_buzz(start_num) << "\n"; // Prints the respective output after checking Fizz Buzz requirement   
      }
   }
   return 0; // Terminate Program after successful execution
}