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
1. [Purpose](#Purpose)
2. [Extracted Requirements](#Extracted_Requirements)
3. [Run Instructions](#Run_Instructions)
4. [Program Demo](#Program_Demo)
5. [Code](#Code)

### Purpose <a name="Purpose"></a>

Develop a program that displays the most popular URLs on the basis of a survey which was recently conducted for `N` users. For every user, you are given one URL, which they have already visited. The popularity of a URL, is directly proportional to the number of visits to that URL. The program must sort the URLs in decreasing order of popularity.

**Input Format**</br>

- First Line: `N`</br>

- Next `N` lines: String `S` (where the <code>i<sup>th</sup></code> line corresponds to the URL that is visited by the <code>i<sup>th</sup></code> user)</br>

**Output Format**</br>

Print an integer `M` denoting the number of unique URLs accessed by the users and the URLs in decreasing order of popularity in the next `M` lines. If the number of visits of any two URLs is the same, then display them in increasing lexicographical order.</br>

**Constraints**</br>
1 <= N <= 10<sup>5</sup></br>
1 <= |S| <= 100

**Description of classes**</br>

1. Website class </br>
Design a `Website` class that contains an attribute URL of type String. This data stores the URL of the website. The website class must contain a class method named as `getMostVisitedPages` that returns a list containing the most visited URLs in the order as described in the question.</br>
You can use extra attributes or methods in the `Website` class.</br>

2. Main class </br>
This class will be provided to you and it is responsible for taking inputs from the user.</br>

**Expected Output**</br>

|         Sample Input           |        Sample Output           |
|:---------------------------:   |:---------------------------:   |
|              5                 |              3                 |
| https://www.hackerearth.com    | https://www.hackerearth.com    |
|  https://www.wikipedia.org     |    https://www.google.com      |
|    https://www.google.com      |  https://www.wikipedia.org     |
| https://www.hackerearth.com    |                                |
| https://www.hackerearth.com    |                                |


### Extracted Requirements <a name="Extracted_Requirements"></a>

### Run Instructions <a name="Run_Instructions"></a>

### Program Demo <a name="Program_Demo"></a>

### Code <a name="Code"></a>
```cpp

```