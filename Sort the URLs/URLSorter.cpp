#include <iostream> // For User IO
#include <math.h> // For math operations
#include <vector> // For vector data type

using namespace std;

class Website
{
   public:
      Website(); // Constructor
      ~Website(){}; // Destructor
      void addPage(string page); // Adds the page to the Vector
      vector<string> getMostVisitedPages() const; // Returns a vector of URLs in terms of popularity and sorted order
   
   private:
      // Implementing a vector with pair
      vector<pair <string, int>> dictionary;

};

Website::Website()
{
   cout << "Website Constructor called\n";
}

void Website::addPage(string page)
{

}

vector<string> Website::getMostVisitedPages() const
{

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
   Website myWebsiteinstance;

   return 0;
}