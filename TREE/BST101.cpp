----------------------------------------------------------------------------------------
                            Binary Search Tree
----------------------------------------------------------------------------------------

Populate Inorder successor of all nodes	
----------------------------------------------------
Given a Binary Tree where each node has the following structure, write a function to populate the next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

class node {
public:
    int data;
    node* left;
    node* right;
    node* next;
};

Initially, all next pointers have NULL values. Your function should fill these next pointers so that they point to inorder successor.

Solution (Use Reverse Inorder Traversal) 
Traverse the given tree in reverse inorder traversal and keep track of previously visited node. When a node is being visited, assign a previously visited node as next.

// C++ program to populate inorder
// traversal of all nodes
#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
    node* next;
};
 
/* Set next of p and all descendants of p
by traversing them in reverse Inorder */
void populateNext(node* p)
{
    // The first visited node will be the
    // rightmost node next of the rightmost
    // node will be NULL
    static node* next = NULL;
 
    if (p) {
        // First set the next pointer
        // in right subtree
        populateNext(p->right);
 
        // Set the next as previously visited
        // node in reverse Inorder
        p->next = next;
 
        // Change the prev for subsequent node
        next = p;
 
        // Finally, set the next pointer in
        // left subtree
        populateNext(p->left);
    }
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
node* newnode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;
 
    return (Node);
}
 
// Driver Code
int main()
{
 
    /* Constructed binary tree is
            10
            / \
        8 12
        /
    3
    */
    node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);
 
    // Populates nextRight pointer in all nodes
    populateNext(root);
 
    // Let us see the populated values
    node* ptr = root->left->left;
    while (ptr) {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }
 
    return 0;
}
 
Output

Next of 3 is 8
Next of 8 is 10
Next of 10 is 12
Next of 12 is -1
We can avoid the use of static variables by passing reference to next as a parameter. 


// An implementation that doesn't use static variable
 
// A wrapper over populateNextRecur
void populateNext(node* root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    node* next = NULL;
 
    populateNextRecur(root, &next);
}
 
/* Set next of all descendants of p by
traversing them in reverse Inorder */
void populateNextRecur(node* p, node** next_ref)
{
    if (p) {
        // First set the next pointer in right subtree
        populateNextRecur(p->right, next_ref);
 
        // Set the next as previously visited
        // node in reverse Inorder
        p->next = *next_ref;
 
        // Change the prev for subsequent node
        *next_ref = p;
 
        // Finally, set the next pointer in right subtree
        populateNextRecur(p->left, next_ref);
    }
}
 
Time Complexity: O(n)

Approach:

Steps:

Create an array or an ArrayList.
Store the inorder traversal of the binary tree into the ArrayList (nodes are to be stored).
Now traverse the array and replace the next pointer of the node to the immediate right node(next element in the array which is the required inorder successor).

    list.get(i).next = list.get(i+1)

Implementation:

// C++ Program to populate inorder successor for all nodes
#include <bits/stdc++.h>
using namespace std;
 
// class Node
class Node {
public:
    int data;
    Node *left, *right, *next;
 
    // constructor for initializing key value and all the
    // pointers
    Node(int data)
    {
        this->data = data;
        left = right = next = nullptr;
    }
};
 
// function for populating next pointer to inorder
// successor
void populateNext(Node*& root, vector<Node*>& list)
{
    // list = [3,8,10,12]
 
    // inorder successor of the present node is the
    // immediate right node for ex: inorder successor of
    // 3 is 8
    for (int i = 0; i < list.size(); i++) {
        // check if it is the last node
        // point next of last node(right most) to null
        if (i != list.size() - 1)
            list[i]->next = list[i + 1];
        else
            list[i]->next = nullptr;
    }
 
    // Let us see the populated values
    Node* ptr = root->left->left;
    while (ptr) {
        // -1 is printed if there is no successor
        int print = ptr->next ? ptr->next->data : -1;
        cout << "Next of " << ptr->data << " is: " << print
             << endl;
        ptr = ptr->next;
    }
}
 
// insert the inorder into a list to keep track
// of the inorder successor
void inorder(Node* root, vector<Node*>& list)
{
    if (root) {
        inorder(root->left, list);
        list.push_back(root);
        inorder(root->right, list);
    }
}
 
// Driver function
int main()
{
    /*   10
       /   \
      8    12
     /
    3         */
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
 
    // list to store inorder sequence
    vector<Node*> list;
 
    // function calls
    inorder(root, list);
    populateNext(root, list);
    return 0;
}
 
Output
Next of 3 is: 8
Next of 8 is: 10
Next of 10 is: 12
Next of 12 is: -1

Approach – 3(Using stack)

Use a stack to store all the left elements corresponding to a node to the point that the node is the leftmost node itself. After this, store all the left of the right of the leftmost node in the stack. Then, until and unless the stack is empty, point the next of the current node to the topmost element of the stack and if the topmost element of the node has a right node, store all the left element of the right of the topmost.

#include <iostream>
#include <stack>
using namespace std;
 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
 
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
 
Node* inorder(Node* root)
{
    if (root->left == NULL)
        return root;
    inorder(root->left);
}
 
void populateNext(Node* root)
{
    stack<Node*> s;
    Node* temp = root;
    while (temp->left) {
        s.push(temp);
        temp = temp->left;
    }
    Node* curr = temp;
    if (curr->right) {
        Node* q = curr->right;
        while (q) {
            s.push(q);
            q = q->left;
        }
    }
    while (!s.empty()) {
        Node* inorder = s.top();
        s.pop();
        curr->next = inorder;
        if (inorder->right) {
            Node* q = inorder->right;
            while (q) {
                s.push(q);
                q = q->left;
            }
        }
        curr = inorder;
    }
}
 
Node* newnode(int data)
{
    Node* node = new Node(data);
    return (node);
}
 
int main()
{
    /* Constructed binary tree is
               10
               / \
              8  12
             /
            3
       */
    Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);
    populateNext(root);
    Node* ptr = inorder(root);
    while (ptr) {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next ? ptr->next->data : -1) << endl;
        ptr = ptr->next;
    }
 
    return 0;
}
Output
Next of 3 is 8
Next of 8 is 10
Next of 10 is 12
Next of 12 is -1
Complexity Analysis:
Time Complexity: O(n), where n is the number of nodes in the tree.  
Space Complexity: O(h), where h is the height of the tree. 

Find LCA  of 2 nodes in a BST	
----------------------------------------
Given two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). You may assume that both values exist in the tree. 

Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself). The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root [i.e., closest to n1 and n2].

Examples: 

Input Tree: 













Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14 
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14 
which is a ancestor of both the nodes.

Using Recursion:
To solve the problem follow the below idea:

For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. 

So just recursively traverse the BST , if node’s value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST)

Follow the given steps to solve the problem:

Create a recursive function that takes a node and the two values n1 and n2.
If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for the right subtree.
If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for the left subtree.
If both the above cases are false then return the current node as LCA.

// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node *left, *right;
};
 
