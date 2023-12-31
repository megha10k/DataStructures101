------------------------------------------------------------------
                          Array
------------------------------------------------------------------

Reverse the array	
------------------------------------------
Examples : 
 
Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Iterative way :

// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}	

/* Utility function to print an array */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	int n = sizeof(arr) / sizeof(arr[0]);

	// To print original array
	printArray(arr, n);
	
	// Function calling
	rvereseArray(arr, 0, n-1);
	
	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, n);
	
	return 0;
}

Recursive Way :

// Recursive C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
	if (start >= end)
	return;
	
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	
	// Recursive Function calling
	rvereseArray(arr, start + 1, end - 1);
}	


/* Utility function to print an array */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	// To print original array
	printArray(arr, 6);
	
	// Function calling
	rvereseArray(arr, 0, 5);
	
	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, 6);
	
	return 0;
}

Find the maximum and minimum element in an array
---------------------------------------------------------	
Examples:

Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
         Maximum element is: 9

First of all, how do we return multiple values from a function? We can do it either using structures or pointers. 
We have created a structure named pair (which contains min and max) to return multiple values. 

struct pair {
	int min;
	int max;
};

Using Linear search:

// C++ program of above implementation
#include<iostream>
using namespace std;

// Pair struct is used to return
// two values from getMinMax()
struct Pair
{
	int min;
	int max;
};

Pair getMinMax(int arr[], int n)
{
	struct Pair minmax;	
	int i;
	
	// If there is only one element
	// then return it as min and max both
	if (n == 1)
	{
		minmax.max = arr[0];
		minmax.min = arr[0];	
		return minmax;
	}
	
	// If there are more than one elements,
	// then initialize min and max
	if (arr[0] > arr[1])
	{
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else
	{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}
	
	for(i = 2; i < n; i++)
	{
		if (arr[i] > minmax.max)	
			minmax.max = arr[i];
			
		else if (arr[i] < minmax.min)	
			minmax.min = arr[i];
	}
	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445,
				1, 330, 3000 };
	int arr_size = 6;
	
	struct Pair minmax = getMinMax(arr, arr_size);
	
	cout << "Minimum element is "
		<< minmax.min << endl;
	cout << "Maximum element is "
		<< minmax.max;
		
	return 0;
}

Using the tournament method:
Approch -
Pair MaxMin(array, array_size)
    if array_size = 1
        return element as both max and min
    else if arry_size = 2
        one comparison to determine max and min
         return that pair
    else    /* array_size  > 2 */
        recur for max and min of left half
        recur for max and min of right half
        one comparison determines true max of the two candidates
        one comparison determines true min of the two candidates
        return the pair of max and min

// C++ program of above implementation
#include <iostream>
using namespace std;

// structure is used to return
// two values from minMax()
struct Pair {
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
	struct Pair minmax, mml, mmr;
	int mid;

	// If there is only one element
	if (low == high) {
		minmax.max = arr[low];
		minmax.min = arr[low];
		return minmax;
	}

	// If there are two elements
	if (high == low + 1) {
		if (arr[low] > arr[high]) {
			minmax.max = arr[low];
			minmax.min = arr[high];
		}
		else {
			minmax.max = arr[high];
			minmax.min = arr[low];
		}
		return minmax;
	}

	// If there are more than 2 elements
	mid = (low + high) / 2;
	mml = getMinMax(arr, low, mid);
	mmr = getMinMax(arr, mid + 1, high);

	// Compare minimums of two parts
	if (mml.min < mmr.min)
		minmax.min = mml.min;
	else
		minmax.min = mmr.min;

	// Compare maximums of two parts
	if (mml.max > mmr.max)
		minmax.max = mml.max;
	else
		minmax.max = mmr.max;

	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;

	struct Pair minmax = getMinMax(arr, 0, arr_size - 1);

	cout << "Minimum element is " << minmax.min << endl;
	cout << "Maximum element is " << minmax.max;

	return 0;
}

By comparing in pairs:

If n is odd then initialize min and max as the first element. 
If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
For the rest of the elements, pick them in pairs and compare their 
maximum and minimum with max and min respectively. 

// C++ program of above implementation
#include<iostream>
using namespace std;

// Structure is used to return
// two values from minMax()
struct Pair
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int n)
{
	struct Pair minmax;	
	int i;
	
	// If array has even number of elements
	// then initialize the first two elements
	// as minimum and maximum
	if (n % 2 == 0)
	{
		if (arr[0] > arr[1])	
		{
			minmax.max = arr[0];
			minmax.min = arr[1];
		}
		else
		{
			minmax.min = arr[0];
			minmax.max = arr[1];
		}
		
		// Set the starting index for loop
		i = 2;
	}
	
	// If array has odd number of elements
	// then initialize the first element as
	// minimum and maximum
	else
	{
		minmax.min = arr[0];
		minmax.max = arr[0];
		
		// Set the starting index for loop
		i = 1;
	}
	
	// In the while loop, pick elements in
	// pair and compare the pair with max
	// and min so far
	while (i < n - 1)
	{		
		if (arr[i] > arr[i + 1])		
		{
			if(arr[i] > minmax.max)	
				minmax.max = arr[i];
				
			if(arr[i + 1] < minmax.min)		
				minmax.min = arr[i + 1];	
		}
		else	
		{
			if (arr[i + 1] > minmax.max)	
				minmax.max = arr[i + 1];
				
			if (arr[i] < minmax.min)		
				minmax.min = arr[i];	
		}
		
		// Increment the index by 2 as
		// two elements are processed in loop
		i += 2;
	}		
	return minmax;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445,
				1, 330, 3000 };
	int arr_size = 6;
	
	Pair minmax = getMinMax(arr, arr_size);
	
	cout << "nMinimum element is "
		<< minmax.min << endl;
	cout << "nMaximum element is "
		<< minmax.max;
		
	return 0;
}

Find the “Kth” max and min element of an array
-------------------------------------------------
Given an array and a number K where K is smaller than the size of the array. Find the K’th smallest element in the given array. Given that all array elements are distinct.

Examples:  

Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 4 
Output: 10 

Using sorting:
Sort the input array in the increasing order
Return the element at the K-1 index (0 – Based indexing) in the sorted array

// C++ program to find K'th smallest element
#include <bits/stdc++.h>
using namespace std;

// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
	// Sort the given array
	sort(arr, arr + N);

	// Return k'th element in the sorted array
	return arr[K - 1];
}

// Driver's code
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	// Function call
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}

Using set data structure:
Insert all array elements into the set
Advance the iterator to the Kth element in the set
Return the value of the element at which the iterator is pointing

// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 4;

	set<int> s(arr, arr + N);

	// s.begin() returns a pointer to first
	// element in the set
	set<int>::iterator itr = s.begin();

	advance(itr, K - 1); // itr points to kth element in set

	cout << *itr << "\n";

	return 0;
}

Using heap data structure:
Insert all the array elements into the Min-Heap
Call extractMin() function K times
Return the value obtained at the last call of extractMin() function 
// C++ program to find K'th smallest element using min heap

#include <climits>
#include <iostream>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);

// A class for Min Heap
class MinHeap {

	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	MinHeap(int a[], int size); // Constructor

	// To minheapify subtree rooted with index i
	void MinHeapify(int i);
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMin(); // extracts root (minimum) element
	int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heap_size == 0)
		return INT_MAX;

	// Store the minimum value.
	int root = harr[0];

	// If there are more than 1 items, move the last item to
	// root and call heapify.
	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		MinHeapify(0);
	}
	heap_size--;

	return root;
}

// A recursive method to heapify a subtree with root at
// given index This method assumes that the subtrees are
// already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < heap_size && harr[l] < harr[i])
		smallest = l;

	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
	// Build a heap of n elements: O(n) time
	MinHeap mh(arr, N);

	// Do extract min (K-1) times
	for (int i = 0; i < K - 1; i++)
		mh.extractMin();

	// Return root
	return mh.getMin();
}

