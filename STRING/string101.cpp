--------------------------------------------------------------------------
                                 Strings
--------------------------------------------------------------------------
Reverse a String	
-------------------------
Given a string, write a recursive program to reverse it.

Method 1 (Using Stack) 
 
// C++ program to reverse a string using stack
#include <bits/stdc++.h>
using namespace std;
 
void recursiveReverse(string &str)
{
   stack<char> st;
   for (int i=0; i<str.length(); i++)
       st.push(str[i]);
 
   for (int i=0; i<str.length(); i++) {
       str[i] = st.top();
       st.pop();
   }      
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    recursiveReverse(str);
    cout << str;
    return 0;
}
Output: 
skeegrofskeeg
 
Time complexity: O(n) 
Auxiliary Space: O(n)

Method 2 (Iterative)
 
// A Simple Iterative C++ program to reverse
// a string
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}
Output: 
skeegrofskeeg
 

Time complexity: O(n) 
Auxiliary Space: O(1)

Method 3 (Iterative using two pointers) 

// A Simple Iterative C++ program to reverse
// a string
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i=0, j=n-1; i<j; i++,j--)
        swap(str[i], str[j]); 
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}
Output: 
skeegrofskeeg
 
Time complexity: O(n) 
Auxiliary Space: O(1)

Method 4 (Recursive) 

// A quickly written program for reversing a string
// using reverse()
#include<bits/stdc++.h>
using namespace std;
int main()
{
   string str = "geeksforgeeks";
     
   // Reverse str[begin..end]
   reverse(str.begin(),str.end());
     
   cout << str;
   return 0;
}
Output: 
skeegrofskeeg
 
Time complexity: O(n) where n is length of string
Auxiliary Space: O(n)


Method 5: Using the inbuilt method ‘reverse()’ in C++ STL

// C++ program to reverse string using
// reverse() method
 
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    // Given String
    string str = "geeksforgeeks";
 
    // reverse function in C++ STL
    reverse(str.begin(), str.end());
 
    // Printing the reversed string
    cout << str;
 
    return 0;
}

Output
skeegrofskeeg
Time complexity: O(n) 
Auxiliary Space: O(1)

Check whether a String is Palindrome or not	
------------------------------------------------
Given a string S consisting of N characters of the English alphabet, the task is to check if the given string is a palindrome. If the given string is a palindrome, then print “Yes“. Otherwise, print “No“.

Note: A string is said to be palindrome if the reverse of the string is the same as the string. 

Examples:

Input: S = “ABCDCBA”
Output: Yes
Explanation:
The reverse of the given string is equal to the (ABCDCBA) which is equal to the given string. Therefore, the given string is palindrome.

Input: S = “GeeksforGeeks”
Output: No
Explanation: 
The reverse of the given string is equal to the (skeeGrofskeeG) which is not equal to the given string. Therefore, the given string is not a palindrome.

Naive Approach: The simplest approach to use the inbuilt reverse function in the STL. Follow the steps below to solve the problem:

Copy the string S to another string, say P, and then reverse the string S.
Now check if the string S is equal to the string P and then print “Yes“. Otherwise, print “No“.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to check whether
// the string is palindrome
string isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return "Yes";
    }
    // Otherwise
    else {
        // return "No"
        return "No";
    }
}
// Driver Code
int main()
{
    string S = "ABCDCBA";
    cout << isPalindrome(S);
 
    return 0;
}
Output
Yes
Time Complexity: O(N)
Auxiliary Space: O(N)

Efficient Approach: The above approach can be optimized in space complexity by traversing the string and checking whether the character at ith index is equal to the character at the (N-i-1)th index for every index in the range [0, N/2]. Follow the steps below to solve the problem:

Iterate over the range [0, N/2], using the variable i and in each iteration check if the character at index i and N-i-1 are not equal, then print “No” and break.
If none of the above cases satisfy, then print “Yes“.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to check whether string
// is palindrome
string isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}
// Driver Code
int main()
{
    string S = "ABCDCBA";
    cout << isPalindrome(S);
 
    return 0;
}
Output: 
Yes
Time Complexity: O(N)
Auxiliary Space: O(1)

Find Duplicate characters in a string	
-----------------------------------------
Write an efficient program to print all the duplicates and their counts in the input string 

Method 1: Using hashing

Algorithm: Let input string be “geeksforgeeks” 

Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2
count[‘k’] = 2 
……
Print all the indexes from the constructed array which have values greater than 1.
Implementation:

// C++ program to count all duplicates
// from string using hashing
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256
 
class gfg
{
    public :
     
    /* Fills count array with
    frequency of characters */
    void fillCharCounts(char *str, int *count)
    {
        int i;
        for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    }
 
    /* Print duplicates present
    in the passed string */
    void printDups(char *str)
    {
         
        // Create an array of size 256 and fill
        // count of every character in it
        int *count = (int *)calloc(NO_OF_CHARS,
                                      sizeof(int));
        fillCharCounts(str, count);
 
        // Print characters having count more than 0
        int i;
        for (i = 0; i < NO_OF_CHARS; i++)
        if(count[i] > 1)
            printf("%c, count = %d \n", i, count[i]);
 
        free(count);
    }
};
 
/* Driver code*/
int main()
{
    gfg g ;
    char str[] = "test string";
    g.printDups(str);
    //getchar();
    return 0;
}

Output
s, count = 2 
t, count = 3 
Time Complexity: O(n), where n = length of the string passed
Space Complexity: O(NO_OF_CHARS)

Note: Hashing involves the use of an array of fixed size each time no matter whatever the string is. 

For example, str = “aaaaaaaaaa”. 

An array of size 256 is used for str, only 1 block out of total size (256) will be utilized to store the number of occurrences of ‘a’ in str (i.e count[‘a’] = 10). 

Rest 256 – 1 = 255 blocks remain unused. 

Thus, Space Complexity is potentially high for such cases. So, to avoid any discrepancies and to improve Space Complexity, maps are generally preferred over long-sized arrays. 

Method 2: Using Maps

Approach: The approach is the same as discussed in Method 1, but, using a map to store the count.

Implementation:

// C++ program to count all duplicates
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}
// This code is contributed by yashbeersingh42
Output
s, count = 2
t, count = 3
Time Complexity: O(N*log(N)), where N = length of the string passed and it generally takes O(log(N)) time for an element insertion in a map. 
Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).

Implementation:

// C++ program to count all duplicates
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;  //increase the count of characters by 1
    }
  
    for (auto it : count) {   //iterating through the unordered map
        if (it.second > 1)   //if the count of characters is greater then 1 then duplicate found
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}
Output
s, count = 2
t, count = 3
Time Complexity: O(N), where N = length of the string passed and it takes O(1) time to insert and access any element in an unordered map
Auxiliary Space: O(K), where K = size of the map (0<=K<=input_string_length).

Write a Code to check whether one string is a rotation of another	
-------------------------------------------------------------------
Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1. 

Examples: 

Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other

Input: S1 = ABCD, S2 = ACBD
Output: Strings are not rotations of each other

Naive Approach: Follow the given steps to solve the problem

Find all the positions of the first character of the original string in the string to be checked.
For every position found, consider it to be the starting index of the string to be checked.
Beginning from the new starting index, compare both strings and check whether they are equal or not.
(Suppose the original string to is s1, string to be checked to be s2,n is the length of strings and j is the position of the first character of s1 in s2, then for i < (length of original string) , check if s1[i]==s2[(j+1)%n). Return false if any character mismatch is found, else return true.
Repeat 3rd step for all positions found.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
bool checkString(string& s1, string& s2, int indexFound,
                 int Size)
{
    for (int i = 0; i < Size; i++) {
        // check whether the character is equal or not
        if (s1[i] != s2[(indexFound + i) % Size])
            return false;
        // %Size keeps (indexFound+i) in bounds, since it
        // ensures it's value is always less than Size
    }
 
    return true;
}
 
int main()
{

    string s1 = "abcd";
    string s2 = "cdab";
 
    if (s1.length() != s2.length()) {
        cout << "s2 is not a rotation on s1" << endl;
    }
    else {
        // store occurrences of the first character of s1
        vector<int> indexes;
 
        int Size = s1.length();
 
        char firstChar = s1[0];
 
        for (int i = 0; i < Size; i++) {
            if (s2[i] == firstChar) {
                indexes.push_back(i);
            }
        }
 
        bool isRotation = false;
 
        // check if the strings are rotation of each other
        // for every occurrence of firstChar in s2
        for (int idx : indexes) {
            isRotation = checkString(s1, s2, idx, Size);
 
            if (isRotation)
                break;
        }
 
        if (isRotation)
            cout << "Strings are rotations of each other"
                 << endl;
        else
            cout
                << "Strings are not rotations of each other"
                << endl;
    }
    return 0;
}
Output
Strings are rotations of each other
Time Complexity: O(n*n) in the worst case, where n is the length of the string.
Auxiliary Space: O(1)

Program to check if strings are rotations of each other or not using queue:
Follow the given steps to solve the problem

If the size of both strings is not equal, then it can never be possible.
Push the original string into a queue q1.
Push the string to be checked inside another queue q2.
Keep popping q2‘s and pushing it back into it till the number of such operations is less than the size of the string.
If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
 
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }

    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
 
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}
// Driver code
int main()
{
    string str1 = "AACD", str2 = "ACDA";
 
    if (check_rotation(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
Output
Strings are rotations of each other
Time Complexity: O(N1 * N2), where N1 and N2 are the lengths of the strings.
Auxiliary Space: O(N)

Efficient Approach: Follow the given steps to solve the problem

Create a temp string and store concatenation of str1 to str1 in temp, i.e temp = str1.str1
If str2 is a substring of temp then str1 and str2 are rotations of each other.
Example: 

str1 = “ABACD”, str2 = “CDABA”
temp = str1.str1 = “ABACDABACD”
Since str2 is a substring of temp, str1 and str2 are rotations of each other.

// C++ program to check if two given strings
// are rotations of  each other
#include <bits/stdc++.h>
using namespace std;
 
/* Function checks if passed strings (str1
   and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;
 
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}
 
/* Driver code */
int main()
{
    string str1 = "AACD", str2 = "ACDA";
 
    // Function call
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
Output
Strings are rotations of each other
Time Complexity: O(N), where N is the length of the string.
Auxiliary Space: O(N)

Write a Program to check whether a string is a valid shuffle of two strings or not	
-----------------------------------------------------------------------------------
Given strings str1 and str2. The task is to find if str1 is a substring in the shuffled form of str2 or not. Print “YES” if str1 is a substring in shuffled form of str2 else print “NO”. 

Example 

Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld” 
Output: YES 
Explanation: str1 is substring in shuffled form of str2 as 
str2 = “hello” + “fourtwoone” + “world” 
str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form) 
Hence, str1 is a substring of str2 in shuffled form.

Input: str1 = “roseyellow”, str2 = “yellow” 
Output: NO 
Explanation: As the length of str1 is greater than str2. Hence, str1 is not a substring of str2.

Approach: 
Let n = length of str1, m = length of str2. 

If n > m, then string str1 can never be the substring of str2.
Else sort the string str1.
Traverse string str2 
Put all the characters of str2 of length n in another string str.
Sort the string str and Compare str and str1.
If str = str1, then string str1 is a shuffled substring of string str2.
else repeat the above process till ith index of str2 such that (i +n – 1 > m)(as after this index the length of remaining string str2 will be less than str1.
If str is not equals to str1 in above steps, then string str1 can never be substring of str2.

// C++ program to check if string
// str1 is substring of str2 or not.
#include <bits/stdc++.h>
using namespace std;
 
// Function two check string A
// is shuffled  substring of B
// or not
bool isShuffledSubstring(string A, string B)
{
    int n = A.length();
    int m = B.length();
 
    // Return false if length of
    // string A is greater than
    // length of string B
    if (n > m) {
        return false;
    }
    else {
 
        // Sort string A
        sort(A.begin(), A.end());
 
        // Traverse string B
        for (int i = 0; i < m; i++) {
 
            // Return false if (i+n-1 >= m)
            // doesn't satisfy
            if (i + n - 1 >= m)
                return false;
 
            // Initialise the new string
            string str = "";
 
            // Copy the characters of
            // string B in str till
            // length n
            for (int j = 0; j < n; j++)
                str.push_back(B[i + j]);
 
            // Sort the string str
            sort(str.begin(), str.end());
 
            // Return true if sorted
            // string of "str" & sorted
            // string of "A" are equal
            if (str == A)
                return true;
        }
    }
}
 
// Driver Code
int main()
{
    // Input str1 and str2
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";
 
    // Function return true if
    // str1 is shuffled substring
    // of str2
    bool a = isShuffledSubstring(str1, str2);
 
    // If str1 is substring of str2
    // print "YES" else print "NO"
    if (a)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}
Output: 
YES

Time Complexity: O(m*n*log(n)), where n = length of string str1 and m = length of string str2 
Auxiliary Space: O(n) 

Efficient Solution: This problem is a simpler version of Anagram Search. It can be solved in linear time using character frequency counting.
We can achieve O(n) time complexity under the assumption that alphabet size is fixed which is typically true as we have maximum of 256 possible characters in ASCII. The idea is to use two count arrays:

1) The first count array stores frequencies of characters in a pattern. 
2) The second count array stores frequencies of characters in the current window of text.
The important thing to note is, time complexity to compare two counted arrays is O(1) as the number of elements in them is fixed (independent of pattern and text sizes). The following are steps of this algorithm. 
1) Store counts of frequencies of pattern in first count array countP[]. Also, store counts of frequencies of characters in the first window of text in array countTW[].
2) Now run a loop from i = M to N-1. Do following in loop. 
…..a) If the two count arrays are identical, we found an occurrence. 
…..b) Increment count of current character of text in countTW[] 
…..c) Decrement count of the first character in the previous window in countWT[]
3) The last window is not checked by the above loop, so explicitly check it.

The following is the implementation of the above algorithm.


#include<iostream>
#include<cstring>
#define MAX 256
using namespace std;
 
// This function returns true if contents of arr1[] and arr2[]
// are same, otherwise false.
bool compare(int arr1[], int arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
 
// This function search for all permutations of pat[] in txt[]
bool search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt);
 
    // countP[]: Store count of all characters of pattern
    // countTW[]: Store count of current window of text
    int countP[MAX] = {0}, countTW[MAX] = {0};
    for (int i = 0; i < M; i++)
    {
        countP[pat[i]]++;
        countTW[txt[i]]++;
    }
 
    // Traverse through remaining characters of pattern
    for (int i = M; i < N; i++)
    {
        // Compare counts of current window of text with
        // counts of pattern[]
        if (compare(countP, countTW))
           return true;
 
        // Add current character to current window
        (countTW[txt[i]])++;
 
        // Remove the first character of previous window
        countTW[txt[i-M]]--;
    }
 
    // Check for the last window in text
    if (compare(countP, countTW))
        return true;
        return false;
}
 
/* Driver program to test above function */
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    if (search(pat, txt))
       cout << "Yes";
    else
       cout << "No";
    return 0;
}
Output: 
Yes

Count and Say problem	
-------------------------------------------------
Find the n’th term in Look-and-say (Or Count and Say) Sequence. The look-and-say sequence is the sequence of the below integers: 
1, 11, 21, 1211, 111221, 312211, 13112221, 1113213211, … 

How is the above sequence generated? 
n’th term is generated by reading (n-1)’th term.

The first term is "1"

Second term is "11", generated by reading first term as "One 1" 
(There is one 1 in previous term)

Third term is "21", generated by reading second term as "Two 1"

Fourth term is "1211", generated by reading third term as "One 2 One 1" 

and so on
How to find n’th term? 

Example: 

Input: n = 3
Output: 21

Input: n = 5
Output: 111221

The idea is simple, we generate all terms from 1 to n. First, two terms are initialized as “1” and “11”, and all other terms are generated using previous terms. To generate a term using the previous term, we scan the previous term. While scanning a term, we simply keep track of the count of all consecutive characters. For a sequence of the same characters, we append the count followed by the character to generate the next term.