/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
 
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}
 
/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}
 
/* Driver code*/
int main()
{
    // Let us construct the BST
    // shown in the above figure
    node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
 
      // Function calls
    int n1 = 10, n2 = 14;
    node* t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
    return 0;
}
 
Output

LCA of 10 and 14 is 12 
LCA of 14 and 8 is 8 
LCA of 10 and 22 is 20 
Time Complexity: O(H). where H is the height of the tree.
Auxiliary Space: O(H), If recursive stack space is ignored, the space complexity of the above solution is constant.

// A recursive CPP program to find LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node *left, *right;
};
 
/* Function to find LCA of n1 and n2.
The function assumes that both n1 and n2
are present in BST */
node* lca(node* root, int n1, int n2)
{
    while (root != NULL) {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
 
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
 
        else
            break;
    }
    return root;
}
 
/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}
 
/* Driver code*/
int main()
{
    // Let us construct the BST shown in the above figure
    node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
 
      // Function calls
    int n1 = 10, n2 = 14;
    node* t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is "
         << t->data << endl;
    return 0;
}
 
Output
LCA of 10 and 14 is 12 
LCA of 14 and 8 is 8 
LCA of 10 and 22 is 20 
Time Complexity: O(H). where H is the height of the tree
Auxiliary Space: O(1). The space complexity of the above solution is constant.

Convert Binary tree into BST	
--------------------------------------
Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that keeps the original structure of Binary Tree. 

Examples

Example 1
Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7


Example 2
Input:
          10
         /  \
        30   15
       /      \
      20       5
Output:
          15
         /  \
       10    20
       /      \
      5        30
Solution:

Following is a 3 step solution for converting Binary tree to Binary Search Tree.

Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. In the following implementation, Quick Sort is used which takes (n^2) time. This can be done in O(nLogn) time using Heap Sort or Merge Sort.
Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step takes O(n) time.
Following is the implementation of the above approach. The main function to convert is highlighted in the following code.

Implementation:

/* A program to convert Binary Tree to Binary Search Tree */
#include <iostream>
using namespace std;
 
/* A binary tree node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* A helper function that stores inorder
   traversal of a tree rooted with node */
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;
 
    /* first store the left subtree */
    storeInorder(node->left, inorder, index_ptr);
 
    /* Copy the root's data */
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* finally store the right subtree */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
 
/* A helper function that copies contents of arr[]
   to Binary Tree. This function basically does Inorder
   traversal of Binary Tree and one by one copy arr[]
   elements to Binary Tree nodes */
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);
 
    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}
 
// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;
 
    /* Count the number of nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);
 
    // Create a temp array arr[] and store inorder
    // traversal of tree in arr[]
    int* arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);
 
    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);
 
    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);
 
    // delete dynamically allocated memory to
    // avoid memory leak
    delete[] arr;
}
 
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Utility function to print inorder
   traversal of Binary Tree */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout <<" "<< node->data;
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Driver function to test above functions */
int main()
{
    struct node* root = NULL;
 
    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /     \
    20     5 */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    binaryTreeToBST(root);
 
    cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
    printInorder(root);
 
    return 0;
}
Output
Following is the inorder traversal of the converted BST
5 10 15 20 30
Complexity Analysis:

Time Complexity: O(nlogn). This is the complexity of the sorting algorithm which we are using after first in-order traversal, rest of the operations take place in linear time.
Auxiliary Space: O(n). Use of data structure ‘array’ to store in-order traversal.
We will be covering another method for this problem which converts the tree using O(height of the tree) extra space.

Convert a normal BST into a Balanced BST	
------------------------------------------------------
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.

Examples : 

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 

A Simple Solution is to traverse nodes in Inorder and one by one insert into a self-balancing BST like AVL tree. Time complexity of this solution is O(n Log n) and this solution doesn’t guarantee 
An Efficient Solution can construct balanced BST in O(n) time with minimum possible height. Below are steps. 

Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
Build a balanced BST from the above created sorted array using the recursive approach discussed here. This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.

// C++ program to convert a left unbalanced BST to
// a balanced BST
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};
 
/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes)
{
    // Base case
    if (root==NULL)
        return;
 
    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
 
/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to
// a balanced BST
Node* buildTree(Node* root)
{
    // Store nodes of given BST in sorted order
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
 
    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 
// Driver program
int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
 
    root = buildTree(root);
 
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);
 
    return 0;
}
Output
Preorder traversal of balanced BST is : 
7 5 6 8 10 

Merge two BST [ V.V.V>IMP ]	
-----------------------------------
You are given two balanced binary search trees e.g., AVL or Red-Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. Let there be m elements in the first tree and n elements in the other tree. Your merge function should take O(m+n) time.
In the following solutions, it is assumed that the sizes of trees are also given as input. If the size is not given, then we can get the size by traversing the tree

Method 1 (Insert elements of the first tree to the second):

Take all elements of the first BST one by one, and insert them into the second BST. Inserting an element to a self-balancing BST takes Logn time (See this) where n is the size of the BST. So time complexity of this method is Log(n) + Log(n+1) … Log(m+n-1). The value of this expression will be between mLogn and mLog(m+n-1). As an optimization, we can pick the smaller tree as the first tree.

Method 2 (Merge Inorder Traversals):

Do inorder traversal of the first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
Do inorder traversal of the second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
The arrays created in steps 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.
The time complexity of this method is O(m+n) which is better than method 1. This method takes O(m+n) time even if the input BSTs are not balanced. 

Following is the implementation of this method.

// C++ program to Merge Two Balanced Binary Search Trees
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
    int data;
    node* left;
    node* right;
};
 
// A utility function to merge two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n);
 
// A helper function that stores inorder
// traversal of a tree in inorder array
void storeInorder(node* node, int inorder[],
                            int *index_ptr);
 
/* A function that constructs Balanced
Binary Search Tree from a sorted array */
node* sortedArrayToBST(int arr[], int start, int end);
 
/* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
node* mergeTrees(node *root1, node *root2, int m, int n)
{
    // Store inorder traversal of
    // first tree in an array arr1[]
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
 
    // Store inorder traversal of second
    // tree in another array arr2[]
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
 
    // Merge the two sorted array into one
    int *mergedArr = merge(arr1, arr2, m, n);
 
    // Construct a tree from the merged
    // array and return root of the tree
    return sortedArrayToBST (mergedArr, 0, m + n - 1);
}
 
/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}
 
// A utility function to print inorder
// traversal of a given binary tree
void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
// A utility function to merge
// two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n)
{
    // mergedArr[] is going to contain result
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
 
    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaller element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
 
    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }
 
    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }
 
    return mergedArr;
}
 
// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    storeInorder(node->left, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* now recur on right child */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A function that constructs Balanced
 Binary Search Tree from a sorted array*/

node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    node *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
    left child of root */
    root->left = sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
    right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
 
/* Driver code*/
int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    node *mergedTree = mergeTrees(root1, root2, 5, 3);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
 
    return 0;
}
 
