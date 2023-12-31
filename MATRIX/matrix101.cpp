-------------------------------------------------------------------------
                              Matrix
--------------------------------------------------------------------------
Spiral traversal on a Matrix	
--------------------------------
Given a 2D array, print it in spiral form.

Examples: 

Input:  {{1,    2,   3,   4},
              {5,    6,   7,   8},
             {9,   10,  11,  12},
            {13,  14,  15,  16 }}
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
Explanation: The output is matrix in spiral format. 

Input: { {1,   2,   3,   4,  5,   6},
           {7,   8,   9,  10,  11,  12},
          {13,  14,  15, 16,  17,  18}}

Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
Explanation: The output is matrix in spiral format.

Using the simulation approach:

To solve the problem follow the below idea:

Draw the path that the spiral makes. We know that the path should turn clockwise whenever it would go out of bounds or into a cell that was previously visited

Follow the given steps to solve the problem:

Let the array have R rows and C columns
seen[r] denotes that the cell on the r-th row and c-th column was previously visited. Our current position is (r, c), facing direction di, and we want to visit R x C total cells.
As we move through the matrix, our candidate’s next position is (cr, cc). 
If the candidate is in the bounds of the matrix and unseen, then it becomes our next position; otherwise, our next position is the one after performing a clockwise turn.

// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
 
    if (m == 0)
        return ans;
 
    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
 
    int x = 0, y = 0, di = 0;
 
    // Iterate from 0 to m * n - 1
    for (int i = 0; i < m * n; i++) {
        ans.push_back(matrix[x][y]);
        // on normal geeksforgeeks ui page it is showing
        // 'ans.push_back(matrix[x])' which gets copied as
        // this only and gives error on compilation,
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}
 
// Driver code
int main()
{
    vector<vector<int> > a{ { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 } };
 
    // Function call
    for (int x : spiralOrder(a)) {
        cout << x << " ";
    }
    return 0;
}
 
Output
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
Time Complexity: O(N), where N is the total number of elements in the input matrix. We add every element in the matrix to our final answer
Auxiliary Space: O(N), the information stored in seen and in ans.

By dividing the matrix into cycles:

To solve the problem follow the below idea:

The problem can be solved by dividing the matrix into loops or squares or boundaries. It can be seen that the elements of the outer loop are printed first in a clockwise manner then the elements of the inner loop are printed. So printing the elements of a loop can be solved using four loops that print all the elements. Every ‘for’ loop defines a single-direction movement along with the matrix. The first for loop represents the movement from left to right, whereas the second crawl represents the movement from top to bottom, the third represents the movement from the right to left, and the fourth represents the movement from bottom to up

Follow the given steps to solve the problem:

Create and initialize variables k – starting row index, m – ending row index, l – starting column index, n – ending column index
Run a loop until all the squares of loops are printed.
In each outer loop traversal print the elements of a square in a clockwise manner.
Print the top row, i.e. Print the elements of the kth row from column index l to n, and increase the count of k.
Print the right column, i.e. Print the last column or n-1th column from row index k to m and decrease the count of n.
Print the bottom row, i.e. if k < m, then print the elements of the m-1th row from column n-1 to l and decrease the count of m
Print the left column, i.e. if l < n, then print the elements of lth column from m-1th row to k and increase the count of l.

// C++ Program to print a matrix spirally
 
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
 
void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}
 
/* Driver Code */
int main()
{
    int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
 
    // Function Call
    spiralPrint(R, C, a);
    return 0;
}

Output
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
Time Complexity: O(M*N). To traverse the matrix O(M*M) time is required.
Auxiliary Space: O(1). No extra space is required.

Using recursion:
To solve the problem follow the below idea:

The above problem can be solved by printing the boundary of the Matrix recursively. In each recursive call, we decrease the dimensions of the matrix. The idea of printing the boundary or loops is the same

Follow the given steps to solve the problem:

create a recursive function that takes a matrix and some variables (k – starting row index, m – ending row index, l – starting column index, n – ending column index) as parameters
Check the base cases (starting index is less than or equal to the ending index) and print the boundary elements in a clockwise manner
Print the top row, i.e. Print the elements of the kth row from column index l to n, and increase the count of k
Print the right column, i.e. Print the last column or n-1th column from row index k to m and decrease the count of n
Print the bottom row, i.e. if k > m, then print the elements of m-1th row from column n-1 to l and decrease the count of m
Print the left column, i.e. if l < n, then print the elements of the lth column from m-1th row to k and increase the count of l
Call the function recursively with the values of starting and ending indices of rows and columns

// C++. program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
#define R 4
#define C 4
 