// C++ program to find n'th term in look and say
// sequence
#include <bits/stdc++.h>
using namespace std;
 
// Returns n'th term in look-and-say sequence
string countnndSay(int n)
{
    // Base cases
    if (n == 1)      return "1";
    if (n == 2)      return "11";
 
    // Find n'th term by generating all terms from 3 to
    // n-1.  Every term is generated using previous term
    string str = "11"; // Initialize previous term
    for (int i = 3; i<=n; i++)
    {
        // In below for loop, previous character
        // is processed in current iteration. That
        // is why a dummy character is added to make
        // sure that loop runs one extra iteration.
        str += '$';
        int len = str.length();
 
        int cnt = 1; // Initialize count of matching chars
        string  tmp = ""; // Initialize i'th term in series
 
        // Process previous term to find the next term
        for (int j = 1; j < len; j++)
        {
            // If current character doesn't match
            if (str[j] != str[j-1])
            {
                // Append count of str[j-1] to temp
                tmp += cnt + '0';
 
                // Append str[j-1]
                tmp += str[j-1];
 
                // Reset count
                cnt = 1;
            }
 
            //  If matches, then increment count of matching
            // characters
            else cnt++;
        }
 
        // Update str
        str = tmp;
    }
 
    return str;
}
 
// Driver program
int main()
{
    int N = 3;
    cout << countnndSay(N) << endl;
    return 0;
}
Output
21
Another Approach(Using STL): There is one more idea where we can use unordered_map from c++ stl to track the count of digits. Basic idea is to use a generator function that will generate a string from the previous string. In the count and say function we will iterate over integers from 1 to n-1 and keep updating our result.

#include <bits/stdc++.h>
using namespace std;
 
// generator function returns int string from prev int
// string e.g. -> it will return '1211' for '21' ( One 2's
// and One 1)
string generator(string str)
{
    string ans = "";
 
    unordered_map<char, int>
        tempCount; // It is used to count integer sequence
 
    for (int i = 0; i < str.length() + 1; i++) {
        // when current char is different from prev one we
        // clear the map and update the ans
        if (tempCount.find(str[i]) == tempCount.end()
            && i > 0) {
            auto prev = tempCount.find(str[i - 1]);
            ans += to_string(prev->second) + prev->first;
            tempCount.clear();
        }
        // when current char is same as prev one we increase
        // it's count value
        tempCount[str[i]]++;
    }
 
    return ans;
}
 
string countnndSay(int n)
{
    string res = "1"; // res variable keep tracks of string
                      // from 1 to n-1
 
    // For loop iterates for n-1 time and generate strings
    // in sequence "1" -> "11" -> "21" -> "1211"
    for (int i = 1; i < n; i++) {
        res = generator(res);
    }
 
    return res;
}
 
int main()
{
 
    int N = 3;
    cout << countnndSay(N) << endl;
    return 0;
}
Output
21

Write a program to find the longest Palindrome in a string.[ Longest palindromic Substring]	
--------------------------------------------------------------------------------------------
Given a string, find the longest substring which is a palindrome. 

Examples: 

Input: Given string :"forgeeksskeegfor", 
Output: "geeksskeeg".

Input: Given string :"Geeks", 
Output: "ee". 

Common mistake : Wrong Approach:   
Some people will be tempted to come up with a O(n) time complexity quick solution, which is unfortunately flawed (however can be corrected easily):

 (i)Reverse S and  and store it in S’. 
 (ii)Find the longest common substring between S and S’  which must also be the longest palindromic substring.

This seemed to work, let’s see some examples below.

For example, S = “caba” then  S’ = “abac”.

The longest common substring between S and S’ is “aba”, which is the answer.

Let’s try another example: S = “abacdfgdcaba” then S’ = “abacdgfdcaba”.

The longest common substring between S and S’ is “abacd”. Clearly, this is not a valid palindrome.

Correct Approach:

We could see that the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of S. To rectify this, each time we find a longest common substring candidate, we check if the substring’s indices are the same as the reversed substring’s original indices. If it is, then we attempt to update the longest palindrome found so far; if not, we skip this and find the next candidate. This gives us an O(n^2) Dynamic Programming solution which uses O(n^2) space (which could be improved to use O(n) space).

Dynamic programming Approach: Dynamic programming solution is already discussed here in the previous post. The time complexity of the Dynamic Programming based solution is O(n^2) and it requires O(n^2) extra space. We can find the longest palindrome substring( LPS ) in (n^2) time with O(1) extra space. 

The algorithm below is very simple and easy to understand. The idea is to Fix a center and expand in both directions for longer palindromes and keep track of the longest palindrome seen so far.

ALGO:

Maintain a variable ‘ maxLength = 1 ‘ (for storing LPS length) and ‘ start =0 ‘ (for storing starting index of LPS ).
The idea is very simple, we will traverse through the entire string with i=0 to i<(length of string).
while traversing, initialize ‘low‘ and ‘high‘ pointer such that low= i-1 and high= i+1.
keep incrementing ‘high’ until str[high]==str[i] .
similarly keep decrementing ‘low’ until str[low]==str[i].
finally we will keep incrementing ‘high’ and decrementing ‘low’ until str[low]==str[high].
calculate length=high-low-1, if length > maxLength then maxLength = length and start = low+1 .
Print the LPS and return maxLength.
 
// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
// easy to understand as compared to previous version.
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to print
// a substring str[low..high]
// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(string str)
{
    int n = str.size(); // calculating size of string
    if (n < 2)
        return n; // if string is empty then size will be 0.
                  // if n==1 then, answer will be 1(single
                  // character will always palindrome)
 
    int maxLength = 1, start = 0;
    int low, high;
    for (int i = 0; i < n; i++) {
        low = i - 1;
        high = i + 1;
        while (high < n
               && str[high] == str[i]) // increment 'high'
            high++;
 
        while (low >= 0
               && str[low] == str[i]) // decrement 'low'
            low--;
 
        while (low >= 0 && high < n
               && str[low] == str[high]) {
            low--;
            high++;
        }
 
        int length = high - low - 1;
        if (maxLength < length) {
            maxLength = length;
            start = low + 1;
        }
    }
 
    cout << "Longest palindrome substring is: ";
    cout << str.substr(start, maxLength);
    return maxLength;
}
 
// Driver program to test above functions
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalSubstr(str)
         << endl;
    return 0;
}
Output
Longest palindrome substring is: geeksskeeg
Length is: 10
Complexity Analysis:  

Time complexity: O(n^2), where n is the length of the input string. 
Outer Loop that traverses through the entire string, and Inner Loop that is used to expand from i .
Auxiliary Space: O(1). 
No extra space is needed.
The Above approach is a cleaner way.

The function implementation to print the LPS and return the maxLength is given below:


// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
// easy to understand as compared to previous version.
 
#include <bits/stdc++.h>
using namespace std;
 
int maxLength; // variables to store and
string res; // update  maxLength and res
 
// A utility function to get the longest palindrome
// starting and expanding out from given center indices
void cSubUtil(string& s, int l, int r)
{
    // check if the indices lie in the range of string
    // and also if it is palindrome
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        // expand the boundary
        l--;
        r++;
    }
    // if it's length is greater than maxLength update
    // maxLength and res
    if (r - l - 1 >= maxLength) {
        res = s.substr(l + 1, r - l - 1);
        maxLength = r - l - 1;
    }
    return;
}
// A function which takes a string prints the LPS and
// returns the length of LPS
int longestPalSubstr(string str)
{
    res = "";
    maxLength = 1;
    // for every index in the string check palindromes
    // starting from that index
    for (int i = 0; i < str.length(); i++) {
        // check for odd length palindromes
        cSubUtil(str, i, i);
        // check for even length palindromes
        cSubUtil(str, i, i + 1);
    }
 
    cout << "Longest palindrome substring is: ";
    cout << res << "\n";
 
    return maxLength;
}
 
// Driver program to test above functions
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: " << longestPalSubstr(str)
         << endl;
    return 0;
}
Output
Longest palindrome substring is: geeksskeeg
Length is: 10

Find Longest Recurring Subsequence in String	
--------------------------------------------------
Given a string, find the length of the longest repeating subsequence, such that the two subsequences don’t have same string character at the same position, i.e. any ith character in the two subsequences shouldn’t have the same index in the original string. 

Examples:

Input: str = "abc"
Output: 0
There is no repeating subsequence

Input: str = "aab"
Output: 1
The two subsequence are 'a'(first) and 'a'(second). 
Note that 'b' cannot be considered as part of subsequence 
as it would be at same index in both.

Input: str = "aabb"
Output: 2

Input: str = "axxxy"
Output: 2

Algorithm:

Step 1: Initialize the input string, which is to be checked.
Step 2: Initialize the length of string to the variable.
Step 3: Create a DP table using 2D matrix and set each element to 0.
Step 4: Fill the table if  characters are same and indexes are different.
Step 5: Return the values inside the table
Step 6: Print the String.

// C++ program to find the longest repeating
// subsequence
#include <iostream>
#include <string>
using namespace std;
 
// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
 
    // Create and initialize DP table
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
 
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];         
                      
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
 
// Driver Program
int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str);
    return 0;
}
Output
The length of the largest subsequence that repeats itself is : 2
Time Complexity: O(n2)
Auxiliary Space: O(n2)

Another approach: (Using recursion)

// C++ program to find the longest repeating
// subsequence using recursion
#include <bits/stdc++.h>
using namespace std;
 
int dp[1000][1000];
 
// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
 
int findLongestRepeatingSubSeq(string X, int m, int n)
{
     
    if(dp[m][n]!=-1)
    return dp[m][n];
     
    // return if we have reached the end of either string
    if (m == 0 || n == 0)
        return dp[m][n] = 0;
 
    // if characters at index m and n matches
    // and index is different
    if (X[m - 1] == X[n - 1] && m != n)
        return dp[m][n] = findLongestRepeatingSubSeq(X,
                            m - 1, n - 1) + 1;
 
    // else if characters at index m and n don't match
    return dp[m][n] = max (findLongestRepeatingSubSeq(X, m, n - 1),
                           findLongestRepeatingSubSeq(X, m - 1, n));
}
 
// Longest Repeated Subsequence Problem
int main()
{
    string str = "aabb";
    int m = str.length();
 
memset(dp,-1,sizeof(dp));
cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str,m,m);
 
    return 0;

}
Output: 

The length of the largest subsequence that repeats itself is : 2

Approach 3:

To find the length of the Longest Repeating Subsequence  dynamic  programming Top-down Approach:

Take the input string.
Perform the Longest common subsequence where s1[i]==s1[j] and i!=j.
Return the length.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
int lrs(string s1,int i,int j, vector<vector<int>>&dp){
 
    // return if we have reached the
    //end of either string
    if(i >= s1.length() || j >= s1.length())
        return 0;
 
    if(dp[i][j] != -1)
        return dp[i][j];
     
    // while dp[i][j] is not computed earlier
    if(dp[i][j] == -1){
     
        // if characters at index m and n matches
        // and index is different
        // Index should not match
        if(s1[i] == s1[j] && i != j)
            dp[i][j] = 1+lrs(s1, i+1, j+1, dp);
         
        // else if characters at index m and n don't match
        else
            dp[i][j] = max(lrs(s1, i, j+1, dp),
                                lrs(s1, i+1, j, dp));
    }
     
    // return answer
    return dp[i][j];
}
 
// Driver Code
int main(){
string s1 = "aabb";
     
// Reversing the same string
string s2 = s1;
reverse(s2.begin(),s2.end());
vector<vector<int>>dp(1000,vector<int>(1000,-1));
cout<<"LENGTH OF LONGEST REPEATING SUBSEQUENCE IS : "<<lrs(s1, 0, 0, dp);
 
}

Time Complexity: O(n2)
Auxiliary Space: O(n2)

Print all Subsequences of a string.	
-------------------------------------
Given a string, we have to find out all subsequences of it. A String is a subsequence of a given String, that is generated by deleting some character of a given string without changing its order.

Examples: 

Input : abc
Output : a, b, c, ab, bc, ac, abc

Input : aaa
Output : a, a, a, aa, aa, aa, aaa

Method 1 (Pick and Don’t Pick Concept) :

Implementation:
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Find all subsequences
void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    // output is passed with including
    // the Ist character of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
 
// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output);
 
    return 0;
}
Output
abcd abc abd ab acd ac ad a bcd bc bd b cd c d
Method 2 

Explanation : 

Step 1: Iterate over the entire String
Step 2: Iterate from the end of string 
        in order to generate different substring
        add the substring to the list
Step 3: Drop kth character from the substring obtained 
        from above to generate different subsequence.
Step 4: if the subsequence is not in the list then recur.

// CPP program to print all subsequence of a
// given string.
#include <bits/stdc++.h>
using namespace std;
 
// set to store all the subsequences
unordered_set<string> st;
 
// Function computes all the subsequence of an string
void subsequence(string str)
{
 
    // Iterate over the entire string
    for (int i = 0; i < str.length(); i++) {
 
        // Iterate from the end of the string
        // to generate substrings
        for (int j = str.length(); j > i; j--) {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);
 
            // Drop kth character in the substring
            // and if its not in the set then recur
            for (int k = 1; k < sub_str.length(); k++) {
                string sb = sub_str;
 
                // Drop character from the string
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}
 
// Driver Code
int main()
{
    string s = "aabc";
    subsequence(s);
    for (auto i : st)
        cout << i << " ";
    cout << endl;
 
    return 0;
}

Output
aab aa aac bc b abc aabc ab ac a c 
Method 3: One by one fix characters and recursively generates all subsets starting from them. After every recursive call, we remove last character so that the next permutation can be generated. 

Implementation:

// CPP program to generate power set in
// lexicographic order.
#include <bits/stdc++.h>
using namespace std;
 
// str : Stores input string
// n : Length of str.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string str, int n, int index = -1,
                    string curr = "")
{
    // base case
    if (index == n)
        return;
 
    if (!curr.empty()) {
        cout << curr << "\n";
    }
 
    for (int i = index + 1; i < n; i++) {
 
        curr += str[i];
        printSubSeqRec(str, n, i, curr);
 
        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}
// Generates power set in lexicographic
// order.
void printSubSeq(string str)
{
    printSubSeqRec(str, str.size());
}
 
// Driver code
int main()
{
    string str = "cab";
    printSubSeq(str);
    return 0;
}
Output
c ca cab cb a ab b
Time Complexity: O(n * 2n), where n is the size of the given string
Auxiliary Space: O(1), as no extra space is used

Print all the permutations of the given string	
-------------------------------------------------
A permutation also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 

Below are the permutations of string ABC. 
ABC ACB BAC BCA CBA CAB

Here is a solution that is used as a basis in backtracking.

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;
 
// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string &a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
// Driver Code
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}

Output
ABC ACB BAC BCA CBA CAB

Algorithm Paradigm: Backtracking 
Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a permutation.
Auxiliary Space: O(r – l)

Note: The above solution prints duplicate permutations if there are repeating characters in the input string. Please see the below link for a solution that prints only distinct permutations even if there are duplicates in input.

Another approach:

#include <bits/stdc++.h>
#include <string>
using namespace std;
 
void permute(string s , string answer)
{
    if(s.length() == 0)
    {
        cout<<answer<<"  ";
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch);
    }
 
}
 
int main()
{
    string s;
    string answer="";
 
    cout<<"Enter the string : ";
    cin>>s;
 
    cout<<"\nAll possible strings are : ";
    permute(s , answer);
    return 0;
}
Output:
Enter the string : abc
All possible strings are : abc  acb  bac  bca  cab  cba
Time Complexity: O(n*n!) The time complexity is the same as the above approach, i.e. there are n! permutations and it requires O(n) time to print a permutation.
Auxiliary Space: O(|s|)

Split the Binary string into two substring with equal 0’s and 1’s	
------------------------------------------------------------------
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
Example: 
 
Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.

Input: str = “0111100010” 
Output: 3 

