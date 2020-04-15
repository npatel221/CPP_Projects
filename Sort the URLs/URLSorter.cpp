#include <iostream> // For User IO
#include <math.h> // For math
#include <vector>
#include <map>
#include <algorithm>

class Website
{
   std::vector<std::string> URL, unique_URL, sorted_URL;

   public:
      Website(); // Constructor
      std::vector<std::string> getMostVisitedPages(); // Returns an array of URLs in terms of popularity and sorted order
      int count_unique_url(); // Calculates the number of unique URL in the URL List
      std::vector<int> calculate_popularity();
      void addPage(std::string); // Adds items to the URL List
};

Website::Website()
{
}

bool sortByVal(const std::pair<std::string, int> &a, 
               const std::pair<std::string, int> &b) 
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

std::vector<std::string> Website::getMostVisitedPages() 
{
   std::vector<int> popularity_URL = this->calculate_popularity();
   // std::map<std::string, int> unique_URL_popularity; // Dictionary with Keys = URL, values = popularity count
   
   // // Loop through the unique URL list and add it to the dictionary along with keys
   // for(int i = 0; i < unique_URL.size(); i++)
   // {
   //    unique_URL_popularity.insert({unique_URL[i], popularity_URL[i]});
   // }

   // for (const auto &mypair: unique_URL_popularity)
   // {
   //    std::cout << mypair.first << " : " << mypair.second << '\n';
   // }

   // Implementing a vector with pair
   std::vector<std::pair <std::string, int>> dictionary;
   for(int i = 0; i < unique_URL.size(); i++)
   {
      dictionary.push_back(std::make_pair(unique_URL[i], popularity_URL[i]));
   }

   std::sort(dictionary.begin(), dictionary.end(), sortByVal);
   for(int i = 0; i < dictionary.size(); i++)
   {
      sorted_URL.push_back(dictionary[i].first);
   }
   return sorted_URL;
}

// This function will return the number of unique URL present.
// It will also create a vector of unique URL without duplicates.
int Website::count_unique_url()
{
   for (int i = 0; i < URL.size(); i++) // loop through the entire URL list
   {
      bool is_unique = true; // initialize it to true
      for (int x = 0; x < unique_URL.size(); x++) // loop through the entire unique URL List
      {
         if (URL[i] == unique_URL[x]) // if the item from the URL List is already in the unique URL list
         {
            is_unique = false; // set the flag to false as the value has been already added inside the unique URL list
            break; // exit the for loop to save iterations and execution time
         }
      }
      if(is_unique == true) // Unique URL add it to the Unique List
      {
         unique_URL.push_back(URL[i]); // append to the end of the unique URL List
      }
   }
   return unique_URL.size(); // M parameter, # of unique URLs present in the URL List
}

// This function will calculate the popularity of the URL
// It will return a int vector that will contain the count of the URL
std::vector<int> Website::calculate_popularity()
{
   std::vector<int> popularity(unique_URL.size());

   for (int i = 0; i < popularity.size(); i++)
   {
      int count = 0;
      for (int x = 0; x < URL.size(); x++)
      {  
         if(unique_URL[i] == URL[x])
         {
            count++;
         }
      }
      popularity[i] = count;
   }
   return popularity;
}

void Website::addPage(std::string value)
{
   URL.push_back(value); // Add value
}

int main()
{
   // Get # of URL's from the User. N value
   int num_URLS;
   std::cin >> num_URLS;
   if ((num_URLS < 1) or (num_URLS > pow(10,5)))
   {
      return 1; // Terminate execution with an error
   }

   Website my_website_instance; // Instantiate the class

   // Get URL's and add it to the array
   std::string temp; // Temp variable
   for (int i = 0; i < num_URLS; i++)
   {
      std::cin >> temp;
      my_website_instance.addPage(temp);
   }

   //std::cout << "# of Unique URLs: " << my_website_instance.count_unique_url() << "\n";
   my_website_instance.count_unique_url();
   std::vector<std::string> out_test = my_website_instance.getMostVisitedPages();
   for(int i = 0; i < out_test.size(); i++)
   {
      std::cout << out_test[i] << "\n";
   }

   return 0;
}