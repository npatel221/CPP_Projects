#include <iostream> // for User IO
#include <math.h> // for math operations
#include <algorithm>

using namespace std;

// This function checks if the number of digits are even or odd. 
// If even return true, odd return false
bool isEven(int num)
{
    string temp = to_string(num); // convert num to string
    return ((temp.size()%2) == 0); // check size divisible by 2 to see if even/odd
}

// This function checks if the input num only consists of digits 4 and 5
// Return TRUE: if only 4 and 5 present, FALSE: otherwise
bool checkDigits(int num)
{
    string temp = to_string(num); // convert num to string
    for (int i = 0; i < temp.size(); i++) // loop through the string character by character
    {
        if ((temp[i] != '4') && (temp[i] != '5')) // check for 4 and 5 presence
        {
            return false;
        }
    }
    return true; // only 4 and 5 are present
}

// This function checks if the input num is a palindrome string or not
// Return TRUE: is palindrome, FALSE: not palindrome
bool isPalindrome(int num)
{
    string temp = to_string(num); // convert num to string
    string first_half = temp.substr(0,temp.size()/2); // extract first half
    string second_half = temp.substr(temp.size()/2, temp.size()); // extract second half
    
    reverse(second_half.begin(), second_half.end()); // reverse the second half
    return (first_half == second_half); // check if the first half equals the reverse second half of the string
}

int main()
{
    // Get # of test cases from the User. T value
    int numTestCases;
    cin >> numTestCases;

    // Check if the input is within the limits as required
    if ((numTestCases < 1) or (numTestCases > pow(10, 6)))
    {
        return 1; // Terminate execution with an error
    }

    cout << isPalindrome(4554) << endl;
    return 0;
}