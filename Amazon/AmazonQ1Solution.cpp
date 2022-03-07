#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// This function will print a 2D vector containing X and Y location of restaurants
template <typename T>
void Print2DVector(const vector<T>& vecToPrint)
{
    for (auto iter = vecToPrint.cbegin(); iter != vecToPrint.cend(); iter++)
    {
        cout << "[" << (*iter)[0] << ", " << (*iter)[1] << "]" << endl;
    }
    return;
}

// this function finds the closest restaurants from the customer location
vector<vector<int>> findRestaurants(vector<vector<int>> allLocations, int numRestaurants)
{
    vector <vector<int>> finalResult; // {{x1,y1},{x2,y2}} closest restaurants
    
    multimap <double, vector<int>> mmapSortedByClosestDistance;
    
    const vector<double> customerLocation = {0.0, 0.0}; // customer location set to 0,0
    
    // Calculate distance and add it to multimap collection
    for (auto iter = allLocations.cbegin(); iter != allLocations.cend(); iter++)
    {
        // Calculate eucledian distance in 2D space
        int x = (*iter)[0]; // get x
        int y = (*iter)[1]; // get y
        double distance = sqrt(pow((x - customerLocation[0]),2) + pow((y - customerLocation[1]),2));
       
        mmapSortedByClosestDistance.insert(make_pair(distance, (*iter))); // add to a multimap sorted by distance
    }
    
    // populate finalResult vector based on user requested # of restaurants
    for (auto iter = mmapSortedByClosestDistance.cbegin(); iter != mmapSortedByClosestDistance.cend(); iter++)
    {
        if (finalResult.size() < numRestaurants)
        {
            finalResult.push_back((*iter).second); // add x and y to the return vector
        }
        else
        {
            break;
        }
    }
    return finalResult;
}

int main()
{
    // Test Case # 1
    vector<vector<int>> allLocations  = {{1,2}, {3,4}, {1,-1}};
    int numRestaurants = 2;
    // Expected Output [[1,-1],[1,2]]
    
    vector<vector<int>> results = findRestaurants(allLocations, numRestaurants);
    Print2DVector(results);
    return 0;
}