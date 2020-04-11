#include <iostream> // For User IO
#include <math.h> // For math
#include <vector>

class Website
{
   std::vector<std::string> URL, unique_URL;
   public:
      Website(); // Constructor
      void getMostVisitedPages(); // Returns an array of URLs in terms of popularity and sorted order
      int count_unique_url(); // Calculates the number of unique URL in the URL List
      void addPage(std::string); // Adds items to the URL List
};

Website::Website()
{

}

void Website::getMostVisitedPages() 
{
   
}

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


   // std::string* output = my_website_instance.getMostVisitedPages();
   // for (int i = 0; i < num_URLS; i++)
   // {
   //    std::cout << output[i] << "\n";
   // }
   std::cout << my_website_instance.count_unique_url();

   return 0;
}