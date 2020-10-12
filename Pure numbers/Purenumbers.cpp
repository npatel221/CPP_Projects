#include <iostream> // for User IO
#include <math.h> // for math operations
#include <algorithm>
#include <typeinfo>

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

int getNPurenum(int nValue)
{
    string pureNumString = "";
    while(nValue > 0)
    {
        nValue--;
        if(nValue%2 == 0)
        {
            pureNumString.append("4"); // Add 4
        }
        else
        {
            pureNumString.append("5"); // Add 5
        }
        nValue = nValue/2;        
    }
    string second_half = pureNumString; // Return
    reverse(pureNumString.begin(), pureNumString.end());
    pureNumString.append(second_half);
    return stoi(pureNumString);
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

    int pureNumArray[numTestCases];
    for (int i = 0; i < numTestCases; i++)
    {
        int temp;
        cin >> temp;
        // Check if the input is within the limits as required
        if ((temp < 1) or (temp > pow(10, 6)))
        {
            return 1; // Terminate execution with an error
        }

        pureNumArray[i] = getNPurenum(temp);

        // Test for conditions
        if (isEven(pureNumArray[i]) && checkDigits(pureNumArray[i]) && isPalindrome(pureNumArray[i]))
        {
            continue;
        }
        else
        {
            return 1; // Terminate execution with error
        }
    }

    // Print Nth pure number from the array
    for (int i = 0; i < numTestCases; i++)
    {
        cout << pureNumArray[i] << endl;
    }
    return 0;
}