Input: str = “0000000000” 
Output: -1

Approach: Initialize count = 0 and traverse the string character by character and keep track of the number of 0s and 1s so far, whenever the count of 0s and 1s become equal increment the count. As in the given question, if it is not possible to split string then on that time count of 0s must not be equal to count of 1s then return -1 else print the value of count after the traversal of the complete string.

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{
 
    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;
 
    // To store the count of maximum
    // substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }
 
    // It is not possible to
    // split the string
    if (count0!=count1) {
        return -1;
    }
 
    return cnt;
}
 
// Driver code
int main()
{
    string str = "0100110101";
    int n = str.length();
 
    cout << maxSubStr(str, n);
 
    return 0;
}
Output: 
4
Time complexity: O(N) where N is the length of string 
Space Complexity: O(1)

Word Wrap Problem [VERY IMP].	
--------------------------------------
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is smaller than the line width.
The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces. 
 

The extra spaces includes spaces put at the end of every line except the last one.  
The problem is to minimize the following total cost.
 Cost of a line = (Number of extra spaces in the line)^3
 Total Cost = Sum of costs for all lines

For example, consider the following string and line width M = 15
 "Geeks for Geeks presents word wrap problem" 
     
Following is the optimized arrangement of words in 3 lines
Geeks for Geeks
presents word
wrap problem 

The total extra spaces in line 1, line 2 and line 3 are 0, 2 and 3 respectively. 
So optimal value of total cost is 0 + 2*2*2 + 3*3*3 = 35
Please note that the total cost function is not sum of extra spaces, but sum of cubes (or square is also used) of extra spaces. The idea behind this cost function is to balance the spaces among lines. For example, consider the following two arrangement of same set of words:
1) There are 3 lines. One line has 3 extra spaces and all other lines have 0 extra spaces. Total extra spaces = 3 + 0 + 0 = 3. Total cost = 3*3*3 + 0*0*0 + 0*0*0 = 27.
2) There are 3 lines. Each of the 3 lines has one extra space. Total extra spaces = 1 + 1 + 1 = 3. Total cost = 1*1*1 + 1*1*1 + 1*1*1 = 3.
Total extra spaces are 3 in both scenarios, but second arrangement should be preferred because extra spaces are balanced in all three lines. The cost function with cubic sum serves the purpose because the value of total cost in second scenario is less.
 
Method 1 (Greedy Solution) 
The greedy solution is to place as many words as possible in the first line. Then do the same thing for the second line and so on until all words are placed. This solution gives optimal solution for many cases, but doesn’t give optimal solution in all cases. For example, consider the following string “aaa bb cc ddddd” and line width as 6. Greedy method will produce following output. 

aaa bb 
cc 
ddddd
Extra spaces in the above 3 lines are 0, 4 and 1 respectively. So total cost is 0 + 64 + 1 = 65.
But the above solution is not the best solution. Following arrangement has more balanced spaces. Therefore less value of total cost function.


aaa
bb cc
ddddd
Extra spaces in the above 3 lines are 3, 1 and 1 respectively. So total cost is 27 + 1 + 1 = 29.
Despite being sub-optimal in some cases, the greedy approach is used by many word processors like MS Word and OpenOffice.org Writer.

Method 2 (Recursive Approach with memoization)

The problem can be solved using a divide and conquer (recursive) approach. The algorithm for the same is mentioned below:

1. We recur for each word starting with first word, and remaining length of the line (initially k).
2. The last word would be the base case:
    We check if we can put it on same line:
        if yes, then we return cost as 0.
        if no, we return cost of current line based on its remaining length.
3. For non-last words, we have to check if it can fit in the current line:
    if yes, then we have two choices i.e. whether to put it in same line or next line.
        if we put it on next line: cost1 = square(remLength) + cost of putting word on next line.
        if we put it on same line: cost2 = cost of putting word on same line.
        return min(cost1, cost2)
    if no, then we have to put it on next line:
        return cost of putting word on next line
4. We use memoization table of size n (number of words) * k (line length), to keep track of already visited positions.

#include <bits/stdc++.h>
using namespace std;
 
int solveWordWrapUsingMemo(int words[], int n, int length,
                           int wordIndex, int remLength,
                           vector<vector<int> > memo);
 
int square(int n) { return n * n; }
 
int solveWordWrapUtil(int words[], int n, int length,
                      int wordIndex, int remLength,
                      vector<vector<int> > memo)
{
 
    // base case for last word
    if (wordIndex == n - 1) {
        memo[wordIndex][remLength]
            = words[wordIndex] < remLength
                  ? 0
                  : square(remLength);
        return memo[wordIndex][remLength];
    }
 
    int currWord = words[wordIndex];
    // if word can fit in the remaining line
    if (currWord < remLength) {
        return min(solveWordWrapUsingMemo(
                       words, n, length, wordIndex + 1,
                       remLength == length
                           ? remLength - currWord
                           : remLength - currWord - 1,
                       memo),
 
                   square(remLength)
                       + solveWordWrapUsingMemo(
                           words, n, length, wordIndex + 1,
                           length - currWord, memo));
    }
    else {
        // if word is kept on next line
        return square(remLength)
               + solveWordWrapUsingMemo(
                   words, n, length, wordIndex + 1,
                   length - currWord, memo);
    }
}
 
int solveWordWrapUsingMemo(int words[], int n, int length,
                           int wordIndex, int remLength,
                           vector<vector<int> > memo)
{
    if (memo[wordIndex][remLength] != -1) {
        return memo[wordIndex][remLength];
    }
 
    memo[wordIndex][remLength] = solveWordWrapUtil(
        words, n, length, wordIndex, remLength, memo);
    return memo[wordIndex][remLength];
}
 
int solveWordWrap(int words[], int n, int k)
{
 
    vector<vector<int> > memo(n, vector<int>(k + 1, -1));
 
    return solveWordWrapUsingMemo(words, n, k, 0, k, memo);
}
int main()
{
    int words[] = { 3, 2, 2, 5 };
    int n = sizeof(words) / sizeof(words[0]);
    int k = 6;
 
    cout << solveWordWrap(words, n, k);
    return 0;
}

Output
10

EDIT Distance [Very Imp]	
--------------------------------------
Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

Insert
Remove
Replace
All of the above operations are of equal cost. 

Examples: 

Input:   str1 = “geek”, str2 = “gesek”
Output:  1
Explanation: We can convert str1 into str2 by inserting a ‘s’.

Input:   str1 = “cat”, str2 = “cut”
Output:  1
Explanation: We can convert str1 into str2 by replacing ‘a’ with ‘u’.

Input:   str1 = “sunday”, str2 = “saturday”
Output:  3
Explanation: Last three and first characters are same.  We basically need to convert “un” to “atur”.  This can be done using below three operations. Replace ‘n’ with ‘r’, insert t, insert a

What are the subproblems in this case? 
The idea is to process all characters one by one starting from either from left or right sides of both strings. 
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.  

m: Length of str1 (first string)
n: Length of str2 (second string)
If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values. 
Insert: Recur for m and n-1
Remove: Recur for m-1 and n
Replace: Recur for m-1 and n-1

// A Naive recursive C++ program to find minimum number
// operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;
 
// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDist(string str1, string str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;
 
    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
 
// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
 
    return 0;
}
Output
3
The time complexity of above solution is exponential. In worst case, we may end up doing O(3m) operations. The worst case happens when none of characters of two strings match. Below is a recursive call diagram for worst case. 
Auxiliary Space: O(1), because no extra space is utilized.

Find next greater number with same set of digits. [Very Very IMP]	
----------------------------------------------------------------------
Given a number n, find the smallest number that has same set of digits as n and is greater than n. If n is the greatest possible number with its set of digits, then print “not possible”.

Examples: 
For simplicity of implementation, we have considered input number as a string. 

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"

Following are few observations about the next greater number. 

1.If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321. 
2.If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234. 
3.For other cases, we need to process the number from rightmost side (why? because we need to find the smallest of all greater numbers)
 
Following is the algorithm for finding the next greater number. 

Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9. If we do not find such a digit, then output is “Not Possible”.
Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.
Swap the above found two digits, we get 536974 in above example.
Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output. For above example, we sort digits in bold 536974. We get “536479” which is the next greater number for input 534976.

// C++ program to find the smallest number which greater than a given number
// and has same set of digits as given number
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
// Utility function to swap two digits
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
// Given a number as a char array number[], this function finds the
// next greater number.  It modifies the same array to store the result
void findNext(char number[], int n)
{
    int i, j;
 
    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;
 
    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits
    if (i==0)
    {
        cout << "Next number is not possible";
        return;
    }
 
    // II) Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;
 
    // III) Swap the above found smallest digit with number[i-1]
    swap(&number[smallest], &number[i-1]);
 
    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);
 
    cout << "Next number with same set of digits is " << number;
 
    return;
}
 
// Driver program to test above function
int main()
{
    char digits[] = "534976";
    int n = strlen(digits);
    findNext(digits, n);
    return 0;
}
Output
Next number with same set of digits is 536479
Time Complexity: O(N*logN) 
Auxiliary Space: O(1)

The above implementation can be optimized in following ways. 

We can use binary search in step II instead of linear search. 
In step IV, instead of doing simple sort, we can apply some clever technique to do it in linear time. Hint: We know that all digits are linearly sorted in reverse order except one digit which was swapped.
With above optimizations, we can say that the time complexity of this method is O(n). 

Optimised Approach:

Here instead of sorting the digits after (i-1) index, we are reversing the digits as mentioned in the above optimisation point.
As they will be in decreasing order so to find the smallest element possible from the right part we just reverse them thus reducing time complexity.

#include <bits/stdc++.h>
using namespace std;
 
vector<int> nextPermutation(int n, vector<int> arr)
{
    // If number of digits is 1 then just return the vector
    if (n == 1)
        return arr;
 
    // Start from the right most digit and find the first
    // digit that is
    // smaller than the digit next to it.
    int i = 0;
    for (i = n - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1])
            break;
    }
 
    // If there is a possibility of a next greater element
    if (i != 0) {
        // Find the smallest digit on right side of (i-1)'th
        // digit that is
        // greater than number[i-1]
        for (int j = n - 1; j >= i; j--) {
            if (arr[i - 1] < arr[j]) {
                // Swap the found smallest digit i.e. arr[j]
                // with arr[i-1]
                swap(arr[i - 1], arr[j]);
                break;
            }
        }
    }
 
    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    reverse(arr.begin() + i, arr.end());
 
    // If i is 0 that means elements are in decreasing order
    // Therefore, no greater element possible then we just
    // return the lowest possible
    // order/element formed from these digits by just
    // reversing the vector
 
    return arr;
}
 
int main()
{
    int n = 6;
    vector<int> v{ 5,3,4,9,7,6 };
    vector<int> res;
    res = nextPermutation(n, v);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
Output
5 3 6 4 7 9 
Time Complexity: O(N)
Auxiliary Space: O(1)

Balanced Parenthesis problem.[Imp]	
-----------------------------------------
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

Example: 

Input: exp = “[()]{}{[()()]()}” 
Output: Balanced
Explanation: all the brackets are well-formed

Input: exp = “[(])” 
Output: Not Balanced 
Explanation: 1 and 4 brackets are not balanced because 
there is a closing ‘]’ before the closing ‘(‘

Using Stack:
The idea is to put all the opening brackets in the stack. Whenever you hit a closing bracket, search if the top of the stack is the opening bracket of the same nature. If this holds then pop the stack and continue the iteration, in the end if the stack is empty, it means all brackets are well-formed . Otherwise, they are not balanced.

Illustration: 

Follow the steps mentioned below to implement the idea:

Declare a character stack (say temp).
Now traverse the string exp. 
If the current character is a starting bracket ( ‘(‘ or ‘{‘  or ‘[‘ ) then push it to stack.
If the current character is a closing bracket ( ‘)’ or ‘}’ or ‘]’ ) then pop from stack and if the popped character is the matching starting bracket then fine.
Else brackets are Not Balanced.
After complete traversal, if there is some starting bracket left in stack then Not balanced, else Balanced.
Below is the implementation of the above approach:


// C++ program to check for balanced brackets.
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    // Declare a stack to hold the previous brackets.
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {
             
            // If the stack is empty
            // just push the current bracket
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')')
                 || (temp.top() == '{' && expr[i] == '}')
                 || (temp.top() == '[' && expr[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            temp.pop();
        }
        else {
            temp.push(expr[i]);
        }
    }
    if (temp.empty()) {
         
        // If stack is empty return true
        return true;
    }
    return false;
}
 
// Driver code
int main()
{
    string expr = "{()}[]";
 
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
Output
Balanced
Time Complexity: O(N), Iteration over the string of size N one time.
Auxiliary Space: O(N) for stack. 

Word break Problem[ Very Imp]	
--------------------------------
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details. 
This is a famous Google interview question, also being asked by many other companies now a days.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" 
or "i like sam sung".

Recursive implementation: 
The idea is simple, we consider each prefix and search it in dictionary. If the prefix is present in dictionary, we recur for rest of the string (or suffix).

If the recursive call for suffix returns true, we return true, otherwise we try next prefix. If we have tried all prefixes and none of them resulted in a solution, we return false.

// A recursive program to test whether a given
// string can be segmented into space separated
// words in dictionary
#include <iostream>
using namespace std;
 
/* A utility function to check whether a word is
  present in dictionary or not. An array of strings
  is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have
  used for simplicity of the program*/
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}
 
// returns true if string can be segmented into space
// separated words, otherwise returns false
bool wordBreak(string str)
{
    int size = str.size();
 
    // Base case
    if (size == 0)  return true;
 
    // Try all prefixes of lengths from 1 to size
    for (int i=1; i<=size; i++)
    {
        // The parameter for dictionaryContains is
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in  dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of 
        // length size-i
        if (dictionaryContains( str.substr(0, i) ) &&
            wordBreak( str.substr(i, size-i) ))
            return true;
    }
 
    // If we have tried all prefixes and
    // none of them worked
    return false;
}
 
// Driver program to test above functions
int main()
{
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}
Output

Yes
Yes
Yes
Yes
Yes
No

Rabin Karp Algorithm	
--------------------------
Given a text txt[0. . .n-1] and a pattern pat[0. . .m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Examples: 

Input:  txt[] = “THIS IS A TEST TEXT”, pat[] = “TEST”
Output: Pattern found at index 10

Input:  txt[] =  “AABAACAADAABAABA”, pat[] =  “AABA”
Output: Pattern found at index 0
              Pattern found at index 9
              Pattern found at index 12

Approach: To solve the problem follow the below idea:

The Naive String Matching algorithm slides the pattern one by one. After each slide, one by one checks characters at the current shift, and if all characters match then print the match

Like the Naive Algorithm, the Rabin-Karp algorithm also slides the pattern one by one. But unlike the Naive algorithm, the Rabin Karp algorithm matches the hash value of the pattern with the hash value of the current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for the following strings.

Pattern itself
All the substrings of the text of length m
Since we need to efficiently calculate hash values for all the substrings of size m of text, we must have a hash function that has the following property:

Hash at the next shift must be efficiently computable from the current hash value and next character in text or we can say hash(txt[s+1 .. s+m]) must be efficiently computable from hash(txt[s .. s+m-1]) and txt[s+m] i.e., hash(txt[s+1 .. s+m]) = rehash(txt[s+m], hash(txt[s .. s+m-1])) and
Rehash must be O(1) operation.
Note: The hash function suggested by Rabin and Karp calculates an integer value. The integer value for a string is the numeric value of a string. 
For example, If all possible characters are from 1 to 10, the numeric value of “122” will be 122. 

The number of possible characters is higher than 10 (256 in general) and the pattern length can be large. So the numeric values cannot be practically stored as an integer. Therefore, the numeric value is calculated using modular arithmetic to make sure that the hash values can be stored in an integer variable (can fit in memory words). To do rehashing, we need to take off the most significant digit and add the new least significant digit for in hash value. Rehashing is done using the following formula:

hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
hash( txt[s .. s+m-1] ) : Hash value at shift s
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
d: Number of characters in the alphabet 
q: A prime number 
h: d(m-1)

How does the above expression work? 

This is simple mathematics, we compute the decimal value of the current window from the previous window. 
Example: pattern length is 3 and string is “23456” 
You compute the value of the first window (which is “234”) as 234. 
How will you compute the value of the next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.

Follow the steps mentioned here to implement the idea:

Initially calculate the hash value of the pattern.
Start iterating from the starting of the string:
Calculate the hash value of the current substring having length m.
If the hash value of the current substring and the pattern are same check if the substring is same as the pattern.
If they are same, store the starting index as a valid answer. Otherwise, continue for the next substrings.
Return the starting indices as the required answer.
Below is the implementation of the above approach:


/* Following program is a C++ implementation Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;
 
// d is the number of characters in the input alphabet
#define d 256
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            if (j == M)
                cout << "Pattern found at index " << i
                     << endl;
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}
 
/* Driver code */
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
 
    // we mod to avoid overflowing of value but we should
    // take as big q as possible to avoid the collison
    int q = INT_MAX;
 
    // Function Call
    search(pat, txt, q);
    return 0;
}