Output
Following is Inorder traversal of the merged tree 
20 40 50 70 80 100 120 300
 
Method 3 (In-Place Merge using DLL):

We can use a Doubly Linked List to merge trees in place. Following are the steps.

Convert the given two Binary Search Trees into a doubly linked list in place (Refer to this post for this step). 
Merge the two sorted Linked Lists (Refer to this post for this step). 
Build a Balanced Binary Search Tree from the merged list created in step 2. (Refer to this post for this step)
The time complexity of this method is also O(m+n) and this method does conversion in place.

// C++ Code for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
a pointer to left child
and a pointer to right child */
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
 
// Function to return a new Node
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
// Function to convert bst to
// a doubly linked list
void bstTodll(Node* root, Node*& head)
{
    // if root is NULL
    if (!root)
        return;
 
    // Convert right subtree recursively
    bstTodll(root->right, head);
 
    // Update root
    root->right = head;
 
    // if head is not NULL
    if (head) {
 
        // Update left of the head
        head->left = root;
    }
 
    // Update head
    head = root;
 
    // Convert left subtree recursively
    bstTodll(root->left, head);
}
 
// Function to merge two sorted linked list
Node* mergeLinkedList(Node* head1, Node* head2)
{
 
    /*Create head and tail for result list*/
    Node* head = NULL;
    Node* tail = NULL;
 
    while (head1 && head2) {
 
        if (head1->data < head2->data) {
 
            if (!head)
                head = head1;
            else {
 
                tail->right = head1;
                head1->left = tail;
            }
 
            tail = head1;
            head1 = head1->right;
        }
 
        else {
 
            if (!head)
                head = head2;
            else {
                tail->right = head2;
                head2->left = tail;
            }
 
            tail = head2;
            head2 = head2->right;
        }
    }
 
    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
 
    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
 
    // Return the created DLL
    return head;
}
 
// function to convert list to bst
Node* sortedListToBST(Node*& head, int n)
{
    // if no element is left or head is null
    if (n <= 0 || !head)
        return NULL;
 
    // Create left part from the list recursively
    Node* left = sortedListToBST(head, n / 2);
 
    Node* root = head;
    root->left = left;
    head = head->right;
 
    // Create left part from the list recursively
    root->right = sortedListToBST(head, n - (n / 2) - 1);
 
    // Return the root of BST
    return root;
}
 
// This function merges two balanced BSTs
Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
    // Convert BSTs into sorted Doubly Linked Lists
 
    Node* head1 = NULL;
    bstTodll(root1, head1);
    head1->left = NULL;
 
    Node* head2 = NULL;
    bstTodll(root2, head2);
    head2->left = NULL;
 
    // Merge the two sorted lists into one
    Node* head = mergeLinkedList(head1, head2);
 
    // Construct a tree from the merged lists
    return sortedListToBST(head, m + n);
}
 
void printInorder(Node* node)
{
    // if current node is NULL
    if (!node) {
        return;
    }
 
    printInorder(node->left);
 
      // Print node of current data
    cout << node->data << " ";
 
    printInorder(node->right);
}
 
/* Driver code*/
int main()
{
    /* Create following tree as first balanced BST
       100
       / \
      50 300
     / \
    20 70   */
 
    Node* root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
             80
            / \
           40 120
    */
    Node* root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);
 
      // Function Call
    Node* mergedTree = mergeTrees(root1, root2, 5, 3);
 
    cout << "Following is Inorder traversal of the merged "
            "tree \n";
    printInorder(mergedTree);
 
    return 0;
}
 
Output
Following is Inorder traversal of the merged tree 
20 40 50 70 80 100 120 300 
Time Complexity: O(N + M). where N and M are the numbers of nodes in the given trees.
Auxiliary Space: O(1), as constant extra space is used.

Find Kth largest element in a BST	
---------------------------------------------
Given a Binary Search Tree (BST) and a positive integer k, find the k’th largest element in the Binary Search Tree. 
For example, in the following BST, if k = 3, then output should be 14, and if k = 5, then output should be 10. 














The method 1 requires O(n) time. The method 2 takes O(h) time where h is height of BST, but requires augmenting the BST (storing count of nodes in left subtree with every node). 

Approach: 

The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
The reverse inorder traversal traverses all nodes in decreasing order, i.e, visit the right node then centre then left and continue traversing the nodes recursively.
While doing the traversal, keep track of the count of nodes visited so far.
When the count becomes equal to k, stop the traversal and print the key.
Implementation:

// C++ program to find k'th largest element in BST
#include<bits/stdc++.h>
using namespace std;
  
struct Node
{
    int key;
    Node *left, *right;
};
  
// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// A function to find k'th largest element in a given tree.
void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;
  
    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);
  
    // Increment count of visited nodes
    c++;
  
    // If c becomes k now, then this is the k'th largest 
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }
  
    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}
  
// Function to find k'th largest element
void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;
  
    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}
  
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
  
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
  
    /* return the (unchanged) node pointer */
    return node;
}
  
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    int c = 0;
    for (int k=1; k<=7; k++)
        kthLargest(root, k);
  
    return 0;
}
Output
K'th largest element is 80
K'th largest element is 70
K'th largest element is 60
K'th largest element is 50
K'th largest element is 40
K'th largest element is 30
K'th largest element is 20
Complexity Analysis:  

Time Complexity: O(n). 
In worst case the code can traverse each and every node of the tree if the k given is equal to n (total number of nodes in the tree). Therefore overall time complexity is O(n).
Auxiliary Space: O(h). 
Max recursion stack of height h at a given time.

Find Kth smallest element in a BST	
----------------------------------------
Given the root of a binary search tree and K as input, find Kth smallest element in BST. 
For example, in the following BST, if k = 3, then the output should be 10, and if k = 5, then the output should be 14.

Method 1: Using Inorder Traversal (O(n) time and O(h) auxiliary space) 

The Inorder Traversal of a BST traverses the nodes in increasing order. So the idea is to traverse the tree in Inorder. While traversing, keep track of the count of the nodes visited. If the count becomes k, print the node. 

// A simple inorder traversal based C++ program to find k-th
// smallest element in a BST.
#include <iostream>
 
using namespace std;
 
// A BST node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
// Recursive function to insert an key into BST
Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
 
// Function to find k'th smallest element in BST
// Here count denotes the number of nodes processed so far
int count = 0;
Node* kthSmallest(Node* root, int& k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    // search in left subtree
    Node* left = kthSmallest(root->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;
 
    // if current element is k'th smallest, return it
    count++;
    if (count == k)
        return root;
 
    // else search in right subtree
    return kthSmallest(root->right, k);
}
 
// Function to print k'th smallest element in BST
void printKthSmallest(Node* root, int k)
{
    // maintain index to count number of nodes processed so far
 
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
}
 
// main function
int main()
{
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : keys)
        root = insert(root, x);
 
    int k = 3;
    printKthSmallest(root, k);
    return 0;
}
 
Output: 
K-th Smallest Element is 10