// Function for printing matrix in spiral
// form i, j: Start index of matrix, row
// and column respectively m, n: End index
// of matrix row and column respectively
void print(int arr[R][C], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;
 
    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";
 
    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
 
    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
 
    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
 
    print(arr, i + 1, j + 1, m - 1, n - 1);
}
 
// Driver Code
int main()
{
    int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
 
    // Function Call
    print(a, 0, 0, R, C);
    return 0;
}

Output
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
Time Complexity: O(M*N). To traverse the matrix O(m*n) time is required.
Auxiliary Space: O(1). No extra space is required.

Search an element in a Matrix	
----------------------------------
Given an n x n matrix and an integer x, find the position of x in the matrix if it is present. Otherwise, print “Element not found”. Every row and column of the matrix is sorted in increasing order. The designed algorithm should have linear time complexity

Examples: 

Input: mat[4][4] = { {10, 20, 30, 40},  x = 29
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}}
 
Output: Found at (2, 1)
Explanation: Element at (2,1) is 29

Input : mat[4][4] = { {10, 20, 30, 40},   x = 100
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
     
Output: Element not found
Explanation: Element 100 does not exist in the matrix

Naive approach: To solve the problem follow the below idea:

The simple idea is to traverse the array and search elements one by one

Follow the given steps to solve the problem:

Run a nested loop, outer loop for the row, and inner loop for the column
Check every element with x and if the element is found then print “element found”
If the element is not found, then print “element not found”

// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
 
using namespace std;
 
/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
 
    // traverse through the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            // if the element is found
            if (mat[i][j] == x) {
                cout << "Element found at (" << i << ", "
                     << j << ")\n";
                return 1;
            }
    }
 
    cout << "n Element not found";
    return 0;
}
 
// Driver code
int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
 
    // Function call
    search(mat, 4, 29);
 
    return 0;
}

Output
Element found at (2, 1)
Time Complexity: O(N2)
Auxiliary Space: O(1), since no extra space has been taken

Note: A better solution is to use Divide and Conquer to find the element which has a time complexity of O(n1.58). Please refer here for details

Search in a row-wise and column-wise sorted matrix in linear time complexity:
The simple idea is to remove a row or column in each comparison until an element is found. Start searching from the top-right corner of the matrix. There are three possible cases:-

The given number is greater than the current number: This will ensure that all the elements in the current row are smaller than the given number as the pointer is already at the right-most elements and the row is sorted. Thus, the entire row gets eliminated and continues the search for the next row. Here, elimination means that a row needs not to be searched.
The given number is smaller than the current number: This will ensure that all the elements in the current column are greater than the given number. Thus, the entire column gets eliminated and continues the search for the previous column, i.e. the column on the immediate left.
The given number is equal to the current number: This will end the search.
Follow the given steps to solve the problem:

Let the given element be x, create two variable i = 0, j = n-1 as index of row and column.
Run a loop until i < n.
Check if the current element is greater than x then decrease the count of j. Exclude the current column.
Check if the current element is less than x then increase the count of i. Exclude the current row.
If the element is equal, then print the position and end.
Print the Element is not found

// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
using namespace std;
 
/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
 
    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return -1;
 
    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            cout << "Element found at " << i << ", " << j;
            return 1;
        }
        if (mat[i][j] > x)
            j--;
 
        // Check if mat[i][j] < x
        else
            i++;
    }
 
    cout << "n Element not found";
    return 0;
}
 
// Driver code
int main()
{
    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
 
    // Function call
    search(mat, 4, 29);
 
    return 0;
}

Output
Element found at 2, 1
Time Complexity: O(N), Only one traversal is needed, i.e, i from 0 to n and j from n-1 to 0 with at most 2*N steps. The above approach will also work for the M x N matrix (not only for N x N). Complexity would be O(M + N)
Auxiliary Space: O(1), No extra space is required

Find median in a row wise sorted matrix	
-------------------------------------------
We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.

Examples: 

Input: 1 3 5
        2 6 9
        3 6 9
Output: Median is 5
If we put all the values in a sorted 
array A[] = 1 2 3 3 5 6 6 9 9)

Input: 1 3 4
       2 5 6
       7 8 9
Output: Median is 5

Simple Method: The simplest method to solve this problem is to store all the elements of the given matrix in an array of size r*c. Then we can either sort the array and find the median element in O(r*clog(r*c)) or we can use the approach discussed here to find the median in O(r*c). Auxiliary space required will be O(r*c) in both cases.

An efficient approach for this problem is to use a binary search algorithm. The idea is that for a number to be median there should be exactly (n/2) numbers that are less than this number. So, we try to find the count of numbers less than all the numbers. Below is the step-by-step algorithm for this approach: 


Algorithm:  