Output
Pattern found at index 0
Pattern found at index 10
Time Complexity: 
The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the same as the hash values of all the substrings of txt[] match with the hash value of pat[]. 
Auxiliary Space: O(1)

KMP Algorithm	
-------------------------

Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.
 
Examples: 

Input : aabcdaabc
Output : 4
The string "aabc" is the longest
prefix which is also suffix.

Input : abcab
Output : 2

Input : aaaa
Output : 2

Simple Solution: Since overlapping prefixes and suffixes is not allowed, we break the string from the middle and start matching left and right strings. If they are equal return size of one string, else they try for shorter lengths on both sides.
Below is a solution to the above approach!


// CPP program to find length of the
// longest prefix which is also suffix
#include <bits/stdc++.h>
using namespace std;
 
// Function to find largest prefix
// which is also a suffix
int largest_prefix_suffix(const std::string
                                      &str)
{
   
  int n = str.length();
   
  // if n is less than 2
  if(n < 2) {
    return 0;
  }
 
  int len = 0;
  int i = 1;
   
  // Iterate i till n
  while(i < n)
  {
     
    // If str[i] is equal to
    // str[len]
    if(str[i] == str[len])
    {
      ++len;
      ++i;
    }
    else
    {
      i = i - len + 1;
      len = 0;
    }
  }
   
  // Return len
  return len>n/2? len/2:len;
 
}
 
// Driver code
int main()
{
     
  string s = "blablabla";
 
  // Function Call
  cout << largest_prefix_suffix(s);
  return 0;
}
Output: 3

Efficient Solution: The idea is to use the preprocessing algorithm KMP search. In the preprocessing algorithm, we build lps array which stores the following values.

lps[i] = the longest proper prefix of pat[0..i] 
which is also a suffix of pat[0..i].


// Efficient CPP program to find length of
// the longest prefix which is also suffix
#include<bits/stdc++.h>
using namespace std;
 
// Returns length of the longest prefix
// which is also suffix and the two do
// not overlap. This function mainly is
// copy computeLPSArray() of in below post
int longestPrefixSuffix(string s)
{
    int n = s.length();
 
    int lps[n];
    lps[0] = 0; // lps[0] is always 0
 
    // length of the previous
    // longest prefix suffix
    int len = 0;
 
    // the loop calculates lps[i]
    // for i = 1 to n-1
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider
            // the example. AAACAAAA
            // and i = 7. The idea is
            // similar to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do
                // not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
 
    int res = lps[n-1];
 
    // Since we are looking for
    // non overlapping parts.
    return (res > n/2)? res/2 : res;
}
 
// Driver program to test above function
int main()
{
    string s = "abcab";
    cout << longestPrefixSuffix(s);
    return 0;
}
Output: 
2
 
Please refer computeLPSArray() of KMP search for explanation.
Time Complexity : O(n) 
Auxiliary Space : O(n)

Convert a Sentence into its equivalent mobile numeric keypad sequence.	
-----------------------------------------------------------------------
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 

Examples : 

Input: GEEKSFORGEEKS
Output: 4333355777733366677743333557777
Explanation: For obtaining a number, we need to press a number corresponding to that character for a number of times equal to the position of the character. For example, for character E, press number 3 two times and accordingly.

Input : HELLO WORLD
Output : 4433555555666096667775553

Approach: Follow the steps given below to convert a sentence into its equivalent mobile numeric keypad sequence. 

For each character, store the sequence which should be obtained at its respective position in an array, i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.
For each character, subtract ASCII value of ‘A’ and obtain the position in the array pointed 
by that character and add the sequence stored in that array to a string.
If the character is a space, store 0
Print the overall sequence.

// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
 
// Function which computes the sequence
string printSequence(string arr[], string input)
{
    string output = "";
 
    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++) {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";
 
        else {
            // Calculating index for each
            // character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }
 
    // Output sequence
    return output;
}
 
// Driver Code
int main()
{
    // storing the sequence in array
    string str[]
        = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };
 
    string input = "GEEKSFORGEEKS";
    cout << printSequence(str, input);
    return 0;
}
Output
4333355777733366677743333557777
Time complexity: O(N), For traversing the string
Auxiliary Space: O(N), For storing the answer.

Minimum number of bracket reversals needed to make an expression balanced.	
---------------------------------------------------------------------------
Given an expression with only ‘}’ and ‘{‘. The expression may not be balanced. Find minimum number of bracket reversals to make the expression balanced.
Examples: 

Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3

One simple observation is, the string can be balanced only if total number of brackets is even (there must be equal no of ‘{‘ and ‘}’)
A Naive Solution is to consider every bracket and recursively count number of reversals by taking two cases (i) keeping the bracket as it is (ii) reversing the bracket. If we get a balanced expression, we update result if number of steps followed for reaching here is smaller than the minimum so far. Time complexity of this solution is O(2n). 

An Efficient Solution can solve this problem in O(n) time. The idea is to first remove all balanced part of expression. For example, convert “}{{}}{{{” to “}{{{” by removing highlighted part. If we take a closer look, we can notice that, after removing balanced part, we always end up with an expression of the form }}…}{{…{, an expression that contains 0 or more number of closing brackets followed by 0 or more numbers of opening brackets. 
How many minimum reversals are required for an expression of the form “}}..}{{..{” ?. Let m be the total number of closing brackets and n be the number of opening brackets. We need ⌈m/2⌉ + ⌈n/2⌉ reversals. For example }}}}{{ requires 2+1 reversals.

// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
    int len = expr.length();
 
    // length of expression must be even to make
    // it balanced by using reversals.
    if (len % 2)
        return -1;
 
    // After this loop, stack contains unbalanced
    // part of expression, i.e., expression of the
    // form "}}..}{{..{"
    stack<char> s;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '}' && !s.empty()) {
            if (s.top() == '{')
                s.pop();
            else
                s.push(expr[i]);
        }
        else
            s.push(expr[i]);
    }
 
    // Length of the reduced expression
    // red_len = (m+n)
    int red_len = s.size();
 
    // count opening brackets at the end of
    // stack
    int n = 0;
    while (!s.empty() && s.top() == '{') {
        s.pop();
        n++;
    }
 
    // return ceil(m/2) + ceil(n/2) which is
    // actually equal to (m+n)/2 + n%2 when
    // m+n is even.
    return (red_len / 2 + n % 2);
}
 
// Driver program to test above function
int main()
{
    string expr = "}}{{";
    cout << countMinReversals(expr);
    return 0;
}
Output

2
Time Complexity: O(n) 
Auxiliary Space: O(n)

An another Intuitive Solution can solve this problem with same complexity. 