Method 2: Augmented Tree Data Structure (O(h) Time Complexity and O(h) auxiliary space)

The idea is to maintain the rank of each node. We can keep track of elements in the left subtree of every node while building the tree. Since we need the K-th smallest element, we can maintain the number of elements of the left subtree in every node.
Assume that the root is having ‘lCount’ nodes in its left subtree. If K = lCount + 1, root is K-th node. If K < lCount + 1, we will continue our search (recursion) for the Kth smallest element in the left subtree of root. If K > lCount + 1, we continue our search in the right subtree for the (K – lCount – 1)-th smallest element. Note that we need the count of elements in the left subtree only.

// A simple inorder traversal based C++ program to find k-th
// smallest element in a BST.
#include <iostream>
using namespace std;
 
// A BST node
struct Node {
    int data;
    Node *left, *right;
    int lCount;
    Node(int x)
    {
        data = x;
        left = right = NULL;
        lCount = 0;
    }
};
 
// Recursive function to insert an key into BST
Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);
 
    // If a node is inserted in left subtree, then lCount of
    // this node is increased. For simplicity, we are
    // assuming that all keys (tried to be inserted) are
    // distinct.
    if (x < root->data) {
        root->left = insert(root->left, x);
        root->lCount++;
    }
 
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
 
// Function to find k'th smallest element in BST
// Here count denotes the number of nodes processed so far
Node* kthSmallest(Node* root, int k)
{
    // base case
    if (root == NULL)
        return NULL;
    int count = root->lCount + 1;
    if (count == k)
        return root;
    if (count > k)
        return kthSmallest(root->left, k);
    // else search in right subtree
    return kthSmallest(root->right, k - count);
}
 
// main function
int main()
{
    Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };
    for (int x : keys)
        root = insert(root, x);
    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->data;
    return 0;
}
 
Output: 
K-th Smallest Element is 12
Time complexity: O(h) where h is the height of the tree.

Count pairs from 2 BST whose sum is equal to given value “X”	
-------------------------------------------------------------------
Given two BSTs containing n1 and n2 distinct nodes respectively. Given a value x. The problem is to count all pairs from both the BSTs whose sum is equal to x.

Examples: 

Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are:
(5, 11), (6, 10) and (8, 8)

Method 1: For each node value a in BST 1, search the value (x – a) in BST 2. If value found then increment the count. For searching a value in BST, refer this post. 
Time complexity: O(n1 * h2), here n1 is number of nodes in first BST and h2 is height of second BST.

Method 2: Traverse BST 1 from smallest value to node to largest. This can be achieved with the help of iterative inorder traversal. Traverse BST 2 from largest value node to smallest. This can be achieved with the help of reverse inorder traversal. Perform these two traversals simultaneously. Sum up the corresponding node’s value from both the BSTs at a particular instance of traversals. If sum == x, then increment count. If x > sum, then move to the inorder successor of the current node of BST 1, else move to the inorder predecessor of the current node of BST 2. Perform these operations until either of the two traversals gets completed.

// C++ implementation to count pairs from two
// BSTs whose sum is equal to a given  value x
#include <bits/stdc++.h>
using namespace std;
 
// structure of a node of BST
struct Node {
    int data;
    Node* left, *right;
};
 
// function to create and return a node of BST
Node* getNode(int data)
{
    // allocate space for the node
    Node* new_node = (Node*)malloc(sizeof(Node));
 
    // put in the data
    new_node->data = data;
    new_node->left = new_node->right = NULL;
}
 
// function to count pairs from two BSTs
// whose sum is equal to a given value x
int countPairs(Node* root1, Node* root2, int x)
{
    // if either of the tree is empty
    if (root1 == NULL || root2 == NULL)
        return 0;
 
    // stack 'st1' used for the inorder
    // traversal of BST 1
    // stack 'st2' used for the reverse
    // inorder traversal of BST 2
    stack<Node*> st1, st2;
    Node* top1, *top2;
 
    int count = 0;
 
    // the loop will break when either of two
    // traversals gets completed
    while (1) {
 
        // to find next node in inorder
        // traversal of BST 1
        while (root1 != NULL) {
            st1.push(root1);
            root1 = root1->left;
        }
 
        // to find next node in reverse
        // inorder traversal of BST 2
        while (root2 != NULL) {
            st2.push(root2);
            root2 = root2->right;
        }
 
        // if either gets empty then corresponding
        // tree traversal is completed
        if (st1.empty() || st2.empty())
            break;
 
        top1 = st1.top();
        top2 = st2.top();
 
        // if the sum of the node's is equal to 'x'
        if ((top1->data + top2->data) == x) {
            // increment count
            count++;
 
            // pop nodes from the respective stacks
            st1.pop();
            st2.pop();
 
            // insert next possible node in the
            // respective stacks
            root1 = top1->right;
            root2 = top2->left;
        }
 
        // move to next possible node in the
        // inorder traversal of BST 1
        else if ((top1->data + top2->data) < x) {
            st1.pop();
            root1 = top1->right;
        }
 
        // move to next possible node in the
        // reverse inorder traversal of BST 2
        else {
            st2.pop();
            root2 = top2->left;
        }
    }
 
    // required count of pairs
    return count;
}
 
// Driver program to test above
int main()
{
    // formation of BST 1
    Node* root1 = getNode(5); /*             5        */
    root1->left = getNode(3); /*           /   \      */
    root1->right = getNode(7); /*         3     7     */
    root1->left->left = getNode(2); /*    / \   / \    */
    root1->left->right = getNode(4); /*  2  4  6  8    */
    root1->right->left = getNode(6);
    root1->right->right = getNode(8);
 
    // formation of BST 2
    Node* root2 = getNode(10); /*           10         */
    root2->left = getNode(6); /*           /   \        */
    root2->right = getNode(15); /*        6     15      */
    root2->left->left = getNode(3); /*    / \   /  \     */
    root2->left->right = getNode(8); /*  3  8  11  18    */
    root2->right->left = getNode(11);
    root2->right->right = getNode(18);
 
    int x = 16;
    cout << "Pairs = "
         << countPairs(root1, root2, x);
 
    return 0;
}
Output
Pairs = 3
Time Complexity: O(n1 + n2) 
Auxiliary Space: O(h1 + h2) Where h1 is height of first tree and h2 is height of second tree

Method 3 : 

Recursive approach to solving this question.
Traverse the BST1 and for each node find the diff i.e. (x – root1.data) in BST2 and increment the count.

Implementation:

// C++ implementation to count pairs from two
// BSTs whose sum is equal to a given  value x
#include <bits/stdc++.h>
using namespace std;
 
// structure of a node of BST
struct Node {
    int data;
    Node *left, *right;
 