First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found by comparing the first element of each row, and similarly, the maximum element can be found by comparing the last element of each row.
Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max and get a count of numbers less than or equal to our mid. And accordingly change the min or max.
For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every number, we get the count of numbers less than or equal to that by using upper_bound() in each row of the matrix, if it is less than the required count, the median must be greater than the selected number, else the median must be less than or equal to the selected number.
Below is the implementation of the above approach:


// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 100;
 
// function to find median in the matrix
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
 
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
 
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
 
        // Find count of elements smaller than or equal to mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
 
// driver program to check above functions
int main()
{
    int r = 3, c = 3;
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is " << binaryMedian(m, r, c) << endl;
    return 0;
}
Output
Median is 5
Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
Auxiliary Space: O(1) 

Find row with maximum no. of 1’s	
-------------------------------------
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s. 

Example:  

Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2

A simple method is to do a row-wise traversal of the matrix, count the number of 1s in each row, and compare the count with max. Finally, return the index of the row with maximum 1s. The time complexity of this method is O(m*n) where m is the number of rows and n is the number of columns in the matrix.

Implementation:

// CPP program to find the row
// with maximum number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
 
// Function that returns index of row
// with maximum number of 1s.
int rowWithMax1s(bool mat[R][C]) {
    // code here
    int rowIndex = -1 ;
    int maxCount = 0 ;
     
    for(int i = 0 ; i < R ; i++){
        int count = 0 ;
        for(int j = 0 ; j < C ; j++ ){
            if(mat[i][j] == 1){
                count++ ;
            }
        }
        if(count > maxCount){
            maxCount = count ;
            rowIndex = i ;
        }
    }
     
    return rowIndex ;
}
 
 
// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
 
    return 0;
}
Output
Index of row with maximum 1s is 2
Time Complexity:  O(m*n)
Space Complexity:  O(1)

We can do better. Since each row is sorted, we can use Binary Search to count of 1s in each row. We find the index of first instance of 1 in each row. The count of 1s will be equal to total number of columns minus the index of first 1.

Implementation: See the following code for implementation of the above approach.  

// CPP program to find the row with maximum number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
 
// Function to find the index of first instance
// of 1 in a boolean array arr[]
int first(bool arr[], int low, int high)
{
    if(high >= low)
    {
        // Get the middle index
        int mid = low + (high - low)/2;
     
        // Check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
     
        // If the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
         
        // If element is not first 1, recur for left side
        else
            return first(arr, low, (mid -1));
    }
    return -1;
}
 
// Function that returns index of row
// with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize max values
    int max_row_index = 0, max = -1;
 
    // Traverse for each row and count number of 1s
    // by finding the index of first 1
    int i, index;
    for (i = 0; i < R; i++)
    {
        index = first (mat[i], 0, C-1);
        if (index != -1 && C-index > max)
        {
            max = C - index;
            max_row_index = i;
        }
    }
 
    return max_row_index;
}
 
// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
 
    return 0;
}
 
Output
Index of row with maximum 1s is 2
Time Complexity: O(mLogn) where m is number of rows and n is number of columns in matrix.
Auxiliary Space:  O(Log n), as implicit stack is created due to recursion.

The above solution can be optimized further. Instead of doing binary search in every row, we first check whether the row has more 1s than max so far. If the row has more 1s, then only count 1s in the row. Also, to count 1s in a row, we don’t do binary search in complete row, we do search in before the index of last max. 

Implementation: Following is an optimized version of the above solution.  


#include <bits/stdc++.h>
using namespace std;
 
// The main function that returns index
// of row with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    int i, index;
 
    // Initialize max using values from first row.
    int max_row_index = 0;
    int max = first(mat[0], 0, C - 1);
 
    // Traverse for each row and count number of 1s
    // by finding the index of first 1
    for (i = 1; i < R; i++)
    {
        // Count 1s in this row only if this row
        // has more 1s than max so far
 
        // Count 1s in this row only if this row
        // has more 1s than max so far
        if (max != -1 && mat[i][C - max - 1] == 1)
        {
            // Note the optimization here also
            index = first (mat[i], 0, C - max);
 
            if (index != -1 && C - index > max)
            {
                max = C - index;
                max_row_index = i;
            }
        }
        else
        {
            max = first(mat[i], 0, C - 1);
        }
    }
    return max_row_index;
}

The worst case time complexity of the above optimized version is also O(mLogn), the will solution work better on average. 
 
The worst case of the above solution occurs for a matrix like following. 
0 0 0 … 0 1 
0 0 0 ..0 1 1 
0 … 0 1 1 1 
….0 1 1 1 1

Following method works in O(m+n) time complexity in worst case. 

Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row 
…IF the element on left of previous leftmost 1 is 0, ignore this row. 
…ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.
The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.
Implementation: Following is the implementation of this method.