The idea is to follow the algorithm used in Check if the parentheses is balanced or not. We follow this algorithm with a new condition when we find that the parentheses is not balanced.  This case arises when the stack is empty and we encounter a ‘ } ‘. In Check if the parentheses is balanced or not program we break the loop when we find that parentheses is not balanced but here we will reverse it to ‘ { ‘ and push it to the stack. While doing this, answer is incremented by 1.

Here, since we found a case of unbalanced expression the ‘ { ‘ must be changed in order to get a balanced expression. Also, changing this would be the most minimal way to get a balanced expression as it is a must condition to change it.

For example,  string = “}{{}}{}}” will be converted to “{{{}}{}}” and we get a balanced expression. There may arise a case where after doing this to the string we have some ‘{‘ left in the stack. For example,  string = “{}{{{{” will be converted to “{}{{{{” and there will be 4 ‘{‘ present in the stack which are not popped and are not balanced.

We can simply make it balanced by reversing the right half of the stack to ‘}’. Example: if stack has ‘ {{{{ ‘ left, we make it ‘ {{}} ‘ forming a balanced expression. Hence, answer gets updated by (stack size / 2). The case where the size of stack is odd, it is not possible to transform it to a balanced string.


#include <iostream>
using namespace std;
#include <stack>
 
int countMinReversals(string str)
{
    // Step 1: Initialize a stack of char type and ans as 0.
    stack<char> st;
    int ans = 0;
 
    // Step 2: Run a loop for each character of the string
    for (int i = 0; i < str.size(); i++) {
       
        // Step 2.1: If ' { ' encountered push it to the
        // stack
        if (str[i] == '{')
            st.push(str[i]);
        // Step 2.2: If ' } ' is encountered
        else {
            // Step 2.2.1: If stack has a '{' present for
            // '}' encountered, pop from the stack.
            if (!st.empty())
                st.pop();
            // Step 2.2.2: If stack is empty, change '}' to
            // '{' and push it to stack and increment ans by
            // 1
            else {
                st.push('{');
                ans++;
            }
        }
    }
    // Step 3: if stack size is odd return -1.
    if (st.size() % 2 != 0)
        return -1;
    // Step 4: Increment ans by ( stackSize/2 ).
    ans += st.size() / 2;
 
    return ans;
}
 
int main()
{
    string expr = "{{{{}}";
    cout << countMinReversals(expr);
    return 0;
}
Output:
1
Time Complexity: O(n)
Auxiliary Space: O(n)

Another efficient solution solve the problem in O(1) i.e. constant space. Since the expression only contains one type of brackets, the idea is to maintain two variables to keep count of left bracket as well as right bracket as we did in Length of the longest valid substring. If the expression has balanced brackets, then we decrement left variable else we increment right variable. Then all we need to return is ceil(left/2) + ceil(right/2).

// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
    int len = expr.length();
 
    // Expressions of odd lengths
    // cannot be balanced
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++) {
 
        // If we find a left bracket then we simply
        // increment the left bracket
        if (expr[i] == '{') {
            left_brace++;
        }
 
        // Else if left bracket is 0 then we find
        // unbalanced right bracket and increment
        // right bracket or if the expression
        // is balanced then we decrement left
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
}
 
// Driver program to test above function
int main()
{
    string expr = "}}{{";
    cout << countMinReversals(expr);
    return 0;
}
Output
2
Time Complexity: O(n) 
Auxiliary Space: O(1)

Instead of maintaining two different variables for left brace and right brace, we can do it using a single temporary variable.

Traverse the array. For each ‘{‘ , increment the value of temp by 1 and for each ‘}’, if value of temp >0, then decrement the value of temp by 1 else, increment the value of result as well as temp by 1. At end, add half of the value of temp to the result.


// C++ program to find minimum number of
// reversals required to balance an expression
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string s)
{
    int temp = 0, res = 0, n = s.size();
    if (n % 2 != 0)
        return -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{')
            temp++;
        else {
            if (temp == 0) {
                res++;
                temp++;
            }
            else
                temp--;
        }
    }
    if (temp > 0)
        res += temp / 2;
    return res;
}
 
// Driver program to test above function
int main()
{
    string expr = "}}{{";
    cout << countMinReversals(expr);
    return 0;
    // This code is contributed by Akansha Mittal
}
Output:2
Time Complexity: O(n)
Auxiliary Space: O(1)

Count All Palindromic Subsequence in a given String.	
------------------------------------------------------
Find how many palindromic subsequences (need not necessarily be distinct) can be formed in a given string. Note that the empty string is not considered a palindrome. 

Examples: 

Input : str = "abcd"
Output : 4
Explanation :- palindromic  subsequence are : "a" ,"b", "c" ,"d" 

Input : str = "aab"
Output : 4
Explanation :- palindromic subsequence are :"a", "a", "b", "aa"

Input : str = "aaaa"
Output : 15

The above problem can be recursively defined. 

Initial Values : i= 0, j= n-1;

CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j])
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1)
Explanation of Recurisive Solution to Counting Palindromic Subsequence


If we draw recursion tree of the above recursive solution, we can observe overlapping Subproblems. Since the problem has overlapping subproblems, we can solve it efficiently using Dynamic Programming. Below is Dynamic Programming based solution.

Example 

// Counts Palindromic Subsequence in a given String
#include <cstring>
#include <iostream>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str)
{
    int N = str.length();
 
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
 
    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;
 
    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
 
    // return total palindromic subsequence
    return cps[0][N - 1];
}
 
// Driver program
int main()
{
    string str = "abcb";
    cout << "Total palindromic subsequence are : "
         << countPS(str) << endl;
    return 0;
}
Output: 
Total palindromic subsequence are : 6
Time Complexity: O(N2), Auxiliary Space: O(N2)

Another approach: (Using recursion)

// C++ program to counts Palindromic Subsequence
// in a given String using recursion
#include <bits/stdc++.h>
using namespace std;
 
int n, dp[1000][1000];
string str = "abcb";
 
// Function return the total
// palindromic subsequence
int countPS(int i, int j)
{
 
    if (i > j)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (i == j)
        return dp[i][j] = 1;
 
    else if (str[i] == str[j])
        return dp[i][j]
               = countPS(i + 1, j) +
                countPS(i, j - 1) + 1;
 
    else
        return dp[i][j] = countPS(i + 1, j) +
                          countPS(i, j - 1) -
                          countPS(i + 1, j - 1);
}
 
// Driver code
int main()
{
    memset(dp, -1, sizeof(dp));
    n = str.size();
    cout << "Total palindromic subsequence are : "
         << countPS(0, n - 1) << endl;
    return 0;
}

Output: 

Total palindromic subsequence are : 6
Time Complexity : O(N2), Auxiliary Space: O(N2)

Count of number of given string in 2D character array	
-------------------------------------------------------
Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array, such that individual characters can be present left to right, right to left, top to down or down to top.

Examples: 

Input : a ={
            {D,D,D,G,D,D},
            {B,B,D,E,B,S},
            {B,S,K,E,B,K},
            {D,D,D,D,D,E},
            {D,D,D,D,D,E},
            {D,D,D,D,D,G}
           }
        str= "GEEKS"
Output :2

Input : a = {
            {B,B,M,B,B,B},
            {C,B,A,B,B,B},
            {I,B,G,B,B,B},
            {G,B,I,B,B,B},
            {A,B,C,B,B,B},
            {M,C,I,G,A,M}
            }
        str= "MAGIC"

Output :3

Approach:

To count all occurrences, we follow simple brute force approach. 
Traverse through each character of the matrix and taking each character as a start of the string to be found. 
Try to search in all the possible directions. 
Whenever, a word is found, increase the count.
 After traversing the matrix what ever will be the value of count will be number of times string exists in character matrix.
Algorithm : 

Step 1– Traverse matrix character by character and take one character as string start 
Step 2– For each character find the string in all the four directions recursively 
Step 3– If a string found, we increase the count 
Step 4– When we are done with one character as start, we repeat the same process for the next character 
Step 5– Calculate the sum of count for each character 
Step 6– Final count will be the answer
Implementation:


// C++ code for finding count
// of string in a given 2D
// character array.
#include <bits/stdc++.h>
using namespace std;
 
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

// utility function to search
// complete string from any
// given index of 2d char array
int internalSearch(string needle, int row,
                   int col, string hay[],
                   int row_max, int col_max, int xx)
{
    int found = 0;
 
    if (row >= 0 && row <= row_max && col >= 0 &&
        col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;
 
        hay[row][col] = 0;
 
        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {
 
            // through Backtrack searching
            // in every directions
            found += internalSearch(needle, row,
                                    col + 1, hay,
                                    row_max, col_max,xx);
            found += internalSearch(needle, row, col - 1,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row + 1, col,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row - 1, col,
                                    hay, row_max, col_max,xx);
        }
        hay[row][col] = match;
    }
    return found;
}
 
// Function to search the string in 2d array
int searchString(string needle, int row, int col,
                  string str[], int row_count,
                                int col_count)
{
    int found = 0;
    int r, c;
 
    for (r = 0; r < row_count; ++r)
    {
        for (c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str,
                                    row_count - 1,
                                    col_count - 1, 0);
        }
    }
    return found;
}
 
// Driver code
int main()
{
    string needle = "MAGIC";
    string input[] = { "BBABBM",
                       "CBMBBA",
                       "IBABBG",
                       "GOZBBI",
                       "ABBBBC",
                       "MCIGAM" };
    string str[ARRAY_SIZE(input)];
    int i;
    for (i = 0; i < ARRAY_SIZE(input); ++i)
    {
        str[i] = input[i];
    }
 
    cout << "count: " << searchString(needle, 0, 0, str,
                                      ARRAY_SIZE(str),
                                      str[0].size()) << endl;
    return 0;
}

Output
count: 3
Time Complexity: O(n*m), where n is row size and m is the column size.
Auxiliary Space: O(n*m)

Search a Word in a 2D Grid of characters.	
----------------------------------------------
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
Example: 

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0
Explanation: 'GEEKS' can be found as prefix of
1st 2 rows and suffix of first row

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
Explanation: EEE can be found in first row 
twice at index 2 and index 10
and in second row at 2 and 12
Below diagram shows a bigger grid and presence of different words in it. 

Approach: The idea used here is simple, we check every cell. If cell has first character, then we one by one try all 8 directions from that cell for a match. Implementation is interesting though. We use two arrays x[] and y[] to find next move in all 8 directions. 

// C++ programs to search a word in a 2D grid
#include <bits/stdc++.h>
using namespace std;
 
// For searching in all 8 direction
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
 
// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char *grid, int row, int col,
               string word, int R, int C)
{
    // If first character of word doesn't
    // match with given starting point in grid.
    if (*(grid+row*C+col) != word[0])
        return false;
 
    int len = word.length();
 
    // Search word in all 8 directions
    // starting from (row, col)
    for (int dir = 0; dir < 8; dir++) {
        // Initialize starting point
        // for current direction
        int k, rd = row + x[dir], cd = col + y[dir];
 
        // First character is already checked,
        // match remaining characters
        for (k = 1; k < len; k++) {
            // If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            // If not matched,  break
            if (*(grid+rd*C+cd) != word[k])
                break;
 
            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
 
        // If all character matched, then value of k must
        // be equal to length of word
        if (k == len)
            return true;
    }
    return false;
}
 
// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char *grid, string word,
                  int R, int C)
{
    // Consider every point as starting
    // point and search given word
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern found at "
                     << row << ", "
                     << col << endl;
}
 
// Driver program
int main()
{
      int R = 3, C = 13;
    char grid[R][C] = { "GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };
 
    patternSearch((char *)grid, "GEEKS", R, C);
    cout << endl;
    patternSearch((char *)grid, "EEE", R, C);
    return 0;
}
Output: 

pattern found at 0, 0
pattern found at 0, 8
pattern found at 1, 0

pattern found at 0, 2
pattern found at 0, 10
pattern found at 2, 2
pattern found at 2, 12
Complexity Analysis:  

Time complexity: O(R*C*8*len(str)). 
All the cells will be visited and traversed in all 8 directions, where R and C is side of matrix so time complexity is O(R*C).
Auxiliary Space: O(1). 
As no extra space is needed.

Boyer Moore Algorithm for Pattern Searching
-----------------------------------------------
Given a text txt[0..n-1] and a pattern pat[0..m-1] where n is the length of the text and m is the length of the pattern, write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m. 
Examples: 

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
Boyer Moore is a combination of the following two approaches. 

Bad Character Heuristic 
Good Suffix Heuristic 
Both of the above heuristics can also be used independently to search a pattern in a text. Let us first understand how two independent approaches work together in the Boyer Moore algorithm. If we take a look at the Naive algorithm, it slides the pattern over the text one by one. KMP algorithm does preprocessing over the pattern so that the pattern can be shifted by more than one. The Boyer Moore algorithm does preprocessing for the same reason. It processes the pattern and creates different arrays for each of the two heuristics. At every step, it slides the pattern by the max of the slides suggested by each of the two heuristics. So it uses greatest offset suggested by the two heuristics at every step. 


Unlike the previous pattern searching algorithms, the Boyer Moore algorithm starts matching from the last character of the pattern.
In this post, we will discuss the bad character heuristic and the Good Suffix heuristic in the next post. 

 Bad Character Heuristic

The idea of bad character heuristic is simple. The character of the text which doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until – 

he mismatch becomes a match
Pattern P moves past the mismatched character.
Case 1 – Mismatch become match 
We will lookup the position of the last occurrence of the mismatched character in the pattern, and if the mismatched character exists in the pattern, then we’ll shift the pattern such that it becomes aligned to the mismatched character in the text T. 
 

Boyer Moore Algorithm for Pattern Searching
case 1

Explanation: In the above example, we got a mismatch at position 3. Here our mismatching character is “A”. Now we will search for last occurrence of “A” in pattern. We got “A” at position 1 in pattern (displayed in Blue) and this is the last occurrence of it. Now we will shift pattern 2 times so that “A” in pattern get aligned with “A” in text.

Case 2 – Pattern move past the mismatch character 
We’ll lookup the position of last occurrence of mismatching character in pattern and if character does not exist we will shift pattern past the mismatching character. 
 

Boyer Moore Algorithm for Pattern Searching
case2

Explanation: 

Here we have a mismatch at position 7. The mismatching character “C” does not exist in pattern before position 7 so we’ll shift pattern past to the position 7 and eventually in above example we have got a perfect match of pattern (displayed in Green). We are doing this because “C” does not exist in the pattern so at every shift before position 7 we will get mismatch and our search will be fruitless.

In the following implementation, we preprocess the pattern and store the last occurrence of every possible character in an array of size equal to alphabet size. If the character is not present at all, then it may result in a shift by m (length of pattern). Therefore, the bad character heuristic takes O(n/m)                     time in the best case. 
 
/* C++ Program for Bad Character Heuristic of Boyer
Moore String Matching Algorithm */
#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256
 
// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic( string str, int size,
                        int badchar[NO_OF_CHARS])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}
 
/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
 
    int badchar[NO_OF_CHARS];
 
    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; // s is shift of the pattern with
                // respect to text
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
 
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            cout << "pattern occurs at shift = " <<  s << endl;
 
            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
 
        }
 
        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += max(1, j - badchar[txt[s + j]]);
    }
}
 
/* Driver code */
int main()
{
    string txt= "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
Output
pattern occurs at shift = 4
Time Complexity : O(n x m)
Auxiliary Space: O(1)
The Bad Character Heuristic may take O(mn) time in worst case. The worst case occurs when all characters of the text and pattern are same. For example, txt[] = “AAAAAAAAAAAAAAAAAA” and pat[] = “AAAAA”. The Bad Character Heuristic may take O(n/m) in the best case. The best case occurs when all the characters of the text and pattern are different. 

Converting Roman Numerals to Decimal	
-------------------------------------------
Given a Roman numeral, the task is to find its corresponding decimal value.

Example : 

Input: IX
Output: 9
IX is a Roman symbol which represents 9 

Input: XL
Output: 40
XL is a Roman symbol which represents 40

Input: MCMIV
Output: 1904
M is a thousand, 
CM is nine hundred and 
IV is four

Roman numerals are based on the following symbols.  

SYMBOL       VALUE
  I            1
  IV           4
  V            5
  IX           9
  X            10
  XL           40
  L            50
  XC           90
  C            100
  CD           400
  D            500
  CM           900 
  M            1000
Approach: A number in Roman Numerals is a string of these symbols written in descending order(e.g. M’s first, followed by D’s, etc.). However, in a few specific cases, to avoid four characters being repeated in succession(such as IIII or XXXX), subtractive notation is often used as follows: 


I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10).
X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand).
Algorithm to convert Roman Numerals to Integer Number:  

Split the Roman Numeral string into Roman Symbols (character).
Convert each symbol of Roman Numerals into the value it represents.
Take symbol one by one from starting from index 0: 
If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
else subtract this value by adding the value of next symbol to the running total.
Following is the implementation of the above algorithm: 


// Program to convert Roman
// Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;
 
// This function returns value
// of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
 
// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;
 
    // Traverse given input
    for (int i = 0; i < str.length(); i++) {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);
 
        if (i + 1 < str.length()) {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);
 
            // Comparing both values
            if (s1 >= s2) {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}
 
// Driver Code
int main()
{
    // Considering inputs given are valid
    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
 
    return 0;
}
Output
Integer form of Roman Numeral is 1904
Complexity Analysis: 

Time Complexity: O(n), where n is the length of the string. 
Only one traversal of the string is required.
Space Complexity: O(1). 
As no extra space is required.

Another solution –
// Program to convert Roman
// Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;
 
// This function returns value
// of a Roman symbol
int romanToDecimal(string& str)
{
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[i + 1]])
        {
            sum+=m[str[i+1]]-m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}
 
// Driver Code
int main()
{
    // Considering inputs given are valid
    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
 
    return 0;
}
Output
Integer form of Roman Numeral is 1904
Time complexity – O(N)
Auxiliary Space – O(1)

Longest Common Prefix	
-------------------------------
Given a set of strings, find the longest common prefix. 

Examples: 

Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"

We start with an example. Suppose there are two strings- “geeksforgeeks” and “geeks”. What is the longest common prefix in both of them? It is “geeks”.
Now let us introduce another word “geek”. So now what is the longest common prefix in these three words ? It is “geek”
We can see that the longest common prefix holds the associative property, i.e- 

LCP(string1, string2, string3) 
         = LCP (LCP (string1, string2), string3)

Like here

LCP (“geeksforgeeks”, “geeks”, “geek”)
     =  LCP (LCP (“geeksforgeeks”, “geeks”), “geek”)
     =  LCP (“geeks”, “geek”) = “geek”
So we can make use of the above associative property to find the LCP of the given strings. We one by one calculate the LCP of each of the given string with the LCP so far. The final result will be our longest common prefix of all the strings.
Note that it is possible that the given strings have no common prefix. This happens when the first character of all the strings are not same.
We show the algorithm with the input strings- “geeksforgeeks”, “geeks”, “geek”, “geezer” by the below figure.















//  A C++ Program to find the longest common prefix
#include<bits/stdc++.h>
using namespace std;
 
// A Utility Function to find the common prefix between
// strings- str1 and str2
string commonPrefixUtil(string& str1, string& str2)
{
    string result = "";
    int len = min(str1.length(), str2.length());
 
    // Compare str1 and str2
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
            break;
        result += str1[i];
    }
 
    return (result);
}
 
// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix (string arr[], int n)
{
    string prefix =  arr[0];
 
    for (int i=1; i < n; i++)
        prefix = commonPrefixUtil(prefix, arr[i]);
 
    return (prefix);
}
 
// Driver program to test above function
int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    string ans = commonPrefix(arr, n);
 
    if (ans.length())
        printf ("The longest common prefix is - %s",
                 ans.c_str());
    else
        printf("There is no common prefix");
 
    return (0);
}
Output
The longest common prefix is - gee
Time Complexity : Since we are iterating through all the strings and for each string we are iterating though each characters, so we can say that the time complexity is O(N M) where, 

N = Number of strings
M = Length of the largest string
Auxiliary Space : To store the longest prefix string we are allocating space which is O(M).

Number of flips to make binary string alternate	
--------------------------------------------------
Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped. 

Examples : 

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1 

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.

Expected time complexity : O(n) where n is length of input string.

We can solve this problem by considering all possible results, As we are supposed to get alternate string, there are only 2 possibilities, alternate string starting with 0 and alternate string starting with 1. We will try both cases and choose the string which will require minimum number of flips as our final answer. 

Trying a case requires O(n) time in which we will loop over all characters of given string, if current character is expected character according to alternation then we will do nothing otherwise we will increase flip count by 1. After trying strings starting with 0 and starting with 1, we will choose the string with minimum flip count. 

Total time complexity of solution will be O(n) 

Implementation:

// C++ program to find minimum number of flip to make binary
// string alternate
#include <bits/stdc++.h>
using namespace std;
 
//  Utility method to flip a character
char flip(char ch) { return (ch == '0') ? '1' : '0'; }
 
//  Utility method to get minimum flips when alternate
//  string starts with expected char
int getFlipWithStartingCharcter(string str, char expected)
{
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++) {
        // if current character is not expected, increase
        // flip count
        if (str[i] != expected)
            flipCount++;
 
        //  flip expected character each time
        expected = flip(expected);
    }
    return flipCount;
}
 
// method return minimum flip to make binary string
// alternate
int minFlipToMakeStringAlternate(string str)
{
    //  return minimum of following two
    //  1) flips when alternate string starts with 0
    //  2) flips when alternate string starts with 1
    return min(getFlipWithStartingCharcter(str, '0'),
               getFlipWithStartingCharcter(str, '1'));
}
 
//  Driver code to test above method
int main()
{
    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}
 
Output
2
Time Complexity: O(N)
Auxiliary Space: O(1) 

Find the first repeated word in string
----------------------------------------
Given a string, Find the 1st repeated word in a string

Examples: 

Input : "Ravi had been saying that he had been there"
Output : had

Input : "Ravi had been saying that"
Output : No Repetition

Input : "he had had he"
Output : he

Simple Approach : Start iterating from back and for every new word , store it in unordered map . For every word which has occurred more than one  , update ans to be that word , at last reverse ans and print it.

