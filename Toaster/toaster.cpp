/*
This program implements a software controller for a bread & bagel toaster.
*/

// imports
#include <iostream>
#include <time.h>

// Namespace
using namespace std;

// Class definition
class Toaster
{
public:
    Toaster();  // constructor
    ~Toaster(); // destructor
    void setMode(string desiredMode);
    string getMode() const;
    void setIntensityLevel(unsigned short desiredIntLevel);
    unsigned short getIntensityLevel() const;
    void getFilamentStatus() const;
    bool run();

private:
    enum mode { BREAD, BAGEL } toasterMode; // declare enum type instantiate as toasterMode
    unsigned short intLevel; // intensity level from 1 to 10
    bool leftOutFilament, leftInFilament, rightInFilament, rightOutFilament; // outputs
    void setFilament(); // turn on appropriate filaments
    void resetFilament(); // turn off all filaments
    double secondsElapsed, secondsToDelay, starttime;

protected:
};

// Constructor
Toaster::Toaster()
{
    //cout << "Toaster object created" << endl;

    // default settings
    this->setIntensityLevel(1);
    this->setMode("BREAD");

    resetFilament();

    starttime = time(NULL); //Start timer
    cout << "Current Time: " << starttime << endl;
}

// Destructor
Toaster::~Toaster()
{
    resetFilament();
    cout << "Toaster object destroyed" << endl;
}

// Set toaster mode to BAGEL
void Toaster::setMode(string desiredMode)
{
    if (desiredMode == "BREAD")
    {
        toasterMode = BREAD;
    }
    else if (desiredMode == "BAGEL")
    {
        toasterMode = BAGEL;
    }
    else // error
    {
        cout << "Error: acceptable modes are BREAD and BAGEL" << endl;
        exit(EXIT_FAILURE); // terminate execution
    }
}

// This function returns the current Toast mode
string Toaster::getMode() const
{
    if (toasterMode == BREAD)
    {
        return "Bread";
    }
    else if (toasterMode == BAGEL)
    {
        return "Bagel";
    }
    else
    {
        return "Notset";
    }
}

// This function will update the Toast intensity level
// to the user selected value between 1 - 10 exclusive
void Toaster::setIntensityLevel(unsigned short desiredIntLevel)
{
    // only update when its between 1 - 10
    if (desiredIntLevel >= 1 && desiredIntLevel <= 10)
    {
        intLevel = desiredIntLevel;
        secondsToDelay = intLevel * 10; // simulate toast operation from 10 - 100 seconds
    }
    else // error
    {
        cout << "Error: intensity level not between 1-10!" << endl;
        exit(EXIT_FAILURE); // terminate execution
    }
}

// This function returns the current intensity level of the toaster
unsigned short Toaster::getIntensityLevel() const
{
    return intLevel;
}

void Toaster::setFilament()
{
    if (toasterMode == BREAD) // heat all 4 filaments
    {
        leftOutFilament = true;
        leftInFilament = true;
        rightInFilament = true;
        rightOutFilament = true;
    }
    else if (toasterMode == BAGEL) // heat only the inner filaments
    {
        leftOutFilament = false;
        leftInFilament = true;
        rightInFilament = true;
        rightOutFilament = false;
    }
    else
    {
        resetFilament();
    }
}

void Toaster::resetFilament()
{
    leftOutFilament = false;
    leftInFilament = false;
    rightInFilament = false;
    rightOutFilament = false;
}

void Toaster::getFilamentStatus() const
{
    printf("Left Out: %s | Left In: %s | Right In: %s | Right Out: %s\n",
           leftOutFilament ? "true" : "false", leftInFilament ? "true" : "false",
           rightInFilament ? "true" : "false", rightOutFilament ? "true" : "false");
}

bool Toaster::run()
{
    //secondsElapsed = double(clock() - timer) / CLOCKS_PER_SEC; // calculate time elapsed
    secondsElapsed = (time(NULL) - starttime);
    cout << "Seconds Elapsed: " << secondsElapsed << endl;
    if (secondsElapsed >= secondsToDelay) // time passed toast done
    {
        resetFilament();
        return true;
    }
    else
    {
        setFilament();
        return false;
    }
}

int main()
{
    cout << "Welcome to Toaster Program!" << endl;
    
    string modeSelection;
    unsigned short levelSelection;

    cout << "\nMode of Operation (BREAD or BAGEL): ";
    cin >> modeSelection;

    cout << "\nIntensity Level (1 - 10): ";
    cin >> levelSelection;

    Toaster myToasterInst;

    myToasterInst.setMode(modeSelection);
    myToasterInst.setIntensityLevel(levelSelection);
    //cout << myToasterInst.getMode() << endl;
    //myToasterInst.setIntensityLevel(11);
    //myToasterInst.getFilamentStatus();

    while (!myToasterInst.run())
    {
        myToasterInst.getFilamentStatus();
    }
    return 0;
}