// C++ program to find the row with maximum
// number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = C - 1;
 
    for (int i = 0; i < R; i++) {
        // Move left until a 0 is found
      bool flag=false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          flag=true ;//present row has more 1's than previous
          }
      // if the present row has more 1's than previous
      if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}
// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
  
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
  
    return 0;
}
Output
Index of row with maximum 1s is 2
Time Complexity: O(m+n) where m is number of rows and n is number of columns in matrix.
Auxiliary Space:  O(1), as implicit stack is created due to recursion.

Print elements in sorted order using row-column wise sorted matrix	
-----------------------------------------------------------------------
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Example: 

Input: mat[][] = { {10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {27, 29, 37, 48},
                   {32, 33, 39, 50},
                   };
Output: 10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50

// A C++ program to Print all elements in sorted order from row and
// column wise sorted matrix
#include<iostream>
#include<climits>
using namespace std;
 
#define INF INT_MAX
#define N 4
 
// A utility function to youngify a Young Tableau.  This is different
// from standard youngify.  It assumes that the value at mat[0][0] is
// infinite.
void youngify(int mat[][N], int i, int j)
{
    // Find the values at down and right sides of mat[i][j]
    int downVal  = (i+1 < N)? mat[i+1][j]: INF;
    int rightVal = (j+1 < N)? mat[i][j+1]: INF;
 
    // If mat[i][j] is the down right corner element, return
    if (downVal==INF && rightVal==INF)
        return;
 
    // Move the smaller of two values (downVal and rightVal) to
    // mat[i][j] and recur for smaller value
    if (downVal < rightVal)
    {
        mat[i][j] = downVal;
        mat[i+1][j] = INF;
        youngify(mat, i+1, j);
    }
    else
    {
        mat[i][j] = rightVal;
        mat[i][j+1] = INF;
        youngify(mat, i, j+1);
    }
}
 
// A utility function to extract minimum element from Young tableau
int extractMin(int mat[][N])
{
    int ret = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return ret;
}
 
// This function uses extractMin() to print elements in sorted order
void printSorted(int mat[][N])
{
   for (int i=0; i<N*N; i++)
     cout << extractMin(mat) << " ";
}
 
// driver program to test above function
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}
Output
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
Time complexity of extract minimum is O(N) and it is called O(N2) times. Therefore the overall time complexity is O(N3).

Another approach: The idea is to keep all elements of the matrix in a one-dimensional array and then sort the array and print all values in it.

#include <bits/stdc++.h>
using namespace std;
 
// Function to print all elements of matrix in sorted orderd
void sortedMatrix(int N, vector<vector<int> > Mat)
{
    vector<int> temp;
   
   // Store all elements of matrix into temp
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp.push_back(Mat[i][j]);
        }
    }
 
    // Sort the temp
    sort(temp.begin(), temp.end());
 
    // Print the values of temp
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
}
 
int main()
{
    int N = 4;
    vector<vector<int> > Mat = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 27, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    sortedMatrix(N, Mat);
 
    return 0;
}

Output
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
Time Complexity: O(N2log(N2))
Auxiliary Space: O(N2)

A better solution is to use the approach used for merging k sorted arrays. The idea is to use a Min Heap of size N which stores elements of first column. They do extract minimum. In extract minimum, replace the minimum element with the next element of the row from which the element is extracted.


// C++ program to merge k sorted arrays of size n each.
#include<iostream>
#include<climits>
using namespace std;
 
#define N 4
 
// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the row from which the element is taken
    int j; // index of the next element to be picked from row
};
 
// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);
 
// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor: creates a min heap of given size
    MinHeap(MinHeapNode a[], int size);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to get the root
    MinHeapNode getMin() { return harr[0]; }
 
    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
};
 
// This function prints elements of a given matrix in non-decreasing
//  order. It assumes that ma[][] is sorted row wise sorted.
void printSorted(int mat[][N])
{
    // Create a min heap with k heap nodes.  Every heap node
    // has first element of an array
    MinHeapNode *harr = new MinHeapNode[N];
    for (int i = 0; i < N; i++)
    {
        harr[i].element = mat[i][0]; // Store the first element
        harr[i].i = i;  // index of row
        harr[i].j = 1;  // Index of next element to be stored from row
    }
    MinHeap hp(harr, N); // Create the min heap
 
    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < N*N; count++)
    {
        // Get the minimum element and store it in output
        MinHeapNode root = hp.getMin();
 
        cout << root.element << " ";
 
        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // array as the current root.
        if (root.j < N)
        {
            root.element = mat[root.i][root.j];
            root.j += 1;
        }
        // If root was the last element of its array
        else root.element =  INT_MAX; //INT_MAX is for infinite
 
        // Replace root with next element of array
        hp.replaceMin(root);
    }
}
 
// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS
// FROM CORMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}
 
// driver program to test above function
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}
Output
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
Time complexity: O(N2LogN). 

Maximum size rectangle
-------------------------------------
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s. 

Example: 

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :
8
Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 

Input:
0 1 1
1 1 1
0 1 1      
Output:
6
Explanation : 
The largest rectangle with only 1's is from 
(0, 1) to (2, 2) which is
1 1
1 1
1 1
If the height of bars of the histogram is given then the largest area of the histogram can be found. This way in each row, the largest area of bars of the histogram can be found. To get the largest rectangle full of 1’s, update the next row with the previous row and find the largest area under the histogram, i.e. consider each 1’s as filled squares and 0’s with an empty square and consider each row as the base.

Illustration: 

Input :
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Step 1: 
0 1 1 0  maximum area  = 2
Step 2:
row 1  1 2 2 1  area = 4, maximum area becomes 4
row 2  2 3 3 2  area = 8, maximum area becomes 8
row 3  3 4 0 0  area = 6, maximum area remains 8

Algorithm: 
Run a loop to traverse through the rows.
Now If the current row is not the first row then update the row as follows, if matrix[i][j] is not zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j].
Find the maximum rectangular area under the histogram, consider the ith row as heights of bars of a histogram. This can be calculated as given in this article Largest Rectangular Area in a Histogram
Do the previous two steps for all rows and print the maximum area of all the rows.

Implementation:
// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <bits/stdc++.h>
using namespace std;
 
// Rows and columns in input matrix
#define R 4
#define C 4
 
// Finds the maximum area under
// the histogram represented
// by histogram.  See below article for details.
 
 
int maxHist(int row[])
{
    // Create an empty stack.
    // The stack holds indexes of
    // hist[] array/ The bars stored
    // in stack are always
    // in increasing order of their heights.
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
    // row (or histogram)
 
    int area = 0; // Initialize area with current top
 
    // Run through all bars of given histogram (or row)
    int i = 0;
    while (i < C) {
        // If this bar is higher than the bar on top stack,
        // push it to stack
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
 
// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle(int A[][C])
{
    // Calculate area for first row and initialize it as
    // result
    int result = maxHist(A[0]);
 
    // iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < R; i++) {
 
        for (int j = 0; j < C; j++)
 
            // if A[i][j] is 1 then add A[i -1][j]
            if (A[i][j])
                A[i][j] += A[i - 1][j];
 
        // Update result if area with current row (as last
        // row) of rectangle) is more
        result = max(result, maxHist(A[i]));
    }
 
    return result;
}
 
// Driver code
int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "
         << maxRectangle(A);
 
    return 0;
}
Output
Area of maximum rectangle is 8
Complexity Analysis:  

Time Complexity: O(R x C). 
Only one traversal of the matrix is required, so the time complexity is O(R X C)
Space Complexity: O(C). 
Stack is required to store the columns, so space complexity is O(C)

Find a specific pair in matrix	
---------------------------------------
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example: 

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference. 
The program should do only ONE traversal of the matrix. i.e. expected time complexity is O(n2)
A simple solution would be to apply Brute-Force. For all values mat(a, b) in the matrix, we find mat(c, d) that has maximum value such that c > a and d > b and keeps on updating maximum value found so far. We finally return the maximum value.

// A Naive method to find maximum value of mat[d][e]
// - ma[a][b] such that d > a and e > b
#include <bits/stdc++.h>
using namespace std;
#define N 5
 
// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.
int findMaxValue(int mat[][N])
{
    // stores maximum value
    int maxValue = INT_MIN;
 
    // Consider all possible pairs mat[a][b] and
    // mat[d][e]
    for (int a = 0; a < N - 1; a++)
    for (int b = 0; b < N - 1; b++)
        for (int d = a + 1; d < N; d++)
        for (int e = b + 1; e < N; e++)
            if (maxValue < (mat[d][e] - mat[a][b]))
                maxValue = mat[d][e] - mat[a][b];
 
    return maxValue;
}
 
// Driver program to test above function
int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat);
 
    return 0;
}
Output
Maximum Value is 18
Time complexity: O(N4).
Auxiliary Space: O(1)

The above program runs in O(n^4) time which is nowhere close to expected time complexity of O(n^2)

An efficient solution uses extra space. We pre-process the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1) and in the process keeps on updating maximum value found so far. We finally return the maximum value.

Implementation:


// An efficient method to find maximum value of mat[d]
// - ma[a][b] such that c > a and d > b
#include <bits/stdc++.h>
using namespace std;
#define N 5
 
// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N])
{
    //stores maximum value
    int maxValue = INT_MIN;
 
    // maxArr[i][j] stores max of elements in matrix
    // from (i, j) to (N-1, N-1)
    int maxArr[N][N];
 
    // last element of maxArr will be same's as of
    // the input matrix
    maxArr[N-1][N-1] = mat[N-1][N-1];
 
    // preprocess last row
    int maxv = mat[N-1][N-1];  // Initialize max
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N-1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N-1][j] = maxv;
    }
 
    // preprocess last column
    maxv = mat[N - 1][N - 1];  // Initialize max
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }
 
    // preprocess rest of the matrix from bottom
    for (int i = N-2; i >= 0; i--)
    {
        for (int j = N-2; j >= 0; j--)
        {
            // Update maxValue
            if (maxArr[i+1][j+1] - mat[i][j] >
                                            maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];
 
            // set maxArr (i, j)
            maxArr[i][j] = max(mat[i][j],
                               max(maxArr[i][j + 1],
                                   maxArr[i + 1][j]) );
        }
    }
 
    return maxValue;
}
 
// Driver program to test above function
int main()
{
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "
         << findMaxValue(mat);
 
    return 0;
}
Output
Maximum Value is 18
Time complexity: O(N2).
Auxiliary Space: O(N2)

If we are allowed to modify of the matrix, we can avoid using extra space and use input matrix instead.

Rotate matrix by 90 degrees	
---------------------------------------
Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

Examples: 

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2 

Method 1

Approach: The approach is similar to Inplace rotate square matrix by 90 degrees | Set 1. The only thing that is different is to print the elements of the cycle in a clockwise direction i.e. An N x N matrix will have floor(N/2) square cycles. 
For example, a 3 X 3 matrix will have 1 cycle. The cycle is formed by its 1st row, last column, last row, and 1st column. 
For each square cycle, we swap the elements involved with the corresponding cell in the matrix in the clockwise direction. We just need a temporary variable for this.

Explanation:

Let size of row and column be 3. 
During first iteration – 
a[i][j] = Element at first index (leftmost corner top)= 1.
a[j][n-1-i]= Rightmost corner top Element = 3.
a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
a[n-1-j][i] = Leftmost corner bottom element = 7.
Move these elements in the clockwise direction. 
During second iteration – 
a[i][j] = 2.
a[j][n-1-i] = 6.
a[n-1-i][n-1-j] = 8.
a[n-1-j][i] = 4. 
Similarly, move these elements in the clockwise direction. 

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[N][N])
{
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
 
// Function for print matrix
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}
Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
Complexity Analysis:
Time Complexity – O(n*n)
Auxiliary Space – O(1)

Method 2:

Approach: The approach is based on the pattern made by indices after rotating the matrix. Consider the following illustration to have a clear insight into it.

Consider a 3 x 3 matrix having indices (i, j) as follows. 

00 01 02 
10 11 12 
20 21 22

After rotating the matrix by 90 degrees in clockwise direction, indices transform into
20 10 00  current_row_index = 0, i = 2, 1, 0 
21 11 01 current_row_index = 1, i = 2, 1, 0 
22 12 02  current_row_index = 2, i = 2, 1, 0

Observation: In any row, for every decreasing row index i, there exists a constant column index j, such that j = current_row_index. 

This pattern can be printed using 2 nested loops.
(This pattern of writing indices is achieved by writing the exact indices of the desired elements of 
where they actually existed in the original array.)  

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int arr[N][N])
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    return 0;
}

Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
Complexity Analysis:
Time Complexity – O(n*n)
Auxiliary Space – O(1)

Method 3:

Approach: The Approach is to rotate the given matrix two times, first time with respect to the Main diagonal, next time rotate the resultant matrix with respect to the middle column, Consider the following illustration to have a clear insight intoe square matrix 90 degrees in a clockwise direction

#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
             
        cout << '\n';
    }
}
 
void rotate(int arr[N][N])
{
     
    // First rotation
    // with respect to main diagonal
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
     
    // Second rotation
    // with respect to middle column
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N / 2; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = temp;
        }
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate(arr);
    print(arr);
    return 0;
}

Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
Complexity Analysis:

Time Complexity – O(n*n)

Auxiliary Space – O(1)

Method 4:

Approach: This approach is similar to method 3 the only difference is that in first rotation we rotate about the Secondary Diagonal and after that about the Middle row.

#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
             
        cout << '\n';
    }
}
 
void rotate(int arr[N][N])
{
     
    // First rotation
    // with respect to Secondary diagonal
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][N - 1 - i];
            arr[N - 1 - j][N - 1 - i] = temp;
        }
    }
     
    // Second rotation
    // with respect to middle row
    for(int i = 0; i < N / 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - i][j];
            arr[N - 1 - i][j] = temp;
        }
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate(arr);
    print(arr);
    return 0;
}

Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
Complexity Analysis:
Time Complexity – O(n*n)
Auxiliary Space – O(1)