    // constructor
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
static int pairCount = 0;
 
void findPairs(Node* root2, int diff)
{
    if (root2 == NULL) {
        return;
    }
    if (diff > root2->data) {
        findPairs(root2->right, diff);
    }
    else {
        findPairs(root2->left, diff);
    }
    if (root2->data == diff) {
        pairCount++;
    }
}
 
void traverseTree(Node* root1, Node* root2, int sum)
{
    if (root1 == NULL || root2 == NULL) {
        return;
    }
    traverseTree(root1->left, root2, sum);
    traverseTree(root1->right, root2, sum);
    int diff = sum - root1->data;
    findPairs(root2, diff);
}
 
// function to count pairs from two BSTs
// whose sum is equal to a given value x
int countPairs(Node* root1, Node* root2, int sum)
{
    traverseTree(root1, root2, sum);
    return pairCount;
}
 
// Driver program to test above
int main()
{
    // formation of BST 1
    Node* root1 = new Node(5); /*             5        */
    root1->left = new Node(3); /*           /   \      */
    root1->right = new Node(7); /*         3     7     */
    root1->left->left = new Node(2); /*    / \   / \    */
    root1->left->right = new Node(4); /*  2   4 6   8 */
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);
 
    // formation of BST 2
    Node* root2 = new Node(10); /*           10         */
    root2->left = new Node(6); /*           /   \ */
    root2->right = new Node(15); /*        6     15 */
    root2->left->left = new Node(3); /*    / \   /  \ */
    root2->left->right = new Node(8); /*  3  8  11  18    */
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);
 
    int x = 16;
    cout << "Pairs = " << countPairs(root1, root2, x);
}
 
Output
Pairs = 3

Find the median of BST in O(n) time and O(1) space	
-------------------------------------------------------
Given a Binary Search Tree, find the median of it. 

