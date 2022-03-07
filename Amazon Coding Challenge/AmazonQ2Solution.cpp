#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// this function will print out contents of a 2D vector list for verification
template <typename T>
void Print2DVector(const vector<T>& vecToPrint)
{
    if (vecToPrint.empty())
    {
        cout << "[()]" << endl;
    }
    else
    {
        // print out each element
        for (auto iter = vecToPrint.cbegin(); iter != vecToPrint.cend(); iter++)
        {
            cout << "[" << (*iter)[0] << "," << (*iter)[1] << "]" << endl;
        }
    }
    return;
}

// remove apps where memory required is higher then capacity, thus unsupported
void RemoveAllAppsThatCantBeSupported (int& capacity, vector<vector<int>>& appList)
{
    for (auto iter = appList.cbegin(); iter != appList.cend(); iter++)
    {
        if ((*iter)[1] > capacity) // higher then capacity
        {
            appList.erase(iter); // remove the element
            iter--; // move back iterator
        }
    }
    appList.shrink_to_fit(); // shrink vector size to optimize memory
    return;
}

// predicate to sort by increasing memory consumption. lhs / rhs = {id, consumption}
bool SortByIncMemoryConsumption(vector<int>& lhs, vector<int>& rhs)
{
    return (lhs[1] < rhs[1]);
}

// this function will find the optimal pair of apps with max memory utilization
vector<vector<int>> applicationPairs(int deviceCapacity, vector<vector<int>> foregroundAppList, vector<vector<int>> backgroundAppList)
{
    // deviceCapacity = amount of memory available in MB
    // foregroundAppList / backgroundAppList = [[id, memory consumption], [id, memory consumption]]
    vector<vector<int>> optimalPair; // [[consumption, forAppId, backAppId]]

    RemoveAllAppsThatCantBeSupported(deviceCapacity, foregroundAppList);
    RemoveAllAppsThatCantBeSupported(deviceCapacity, backgroundAppList);

    // sort app list with increasing memory consumption so the algorithm can do early stoppage
    sort(foregroundAppList.begin(), foregroundAppList.end(), SortByIncMemoryConsumption);
    sort(backgroundAppList.begin(), backgroundAppList.end(), SortByIncMemoryConsumption);

    for (auto fIter = foregroundAppList.cbegin(); fIter != foregroundAppList.cend(); fIter++)
    {
        for (auto bIter = backgroundAppList.cbegin(); bIter != backgroundAppList.cend(); bIter++)
        {
            int forConsumption = (*fIter)[1];
            int backConsumption = (*bIter)[1];
            int consumption = forConsumption + backConsumption;

            if (consumption <= deviceCapacity) // app can run
            {
                // assign to vector when its empty or consumption is better (higher)
                if ((optimalPair.empty()) || (consumption > optimalPair[0][0]))
                {
                    optimalPair = {{consumption, (*fIter)[0], (*bIter)[0]}}; // assign
                }
                else if (consumption == optimalPair[0][0]) // append to vector if consumption is same if not better
                {
                    optimalPair.push_back({consumption, (*fIter)[0], (*bIter)[0]}); // append
                }
            }
            else // app can't run
            {
            	break;
            }
        }
    }
    
    if (optimalPair.size() == 0) // empty and no optimal pair exists
    {
        optimalPair = {{}};
    }
    else
    {
        // drop the consumption
        for (auto iter = optimalPair.begin(); iter != optimalPair.end(); iter++)
        {
            (*iter).erase((*iter).begin()); // remove consumption field from sub vector
            (*iter).shrink_to_fit(); // reduce capacity
        }
    }

    return optimalPair;
}

int main()
{
    // Test Case # 1
    // int deviceCap = 7;
    // vector<vector<int>> foreAppList = {{1,2}, {2,4}, {3,6}};
    // vector<vector<int>> backAppList = {{1,2}};
    // Expected Output [[2,1]]

    // Test Case # 2
    int deviceCap = 10;
    vector<vector<int>> foreAppList = {{1,3}, {2,5}, {3,7}, {4,10}};
    vector<vector<int>> backAppList = {{1,2}, {2,3}, {3,4}, {4,5}};
    // Expected Output [[2,4],[3,2]]

    // Test Case # 3
    // int deviceCap = 16;
    // vector<vector<int>> foreAppList = {{2,7},{3,14}};
    // vector<vector<int>> backAppList = {{2,10},{3,14}};
    // Expected Output [()]

    vector<vector<int>> results = applicationPairs(deviceCap, foreAppList, backAppList);
    Print2DVector(results);
    return 0;
}
