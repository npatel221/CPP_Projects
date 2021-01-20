#include <iostream>
#include <math.h> // for computing ln

using namespace std;

int convert(unsigned short myint)
{
    //cout << "Hello World\n";
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


int main()
{
    cout << "Return: " << convert(9) << endl;
    return 0;
}