Method 5: 

Approach: We first transpose the given matrix, and then reverse the content of individual rows to get the resultant 90 degree clockwise rotated matrix.

1  2  3                                                1  4  7                                                                 7  4  1

4  5  6        ——Transpose——>    2  5  8         —-Reverse individual rows—->    8  5  2     (Resultant matrix)

7  8  9                                                3  6  9                                                                 9  6  3

#include <iostream>
using namespace std;
const int n = 4;
void print(int mat[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void rotate90clockwise(int mat[n][n])
{
    // Transpose of matrix
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    // Reverse individual rows
    for (int i = 0; i < n; i++) {
        int low = 0, high = n - 1;
        while (low < high) {
            swap(mat[i][low], mat[i][high]);
            low++;
            high--;
        }
    }
}
int main()
{
    int mat[n][n]
        = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90clockwise(mat);
    print(mat);
}
Output
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
Complexity Analysis:
Time Complexity – O(n*n)
Auxiliary Space – O(1)

Kth smallest element in a row-column wise sorted.
--------------------------------------------------------
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array.
Example, 

Input:k = 3 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50 
Output: 20
Explanation: The 3rd smallest element is 20 

Input:k = 7 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50 
Output: 30

Explanation: The 7th smallest element is 30

Approach: So the idea is to find the kth minimum element. Each row and each column is sorted. So it can be thought as C sorted lists and the lists have to be merged into a single list, the kth element of the list has to be found out. So the approach is similar, the only difference is when the kth element is found the loop ends.
Algorithm:

The idea is to use min heap. Create a Min-Heap to store the elements
Traverse the first row from start to end and build a min heap of elements from first row. A heap entry also stores row number and column number.
Now Run a loop k times to extract min element from heap in each iteration
Get minimum element (or root) from Min-Heap.
Find row number and column number of the minimum element.
Replace root with the next element from same column and min-heapify the root.
Print the last extracted element, which is the kth minimum element
Implementation:

// kth largest element in a 2d array sorted row-wise and
// column-wise
#include <bits/stdc++.h>
using namespace std;
 
// A structure to store entry of heap. The entry contains
// value from 2D array, row and column numbers of the value
struct HeapNode {
    int val; // value to be stored
    int r; // Row number of value in 2D array
    int c; // Column number of value in 2D array
};
 
// A utility function to minheapify the node harr[i] of a
// heap stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
     if(l < heap_size&& r<heap_size && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
            HeapNode temp=harr[r];
            harr[r]=harr[i];
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,heap_size);
            minHeapify(harr ,r,heap_size);
        }
          if (l < heap_size && harr[l].val < harr[i].val){
            HeapNode temp=harr[i];           
            harr[i]=harr[l];
            harr[l]=temp;
            minHeapify(harr ,l,heap_size);
        }
}
 
// This function returns kth
// smallest element in a 2D array
// mat[][]
int kthSmallest(int mat[4][4], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k < 0 || k >= n * n)
        return INT_MAX;
 
    // Create a min heap of elements from first row of 2D
    // array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
        harr[i] = { mat[0][i], 0, i };
 
    HeapNode hr;
    for (int i = 0; i < k; i++) {
        // Get current heap root
        hr = harr[0];
 
        // Get next value from column of root's value. If
        // the value stored at root was last value in its
        // column, then assign INFINITE as next value
        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]: INT_MAX;
 
        // Update heap root with next value
        harr[0] = { nextval, (hr.r) + 1, hr.c };
 
        // Heapify root
        minHeapify(harr, 0, n);
    }
 
    // Return the value at last extracted root
    return hr.val;
}
 
// driver program to test above function
int main()
{
    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
        << kthSmallest(mat, 4, 7);
    return 0;
}

Output
7th smallest element is 30
The codes above are contributed by RISHABH CHAUHAN.
Complexity Analysis:

Time Complexity: The above solution involves following steps. 
Building a min-heap which takes O(n) time
Heapify k times which takes O(k Logn) time.
Auxiliary Space: O(R), where R is the length of a row, as the Min-Heap stores one row at a time.
The above code can be optimized to build a heap of size k when k is smaller than n. In that case, the kth smallest element must be in first k rows and k columns. 
We will soon be publishing more efficient algorithms for finding the kth smallest element. 
This article is compiled by Ravi Gupta. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above
 

Using inbuilt priority_queue :

By using a comparator, we can carry out custom comparison in priority_queue. We will use priority_queue<pair<int,int>> for this.
Implementation : 
// kth largest element in a 2d array sorted row-wise and
// column-wise
#include<bits/stdc++.h>
using namespace std;
 
