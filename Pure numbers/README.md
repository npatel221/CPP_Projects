# Pure numbers

Folder Structure
```

```

### Table of Contents
1. [Purpose](#Purpose)</br>
   1.1. [Input Format](#Input_Format)</br>
   1.2. [Output Format](#Output_Format)</br>
   1.3. [Constraints](#Constraints)</br>
   1.4. [Expected Output](#Expected_Output)</br>
   1.5. [Explanation](#Explanation)</br>
2. [Extracted Requirements](#Extracted_Requirements)
3. [Run Instructions](#Run_Instructions)
4. [Program Demo](#Program_Demo)
5. [Code](#Code)

### Purpose <a name="Purpose"></a>

Develop a program that finds the **<em>N<sup>th</sup></em>** pure number, where **<em>N</em>** is an integer provided by the user. A pure number must satisfy the following properties:

1. It comprises of only **4** and **5**.
2. It is a **palindrome** number.
3. The number of digits in a pure number is **even**.

For example, 4444, 5445, 44 are pure numbers while 12, 444, 4545 are not. Pure numbers are to be generated in an ascending order. So, purenumber[1] < purenumber[2].

The first few elements in the list are as follows: 44, 55, 4444, ....

**Input Format** <a name="Input_Format"></a>

- First line: **<em>T</em>** denoting the number of test cases
- Next **<em>T</em>** lines: A number **<em>N</em>**

**Output Format** <a name="Output_Format"></a>

- Print the **<em>N<sup>th</sup></em>** pure number.

**Constraints** <a name="Constraints"></a>

1 &le; **<em>T</em>** &le; 10<sup>6</sup></br>
1 &le; **<em>N</em>** &le; 10<sup>6</sup>

**Expected Output** <a name="Expected_Output"></a>

**Explanation** <a name="Explanation"></a>

### Extracted Requirements <a name="Extracted_Requirements"></a>

### Run Instructions <a name="Run_Instructions"></a>

Use the provided `Makefile` and `make` command to automatically compile the C++ code on your linux machine. After the compile is successful you can run the program using `./Purenumbers` command in your native terminal. Below is a description of all the supported make commands by the provided makefile.

`make all`: compiles the C++ file into an executable file, `Purenumbers`

`make run`: compiles the C++ file into an executable file, `Purenumbers` and starts the `Purenumbers` program

`make test`: compiles the C++ file into an executable file, `Purenumbers` and provides the `Purenumbers` with sample input from the bash script `out_test`

`make clean`: removes all of the compiled files, `Purenumbers`. Keeps the source code intact.

### Program Demo <a name="Program_Demo"></a>
<p align="center">
  <img src="images/Purenumbers_Demo.gif"/>
</p>

### Code <a name="Code"></a>
```cpp
#include <iostream> // for User IO
#include <math.h> // for math operations
#include <algorithm> // for reverse string algorithm

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

    // Divide the string into 2 seperate string at middle
    string first_half = temp.substr(0,temp.size()/2); // extract first half = [0, size()/2)
    string second_half = temp.substr(temp.size()/2, temp.size()); // extract second half = [size()/2, size())
    
    reverse(second_half.begin(), second_half.end()); // reverse the second half
    return (first_half == second_half); // check if the first half equals the reverse second half of the string
}

// This function calculates and returns the Nth pure number
int getNPurenum(int nValue)
{
    string pureNumString = "";
    // Calculate Right half of Nth pure num algorithm
    while(nValue > 0)
    {
        nValue--;
        if(nValue%2 == 0) // even append 4
        {
            pureNumString.append("4"); // Add 4
        }
        else // odd append 5
        {
            pureNumString.append("5"); // Add 5
        }
        nValue = floor(nValue/2); // divide by 2 then round down using floor function        
    }

    // Generate palindrome string for the left half side
    string second_half = pureNumString; // save a copy
    reverse(pureNumString.begin(), pureNumString.end()); // flip to get left side
    pureNumString.append(second_half); // merge left + right side

    return stoi(pureNumString); // convert string to int then return it
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

    int pureNumArray[numTestCases]; // int array to hold all Nth pure numbers

    // Get N number whose pure number is to be calculated
    for (int i = 0; i < numTestCases; i++)
    {
        // Get N from the user and store it in temp
        int temp;
        cin >> temp;

        // Check if the input is within the limits as required
        if ((temp < 1) or (temp > pow(10, 6)))
        {
            return 1; // Terminate execution with an error
        }

        pureNumArray[i] = getNPurenum(temp); // Calculate Nth pure num and add it to array

        // Test for 3 conditions to validate its a pure number
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
```