If number of nodes are even: then median = ((n/2th node + ((n)/2th+1) node) /2 
If number of nodes are odd: then median = (n+1)/2th node.
Examples:

Input:








Output: median of Below BST is 6.
Explanation: Inorder of Given BST will be  
1, 3, 4, 6, 7, 8, 9 So, here median will 6.


Given BST:
 






Output: median of Below BST is 12

Using Morris Inorder Traversal:
The idea is based on K’th smallest element in BST using O(1) Extra Space.

The task is very simple if we are allowed to use extra space but Inorder to traversal using recursion and stack both use Space which is not allowed here. So, the solution is to do Morris Inorder traversal as it doesn’t require extra space.

Follow the steps mentioned below to implement the idea:

Count the number of nodes in the given BST using Morris Inorder Traversal.
Then perform Morris Inorder traversal one more time by counting nodes and by checking if the count is equal to the median point.
To consider even no. of nodes, an extra pointer pointing to the previous node is used.

/* C++ program to find the median of BST in O(n)
   time and O(1) space*/
#include<bits/stdc++.h>
using namespace std;
 
/* A binary search tree Node has data, pointer
   to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with
   given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
/* Function to count nodes in a  binary search tree
   using Morris Inorder traversal*/
int counNodes(struct Node *root)
{
    struct Node *current, *pre;
 
    // Initialise count of nodes as 0
    int count = 0;
 
    if (root == NULL)
        return count;
 
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Count node if its left is NULL
            count++;
 
            // Move to its right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
 
            while (pre->right != NULL &&
                   pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its
               inorder predecessor */
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to
               restore the original tree i.e., fix
               the right child of predecessor */
            else
            {
                pre->right = NULL;
 
                // Increment count if the current
                // node is to be visited
                count++;
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
 
    return count;
}
 
/* Function to find median in O(n) time and O(1) space
   using Morris Inorder traversal*/
int findMedian(struct Node *root)
{
   if (root == NULL)
        return 0;
 
    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;
 
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;
 
            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count+1)/2)
                return current->data;
 
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (prev->data + current->data)/2;
 
            // Update prev for even no. of nodes
            prev = current;
 
            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to restore the original
              tree i.e., fix the right child of predecessor */
            else
            {
                pre->right = NULL;
 
                prev = pre;
 
                // Count current node
                currCount++;
 
                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return current->data;
 
                else if (count%2==0 && currCount == (count/2)+1)
                    return (prev->data+current->data)/2;
 
                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;
 
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Let us create following BST
                  50
               /     \
              30      70
             /  \    /  \
           20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}
Output
Median of BST is 50
Time Complexity: O(N)
Auxiliary Space: O(1)

Count BST nodes that lie in a given range	
---------------------------------------------------
Given the head of a Binary Search Tree (BST) and a range (l, h), count the number of nodes that lie in the given range (l, h).

Examples:  

Input: Range: [5, 45]

         10
       /     \
    5       50
   /        /    \
 1         40   100
Output:  3
Explanation: There are three nodes in range, 5, 10 and 40


Input: Range: [10, 100]

          10
        /    \
     5      50
   /       /    \
 1        40   100
Output:  4

Approach:

Traverse the given binary search tree starting from root. For every node check if this node lies in range, if yes, then add 1 to result and recur for both of its children. If current node is smaller than low value of range, then recur for right child, else recur for left child.

Follow the below steps to Implement the idea:

Traverse the tree starting from the root.
If root->data is equal to high and root->data is equal to low return 1.
If root->data <= high and root->data >= low then return 1 + count on left of root + count on right of root.
Else if root->data < low return count on right of root.
Else if root->data > high return count on right of root.

// C++ program to count BST nodes within a given range
#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct node
{
    int data;
    struct node* left, *right;
};
 
// Utility function to create new node
node *newNode(int data)
{
    node *temp = new node;
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
// Returns count of nodes in BST in range [low, high]
int getCount(node *root, int low, int high)
{
    // Base case
    if (!root) return 0;
 
    // Special Optional case for improving efficiency
    if (root->data == high && root->data == low)
        return 1;
 
    // If current node is in range, then include it in count and
    // recur for left and right children of it
    if (root->data <= high && root->data >= low)
         return 1 + getCount(root->left, low, high) +
                    getCount(root->right, low, high);
 
    // If current node is smaller than low, then recur for right
    // child
    else if (root->data < low)
         return getCount(root->right, low, high);
 
    // Else recur for left child
    else return getCount(root->left, low, high);
}
 
// Driver program
int main()
{
    // Let us construct the BST shown in the above figure
    node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(50);
    root->left->left  = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 5;
    int h = 45;
    cout << "Count of nodes between [" << l << ", " << h
         << "] is " << getCount(root, l, h);
    return 0;
}
Output
Count of nodes between [5, 45] is 3
Time complexity: O(H + k) where h is the height of BST and k is the number of nodes in the given range.
Auxiliary Space: O(n) 

Replace every element with the least greater element on its right	
------------------------------------------------------------------------
Given an array of integers, replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1.

Examples: 

Input: [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]

A naive method is to run two loops. The outer loop will one by one pick array elements from left to right. The inner loop will find the smallest element greater than the picked element on its right side. Finally, the outer loop will replace the picked element with the element found by inner loop. The time complexity of this method will be O(n2).

A tricky solution would be to use Binary Search Trees. We start scanning the array from right to left and insert each element into the BST. For each inserted element, we replace it in the array by its inorder successor in BST. If the element inserted is the maximum so far (i.e. its inorder successor doesn’t exist), we replace it by -1.

// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;
 
// A binary Tree node
struct Node {
    int data;
    Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with
given data in BST and find its successor */
Node* insert(Node* root, int val, int& suc)
{
    /* If the tree is empty, return a new node */
    if (!root)
        return newNode(val);
    // go to right subtree
    if (val >= root->data)
        root->right = insert(root->right, val, suc);
    // If key is smaller than root's key, go to left
    // subtree and set successor as current node
    else {
        suc = root->data;
        root->left = insert(root->left, val, suc);
    }
    return root;
}
 
// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
    Node* root = nullptr;
    // start from right to left
    for (int i = n - 1; i >= 0; i--) {
        int suc = -1;
        // insert current element into BST and
        // find its inorder successor
        root = insert(root, arr[i], suc);
        arr[i] = suc;
    }
}
 
// Driver Program to test above functions
int main()
{
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
    replace(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
 
Output
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
The worst-case time complexity of the above solution is also O(n2) as it uses BST. The worst-case will happen when array is sorted in ascending or descending order. The complexity can easily be reduced to O(nlogn) by using balanced trees like red-black trees.

Another Approach:

We can use the Next Greater Element using stack algorithm to solve this problem in O(Nlog(N)) time and O(N) space.

Algorithm:

First, we take an array of pairs namely temp, and store each element and its index in this array,i.e. temp[i] will be storing {arr[i],i}.
Sort the array according to the array elements.
Now get the next greater index for each and every index of the temp array in an array namely index by using Next Greater Element using stack.
Now index[i] stores the index of the next least greater element of the element temp[i].first and if index[i] is -1, then it means that there is no least greater element of the element temp[i].second at its right side.
Now take a result array where result[i] will be equal to a[indexes[temp[i].second]] if index[i] is not -1 otherwise result[i] will be equal to -1.

#include <bits/stdc++.h>
using namespace std;
// function to get the next least greater index for each and
// every temp.second of the temp array using stack this
// function is similar to the Next Greater element for each
// and every element of an array using stack difference is
// we are finding the next greater index not value and the
// indexes are stored in the temp[i].second for all i
vector<int> nextGreaterIndex(vector<pair<int, int> >& temp)
{
    int n = temp.size();
    // initially result[i] for all i is -1
    vector<int> res(n, -1);
    stack<int> stack;
    for (int i = 0; i < n; i++) {
        // if the stack is empty or this index is smaller
        // than the index stored at top of the stack then we
        // push this index to the stack
        if (stack.empty() || temp[i].second < stack.top())
            stack.push(
                temp[i].second); // notice temp[i].second is
                                 // the index
        // else this index (i.e. temp[i].second) is greater
        // than the index stored at top of the stack we pop
        // all the indexes stored at stack's top and for all
        // these indexes we make this index i.e.
        // temp[i].second as their next greater index
        else {
            while (!stack.empty()
                   && temp[i].second > stack.top()) {
                res[stack.top()] = temp[i].second;
                stack.pop();
            }
            // after that push the current index to the
            // stack
            stack.push(temp[i].second);
        }
    }
    // now res will store the next least greater indexes for
    // each and every indexes stored at temp[i].second for
    // all i
    return res;
}
// now we will be using above function for finding the next
// greater index for each and every indexes stored at
// temp[i].second
vector<int> replaceByLeastGreaterUsingStack(int arr[],
                                            int n)
{
    // first of all in temp we store the pairs of {arr[i].i}
    vector<pair<int, int> > temp;
    for (int i = 0; i < n; i++) {
        temp.push_back({ arr[i], i });
    }
    // we sort the temp according to the first of the pair
    // i.e value
    sort(temp.begin(), temp.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             if (a.first == b.first)
                 return a.second > b.second;
             return a.first < b.first;
         });
    // now indexes vector will store the next greater index
    // for each temp[i].second index
    vector<int> indexes = nextGreaterIndex(temp);
    // we initialize a result vector with all -1
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        // now if there is no next greater index after the
        // index temp[i].second the result will be -1
        // otherwise the result will be the element of the
        // array arr at index indexes[temp[i].second]
        if (indexes[temp[i].second] != -1)
            res[temp[i].second]
                = arr[indexes[temp[i].second]];
    }
    // return the res which will store the least greater
    // element of each and every element in the array at its
    // right side
    return res;
}
// driver code
int main()
{
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(int);
    auto res = replaceByLeastGreaterUsingStack(arr, n);
    cout << "Least Greater elements on the right side are "
         << endl;
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
} 
Output
Least Greater elements on the right side are 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 

Another approach with set

A different way to think about the problem is listing our requirements and then thinking over it to find a solution. If we traverse the array from backwards, we need  a data structure(ds) to support:

Insert an element into our ds in sorted order (so at any point of time the elements in our ds are sorted)
Finding the upper bound of the current element (upper bound will give just greater element from our ds if present)
Carefully observing at our requirements, a set is what comes in mind. 

Why not multiset? Well we can use a multiset but there is no need to store an element more than once.

Let’s code our approach

Time and space complexity: We insert each element in our set and find upper bound for each element using a loop so its time complexity is O(n*log(n)). We are storing each element in our set so space complexity is O(n)

#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
void solve(vector<int>& arr)
{
    set<int> s;
    for (int i = arr.size() - 1; i >= 0;
         i--) { // traversing the array backwards
        s.insert(arr[i]); // inserting the element into set
        auto it
            = s.upper_bound(arr[i]); // finding upper bound
        if (it == s.end())
            arr[i] = -1; // if upper_bound does not exist
                         // then -1
        else
            arr[i] = *it; // if upper_bound exists, lets
                          // take it
    }
}
 
void printArray(vector<int>& arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}
 
int main()
{
    vector<int> arr = { 8,  58, 71, 18, 31, 32, 63, 92,
                        43, 3,  91, 93, 25, 80, 28 };
    printArray(arr);
    solve(arr);
    printArray(arr);
    return 0;
}
Output
8 58 71 18 31 32 63 92 43 3 91 93 25 80 28 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 

Given “n” appointments, find the conflicting appointments	
-----------------------------------------------------------
Given n appointments, find all conflicting appointments. 

Examples:

Input: appointments[] = { {1, 5} {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}}
Output: Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]
An appointment is conflicting if it conflicts with any of the previous appointments in the array.

We strongly recommend to minimize the browser and try this yourself first.

A Simple Solution is to one by one process all appointments from the second appointment to last. For every appointment i, check if it conflicts with i-1, i-2, … 0. The time complexity of this method is O(n2). 
We can use Interval Tree to solve this problem in O(nLogn) time. Following is a detailed algorithm. 

Create an Interval Tree, initially with the first appointment.
Do following for all other appointments starting from the second one.
Check if the current appointment conflicts with any of the existing  appointments in Interval Tree.  If conflicts, then print the current appointment.  This step can be done O(Logn) time.
Insert the current appointment in Interval Tree. This step also can be done O(Logn) time.

// C++ program to print all conflicting appointments in a
// given set of appointments
#include <bits/stdc++.h>
using namespace std;
 
// Structure to represent an interval
struct Interval
{
    int low, high;
};
 
// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};
 
// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
      return temp;
};
 
// A utility function to insert a new Interval Search Tree
// Node. This is similar to BST Insert.  Here the low value
//  of interval is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
 
    // Get low value of interval at root
    int l = root->i->low;
 
    // If root's low value is smaller, then new interval
    //  goes to left subtree
    if (i.low < l)
        root->left = insert(root->left, i);
 
    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);
 
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}
 