Implementation:
// Cpp program to find first repeated word in a string
#include<bits/stdc++.h>
using namespace std;
void solve(string s)
{
    unordered_map<string,int> mp;  // to store occurrences of word
    string t="",ans="";
    // traversing from back makes sure that we get the word which repeats first as ans
    for(int i=s.length()-1;i>=0;i--)
    {
        // if char present , then add that in temp word string t
        if(s[i]!=' ')
        {
            t+=s[i];
             
        }
        // if space is there then this word t needs to stored in map
        else
        {
            mp[t]++;
            // if that string t has occurred previously then it is a possible ans
            if(mp[t]>1)
               ans=t;
            // set t as empty for again new word  
            t="";
             
        }
    }
     
    // first word like "he" needs to be mapped
            mp[t]++;
            if(mp[t]>1)
               ans=t;
                           
    if(ans!="")
    {
        // reverse ans string as it has characters in reverse order
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    else
    cout<<"No Repetition\n";
}
int main()
{
    string u="Ravi had been saying that he had been there";
    string v="Ravi had been saying that";
    string w="he had had he";
    solve(u);
    solve(v);
    solve(w);
     
     
    return 0;
     
}
Output
had
No Repetition
he
Another Approach: The idea is to tokenize the string and store each word and its count in hashmap. Then traverse the string again and for each word of string, check its count in created hashmap. 

Implementation:
// CPP program for finding first repeated
// word in a string
#include <bits/stdc++.h>
using namespace std;
 
// returns first repeated word
string findFirstRepeated(string s)
{
    // break string into tokens
    // and then each string into set
    // if a word appeared before appears
    // again, return the word and break
 
    istringstream iss(s);
    string token;
 
    // hashmap for storing word and its count
    // in sentence
    unordered_map<string, int> setOfWords;
 
    // store all the words of string
    // and the count of word in hashmap
 
    while (getline(iss, token, ' ')) {
        if (setOfWords.find(token) != setOfWords.end())            
            setOfWords[token] += 1;  // word exists
        else
            // insert new word to set
            setOfWords.insert(make_pair(token, 1));       
    }
 
    // traverse again from first word of string s
    // to check if count of word is greater than 1
 
    // either take a new stream or store the words
    // in vector of strings in previous loop
    istringstream iss2(s);
    while (getline(iss2, token, ' ')) {
        int count = setOfWords[token];
        if (count > 1) {
            return token;
        }
    }
 
    return "NoRepetition";
}
 
// driver program
int main()
{
    string s("Ravi had been saying that he had been there");
    string firstWord = findFirstRepeated(s);
    if (firstWord != "NoRepetition")
        cout << "First repeated word :: "
             << firstWord << endl;
    else
        cout << "No Repetitionn";
    return 0;
}
Output
First repeated word :: had

Minimum number of swaps for bracket balancing
----------------------------------------------------
You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the form S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.

Examples: 

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
The string is already balanced.

We can solve this problem by using greedy strategies. If the first X characters form a balanced string, we can neglect these characters and continue on. If we encounter a ‘]’ before the required ‘[‘, then we must start swapping elements to balance the string.

Naive Approach 
Initialize sum = 0 where sum stores result. Go through the string maintaining a count of the number of ‘[‘ brackets encountered. Reduce this count when we encounter a ‘]’ character. If the count hits negative, then we must start balancing the string. 
Let index ‘i’ represent the position we are at. We now move forward to the next ‘[‘ at index j. Increase sum by j – i. Move the ‘[‘ at position j, to position i, and shift all other characters to the right. Set the count back to 0 and continue traversing the string. In the end, ‘sum’ will have the required value.


Time Complexity = O(N^2) 
Extra Space = O(1)

Optimized approach 
We can initially go through the string and store the positions of ‘[‘ in a vector say ‘pos‘. Initialize ‘p’ to 0. We shall use p to traverse the vector ‘pos’. Similar to the naive approach, we maintain a count of encountered ‘[‘ brackets. When we encounter a ‘[‘ we increase the count and increase ‘p’ by 1. When we encounter a ‘]’ we decrease the count. If the count ever goes negative, this means we must start swapping. The element pos[p] tells us the index of the next ‘[‘. We increase the sum by pos[p] – i, where i is the current index. We can swap the elements in the current index and pos[p] and reset the count to 0 and increment p so that it pos[p] indicates to the next ‘[‘.
Since we have converted a step that was O(N) in the naive approach, to an O(1) step, our new time complexity reduces. 

Time Complexity = O(N) 
Extra Space = O(N)

// C++ program to count swaps required to balance string
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Function to calculate swaps required
long swapCount(string s)
{
    // Keep track of '['
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);
 
    int count = 0; // To count number of encountered '['
    int p = 0;  // To track position of next '[' in pos
    long sum = 0; // To store result
 
    for (int i = 0; i < s.length(); ++i)
    {
        // Increment count and move p to next position
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
            --count;
 
        // We have encountered an unbalanced part of string
        if (count < 0)
        {
            // Increment sum by number of swaps required
            // i.e. position of next '[' - current position
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;
 
            // Reset count to 1
            count = 1;
        }
    }
    return sum;
}
 
// Driver code
int main()
{
    string s = "[]][][";
    cout << swapCount(s) << "\n";
 
    s = "[[][]]";
    cout << swapCount(s) << "\n";
    return 0;
}
Output:  
2
0
Time Complexity: O(N) 
Auxiliary Space: O(1) 
Another Method: 
We can do without having to store the positions of ‘[‘. 

// C++ program to count swaps required
// to balance string
#include <bits/stdc++.h>
using namespace std;
 
long swapCount(string chars)
{
     
    // Stores total number of Left and
    // Right brackets encountered
    int countLeft = 0, countRight = 0;
     
    // swap stores the number of swaps
    // required imbalance maintains
    // the number of imbalance pair
    int swap = 0 , imbalance = 0;
      
    for(int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {
             
            // Increment count of Left bracket
            countLeft++;
             
            if (imbalance > 0)
            {
                 
                // swaps count is last swap count + total
                // number imbalanced brackets
                swap += imbalance;
                 
                // imbalance decremented by 1 as it solved
                // only one imbalance of Left and Right
                imbalance--;    
            }
        }
        else if(chars[i] == ']' )
        {
             
            // Increment count of Right bracket
            countRight++;
             
            // imbalance is reset to current difference
            // between Left and Right brackets
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}
 
// Driver code 
int main()
{
    string s = "[]][][";
    cout << swapCount(s) << endl;
 
    s = "[[][]]";
    cout << swapCount(s) << endl;
 
    return 0;
}
Output
2
0
Time Complexity :O(N) 
Auxiliary Space : O(1) 

Find the longest common subsequence between two strings
---------------------------------------------------------
Examples: 
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem. 

1) Optimal Substructure: 
Let the input sequences be X[0..m-1] and Y[0..n-1] of lengths m and n respectively. And let L(X[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y. Following is the recursive definition of L(X[0..m-1], Y[0..n-1]).

If last characters of both sequences match (or X[m-1] == Y[n-1]) then 
L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])

If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then 
L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2]) )

Examples: 
1) Consider the input strings “AGGTAB” and “GXTXAYB”. Last characters match for the strings. So length of LCS can be written as: 
L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”) 

2) Consider the input strings “ABCDGH” and “AEDFHR. Last characters do not match for the strings. So length of LCS can be written as: 
L(“ABCDGH”, “AEDFHR”) = MAX ( L(“ABCDG”, “AEDFHR”), L(“ABCDGH”, “AEDFH”) )
So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.


2) Overlapping Subproblems: 
Following is simple recursive implementation of the LCS problem. The implementation simply follows the recursive structure mentioned above. 


/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h> 
using namespace std; 
  
  
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n ) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m-1] == Y[n-1]) 
        return 1 + lcs(X, Y, m-1, n-1); 
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
  
  
  
/* Driver code */
int main() 
{ 
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
      
    int m = strlen(X); 
    int n = strlen(Y); 
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ; 
      
    return 0; 
} 
  
// This code is contributed by rathbhupendra
Output
Length of LCS is 4
Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0. 

Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

                         lcs("AXYT", "AYZX")
                       /                     \
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
In the above partial recursion tree, lcs(“AXY”, “AYZ”) is being solved twice. If we draw the complete recursion tree, then we can see that there are many subproblems which are solved again and again. So this problem has Overlapping Substructure property and recomputation of same subproblems can be avoided by either using Memoization or Tabulation. 

Following is a Memoization implementation for the LCS problem. 


/* A Top-Down DP implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char* X, char* Y, int m, int n,
        vector<vector<int> >& dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
  
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
}
  
/* Driver code */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
  
    int m = strlen(X);
    int n = strlen(Y);
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    cout << "Length of LCS is " << lcs(X, Y, m, n, dp);
  
    return 0;
}
Output
Length of LCS is 4
Time Complexity : O(mn) ignoring recursion stack space

Following is a tabulated implementation for the LCS problem. 