int kthSmallest(int mat[4][4], int n, int k)
{
    // USING LAMBDA FUNCTION
    // [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH
    // ARE OUT OF SCOPE i.e. mat[r]
    // NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
      // Capturing the value of mat by reference to prevent copying
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
     
    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }
     
    //RUNNING LOOP FOR (k-1) TIMES
    for(int i=1; i<k; i++){
        auto p = pq.top();
        pq.pop();
         
        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if(p.second+1 < n) pq.push({p.first,p.second + 1});
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}
 
// driver program to test above function
int main()
{
    int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
        << kthSmallest(mat, 4, 7);
    return 0;
}
Output
7th smallest element is 30
Time Complexity: O(n log n)

Auxiliary Space: O(n)

Using Binary Search over the Range:
This approach uses binary search to iterate over possible solutions. We know that 


answer >= mat[0][0]
answer <= mat[N-1][N-1]
So we do a binary search on this range and in each  iteration determine the no of elements greater than or equal to our current middle element. The elements greater than or equal to current element can be found in O( n logn ) time using binary search.

#include <bits/stdc++.h>
using namespace std;
 
// This returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix
        // further are less than or equal to num
        if (mat[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements
        // in that row
        if (mat[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal
        // to num
        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                   mat[i][greaterThan + jump] <= num) {
                greaterThan += jump;
            }
        }
 
        ans += greaterThan + 1;
    }
    return ans;
}
 
// returns kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
    //  We know the answer lies between the first and the last element
    // So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);
 
        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
int main() {
    int n = 4;
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
Output: 

7th smallest element is 30
Complexity Analysis

Time Complexity : O( y * n*logn)
Where y =  log( abs(Mat[0][0] - Mat[n-1][n-1]) )
We call the getElementsGreaterThanOrEqual function  log ( abs(Mat[0][0] – Mat[n-1][n-1])  ) times
Time complexity of getElementsGreaterThanOrEqual is O(n logn) since there we do binary search n times.
Auxiliary Space: O(1)
USING ARRAY:

We will make a new array and will copy all the contents of matrix in this array. After that we will sort that array and find kth smallest element. This will be so easier.


// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;
 
int kthSmallest(int mat[4][4], int n, int k)
{
 
  int a[n*n];
  int v = 0;
 
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      a[v] = mat[i][j];
      v++;
    }
  }
 
  sort(a, a + (n*n));
  int result = a[k - 1];
  return result;
}
 
// Driver code
int main()
{
  int mat[4][4] = { { 10, 20, 30, 40 },
                   { 15, 25, 35, 45 },
                   { 25, 29, 37, 48 },
                   { 32, 33, 39, 50 } };
  int res = kthSmallest(mat, 4, 7);
 
  cout <<  "7th smallest element is " << res;
  return 0;
}
 
// This code is contributed by sanjoy_62.
Output
7th smallest element is 30
Time Complexity: O(n2) 
Auxiliary Space: O(n2)

Using Priority queue approach

#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
  //n = size of matrix
  int i,j,n=matrix.size();
   
  //using built-in priority queue which acts as max Heap i.e. largest element will be on top
  //Kth smallest element can also be seen as largest element in a priority queue of size k
  //By this logic we pop elements from priority queue when its size becomes greater than k
  //thus top of priority queue is kth smallest element in matrix
   
  priority_queue<int> maxH;
  if(k==1)
    return matrix[0][0];
   
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      maxH.push(matrix[i][j]);
      if(maxH.size()>k)
        maxH.pop();
    }
  }
   
  return maxH.top();
}
int main() {
 
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
      int k = 8;
    cout << "8th smallest element is " << kthSmallest(matrix,k);
    return 0;
}
Output
8th smallest element is 13
Time Complexity: O(n2) 
Auxiliary Space: O(n)

Common elements in all rows of a given matrix	
-------------------------------------------------
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example: 

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.

A simple solution is to consider every element and check if it is present in all rows. If present, then print it. 
A better solution is to sort all rows in the matrix . Sorting will take O(mnlogn) time and finding common elements will take O(mn) time. So overall time complexity of this solution is O(mnlogn)

Can we do better than O(mnlogn)? 
The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared m-1 times before. 

// A Program to prints common element in all
// rows of matrix
#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5
 
// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;
 
    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
 
    // traverse the matrix
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]] = i + 1;
 
                // If this is last row
                if (i==M-1 && mp[mat[i][j]]==M)
                  cout << mat[i][j] << " ";
            }
        }
    }
}
 
// driver program to test above function
int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}
Output
8 1 
The time complexity of this solution is O(m * n) and we are doing only one traversal of the matrix.
Auxiliary Space: O(N)
