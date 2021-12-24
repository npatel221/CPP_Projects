#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void Solution(vector<string> &stringList, vector< tuple<int, int, int> > &questionList)
{
	for (int i = 0; i < questionList.size(); i++)
    {
    	// get L R K from the question list
        int L = get<0>(questionList[i]);
        int R = get<1>(questionList[i]);
        int K = get<2>(questionList[i]);

        string output = "";
        if (L == R) // start and finish are same
        {
            output = stringList[L-1];
        }
        else
        {
            for (int i = L-1; i < R; i++) // concat strings
            {
                output += stringList[i];
            }
        }
        sort(output.begin(), output.end()); // ascending alphabetical order
        cout << output[K-1] << endl; // get Kth character
    }
    return;
}

int main()
{
	// Get Num Strings Input from User
	int nNumStrings = 0;
	scanf("%d", &nNumStrings);	

	// Get String String from User based on N
	vector<string> stringList(nNumStrings, "");
	for (int i = 0; i < nNumStrings; i++)
	{
		cin >> stringList[i];
	}

	// Get Num Questions Input from User
	int qNumQuestions = 0;
	scanf("%i", &qNumQuestions);

	// Get Question List from User based on # of q's
	vector< tuple<int, int, int> > questionList(qNumQuestions);
	for (int i = 0; i < qNumQuestions; i++)
	{
        int L, R, K = 0;
		scanf("%i %i %i", &L, &R, &K); // extract L R K from user input
        questionList[i] = make_tuple(L, R, K); // add to the vector
	}

	Solution(stringList, questionList); // get answers
	return 0;
}