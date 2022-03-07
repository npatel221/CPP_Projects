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
Input:</br>
allLocations = [[1,2],[3,4],[1,-1]]
numRestaurants = 2

Output:</br>
[[1,-1],[1,2]]

# Code Question 2

Your team at Amazon is working on a system that divides applications to a mixed cluster of computing devices. Each application is identified by an integer ID, requires a fixed non-zero amount of memory to execute , and is defined to be either a foreground or background application. IDs are guaranteed to be unique within their own application type, but not across types.

Each device should be assigned two applications at once, one foreground application and one background application. Devices have limited amounts of memory and cannot execute applications that require more memory than the available memory. THe goal of the system is to maximize the total utilization of the memory of a given device. A foreground/background application pair is considered to be optimal if there does not exist another pair that uses more memory than this pair, and also has a total less then or equal to the total memory of the device. For example, if the device has 10MB memory, a foreground/background pair using a sum total of 9MB memory would be optimal if there does not exist a pair that uses a sum total of 10 MB, but would not be optimal if such a pair did exist.

Write an algorithm to find the sets of foreground and background application pairs that optimally utilize the given device for a given list of foreground applications and a given list of background applications.

### Input
The input to the function/method consists of three arguments:
<em>deviceCapacity</em>: an integer representing the maximum capacity of the given device</br>
<em>foregroundAppList</em>: a list of pairs of integers where the first integer represents the unique ID of a foreground application and the second integer represents the amount of memory required by this application</br>
<em>backgroundAppList</em>: a list of pairs of integers where the first integer represents the unique ID of a background application and the second integer represents the amount of memory required by this application.

### Output
Return a list of pairs of integers representing the pairs of IDs of foreground and background applications that optimally utilize the given device [foregroundAppID, backgroundAppID]. If no pair is possible, return a list with empty pair - not just an empty list.

### Examples
##### Example 1
Input:</br>
deviceCapacity = 7</br>
foregroundAppList = [[1,2],[2,4],[3,6]]</br>
backgroundAppList = [[1,2]]</br>

Output:</br>
[[2,1]]</br>
##### Example 2
Input:</br>
deviceCapacity = 10</br>
foregroundAppList = [[1,3],[2,5],[3,7],[4,10]]</br>
backgroundAppList = [[1,2],[2,3],[3,4],[4,5]]</br>

Output:</br>
[[2,4],[3,2]]</br>
##### Example 3
Input:</br>
deviceCapacity = 16</br>
foregroundAppList = [[2,7],[3,14]]</br>
backgroundAppList = [[2,10],[3,14]]</br>

Output:</br>
[()]</br>