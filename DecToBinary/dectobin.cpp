#include <iostream>
#include <math.h> // for computing ln

using namespace std;

int convert(unsigned short myint)
{
    int power = floor(log(myint) / log(2));
    if (pow(2,power) == myint)
    {
        return 1;
    }
    else
    {
        int oneCount = 0;
        for (int i = power; i >= 0; i--)
        {
            // calculate the index first
            int binIncrement = pow(2,i);
            if (myint >= binIncrement)
            {
                myint = myint - binIncrement;
                oneCount++;
            }
        }
        return oneCount;
    }
}

unsigned int binToDec(const string binaryNum)
{
    unsigned int decimal, exponent;
    int stringSize = binaryNum.size();

    // iterate through the string
    for (int i = 0; i < stringSize; i++)
    {
        if (binaryNum[i] == '1') // calculate the 2^exponent and add to decimal value
        {
            decimal += pow(2,(stringSize - (i+1)));
        }
        else if (binaryNum[i] == '0') // do nothing
        {
            continue;
        }
        else // invalid character
        {
            cout << "Invalid binary string" << endl;
            exit(1);
        }
    }
    return decimal;
}

int main()
{
    // Get how many 1's in a decimal number
    cout << "---COUNT HOW MANY 1's IN A DECIMAL NUM\n";
    cout << "Decimal: " << 9 << "\t 1's Count: ";
    cout << convert(9) << endl;

    // Binary to Decimal demo
    cout << "---BINARY TO DECIMAL CONVERTER---\n";
    string binarynum = "011";
    cout << "Binary: " << binarynum << "\tDecimal: ";
    cout << binToDec(binarynum) << endl;
    return 0;
}