# Code Question 1
Amazon's Alexa team is working on optimizing the customer experience for scenarios where customers ask generic questions. One example of a generic question is "What are good vegetarian restaurants nearby?" In this eample, Alex would then search for a list of vegetarian restaurants in the city and select the nearest X vegetarian restaurants relatie to the customer's location. Given an array representing the locations of N vegetarian restaurants in the city, implement an algorithm to find the nearest X vegetarian restaurants to the customer's location.

### Input
The input to the function/method consists of two arguements:</br>
<em>allLocations</em>: a list of elements where each element consists of a pair of integers representing the x and y coordinates of the vegetarian restaurant in the city.</br>
<em>numRestaurants</em>: an integer representing the number of nearby vegetarian restaurants that would be erturned to the customer (X).</br>

### Output
Return a list of elements where each element of the list represents the x and y integer coordinates of the nearest recommended vegetarian restaurant relative to the customer's location. If there is a tie, return any of the locations as long as you satisfy returning exactly X nearby vegetarian restaurants. If no location is possible, return a list with an empty location - not just an empty list.

### Constraints
<em>numRestaurants</em> &le; size(<em>allLocations</em>)

### Note
The customer begins at the location [0,0]</br>
The distance from the customer's current location to a recommended vegetarian restaurant location (x,y) is the square root of x<sup>2</sup> + y<sup>2</sup>.</br>
If there are ties then return any of the locations as long as you satisfy returning exactly X nearby vegetarian restaurants.</br>
The returned output can be in any order.</br>

### Example
Input:
allLocations = [[1,2],[3,4],[1,-1]]
numRestaurants = 2

Output:
[[1,-1],[1,2]]