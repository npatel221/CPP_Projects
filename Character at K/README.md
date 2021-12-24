# Character at K

## Problem
You are given a list that contains <b><em>N</em></b> strings of lowercase English alphabets. Any number of contiguous strings can be grouped together to form a new string. The grouping function accepts two integers <b><em>X</em></b> and <b><em>Y</em></b> and concatenates all strings between indices <b><em>X</em></b> and <b><em>Y</em></b> (inclusive) and returns a modified string in which the alphabets of the concatenated string are sorted.

You are asked <b><em>Q</em></b> questions each containing two integers <b><em>L</em></b> and <b><em>R</em></b>. Determine the <b><em>K<sup>th</sup></em></b> character in the concatenated string if we pass <b><em>L</em></b> and <b><em>R</em></b> to the grouping function.

</br>

### Input Format
- First line: <b><em>N</em></b> (number of strings in the list)
- Next <b><em>N</em></b> lines: String <b><em>S<sub>i</sub></em></b>
- Next line: <b><em>Q</em></b> (number of questions)
- Next <b><em>Q</em></b> lines: Three space-separated integers <b><em>L</em></b>, <b><em>R</em></b> and <b><em>K</em></b>

</br>

### Output Format
For each question, print the <b><em>K<sup>th</sup></em></b> character of the concatenated string in a new line.

</br>

### Constraints
1 &le; <b><em>N</em></b> &le; 10<sup>5</sup></br>
1 &le; <b><em>len(S<sub>i</sub>)</em></b> &le; 50</br>
1 &le; <b><em>Q</em></b> &le; 10<sup>5</sup></br>
1 &le; <b><em>L</em></b> &le; <b><em>R</em></b> &le; <b><em>N</em></b></br>
It is always guaranteed that the <b><em>K<sup>th</sup></em></b> position is valid.

</br>

### Sample Input & Output
| Sample Input | Sample Output |
|:------------:|:-------------:|
|       5      |       c       |
|     aaaaa    |       d       |
|     bbbbb    |       e       |
|     ccccc    |               |
|     ddddd    |               |
|     eeeee    |               |
|       3      |               |
|     3 3 3    |               |
|    1 5 16    |               |
|    3 5 15    |               |

</br>

### Explanation
<b>Question 1:</b> Grouped string - <em>ccccc</em>. 3rd character is <b>c</b>.

<b>Question 2:</b> Grouped string - <em>aaaaabbbbbcccccdddddeeeee</em>. 16th character is <b>d</b>.

<b>Question 3:</b> Grouped string - <em>cccccdddddeeeee</em>. 15th character is <b>e</b>.