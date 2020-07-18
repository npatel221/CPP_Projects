#include <iostream> // For User IO
#include <math.h> // For math operations
#include <vector> // For vector data type
#include <algorithm> // For sorting data

using namespace std;

class Website
{
   public:
      Website(int number_of_URL); // Constructor
      ~Website(){}; // Destructor

      //bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b);
      void addPage(string page); // Adds the page to the Vector
      vector<string> getMostVisitedPages() const; // Returns a vector of URLs in terms of popularity and sorted order
   
   private:
      // Implementing a vector with pair
      vector<pair <string, int>> dictionary;
      int num_URLs;

};

Website::Website(int number_of_URL)
{
   num_URLs = number_of_URL;
   cout << "# of URLs: " << num_URLs << endl;
}

bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
   if (a.second == b.second)
   {
      return (a.first < b.first);
   }
   else
   {
      return (a.second > b.second);
   }
}

void Website::addPage(string page)
{
   int size = dictionary.size();

   if (size == 0) // Add the first item
   {
      dictionary.push_back(make_pair(page,1));
   }
   else
   {
      bool found = false;
      for(int i = 0; i < size; i++)
      {
         if (dictionary[i].first == page)
         {
            found = true;
            dictionary[i].second++;
            break;
         }
      }
      if (found == false)
      {
         dictionary.push_back(make_pair(page,1));
      }
   }
   sort(dictionary.begin(), dictionary.end(), sortByVal);
}

vector<string> Website::getMostVisitedPages() const
{
   vector<string> return_list;
   for (int i = 0; i < dictionary.size(); i++)
   {
      return_list.push_back(dictionary[i].first);
      cout << "URL: " << dictionary[i].first << " count: " << dictionary[i].second << endl;
   }
   return return_list;
}

int main()
{
   // Get # of URL's from the User. N value
   int num_URLS;
   cin >> num_URLS;

   // Check if the input is within the limits as required
   if ((num_URLS < 1) or (num_URLS > pow(10,5)))
   {
      cout << "Input outside the limits\n";
      return 1; // Terminate execution with an error
   }

   // Create an instance
   Website myWebsiteinstance(num_URLS);

   // Get URL's and add it to our dictionary
   string temp; // Temp variable
   for (int i = 0; i < num_URLS; i++)
   {
      cin >> temp;
      myWebsiteinstance.addPage(temp);
   }

   vector<string> sorted_URLs = myWebsiteinstance.getMostVisitedPages();
   cout << "Size of return: " << sorted_URLs.size() << endl;
   for (int i = 0; i < sorted_URLs.size(); i++)
   {
      cout << sorted_URLs[i] << endl;
   }
   return 0;
}