/* Dynamic Programming C implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
    // intitalizing a matrix of size (m+1)*(n+1)
    int L[m + 1][n + 1];
  
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
        that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
  
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
  
    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
    return L[m][n];
}
  
// Driver program to test above function 
int main()
{
      
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
  
    int m = strlen(X);
    int n = strlen(Y);
  
    cout << "Length of LCS is: " << lcs(X, Y, m, n);
  
    return 0;
}
Output
Length of LCS is  4
Time Complexity of the above implementation is O(mn) which is much better than the worst-case time complexity of Naive Recursive implementation. 
The above algorithm/code returns only length of LCS. Please see the following post for printing the LCS. 

Program to generate all possible valid IP addresses from given  string
--------------------------------------------------------------------------
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Examples :

Input: 25525511135
Output: [“255.255.11.135”, “255.255.111.35”]
Explanation:
These are the only valid possible
IP addresses.

Input: "25505011535"
Output: []
Explanation: 
We cannot generate a valid IP
address with this string.
First, we will place 3 dots in the given string and then try out all the possible combinations for the 3 dots. 
Corner case for validity:

For string "25011255255"
25.011.255.255 is not valid as 011 is not valid.
25.11.255.255 is not valid either as you are not
allowed to change the string.
250.11.255.255 is valid.

Approach: Split the string with ‘ . ‘ and then check for all corner cases. Before entering the loop, check the size of the string. Generate all the possible combinations using looping through the string. If IP is found to be valid then return the IP address, else simply return the empty list.

// C++ program to generate all possible
// valid IP addresses from given string
#include <bits/stdc++.h>
using namespace std;
 
// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        }
        else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
 
    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++) {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3
            || stoi(ips[i]) < 0
            || stoi(ips[i]) > 255)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) == 0)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
            return 0;
    }
    return 1;
}
 
// Function converts string to IP address
void convert(string ip)
{
    int l = ip.length();
 
    // Check for string size
    if (l > 12 || l < 4) {
        cout << "Not Valid IP Address";
    }
 
    string check = ip;
    vector<string> ans;
 
    // Generating different combinations.
    for (int i = 1; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1; k < l; k++) {
                check = check.substr(0, k) + "."
                        + check.substr(k);
                check
                    = check.substr(0, j) + "."
                      + check.substr(j);
                check
                    = check.substr(0, i) + "."
                      + check.substr(i);
 
                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check)) {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}
 
// Driver code
int main()
{
    string A = "25525511135";
    string B = "25505011535";
 
    convert(A);
    convert(B);
 
    return 0;
}
Output
255.255.11.135
255.255.111.35
Complexity Analysis:

Time Complexity: O(n^3), where n is the length of the string 
Three nested traversal of the string is needed, where n is always less than 12.
Auxiliary Space: O(n). 
As extra space is needed.

Another Approach: (Using Recursion)

#include <iostream>
#include <vector>
using namespace std;
 
void solve(string s, int i, int j, int level, string temp,
           vector<string>& res)
{
    if (i == (j + 1) && level == 5) {
        res.push_back(temp.substr(1));
    }
 
    // Digits of a number ranging 0-255 can lie only between
    // 0-3
    for (int k = i; k < i + 3 && k <= j; k++) {
        string ad = s.substr(i, k - i + 1);
 
        // Return if string starting with '0' or it is
        // greater than 255.
        if ((s[i] == '0'&&ad.size()>1) || stol(ad) > 255)
            return;
 
        // Recursively call for another level.
        solve(s, k + 1, j, level + 1, temp + '.' + ad, res);
    }
}
 
int main()
{
    string s = "25525511135";
    int n = s.length();
 
    vector<string> ans;
 
    solve(s, 0, n - 1, 1, "", ans);
 
    for (string s : ans)
        cout << s << endl;
 
    return 0;
}
Output
255.255.11.135
255.255.111.35

The smallest window that contains all characters of string itself
-------------------------------------------------------------------
Given a string, find the smallest window length with all distinct characters of the given string. For eg. str = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca” .
Examples: 

Input: aabcbcdbca
Output: dbca
Explanation: 
Possible substrings= {aabcbcd, abcbcd, 
bcdbca, dbca....}
Of the set of possible substrings 'dbca' 
is the shortest substring having all the 
distinct characters of given string. 

Input: aaab
Output: ab
Explanation: 
Possible substrings={aaab, aab, ab}
Of the set of possible substrings 'ab' 
is the shortest substring having all 
the distinct characters of given string.

Solution: Above problem states that we have to find the smallest window that contains all the distinct characters of the given string even if the smallest string contains repeating elements. 
For example, in “aabcbcdb”, the smallest string that contains all the characters is “abcbcd”.

Method 1: This is the Brute Force method of solving the problem using HashMap.

Approach : For solving the problem we first have to find out all the distinct characters present in the string. This can be done using a HashMap. The next thing is to generate all the possible substrings. This follows by checking whether a substring generated has all the required characters(stored in the hash_map) or not. If yes, then compare its length with the minimum substring length which follows the above constraints, found till now.
HashMap: HashMap is a part of Java’s collection since Java 1.2. It provides the basic implementation of the Map interface of Java. It stores the data in (Key, Value) pairs. To access a value one must know its key. HashMap is known as HashMap because it uses a technique called Hashing. Hashing is a technique of converting a large String to small String that represents the same String. A shorter value helps in indexing and faster searches. HashSet also uses HashMap internally. It internally uses a link list to store key-value pairs already explained in HashSet in detail and further articles. 

Algorithm : 

Store all distinct characters of the given string in a hash_map.
Take a variable count and initialize it with value 0.
Generate the substrings using two pointers.
Now check whether generated substring is valid or not-: 
As soon we find that the character of the substring generated has not been encountered before, increment count by 1.
We can use a visited array of max_chars size to find whether the current character has been encountered before or not.
If count is equal to equal to size of hash_map the substring generated is valid
If it is a valid substring, compare it with the minimum length substring already generated.
Pseudo Code:

maphash_map;
for ( i=0 to str.length())
hash_map[str[i]]++;//finding all distinct characters of string
minimum_size=INT_MAX
Distinct_chars=hash_map.size()
for(i=0 to str.length())
count=0;
sub_str="";
visited[256]={0};
 for(j=i to n)
   sub_str+=str[j]
   if(visited[str[j]]==0)
   count++
   visited[str[j]]=1;
   if(count==Distinct_chars)
   end loop

if(sub_str.length()<minimum_size&&
count==Distinct_chars)
ans=sub_str;
  
return ans

Implementation:

// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHARS = 256;
 
// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
    int n = str.length();
 
    // Count all distinct characters.
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++) {
        hash_map[str[i]]++;
    }
 
    dist_count = hash_map.size();
    int size = INT_MAX;
    string res;
    // Now follow the algorithm discussed in below
    for (int i = 0; i < n; i++) {
        int count = 0;
        int visited[256] = { 0 };
        string sub_str = "";
        for (int j = i; j < n; j++) {
            if (visited[str[j]] == 0) {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size=res.length();
        }
    }
    return res;
}
 
// Driver Code
int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}
Output
Smallest window containing all distinct characters is: dbca
Complexity Analysis: 

Time Complexity: O(N^2). 
This time is required to generate all possible sub-strings of a string of length “N”.
Space Complexity: O(N). 
As a hash_map has been used of size N.
Method 2: Here we have used Sliding Window technique to arrive at the solution. This technique shows how a nested for loop in few problems can be converted to single for loop and hence reducing the time complexity.

Approach: Basically a window of characters is maintained by using two pointers namely start and end. These start and end pointers can be used to shrink and increase the size of window respectively. Whenever the window contains all characters of given string, the window is shrinked from left side to remove extra characters and then its length is compared with the smallest window found so far. 
If in the present window, no more characters can be deleted then we start increasing the size of the window using the end until all the distinct characters present in the string are also there in the window. Finally, find the minimum size of each window.

Algorithm : 

Maintain an array (visited) of maximum possible characters (256 characters) and as soon as we find any in the string, mark that index in the array (this is to count all distinct characters in the string).
Take two pointers start and end which will mark the start and end of window.
Take a counter=0 which will be used to count distinct characters in the window.
Now start reading the characters of the given string and if we come across a character which has not been visited yet increment the counter by 1.
If the counter is equal to total number of distinct characters, Try to shrink the window.
For shrinking the window -: 
If the frequency of character at start pointer is greater than 1 increment the pointer as it is redundant.
Now compare the length of present window with the minimum window length.
Implementation:


// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;
 
const int MAX_CHARS = 256;
 
// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
    int n = str.length();
 
    // if string is empty or having one char
    if (n <= 1)
        return str;
 
    // Count all distinct characters.
    int dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
 
    // Now follow the algorithm discussed in below
    // post. We basically maintain a window of characters
    // that contains all characters of given string.
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    int count = 0;
    int curr_count[MAX_CHARS] = { 0 };
    for (int j = 0; j < n; j++) {
        // Count occurrence of characters of string
        curr_count[str[j]]++;
 
        // If any distinct character matched,
        // then increment count
        if (curr_count[str[j]] == 1)
            count++;
 
        // if all the characters are matched
        if (count == dist_count) {
            // Try to minimize the window i.e., check if
            // any character is occurring more no. of times
            // than its occurrence in pattern, if yes
            // then remove it from starting and also remove
            // the useless characters.
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }
 
            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}
 
// Driver code
int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}
Output
Smallest window containing all distinct characters is: dbca
Complexity Analysis: 

Time Complexity: O(N). 
As the string is traversed using two pointers only once.
Space Complexity: O(N). 
As a hash_map is used of size N

Rearrange characters in a string such that no two adjacent are same	
------------------------------------------------------------------------
Given a string with lowercase repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are the same. If it is not possible to do so, then print “Not possible”.

Examples: 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible

The idea is to put the highest frequency character first (a greedy approach). Use a priority queue (Or Binary Max Heap) and put all characters and ordered by their frequencies (highest frequency character at root). One by one take the highest frequency character from the heap and add it to result. After adding it, just decrease the frequency of the character and then temporarily move this character out of priority queue so that it is not picked again next time.

Follow the given steps to solve the problem:

Build a Priority_queue or max_heap, pq that stores characters with their frequencies. 
Priority_queue or max_heap is built on the bases of the frequency of character. 
Create a temporary Key that will be used as the previously visited element (the previous element in the resultant string. Initialize it { char = ‘#’ , freq = ‘-1’ } 
While pq is not empty. 
Pop an element and add it to the result. 
Decrease the frequency of the popped element by ‘1’ 
Push the previous element back into the priority_queue if its frequency is greater than zero. 
Make the current element as the previous element for the next iteration. 
If the length of the resultant string and the original string is not equal, then print “not possible”, else print the resultant string.

// C++ program to rearrange characters in a string
// so that no two adjacent characters are same.
 
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
 
struct Key {
 
    int freq; // store frequency of character
    char ch;
 
    // Function for priority_queue to store Key
    // according to freq
    bool operator<(const Key& k) const
    {
        return freq < k.freq;
    }
};
 
// Function to rearrange character of a string
// so that no char repeat twice
void rearrangeString(string str)
{
    int N = str.length();
 
    // Store frequencies of all characters in string
    int count[MAX_CHAR] = { 0 };
    for (int i = 0; i < N; i++)
        count[str[i] - 'a']++;
 
    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++) {
        int val = c - 'a';
        if (count[val]) {
            pq.push(Key{ count[val], c });
        }
    }
 
    // 'str' that will store resultant value
    str = "";
 
    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev{ -1, '#' };
 
    // traverse queue
    while (!pq.empty()) {
        // pop top element from queue and add it
        // to string.
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;
 
        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);
 
        // Make current character as the previous 'char'
        // decrease frequency by 'one'
        (k.freq)--;
        prev = k;
    }
 
    // If length of the resultant string and original
    // string is not same then string is not valid
    if (N != str.length())
        cout << " Not possible " << endl;
 
    else // valid string
        cout << str << endl;
}
 
// Driver's code
int main()
{
    string str = "bbbaa";
 
    // Function call
    rearrangeString(str);
    return 0;
}
Output
babab
Time complexity : O(N log(N))
Auxiliary Space: O(N), Extra space is used to store the resultant string

Rearrange characters in a String such that no two adjacent characters are same using Frequency:
To solve the problem using this approach follow the below idea:

Fill all the even positions of the result string first, with the highest frequency character. If there are still some even positions remaining, fill them first. Once even positions are done, then fill the odd positions. This way, it can be ensured that no two adjacent characters are the same. 

Follow the given steps to solve the problem:

Calculate the frequencies of every character in the input string
If a character with a maximum frequency has a frequency greater than (n + 1) / 2, then return an empty string, as it is not possible to construct a string
Now fill the even index positions with the maximum frequency character, if some even positions are remaining then first fill them with remaining characters
Then fill odd index positions with the remaining characters
Return the constructed string

// C++ code for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
char getMaxCountChar(vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}
 
string rearrangeString(string S)
{
    int N = S.size();
    if (N == 0)
        return "";
 
    vector<int> count(26, 0);
    for (auto& ch : S)
        count[ch - 'a']++;
 
    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];
 
    // check if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";
 
    string res(n, ' ');
    int ind = 0;
 
    // filling the most frequently occurring char in the
    // even indices
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
 
    count[ch_max - 'a'] = 0;
 
    // now filling the other Chars, first
    // filling the even positions and then
    // the odd positions
    for (int i = 0; i < 26; i++) {
 
        while (count[i] > 0) {
 
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
 
    return res;
}
// Driver's code
int main()
{
    string str = "bbbaa";
 
    // Function call
    string res = rearrangeString(str);
    if (res == "")
        cout << "Not possible" << endl;
    else
        cout << res << endl;
 
    return 0;
}
Output
babab 
Time complexity: O(N)
Auxiliary Space: O(N+26), as there are 26 lowercase english characters

Minimum characters to be added at front to make string palindrome	
-------------------------------------------------------------------

Given string str we need to tell minimum characters to be added in front of the string to make string palindrome.

Examples: 

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.

Naive approach: Start checking the string each time if it is a palindrome and if not, then delete the last character and check again. When the string gets reduced to either a palindrome or an empty string then the number of characters deleted from the end till now will be the answer as those characters could have been inserted at the beginning of the original string in the order which will make the string a palindrome.

// C++ program for getting minimum character to be
// added at front to make string palindrome
#include<bits/stdc++.h>
using namespace std;
 
// function for checking string is palindrome or not
bool ispalindrome(string s)
{
    int l = s.length();
    int j;
     
    for(int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}
 
// Driver code
int main()
{
    string s = "BABABAA";
    int cnt = 0;
    int flag = 0;
     
    while(s.length()>0)
    {
        // if string becomes palindrome then break
        if(ispalindrome(s))
        {
            flag = 1;
             break;
        }
        else
        {
        cnt++;
         
        // erase the last element of the string
        s.erase(s.begin() + s.length() - 1);
        }
    }
     
    // print the number of insertion at front
    if(flag)
        cout << cnt;
}
Output
2
Time complexity: O(n2)
Auxiliary Space: O(1)

Efficient approach: We can solve this problem efficiently in O(n) time using lps array of KMP algorithm. 
First, we concat string by concatenating the given string, a special character and reverse of given string then we will get lps array for this concatenated string, recall that each index of lps array represents the longest proper prefix which is also a suffix. We can use this lps array to solve the problem. 

For string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
                   0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
Here we are only interested in the last value of this lps array because it shows us the largest suffix of the reversed string that matches the prefix of the original string i.e these many characters already satisfy the palindrome property. Finally minimum number of characters needed to make the string a palindrome is the length of the input string minus the last entry of our lps array. 

// C++ program for getting minimum character to be
// added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;
 
// returns vector lps for given string str
vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
 
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
 
    // Get concatenation of string, special character
    // and reverse string
    string concat = str + "$" + revStr;
 
    //  Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(concat);
 
    // By subtracting last entry of lps vector from
    // string length, we will get our result
    return (str.length() - lps.back());
}
 
// Driver program to test above functions
int main()
{
    string str = "AACECAAAA";
    cout << getMinCharToAddedToMakeStringPalin(str);
    return 0;
}
Output
2
Time Complexity: O(n)
Auxiliary Space: O(n)

Given a sequence of words, print all anagrams together	
--------------------------------------------------------
Given an array of words, print all anagrams together. 

For example, 

Input: array = {“cat”, “dog”, “tac”, “god”, “act”}
output: cat tac act, dog god
Explanation: cat tac and act are anagrams 
and dog and god are anagrams as 
they have the same set of characters.

Input: array = {“abc”, “def”, “ghi”}
output: abc, def, ghi
Explanation: There are no anagrams in the array.

Approach: This is a HashMap solution using C++ Standard Template Library which stores the Key-Value Pair. In the hashmap, the key will be the sorted set of characters and value will be the output string. Two anagrams will be similar when their characters are sorted. Now,  


Store the vector elements in HashMap with key as the sorted string.
If the key is same, then add the string to the value of HashMap(string vector).
Traverse the HashMap and print the anagram strings.

Implementation:

// C++ program for finding all anagram
// pairs in the given array
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
 
// Utility function for
// printing anagram list
void printAnagram(unordered_map<string,vector<string> >& store)
{
    for (auto it:store)
    {
        vector<string> temp_vec(it.second);
        int size = temp_vec.size();
       
        for (int i = 0; i < size; i++)
        cout << temp_vec[i] << " ";
           
        cout << "\n";
    }
}
 
// Utility function for storing
// the vector of strings into HashMap
void storeInMap(vector<string>& vec)
{
    unordered_map<string,vector<string> > store;
   
    for (int i = 0; i < vec.size(); i++)
    {
        string tempString(vec[i]);
       
          // sort the string
        sort(tempString.begin(),tempString.end());
       
          // make hash of a sorted string
        store[tempString].push_back(vec[i]);
    }
 
    // print utility function for printing
    // all the anagrams
    printAnagram(store);
}
 
// Driver code
int main()
{
    // initialize vector of strings
    vector<string> arr;
    arr.push_back("geeksquiz");
    arr.push_back("geeksforgeeks");
    arr.push_back("abcd");
    arr.push_back("forgeeksgeeks");
    arr.push_back("zuiqkeegs");
    arr.push_back("cat");
    arr.push_back("act");
    arr.push_back("tca");
 
    // utility function for storing
    // strings into hashmap
    storeInMap(arr);
    return 0;
}
Output
cat act tca 
abcd 
geeksquiz zuiqkeegs 
geeksforgeeks forgeeksgeeks 

Complexity Analysis: 

Time Complexity: O(n * m(log m)),  where m is the length of a word.
A single traversal through the array is needed.
Space Complexity: O(n). 
There are n words in a string. The map requires O(n) space to store the strings.

Find the smallest window in a string containing all characters of another string	
----------------------------------------------------------------------------------
Given two strings, string and pattern, the task is to find the smallest substring in string containing all characters of pattern. 

Examples: 

Input: string = “this is a test string”, pattern = “tist” 
Output: “t stri” 
Explanation: “t stri” contains all the characters of pattern.

Input: string = “geeksforgeeks”, pattern = “ork” 
Output: “ksfor”

Naive Approach:

Generate all substrings of string.
For each substring, check whether the substring contains all characters of pattern (“tist”) 
Finally, print the smallest substring containing all characters of pattern.
Time Complexity: O(N3)
Auxiliary Space: O(N) to create substrings.

Using Hashing:

The idea is to use the two pointer approach on the hash array of pattern string and then find the minimum window by eliminating characters from the start of the window.

Follow the steps below to solve the problem:

First check if the length of the string is less than the length of the given pattern, if yes then “no such window can exist “.
Store the occurrence of characters of the given pattern in a hash array (say, hash_pat[]).
We will be using two pointer technique basically
Start matching the characters of the pattern with the characters of the string i.e. increment count if a character matches.
Check if (count == length of pattern ) this means a window is found.
If such a window is found, try to minimize it by removing extra characters from the beginning of the current window.
Delete one character from the first and again find this deleted key at right.
If found, then again check if count and pattern length are same and repeat the process.
Update min_length.
Print the minimum length window.
See the image below for a better understanding:

Illustration:
















Below is the implementation of the above aapproach.

// C++ program to find
// smallest window containing
// all characters of a pattern.
#include <bits/stdc++.h>
using namespace std;
 
const int no_of_chars = 256;
 
// Function to find smallest
// window containing
// all characters of 'pat'
string findSubString(string str, string pat)
{
    int len1 = str.length();
    int len2 = pat.length();
 
    // Check if string's length
    // is less than pattern's
    // length. If yes then no such
    // window can exist
    if (len1 < len2) {
        cout << "No such window exists";
        return "";
    }
 
    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };
 
    // Store occurrence ofs characters
    // of pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;
 
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    // Start traversing the string
    // Count of characters
    int count = 0;
    for (int j = 0; j < len1; j++) {
       
        // Count occurrence of characters
        // of string
        hash_str[str[j]]++;
 
        // If string's char matches with
        // pattern's char
        // then increment count
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;
 
        // if all the characters are matched
        if (count == len2) {
           
            // Try to minimize the window
            while (hash_str[str[start]]
                       > hash_pat[str[start]]
                   || hash_pat[str[start]] == 0) {
 
                if (hash_str[str[start]]
                    > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
 
            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // If no window found
    if (start_index == -1) {
        cout << "No such window exists";
        return "";
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}
 
// Driver code
int main()
{
    string str = "this is a test string";
    string pat = "tist";
 
    cout << findSubString(str, pat);
    return 0;
}
Output
t stri
Time Complexity:  O(N), where N is the length of string. 
Auxiliary Space: O(1)

Recursively remove all adjacent duplicates
-----------------------------------------------
Given a string S, The task is to remove all the consecutive duplicate characters of the string and return the resultant string. 

Examples: 

Input: S= “aaaaabbbbbb”
Output: ab

Input: S = “geeksforgeeks”
Output: geksforgeks

Input: S = “aabccba”
Output: abcba

using recursion:
Approach:

If the string is not empty compare the adjacent characters of the string. If they are the same then shift the characters one by one to the left. Call recursion on string S otherwise, call recursion from S+1 string.

Follow the below steps to implement the idea:

If the string is empty, return.
Else compare the adjacent characters of the string. If they are the same then shift the characters one by one to the left. Call recursion on string S
If they are not same then call recursion from S+1 string.
Illustration:

The recursion tree for the string S = aabcca is shown below.

                                                   aabcca    S = aabcca
                                                   /
                                             abcca            S = abcca        
                                             /
                                          bcca                 S = abcca
                                          /
                                     cca                        S = abcca
                                    /
                               ca                                S = abca
                              /
                           a                                     S = abca (Output String)
                         /
                  empty string

// Recursive Program to remove consecutive
// duplicates from string S.
#include <bits/stdc++.h>
using namespace std;
  
// A recursive function that removes
// consecutive duplicates from string S
void removeDuplicates(char* S)
{
    // When string is empty, return
    if (S[0] == '\0')
        return;
  
    // if the adjacent characters are same
    if (S[0] == S[1]) {
  
        // Shift character by one to left
        int i = 0;
        while (S[i] != '\0') {
            S[i] = S[i + 1];
            i++;
        }
  
        // Check on Updated String S
        removeDuplicates(S);
    }
  
    // If the adjacent characters are not same
    // Check from S+1 string address
    removeDuplicates(S + 1);
}
  
// Driver Program
int main()
{
    char S1[] = "geeksforgeeks";
    removeDuplicates(S1);
    cout << S1 << endl;
  
    char S2[] = "aabcca";
    removeDuplicates(S2);
    cout << S2 << endl;
  
    return 0;
}
Output
geksforgeks
abca
Time complexity: O(N2)
Auxiliary Space: O(1)

Using Iterative approach:
The idea is to check if current character is equal to the next character or not . If current character is equal to the next character we’ll ignore it and when it is not equal we will add it to our answer. At last add the last character.

Follow the below steps to implement the idea:

Create an str string to store the result
Iterate form 0 to string length – 2.
If the current character is not equal to next character then add it to answer string.
Else continue.
return str.

// C++ program to remove consecutive
// duplicates from a given string.
#include <bits/stdc++.h>
using namespace std;
  
// A iterative function that removes
// consecutive duplicates from string S
string removeDuplicates(string s)
{
  
    int n = s.length();
    string str = "";
    // We don't need to do anything for
    // empty string.
    if (n == 0)
        return str;
  
    // Traversing string
    for (int i = 0; i < n - 1; i++) {
        // checking if s[i] is not same as s[i+1] then add
        // it into str
        if (s[i] != s[i + 1]) {
            str += s[i];
        }
    }
    // Since the last character will not be inserted in the
    // loop we add it at the end
    str.push_back(s[n - 1]);
    return str;
}
  
// Driver Program
int main()
{
  
    string s1 = "geeksforgeeks";
    cout << removeDuplicates(s1) << endl;
  
    string s2 = "aabcca";
    cout << removeDuplicates(s2) << endl;
  
    return 0;
}
Output
geksforgeks
abca
Time Complexity: O(N) 
Auxiliary Space: O(1)

String matching where one string contains wildcard characters	
----------------------------------------------------------------
Given two strings where first string may contain wild card characters and second string is a normal string. Write a function that returns true if the two strings match. The following are allowed wild card characters in first string. 

* --> Matches with 0 or more instances of any character or set of characters.
? --> Matches with any one character.
For example, “g*ks” matches with “geeks” match. And string “ge?ks*” matches with “geeksforgeeks” (note ‘*’ at the end of first string). But “g*k” doesn’t match with “gee” as character ‘k’ is not present in second string. 

// A C program to match wild card characters
#include <stdbool.h>
#include <stdio.h>
 
// The main function that checks if two given strings
// match. The first string may contain wildcard characters
bool match(char* first, char* second)
{
    // If we reach at the end of both strings, we are done
    if (*first == '\0' && *second == '\0')
        return true;
 
    // Make sure to eliminate consecutive '*'
    if (*first == '*') {
        while (*(first + 1) == '*')
            first++;
    }
 
    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the
    // first string will not contain two consecutive '*'
    if (*first == '*' && *(first + 1) != '\0'
        && *second == '\0')
        return false;
 
    // If the first string contains '?', or current
    // characters of both strings match
    if (*first == '?' || *first == *second)
        return match(first + 1, second + 1);
 
    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*first == '*')
        return match(first + 1, second)
               || match(first, second + 1);
    return false;
}
 
// A function to run test cases
void test(char* first, char* second)
{
    match(first, second) ? puts("Yes") : puts("No");
}
 
// Driver program to test above functions
int main()
{
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee"); // No because 'k' is not in second
    test("*pqrs",
         "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have
                             // 2 instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    test("geeks**", "geeks"); // Yes
 
    return 0;
}
Output: 
Yes
Yes
No
No
Yes
No
Yes
Yes
Yes
Time Complexity: O(n)
Auxiliary Space: O(1)

Function to find Number of customers who could not get a computer	
-------------------------------------------------------------------
Write a function “runCustomerSimulation” that takes following two inputs 

An integer ‘n’: total number of computers in a cafe and a string: 
A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer. 
A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times. 
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.
runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0
runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.
runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.

Below are simple steps to find number of customers who could not get any computer.

Initialize result as 0.
Traverse the given sequence. While traversing, keep track of occupied computers (this can be done by keeping track of characters which have appeared only once and a computer was available when they appeared). At any point, if count of occupied computers is equal to ‘n’, and there is a new customer, increment result by 1.
The important thing is to keep track of existing customers in cafe in a way that can indicate whether the customer has got a computer or not. Note that in sequence “ABCBCADEED”, customer ‘B’ did not get a seat, but still in cafe as a new customer ‘C’ is next in sequence.

Below are implementations of above idea. 


// C++ program to find number of customers who couldn't get a resource.
#include<iostream>
#include<cstring>
using namespace std;
 
#define MAX_CHAR 26
 
// n is number of computers in cafe.
// 'seq' is given sequence of customer entry, exit events
int runCustomerSimulation(int n, const char *seq)
{
    // seen[i] = 0, indicates that customer 'i' is not in cafe
    // seen[1] = 1, indicates that customer 'i' is in cafe but
    //             computer is not assigned yet.
    // seen[2] = 2, indicates that customer 'i' is in cafe and
    //             has occupied a computer.
    char seen[MAX_CHAR] = {0};
 
    // Initialize result which is number of customers who could
    // not get any computer.
    int res = 0;
 
    int occupied = 0; // To keep track of occupied computers
 
    // Traverse the input sequence
    for (int i=0; seq[i]; i++)
    {
        // Find index of current character in seen[0...25]
        int ind = seq[i] - 'A';
 
        // If First occurrence of 'seq[i]'
        if (seen[ind] == 0)
        {
            // set the current character as seen
            seen[ind] = 1;
 
            // If number of occupied computers is less than
            // n, then assign a computer to new customer
            if (occupied < n)
            {
                occupied++;
 
                // Set the current character as occupying a computer
                seen[ind] = 2;
            }
 
            // Else this customer cannot get a computer,
            // increment result
            else
                res++;
        }
 
        // If this is second occurrence of 'seq[i]'
        else
        {
        // Decrement occupied only if this customer
        // was using a computer
        if (seen[ind] == 2)
            occupied--;
        seen[ind] = 0;
        }
    }
    return res;
}
 
// Driver program
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}
Output
0
1
0
2
3
Time complexity of above solution is O(n) and extra space required is O(CHAR_MAX) where CHAR_MAX is total number of possible characters in given sequence.

Transform One String to Another using Minimum Number of Given Operation	
----------------------------------------------------------------------------
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.

Examples: 

Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.

Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD

     Checking whether a string can be transformed to another is simple. We need to check whether both strings have same number of characters and same set of characters. This can be easily done by creating a count array for first string and checking if second string has same count of every character. 
How to find minimum number of operations when we are sure that we can transform A to B? The idea is to start matching from last characters of both strings. If last characters match, then our task reduces to n-1 characters. If last characters don’t match, then find the position of B’s mismatching character in A. The difference between two positions indicates that these many characters of A must be moved before current character of A. 

Below is complete algorithm. 
1) Find if A can be transformed to B or not by first creating a count array for all characters of A, then checking with B if B has same count for every character. 
2) Initialize result as 0. 
3) Start traversing from end of both strings. 
……a) If current characters of A and B match, i.e., A[i] == B[j] 
………then do i = i-1 and j = j-1 
    b) If current characters don’t match, then search B[j] in remaining 
………A. While searching, keep incrementing result as these characters 
………must be moved ahead for A to B transformation.

// C++ program to find minimum number of operations required
// to transform one string to other
#include <bits/stdc++.h>
using namespace std;
 
// Function to find minimum number of operations required to
// transform A to B.
int minOps(string& A, string& B)
{
    int m = A.length(), n = B.length();
 
    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in A
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // subtract count for every character in B
    for (int i = 0; i < n; i++)
        count[B[i]]--;
    // Check if all counts become 0
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
 
    // This part calculates the number of operations
    // required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j]) {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0) {
            i--;
            j--;
        }
    }
    return res;
}
 
// Driver program
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations required is " << minOps(A, B);
    return 0;
}

Output: 

Minimum number of operations required is 3
Time Complexity: O(n), please note that i is always decremented (in while loop and in if), and the for loop starts from n-1 and runs while i >= 0.
Auxiliary Space: O(1).

Check if two given strings are isomorphic to each other	
-----------------------------------------------------------
Two strings str1 and str2 are called isomorphic if there is a one-to-one mapping possible for every character of str1 to every character of str2. And all occurrences of every character in ‘str1’ map to the same character in ‘str2’.

Examples: 

Input:  str1 = “aab”, str2 = “xxy”
Output: True
Explanation: ‘a’ is mapped to ‘x’ and ‘b’ is mapped to ‘y’.

Input:  str1 = “aab”, str2 = “xyz”
Output: False
Explanation: One occurrence of ‘a’ in str1 has ‘x’ in str2 and other occurrence of ‘a’ has ‘y’.

Naive Approach:
A Simple Solution is to consider every character of ‘str1’ and check if all occurrences of it map to the same character in ‘str2’. 
Time Complexity: O(N * N)
Auxiliary Space: O(1)

Using Mapping:
The idea is to create an array to store mappings of processed characters. 

Follow the steps below to solve the problem:

If the lengths of str1 and str2 are not same, return false.
Do the following for every character in str1 and str2.
If this character is seen first time in str1, then-current of str2 must have not appeared before.
If the current character of str2 is seen, return false. Mark the current character of str2 as visited.
Store mapping of current characters.
Else check if the previous occurrence of str1[i] mapped to the same character.

// C++ program to check if two strings are isomorphic
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256
 
// This function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{
 
    int m = str1.length(), n = str2.length();
 
    // Length of both strings must be same for one to one
    // correspondence
    if (m != n)
        return false;
 
    // To mark visited characters in str2
    bool marked[MAX_CHARS] = { false };
 
    // To store mapping of every character from str1 to
    // that of str2. Initialize all entries of map as -1.
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
 
    // Process all characters one by on
    for (int i = 0; i < n; i++) {
        // If current character of str1 is seen first
        // time in it.
        if (map[str1[i]] == -1) {
            // If current character of str2 is already
            // seen, one to one mapping not possible
            if (marked[str2[i]] == true)
                return false;
 
            // Mark current character of str2 as visited
            marked[str2[i]] = true;
 
            // Store mapping of current characters
            map[str1[i]] = str2[i];
        }
 
        // If this is not first appearance of current
        // character in str1, then check if previous
        // appearance mapped to same character of str2
        else if (map[str1[i]] != str2[i])
            return false;
    }
 
    return true;
}
 
// Driver program
int main()
{
    cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
         << endl;
    return 0;
}
Output
True
Time Complexity: O(N), Traversing over the string of size N
Auxiliary Space: O(1)

Using Hashing:
The idea is to store the frequency of both strings in the separate array and then check if the frequency of the mapped characters are same or not.

Follow the steps below to solve the problem:

First, create two arrays of size 256 to store the frequency of the characters of the strings.
Now traverse the string and store the count of the characters.
After storing the count, check whether the count of every ith character of both the strings are same or not.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 26
 
// This function returns true if
// str1 and str2 are isomorphic
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
 
    // Length of both strings must be
    // same for one to one
    // correspondence
    if (n != m)
        return false;
 
    // For counting the previous appearances of character in
    // both the strings
    int count[MAX_CHARS] = { 0 };
    int dcount[MAX_CHARS] = { 0 };
 
    // Process all characters one by one
    for (int i = 0; i < n; i++) {
        count[str1[i] - 'a']++;
        dcount[str2[i] - 'a']++;
    }
    // For string to be isomorphic the previous counts
    // of appearances of
    // current character in both string must be same if
    // it is not same we return false.
 
    // before it was not working for the test case mentioned
    // below(wrong output)
    // str1 = "aba" , str2 = "xyy"
    for (int i = 0; i < n; i++) {
        if (count[str1[i] - 'a'] != dcount[str2[i] - 'a']) {
            return false;
        }
    }
    return true;
}
 
// Driver Code
int main()
{
    cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
         << endl;
    return 0;
}
Output
True
Time Complexity: O(N), Traverse on the string of size N
Auxiliary Space: O(1)

Check if two given strings are isomorphic to each other	
----------------------------------------------------------

Two strings str1 and str2 are called isomorphic if there is a one-to-one mapping possible for every character of str1 to every character of str2. And all occurrences of every character in ‘str1’ map to the same character in ‘str2’.

Examples: 

Input:  str1 = “aab”, str2 = “xxy”
Output: True
Explanation: ‘a’ is mapped to ‘x’ and ‘b’ is mapped to ‘y’.

Input:  str1 = “aab”, str2 = “xyz”
Output: False
Explanation: One occurrence of ‘a’ in str1 has ‘x’ in str2 and other occurrence of ‘a’ has ‘y’.

Naive Approach:

A Simple Solution is to consider every character of ‘str1’ and check if all occurrences of it map to the same character in ‘str2’. 

Time Complexity: O(N * N)
Auxiliary Space: O(1)

Using Mapping:
The idea is to create an array to store mappings of processed characters. 

Follow the steps below to solve the problem:

If the lengths of str1 and str2 are not same, return false.
Do the following for every character in str1 and str2.
If this character is seen first time in str1, then-current of str2 must have not appeared before.
If the current character of str2 is seen, return false. Mark the current character of str2 as visited.
Store mapping of current characters.
Else check if the previous occurrence of str1[i] mapped to the same character.

// C++ program to check if two strings are isomorphic
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256
 
// This function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{
 
    int m = str1.length(), n = str2.length();
 
    // Length of both strings must be same for one to one
    // correspondence
    if (m != n)
        return false;
 
    // To mark visited characters in str2
    bool marked[MAX_CHARS] = { false };
 
    // To store mapping of every character from str1 to
    // that of str2. Initialize all entries of map as -1.
    int map[MAX_CHARS];
    memset(map, -1, sizeof(map));
 
    // Process all characters one by on
    for (int i = 0; i < n; i++) {
        // If current character of str1 is seen first
        // time in it.
        if (map[str1[i]] == -1) {
            // If current character of str2 is already
            // seen, one to one mapping not possible
            if (marked[str2[i]] == true)
                return false;
 
            // Mark current character of str2 as visited
            marked[str2[i]] = true;
 
            // Store mapping of current characters
            map[str1[i]] = str2[i];
        }
 
        // If this is not first appearance of current
        // character in str1, then check if previous
        // appearance mapped to same character of str2
        else if (map[str1[i]] != str2[i])
            return false;
    }
 
    return true;
}
 
// Driver program
int main()
{
    cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
         << endl;
    return 0;
}
Output
True
Time Complexity: O(N), Traversing over the string of size N
Auxiliary Space: O(1)

Using Hashing:
The idea is to store the frequency of both strings in the separate array and then check if the frequency of the mapped characters are same or not.


Follow the steps below to solve the problem:

First, create two arrays of size 256 to store the frequency of the characters of the strings.
Now traverse the string and store the count of the characters.
After storing the count, check whether the count of every ith character of both the strings are same or not.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 26
 
// This function returns true if
// str1 and str2 are isomorphic
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
 
    // Length of both strings must be
    // same for one to one
    // correspondence
    if (n != m)
        return false;
 
    // For counting the previous appearances of character in
    // both the strings
    int count[MAX_CHARS] = { 0 };
    int dcount[MAX_CHARS] = { 0 };
 
    // Process all characters one by one
    for (int i = 0; i < n; i++) {
        count[str1[i] - 'a']++;
        dcount[str2[i] - 'a']++;
    }
    // For string to be isomorphic the previous counts
    // of appearances of
    // current character in both string must be same if
    // it is not same we return false.
 
    // before it was not working for the test case mentioned
    // below(wrong output)
    // str1 = "aba" , str2 = "xyy"
    for (int i = 0; i < n; i++) {
        if (count[str1[i] - 'a'] != dcount[str2[i] - 'a']) {
            return false;
        }
    }
    return true;
}
 
// Driver Code
int main()
{
    cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
         << endl;
    return 0;
}
Output
True
Time Complexity: O(N), Traverse on the string of size N
Auxiliary Space: O(1)

Recursively print all sentences that can be formed from list of word lists	
-----------------------------------------------------------------------------
Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion? 

Example: 

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink 

// C++ program to print all possible sentences from a list of word list
#include <iostream>
#include <string>

#define R 3
#define C 3
using namespace std;

// A recursive function to print all possible sentences that can be formed
// from a list of word list
void printUtil(string arr[R][C], int m, int n, string output[R])
{
	// Add current word to output array
	output[m] = arr[m][n];

	// If this is last word of current output sentence, then print
	// the output sentence
	if (m==R-1)
	{
		for (int i=0; i<R; i++)
		cout << output[i] << " ";
		cout << endl;
		return;
	}

	// Recur for next row
	for (int i=0; i<C; i++)
	if (arr[m+1][i] != "")
		printUtil(arr, m+1, i, output);
}

// A wrapper over printUtil()
void print(string arr[R][C])
{
// Create an array to store sentence
string output[R];

// Consider all words for first row as starting points and
// print all sentences
for (int i=0; i<C; i++)
	if (arr[0][i] != "")
		printUtil(arr, 0, i, output);
}

// Driver program to test above functions
int main()
{
string arr[R][C] = {{"you", "we"},
						{"have", "are"},
						{"sleep", "eat", "drink"}};

print(arr);

return 0;
}
Output
you have sleep 
you have eat 
you have drink 
you are sleep 
you are eat 
you are drink 
we have sleep 
we have eat 
we have drink 
we are sleep 
we are eat 
we are drink 