// Driver's code
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	// Function call
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}

Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo	
---------------------------------------------------------------------------------
Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.
Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Using the Pointer Approach: 
The problem was posed with three colors, here `0′, `1′ and `2′. The array is divided into four sections: 
arr[1] to arr[low – 1]
arr[low] to arr[mid – 1]
arr[mid] to arr[high – 1]
arr[high] to arr[n]
If the ith element is 0 then swap the element to the low range.
Similarly, if the element is 1 then keep it as it is.
If the element is 2 then swap it with an element in high range.

Follow the steps below to solve the given problem:

Keep three indices low = 1, mid = 1, and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
Traverse the array from start to end and mid is less than high. (Loop counter is i)
If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
If the element is 1 then update mid = mid + 1
If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
Print the array.

// C++ program to sort an array
// with 0, 1 and 2 in a single pass
#include <bits/stdc++.h>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	// Iterate till all the elements
	// are sorted
	while (mid <= hi) {
		switch (a[mid]) {

		// If the element is 0
		case 0:
			swap(a[lo++], a[mid++]);
			break;

		// If the element is 1 .
		case 1:
			mid++;
			break;

		// If the element is 2
		case 2:
			swap(a[mid], a[hi--]);
			break;
		}
	}
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
	// Iterate and print every element
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort012(arr, n);

	printArray(arr, n);

	return 0;
}

Using Counting Approach: 

Count the number of 0s, 1s, and 2s in the given array. Then store all the 0s at the beginning followed by all the 1s and then all the 2s.

Illustration:

arr[] = {0, 1, 2, 0, 1, 2}

cnt0 = 0, cnt1 = 0, cnt2 = 0

At i = 0: arr[0] == 0

cnt0 = cnt0 + 1 = 1
At i = 1: arr[1] == 1

cnt1 = cnt1 + 1 = 1
At i = 2: arr[2] == 2

cnt2 = cnt2 + 1 = 1
At i = 3: arr[3] == 0

cnt0 = cnt0 + 1 = 2
At i = 4: arr[4] == 1

cnt1 = cnt1 + 1 = 2
At i = 5: arr[5] == 2

cnt2 = cnt2 + 1 = 2
Replace cnt0 number of elements with 0 in arr

arr[] = {0, 0, 2, 0, 1, 2}
Replace cnt1 number of elements with 1 in arr

arr[] = {0, 0, 1, 1, 1, 2}
Replace cnt2 number of elements with 2 in arr

arr[] = {0, 0, 1, 1, 2, 2}
Hence, arr[] = {0, 0, 1, 1, 2, 2}

Follow the steps below to solve the given problem:  

Keep three counters c0 to count 0s, c1 to count 1s, and c2 to count 2s
Traverse through the array and increase the count of c0 if the element is 0, increase the count of c1 if the element is 1 and increase the count of c2 if the element is 2
Now again traverse the array and replace the first c0 elements with 0, the next c1 elements with 1, and the next c2 elements with 2.

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the contents of an array
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Function to sort the array of 0s, 1s and 2s
void sortArr(int arr[], int n)
{
	int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;

	// Count the number of 0s, 1s and 2s in the array
	for (i = 0; i < n; i++) {
		switch (arr[i]) {
		case 0:
			cnt0++;
			break;
		case 1:
			cnt1++;
			break;
		case 2:
			cnt2++;
			break;
		}
	}

	// Update the array
	i = 0;

	// Store all the 0s in the beginning
	while (cnt0 > 0) {
		arr[i++] = 0;
		cnt0--;
	}

	// Then all the 1s
	while (cnt1 > 0) {
		arr[i++] = 1;
		cnt1--;
	}

	// Finally all the 2s
	while (cnt2 > 0) {
		arr[i++] = 2;
		cnt2--;
	}

	// Print the sorted array
	printArr(arr, n);
}

// Driver code
int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(int);

	sortArr(arr, n);

	return 0;
}

Move all the negative elements to one side of the array
-------------------------------------------------------------
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Naive approach: The idea is to sort the array of elements, this will make sure that all the negative elements will come before all the positive elements.

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void move(vector<int>& arr){
sort(arr.begin(),arr.end());
}
int main() {

	vector<int> arr = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	move(arr);
	for (int e : arr)
	cout<<e << " ";
	return 0;
}

Another 0(N) sol

// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}

// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver code
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}

Two Pointer Approach: The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :

Check If the left and right pointer elements are negative then simply increment the left pointer.
Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
Repeat the above 3 steps until the left pointer ≤ right pointer.

// C++ program of the above
// approach

#include <iostream>
using namespace std;

// Function to shift all the
// negative elements on left side
void shiftall(int arr[], int left,
			int right)
{

// Loop to iterate over the
// array from left to the right
while (left<=right)
{
	// Condition to check if the left
	// and the right elements are
	// negative
	if (arr[left] < 0 && arr[right] < 0)
	left+=1;
	
	// Condition to check if the left
	// pointer element is positive and
	// the right pointer element is negative
	else if (arr[left]>0 && arr[right]<0)
	{
	int temp=arr[left];
	arr[left]=arr[right];
	arr[right]=temp;
	left+=1;
	right-=1;
	}
	
	// Condition to check if both the
	// elements are positive
	else if (arr[left]>0 && arr[right] >0)
	right-=1;
	else{
	left += 1;
	right -= 1;
	}
}
}

// Function to print the array
void display(int arr[], int right){

// Loop to iterate over the element
// of the given array
for (int i=0;i<=right;++i){
	cout<<arr[i]<<" ";
}
cout<<endl;
}

// Driver Code
int main()
{
int arr[] = {-12, 11, -13, -5,
			6, -7, 5, -3, 11};
int arr_size = sizeof(arr) /
				sizeof(arr[0]);

// Function Call
shiftall(arr,0,arr_size-1);
display(arr,arr_size-1);
return 0;
}

Approach 3:
Here, we will use the famous Dutch National Flag Algorithm for two “colors”. The first color will be for all negative integers and the second color will be for all positive integers. We will divide the array into three partitions with the help of two pointers, low and high. 

ar[1…low-1] negative integers
ar[low…high] unknown
ar[high+1…N] positive integers
Now, we explore the array with the help of low pointer, shrinking the unknown partition, and moving elements to their correct partition in the process. We do this until we have explored all the elements, and size of the unknown partition shrinks to zero.

Below is the implementation of the above approach:


#include <iostream>
using namespace std;
 
// Swap Function.
void swap(int &a,int &b){
  int temp =a;
  a=b;
  b=temp;
}
   
// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}
void displayArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main() {
    // Data
    int arr[] = {1, 2,  -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2,  1};
      int n = sizeof(arr)/sizeof(arr[0]);
      reArrange(arr,n);
    displayArray(arr,n);
    return 0;
}

Find the Union and Intersection of the two sorted arrays.
----------------------------------------------------------------

For example, if the input arrays are: 

arr1[] = {7, 1, 5, 2, 3, 6} 
arr2[] = {3, 8, 6, 20, 7} 
Then your program should print Union as {1, 2, 3, 5, 6, 7, 8, 20} and Intersection as {3, 6, 7}. Note that the elements of union and intersection can be printed in any order.

Method 1 (Using Set):

Union of two arrays we can get with the Set data structure very easily. Set is a data structure that allows only the distinct elements in it. So, when we put the elements of both the array into the set we will get only the distinct elements that are equal to the union operation over the arrays. Let’s code it now –> 


// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
 
    // Defining set container s
    set<int> s;
 
    // Inserting array elements in s
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
 
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: "
         << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " "; // s will contain only distinct
                             // elements from array a and b
}
 
// Driver Code
int main()
{
    int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
 
    getUnion(a, 9, b, 10);
}

Method 2: (Using map data structure)

From the knowledge of data structures, we know that map stores distinct keys only. So if we insert any key appearing more than one time it gets stored only once. The idea is to insert both the arrays in one common map which would then store the distinct elements of both arrays (union of both the array).

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
void printUnion(int* a, int n, int* b, int m)
{
 
    // Defining map container mp
    map<int, int> mp;
 
    // Inserting array elements in mp
    for (int i = 0; i < n; i++)
        mp.insert({ a[i], i });
 
    for (int i = 0; i < m; i++)
        mp.insert({ b[i], i });
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first
             << " "; // mp will contain only distinct
                     // elements from array a and b
}
 
// Driver Code
int main()
{
    int a[7] = { 1, 2, 5, 6, 2, 3, 5 };
    int b[9] = { 2, 4, 5, 6, 8, 9, 4, 6, 5 };
 
    printUnion(a, 7, b, 9);
}

Write a program to cyclically rotate an array by one.
--------------------------------------------------------
Given an array, cyclically rotate the array clockwise by one. 

Examples:  

Input:  arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}

Following are steps. 
1) Store last element in a variable say x. 
2) Shift all elements one position ahead. 
3) Replace first element of array with x.

// C++ code for program
// to cyclically rotate
// an array by one
# include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
	int x = arr[n - 1], i;
	for (i = n - 1; i > 0; i--)
	arr[i] = arr[i - 1];
	arr[0] = x;
}

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 5}, i;
	int n = sizeof(arr) /
			sizeof(arr[0]);

	cout << "Given array is \n";
	for (i = 0; i < n; i++)
		cout << arr[i] << ' ';

	rotate(arr, n);

	cout << "\nRotated array is\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << ' ';

	return 0;
}

Another approach:

We can use two pointers, say i and j which point to first and last element of array respectively. As we know in cyclic rotation we will bring last element to first and shift rest in forward direction, so start swapping arr[i] and arr[j] and keep j fixed and i moving towards j.  Repeat till i is not equal to j.

#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
	int i = 0, j = n-1; // i and j pointing to first and last element respectively
	while(i != j){
	swap(arr[i], arr[j]);
	i++;
	}
}

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 5}, i;
	int n = sizeof(arr) /
			sizeof(arr[0]);

	cout << "Given array is \n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	rotate(arr, n);

	cout << "\nRotated array is\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

Find Largest sum contiguous Subarray
--------------------------------------------
The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.

Pseudocode:

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0
Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

Illustration:

    Lets take the example: {-2, -3, 4, -1, -2, 1, 5, -3}
    max_so_far = INT_MIN
    max_ending_here = 0

    for i=0,  a[0] =  -2
    max_ending_here = max_ending_here + (-2)
    Set max_ending_here = 0 because max_ending_here < 0
    and set max_so_far = -2

    for i=1,  a[1] =  -3
    max_ending_here = max_ending_here + (-3)
    Since max_ending_here = -3 and max_so_far = -2, max_so_far will remain -2
    Set max_ending_here = 0 because max_ending_here < 0

    for i=2,  a[2] =  4
    max_ending_here = max_ending_here + (4)
    max_ending_here = 4
    max_so_far is updated to 4 because max_ending_here greater 
    than max_so_far which was -2 till now

    for i=3,  a[3] =  -1
    max_ending_here = max_ending_here + (-1)
    max_ending_here = 3

    for i=4,  a[4] =  -2
    max_ending_here = max_ending_here + (-2)
    max_ending_here = 1

    for i=5,  a[5] =  1
    max_ending_here = max_ending_here + (1)
    max_ending_here = 2

    for i=6,  a[6] =  5
    max_ending_here = max_ending_here + (5)
    max_ending_here = 7
    max_so_far is updated to 7 because max_ending_here is 
    greater than max_so_far

    for i=7,  a[7] =  -3
    max_ending_here = max_ending_here + (-3)
    max_ending_here = 4

Follow the below steps to Implement the idea:

Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
Run a for loop form 0 to N-1 and for each index i: 
Add the arr[i] to max_ending_here.
If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
If max_ending_here < 0 then update max_ending_here = 0
Return max_so_far

// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}

Another:

Follow the below steps to implement the idea:

Initialize the variables s, start, and end with 0 and max_so_far = INT_MIN and max_ending_here = 0
Run a for loop form 0 to N-1 and for each index i: 
Add the arr[i] to max_ending_here.
If max_so_far is less than max_ending_here then update max_so_far to max_ending_here and update start to s and end to i .
If max_ending_here < 0 then update max_ending_here = 0 and s with i+1.
Print values from index start to end.

// C++ program to print largest contiguous array sum

#include <climits>
#include <iostream>
using namespace std;

void maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
		start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here += a[i];

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is " << max_so_far
		<< endl;
	cout << "Starting index " << start << endl
		<< "Ending index " << end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	return 0;
}

Minimize the maximum difference between heights
----------------------------------------------------

Given the heights of N towers and a value of K, Either increase or decrease the height of every tower by K (only once) where K > 0. After modifications, the task is to minimize the difference between the heights of the longest and the shortest tower and output its difference.

Examples: 

Input: arr[] = {1, 15, 10}, k = 6
Output:  Maximum difference is 5.
Explanation: Change 1 to 7, 15 to 9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can’t get a lower difference.

Input: arr[] = {1, 5, 15, 10}, k = 3   
Output: Maximum difference is 8, arr[] = {4, 8, 12, 7}

The idea for this is given below:

The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights, then calculate the maximum height difference.
This can be achieved using sorting.
Illustration:

Given arr[] = {1, 15, 10}, n = 3, k = 6

Array after sorting => arr[] = {1, 10, 15}

Initially maxHeight = arr[n – 1] = 15
            minHeight = arr[0] = 1
            ans = maxHeight – minHeight = 15 – 1 = 14

At i = 1

minHeight = min(arr[0] + k, arr[i] – k) = min(1 + 6, 10 – 6) = 4
maxHeight = max(arr[i – 1] + k, arr[n – 1] – k) = max(1 + 6, 15 – 6) = 9
ans = min(ans, maxHeight – minHeight) = min(14, 9 – 4) = 5 => ans = 5

At i = 2

minHeight = min(arr[0] + k, arr[i] – k) = min(1 + 6, 15 – 6) = 7
maxHeight = max(arr[i – 1] + k, arr[n – 1] – k) = max(10 + 6, 15 – 6) = 16
ans = min(ans, maxHeight – minHeight) = min(5, 16 – 7) = 5 => ans = 5
Hence minimum difference is 5 

Note:- Consider where a[i] < K because the height of the tower can’t be negative so neglect that case.

Follow the steps below to solve the given problem:

Sort the array 
Try to make each height of the tower maximum by decreasing the height of all the towers to the right by k and increasing all the height of the towers to the left by k. Check whether the current index tower has the maximum height or not by comparing it with a[n]-k. If the tower’s height is greater than the a[n]-k then it’s the tallest tower available.
Similarly, find the shortest tower and minimize the difference between these two towers.  

// C++ Code for the Approach

#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(int arr[], int n, int k)
{
	sort(arr, arr + n);

	// Maximum possible height difference
	int ans = arr[n - 1] - arr[0];

	int tempmin, tempmax;
	tempmin = arr[0];
	tempmax = arr[n - 1];

	for (int i = 1; i < n; i++) {

		// If on subtracting k we got
		// negative then continue
		if (arr[i] - k < 0)
			continue;

		// Minimum element when we
		// add k to whole array
		tempmin = min(arr[0] + k, arr[i] - k);

		// Maximum element when we
		// subtract k from whole array
		tempmax = max(arr[i - 1] + k, arr[n - 1] - k);

		ans = min(ans, tempmax - tempmin);
	}
	return ans;
}

// Driver Code Starts
int main()
{

	int k = 6, n = 6;
	int arr[n] = { 7, 4, 8, 8, 8, 9 };

	// Function Call
	int ans = getMinDiff(arr, n, k);
	cout << ans;
}

Minimum no. of Jumps to reach end of an array
--------------------------------------------------------
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then we cannot move through that element. If we can’t reach the end, return -1.

Examples: 

Input:  arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 -> 9)
 
Explanation: Jump from 1st element to 
2nd element as there is only 1 step, 
now there are three options 5, 8 or 9. 
If 8 or 9 is chosen then the end node 9 
can be reached. So 3 jumps are made.
Input  :  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
Output : 10

Explanation: In every step a jump is 
needed so the count of jumps is 10.

Implementation: Variables to be used: 

maxReach The variable maxReach stores at all times the maximal reachable index in the array.
jump stores the amount of jumps necessary to reach the maximal reachable position. It also indicates the current jump we are making in the array.
step The variable step stores the number of steps we can still take in the current jump ‘jump’ (and is initialized with value at index 0, i.e. initial number of steps)
Given array arr = 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 

maxReach = arr[0]; // arr[0] = 1, so the maximum index we can reach at the moment is 1. 
step = arr[0]; // arr[0] = 1, the amount of steps we can still take is also 1. 
jump = 1; // we are currently making our first jump.
Now, starting iteration from index 1, the above values are updated as follows:

First, we test whether we have reached the end of the array, in that case, we just need to return the jump variable.
if (i == arr.length - 1)
    return jump;
Next we update the maxReach. This is equal to the maximum of maxReach and i+arr[i](the number of steps we can take from the current position). 
maxReach = Math.max(maxReach, i+arr[i]);
We used up a step to get to the current index, so steps has to be decreased. 
step--;
If no more steps are remaining (i.e. steps=0, then we must have used a jump. Therefore increase jump. Since we know that it is possible somehow to reach maxReach, we again initialize the steps to the number of steps to reach maxReach from position i. But before re-initializing step, we also check whether a step is becoming zero or negative. In this case, It is not possible to reach further. 
if (step == 0) {
    jump++;
    if(i>=maxReach)
       return -1;
    step = maxReach - i;
} 

// C++ program to count Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

	// The number of jumps needed to
	// reach the starting index is 0
	if (n <= 1)
		return 0;

	// Return -1 if not possible to jump
	if (arr[0] == 0)
		return -1;

	// initialization
	// stores all time the maximal
	// reachable index in the array.
	int maxReach = arr[0];

	// stores the number of steps
	// we can still take
	int step = arr[0];

	// stores the number of jumps
	// necessary to reach that maximal
	// reachable position.
	int jump = 1;

	// Start traversing array
	int i = 1;
	for (i = 1; i < n; i++) {
		// Check if we have reached the end of the array
		if (i == n - 1)
			return jump;

		// updating maxReach
		maxReach = max(maxReach, i + arr[i]);

		// we use a step to get to the current index
		step--;

		// If no further steps left
		if (step == 0) {
			// we must have used a jump
			jump++;

			// Check if the current index/position or lesser index
			// is the maximum reach point from the previous indexes
			if (i >= maxReach)
				return -1;

			// re-initialize the steps to the amount
			// of steps to reach maxReach from position i.
			step = maxReach - i;
		}
	}

	return -1;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);

	// Calling the minJumps function
	cout << ("Minimum number of jumps to reach end is %d ",
			minJumps(arr, size));
	return 0;
}

Another Approach:

For solving minimum jumps to reach the end of the array,
For every jump index, we consider needing to evaluate the corresponding step values in the index and using the index value divides the array into sub-parts and find out the maximum steps covered index.
The following code and explanation will give you a clear idea:
In each sub-array find out the max distance covered index as the first part of the array, and the second array
Input Array : {1, 3, 5, 9, 6, 2, 6, 7, 6, 8, 9} -> index position starts with 0

Steps :

Initial step is considering the first index and incrementing the jump

Jump = 1

1, { 3, 5, 9, 6, 2, 6, 7, 6, 8, 9} -> 1 is considered as a first jump

next step

From the initial step, there is only one step to move so

Jump = 2

1,3, { 5, 9, 6,2, 6, 7, 6, 8, 9} -> 1 is considered as a first jump

next step

Now we have the flexibility to choose any of {5,9,6} because the last step says we can move up to 3 steps

Consider it as a subarray, evaluate the max distance covers with each index position

As {5,9,6} index positions are {2,3,4}

so the total farther steps we can cover:

{7,12,10} -> we can assume it as {7,12} & {10} are 2 sub-arrays where left part of arrays says max distance covered with 2 steps and right side array says max steps cover with remaining values

next step:

Considering the maximum distance covered in first array we iterate the remaining next elements

1,3,9 {6,2, 6, 7, 6, 8, 9}

From above step we already visited the 4th index we continue with next 5th index as explained above

{6,2, 6, 7, 6, 8, 9} index positions {4,5,6,7,8,9,10}

{10,7,12,14,14,17,19}

Max step covers here is 19 which corresponding index is 10

// C++ program to illustrate Minimum
// number of jumps to reach end

#include <iostream>

using namespace std;

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
	// The number of jumps needed to
	// reach the starting index is 0
	if (n <= 1)
		return 0;

	// Return -1 if not possible to jump
	if (arr[0] == 0)
		return -1;

	// Stores the number of jumps
	// necessary to reach that maximal
	// reachable position.
	int jump = 1;

	// Stores the subarray last index
	int subArrEndIndex = arr[0];

	int i = 1;

	// Maximum steps covers in
	// first half of sub array
	int subArrFistHalfMaxSteps = 0;

	// Maximum steps covers
	// in second half of sub array
	int subArrSecondHalfMaxSteps = 0;

	// Start traversing array
	for (i = 1; i < n;) {

		subArrEndIndex = i + subArrEndIndex;
	
		// Check if we have reached
		// the end of the array
		if (subArrEndIndex >= n)
			return jump;

		int firstHalfMaxStepIndex = 0;
	
		// Iterate the sub array
		// and find out the maxsteps
		// cover index
		for (; i < subArrEndIndex; i++) {
			int stepsCanCover = arr[i] + i;
			if (subArrFistHalfMaxSteps < stepsCanCover) {
				subArrFistHalfMaxSteps = stepsCanCover;
				subArrSecondHalfMaxSteps = 0;
				firstHalfMaxStepIndex = i;
			}
			else if (subArrSecondHalfMaxSteps
					< stepsCanCover) {
				subArrSecondHalfMaxSteps = stepsCanCover;
			}
		}
		if (i > subArrFistHalfMaxSteps)
			return -1;
		jump++;
	
		// Next subarray end index
		// and so far calculated sub
		// array max step cover value
		subArrEndIndex = arr[firstHalfMaxStepIndex];
		subArrFistHalfMaxSteps = subArrSecondHalfMaxSteps;
	}

	return -1;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
	int size = sizeof(arr) / sizeof(int);

	// Calling the minJumps function
	cout << ("Minimum number of jumps to reach end is %d ",
			minJumps(arr, size));
	return 0;
}

Find duplicate in an array of N+1 Integers	
-----------------------------------------------------
Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and using only constant memory space.

Example: 

Input : n = 7 and array[] = {1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6

Explanation: The numbers 1 , 3 and 6 appears more
than once in the array.

Input : n = 5 and array[] = {1, 2, 3, 4 ,3}
Output: 3

Explanation: The number 3 appears more than once
in the array.

Efficient approach:

Approach: The elements in the array is from 0 to n-1 and all of them are positive. So to find out the duplicate elements, a HashMap is required, but the question is to solve the problem in constant space. There is a catch, the array is of length n and the elements are from 0 to n-1 (n elements). The array can be used as a HashMap. 
Problem in the below approach. This approach only works for arrays having at most 2 duplicate elements i.e It will not work if the array contains more than 2 duplicates of an element. For example: {1, 6, 3, 1, 3, 6, 6} it will give output as : 1 3 6 6.
Note: The above program doesn’t handle 0 cases (If 0 is present in array). The program can be easily modified to handle that also. It is not handled to keep the code simple. (Program can be modified to handle 0 cases by adding plus One(+1) to all the values. also subtracting One from the answer and by writing { arr [abs(arr[i]) – 1] } in code)
In other approach below, the discussed solution prints repeating elements only once.

Approach: The basic idea is to use a HashMap to solve the problem. But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n. So, the input array can be used as a HashMap. While Traversing the array, if an element ‘a’ is encountered then increase the value of a%n‘th element by n. The frequency can be retrieved by dividing the a % n’th element by n.
Algorithm: 
Traverse the given array from start to end.
For every element in the array increment the arr[i]%n‘th element by n.
Now traverse the array again and print all those indexes i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index
This approach works because all elements are in the range from 0 to n-1 and arr[i] would be greater than n only if a value “i” has appeared more than once.

// C++ code to find
// duplicates in O(n) time
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
	int arr_size = sizeof(numRay) / sizeof(numRay[0]);
	// count the frequency
	for (int i = 0; i < arr_size; i++) {
		numRay[numRay[i] % arr_size]
			= numRay[numRay[i] % arr_size] + arr_size;
	}
	cout << "The repeating elements are : " << endl;
	for (int i = 0; i < arr_size; i++) {
		if (numRay[i] >= arr_size * 2) {
			cout << i << " " << endl;
		}
	}
	return 0;
}

Another efficient approach: Modifying array by making visited elements -ve (visited once) or greater than n (visited twice or more)

Approach:
Increment the array elements by 1 (arr[i]+1) to handle occurrence of 0. Traverse the array and for every element that has been visited the first time, make the element at index equal to the value of the current element as negative. If element has already been visited before, add it (arr[i]-1) to result vector and make the element at index equal to the value of current element more than n (by multiplying it with (n+1)) to avoid adding it to result vector, incase it occurs again. 
Algorithm:
Traverse the array and increment each element  by 1. This is done to remove occurrence of 0 from the array. Later, while adding the duplicate elements in the result vector, we decrement elements by 1 to get actual value.
Declare result vector.
Declare a count variable to count the occurrence of (n-1)th element in the array. 
For eg : array = [0,2,4,3,4], n=5, then we need the count variable to count the occurrence of 4. 
In the algorithm, we need to access elements present at index equal to other element values, meaning we have to access values like array[array[i]]. For eg: if i=0, we access array[array[i]] = array[array[0]] = array[1] = 2. Similarly, we might need to access the element at index equal to largest value possible in the array, i.e., n-1 (array[array[n-1]]). However, we incremented each element by 1 and thus largest possible element in the array became n. In 0-based indexing array[n] returns garbage value  and thus our algorithm cannot calculate the occurrence of the largest possible element in the array. Hence we need the count variable to count its occurrence separately and later add it to result vector if found duplicate.
Run a for loop from 0 to n and in each iteration of the loop:
Calculate index value – 
Since we need to access elements present at index equal to other element values, index is the absolute value of arr[i]. If abs(arr[i]) is greater than n, then index is equal to abs(arr[i])/(n+1) else abs(arr[i]). 
If an element ‘x’ occurs twice in the array, we negate the element present at x, i.e., array[x] = -array[x], but if it occurs more than twice, then, to avoid it from getting pushed to result vector again, we make element at x equal to a number greater than n (a number that would never occur in the array). To do this, we multiply it by (n+1), i.e., array[x] = array[x]*(n+1). We cannot multiply with n as if array[x] = 1, then array[x]*n = n, which is the largest possible element and can occur in the array. 
Thus, during traversal, if we come across array[x] which is greater than n, we need to calculate array[x]/(n+1) to get the original value of index.
 
Check if obtained index value is equal to n, if so, increment the count variable and move to the next iteration, as we will calculate the occurrence of n separately.
 
Get the value of element at calculated index in a variable and run the following else-if conditions:
If this value is less than 0 (-ve), it means that element equal to its index has appeared twice, thus push the value of index-1 (as element values had been incremented earlier) in result vector. Going forward, as this index value has already been pushed to result vector, we don’t want a duplicate in result vector if it occurs again and thus, make the value of the element present at this index greater than n by multiplying it with (n+1).
If this value is greater than n, it means that element equal to the index value has already been pushed to result vector and nothing needs to be done. So just continue to the next iteration.
If this value is between 0 and n, it means that the element equal to the index value has appeared for the first time and thus make it negative.
 
After exiting from the for loop, if the value of count variable is more than 1, it means that the largest possible element (n) has duplicates in the array and thus, push (n-1) to result vector.
Check if size of result vector is 0, if so, push -1 as there are no duplicates. Otherwise, sort the result vector
Return the result vector.

#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n)
{

	// Increment array elements by 1
	for (int i = 0; i < n; i++) {
		arr[i] += 1;
	}

	// result vector
	vector<int> res;

	// count variable for count of
	// largest element
	int count = 0;

	for (int i = 0; i < n; i++) {

		// Calculate index value
		int index = abs(arr[i]) > n ? abs(arr[i]) / (n + 1)
									: abs(arr[i]);

		// Check if index equals largest element value
		if (index == n) {
			count++;
			continue;
		}

		// Get element value at index
		int val = arr[index];

		// Check if element value is negative, positive
		// or greater than n
		if (val < 0) {
			res.push_back(index - 1);
			arr[index] = abs(arr[index]) * (n + 1);
		}
		else if (val > n)
			continue;
		else
			arr[index] = -arr[index];
	}

	// If largest element occurs more than once
	if (count > 1)
		res.push_back(n - 1);

	if (res.size() == 0)
		res.push_back(-1);
	else
		sort(res.begin(), res.end());

	return res;
}

// Driver Code
int main()
{
	int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
	int n = sizeof(numRay) / sizeof(numRay[0]);

	vector<int> ans = duplicates(numRay, n);
	for (int i : ans)
		cout << i << ' ' << endl;
	return 0;
}

Merge 2 sorted arrays without using Extra space.
----------------------------------------------------
Given two sorted arrays, the task is to merge them in a sorted manner.
Examples: 

Input: arr1[] = { 1, 3, 4, 5}, arr2[] = {2, 4, 6, 8} 
Output: arr3[] = {1, 2, 3, 4, 4, 5, 6, 8}

Input: arr1[] = { 5, 8, 9}, arr2[] = {4, 7, 8} 
Output: arr3[] = {4, 5, 7, 8, 8, 9} 

Naive Approach:

// C++ program to merge two sorted arrays/
#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int n1,
							int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;
	// traverse the arr1 and insert its element in arr3
	while(i < n1){
	arr3[k++] = arr1[i++];
	}
	
	// now traverse arr2 and insert in arr3
	while(j < n2){
	arr3[k++] = arr2[j++];
	}
	
	// sort the whole array arr3
	sort(arr3, arr3+n1+n2);
}

// Driver code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {2, 4, 6, 8};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int arr3[n1+n2];
	mergeArrays(arr1, arr2, n1, n2, arr3);

	cout << "Array after merging" <<endl;
	for (int i=0; i < n1+n2; i++)
		cout << arr3[i] << " ";

	return 0;
}

Method 2 (O(n1 + n2) Time and O(n1 + n2) Extra Space) 
The idea is to use Merge function of Merge sort. 

Create an array arr3[] of size n1 + n2.
Simultaneously traverse arr1[] and arr2[]. 
Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked.
If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].

// C++ program to merge two sorted arrays/
#include<iostream>
using namespace std;

// Merge arr1[0..n1-1] and arr2[0..n2-1] into
// arr3[0..n1+n2-1]
void mergeArrays(int arr1[], int arr2[], int n1,
							int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i<n1 && j <n2)
	{
		// Check if current element of first
		// array is smaller than current element
		// of second array. If yes, store first
		// array element and increment first array
		// index. Otherwise do same with second array
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	// Store remaining elements of first array
	while (i < n1)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < n2)
		arr3[k++] = arr2[j++];
}

// Driver code
int main()
{
	int arr1[] = {1, 3, 5, 7};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {2, 4, 6, 8};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int arr3[n1+n2];
	mergeArrays(arr1, arr2, n1, n2, arr3);

	cout << "Array after merging" <<endl;
	for (int i=0; i < n1+n2; i++)
		cout << arr3[i] << " ";

	return 0;
}

Method 3: Using Maps (O(nlog(n) + mlog(m)) Time and O(N) Extra Space) 

Insert elements of both arrays in a map as keys.
Print the keys of the map.

// C++ program to merge two sorted arrays
//using maps
#include<bits/stdc++.h>
using namespace std;

// Function to merge arrays
void mergeArrays(int a[], int b[], int n, int m)
{
	// Declaring a map.
	// using map as a inbuilt tool
	// to store elements in sorted order.
	map<int, int> mp;
	
	// Inserting values to a map.
	for(int i = 0; i < n; i++)mp[a[i]]++;
	
	
	for(int i = 0;i < m;i++)mp[b[i]]++;

	
	// Printing keys of the map.
	for(auto j: mp)
	{
		for(int i=0; i<j.second;i++)cout<<j.first<<" ";
	}
}

// Driver Code
int main()
{
	int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6, 8};
	
	int size = sizeof(a)/sizeof(int);
	int size1 = sizeof(b)/sizeof(int);
	
	// Function call
	mergeArrays(a, b, size, size1);
	
	return 0;
}

Kadane’s algo
------------------------------------------------
The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.

SAME:Find Largest sum contiguous Subarray


Merge Intervals
---------------------------------
Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.

Example:

Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10].

Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}} 

Merge Overlapping Intervals Using Nested Loop

A simple approach is to start from the first interval and compare it with all other intervals for overlapping, if it overlaps with any other interval, then remove the other interval from the list and merge the other into the first interval. Repeat the same steps for the remaining intervals after the first. This approach cannot be implemented in better than O(n^2) time.

Merge Overlapping Intervals Optimized Approach

The idea to solve this problem is, first sort the intervals according to the starting time. Once we have the sorted intervals, we can combine all intervals in a linear traversal. The idea is, in sorted array of intervals, if interval[i] doesn’t overlap with interval[i-1], then interval[i+1] cannot overlap with interval[i-1] because starting time of interval[i+1] must be greater than or equal to interval[i].

Follow the steps mentioned below to implement the approach:

Sort the intervals based on the increasing order of starting time.
Push the first interval into a stack.
For each interval do the following:
  If the current interval does not overlap with the top of the stack then, push the current interval into the stack.
  If the current interval overlap with the top of the stack then, update the stack top with the ending time of the current interval.
The end stack contains the merged intervals. 

// A C++ program for merging overlapping intervals
#include <bits/stdc++.h>
using namespace std;

// An interval has start time and end time
struct Interval {
	int start, end;
};

// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
	// Test if the given set has at least one interval
	if (n <= 0)
		return;

	// Create an empty stack of intervals
	stack<Interval> s;

	// sort the intervals in increasing order of start time
	sort(arr, arr + n, compareInterval);

	// push the first interval to stack
	s.push(arr[0]);

	// Start from the next interval and merge if necessary
	for (int i = 1; i < n; i++) {
		// get interval from stack top
		Interval top = s.top();

		// if current interval is not overlapping with stack
		// top, push it to the stack
		if (top.end < arr[i].start)
			s.push(arr[i]);

		// Otherwise update the ending time of top if ending
		// of current interval is more
		else if (top.end < arr[i].end) {
			top.end = arr[i].end;
			s.pop();
			s.push(top);
		}
	}

	// Print contents of stack
	cout << "\n The Merged Intervals are: ";
	while (!s.empty()) {
		Interval t = s.top();
		cout << "[" << t.start << "," << t.end << "] ";
		s.pop();
	}
	return;
}

// Driver program
int main()
{
	Interval arr[]
		= { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}

Merge Overlapping Intervals Space Optimized Approach

The above solution requires O(n) extra space for the stack. We can avoid the use of extra space by doing merge operations in place. Below are detailed steps. 

Follow the steps mentioned below to implement the approach:

Sort all intervals in increasing order of start time.
Traverse sorted intervals starting from the first interval, 
Do the following for every interval.
If the current interval is not the first interval and it overlaps with the previous interval,
then merge it with the previous interval. Keep doing it while the interval overlaps with the previous one.         
Otherwise, Add the current interval to the output list of intervals.

// C++ program to merge overlapping Intervals in
// O(n Log n) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

// An Interval
struct Interval {
	int s, e;
};

// Function used in sort
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)
{
	// Sort Intervals in increasing order of
	// start time
	sort(arr, arr + n, mycomp);

	int index = 0; // Stores index of last element
	// in output array (modified arr[])

	// Traverse all input Intervals
	for (int i = 1; i < n; i++) {
		// If this is not first Interval and overlaps
		// with the previous one
		if (arr[index].e >= arr[i].s) {
			// Merge previous and current Intervals
			arr[index].e = max(arr[index].e, arr[i].e);
		}
		else {
			index++;
			arr[index] = arr[i];
		}
	}

	// Now arr[0..index-1] stores the merged Intervals
	cout << "\n The Merged Intervals are: ";
	for (int i = 0; i <= index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

// Driver program
int main()
{
	Interval arr[]
		= { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}

Next Permutation
---------------------------------------------------
All the permutations of a word when arranged in a dictionary, the order of words so obtained is called lexicographical order. in Simple words, it is the one that has all its elements sorted in ascending order, and the largest has all its elements sorted in descending order.

lexicographically is nothing but the greater permutation of it. 

For reference: a b c d e f g h i j k l m n o p q r s t u v w x y z

For example, lexicographically next permutation of “gfg” is “ggf” and the next permutation of “acb” is “bac”. 
Note: In some cases, the next lexicographically greater word might not exist, e.g, “aaa” and “edcba”. 

// C++ program to demonstrate next lexicographically
// greater permutation of a word

#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	string s = { "gfg" };
	bool val
		= next_permutation(s.begin(),
						s.end());
	if (val == false)
		cout << "No Word Possible"
			<< endl;
	else
		cout << s << endl;
	return 0;
}

The same program can also be implemented without using STL. Below is the code snippet for the same. 

The Idea is Based on the Following Facts: 

1. A sequence sorted in descending order does not have the next permutation. For example “edcba” does not have the next permutation.
2. For a sequence that is not sorted in descending order for example “abedc”, we can follow these steps.  
a) Traverse from the right and find the first item that is not following the ascending order. For example in “abedc”, the character ‘b’ does not follow the ascending order.
b) Swap the found character with the closest greater (or smallest greater) element on the right side of it. In the case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, the string becomes “acedb”.
c) After swapping, reverse the string after the position of the character found in step a. After reversing the substring “edb” of “acedb”, we get “acbde” which is the required next permutation. 
Optimizations in steps b) and c) 

 a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element. 

 c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it. 

// C++ program to demonstrate
// the next lexicographically
// greater permutation of a word
#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
	if (*a == *b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void rev(string& s, int l, int r)
{
	while (l < r)
		swap(&s[l++], &s[r--]);
}

int bsearch(string& s, int l, int r, int key)
{
	int index = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (s[mid] <= key)
			r = mid - 1;
		else {
			l = mid + 1;
			if (index == -1 || s[index] >= s[mid])
				index = mid;
		}
	}
	return index;
}

bool nextpermutation(string& s)
{
	int len = s.length(), i = len - 2;
	while (i >= 0 && s[i] >= s[i + 1])
		--i;
	if (i < 0)
		return false;
	else {
		int index = bsearch(s, i + 1, len - 1, s[i]);
		swap(&s[i], &s[index]);
		rev(s, i + 1, len - 1);
		return true;
	}
}

// Driver code
int main()
{
	string s = { "gfg" };
	bool val = nextpermutation(s);
	if (val == false)
		cout << "No Word Possible" << endl;
	else
		cout << s << endl;
	return 0;
}

Count Inversion
------------------------------------------------
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

Given an array a[]. The task is to find the inversion count of a[]. Wher two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Examples: 

Input: arr[] = {8, 4, 2, 1}
Output: 6
Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 

Naive Approach:

Traverse through the array, and for every index, find the number of smaller elements on its right side of the array. This can be done using a nested loop. Sum up the counts for all indices in the array and print the sum.

Follow the below steps to Implement the idea:

Traverse through the array from start to end
For every element, find the count of elements smaller than the current number up to that index using another loop.
Sum up the count of inversion for every index.
Print the count of inversions.

// C++ program to Count Inversions
// in an array
#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}

// Driver Code
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << " Number of inversions are "
		<< getInvCount(arr, n);
	return 0;
}

Best time to buy and Sell stock	
-----------------------------------------
Type I: At most one transaction is allowed

Given an array prices[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most one transaction is allowed.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = {7, 1, 5, 3, 6, 4]
Output: 5
Explanation:
The lowest price of the stock is on the 2nd day, i.e. price = 1. Starting from the 2nd day, the highest price of the stock is witnessed on the 5th day, i.e. price = 6. 
Therefore, maximum possible profit = 6 – 1 = 5. 

Input: prices[] = {7, 6, 4, 3, 1} 
Output: 0
Explanation: Since the array is in decreasing order, no possible way exists to solve the problem.

Approach 1:
This problem can be solved using the greedy approach. To maximize the profit we have to minimize the buy cost and we have to sell it at maximum price. 
Follow the steps below to implement the above idea:

Declare a buy variable to store the buy cost and max_profit to store the maximum profit.
Initialize the buy variable to the first element of the prices array.
Iterate over the prices array and check if the current price is minimum or not.
If the current price is minimum then buy on this ith day.
If the current price is greater than the previous buy then make profit from it and maximize the max_profit.
Finally, return the max_profit.

// C++ code for the above approach
#include <iostream>
using namespace std;

int maxProfit(int prices[], int n)
{
	int buy = prices[0], max_profit = 0;
	for (int i = 1; i < n; i++) {

		// Checking for lower buy value
		if (buy > prices[i])
			buy = prices[i];

		// Checking for higher profit
		else if (prices[i] - buy > max_profit)
			max_profit = prices[i] - buy;
	}
	return max_profit;
}

// Driver Code
int main()
{
	int prices[] = { 7, 1, 5, 6, 4 };
	int n = sizeof(prices) / sizeof(prices[0]);
	int max_profit = maxProfit(prices, n);
	cout << max_profit << endl;
	return 0;
}

Approach 2: The given problem can be solved based on the idea of finding the maximum difference between two array elements with smaller number occurring before the larger number. Therefore, this problem can be reduced to finding max⁡(prices[j]−prices[i]) for every pair of indices i and j, such that j>i.

// C++ program for the above approach

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find maximum profit possible
// by buying and selling at most one stack
int findMaximumProfit(vector<int>& prices, int i, int k,
					bool buy, vector<vector<int> >& v)
{
	// If no stock can be chosen
	if (i >= prices.size() || k <= 0)
		return 0;

	if (v[i][buy] != -1)
		return v[i][buy];

	// If a stock is already bought
	if (buy) {
		return v[i][buy]
			= max(-prices[i]
						+ findMaximumProfit(prices, i + 1,
											k, !buy, v),
					findMaximumProfit(prices, i + 1, k,
									buy, v));
	}

	// Otherwise
	else {
		// Buy now
		return v[i][buy]
			= max(prices[i]
						+ findMaximumProfit(
							prices, i + 1, k - 1, !buy, v),
					findMaximumProfit(prices, i + 1, k,
									buy, v));
	}
}

// Function to find the maximum
// profit in the buy and sell stock
int maxProfit(vector<int>& prices)
{

	int n = prices.size();
	vector<vector<int> > v(n, vector<int>(2, -1));

	// buy = 1 because atmost one
	// transaction is allowed
	return findMaximumProfit(prices, 0, 1, 1, v);
}

// Driver Code
int main()
{
	// Given prices
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };

	// Function Call to find the
	// maximum profit possible by
	// buying and selling a single stock
	int ans = maxProfit(prices);

	// Print answer
	cout << ans << endl;

	return 0;
}

Type II: Infinite transactions are allowed

Given an array price[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where any number of transactions are allowed.

Examples: 

Input: prices[] = {7, 1, 5, 3, 6, 4} 
Output: 7
Explanation:
Purchase on 2nd day. Price = 1.
Sell on 3rd day. Price = 5.
Therefore, profit = 5 – 1 = 4.
Purchase on 4th day. Price = 3.
Sell on 5th day. Price = 6.
Therefore, profit = 4 + (6 – 3) = 7.

Input: prices = {1, 2, 3, 4, 5} 
Output: 4
Explanation: 
Purchase on 1st day. Price = 1.
Sell on 5th day. Price = 5. 
Therefore, profit = 5 – 1 = 4.

Approach: The idea is to maintain a boolean value that denotes if there is any current purchase ongoing or not. If yes, then at the current state, the stock can be sold to maximize profit or move to the next price without selling the stock. Otherwise, if no transaction is happening, the current stock can be bought or move to the next price without buying.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate maximum
// profit possible by buying or
// selling stocks any number of times
int find(int ind, vector<int>& v, bool buy,
         vector<vector<int> >& memo)
{
 
    // No prices left
    if (ind >= v.size())
        return 0;
 
    // Already found
    if (memo[ind][buy] != -1)
        return memo[ind][buy];
 
    // Already bought, now sell
    if (buy) {
        return memo[ind][buy]
               = max(-v[ind] + find(ind + 1, v, !buy, memo),
                     find(ind + 1, v, buy, memo));
    }
 
    // Otherwise, buy the stock
    else {
        return memo[ind][buy]
               = max(v[ind] + find(ind + 1, v, !buy, memo),
                     find(ind + 1, v, buy, memo));
    }
}
 
// Function to find the maximum
// profit possible by buying and
// selling stocks any number of times
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if (n < 2)
        return 0;
 
    vector<vector<int> > v(n + 1, vector<int>(2, -1));
    return find(0, prices, 1, v);
}
 
// Driver Code
int main()
{
 
    // Given prices
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
 
    // Function Call to calculate
    // maximum profit possible
    int ans = maxProfit(prices);
 
    // Print the total profit
    cout << ans << endl;
    return 0;
}

Method 2 :- Optimised Solution

One more way to solve the problem is to think of the situation when we buy the stocks in the beginning of the upstreak in the stock graph and sell it at the highest point of that upstreak line of the graph. We just have to calculate the sum of all the upstreaks that are present in the graph.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the maximum profit possible by buying
// and selling stocks any number of times
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if (n < 2)
        return 0;
    int sellingDate = 0;
    int buyingDate = 0;
    int totalProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] >= prices[i - 1])
            sellingDate++;
        else {
            totalProfit += (prices[sellingDate] - prices[buyingDate]);
            sellingDate = buyingDate = i;
        }
    }
    totalProfit += (prices[sellingDate] - prices[buyingDate]);
    return totalProfit;
}
 
// Driver Code
int main()
{
    // Given prices
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    // Function Call to calculate maximum profit possible
    int ans = maxProfit(prices);
    // Print the total profit
    cout << ans << endl;
    return 0;
}
 
Type III: At most two transactions are allowed

Problem: Given an array price[] of length N which denotes the prices of the stocks on different days. The task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most two transactions are allowed.

Note: Stock must be bought before being sold. 

Input: prices[] = {3, 3, 5, 0, 0, 3, 1, 4} 
Output: 6 
Explanation: 
Buy on Day 4 and Sell at Day 6 => Profit = 3 0 = 3 
Buy on Day 7 and Sell at Day 8 => Profit = 4 1 = 3 
Therefore, Total Profit = 3 + 3 = 6

Input: prices[] = {1, 2, 3, 4, 5} 
Output: 4 
Explanation: 
Buy on Day 1 and sell at Day 6 => Profit = 5 1 = 4 
Therefore, Total Profit = 4 

Approach 1: The problem can be solved by following the above approach. Now, if the number of transactions is equal to 2, then the current profit can be the desired answer. Similarly, Try out all the possible answers by memoizing them into the DP Table.

// C++ program for the above approach
 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Function to find the maximum
// profit in the buy and sell stock
int find(vector<int>& prices, int ind, bool buy, int c,
         vector<vector<vector<int> > >& memo)
{
    // If buy =1 means buy now
    // else sell
    if (ind >= prices.size() || c >= 2)
        return 0;
    if (memo[ind][buy] != -1)
        return memo[ind][buy];
 
    // Already bought, sell now
    if (buy) {
        return memo[ind][buy]
               = max(-prices[ind]
                         + find(prices, ind + 1, !buy, c,
                                memo),
                     find(prices, ind + 1, buy, c, memo));
    }
 
    // Can buy stocks
    else {
        return memo[ind][buy]
               = max(prices[ind]
                         + find(prices, ind + 1, !buy,
                                c + 1, memo),
                     find(prices, ind + 1, buy, c, memo));
    }
}
 
// Function to find the maximum
// profit in the buy and sell stock
int maxProfit(vector<int>& prices)
{
    // Here maximum two transaction are allowed
 
    // Use 3-D vector because here
    // three states are there: i,k,buy/sell
    vector<vector<vector<int> > > memo(
        prices.size(),
        vector<vector<int> >(2, vector<int>(2, -1)));
 
    // Answer
    return find(prices, 0, 1, 0, memo);
}
 
// Driver Code
int main()
{
 
    // Given prices
    vector<int> prices = { 3, 3, 5, 0, 0, 3, 1, 4 };
 
    // Function Call
    int ans = maxProfit(prices);
 
    // Answer
    cout << ans << endl;
    return 0;
}

Type IV: At most K transactions are allowed

Problem: Given an array price[] of length N which denotes the prices of the stocks on different days. The task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most K transactions are allowed.

Note: Stock must be bought before being sold.

Examples: 

Input: K = 2, prices[] = {2, 4, 1} 
Output: 2
Explanation: Buy on day 1 when price is 2 and sell on day 2 when price is 4. Therefore, profit = 4-2 = 2.

Input: K = 2, prices[] = {3, 2, 6, 5, 0, 3} 
Output: 7
Explanation: 
Buy on day 2 when price is 2 and sell on day 3 when price is 6. Therefore, profit = 6-2 = 4.
Buy on day 5 when price is 0 and sell on day 6 when price is 3. Therefore, profit = 3-0 = 3.
Therefore, the total profit = 4+3 = 7

Approach: The idea is to maintain the count of transactions completed till and compare the count of the transaction to K. If it is less than K then buy and sell the stock. Otherwise, the current profit can be the maximum profit.

// C++ program for the above approach
 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Function to find the maximum
// profit with atmost K transactions
int find(vector<int>& prices, int ind, bool buy, int c,
         int k, vector<vector<vector<int> > >& memo)
{
 
    // If there are no more transaction
    // allowed, return the profit as 0
    if (ind >= prices.size() || c >= k)
        return 0;
 
    // Memoize
    else if (memo[ind][buy] != -1)
        return memo[ind][buy];
 
    // Already bought, now sell
    if (buy) {
        return memo[ind][buy] = max(
                   -prices[ind]
                       + find(prices, ind + 1, !buy, c, k,
                              memo),
                   find(prices, ind + 1, buy, c, k, memo));
    }
 
    // Stocks can be bought
    else {
        return memo[ind][buy] = max(
                   prices[ind]
                       + find(prices, ind + 1, !buy, c + 1,
                              k, memo),
                   find(prices, ind + 1, buy, c, k, memo));
    }
}
 
// Function to find the maximum profit
// in the buy and sell stock
int maxProfit(int k, vector<int>& prices)
{
    // If transactions are greater
    // than number of prices
    if (2 * k > prices.size()) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
 
    // Maximum k transaction
    vector<vector<vector<int> > > memo(
        prices.size() + 1,
        vector<vector<int> >(2, vector<int>(k + 1, -1)));
    return find(prices, 0, 1, 0, k, memo);
}
 
// Driver Code
int main()
{
 
    // Given prices
    vector<int> prices = { 2, 4, 1 };
 
    // Given K
    int k = 2;
 
    // Function Call
    int ans = maxProfit(k, prices);
 
    // Print answer
    cout << ans << endl;
    return 0;
}

Find all pairs on integer array whose sum is equal to given number	
---------------------------------------------------------------------
Given an array of N integers, and a number sum, the task is to find the number of pairs of integers in the array whose sum is equal to sum.

Examples:  

Input:  arr[] = {1, 5, 7, -1}, sum = 6
Output:  2
Explanation: Pairs with sum 6 are (1, 5) and (7, -1).

Input:  arr[] = {1, 5, 7, -1, 5}, sum = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).         

Input:  arr[] = {1, 1, 1, 1}, sum = 2
Output:  6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

Input:  arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}, sum = 11
Output:  9
Explanation: Pairs with sum 11 are (10, 1), (10, 1), (10, 1), (12, -1), (10, 1), (10, 1), (10, 1), (7, 4), (6, 5).

Naive Approach: 

A simple solution is to traverse each element and check if there’s another number in the array which can be added to it to give sum.
This can be achieved by nested loops.

Illustration:

Given arr[] = {1, 5, 7, -1}, sum = 6
count = 0

First Iteration : For index = 0
{1, 5, 7, -1}, pair = (1, 5), count = 1
Second Iteration : For index = 1
{1, 5, 7, -1}, count = 1
Third Iteration : For index = 2
{1, 5, 7, -1}, count = 2
Hence output is 2

Follow the steps below to solve the given problem:

Initialize the count variable with 0 which stores the result.
Iterate arr and if the sum of ith and jth [i + 1…..n – 1] element is equal to sum i.e. arr[i] + arr[j] == sum, then increment the count variable.
Return the count.

// C++ implementation of simple method to find count of
// pairs with given sum.
#include <bits/stdc++.h>
using namespace std;

// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
int getPairsCount(int arr[], int n, int sum)
{
	int count = 0; // Initialize result

	// Consider all possible pairs and check their sums
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] + arr[j] == sum)
				count++;

	return count;
}

// Driver function to test the above function
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, sum);
	return 0;
}

Using Binary Search
This approach is based on the following idea:

If the array is sorted then for each array element arr[i], find the number of pairs by finding all the values (sum – arr[i]) which are situated after ith index.
This can be achieved using Binary Search.

Illustration:

Given arr[] = {1, 5, 7, -1}, sum = 6

Array after sorting: arr[] = {-1, 1, 5, 7}
count = 0

At index = 0: val = sum – arr[0] = 6 – (-1) = 7
count = count + upperBound(1, 3, 7) – lowerBound(1, 3, 7)
count = 1

At index = 1: val = sum – arr[1] = 6 – 1 = 5
count = count + upperBound(2, 3, 5) – lowerBound(2, 3, 5)
count = 2

At index = 2: val = sum – arr[2] = 6 – 5 = 1
count = count + upperBound(3, 3, 1) – lowerBound(3, 3, 1)
count = 2

Number of pairs = 2

Follow the steps below to solve the given problem:

Sort the array arr[] in increasing order.
Loop from i = 0 to N-1.
Find the index of the first element having value same or just greater than (sum – arr[i]) using lower bound.
Find the index of the first element having value just greater than (sum – arr[i]) using upper bound.
The gap between these two indices is the number of elements with value same as (sum – arr[i]).
Add this with the final count of pairs.
Return the final count after the iteration is over.

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of pairs
int getPairsCount(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int x = 0, c = 0, y, z;
	for (int i = 0; i < n - 1; i++) {
		x = k - arr[i];

		// Lower bound from i+1
		int y = lower_bound(arr + i + 1, arr + n, x) - arr;

		// Upper bound from i+1
		int z = upper_bound(arr + i + 1, arr + n, x) - arr;
		c = c + z - y;
	}
	return c;
}

// Driver code
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;

	// Function call
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, k);
	return 0;
}

Using Hashing
This approach is based on the following idea:

Check the frequency of sum – arr[i] in the arr
This can be achieved using Hashing.
Illustration:

Given arr[] = {1, 5, 7, -1}, sum = 6

Store the frequency of every element: 
freq[arr[i]] = freq[arr[i]] + 1
freq[1] : 1
freq[5] : 1
freq[7] : 1
freq[-1] : 1
 
Initialise a variable count with 0 to find the required count of pairs
At index = 0: freq[sum – arr[0]] = freq[6 – 1] = freq[5] = 1
count = 1
At index = 1: freq[sum – arr[1]] = freq[6 – 5] = freq[1] = 1
count = 2
At index = 2: freq[sum – arr[2]] = freq[6 – 7] = freq[-1] = 1
count = 3
At index = 3: freq[sum – arr[3]] = freq[6 – (-1)] = freq[7] = 1
count = 4
The above also contains repeated pairs from front and last, i.e. pair (a, b) and (b, a) are considered as different pairs till now.
Therefore, we will reduce the count by half to determine the count of unique pairs.
count = count / 2 = 2
Therefore, required Number of pairs with given sum = 2
Follow the steps below to solve the given problem: 

Create a map to store the frequency of each number in the array. (Single traversal is required)
In the next traversal, for every element check if it can be combined with any other element (other than itself!) to give the desired sum. Increment the counter accordingly.
After completion of the second traversal, we’d have twice the required value stored in counter because every pair is counted two times. Hence divide the count by 2 and return.

// C++ implementation of simple method to find count of
// pairs with given sum.
#include <bits/stdc++.h>
using namespace std;

// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
int getPairsCount(int arr[], int n, int sum)
{
	unordered_map<int, int> m;

	// Store counts of all elements in map m
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	int twice_count = 0;

	// iterate through each element and increment the
	// count (Notice that every pair is counted twice)
	for (int i = 0; i < n; i++) {
		twice_count += m[sum - arr[i]];

		// if (arr[i], arr[i]) pair satisfies the condition,
		// then we need to ensure that the count is
		// decreased by one such that the (arr[i], arr[i])
		// pair is not considered
		if (sum - arr[i] == arr[i])
			twice_count--;
	}

	// return the half of twice_count
	return twice_count / 2;
}

// Driver function to test the above function
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, sum);
	return 0;
}

Find common elements In 3 sorted arrays	
-----------------------------------------------------
Given three arrays sorted in non-decreasing order, print all common elements in these arrays.

Examples: 

Input: 
ar1[] = {1, 5, 10, 20, 40, 80} 
ar2[] = {6, 7, 20, 80, 100} 
ar3[] = {3, 4, 15, 20, 30, 70, 80, 120} 
Output: 20, 80

Input: 
ar1[] = {1, 5, 5} 
ar2[] = {3, 4, 5, 5, 10} 
ar3[] = {5, 5, 10, 20} 
Output: 5, 5

A simple solution is to first find intersection of two arrays and store the intersection in a temporary array, then find the intersection of third array and temporary array. 
Time complexity of this solution is O(n1 + n2 + n3) where n1, n2 and n3 are sizes of ar1[], ar2[] and ar3[] respectively.
The above solution requires extra space and two loops, we can find the common elements using a single loop and without extra space. The idea is similar to intersection of two arrays. Like two arrays loop, we run a loop and traverse three arrays. 
Let the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z. We can have following cases inside the loop. 

If x, y and z are same, we can simply print any of them as common element and move ahead in all three arrays.
Else If x < y, we can move ahead in ar1[] as x cannot be a common element.
Else If x > z and y > z), we can simply move ahead in ar3[] as z cannot be a common element.

// C++ program to print common elements in three arrays
#include <bits/stdc++.h>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1,
				int n2, int n3)
{
	// Initialize starting indexes for ar1[], ar2[] and
	// ar3[]
	int i = 0, j = 0, k = 0;

	// Iterate through three arrays while all arrays have
	// elements
	while (i < n1 && j < n2 && k < n3) {
		// If x = y and y = z, print any of them and move
		// ahead in all arrays
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
			cout << ar1[i] << " ";
			i++;
			j++;
			k++;
		}

		// x < y
		else if (ar1[i] < ar2[j])
			i++;

		// y < z
		else if (ar2[j] < ar3[k])
			j++;

		// We reach here when x > y and z < y, i.e., z is
		// smallest
		else
			k++;
	}
}

// Driver code
int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int ar2[] = { 6, 7, 20, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}

Method 2:

The approach used above works well if the arrays does not contain duplicate values however it can fail in cases where the array elements are repeated. This can lead to a single common element to get printed multiple times.

These duplicate entries can be handled without using any additional data structure by keeping the track of the previous element. Since the elements inside the array are arranged in sorted manner there is no possibility for the repeated elements to occur at random positions. 

Let’s consider the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z and let the variables prev1, prev2, prev3 for keeping the track of last encountered element in each array and initialize them with INT_MIN. Hence for every element we visit across each array, we check for the following.

If x = prev1, move ahead in ar1[] and repeat the procedure until x != prev1. Similarly, apply the same for the ar2[] and ar3[].
If x, y, and z are same, we can simply print any of them as common element, update prev1, prev2, and prev3 and move ahead in all three arrays.
Else If (x < y), we update prev1 and move ahead in ar1[] as x cannot be a common element.
Else If (y < z), we update prev2 and move ahead in ar2[] as y cannot be a common element.
Else If (x > z and y > z), we update prev3 and we move ahead in ar3[] as z cannot be a common element.

// C++ program to print common elements in three arrays
#include <bits/stdc++.h>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
	// Initialize starting indexes for ar1[], ar2[] and ar3[]
	int i = 0, j = 0, k = 0;

	// Declare three variables prev1, prev2, prev3 to track
	// previous element
	int prev1, prev2, prev3;

	// Initialize prev1, prev2, prev3 with INT_MIN
	prev1 = prev2 = prev3 = INT_MIN;

	// Iterate through three arrays while all arrays have
	// elements
	while (i < n1 && j < n2 && k < n3) {

		// If ar1[i] = prev1 and i < n1, keep incrementing i
		while (ar1[i] == prev1 && i < n1)
			i++;

		// If ar2[j] = prev2 and j < n2, keep incrementing j
		while (ar2[j] == prev2 && j < n2)
			j++;

		// If ar3[k] = prev3 and k < n3, keep incrementing k
		while (ar3[k] == prev3 && k < n3)
			k++;

		// If x = y and y = z, print any of them, update
		// prev1 prev2, prev3 and move ahead in each array
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
			cout << ar1[i] << " ";
			prev1 = ar1[i++];
			prev2 = ar2[j++];
			prev3 = ar3[k++];
		}

		// If x < y, update prev1 and increment i
		else if (ar1[i] < ar2[j])
			prev1 = ar1[i++];

		// If y < z, update prev2 and increment j
		else if (ar2[j] < ar3[k])
			prev2 = ar2[j++];

		// We reach here when x > y and z < y, i.e., z is
		// smallest update prev3 and increment k
		else
			prev3 = ar3[k++];
	}
}

// Driver code
int main()
{
	int ar1[] = { 1, 5, 10, 20, 40, 80, 80 };
	int ar2[] = { 6, 7, 20, 80, 80, 100 };
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 80, 120 };
	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);
	int n3 = sizeof(ar3) / sizeof(ar3[0]);

	cout << "Common Elements are ";
	findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}

Method 3: Using STL 

The idea is to use hash set. Here we use 2 of the sets to store elements of the 1st and 2nd arrays. The elements of the 3rd array are then checked if they are present in the first 2 sets. Then, we use a 3rd set to prevent any duplicates from getting added to the required array.

#include <bits/stdc++.h>
using namespace std;
 
void findCommon(int a[], int b[], int c[], int n1, int n2,
                int n3)
{
    // three sets to maintain frequency of elements
    unordered_set<int> uset, uset2, uset3;
    for (int i = 0; i < n1; i++) {
        uset.insert(a[i]);
    }
    for (int i = 0; i < n2; i++) {
        uset2.insert(b[i]);
    }
    // checking if elements of 3rd array are present in
    // first 2 sets
    for (int i = 0; i < n3; i++) {
        if (uset.find(c[i]) != uset.end()
            && uset2.find(c[i]) != uset.end()) {
            // using a 3rd set to prevent duplicates
            if (uset3.find(c[i]) == uset3.end())
                cout << c[i] << " ";
            uset3.insert(c[i]);
        }
    }
}
 
// Driver code
int main()
{
    int ar1[] = { 1, 5, 10, 20, 40, 80 };
    int ar2[] = { 6, 7, 20, 80, 100 };
    int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);
 
    cout << "Common Elements are " << endl;
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}

Rearrange the array in alternating positive and negative items with O(1) extra space	
----------------------------------------------------------------------------------------
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by a negative and vice-versa maintaining the order of appearance. The number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array.

Examples: 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

Naive Approach: 

The above problem can be easily solved if O(n) extra space is allowed.

We can store the positive values and negative values in two separate data structures.
We will start filling the original array with alternating negative and positive values in the same order 
in which it appears in the original array.
It becomes interesting due to the limitations that O(1) extra space and order of appearances. 

Optimal Approach:

The idea is to process the array from left to right. While processing, find the first out-of-place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index (0-based index), or if it is positive and at even index (0-based index). Once we find an out-of-place element, we find the first element after it with an opposite sign. We right rotate the subarray between these two elements (including these two).

Illustration:

Let the array be arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }

First iteration: 

{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } , -2 appears on odd index position and is out of place.
We will look for the first element that appears with an opposite sign
{ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 } => perform rotation of subarray between this two elements
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 }

Second iteration: 

{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } , 4 is out of place.
{ -5, 5, -2, 2, 4, 7, 1, 8, 0, -8 } =>-8 is of different sign 
{ -5, 5, -2, 2, -8, 4, 7, 1, 8, 0 } => after performing right rotation between 4 to -8

Algorithm:
We will maintain a variable to mark if the element is in its correct position or not. Let the variable be outofplace. Initially, it is -1.

We will iterate over the array
If outofplace is -1, we will check if the current index is out of place.
If the current index is out of place we will update the outofplace with the index value.
Else we will keep the value as it is.
If the outofplace is not -1, we will search for the next index which has a different sign than that of the value that is present in outofplace position.
Now we will pass this two positions to right rotate our array.
Update the value of outofplace by 2 unit.

/* C++ program to rearrange
positive and negative integers
in alternate fashion while keeping
the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
	char tmp = arr[cur];
	for (int i = cur; i > outofplace; i--)
		arr[i] = arr[i - 1];
	arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
	int outofplace = -1;

	for (int index = 0; index < n; index++) {
		if (outofplace >= 0) {
			// find the item which must be moved into the
			// out-of-place entry if out-of-place entry is
			// positive and current entry is negative OR if
			// out-of-place entry is negative and current
			// entry is negative then right rotate
			//
			// [...-3, -4, -5, 6...] --> [...6, -3, -4,-5...]
			//	 ^						 ^
			//	 |						 |
			//	 outofplace	 -->	 outofplace
			if (((arr[index] >= 0) && (arr[outofplace] < 0))
				|| ((arr[index] < 0)
					&& (arr[outofplace] >= 0))) {
				rightrotate(arr, n, outofplace, index);

				// the new out-of-place entry is now 2 steps
				// ahead
				if (index - outofplace >= 2)
					outofplace = outofplace + 2;
				else
					outofplace = -1;
			}
		}

		// if no entry has been flagged out-of-place
		if (outofplace == -1) {
			// check if current entry is out-of-place
			if (((arr[index] >= 0) && (!(index & 0x01)))
				|| ((arr[index] < 0) && (index & 0x01))) {
				outofplace = index;
			}
		}
	}
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{

	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}

Find if there is any subarray with sum equal to 0	
--------------------------------------------------------

Given an array of positive and negative numbers, find if there is a subarray (of size at least one) with 0 sum.

Examples: 

Input: {4, 2, -3, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: true
Explanation: The third element is zero. A single element is also a sub-array.

Naive approach:
consider all subarrays one by one and check the sum of every subarray. Run two loops: the outer loop picks a starting point i and the inner loop tries all subarrays starting from i.

Time Complexity: O(N2)
Auxiliary Space: O(1)

Using hashing: 
The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array. Hashing is used to store the sum values so that sum can be stored quickly and find out whether the current sum is seen before or not.

Follow the given steps to solve the problem:

Declare a variable sum, to store the sum of prefix elements
Traverse the array and at each index, add the element into the sum and check if this sum exists earlier. If the sum exists, then return true
Also, insert every prefix sum into a map, so that later on it can be found whether the current sum is seen before or not
At the end return false, as no such subarray is found

Illustration:

arr[] = {1, 4, -2, -2, 5, -4, 3}

Consider all prefix sums, one can notice that there is a subarray with 0 sum when :

Either a prefix sum repeats or
Or prefix sum becomes 0.
Prefix sums for above array are: 1, 5, 3, 1, 6, 2, 5
Since prefix sum 1 repeats, we have a subarray with 0 sum. 

// C++ program to find if
// there is a zero sum subarray
 
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver's code
int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
Output: No Such Sub Array Exists!
Time Complexity: O(N) under the assumption that a good hashing function is used, that allows insertion and retrieval operations in O(1) time. 
Auxiliary Space: O(N) Here extra space is required for hashing

Find factorial of a large number
------------------------------------------------------
Examples: 

Input: 100
Output: 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000


Input: 50
Output: 30414093201713378043612608166064768844377641568960512000000000000

We have discussed a simple program for factorial.

Why conventional way of computing factorial fails for large numbers?
A factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long int. 

Illustration:

Example to show working of multiply(res[], x)

A number 5189 is stored in res[] as following: res[] = {9, 8, 1, 5}
let x = 10
Initialize carry = 0

At i = 0, prod = res[0]*x + carry = 9*10 + 0 = 90.
res[0] = 0, carry = 9

At i = 1, prod = res[1]*x + carry = 8*10 + 9 = 89
res[1] = 9, carry = 8

At i = 2, prod = res[2]*x + carry = 1*10 + 8 = 18
res[2] = 8, carry = 1

At i = 3, prod = res[3]*x + carry = 5*10 + 1 = 51
res[3] = 1, carry = 5

res[4] = carry = 5
res[] = {0, 9, 8, 1, 5} 

Follow the steps below to solve the given problem:

Create an array res[] of MAX size where MAX is a number of maximum digits in output. 
Initialize value stored in res[] as 1 and initialize res_size (size of ‘res[]’) as 1. 
Multiply x with res[] and update res[] and res_size to store the multiplication result for all the numbers from x = 2 to n.
To multiply a number x with the number stored in res[], one by one multiply x with every digit of res[].
To implement multiply function perform the following steps:
Initialize carry as 0. 
Do following for i = 0 to res_size – 1 
Find value of res[i] * x + carry. Let this value be prod. 
Update res[i] by storing the last digit of prod in it. 
Update carry by storing the remaining digits in carry. 
Put all digits of carry in res[] and increase res_size by the number of digits in carry.
Below is the implementation of the above algorithm. 

NOTE: In the below implementation, the maximum digits in the output are assumed as 500. To find a factorial of a much larger number ( > 254), increase the size of an array or increase the value of MAX. This can also be solved using Linked List instead of using res[] array which will not waste extra space.


// C++ program to compute factorial of big numbers
#include <iostream>
using namespace std;
 
// Maximum number of digits in output
#define MAX 500
 
int multiply(int x, int res[], int res_size);
 
// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3
    // * 4...*n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);
 
    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}
 
// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;
 
        // Put rest in carry
        carry = prod / 10;
    }
 
    // Put carry in res and increase result size
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}
 
// Driver program
int main()
{
    factorial(100);
    return 0;
}

Using Basic BigInteger

This problem can be solved using the below idea:
-------> Big Integer can also be used to calculate the factorial of large numbers.

Illustration:

N = 5

ans = 1

At i = 2: ans = ans x i = 1 x 2 = 2
At i = 3: ans = ans x i = 2 x 3 = 6
At i = 4: ans = ans x i = 6 x 4 = 24
At i = 5: ans = ans x i = 24 x 5 = 120

Hence factorial of N is 120

Follow the steps below to solve the given problem: 

Declare a BigInteger f with 1 and perform the conventional way of calculating factorial
Traverse a loop from x = 2 to N and multiply x with f and store the resultant value in f

// C++ program to find large
// factorials using BigInteger
#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
 
// Returns Factorial of N
ull factorial(int N)
{
 
    // Initialize result
    ull f = 1; // Or BigInt 1
 
    // Multiply f with 2, 3, ...N
    for (ull i = 2; i <= N; i++)
        f *= i;
 
    return f;
}
 
// Driver method
int main()
{
    int N = 20;
    cout << factorial(N) << endl;
}
 
Output:2432902008176640000
Time Complexity: O(n)
Auxiliary Space: O(1)

Find maximum product subarray	
------------------------------------------------------------
Given an array A[] that contains both positive and negative integers, find the maximum product subarray.

Examples : 

Input: A[] = { 6, -3, -10, 0, 2 }
Output: 180  // The subarray is {6, -3, -10}

Input: A[] = {-1, -3, -10, 0, 60 }
Output: 60  // The subarray is {60}

Input: A[] = { -2, -3, 0, -2, -40 }
Output: 80  // The subarray is {-2, -40}

The idea is to traverse array from left to right keeping two variables minVal and maxVal which represents the minimum and maximum product value till the ith index of the array. Now, if the ith element of the array is negative that means now the values of minVal and maxVal will be swapped as value of maxVal will become minimum by multiplying it with a negative number. Now, compare the minVal and maxVal. 
The value of minVal and maxVal depends on the current index element or the product of the current index element and the previous minVal and maxVal respectively.

// C++ program to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
int maxProduct(int* arr, int n)
{
	// Variables to store maximum and minimum
	// product till ith index.
	int minVal = arr[0];
	int maxVal = arr[0];

	int maxProduct = arr[0];

	for (int i = 1; i < n; i++) {

		// When multiplied by -ve number,
		// maxVal becomes minVal
		// and minVal becomes maxVal.
		if (arr[i] < 0)
			swap(maxVal, minVal);

		// maxVal and minVal stores the
		// product of subarray ending at arr[i].
		maxVal = max(arr[i], maxVal * arr[i]);
		minVal = min(arr[i], minVal * arr[i]);

		// Max Product of array.
		maxProduct = max(maxProduct, maxVal);
	}

	// Return maximum product found in array.
	return maxProduct;
}

// Driver Code
int main()
{
	int arr[] = { -1, -3, -10, 0, 60 };

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum Subarray product is "
		<< maxProduct(arr, n) << endl;

	return 0;
}

Output: Maximum Subarray product is 60
Complexity Analysis: Time Complexity: O( n ) 
                     Auxiliary Space: O( 1 )

Find longest consecutive subsequence	
----------------------------------------------
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: The subsequence 36, 35, 33, 34, 32 is the longest subsequence of consecutive elements.

Naive Approach:
The idea is to first sort the array and find the longest subarray with consecutive elements. After sorting the array and removing the multiple occurrences of elements, run a loop and keep a count and max (both initially zero). Run a loop from start to end and if the current element is not equal to the previous (element+1) then set the count to 1 else increase the count. Update max with a maximum of count and max. 

 
 Illustration:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}

First sort the array to arrange them in consecutive fashion.
arr[] = {1, 2, 3, 4, 9, 10, 20}

Now, store the distinct elements from the sorted array.
dist[] = {1, 2, 3, 4, 9, 10, 20}

Initialise countConsecutive with 0 which will increment when arr[i] == arr[i – 1] + 1 is true otherwise countConsecutive will re-initialise by 1.

Maintain a variable ans to store maximum count of consecutive elements so far.

At i = 0:

as i is 0 then re-initialise countConsecutive by 1.
ans = max(ans, countConsecutive) = max(0, 1) = 1

At i = 1:
check if (dist[1] == dist[0] + 1) = (2 == 1 + 1) = true
as the above condition is true, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 1 + 1 = 2
ans = max(ans, countConsecutive) = max(1, 2) = 1

At i = 2:
check if (dist[2] == dist[1] + 1) = (3 == 2 + 1) = true
as the above condition is true, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 2 + 1 = 3
ans = max(ans, countConsecutive) = max(2, 3) = 3

At i = 3:
check if (dist[3] == dist[2] + 1) = (4 == 3 + 1) = true
as the above condition is true, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 3 + 1 = 4
ans = max(ans, countConsecutive) = max(3, 4) = 4

At i = 4:
check if (dist[4] == dist[3] + 1) = (9 != 4 + 1) = false
as the above condition is false, therefore re-initialise countConsecutive by 1
countConsecutive = 1
ans = max(ans, countConsecutive) = max(4, 1) = 4

At i = 5:
check if (dist[5] == dist[4] + 1) = (10 == 9 + 1) = true
as the above condition is true, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 1 + 1 = 2
ans = max(ans, countConsecutive) = max(4, 2) = 4

At i = 6:
check if (dist[6] == dist[5] + 1) = (20 != 10 + 1) = false
as the above condition is false, therefore re-initialise countConsecutive by 1
countConsecutive = 1
ans = max(ans, countConsecutive) = max(4, 1) = 4
Therefore the longest consecutive subsequence is {1, 2, 3, 4}
Hence, ans is 4.

Follow the steps below to solve the problem:

Initialise ans and countConsecutive with 0.
Sort the arr[].
Store the distinct elements in dist[] array by traversing over the arr[].
Now, traverse on the dist[] array to find the count of consecutive elements.
Simultaneously maintain the answer variable.

// C++ program to find longest
// contiguous subsequence
#include <bits/stdc++.h>
using namespace std;

// Returns length of the longest
// contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
	int ans = 0, count = 0;

	// sort the array
	sort(arr, arr + n);

	vector<int> v;
	v.push_back(arr[0]);

	// insert repeated elements only once in the vector
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1])
			v.push_back(arr[i]);
	}
	// find the maximum length
	// by traversing the array
	for (int i = 0; i < v.size(); i++) {

		// Check if the current element is equal
		// to previous element +1
		if (i > 0 && v[i] == v[i - 1] + 1)
			count++;
		// reset the count
		else
			count = 1;

		// update the maximum
		ans = max(ans, count);
	}
	return ans;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 3 };
	int n = sizeof arr / sizeof arr[0];
	cout << "Length of the Longest contiguous subsequence "
			"is "
		<< findLongestConseqSubseq(arr, n);
	return 0;
}

Time complexity: O(Nlog(N)), Time to sort the array is O(Nlog(N)).
Auxiliary space: O(N). Extra space is needed for storing distinct elements.

Using Hashing:

The idea is to use Hashing. We first insert all elements in a Set. Then check all the possible starts of consecutive subsequences.

Illustration:

Below image is the dry run for example arr[] = {1, 9, 3, 10, 4, 20, 2}:

Follow the steps below to solve the problem:

Create an empty hash.
Insert all array elements to hash.
Do the following for every element arr[i]
Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element of a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.

// C++ program to find longest
// contiguous subsequence
#include <bits/stdc++.h>
using namespace std;
 
// Returns length of the longest
// contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++) {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end()) {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}
Output : Length of the Longest contiguous subsequence is 4
Time complexity: O(N), Only one traversal is needed and the time complexity is O(n) under the assumption that hash insert and search takes O(1) 
Auxiliary space: O(N), To store every element in the hashmap O(n) space is needed

Using Priority Queue:

The Idea is to use Priority Queue. Using priority queue it will sort the elements and eventually it will help to find consecutive elements.

Illustration:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}

Insert all the elements in the Priority Queue:

1	2	3	4	9	10	20
Initialise variable prev with first element of priority queue, prev will contain last element has been picked and it will help to check whether the current element is contributing for consecutive sequence or not.

prev = 1, countConsecutive = 1, ans = 1

Run the algorithm till the priority queue becomes empty.

2	3	4	9	10	20

current element is 2
prev + 1 == 2, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 1 + 1 = 2
update prev with current element, prev = 2
pop the current element
ans = max(ans, countConsecutive) = (1, 2) = 2

3	4	9	10	20

current element is 3
prev + 1 == 3, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 2 + 1 = 3
update prev with current element, prev = 3
pop the current element
ans = max(ans, countConsecutive) = (2, 3) = 3

4	9	10	20

current element is 4
prev + 1 == 4, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 3 + 1 = 4
update prev with current element, prev = 4
pop the current element
ans = max(ans, countConsecutive) = (3, 4) = 4

9	10	20

current element is 9
prev + 1 != 9, therefore re-initialise countConsecutive by 1
countConsecutive = 1
update prev with current element, prev = 9
pop the current element
ans = max(ans, countConsecutive) = (4, 1) = 4

10	20

current element is 10
prev + 1 == 10, therefore increment countConsecutive by 1
countConsecutive = countConsecutive + 1 = 1 + 1 = 2
update prev with current element, prev = 10
pop the current element
ans = max(ans, countConsecutive) = (4, 2) =4

20

current element is 20
prev + 1 != 20, therefore re-initialise countConsecutive by 1
countConsecutive = 1
update prev with current element, prev = 20
pop the current element
ans = max(ans, countConsecutive) = (4, 1) = 4
Hence, the longest consecutive subsequence is 4.

Follow the steps below to solve the problem:

Create a Priority Queue to store the element
Store the first element in a variable
Remove it from the Priority Queue
Check the difference between this removed first element and the new peek element
If the difference is equal to 1 increase the count by 1 and repeats step 2 and step 3
If the difference is greater than 1 set counter to 1 and repeat step 2 and step 3
if the difference is equal to 0 repeat step 2 and 3
if counter greater than the previous maximum then store counter to maximum
Continue step 4 to 7 until we reach the end of the Priority Queue
Return the maximum value

// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
int findLongestConseqSubseq(int arr[], int N)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
 
        // adding element from
        // array to PriorityQueue
        pq.push(arr[i]);
    }
 
    // Storing the first element
    // of the Priority Queue
    // This first element is also
    // the smallest element
    int prev = pq.top();
    pq.pop();
 
    // Taking a counter variable with value 1
    int c = 1;
 
    // Storing value of max as 1
    // as there will always be
    // one element
    int max = 1;
    while (!pq.empty()) {
 
        // check if current peek
        // element minus previous
        // element is greater than
        // 1 This is done because
        // if it's greater than 1
        // then the sequence
        // doesn't start or is broken here
        if (pq.top() - prev > 1) {
 
            // Store the value of counter to 1
            // As new sequence may begin
            c = 1;
 
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
 
        // Check if the previous
        //  element and peek are same
        else if (pq.top() - prev == 0) {
 
            // Update the previous position with the
            // current peek And remove it
            prev = pq.top();
            pq.pop();
        }
 
        // If the difference
        // between previous element and peek is 1
        else {
 
            // Update the counter
            // These are consecutive elements
            c++;
 
            // Update the previous position
            //  with the current peek And remove it
            prev = pq.top();
            pq.pop();
        }
 
        // Check if current longest
        // subsequence is the greatest
        if (max < c) {
 
            // Store the current subsequence count as
            // max
            max = c;
        }
    }
    return max;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = 7;
 
    cout << "Length of the Longest consecutive subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}

Output:
Length of the Longest consecutive subsequence is 4
Time Complexity: O(N*log(N)), Time required to push and pop N elements is logN for each element.
Auxiliary Space: O(N), Space required by priority queue to store N elements.

Given an array of size n and a number k, fin all elements that appear more than ” n/k ” times.	
--------------------------------------------------------------------------------
Given an array of size n and an integer k, find all elements in the array that appear more than n/k times. 

Examples:

Input: arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4
Output: {2, 3}
Explanation: Here n/k is 8/4 = 2, therefore 2 appears 3 times in the array that is greater than 2 and 3 appears 3 times in the array that is greater than 2

Input: arr[] = {9, 8, 7, 9, 2, 9, 7}, k = 3
Output: {9}
Explanation: Here n/k is 7/3 = 2, therefore 9 appears 3 times in the array that is greater than 2.

Using Hashing:
The idea is to pick all elements one by one. For every picked element, count its occurrences by traversing the array, if count becomes more than n/k, then print the element.

Follow the steps below to solve the problem:

First, make a frequency map of all the elements in the array
Then traverse the map and check the frequency of every element
If the frequency is greater than n/k then print the element.

// C++ code to find elements whose
// frequency yis more than n/k
#include <bits/stdc++.h>
using namespace std;
 
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;
 
    // unordered_map initialization
    unordered_map<int, int> freq;
 
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    // Traversing the map
    for (auto i : freq) {
 
        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x) {
 
            // Print the key of whose value
            // is greater than x
            cout << i.first << endl;
        }
    }
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    morethanNbyK(arr, n, k);
 
    return 0;
}

Output
2
1
 
Time Complexity: O(N), Traversing the array of size N.
Auxiliary Space: O(N), Space occupied by the hashmap

Using Moore’s Voting Algorithm:

The idea is to apply Moore’s Voting algorithm, as there can be at max k – 1 elements present in the array which appears more than n/k times so their will be k – 1 candidates. When we encounter an element which is one of our candidates then increment the count else decrement the count.

Illustration:

Consider k = 4, n = 9 
Given array: 3 1 2 2 2 1 4 3 3 

i = 0
temp[] has one element {3} with count 1

i = 1
temp[] has two elements {3, 1} with counts 1 and 1 respectively

i = 2
temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 1 respectively.

i = 3
temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 2 respectively.

i = 4
temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 3 respectively.

i = 5
temp[] has three elements, {3, 1, 2 with counts as 1, 2 and 3 respectively.

i = 6
temp[] has two elements, {1, 2} with counts as 1 and 2 respectively.

i = 7
temp[] has three elements, {3, 1, 2} with counts as 1, 1 and 2 respectively.

i = 8 
temp[] has three elements, {3, 1, 2} with counts as 2, 1 and 2 respectively.

Follow the steps below to solve the problem:

Create a temporary array of size (k – 1) to store elements and their counts (The output elements are going to be among these k-1 elements).
Traverse through the input array and update temp[] (add/remove an element or increase/decrease count) for every traversed element. The array temp[] stores potential (k-1) candidates at every step.
Iterate through final (k-1) potential candidates (stored in temp[]). or every element, check if it actually has counted of more than n/k.

// A C++ program to print elements with count more than n/k
#include <iostream>
using namespace std;
 
// A structure to store an element and its current count
struct eleCount {
    int e; // Element
    int c; // Count
};
 
// Prints elements with more
// than n/k occurrences in arr[]
// of size n. If there are no
// such elements, then it prints
// nothing.
void moreThanNdK(int arr[], int n, int k)
{
    // k must be greater than
    // 1 to get some output
    if (k < 2)
        return;
 
    /* Step 1: Create a temporary
       array (contains element
       and count) of size k-1.
       Initialize count of all
       elements as 0 */
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;
 
    /* Step 2: Process all
      elements of input array */
    for (int i = 0; i < n; i++) {
        int j;
 
        /* If arr[i] is already present in
           the element count array,
           then increment its count
         */
        for (j = 0; j < k - 1; j++) {
            if (temp[j].e == arr[i]) {
                temp[j].c += 1;
                break;
            }
        }
 
        /* If arr[i] is not present in temp[] */
        if (j == k - 1) {
            int l;
 
            /* If there is position available
              in temp[], then place arr[i] in
              the first available position and
              set count as 1*/
            for (l = 0; l < k - 1; l++) {
                if (temp[l].c == 0) {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }
 
            /* If all the position in the
               temp[] are filled, then decrease
               count of every element by 1 */
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].c -= 1;
        }
    }
 
    /*Step 3: Check actual counts of
     * potential candidates in temp[]*/
    for (int i = 0; i < k - 1; i++) {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;
 
        // If actual count is more than n/k,
        // then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}
 
/* Driver code */
int main()
{
 
    int arr1[] = { 4, 5, 6, 7, 8, 4, 4 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);
 
    return 0;
}
Output
Number:4 Count:3
Time Complexity: O(N * K), Checking for each element of the array(size N) in the candidate array of size K
Auxiliary Space: O(K), Space required to store the candidates.

Maximum profit by buying and selling a share at most twice
------------------------------------------------------------------------
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80

Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80


Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.

Input:   price[] = {90, 80, 70, 60, 50}\
Output:  0
Not possible to earn.

A Simple Solution is to consider every index ‘i’ and do the following 

Max profit with at most two transactions = 
MAX {max profit with one transaction and subarray price[0..i] + 
max profit with one transaction and subarray price[i+1..n-1] } 
i varies from 0 to n-1.

Maximum possible using one transaction can be calculated using the following O(n) algorithm 
The maximum difference between two elements such that the larger element appears after the smaller number
The time complexity of the above simple solution is O(n2).

We can do this O(n) using the following Efficient Solution. The idea is to store the maximum possible profit of every subarray and solve the problem in the following two phases.

1) Create a table profit[0..n-1] and initialize all values in it 0.
2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
4) Return profit[n-1]

To do step 2, we need to keep track of the maximum price from right to left side, and to do step 3, we need to keep track of the minimum price from left to right. Why we traverse in reverse directions? The idea is to save space, in the third step, we use the same array for both purposes, maximum with 1 transaction and maximum with 2 transactions. After iteration i, the array profit[0..i] contains the maximum profit with 2 transactions, and profit[i+1..n-1] contains profit with two transactions.

// C++ program to find maximum
// possible profit with at most
// two transactions
#include <bits/stdc++.h>
using namespace std;
 
// Returns maximum profit with
// two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(int price[], int n)
{
    // Create profit array and
    // initialize it as 0
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
 
    /* Get the maximum profit with
       only one transaction
       allowed. After this loop,
       profit[i] contains maximum
       profit from price[i..n-1]
       using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        // max_price has maximum
        // of price[i..n-1]
        if (price[i] > max_price)
            max_price = price[i];
 
        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at
        //    max_price
        profit[i]
            = max(profit[i + 1], max_price - price[i]);
    }
 
    /* Get the maximum profit with two transactions allowed
       After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];
 
        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        //    profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
 
    delete[] profit; // To avoid memory leak
 
    return result;
}
 
// Driver code
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}
 
 

Output
Maximum Profit = 100
Time complexity: O(n)
Auxiliary space: O(n) 

Algorithmic Paradigm: Dynamic Programming 

Another approach:

Initialize four variables for taking care of the first buy, first sell, second buy, second sell. Set first buy and second buy as INT_MIN and first and second sell as 0. This is to ensure to get profit from transactions. Iterate through the array and return the second sell as it will store maximum profit.


#include <iostream>
#include<climits>
using namespace std;
 
int maxtwobuysell(int arr[],int size) {
    int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
       
      for(int i=0;i<size;i++) {
         
          first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
          first_sell = max(first_sell,first_buy+arr[i]);
          second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
          second_sell = max(second_sell,second_buy+arr[i]);
       
    }
     return second_sell;
}
 
int main() {
 
    int arr[] = {2, 30, 15, 10, 8, 25, 80};
      int size = sizeof(arr)/sizeof(arr[0]);
      cout<<maxtwobuysell(arr,size);
    return 0;
}
Output:100
Time Complexity: O(N)
Auxiliary Space: O(1)

Find whether an array is a subset of another array	
----------------------------------------------------------
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both arrays are distinct.

Examples: 

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1} 
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4} 
Output: arr2[] is a subset of arr1[]


Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3} 
Output: arr2[] is not a subset of arr1[] 


Naive Approach:
Use two loops: The outer loop picks all the elements of arr2[] one by one. The inner loop linearly searches for the element picked by the outer loop. If all elements are found then return 1, else return 0.

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
 
/* Return 1 if arr2[] is a subset of
arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
 
        /* If the above inner loop was
        not broken at all then arr2[i]
        is not present in arr1[] */
        if (j == m)
            return 0;
    }
 
    /* If we reach here then all
    elements of arr2[] are present
    in arr1[] */
    return 1;
}
 
// Driver code
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");
 
    getchar();
    return 0;
}
Output
arr2[] is subset of arr1[] 
Time Complexity: O(m*n)
Auxiliary Space: O(1)

Using Sorting and Binary Search:
The idea is to sort the given array arr1[], and then for each element in arr2[] do a binary search for it in sorted arr1[]. If the element is not found then return 0. If all elements are present then return 1.

Illustration:

Given array arr1[] = { 11, 1, 13, 21, 3, 7 } and arr2[] = { 11, 3, 7, 1 }.

Step 1: We will sort the array arr1[], and have arr1[] = { 1, 3, 7, 11, 13, 21}.

Step 2: We will look for each element in arr2[] in arr1[] using binary search.

arr2[] = { 11, 3, 7, 1 }, 11 is present in arr1[] = { 1, 3, 7, 11, 13, 21}
arr2[] = { 11, 3, 7, 1 }, 3 is present in arr1[] = { 1, 3, 7, 11, 13, 21}
arr2[] = { 11, 3, 7, 1 }, 7 is present in arr1[] = { 1, 3, 7, 11, 13, 21}
arr2[] = { 11, 3, 7, 1 }, 1 is present in arr1[] = { 1, 3, 7, 11, 13, 21}
As all the elements are found we can conclude arr2[] is the subset of arr1[].

Algorithm:

The algorithm is pretty straightforward. 

Sort the first array arr1[].
Look for the elements of arr2[] in sorted arr1[].
If we encounter a particular value that is present in arr2[] but not in arr1[], the code will terminate, arr2[] can never be the subset of arr1[].
Else arr2[] is the subset of arr1[].
Below is the code implementation of the above approach :


// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;
 
/* Function prototypes */
void quickSort(int* arr, int si, int ei);
int binarySearch(int arr[], int low, int high, int x);
 
/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
 
    quickSort(arr1, 0, m - 1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
            return 0;
    }
 
    /* If we reach here then all elements
     of arr2[] are present in arr1[] */
    return 1;
}
 
/* FOLLOWING FUNCTIONS ARE ONLY FOR
    SEARCHING AND SORTING PURPOSE */
/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        /*low + (high - low)/2;*/
        int mid = (low + high) / 2;
 
        /* Check if arr[mid] is the first
        occurrence of x. arr[mid] is first
        occurrence if x is one of the following
        is true:
        (i) mid == 0 and arr[mid] == x
        (ii) arr[mid-1] < x and arr[mid] == x    */
        if ((mid == 0 || x > arr[mid - 1])
            && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}
 
void exchange(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
 
    for (j = si; j <= ei - 1; j++) {
        if (A[j] <= x) {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange(&A[i + 1], &A[ei]);
    return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si --> Starting index
ei --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi; /* Partitioning index */
    if (si < ei) {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
 
/*Driver code */
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, arr2, m, n))
        cout << "arr2[] is subset of arr1[] ";
    else
        cout << "arr2[] is not a subset of arr1[] ";
 
    return 0;
}
 
Output
arr2[] is subset of arr1[] 
Time Complexity: O(mLog(m) + nlog(m)). O(mLog(m)) for sorting and O(nlog(m)) for binary searching each element of one array in another. In the above code, Quick Sort is used and the worst-case time complexity of Quick Sort is O(m2).
Auxiliary Space: O(n)

Find whether an array is subset of another array using Sorting and Merging
The idea is to sort the two arrays and then iterate on the second array looking for the same values on the first array using two pointers. Whenever we encounter the same values we will increment both the pointer and if we encounter any values less than that of the second array, we will increment the value of the pointer pointing to the first array. If the value is greater than that of the second array, we know the second array is not the subset of the first array.

Illustration:

Find whether an array is subset of another array using sorting and merging

Algorithm:

The initial step will be to sort the two arrays.

Set two pointers j and i or arr1[] and arr2[] respectively.
If arr1[j] < arr2[i], we will increase j by 1.
If arr1[j] = arr2[i], we will increase j and i by 1.
If arr1[j] > arr2[i], we will terminate as arr2[] is not the subset of arr1[].

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;
 
/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
 
    if (m < n)
        return 0;
 
    // Sort both the arrays
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
 
    // Iterate till they do not exceed their sizes
    while (i < n && j < m) {
        // If the element is smaller then
        // Move ahead in the first array
        if (arr1[j] < arr2[i])
            j++;
        // If both are equal, then move
        // both of them forward
        else if (arr1[j] == arr2[i]) {
            j++;
            i++;
        }
 
        // If we do not have an element smaller
        // or equal to the second array then break
        else if (arr1[j] > arr2[i])
            return 0;
    }
 
    return (i < n) ? false : true;
}
 
// Driver Code
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[] ");
 
    return 0;
}
Output
arr2[] is subset of arr1[] 
Time Complexity: O(mLog(m) + nLog(n)) which is better than approach 2.
Auxiliary Space: O(1)

Find the triplet that sum to a given value	
-------------------------------------------------------
Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false.

Examples: 
 

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24; 
Output: 12, 3, 9 
Explanation: There is a triplet (12, 3 and 9) present 
in the array whose sum is 24. 
Input: array = {1, 2, 3, 4, 5}, sum = 9 
Output: 5, 3, 1 
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9.

Method 1: This is the naive approach towards solving the above problem.  

Approach: A simple method is to generate all possible triplets and compare the sum of every triplet with the given value. The following code implements this simple method using three nested loops.
Algorithm: 
Given an array of length n and a sum s
Create three nested loop first loop runs from start to end (loop counter i), second loop runs from i+1 to end (loop counter j) and third loop runs from j+1 to end (loop counter k)
The counter of these loops represents the index of 3 elements of the triplets.
Find the sum of ith, jth and kth element. If the sum is equal to given sum. Print the triplet and break.
If there is no triplet, then print that no triplet exist.
Implementation:
 
#include <bits/stdc++.h>
using namespace std;
 
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Fix the second element as A[j]
        for (int j = i + 1; j < arr_size - 1; j++)
        {
 
            // Now look for the third number
            for (int k = j + 1; k < arr_size; k++)
            {
                if (A[i] + A[j] + A[k] == sum)
                {
                    cout << "Triplet is " << A[i] <<
                        ", " << A[j] << ", " << A[k];
                    return true;
                }
            }
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}
 
/* Driver code */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A, arr_size, sum);
    return 0;
}

Output
Triplet is 4, 10, 8
 

Complexity Analysis: 
Time Complexity: O(n3). 
There are three nested loops traversing the array, so the time complexity is O(n^3)
Space Complexity: O(1). 
As no extra space is required.

Method 2: This method uses sorting to increase the efficiency of the code. 

Approach: By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take linear time so it is better than a nested loop.
Algorithm : 
Sort the given array.
Loop over the array and fix the first element of the possible triplet, arr[i].
Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
If the sum is smaller than the required sum, increment the first pointer.
Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.
Implementation:

// C++ program to find a triplet
#include <bits/stdc++.h>
using namespace std;
 
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
    /* Sort the elements */
    sort(A, A + arr_size);
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) {
 
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i + 1; // index of the first element in the
        // remaining elements
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i], A[l],A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}
 
/* Driver program to test above function */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    find3Numbers(A, arr_size, sum);
    return 0;
}

Output:
Triplet is 4, 8, 10
Complexity Analysis: 
Time complexity: O(N^2). 
There are only two nested loops traversing the array, so time complexity is O(n^2). Two pointers algorithm takes O(n) time and the first element can be fixed using another nested traversal.
Space Complexity: O(1). 
As no extra space is required.

Method 3: This is a Hashing-based solution. 

Approach: This approach uses extra space but is simpler than the two-pointers approach. Run two loops outer loop from start to end and inner loop from i+1 to end. Create a hashmap or set to store the elements in between i+1 to j-1. So if the given sum is x, check if there is a number in the set which is equal to x – arr[i] – arr[j]. If yes print the triplet. 
 
Algorithm: 
Traverse the array from start to end. (loop counter i)
Create a HashMap or set to store unique pairs.
Run another loop from i+1 to end of the array. (loop counter j)
If there is an element in the set which is equal to x- arr[i] – arr[j], then print the triplet (arr[i], arr[j], x-arr[i]-arr[j]) and break
Insert the jth element in the set.

Implementation:

// C++ program to find a triplet using Hashing
#include <bits/stdc++.h>
using namespace std;
 
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}
 
/* Driver program to test above function */
int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    find3Numbers(A, arr_size, sum);
 
    return 0;
}
Output:
Triplet is 4, 8, 10
Time complexity: O(N^2) 
Auxiliary Space: O(N), since n extra space has been taken.

Trapping Rain water problem	
-------------------------------------------------------
Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:  

Input: arr[] = {2, 0, 2}
Output: 2
Explanation: The structure is like below.
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
Explanation: Structure is like below.
We can trap “3 units” of water between 3 and 2,
“1 unit” on top of bar 2 and “3 units” between 2 and 4.

Input: arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
Output: 6
Explanation: The structure is like below.
Trap “1 unit” between first 1 and 2, “4 units” between
first 2 and 3 and “1 unit” between second last 1 and last 2

Intuition: The basic intuition of the problem is as follows:

An element of the array can store water if there are higher bars on the left and the right. 
The amount of water to be stored in every position can be found by finding the heights of bars on the left and right sides. 
The total amount of water stored is the summation of the water stored in each index.
For example – Consider the array arr[] = {3, 0, 2, 0, 4}. 
Three units of water can be stored in two indexes 1 and 3, and one unit of water at index 2.
Water stored in each index = 0 + 3 + 1 + 3 + 0 = 7  



Approach 1 (Brute Approach): This approach is the brute approach. The idea is to:

Traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. The difference between the smaller height and the height of the current element is the amount of water that can be stored in this array element.

Follow the steps mentioned below to implement the idea:

Traverse the array from start to end:
For every element: 
Traverse the array from start to that index and find the maximum height (a) and 
Traverse the array from the current index to the end, and find the maximum height (b).
The amount of water that will be stored in this column is min(a,b) – array[i], add this value to the total amount of water stored
Print the total amount of water stored.

// C++ implementation of the approach
  
#include <bits/stdc++.h>
using namespace std;
  
// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
    // To store the maximum water
    // that can be stored
    int res = 0;
  
    // For every element of the array
    for (int i = 1; i < n - 1; i++) {
  
        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);
  
        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);
  
        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }
  
    return res;
}
  
// Driver code
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << maxWater(arr, n);
  
    return 0;
}
Output
6
Complexity Analysis: 
Time Complexity: O(N2). There are two nested loops traversing the array.
Space Complexity: O(1). No extra space is required.

Approach 2 (Precalculation): This is an efficient solution based on the precalculation concept:

In previous approach, for every element we needed to calculate the highest element on the left and on the right. 

So, to reduce the time complexity: 

For every element we can precalculate and store the highest bar on the left and on the right (say stored in arrays left[] and right[]). 
Then iterate the array and use the precalculated values to find the amount of water stored in this index, 
which is the same as ( min(left[i], right[i]) – arr[i] )
Follow the below illustration for a better understanding:

Illustration:

Consider arr[] = {3, 0, 2, 0, 4}

Therefore, left[] = {3, 3, 3, 3, 4} and right[] = {4, 4, 4, 4, 4}
Now consider iterating using i from 0 to end

For i = 0:
        => left[0] = 3, right[0] = 4 and arr[0] = 3
        => Water stored = min(left[0], right[0]) – arr[0] = min(3, 4) – 3 = 3 – 3 = 0
        => Total = 0 + 0 = 0

For i = 1:
        => left[1] = 3, right[1] = 4 and arr[1] = 0
        => Water stored = min(left[1], right[1]) – arr[1] = min(3, 4) – 0 = 3 – 0 = 3
        => Total = 0 + 3 = 3

For i = 2:
        => left[2] = 3, right[2] = 4 and arr[2] = 2
        => Water stored = min(left[2], right[2]) – arr[2] = min(3, 4) – 2 = 3 – 2 = 1
        => Total = 3 + 1 = 4

For i = 3:
        => left[3] = 3, right[3] = 4 and arr[3] = 0
        => Water stored = min(left[3], right[3]) – arr[3] = min(3, 4) – 0 = 3 – 0 = 3
        => Total = 4 + 3 = 7

For i = 4:
        => left[4] = 4, right[4] = 4 and arr[4] = 4
        => Water stored = min(left[4], right[4]) – arr[4] = min(4, 4) – 4 = 4 – 4 = 0
        => Total = 7 + 0 = 7

So total rain water trapped = 7

Follow the steps mentioned below to implement the approach:

Create two arrays left[] and right[] of size N. Create a variable (say max) to store the maximum found till a certain index during traversal.
Run one loop from start to end: 
In each iteration update max and also assign left[i] = max.
Run another loop from end to start: 
In each iteration update max found till now and also assign right[i] = max.
Traverse the array from start to end.
The amount of water that will be stored in this column is min(left[i], right[i]) – array[i]
Add this value to the total amount of water stored
Print the total amount of water stored.

// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;
  
int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
  
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
  
    // Initialize result
    int water = 0;
  
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
  
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
  
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
    // .
    for (int i = 1; i < n - 1; i++) {
        int var = min(left[i - 1], right[i + 1]);
        if (var > arr[i]) {
            water += var - arr[i];
        }
    }
  
    return water;
}
  
// Driver program
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findWater(arr, n);
    return 0;
}
Output
6
Complexity Analysis:

Time Complexity: O(N). Only one traversal of the array is needed, So time Complexity is O(N).
Space Complexity: O(N). Two extra arrays are needed, each of size N.
Approach 3 (Using Stack): The idea to solve the problem using stack is as follows:

We can use a stack to track the bars that are bounded by the higher left and right bars. This can be done using only one iteration.

For this we will keep pushing elements in stack, until an element with higher value than the stack top is found. This denotes that there is a chance of storing position on the left side of the current element with the current bar being an end.
So remove the smaller element on left and find the left bar (which is the current top of stack) and the amount of water stored by the left end bar and the current bar being the right end. Continue this till the stack is not empty or a higher value element is found.
Follow the below illustration for a better understanding.

Illustration:

Consider the array arr[] = {3, 0, 2, 0, 4} and an empty stack st.

For i = 0:
        => The stack is empty. So no elements with higher value on left.
        => Push the index into the stack. st = {0} [to keep track of the distance in between]

For i = 1:
        => arr[1] is less than arr[stack top]. So arr[1] has a higher left bound.
        => Push the index into stack. st = {0, 1}

For i = 2:
        => arr[2] is greater than arr[stack top]. So arr[2] is the higher right bound of current stack top.
        => Calculate the water stored in between the left and right bound of the stack top. 
        => The stack top is the base height in between the left and right bound.
        => Pop the stack top. So st = {0}.
        => Water stored in between when arr[0] and arr[2] are the bound= {min(arr[0], arr[2]) – arr[1]} * (2 – 0 – 1) = 2.
        => arr[0] is greater than arr[2] Push the index into stack. st = {0, 2}.
        => Total water stored = 0 + 2 = 2.

For i = 3:
        => arr[3] is less than arr[2]. So arr[3] has a higher left bound.
        => Push the index into the stack. st = {0, 2, 3}.

For i = 4:
        => arr[4] is greater than arr[stack top]. So arr[4] is the higher right bound of current stack top.
        => Calculate the water stored in same way as for i = 2. The base height is arr[3].
        => Pop the stack top. So st = {0, 2}.
        => Water stored in between when arr[4] and arr[2] are the bound= {min(arr[4], arr[2]) – arr[3]} * (4 – 2 – 1) = 2.
        => arr[4] is greater than arr[2].
        => Pop the stack. st = {0}.
        => Water stored in between arr[0] and arr[4] when arr[2] is the base height = {min(3, 4) – 2} * (4 – 0 – 1) = 3
        => arr[0] less than arr[4]. So pop stack. st = {}.
        => As no element left in the stack push the index. st = {4}.
        => Total water stored = 2 + 2 + 3 = 7.

So the total amount of water stored  = 7.

Follow the steps mentioned below to implement the idea:

Loop through the indices of the bar array.
For each bar, do the following:
Loop while the Stack is not empty and the current bar has a height greater than the top bar of the stack,
Store the index of the top bar in pop_height and pop it from the Stack.
Find the distance between the left bar(current top) of the popped bar and the current bar.
Find the minimum height between the top bar and the current bar.
The maximum water that can be trapped is distance * min_height.
The water trapped, including the popped bar, is (distance * min_height) – height[pop_height].
Add that to the answer.
Return the amount received as the total amount of water

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
  
// Function to return the maximum
// water that can be stored
int maxWater(int height[], int n)
{
  
    // Stores the indices of the bars
    stack<int> st;
  
    // Stores the final result
    int ans = 0;
  
    // Loop through the each bar
    for (int i = 0; i < n; i++) {
  
        // Remove bars from the stack
        // until the condition holds
        while ((!st.empty())
               && (height[st.top()] < height[i])) {
  
            // Store the height of the top
            // and pop it.
            int pop_height = height[st.top()];
            st.pop();
  
            // If the stack does not have any
            // bars or the popped bar
            // has no left boundary
            if (st.empty())
                break;
  
            // Get the distance between the
            // left and right boundary of
            // popped bar
            int distance = i - st.top() - 1;
  
            // Calculate the min. height
            int min_height
                = min(height[st.top()], height[i])
                  - pop_height;
  
            ans += distance * min_height;
        }
  
        // If the stack is either empty or
        // height of the current bar is less than
        // or equal to the top bar of stack
        st.push(i);
    }
    return ans;
}
  
// Driver code
int main()
{
  
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    cout << maxWater(arr, n);
  
    return 0;
}

Output
6
Time Complexity: O(N)
Auxiliary Space: O(N)

Approach 4 (Horizontal scan method): The idea is as follows:

If max_height is the height of the tallest block, then it will be the maximum possible height for any trapped rainwater. 
And if for each unit of height we find the leftmost and the rightmost boundary for that height, we can consider all the blocks in between contain that amount of water. 
But this will consider the height of the bars also. So we have to subtract that from the total water trapped.
This can be justified as follows. Say the sections for a certain height is {i1, i2}, {i2, i3}, . . ., {ik-1, ik}
So the water stored in between for a single unit of height is the difference in between the indices
= (i2 – i1 – 1) + (i3 – i2 – 1) + . . . + (ik – ik-1 -1}) = ik – i1 – (k-1) where k is the number of bars in between.

But as we are considering all the blocks in between left and right boundary, it considers all the bars also.
So the trapped water for a single unit becomes (ik – i1 + 1)

Follow the below illustration for a better understanding.

Illustration:

Consider array arr[] = {3, 0, 2, 0, 4}.
max_height = 4 and sum of all blocks = 2 + 3 + 4 = 9.

For height = 1:
        => leftmost boundary = 0 and rightmost boundary = 4.
        => All blocks in between contain 1 height of water. 
        => So amount of water trapped = (4 – 0 + 1) = 5
        => Total trapped water = 0+5 = 5

 For height = 2:
        => leftmost boundary = 0 and rightmost boundary = 4.
        => All blocks in between contain 2 height of water.
        => Earlier we have considered water columns with height 1. So there is increase of 1 unit in height. 
        => So amount of water trapped = (4 – 0 + 1) = 5
        => Total trapped water = 5 + 5 = 10

For height = 3:
        => leftmost boundary = 0 and rightmost boundary = 4.
        => All blocks in between contain 3 height of water.
        => Earlier we have considered water columns with height 2. So there is increase of 1 unit in height. 
        => So amount of water trapped = (4 – 0 + 1) = 5
        => Total trapped water = 10 + 5 = 15

For height = 4:
        => leftmost boundary = 4 and rightmost boundary = 4.
        => All blocks in between contain 4 height of water. 
        => Earlier we have considered water columns with height 3. So there is increase of 1 unit in height. 
        => So amount of water trapped = (4 – 4 + 1) = 1
        => Total trapped water = 15 + 1 = 16

So total water trapped  = 16 – total space taken by bars = 16 – 9 = 7.

Follow the steps mentioned below to implement the idea:

Find the total number of blocks, i.e., the sum of the heights array, num_blocks
Find the maximum height, max_height
Store total water in a variable, total = 0
Keep two pointers, left = 0 and right = N -1, to store the leftmost and the rightmost boundaries for each unit of height
For each height, i from 1 to max_height, do the following
Find the leftmost and the rightmost boundary for the current height.
As mentioned earlier we can consider all the blocks in between these to have at least i unit of water.
Add this amount of water to the total trapped water.
After the iteration is over, subtract num_blocks from total as we have considered them as water height during calculation.

// C++ program to implement the approach
#include <bits/stdc++.h>
using namespace std;
  
int trappedWater(vector<int>& arr)
{
    int num_blocks = 0;
    int n = 0;
    int max_height = INT_MIN;
  
    // Find total blocks, max height and length of array
    for (auto height : arr) {
        num_blocks += height;
        n += 1;
        max_height = max(max_height, height);
    }
  
    // Total water, left pointer and right pointer
    // initialized to 0 and n - 1
    int total = 0;
    int left = 0;
    int right = n - 1;
  
    for (int i = 1; i <= max_height; i++) {
  
        // Find leftmost point greater than current row (i)
        while (arr[left] < i)
            left += 1;
  
        // Find rightmost point greater than current row (i)
        while (arr[right] < i)
            right -= 1;
  
        // water in this row = right - left  + 1
        total += (right - left + 1);
    }
  
    total -= num_blocks;
    return total;
}
  
// Driver code
int main()
{
    vector<int> arr
        = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  
    // Function call
    cout << trappedWater(arr) << endl;
    return 0;
}

Output
6
Time Complexity: O(max (max_height, N))
Space Complexity: O(1)

Chocolate Distribution problem	
-------------------------------------------------
Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
Output: Minimum Difference is 6 

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50} , m = 7 
Output: Minimum Difference is 10 

Naive Approach for Chocolate Distribution Problem
The idea is to generate all subsets of size m of arr[0..n-1]. For every subset, find the difference between the maximum and minimum elements in it. Finally, return the minimum difference.

Efficient Approach for Chocolate Distribution Problem
The idea is based on the observation that to minimize the difference, we must choose consecutive elements from a sorted packet. We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between the last and first elements.

Illustration:
Below is the illustration of example arr[] = [ 7,3,2,4,9,12,56 ] , m = 3






















Follow the steps mentioned below to implement the approach:

Initially sort the given array. And declare a variable to store the minimum difference, and initialize it to INT_MAX. Let the variable be min_diff.
Find the subarray of size m such that the difference between the last (maximum in case of sorted) and first (minimum in case of sorted) elements of the subarray is minimum.
We will run a loop from 0 to (n-m), where n is the size of the given array and m is the size of the subarray.
We will calculate the maximum difference with the subarray and store it in diff = arr[highest index] – arr[lowest index]
Whenever we get a diff less than the min_diff, we will update the min_diff with diff.

// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;
 
// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;
 
    // Sort the given packets
    sort(arr, arr + n);
 
    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;
 
    // Largest number of chocolates
    int min_diff = INT_MAX;
 
    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.
 
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
 
int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}

Output:Minimum difference is 10
Time Complexity: O(N*log(N))
Auxiliary Space: O(1)

Smallest Subarray with sum greater than a given value	
--------------------------------------------------------------
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value. 

Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.

A simple solution is to use two nested loops. The outer loop picks a starting element, the inner loop considers all elements (on right side of current start) as ending element. Whenever sum of elements between current start and end becomes more than the given number, update the result if current length is smaller than the smallest length so far. 

Following is the implementation of simple approach:

# include <iostream>
using namespace std;
 
// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSum(int arr[], int n, int x)
{
    //  Initialize length of smallest subarray as n+1
     int min_len = n + 1;
 
     // Pick every element as starting point
     for (int start=0; start<n; start++)
     {
          // Initialize sum starting with current start
          int curr_sum = arr[start];
 
          // If first element itself is greater
          if (curr_sum > x) return 1;
 
          // Try different ending points for current start
          for (int end=start+1; end<n; end++)
          {
              // add last element to current sum
              curr_sum += arr[end];
 
              // If sum becomes more than x and length of
              // this subarray is smaller than current smallest
              // length, update the smallest length (or result)
              if (curr_sum > x && (end - start + 1) < min_len)
                 min_len = (end - start + 1);
          }
     }
     return min_len;
}
 
/* Driver program to test above function */
int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? cout << "Not possible\n" :
                    cout << res1 << endl;
 
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2+1)? cout << "Not possible\n" :
                    cout << res2 << endl;
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3+1)? cout << "Not possible\n" :
                    cout << res3 << endl;
 
    return 0;
}
Output

3
1
4
Time Complexity: O(n2).
Auxiliary Space: O(1)

Efficient Solution: This problem can be solved in O(n) time using the idea used in this post. Thanks to Ankit and Nitin for suggesting this optimized solution. 


// O(n) solution for finding smallest subarray with sum
// greater than x
#include <iostream>
using namespace std;
 
// Returns length of smallest subarray with sum greater than
// x. If there is no subarray with given sum, then returns
// n+1
int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
 
/* Driver program to test above function */
int main()
{
    int arr1[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n"
                     : cout << res1 << endl;
 
    int arr2[] = { 1, 10, 5, 2, 7 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    x = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2 + 1) ? cout << "Not possible\n"
                     : cout << res2 << endl;
 
    int arr3[] = { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    x = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3 + 1) ? cout << "Not possible\n"
                     : cout << res3 << endl;
 
    return 0;
}
Output
3
1
4
Time Complexity: O(n).
Auxiliary Space: O(1)

How to handle negative numbers? 

The above solution may not work if input array contains negative numbers. For example arr[] = {- 8, 1, 4, 2, -6}. To handle negative numbers, add a condition to ignore subarrays with negative sums.

FOR THIS QS----->Find all subarrays with sum in the given range
Given an unsorted array of size, N. Find subarrays that add to a sum in the given range L-R.

Examples:

Input: arr[] = {2, 3, 5, 8}, L = 4, R = 13
Output: The indexes of subarrays are {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 3}, {3, 3}

Input: arr[] = {1, 4, 6}, L = 3, R = 8
Output: The indexes of subarrays are {0, 1}, {1, 1}, {2, 2}


Naive approach: Follow the given steps to solve the problem using this approach:

Generate every possible subarray using two loops
If the sum of that subarray lies in the range [L, R], then push the starting and ending index into the answer array
Print the subarrays

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to find subarrays with sum
// in the given range
void findSubarrays(vector<int> &arr, vector<pair<int,int>> &ans, int L, int R)
{
    int N = arr.size();
 
      for(int i=0; i<N; i++)
    {
        int sum = 0;
        for(int j=i; j<N; j++)
        {
            sum += arr[j];
           
              // If the sum is in the range then
              // insert it into the answer
            if(sum >= L && sum <= R)
                ans.push_back({i, j});
        }
    }
}
 
void printSubArrays(vector<pair<int,int>> &ans)
{
    int size = ans.size();
      for(int i=0; i<size; i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
 
// Driver Code
int main()
{
    vector<int> arr = {2, 3, 5, 8};
    int L = 4, R = 13;
      vector<pair<int,int>> ans;
     
    // Function call
    findSubarrays(arr, ans, L, R);
      printSubArrays(ans);
   
    return 0;
}
Output
0 1
0 2
1 2
2 2
2 3
3 3
Time complexity: O(N2)
Auxiliary Space: O(N2)

Three way partitioning of an array around a given value	
-------------------------------------------------------------
Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts. 

All elements smaller than lowVal come first. 
All elements in range lowVal to highVal come next. 
All elements greater than highVal appear in the end. 
The individual elements of the three sets can appear in any order.

Examples:

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  , lowVal = 14 , highVal = 20
Output: arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}
Explanation: all elements which are less than 14 are present in the range of 0 to 6
                       all elements which are greater than 14 and less than 20 are present in the range of 7 to 8
                       all elements which are greater than 20 are present in the range of 9 to 12        

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32} , lowVal = 20 , highVal = 20     
Output: arr[] = {1, 14, 5, 4, 2, 1, 3, 20, 20, 98, 87, 32, 54} 

Using Two Pointer:
The idea is based on Dutch National Flag based QuickSort. We traverse the given array of elements from left. We keep track of two pointers, first to store next position of smaller element (smaller than range) from beginning, and second to store next position of greater element from end. while traversing the array use these two pointers to place elements according to there range.

Follow the steps mentioned below to implement the idea:

Create two variables start and end to store the index of the vacant place to store the elements according to their range.
Traverse the array from 0 to end.
If an element is less than lowVal then swap it with the element present at index start and increase the value of start by 1.
If an element is greater than highVal then swap it with the element present at index end and decrease the value of end by 1.
Print the array.                                                                                                                                                                                                                                        

// C++ program to implement three way partitioning
// around a given range.
#include <iostream>
using namespace std;
 
// Partitions arr[0..n-1] around [lowVal..highVal]
void threeWayPartition(int arr[], int n, int lowVal,
                       int highVal)
{
    // Initialize next available positions for
    // smaller (than range) and greater elements
    int start = 0, end = n - 1;
 
    // Traverse elements from left
    for (int i = 0; i <= end;) {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < lowVal) {
            // if i and start are same in that case we can't
            // swap swap only if i is greater than start
            if (i == start) {
                start++;
                i++;
            }
            else
                swap(arr[i++], arr[start++]);
        }
 
        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
 
        else
            i++;
    }
}
 
// Driver code
int main()
{
    int arr[]
        = { 1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    threeWayPartition(arr, n, 10, 20);
 
    cout << "Modified array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
Output
Modified array 
1 5 4 2 1 3 14 20 20 98 87 32 54 
Time Complexity: O(N) 
Auxiliary Space: O(1)

Minimum swaps required bring elements less equal K together	
--------------------------------------------------------------
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together. 

Example: 

Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
Output: 1
Explanation: 
To bring elements 2, 1, 3 together, swap element ‘5’ with ‘3’ such that final array will be arr[] = {2, 1, 3, 6, 5}

Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
Output: 2

Naive Approach: A simple solution is to first count all elements less than or equal to k(say ‘good’). Now traverse for every sub-array and swap those elements whose value is greater than k. The time complexity of this approach is O(n2)

Efficient Approach:  We can use the two-pointer technique and a sliding window.

Find the count of all elements which are less than or equal to ‘k’. Let’s say the count is ‘cnt’
Using the two-pointer technique for a window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
Repeat step 2, for every window of length ‘cnt’ and take a m

Flowchart





























// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;
 
// Utility function to find minimum swaps
// required to club all elements less than
// or equals to k together
int minSwap(int *arr, int n, int k) {
     
    // Find count of elements which are
    // less than equals to k
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
     
    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;
     
    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
         
        // Decrement count of previous window
        if (arr[i] > k)
            --bad;
         
        // Increment count of current window
        if (arr[j] > k)
            ++bad;
         
        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
}
 
// Driver code
int main() {
     
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";
     
    int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    n = sizeof(arr1) / sizeof(arr1[0]);
    k = 5;
    cout << minSwap(arr1, n, k);
    return 0;
}
Output
1
2
Time Complexity: O(n)
Auxiliary Space: O(1)

Using a simple Sliding window technique without using any pointers which can be done in O(N) time

We will name our sliding window as snowballs. Our snowballs will be a number of elements less than or equal to K. Swap variable will start from 0 and we will increase its size as we encounter any element greater than K. 
If we see an element arr[i] value greater than k, we will increase the swap else we will decrease it.
we will keep the count variable to keep track of the number of swaps and also min_count is required to store the minimum value of count.

#include <bits/stdc++.h>
using namespace std;
 
// Function for finding the minimum number of swaps
// required to bring all the numbers less
// than or equal to k together. 
int minSwap(int arr[], int n, int k)
{
 
    // Initially snowBallsize is 0
    int snowBallSize = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Calculating the size of window required
        if (arr[i] <= k) {
            snowBallSize++;
        }
    }
 
    int swap = 0, ans_swaps = INT_MAX;
 
    for (int i = 0; i < snowBallSize; i++) {
        if (arr[i] > k)
            swap++;
    }
 
    ans_swaps = min(ans_swaps, swap);
 
    for (int i = snowBallSize; i < n; i++) {
 
        // Checking in every window no. of swaps required
        // and storing its minimum
        if (arr[i - snowBallSize] <= k && arr[i] > k)
            swap++;
        else if (arr[i - snowBallSize] > k && arr[i] <= k)
            swap--;
        ans_swaps = min(ans_swaps, swap);
    }
    return ans_swaps;
}
 
// Driver's code
int main()
{
    int arr1[] = { 2, 7, 9, 5, 8, 7, 4 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 5;
    cout << minSwap(arr1, n, k) << "\n";
    return 0;
}

Output:2
Time Complexity: O(N)
Auxiliary Space: O(1)

Minimum no. of operations required to make an array palindrome	
------------------------------------------------------------------
Given an array arr[] of N elements. The task is to check if the array is PalinArray or not i.e., if all elements of array are palindrome or not. 

Examples: 

Input: arr[] = {121, 131, 20} 
Output: Array is not a PalinArray 
For the given array, element 20 is not a palindrome. Thus the array is not a PalinArray.

Input: arr[] = {111, 121, 222, 333, 444} 
Output: Array is a PalinArray 
For the given array, all the elements of the array are palindromes. Thus the array is a PalinArray. 

Approach: 

Traverse all elements of the given array and check if each is a palindrome or not.
If yes, print Array is a PalinArray.
Else, print Array is not a PalinArray.

// CPP implementation to check
// if an array is PalinArray or not
#include<bits/stdc++.h>
using namespace std;
 
    // Function to check if palindrome or not
    bool isPalindrome(int N)
    {
        string str = "" + N;
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i])
                return false;
        }
        return true;
    }
 
    // Function to check
    // if an array is PalinArray or not
    bool isPalinArray(int arr[] , int n)
    {
        // Traversing each element of the array
        // and check if it is palindrome or not
        for (int i = 0; i < n; i++) {
            bool ans = isPalindrome(arr[i]);
            if (ans == false)
                return false;
        }
        return true;
    }
 
    // Driver code
    int main()
    {
        int arr[] = { 121, 131, 20 };
 
        // length of array
        int n = sizeof(arr)/sizeof(arr[0]);
 
        bool res = isPalinArray(arr, n);
        if (res == true)
            cout<<"Array is a PalinArray";
        else
            cout<<"Array is not a PalinArray";
    }

Output
Array is not a PalinArray
Complexity Analysis:

Time Complexity: O(n2) since we need to traverse every nested array in the worst case.
Auxiliary Space: O(1)

Median of 2 sorted arrays of equal size		
--------------------------------------------
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))

Input:
Output:
Explanation:


Note: Since the size of the set for which we are looking for the median is even (2n), we need to take the average of the middle two numbers and return the floor of the average.

Method 1 (Simply count while Merging) 

Use the merge procedure of merge sort. Keep track of count while comparing elements of two arrays. If count becomes n(For 2n elements), we have reached the median. Take the average of the elements at indexes n-1 and n in the merged array. See the below implementation. 


// A Simple Merge based O(n)
// solution to find median of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;
 
/* This function returns
median of ar1[] and ar2[].
Assumptions in this function:
Both ar1[] and ar2[]
are sorted arrays
Both have n elements */
double getMedian(int ar1[], int ar2[], int n)
{
    int i = 0; /* Current index of
                  i/p array ar1[] */
    int j = 0; /* Current index of
                  i/p array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    /* Since there are 2n elements,
    median will be average of elements
    at index n-1 and n in the array
    obtained after merging ar1 and ar2 */
    for (count = 0; count <= n; count++) {
        /* Below is to handle case where
           all elements of ar1[] are
           smaller than smallest(or first)
           element of ar2[]*/
        if (i == n) {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
 
        /*Below is to handle case where
          all elements of ar2[] are
          smaller than smallest(or first)
          element of ar1[]*/
        else if (j == n) {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
        /* equals sign because if two
           arrays have some common elements */
        if (ar1[i] <= ar2[j]) {
            /* Store the prev median */
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else {
            /* Store the prev median */
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
 
    return (1.0 * (m1 + m2)) / 2;
}
 
// Driver Code
int main()
{
    int ar1[] = { 1, 6, 7, 8 };
    int ar2[] = { 2, 3, 4, 5 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    return 0;
}
 
// This code is contributed
// by Shivi_Aggarwal
Output
Median is 4.5
Time Complexity: O(n)
Auxiliary Space: O(1)

Method 2 (By comparing the medians of two arrays) 

This method works by first getting medians of the two sorted arrays and then comparing them.
Let ar1 and ar2 be the input arrays. 

Algorithm :  

1) Calculate the medians m1 and m2 of the input arrays ar1[] 
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one    
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays 
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
Examples :  

   ar1[] = {1, 12, 15, 26, 38}
   ar2[] = {2, 13, 17, 30, 45}
For above two arrays m1 = 15 and m2 = 17
For the above ar1[] and ar2[], m1 is smaller than m2. So median is present in one of the following two subarrays. 

   [15, 26, 38] and [2, 13, 17]
Let us repeat the process for above two subarrays:  

    m1 = 26 m2 = 13.
m1 is greater than m2. So the subarrays become  

  [15, 26] and [13, 17]
Now size is 2, so median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
                       = (max(15, 13) + min(26, 17))/2 
                       = (15 + 17)/2
                       = 16
Implementation : 


// A divide and conquer based
// efficient solution to find
// median of two sorted arrays
// of same size.
#include<bits/stdc++.h>
using namespace std;
 
/* to get median of a
   sorted array */
int median(int [], int);
 
/* This function returns median
   of ar1[] and ar2[].
Assumptions in this function:
    Both ar1[] and ar2[] are
    sorted arrays
    Both have n elements */
int getMedian(int ar1[],
              int ar2[], int n)
{
    /* return -1 for
       invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] +
                ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) +
                min(ar1[1], ar2[1])) / 2;
 
    /* get the median of
       the first array */
    int m1 = median(ar1, n);
     
    /* get the median of
       the second array */
    int m2 = median(ar2, n);
 
    /* If medians are equal then
       return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must
       exist in ar1[m1....] and
                ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1,
                             ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2,
                         ar2, n - n / 2);
    }
 
    /* if m1 > m2 then median must
       exist in ar1[....m1] and
                ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1,
                         ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2,
                     ar1, n - n / 2);
}
 
/* Function to get median
   of a sorted array */
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] +
                arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}
 
// Driver code
int main()
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1) /
             sizeof(ar1[0]);
    int n2 = sizeof(ar2) /
             sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays "
             << "of unequal size";
    return 0;
}

Output:
Median is 5
Time Complexity: O(logn) 
Auxiliary Space: O(logn)

Algorithmic Paradigm: Divide and Conquer 

Method 3 (By Merging two arrays w/o extra space)

This method works by merging two arrays without extra space and then sorting them.

Algorithm : 

1) Merge the two input arrays ar1[] and ar2[].
2) Sort ar1[] and ar2[] respectively.
3) The median will be the last element of ar1[] + the first
   element of ar2[] divided by 2. [(ar1[n-1] + ar2[0])/2].
Below is the implementation of the above approach:


// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
/* This function returns
median of ar1[] and ar2[].
Assumptions in this function:
Both ar1[] and ar2[]
are sorted arrays
Both have n elements */
int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}
 
// Driver Code
int main()
{
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
            << " of unequal size";
    getchar();
    return 0;
}
 
// This code is contributed
// by Lakshay
Output
Median is 16
Time Complexity: O(nlogn)
Auxiliary Space: O(1)

Method 4 (Using binary search)

This method can also be used for arrays of different sizes.

Algorithm:

We can find the kth element by using binary search on whole range of constraints of elements.

Initialize ans = 0.0
Intiialize low = -10^9, high = 10^9 and pos = n
Run a loop while(low <= high):
Calculate mid = (low + (high – low)>>1)
Find total elements less or equal to mid in the given arrays
If the count is less or equal to pos
Update low = mid + 1
Else high = mid – 1
Store low in ans, i.e., ans = low.
Again follow step3 with pos as n – 1
Return (sum + low * 1.0)/2

Time Complexity: O(log n)2
Auxiliary Space: O(1)

Median of 2 sorted arrays of different size	
---------------------------------------------------
Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, where N is the number of elements in the first array, and M is the number of elements in the second array. 

This is an extension of median of two sorted arrays of equal size problem. Here we handle arrays of unequal size also.

Examples: 

Input: a[] = {-5, 3, 6, 12, 15}, b[] = {-12, -10, -6, -3, 4, 10}
Output: The median is 3.
Explanation: The merged array is: ar3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15}.
So the median of the merged array is 3


Input: a[] = {2, 3, 5, 8}, b[] = {10, 12, 14, 16, 18, 20}
Output: The median is 11.
Explanation : The merged array is: ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
If the number of the elements are even. So there are two middle elements.
Take the average between the two: (10 + 12) / 2 = 11.

The idea is to merge them into third array and there are tow cases:

Case 1: If the length of the third array is odd, then the median is at (length)/2th index in the array obtained after merging both the arrays.
Case 2: If the length of the third array is even, then the median will be the average of elements at index ((length)/2 ) and ((length)/2 – 1) in the array obtained after merging both arrays.
Illustration:

arr1[] = { -5, 3, 6, 12, 15 } , arr2[] = { -12, -10, -6, -3, 4, 10 }

After merging them in a third array : arr3[] = { -5, 3, 6, 12, 15, -12, -10, -6, -3, 4, 10}
Sort arr3[ ] = { -12, -10, -6, -5, -3, 3, 4, 6, 10, 12, 15 }
As the length of arr3 is odd, so the median is 3
Follow the steps below to solve the problem:

Merge the two given arrays into one array.
Then sort the third(merged) array
If the length of the third array is even then: 
Divide the length of array by 2. Return (arr[value]  + arr[value – 1] / 2).
If the length of the third array is odd then: 
Divide the length of the array by 2 and round that value and return the arr[value] 
Below is the implementation of the above approach:


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
int Solution(int arr[], int n)
{
  
    // If length of array is even
     if (n % 2 == 0)
     {
       int z = n / 2;
       int e = arr[z];
       int q = arr[z - 1];
       int ans = (e + q) / 2;
       return ans;
     }
    
     // If length if array is odd
    else
     {
       int z = round(n / 2);
       return arr[z];
     }
}
 
 // Driver Code
int main() {
    
        // TODO Auto-generated method stub
        int arr1[] = { -5, 3, 6, 12, 15 };
        int arr2[] = { -12, -10, -6, -3, 4, 10 };
 
        int i =  sizeof(arr1) / sizeof(arr1[0]);
        int j =  sizeof(arr2) / sizeof(arr2[0]);
 
        int arr3[i+j];
        int l =  i+j;
        // Merge two array into one array
        for(int k=0;k<i;k++)
        {
            arr3[k]=arr1[k];
        }
          
        int a=0; 
        for(int k=i;k<l;k++)
        {
            arr3[k]=arr2[a++];
        }
 
        // Sort the merged array
        sort(arr3,arr3+l);
 
        // calling the method
        cout<<"Median = " << Solution(arr3, l);
}
 
Output
Median = 3
Time Complexity: O((N + M) Log (N + M)), Time required to sort the array of size N + M
Auxiliary Space: O(N + M), Creating a new array of size N+M.

Median of two sorted arrays of different sizes by Merging Arrays efficiently:
The given arrays are sorted, so merge the sorted arrays in an efficient way and keep the count of elements inserted in the output array or printed form. So when the elements in the output array are half the original size of the given array print the element as a median element. There are two cases: 

Case 1: M+N is odd, the median is at (M+N)/2th index in the array obtained after merging both the arrays.
Case 2: M+N is even, the median will be the average of elements at index ((M+N)/2 – 1) and (M+N)/2 in the array obtained after merging both the arrays
Illustration:

Given two array ar1[ ]= { 900 } and ar2[ ] = { 5, 8, 10, 20 } , n => Size of ar1 = 1 and m => Size of ar2 = 4

Loop will run from 0 till 2. 
First iteration : { 900 }  { 5, 8, 10, 20 } , m1 = 5 
Second iteration : { 900 }  { 5, 8, 10, 20 }, m1 = 8
Third iteration : { 900 }  { 5, 8, 10, 20 }, m1 = 10
As size of ar1 + ar2 = odd , hence we return m1 = 10 as the median
Follow the steps below to solve the problem:

Given two arrays are sorted. So they can be merged in O(m+n) time. Create a variable count to have a count of elements in the output array.
If value of (M+N) is odd, then there is only one median else the median is the average of elements at index (M+N)/2 and ((M+N)/2 – 1).
To merge both arrays, keep two indices i and j initially assigned to 0. Compare the ith index of 1st array and jth index of the second, increase the index of the smallest element and increase the count.
Store (M+N)/2 and (M+N)/2-1 in two variables.
Check if the count reached (M+N) / 2. If (M+N) is odd return m1. If even return (m1+m2)/2.
 
// A Simple Merge based O(n) solution to find
// median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
 
/* This function returns median of ar1[] and ar2[].
Assumption in this function:
Both ar1[] and ar2[] are sorted arrays */
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
    /*loop till (m+n)/2*/
    for (count = 0; count <= (m + n) / 2; count++) {
        // store (n+m)/2-1 in m2
        m2 = m1;
        if (i != n && j != m) {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if (i < n) {
            m1 = ar1[i++];
        }
        // for case when j<m,
        else {
            m1 = ar2[j++];
        }
    }
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    // index is median i.e. (m+n)/2
    // other wise median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    if ((m + n) % 2 == 1) {
        return m1;
    }
    else {
        return (m1 + m2) / 2;
    }
}
/* Driver code */
int main()
{
    int ar1[] = { 900 };
    int ar2[] = { 5, 8, 10, 20 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
}

Output:10
Time Complexity: O(M + N). To merge both arrays O(M+N) time is needed.
Auxiliary Space: O(1). No extra space is required.

Using Recursion:
The idea is simple, calculate the median of both arrays and discard one-half of each array. This approach takes into consideration the size of the arrays. The smaller-sized array is considered the first array in the parameter.

Illustration :

Let’s take an example to understand this
Input :arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
           brr[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 }

Recursive call 1:
smaller array[] = 1 2 3 4 5 6 7 8 9 10, mid = 5
larger array[] = 11 12 13 14 15 16 17 18 19 , mid = 15

5 < 15
Discard first half of the first array and second half of the second array

Recursive call 2:
smaller array[] = 11 12 13 14 15, mid = 13
larger array[] = 5 6 7 8 9 10, mid = 7

7 < 13
Discard first half of the second array and second half of the first array

Recursive call 3:
smaller array[] = 11 12 13 , mid = 12
larger array[] = 7 8 9 10 , mid = 8

8 < 12
Discard first half of the second array and second half of the first array

Recursive call 4:
smaller array[] = 11 12
larger array[] = 8 9 10

Size of the smaller array is 2 and the size of the larger array is odd
so, the median will be the median of max( 11, 8), 9, min( 10, 12)
that is 9, 10, 11, so the median is 10.

Output:10.000000

Some corner cases:

If the size of the smaller array is 0. Return the median of a larger array.
If the size of the smaller array is 1. 
  The size of the larger array is also 1. Return the median of two elements.
  If the size of the larger array is odd. Then after adding the element from the 2nd array, it will be even so the median will be an average of two mid elements. 
       So the element from the smaller array will affect the median if and only if it lies between (M/2 – 1)th and (M/2 + 1)th element of the larger array. 
       So, find the median in between the four elements, the element of the smaller array and (M/2)th, (M/2 – 1)th, (M/2 + 1)th element of a larger array
  Similarly, if size is even, then check for the median of three elements, the element of the smaller array and (M/2)th, (M/2 – 1)th element of a larger array
If the size of the smaller array is 2 
  If the larger array also has two elements, find the median of four elements.
  If the larger array has an odd number of elements, then the median will be one of the following 3 elements 
       The middle element of the larger array
       Max of the second element of smaller array and element just before the middle, i.e M/2-1th element in a bigger array
       Min of the first element of smaller array and element 
       just after the middle in the bigger array, i.e M/2 + 1th element in the bigger array
If the larger array has an even number of elements, then the median will be one of the following 4 elements 
  The middle two elements of the larger array
  Max of the first element of smaller array and element just before the first middle element in the bigger array, i.e M/2 – 2nd element
  Min of the second element of smaller array and element just after the second middle in the bigger array, M/2 + 1th element

Follow the steps below to solve the problem:

Create a recursive function that takes two arrays and the sizes of both arrays.
Take care of the base cases for the size of arrays less than 2. (previously discussed in Approach).Note: The first array is always the smaller array.
Find the middle elements of both arrays. i.e element at (n – 1)/2 and (m – 1)/2 of first and second array respectively. Compare both elements.
If the middle element of the smaller array is less than the middle element of the larger array then the first half of the smaller array is bound to lie strictly in the first half of the merged array. It can also be stated that there is an element in the first half of the larger array and the second half of the smaller array which is the median. So, reduce the search space to the first half of the larger array and the second half of the smaller array.
Similarly, If the middle element of the smaller array is greater than the middle element of the larger array then reduce the search space to the first half of the smaller array and the second half of the larger array.
Below is the implementation of the above approach:


// A C++ program to find median of two sorted arrays of
// unequal sizes
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to find median of two integers
float MO2(int a, int b) { return (a + b) / 2.0; }
 
// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))
           - min(a, min(b, c));
}
 
// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}
 
// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
    if (n == 0)
        return -1;
    if (n % 2 == 0)
        return (double)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    return arr[n / 2];
}
 
// This function assumes that N is smaller than or equal to
// M This function returns -1 if both arrays are empty
float findMedianUtil(int A[], int N, int B[], int M)
{
    // If smaller array is empty, return median from second
    // array
    if (N == 0)
        return medianSingle(B, M);
 
    // If the smaller array has only one element
    if (N == 1) {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
            return MO2(A[0], B[0]);
 
        // Case 2: If the larger array has odd number of
        // elements, then consider the middle 3 elements of
        // larger array and the only element of smaller
        // array. Take few examples like following A = {9},
        // B[] = {5, 8, 10, 20, 30} and A[] = {1}, B[] = {5,
        // 8, 10, 20, 30}
        if (M & 1)
            return MO2(B[M / 2], MO3(A[0], B[M / 2 - 1],
                                     B[M / 2 + 1]));
 
        // Case 3: If the larger array has even number of
        // element, then median will be one of the following
        // 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        return MO3(B[M / 2], B[M / 2 - 1], A[0]);
    }
 
    // If the smaller array has two elements
    else if (N == 2) {
        // Case 4: If the larger array also has two
        // elements, simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
 
        // Case 5: If the larger array has odd number of
        // elements, then median will be one of the
        // following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and
        // element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and
        // element
        //    just after the middle in bigger array
        if (M & 1)
            return MO3(B[M / 2], max(A[0], B[M / 2 - 1]),
                       min(A[1], B[M / 2 + 1]));
 
        // Case 6: If the larger array has even number of
        // elements, then median will be one of the
        // following 4 elements 1) & 2) The middle two
        // elements of larger array 3) Max of first element
        // of smaller array and element
        //    just before the first middle element in bigger
        //    array
        // 4. Min of second element of smaller array and
        // element
        //    just after the second middle in bigger array
        return MO4(B[M / 2], B[M / 2 - 1],
                   max(A[0], B[M / 2 - 2]),
                   min(A[1], B[M / 2 + 1]));
    }
 
    int idxA = (N - 1) / 2;
    int idxB = (M - 1) / 2;
 
    /* if A[idxA] <= B[idxB], then median must exist in
       A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB])
        return findMedianUtil(A + idxA, N / 2 + 1, B,
                              M - idxA);
 
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N / 2 + 1, B + idxA, M - idxA);
}
 
// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian(int A[], int N, int B[], int M)
{
    if (N > M)
        return findMedianUtil(B, M, A, N);
 
    return findMedianUtil(A, N, B, M);
}
 
// Driver program to test above functions
int main()
{
    int A[] = { 900 };
    int B[] = { 5, 8, 10, 20 };
 
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
 
    printf("%f", findMedian(A, N, B, M));
    return 0;
}
Output
10.000000
Time Complexity: O(min(log M, log N)). In each step, one-half of each array is discarded. So the algorithm takes O(min(log M, log N)) time to reach the median value.
Auxiliary Space: O(1). No extra space is required.

Median of two sorted arrays of different sizes using Binary Search:
The given two arrays are sorted, so we can utilize the ability of Binary Search to divide the array and find the median. Median means the point at which the whole array is divided into two parts. Hence since the two arrays are not merged so to get the median we require merging which is costly. Hence instead of merging, we will use a modified binary search algorithm to efficiently find the median.

Illustration:

 A[ ] = { -5, 3, 6, 12, 15 }, n = 5  &  B[ ] = { -12, -10, -6, -3, 4, 10} , m = 6

realmidinmergedarray = 6. 
start = 0 and end = 5 => mid = 2
leftAsize = 2 and leftBsize = 4
leftA = 3
leftB = -3
rightA = 6
rightB = 4
 A[ ] = { -5, 3, 6, 12, 15 } &  B[ ] = { -12, -10, -6, -3, 4, 10} 
As leftA <= rightB and leftB <= rightA, so the condition holds and 3 is returned as the median
Follow the steps below to solve the problem:

If we would have merged the two arrays, the median is the point that will divide the sorted merged array into two equal parts. So the actual median point in the merged array would have been (M+N+1)/2;
We divide A[] and B[] into two parts. We will find the mid value and divide the first array A[] into two parts and simultaneously choose only those elements from left of B[] array such that the sum of the count of elements in the left part of both A[] and B[] will result in the left part of the merged array. 
 Now we have 4 variables indicating four values two from array A[] and two from array B[].
leftA -> Rightmost element in left part of A.
leftb -> Rightmost element in left part of B
rightA -> Leftmost element in right part of A
rightB -> Leftmost element in right part of B
Hence to confirm that the partition was correct we have to check if leftA<=rightB and leftB<=rightA. This is the case when the sum of two parts of A and B results in the left part of the merged array.
 If the condition fails we have to find another midpoint in A and then left part in B[]. 
If we find leftA > rightB. means we have to decrease the size of A’s partition and shift to lesser value in A[]. 
So update the right pointer of to mid-1 else we will increase the left pointer to mid+1. 
Repeat the above steps with new partitions till we get the answers.
If leftA ≤ rightB and leftB ≤ rightA, then we get the correct partition and our answer depends on the total size of the merged array (i.e. M+N). If (M+N) is even we take max(leftA, leftB) and min(rightA, rightB), add them and divide by 2 to get our answer, else we will just return the maximum of leftA and leftB.
Below is the implementation of the above problem:


#include <bits/stdc++.h>
using namespace std;
 
// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}
 
// Driver code
int main()
{
    vector<int> arr1 = { -5, 3, 6, 12, 15 };
    vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
    cout << "Median of the two arrays are" << endl;
    cout << Median(arr1, arr2);
    return 0;
}
Output
Median of the two arrays are
3
Time Complexity: O(min(log M, log N)): Since binary search is being applied on the smaller of the 2 arrays
Auxiliary Space: O(1)
