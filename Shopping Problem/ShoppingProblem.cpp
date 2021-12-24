#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SortFunction(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return true;
    }

    if (a.first > b.first)
    {
        return false;
    }

    if (a.first == b.first)
    {
        if (a.second < b.second)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    int nItems = 0;
    long long mCoins = 0;

    scanf("%d %lld", &nItems, &mCoins);

    vector<int> nPrice(nItems, 0);
    vector<int> nId(nItems, 0);

    for (int i = 0; i < nItems; i++)
    {
        scanf("%d %d", &nPrice[i], &nId[i]);
    }

    bool isThereAnyItemThatCanBeBought = false;

    vector<pair<int, int>> table;

    for (int i = 0; i < nItems; i++)
    {
        if (nPrice[i] <= mCoins) // can afford
        {
            table.push_back(make_pair(nPrice[i], nId[i]));
            isThereAnyItemThatCanBeBought = true;
        }
    }

    if (isThereAnyItemThatCanBeBought == true)
    {
        sort(table.begin(), table.end(), SortFunction);

        vector<int> shoppingListId;

        for (int i = 0; i < table.size(); i++)
        {
            if (table[i].first <= mCoins)
            {
                shoppingListId.push_back(table[i].second); // add Id to the shopping list
                mCoins = mCoins - table[i].first;
            }

            else
            {
                break; // not enough coins to buy any item
            }
        }

        sort(shoppingListId.begin(), shoppingListId.end()); // sort by increasing ID
        for (int id : shoppingListId)
        {
            cout << id << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}