// The main function that searches a given interval i
// in a given Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;
 
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;
 
    // If left child of root is present and max of left child
    // is greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}
 
// This function prints all conflicting appointments in a given
// array of appointments.
void printConflicting(Interval appt[], int n)
{
     // Create an empty Interval Search Tree, add first
     // appointment
     ITNode *root = NULL;
     root = insert(root, appt[0]);
 
     // Process rest of the intervals
     for (int i=1; i<n; i++)
     {
         // If current appointment conflicts with any of the
         // existing intervals, print it
         Interval *res = overlapSearch(root, appt[i]);
         if (res != NULL)
            cout << "[" << appt[i].low << "," << appt[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
 
         // Insert this appointment
         root = insert(root, appt[i]);
     }
}
 
 
// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15},
                        {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}
Output
Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]

Check preorder is valid or not	
----------------------------------------
Given an array of numbers, return true if given array can represent preorder traversal of a Binary Search Tree, else return false. Expected time complexity is O(n).

Examples:

Input:  pre[] = {2, 4, 3}
Output: true
Given array can represent preorder traversal
of below tree
    2
     \
      4
     /
    3

Input:  pre[] = {2, 4, 1}
Output: false
Given array cannot represent preorder traversal of a Binary Search Tree.

Input:  pre[] = {40, 30, 35, 80, 100}
Output: true
Given array can represent preorder traversal of below tree
     40
   /   \
 30    80 
  \      \
  35     100 


Input:  pre[] = {40, 30, 35, 20, 80, 100}
Output: false
Given array cannot represent preorder traversal of a Binary Search Tree.

A Simple Solution is to do following for every node pre[i] starting from first one. 

1) Find the first greater value on right side of current node. 
   Let the index of this node be j. Return true if following 
   conditions hold. Else return false
    (i)  All values after the above found greater value are 
         greater than current node.
    (ii) Recursive calls for the subarrays pre[i+1..j-1] and 
         pre[j+1..n-1] also return true. 
Time Complexity of the above solution is O(n2)

An Efficient Solution can solve this problem in O(n) time. The idea is to use a stack. This problem is similar to Next (or closest) Greater Element problem. Here we find the next greater element and after finding next greater, if we find a smaller element, then return false.

1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we 
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)  

// C++ program for an efficient solution to check if
// a given array can represent Preorder traversal of
// a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
 
bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;
 
    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;
 
    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;
 
        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }
 
        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}
 
// Driver program
int main()
{
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true\n":
                              cout << "false\n";
 
    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true\n":
                              cout << "false\n";
 
    return 0;
}
Output
true
false
Time Complexity: O(n)
Auxiliary Space: O(n)

Another approach: 

We can check if the given preorder traversal is valid or not for a BST without using stack. The idea is to use the similar concept of “Building a BST using narrowing bound algorithm”. We will recursively visit all nodes, but we will not build the nodes. In the end, if the complete array is not traversed, then that means that array can not represent the preorder traversal of any binary tree.

// C++ program to illustrate if a given array can represent
// a preorder traversal of a BST or not
 
#include <bits/stdc++.h>
using namespace std;
 
// We are actually not building the tree
void buildBST_helper(int& preIndex, int n, int pre[],
                     int min, int max)
{
    if (preIndex >= n)
        return;
 
    if (min <= pre[preIndex] && pre[preIndex] <= max) {
        // build node
        int rootData = pre[preIndex];
        preIndex++;
 
        // build left subtree
        buildBST_helper(preIndex, n, pre, min, rootData);
 
        // build right subtree
        buildBST_helper(preIndex, n, pre, rootData, max);
    }
    // else
    // return NULL;
}
 
bool canRepresentBST(int arr[], int N)
{
    // code here
    int min = INT_MIN, max = INT_MAX;
    int preIndex = 0;
 
    buildBST_helper(preIndex, N, arr, min, max);
 
    return preIndex == N;
}
 
// Driver Code
int main()
{
 
    int preorder1[] = { 2, 4, 3 };
    /*
            2
            \
             4
            /
           3
 
*/
    int n1 = sizeof(preorder1) / sizeof(preorder1[0]);
 
    if (canRepresentBST(preorder1, n1))
        cout << "\npreorder1 can represent BST";
    else
        cout << "\npreorder1 can not represent BST  :(";
 
    int preorder2[] = { 5, 3, 4, 1, 6, 10 };
    int n2 = sizeof(preorder2) / sizeof(preorder2[0]);
    /*
                    5
         /     \
       3         1
         \     /  \
         4    6    10
 
*/
    if (canRepresentBST(preorder2, n2))
        cout << "\npreorder2 can represent BST";
    else
        cout << "\npreorder2 can not represent BST  :(";
 
    int preorder3[] = { 5, 3, 4, 8, 6, 10 };
    int n3 = sizeof(preorder3) / sizeof(preorder3[0]);
    /*
                    5
         /     \
       3         8
         \     /  \
         4    6    10
 
*/
    if (canRepresentBST(preorder3, n3))
        cout << "\npreorder3 can represent BST";
    else
        cout << "\npreorder3 can not represent BST  :(";
 
    return 0;
}
 
Output
preorder1 can represent BST
preorder2 can not represent BST  :(
preorder3 can represent BST
Time complexity: O(N)
Auxiliary Space: O(height of the possible binary tree) 

Check whether BST contains Dead end	
------------------------------------------
Given a Binary search Tree that contains positive integer values greater than 0. The task is to check whether the BST contains a dead end or not. Here Dead End means, we are not able to insert any element after that node.

Examples:  

Input :        8
             /   \ 
           5      9
         /   \
        2     7
       /
      1               
Output : Yes
Explanation : Node "1" is the dead End because
         after that we cant insert any element.       

Input :       8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at node 9.  

If we take a closer look at the problem, we can notice that we basically need to check if there is a leaf node with value x such that x+1 and x-1 exist in BST with the exception of x = 1. For x = 1, we can’t insert 0 as the problem statement says BST contains positive integers only.

To implement the above idea we first traverse the whole BST and store all nodes in a set. We also store all leaves in a separate hash to avoid re-traversal of BST. Finally, we check for every leaf node x, if x-1 and x+1 are present in set or not.

// C++ program check whether BST contains
// dead end or not
#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new Node
  with given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}
 
