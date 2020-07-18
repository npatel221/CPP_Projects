# Sort the URLs

Folder Structure
```
Sort the URLs
|  Makefile (helpful file for compiling the C++ program)
|  README.md (contains information about the program)
|  URLSorter.cpp (C++ source code file)
|  out_test (bash script file for automatic input testing)
|  .gif (output from the program)
```

### Table of Contents
1. [Purpose](#Purpose)</br>
   1.1. [Input Format](#Input_Format)</br>
   1.2. [Output Format](#Output_Format)</br>
   1.3. [Constraints](#Constraints)</br>
   1.4. [Description of classes](#Description_of_classes)</br>
   1.5. [Expected Output](#Expected_Output)</br>
   1.6. [Explanation](#Explanation)</br>
2. [Extracted Requirements](#Extracted_Requirements)
3. [Run Instructions](#Run_Instructions)
4. [Program Demo](#Program_Demo)
5. [Code](#Code)

### Purpose <a name="Purpose"></a>

Develop a program that displays the most popular URLs on the basis of a survey which was recently conducted for `N` users. For every user, you are given one URL, which they have already visited. The popularity of a URL, is directly proportional to the number of visits to that URL. The program must sort the URLs in decreasing order of popularity.

**Input Format** <a name="Input_Format"></a>

- First Line: `N`</br>

- Next `N` lines: String `S` (where the <code>i<sup>th</sup></code> line corresponds to the URL that is visited by the <code>i<sup>th</sup></code> user)</br>

**Output Format** <a name="Output_Format"></a>

Print an integer `M` denoting the number of unique URLs accessed by the users and the URLs in decreasing order of popularity in the next `M` lines. If the number of visits of any two URLs is the same, then display them in increasing lexicographical order.</br>

**Constraints** <a name="Constraints"></a>

1 <= N <= 10<sup>5</sup></br>
1 <= |S| <= 100

**Description of classes** <a name="Description_of_classes"></a>

1. Website class </br>
Design a `Website` class that contains an attribute URL of type String. This data stores the URL of the website. The website class must contain a class method named as `getMostVisitedPages` that returns a list containing the most visited URLs in the order as described in the question.</br>
You can use extra attributes or methods in the `Website` class.</br>

2. Main class </br>
This class will be provided to you and it is responsible for taking inputs from the user.</br>

**Expected Output** <a name="Expected_Output"></a>

|         Sample Input           |        Sample Output           |
|:---------------------------:   |:---------------------------:   |
|              5                 |              3                 |
| https://www.hackerearth.com    | https://www.hackerearth.com    |
|  https://www.wikipedia.org     |    https://www.google.com      |
|    https://www.google.com      |  https://www.wikipedia.org     |
| https://www.hackerearth.com    |                                |
| https://www.hackerearth.com    |                                |

**Explanation** <a name="Explanation"></a>

Number of unique url's are 3: https://www.wikipedia.org, https://www.google.com, https://www.hackerearth.com</br>

https://www.hackerearth.com is visited 3 times so it is displayed first, now the number of visits of both the websites https://www.google.com and https://www.wikipedia.org is same, the program needs to display according to the lexiographical order so www.google.com is displayed before www.wikipedia.org.</br>

### Extracted Requirements <a name="Extracted_Requirements"></a>

### Run Instructions <a name="Run_Instructions"></a>

### Program Demo <a name="Program_Demo"></a>

### Code <a name="Code"></a>
```cpp

```