// Function to store all node of given binary search tree
void storeNodes(Node * root, unordered_set<int> &all_nodes,
                          unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;
 
    // store all node of binary search tree
    all_nodes.insert(root->data);
 
    // store leaf node in leaf_hash
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }
 
    // recur call rest tree
    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}
 
// Returns true if there is a dead end in tree,
// else false.
bool isDeadEnd(Node *root)
{
    // Base case
    if (root == NULL)
        return false ;
 
    // create two empty hash sets that store all
    // BST elements and leaf nodes respectively.
    unordered_set<int> all_nodes, leaf_nodes;
 
    // insert 0 in 'all_nodes' for handle case
    // if bst contain value 1
    all_nodes.insert(0);
 
    // Call storeNodes function to store all BST Node
    storeNodes(root, all_nodes, leaf_nodes);
 
    // Traversal leaf node and check Tree contain
    // continuous sequence of
    // size tree or Not
    for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
    {
        int x = (*i);
 
        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
 
    return false ;
}
 
// Driver program
int main()
{
/*       8
       /   \
      5    11
     /  \
    2    7
     \
      3
       \
        4 */
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
Output
Yes 
Time Complexity : O(n)

Improved Approach

In the above approach we are using 2 hashmaps , one for storing all nodes and one for storing leaf nodes , instead of using 2 maps we can do this problem with 1 hashmap also .

We can pass the hashmap of all nodes and check if for node x there exists a x-1 and x+1 or not. If we got a node for which x+1 and x-1 both are present we will return true otherwise we will return false

Implementation:
// C++ program check whether BST contains dead end or not
#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new Node
  with given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}
void findallNodes(Node* root,map<int,int> &allnodes)
{
    if(root == NULL)
    return ;
     
    allnodes[root->data] = 1;
    findallNodes(root->left,allnodes);
    findallNodes(root->right,allnodes);
}
bool check(Node* root,map<int,int> &allnodes)
{
    if(root == NULL)
    return false;
     
    if(root->left == NULL and root->right == NULL)
    {
        int pre = root->data - 1;
        int next = root->data + 1;
 
        if(allnodes.find(pre) != allnodes.end() and allnodes.find(next) != allnodes.end())
        return true;
    }
     
    return check(root->left,allnodes) or check(root->right,allnodes);
     
}
bool isDeadEnd(Node *root)
{
    // Base case
   if (root == NULL)
        return false ;
    map<int,int> allnodes;
      // adding 0 for handling the exception of node having data = 1
    allnodes[0] = 1;
    findallNodes(root,allnodes);
     
    return check(root,allnodes);
     
}
 
// Driver program
int main()
{
/*       8
       /   \
      5    11
     /  \
    2    7
     \
      3
       \
        4 */
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
Output
Yes 

Largest BST in a Binary Tree [ V.V.V.V.V IMP ]	
--------------------------------------------------
Method 3 (Shorter, Smarter and More Efficient) 

In this section, a different O(n) solution is discussed. This solution is simpler than the solutions discussed in Set-1 and Set-2 and works in O(n) time. In this method, we do not need to check explicitly if the binary tree is BST. A Tree is BST if the following is true for every node x. 

1. The largest value in the left subtree (of x) is smaller than the value of x.
2. The smallest value in the right subtree (of x) is greater than the value of x.

So, we will just check if the largest value of the left subtree is less than the value of the root node and the smallest value of right subtree is greater than the value of root node.

We will use a array/list ans :

• ans[0]=minimum value
• ans[1]=maximum value
• ans[2]=size of current largest BST

Algorithm:

1. If root==None:
return INT_MAX,INT_MIN,0
2. If (root.left==None and root.right==None):
             return root.data,root.data,1
3. Initialize ans=[0,0,0]
4. Check if the largest value of the left subtree is less than the value of the root node and the smallest value of the right subtree is greater than the value of the root node, if this holds true, update the ans accordingly and return ans.
5. If 4 is false, we will assign values as IMIN,IMAX, max(left[2],right[2] and return ans.


// C++ program to find largest BST in a Binary Tree.
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
      Node(int val)
    {
          this->data = val;
          left = NULL;
          right = NULL;
    }
};
 
vector<int> largestBSTBT(Node* root)
{
    // Base cases : When tree is empty or it has one child.
    if (root == NULL)
        return {INT_MAX, INT_MIN, 0};
    if (root->left == NULL && root->right == NULL)
        return {root->data, root->data, 1};
 
    // Recur for left subtree and right subtrees
    vector<int> left = largestBSTBT(root->left);
    vector<int> right = largestBSTBT(root->right);
 
    // Create a return variable and initialize its size.
    vector<int> ans(3, 0);
 
    // If whole tree rooted under current root is BST.
    if ((left[1] < root->data) && (right[0] > root->data))
    {
        ans[0] = min(left[0], min(right[0], root->data));
        ans[1] = max(right[1], max(left[1], root->data));
        // Update answer for tree rooted under current 'root'
        ans[2] = 1 + left[2] + right[2];
        return ans;
    }
 
    // If whole tree is not BST, return maximum of left and right subtrees
    ans[0] = INT_MIN;
    ans[1] = INT_MAX;
    ans[2] = max(left[2], right[2]);
 
    return ans;
}
 
int largestBSTBTutil(Node *root)
{
      return largestBSTBT(root)[2];
}
 
// Driver Function
int main() {
 
    /* Let us construct the following Tree
        50
       /  \
      75  45
     /
    45 */
 
    struct Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);
    printf(" Size of the largest BST is %d\n", largestBSTBTutil(root));
    return 0;
}
 
Output
Size of the largest BST is 2
Time Complexity: O(n), Auxiliary Space: O(n)

Flatten BST to sorted list	
-----------------------------------
Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes at its right, and its left node must be NULL after flattening. We must do it in O(H) extra space where ‘H’ is the height of BST.

Examples: 

Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8
Input:
      1
       \
        2
         \
          3
           \
            4
             \
              5
Output: 1 2 3 4 5

Approach: A simple approach will be to recreate the BST from its in-order traversal. This will take O(N) extra space where N is the number of nodes in BST. 

To improve upon that, we will simulate in-order traversal of a binary tree as follows:  

Create a dummy node.
Create a variable called ‘prev’ and make it point to the dummy node.
Perform in-order traversal and at each step. 
Set prev -> right = curr
Set prev -> left = NULL
Set prev = curr
This will improve the space complexity to O(H) in worst case as in-order traversal takes O(H) extra space.

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
 
// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
// Function to print flattened
// binary Tree
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
 
// Function to perform in-order traversal
// recursively
void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
 
// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
    // Dummy node
    node* dummy = new node(-1);
 
    // Pointer to previous element
    node* prev = dummy;
 
    // Calling in-order traversal
    inorder(parent, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
 
    // Delete dummy node
    delete dummy;
    return ret;
}
 
// Driver code
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    // Calling required function
    print(flatten(root));
 
    return 0;
}
Output: 
2 3 4 5 6 7 8
Time Complexity: O(N)
Auxiliary Space: O(H)
