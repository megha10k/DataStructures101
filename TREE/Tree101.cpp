----------------------------------------------------------------------------------------------
                                Binary Trees
-----------------------------------------------------------------------------------------------

Left View of a tree	
----------------------------
Given a Binary Tree, the task is to print the left view of the Binary Tree. The left view of a Binary Tree is a set of leftmost nodes for every level.

Examples: 

Input: 
                   4
                /   \
              5     2
                   /   \
                3     1
              /  \
           6    7

Output: 4 5 3 6
Explanation: 

Input:
         1
      /   \
    2       3
      \   
       4  
         \
          5
            \
             6
Output: 1 2 4 5 6

Using Recursion: 
Keep track of the level of a node by passing the level as a parameter to all recursive calls and also keep track of the maximum level. Whenever, we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level 

Note: We traverse the left subtree before right subtree. 

// C++ program to print left view of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
// A utility function to
// create a new Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print
// left view of a binary tree.
void leftViewUtil(struct Node* root, int level,
                  int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the first Node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
 
// Driver Code
int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    leftView(root);
 
    return 0;
}
Output
10 2 7 14 
Time Complexity: O(N), The function does a simple traversal of the tree, so the complexity is O(n). 
Auxiliary Space: O(h), due to the stack space during recursive call. ‘h’ here is the height of the binary tree.

Using Level Order Traversal: 

The left view contains all nodes that are the first nodes in their levels. A simple solution is to do level order traversal and print the first node in every level. 

Follow the below step to Implement the idea:

Do level order traversal of the tree.
For each level keep a track of the current level and print the first encountered node of this level.
Move to the next level.

// C++ program to print left view of Binary Tree
#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// function to print left view of
// binary tree
void printLeftView(Node* root)
{
    if (!root)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        // number of nodes at current level
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element
            // at the level
            if (i == 1)
                cout<<temp->data<<" ";
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}    
 
// Driver code
int main()
{
    // Let's construct the tree as
    // shown in example
 
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    printLeftView(root);
}

Output
10 2 7 14 
Time Complexity: O(N), where n is the number of nodes in the binary tree.
Auxiliary Space: O(N) since using space for auxiliary queue

Right View of Tree	
-----------------------------
Given a Binary Tree, print the Right view of it. 

The right view of a Binary Tree is a set of nodes visible when the tree is visited from the Right side.

Examples: 

Input:
          1
       /     \
     2        3
   /   \       /  \
  4     5   6    7
                 \
                   8
Output: Right view of the tree is 1 3 7 8

Input:
          1
       /     
     8        
   / 
  7
Output: Right view of the tree is 1 8 7

using Recursion:
The idea is to use recursion and keep track of the maximum level also. And traverse the tree in a manner that the right subtree is visited before the left subtree.

Follow the steps below to solve the problem:

Perform Postorder traversal to get the rightmost node first
Maintain a variable name max_level which will store till which it prints the right view
While traversing the tree in a postorder manner if the current level is greater than max_level then print the current node and update max_level by the current level

// C++ program to print right view of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
// A utility function to
// create a new Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print
// right view of a binary tree.
void rightViewUtil(struct Node* root, int level,
                   int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the last Node of its level
    if (*max_level < level) {
        cout << root->data << "\t";
        *max_level = level;
    }
 
    // Recur for right subtree first,
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
// A wrapper over rightViewUtil()
void rightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
 
// Driver Code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
 
    rightView(root);
 
    return 0;
}
 
Output
1    3    7    8    
Right view of Binary Tree using Queue
Time Complexity: O(N), Traversing the Tree having N nodes
Auxiliary Space: O(N), Function Call stack space in the worst case.

Right View of a Binary Tree using Level Order Traversal:
The idea is to use Level Order Traversal as the last node every level gives the right view of the binary tree.

Follow the steps below to solve the problem:

Perform level order traversal on the tree
At every level print the last node of that level

// C++ program to print left view of
// Binary Tree
 
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// function to print Right view of
// binary tree
void printRightView(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        // get number of nodes for each level
        int n = q.size();
 
        // traverse all the nodes of the current level
        while (n--) {
 
            Node* x = q.front();
            q.pop();
 
            // print the last node of each level
            if (n == 0) {
                cout << x->data << " ";
            }
            // if left child is not null push it into the
            // queue
            if (x->left)
                q.push(x->left);
            // if right child is not null push it into the
            // queue
            if (x->right)
                q.push(x->right);
        }
    }
}
 
// Driver code
int main()
{
    // Let's construct the tree as
    // shown in example
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    printRightView(root);
}

Output
1 3 7 8 
Time Complexity: O(N), where N is the number of nodes in the binary tree.
Auxiliary Space: O(N) since using auxiliary space for queue

Top View of a tree	
---------------------------------
The top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order.

A node x is there in output if x is the topmost node at its horizontal distance. The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1. 

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6

We need to put nodes of the same horizontal distance together. We do a level order traversal so that the topmost node at a horizontal node is visited before any other node of the same horizontal distance below it. Hashing is used to check if a node at a given horizontal distance is seen or not. 

// C++ program to print top view of binary tree
 
#include <bits/stdc++.h>
using namespace std;
 
// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
    int hd;
    int data;
};
 
// function to create a new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
 
// function should print the topView of
// the binary tree
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    // push node and horizontal distance to queue
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
 
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}
 
// Driver code
int main()
{
    /* Create following Binary Tree
         1
        / \
       2   3
        \
          4
           \
            5
              \
               6
    */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topview(root);
    return 0;
}
Output
Following are nodes in top view of Binary Tree
The top view of the tree is : 
2 1 3 6 
Time complexity: O(n*log(n)), where n is the number of nodes in the given tree.
Auxiliary Space : O(n), As we store nodes in the map and queue.


Another approach: This approach does not require a queue. Here we use the two variables, one for the vertical distance of the current node from the root and another for the depth of the current node from the root. We use the vertical distance for indexing. If one node with the same vertical distance comes again, we check if the depth of the new node is lower or higher with respect to the current node with the same vertical distance in the map. If depth of new node is lower, then we replace it.

#include <bits/stdc++.h>
using namespace std;
 
// Structure of binary tree
struct Node {
    Node* left;
    Node* right;
    int data;
};
 
// function to create a new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}
 
// function to fill the map
void fillMap(Node* root, int d, int l,
             map<int, pair<int, int> >& m)
{
    if (root == NULL)
        return;
 
    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }
 
    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}
 
// function should print the topView of
// the binary tree
void topView(struct Node* root)
{
 
    // map to store the pair of node value and its level
    // with respect to the vertical distance from root.
    map<int, pair<int, int> > m;
 
    // fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);
 
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}
// Driver Program to test above functions
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary "
            "Tree\n";
    topView(root);
    return 0;
}
Output
Following are nodes in top view of Binary Tree
2 1 3 6 
Time complexity : O(n*logn), where n is the number of nodes in the given binary tree with each insertion operation in Map requiring O(log2n) complexity.
Auxiliary Space : O(n)

Bottom View of a tree	
---------------------------------
Given a Binary Tree, The task is to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1. 

Examples:

Input:            20
                    /     \
                8         22
             /      \         \
          5         3        25
                   /    \      
              10       14

Output: 5, 10, 3, 14, 25.

Input:              20
                    /     \
                8         22
             /     \     /     \
          5        3  4      25
                  /    \      
              10       14
Output: 5 10 4 14 25. 
Explanation: If there are multiple bottom-most nodes for a horizontal distance from the root, then print the later one in the level traversal. 3 and 4 are both the bottom-most nodes at a horizontal distance of 0, we need to print 4. 

Using level order traversal:
Store tree nodes in a queue for the level order traversal. Start with the horizontal distance hd as 0 of the root node, Using a Map which stores key-value pairs sorted by key and keep on adding a left child to the queue along with the horizontal distance as hd-1 and the right child as hd+1.

Every time a new horizontal distance or an existing horizontal distance is encountered put the node data for the horizontal distance as the key. For the first time it will add it to the map, next time it will replace the value. This will make sure that the bottom-most element for that horizontal distance is present on the map and if you see the tree from beneath that you will see that element. At last traverse the keys of map and print their respective values.

The following are steps to print the Bottom View of the Binary Tree. 

Initialize variable hd = 0,map m with int-int key value pair and queue q to store nodes level-wise.
Set root->hd = hd and push root in q
Run a while loop till q is empty
Store the front element in node temp and temp ->hd in variable hd and pop it then set temp->data as value for key hd in m i.e. m[hd] = temp->data. 
If temp -> left is not NULL and set temp->left->hd = hd-1 as well as If temp -> right is not NULL and set temp->right->hd = hd+1 respectively. 
Iterate over the keys and print the values.

// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
 
// Tree node class
struct Node
{
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node *left, *right; //left and right references
 
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
 
// Method that prints the bottom view.
void bottomView(Node *root)
{
    if (root == NULL)
        return;
 
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
 
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;
 
    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q;
 
    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item
 
    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item
 
        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;
 
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;
 
        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
 
        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
 
    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
 
// Driver Code
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}
Output
Bottom view of the given binary tree :
5 10 4 14 25 
Time Complexity: O(N * logN)
Auxiliary Space: O(N)

Using Depth first search:

Create a map where the key is the horizontal distance and the value is a pair(a, b) where a is the value of the node and b is the height of the node. Perform a pre-order traversal of the tree. If the current node at a horizontal distance of h is the first we’ve seen, insert it into the map. Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update the Map.

Follow the below steps to implement the idea:

Create a map where the key is the horizontal distance and the value is a pair(a, b) where a is the value of the node and b is the height of the node. 
Recursively apply Depth first search on the Tree starting from root node and keep a track of height curr and horizontal distance as hd of the current node with respect to root node as root node’s height is 0.
If there’s no node as value for horizontal distance hd in map then set map[hd] = make_pair(root -> data, curr).
Else store the pair value of mp[hd] in p. Then 
If p.second <= curr then set m[hd].second = curr and m[hd].first = root -> data
Call depth first search for left node of root node with height curr + 1 and horizontal distance as hd – 1 and right node of root node with height curr + 1 and horizontal distance as hd + 1
Base case would be to return when root is NULL.

// C++ Program to print Bottom View of Binary Tree
#include <bits/stdc++.h>
#include <map>
using namespace std;
 
// Tree node class
struct Node
{
    // data of the node
    int data;
     
    // horizontal distance of the node
    int hd;
     
    //left and right references
    Node * left, * right;
     
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};
 
void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;
     
    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }
     
    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
     
    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}
 
void printBottomView(Node * root)
{
     
    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;
     
    printBottomViewUtil(root, 0, 0, m);
     
     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}
 
int main()
{
    Node * root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(25);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;
}
Output
Bottom view of the given binary tree :
5 10 4 14 25 
Time Complexity: O(N * logN) the extra logN factor is for accessing map
Auxiliary Space: O(N)

Zig-Zag traversal of a binary tree	
--------------------------------------------
Write a function to print ZigZag order traversal of a binary tree. For the below binary tree the zigzag order traversal will be 1 3 2 7 6 5 4.

This problem can be solved using two stacks. 

Assume the two stacks are current: currentlevel and nextlevel. We would also need a variable to keep track of the current level order(whether it is left to right or right to left). We pop from the currentlevel stack and print the nodes value. Whenever the current level order is from left to right, push the nodes left child, then its right child to the stack nextlevel. Since a stack is a LIFO(Last-In-First_out) structure, next time when nodes are popped off nextlevel, it will be in the reverse order. On the other hand, when the current level order is from right to left, we would push the nodes right child first, then its left child. Finally, do-not forget to swap those two stacks at the end of each level(i.e., when current level is empty) 

// C++ implementation of a O(n) time method for Zigzag order traversal
#include <iostream>
#include <stack>
using namespace std;
 
// Binary Tree node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// function to print the zigzag traversal
void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
        return;
 
    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;
 
    // push the root
    currentlevel.push(root);
 
    // check if stack is empty  
    bool lefttoright = true;
    while (!currentlevel.empty()) {
 
        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();
 
        // if not null
        if (temp) {
 
            // print the data in it
            cout << temp->data << " ";
 
            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// driver program to test the above function
int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    zizagtraversal(root);
 
    return 0;
}
Output
ZigZag Order traversal of binary tree is 
1 3 2 7 6 5 4 
Time Complexity: O(n) 
Space Complexity: O(n)+(n)=O(n)

Recursive Approach: The approach used here is the observable similarity to the level order traversal. Here we need to include an extra parameter to keep a track of printing each level in left-right or right-left way.

Implementation:

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left;
    Node *right;
 
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 
// Function to Build Tree
Node* buildTree(string str)
{  
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
     
    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;
     
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
         
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
         
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
         
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
             
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
             
        // Get the current node's value from the string
        string currVal = ip[i];
             
        // If the left child is not null
        if(currVal != "N") {
                 
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                 
            // Push it to the queue
            queue.push(currNode->left);
        }
             
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
             
        // If the right child is not null
        if(currVal != "N") {
                 
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                 
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
     
    return root;
}
 
// Function to calculate height of tree
int treeHeight(Node *root){
    if(!root) return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}
 
// Helper Function to store the zig zag order traversal
// of tree in a list recursively
void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int> &ans){
    // Height = 1 means the tree now has only one node
    if(height <= 1){
        if(root) ans.push_back(root->data);
    }
    // When Height > 1
    else{
        if(lor){
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
        }
        else{
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
        }
    }
}
 
// Function to traverse tree in zig zag order
vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    bool leftOrRight = true;
    int height = treeHeight(root);
    for(int i = 1; i <= height; i++){
        zigZagTraversalRecursion(root, i, leftOrRight, ans);
        leftOrRight = !leftOrRight;
    }
    return ans;
}
 
 
int main()
{   
      // Tree:
    //          1
    //        /   \
    //       /     \
    //      /       \
    //     2          3
    //   /   \       /  \
    //  4     5     6     7
    // / \   /  \  / \   /  \
    //8  9  10 11 12 13 14  15
   
    string s = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
    Node* root = buildTree(s);
    vector <int> res = zigZagTraversal(root);
      cout<<"ZigZag traversal of binary tree is:"<<endl;
    for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
    cout<<endl;
  return 0;
}
Output
ZigZag traversal of binary tree is:
1 3 2 4 5 6 7 15 14 13 12 11 10 9 8 

Check if a tree is balanced or not	
----------------------------------------
A height balanced binary tree is a binary tree in which the height of the left subtree and right subtree of any node does not differ by more than 1 and both the left and right subtree are also height balanced.

Examples: The tree on the left is a height balanced binary tree. Whereas the tree on the right is not a height balanced tree. Because the left subtree of the root has a height which is 2 more than the height of the right subtree.
 
Naive Approach: To check if a tree is height-balanced:

Get the height of left and right subtrees using dfs traversal. Return true if the difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false. 

/* CPP program to check if
a tree is height-balanced or not */
 
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        int data = d;
        left = right = NULL;
    }
};
 
// Function to calculate the height of a tree
int height(Node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
    // If tree is not empty then
    // height = 1 + max of left height
    // and right heights
    return 1 + max(height(node->left), height(node->right));
}
 
// Returns true if binary tree
// with root as root is height-balanced
bool isBalanced(Node* root)
{
    // for height of left subtree
    int lh;
 
    // for height of right subtree
    int rh;
 
    // If tree is empty then return true
    if (root == NULL)
        return 1;
 
    // Get the height of left and right sub trees
    lh = height(root->left);
    rh = height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left)
        && isBalanced(root->right))
        return 1;
 
    // If we reach here then tree is not height-balanced
    return 0;
}
 
// Driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
 
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}
 
Output
Tree is not balanced
Time Complexity: O(n^2) in case of full binary tree.
Auxiliary Space: O(n) space for call stack since using recursion

Efficient implementation: Above implementation can be optimized by 

Calculating the height in the same recursion rather than calling a height() function separately. 

For each node make two recursion calls – one for left subtree and the other for the right subtree. 
Based on the heights returned from the recursion calls, decide if the subtree whose root is the current node is height-balanced or not. 
If it is balanced then return the height of that subtree. Otherwise, return -1 to denote that the subtree is not height-balanced.

// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
 
// Function to check if tree is height balanced
int isBalanced(Node* root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}
 
// Driver code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);
 
    if (isBalanced(root) > 0)
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
Output
Balanced
Time Complexity: O(n) 
Because we are only one dfs call and utilizing the height returned from that to determine the height balance, it is performing the task in linear time.
Auxiliary Space: O(n)

Diagonal Traversal of a Binary tree	
---------------------------------------
Consider lines with a slope of -1 that cross through nodes. Print all diagonal elements in a binary tree that belong to the same line, given a binary tree.

Input : Root of below tree







Output : 
Diagonal Traversal of binary tree: 
 8 10 14
 3 6 7 13
 1 4
Observation : root and root->right values will be prioritized over all root->left values.

The plan is to make use of a map. Different slope distances are used in the map as a key. The map’s value is a node vector (or dynamic array). To save values in the map, we traverse the tree. We print the contents of the map after it has been constructed.

// C++ program for diagonal
// traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
// Tree node
struct Node
{
    int data;
    Node *left, *right;
};
 
/* root - root of the binary tree
   d -  distance of current line from rightmost
        -topmost slope.
   diagonalPrint - multimap to store Diagonal
                   elements (Passed by Reference) */
void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left,
                      d + 1, diagonalPrint);
 
    // Vertical distance remains
    // same for right child
    diagonalPrintUtil(root->right,
                         d, diagonalPrint);
}
 
// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{
     
    // create a map of vectors
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
 
// Utility method to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 
    diagonalPrint(root);
 
    return 0;
}
Output
Diagonal Traversal of binary tree : 
8 10 14 
3 6 7 13 
1 4 
Time complexity: O( N logN )
Auxiliary Space: O( N )

The identical problem may be solved with a queue and an iterative method.


#include <bits/stdc++.h>
using namespace std;
 
// Tree node
struct Node {
    int data;
    Node *left, *right;
};
 
vector<int> diagonal(Node* root)
{
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;
 
    // The leftQueue will be a queue which will store all
    // left pointers while traversing the tree, and will be
    // utilized when at any point right pointer becomes NULL
 
    queue<Node*> leftQueue;
    Node* node = root;
 
    while (node) {
 
        // Add current node to output
        diagonalVals.push_back(node->data);
        // If left child available, add it to queue
        if (node->left)
            leftQueue.push(node->left);
 
        // if right child, transfer the node to right
        if (node->right)
            node = node->right;
 
        else {
            // If left child Queue is not empty, utilize it
            // to traverse further
            if (!leftQueue.empty()) {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else {
                // All the right childs traversed and no
                // left child left
                node = NULL;
            }
        }
    }
    return diagonalVals;
}
 
// Utility method to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /* Node* root = newNode(1);
            root->left = newNode(2);
            root->right = newNode(3);
            root->left->left = newNode(9);
            root->left->right = newNode(6);
            root->right->left = newNode(4);
            root->right->right = newNode(5);
            root->right->left->right = newNode(7);
            root->right->left->left = newNode(12);
            root->left->right->left = newNode(11);
            root->left->left->right = newNode(10);*/
 
    vector<int> diagonalValues = diagonal(root);
    for (int i = 0; i < diagonalValues.size(); i++) {
        cout << diagonalValues[i] << " ";
    }
    cout << endl;
 
    return 0;
}
Output
[8, 10, 14, 3, 6, 7, 13, 1, 4]
Time complexity: O( N log N )
Auxiliary Space: O(N)

Approach 2: Using Queue:
Every node will contribute to the formation of the following diagonal. Only when the element’s left is available will we push it into the queue. We’ll process the node and then go to the right.

#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
};
 
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
vector <vector <int>> result;
void diagonalPrint(Node* root)
{
    if(root == NULL)
        return;
 
    queue <Node*> q;
    q.push(root);
 
    while(!q.empty())
    {
        int size = q.size();
        vector <int> answer;
 
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
 
            // traversing each component;
            while(temp)
            {
                answer.push_back(temp->data);
 
                if(temp->left)
                    q.push(temp->left);
 
                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}
 
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
     
    diagonalPrint(root);
 
    for(int i=0 ; i<result.size() ; i++)
    {
        for(int j=0 ; j<result[i].size() ; j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
 
    return 0;
}
Output
8  10  14  
3  6  7  13  
1  4  
Time Complexity: O(N), because we are visiting nodes once.
Auxiliary Space: O(N), because we are using a queue.

Boundary traversal of a Binary tree	
--------------------------------------
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. The boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. (The values of the nodes may still be duplicates.)
The left boundary is defined as the path from the root to the left-most node. The right boundary is defined as the path from the root to the right-most node. If the root doesn’t have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not apply to any subtrees.
The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if it exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
The right-most node is also defined in the same way with left and right exchanged. 
For example, boundary traversal of the following tree is “20 8 4 10 14 25 22”

We break the problem in 3 parts: 

1. Print the left boundary in top-down manner. 
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
…..2.1 Print all leaf nodes of left sub-tree from left to right. 
…..2.2 Print all leaf nodes of right subtree from left to right. 
3. Print the right boundary in bottom-up manner.
We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.

#include <iostream>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
 
// A simple function to print leaf nodes of a binary tree
void printLeaves(Node* root)
{
    if (root == nullptr)
        return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        cout << root->data << " ";
 
    printLeaves(root->right);
}
 
// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root)
{
    if (root == nullptr)
        return;
 
    if (root->left) {
 
        // to ensure top down order, print the node
        // before calling itself for left subtree
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root)
{
    if (root == nullptr)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        cout << root->data << " ";
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to do boundary traversal of a given binary
// tree
void printBoundary(Node* root)
{
    if (root == nullptr)
        return;
 
    cout << root->data << " ";
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
 
    printBoundary(root);
 
    return 0;
}
 
Output
20 8 4 10 14 25 22 
Time Complexity: O(n) where n is the number of nodes in binary tree.
Auxiliary Space: O(n)

Clean Code with returning the traversal:
[No direct printing + Iterative Version of the code]

Algorithm:

Right Boundary – Go Right Right until no Right. Dont Include Leaf nodes. (as it leads to duplication)
Left Boundary – Go Left Left until no Left. Dont Include Leaf nodes. (as it leads to duplication)
Leaf Boundary – Do inorder, if leaf node add to the List.
We pass the array as reference, so its the same memory location used by all functions, to coordinate the result at one place.

#include <bits/stdc++.h>
using namespace std;
  
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};
  
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
 
bool isLeaf(Node* node){
  if(node->left == NULL && node->right==NULL){
    return true;
  }
  return false;
}
 
void addLeftBound(Node * root, vector<int>& ans){
  //Go left left and no left then right but again check from left
  root = root->left;
  while(root!=NULL){
    if(!isLeaf(root)) ans.push_back(root->data);
    if(root->left !=NULL) root = root->left;
    else root = root->right;
  }
}
 
void addRightBound(Node * root, vector<int>& ans){
  //Go right right and no right then left but again check from right
  root = root->right;
  //As we need the reverse of this for Anticlockwise
  stack<int> stk;
  while(root!=NULL){
    if(!isLeaf(root)) stk.push(root->data);
    if(root->right !=NULL) root = root->right;
    else root = root->left;
  }
  while(!stk.empty()){
    ans.push_back(stk.top());
    stk.pop();
  }
}
 
//its kind of inorder
void addLeaves(Node * root, vector<int>& ans){
  if(root==NULL){
    return;
  }
  if(isLeaf(root)){
    ans.push_back(root->data); //just store leaf nodes
    return;
  }
  addLeaves(root->left,ans);
  addLeaves(root->right,ans);
}
 
vector <int> boundary(Node *root)
{
  //Your code here
  vector<int> ans;
  if(root==NULL) return ans;
  if(!isLeaf(root)) ans.push_back(root->data); // if leaf then its done by addLeaf
  addLeftBound(root,ans);
  addLeaves(root,ans);
  addRightBound(root,ans);
 
  return ans;
 
}
 
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
  
    vector<int>ans = boundary(root);
      for(int v : ans){
        cout<<v<<" ";
    }
      cout<<"\n";
  
    return 0;
}
 
Output
20 8 4 10 14 25 22 
Time Complexity: O(n) where n is the number of nodes in binary tree.
Auxiliary Space: O(n) 

Construct Binary Tree from String with Bracket Representation	
------------------------------------------------------------------
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Examples: 

Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  

Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
We know first character in string is root. Substring inside the first adjacent pair of parenthesis is for left subtree and substring inside second pair of parenthesis is for right subtree as in the below diagram. 











We need to find the substring corresponding to left subtree and substring corresponding to right subtree and then recursively call on both of the substrings. 

For this first find the index of starting index and end index of each substring. 
To find the index of closing parenthesis of left subtree substring, use a stack. Let the found index be stored in index variable. 

/* C++ program to construct a binary tree from
   the given string */
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* This function is here just to test  */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
 
// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;
 
    // Inbuilt stack
    stack<char> s;
 
    for (int i = si; i <= ei; i++) {
 
        // if open parenthesis, push it
        if (str[i] == '(')
            s.push(str[i]);
 
        // if close parenthesis
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
 
                // if stack is empty, this is
                // the required index
                if (s.empty())
                    return i;
            }
        }
    }
    // if not found return -1
    return -1;
}
 
// function to construct tree from string
Node* treeFromString(string str, int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;
 
     
      int num = 0;
      // In case the number is having more than 1 digit
      while(si <= ei && str[si] >= '0' && str[si] <= '9')
    {
      num *= 10;
      num += (str[si] - '0');
      si++;
    }
   
      // new root
    Node* root = newNode(num);
    int index = -1;
 
    // if next char is '(' find the index of
    // its complement ')'
    if (si <= ei && str[si] == '(')
        index = findIndex(str, si, ei);
 
    // if index found
    if (index != -1) {
 
        // call for left subtree
        root->left = treeFromString(str, si + 1, index - 1);
 
        // call for right subtree
        root->right
            = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}
 
// Driver Code
int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
}
Output
4 2 3 1 6 5 
Time Complexity: O(N2)
Auxiliary Space: O(N)

Another recursive approach:

The very first element of the string is the root.
If the next two consecutive elements are “(” and “)”, this means there is no left child otherwise we will create and add the left child to the parent node recursively.
Once the left child is added recursively, we will look for consecutive “(” and add the right child to the parent node.
Encountering “)” means the end of either left or right node and we will increment the start index
The recursion ends when the start index is greater than equal to the end index

#include <bits/stdc++.h>
using namespace std;
 
// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
 
// Below function accepts string and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int* start)
{
    // Assuming there is/are no negative
    // character/characters in the string
    if (s.size() == 0 || *start >= s.size())
        return NULL;
 
    // constructing a number from the continuous digits
    int num = 0;
    while (*start < s.size() && s[*start] != '('
           && s[*start] != ')') {
        int num_here = (int)(s[*start] - '0');
        num = num * 10 + num_here;
        *start = *start + 1;
    }
 
    // creating a node from the constructed number from
    // above loop
    struct Node* root = NULL;
      if(num > 0)
      root = new Node(num);
 
    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->left = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
    {
      *start = *start + 1;
      return root;
    }
 
    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if (*start < s.size() && s[*start] == '(') {
        *start = *start + 1;
        root->right = constructtree(s, start);
    }
    if (*start < s.size() && s[*start] == ')')
        *start = *start + 1;
    return root;
}
void preorder(Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    Node* root = constructtree(s, &start);
    preorder(root);
    return 0;
}
Output
4 2 3 1 6 5 

Convert Binary tree into Doubly Linked List	
-----------------------------------------------------
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as in Inorder for the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL. 












A solution to this problem has been discussed in this post. 
In this post, another simple and efficient solution is discussed. The solution discussed here has two simple steps.

Fix Left Pointers: In this step, we change left pointers to point to previous nodes in DLL. The idea is simple, we do in order traversal of the tree. In order to traversal, we keep track of the previously visited node and change the left pointer to the previous node. See fixPrevPtr() implementation below. 
Fix Right Pointers: The above is intuitive and simple. How to change the right pointers to point to the next node in DLL? The idea is to use left pointers fixed in step 1. We start from the rightmost node in Binary Tree (BT). The rightmost node is the last node in DLL. Since left pointers are changed to point to the previous node in DLL, we can linearly traverse the complete DLL using these pointers. The traversal would be from last to the first node. While traversing the DLL, we keep track of the previously visited node and change the right pointer to the previous node. See fixNextPtr() implementation below.  
Implementation:

// A simple inorder traversal based
// program to convert a Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;
 
// A tree node
class node
{
    public:
    int data;
    node *left, *right;
};
 
// A utility function to create
// a new tree node
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return(Node);
}
 
// Standard Inorder traversal of tree
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << "\t" << root->data;
        inorder(root->right);
    }
}
 
// Changes left pointers to work as
// previous pointers in converted DLL
// The function simply does inorder
// traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(node *root)
{
    static node *pre = NULL;
 
    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
 
// Changes right pointers to work
// as next pointers in converted DLL
node *fixNextPtr(node *root)
{
    node *prev = NULL;
 
    // Find the right most node
    // in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;
 
    // Start from the rightmost node,
    // traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
 
    // The leftmost node is head
    // of linked list, return it
    return (root);
}
 
// The main function that converts
// BST to DLL and returns head of DLL
node *BTToDLL(node *root)
{
    // Set the previous pointer
    fixPrevPtr(root);
 
    // Set the next pointer and return head of DLL
    return fixNextPtr(root);
}
 
// Traverses the DLL from left to right
void printList(node *root)
{
    while (root != NULL)
    {
        cout<<"\t"<<root->data;
        root = root->right;
    }
}
 
// Driver code
int main(void)
{
    // Let us create the tree
    // shown in above diagram
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
 
    cout<<"\n\t\tInorder Tree Traversal\n\n";
    inorder(root);
 
    node *head = BTToDLL(root);
 
    cout << "\n\n\t\tDLL Traversal\n\n";
    printList(head);
    return 0;
}
 
Output
        Inorder Tree Traversal

    25    12    30    10    36    15

        DLL Traversal

    25    12    30    10    36    15
Time Complexity: O(n) where n is the number of nodes in a given Binary Tree. The solution simply does two traversals of all Binary Tree nodes.
Auxiliary Space: O(n)
The extra space is used due to recursion call stack of fixPrevPtr function. The worst case happens when the tree is skewed.
 
Convert Binary tree into Sum tree	
------------------------------------------
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree  

                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5
should be changed to 

                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0

Solution: 
Do a traversal of the given tree. In the traversal, store the old value of the current node, recursively call for left and right subtrees and change the value of current node as sum of the values returned by the recursive calls. Finally return the sum of new value and value (which is sum of values in the subtree rooted with this node). 

// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;
 
/* A tree node structure */
class node
{
    public:
int data;
node *left;
node *right;
};
 
// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{
    // Base case
    if(Node == NULL)
    return 0;
 
    // Store the old value
    int old_val = Node->data;
 
    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
 
    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return Node->data + old_val;
}
 
// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout<<" "<<Node->data;
    printInorder(Node->right);
}
 
/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
     
    return temp;
}
 
/* Driver code */
int main()
{
    node *root = NULL;
    int x;
     
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
     
    toSumTree(root);
     
    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout<<"Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}
 
Output
Inorder Traversal of the resultant tree is: 
 0 4 0 20 0 12 0
Time Complexity: The solution involves a simple traversal of the given tree. So the time complexity is O(n) where n is the number of nodes in the given Binary Tree.
Auxiliary Space : O(1) since using constant variables

Convert Binary tree into Sum tree	
-------------------------------------
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree  

                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5
should be changed to 

                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0

Solution: 
Do a traversal of the given tree. In the traversal, store the old value of the current node, recursively call for left and right subtrees and change the value of current node as sum of the values returned by the recursive calls. Finally return the sum of new value and value (which is sum of values in the subtree rooted with this node). 

// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;
 
/* A tree node structure */
class node
{
    public:
int data;
node *left;
node *right;
};
 
// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{
    // Base case
    if(Node == NULL)
    return 0;
 
    // Store the old value
    int old_val = Node->data;
 
    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
 
    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return Node->data + old_val;
}
 
// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout<<" "<<Node->data;
    printInorder(Node->right);
}
 
/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
     
    return temp;
}
 
/* Driver code */
int main()
{
    node *root = NULL;
    int x;
     
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
     
    toSumTree(root);
     
    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout<<"Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}
 
Output
Inorder Traversal of the resultant tree is: 
 0 4 0 20 0 12 0
Time Complexity: The solution involves a simple traversal of the given tree. So the time complexity is O(n) where n is the number of nodes in the given Binary Tree.
Auxiliary Space : O(1) since using constant variables

Construct Binary tree from Inorder and preorder traversal	
--------------------------------------------------------------
In a Preorder sequence, the leftmost element is the root of the tree. So we know ‘A’ is the root for given sequences. By searching ‘A’ in the Inorder sequence, we can find out all elements on the left side of ‘A’ is in the left subtree and elements on right in the right subtree. So we know the below structure now. 

                 A
               /   \
             /       \
           D B E     F C
We recursively follow the above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree() 

Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
Create a new tree node tNode with the data as the picked element. 
Find the picked element’s index in Inorder. Let the index be inIndex. 
Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
return tNode.

/* C++ program to construct tree using
inorder and preorder traversals */
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
    char data;
    node* left;
    node* right;
};
 
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
node* newNode(char data);
 
/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node* tNode = newNode(pre[preIndex++]);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}
 
/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(char data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
 
/* This function is here just to test buildTree() */
void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout<<node->data<<" ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Driver code */
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);
 
    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
 
// This is code is contributed by rathbhupendra
Output
Inorder traversal of the constructed tree is 
D B E A F C 
Time Complexity: O(n^2), The worst case occurs when the tree is left-skewed. Example Preorder and Inorder traversals for worst-case are {A, B, C, D} and {D, C, B, A}. 
Auxiliary Space: O(n), The extra space used is due to the recursive call stack and the worst case occurs for a skewed tree.

Efficient Approach : 

We can optimize the above solution using hashing (unordered_map in C++ or HashMap in Java). We store indexes of inorder traversal in a hash table. So that search can be done O(1) time. 


/* C++ program to construct tree using inorder
   and preorder traversals */
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
 
struct Node* newNode(char data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* Recursive function to construct binary of size
len from Inorder traversal in[] and Preorder traversal
pre[]. Initial values of inStrt and inEnd should be
0 and len -1. The function doesn't do any error
checking for cases where inorder and preorder
do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt,
                       int inEnd, unordered_map<char, int>& mp)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    char curr = pre[preIndex++];
    struct Node* tNode = newNode(curr);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr];
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
 
    return tNode;
}
 
// This function mainly creates an unordered_map, then
// calls buildTree()
struct Node* buldTreeWrap(char in[], char pre[], int len)
{
    // Store indexes of all items so that we
    // we can quickly find later
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    return buildTree(in, pre, 0, len - 1, mp);
}
 
/* This function is here just to test buildTree() */
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
 
    struct Node* root = buldTreeWrap(in, pre, len);
 
    /* Let us test the built tree by printing
      Inorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
}
Output
Inorder traversal of the constructed tree is 
D B E A F C 
Time Complexity: O(n)
Auxiliary Space: O(n), The extra space is used to store the elements in the map also due to recursive function call stack.

Another approach : 

Use the fact that InOrder traversal is Left-Root-Right and PreOrder traversal is Root-Left-Right. Also, the first node in the PreOrder traversal is always the root node and the first node in the InOrder traversal is the leftmost node in the tree.
Maintain two data structures: Stack (to store the path we visited while traversing PreOrder array) and Set (to maintain the node in which the next right subtree is expected).

1. Do below until you reach the leftmost node. 


Keep creating the nodes from the PreOrder traversal 

If the stack’s topmost element is not in the set, link the created node to the left child of the stack’s topmost element (if any), without popping the element. 
Else link the created node to the right child of the stack’s topmost element. Remove the stack’s topmost element from the set and the stack. 
Push the node to a stack.
 

1

2. Keep popping the nodes from the stack until either the stack is empty, or the topmost element of the stack compares to the current element of InOrder traversal. Once the loop is over, push the last node back into the stack and into the set.
 

2

3. Goto Step 1.
 

3


// C++ program to construct a tree using inorder and preorder traversal
#include<bits/stdc++.h>
using namespace std;
 
class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; }
};
 
set<TreeNode*> s;
stack<TreeNode*> st;
 
// Function to build tree using given traversal
TreeNode* buildTree(int preorder[], int inorder[],int n)
{
 
    TreeNode* root = NULL;
    for (int pre = 0, in = 0; pre < n;)
    {
 
        TreeNode* node = NULL;
        do
        {
            node = new TreeNode(preorder[pre]);
            if (root == NULL)
            {
                root = node;
            }
            if (st.size() > 0)
            {
                if (s.find(st.top()) != s.end())
                {
                    s.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                }
                else
                {
                    st.top()->left = node;
                }
            }
            st.push(node);
        } while (preorder[pre++] != inorder[in] && pre < n);
 
        node = NULL;
        while (st.size() > 0 && in < n &&
                st.top()->val == inorder[in])
        {
            node = st.top();
            st.pop();
            in++;
        }
 
        if (node != NULL)
        {
            s.insert(node);
            st.push(node);
        }
    }
 
    return root;
}
 
// Function to print tree in Inorder
void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->val << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
// Driver code
int main()
{
    int in[] = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    int pre[] = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    int len = sizeof(in)/sizeof(int);
 
    TreeNode *root = buildTree(pre, in, len);
 
    printInorder(root);
    return 0;
}
 
Output
9 8 4 2 10 5 10 1 6 3 13 12 7 
Time Complexity: O(n), As we are traversing both the inorder and preorder just once.
Auxiliary Space: O(n), The extra space is used to store the elements in the stack and the set.

Find minimum swaps required to convert a Binary tree into BST	
-------------------------------------------------------------------
Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Examples:  

Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:








Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.









So, minimum 3 swaps are required.


Input : arr[] = { 1, 2, 3 }
Output : 1
Binary tree of the given array:






After swapping node 1 with node 2.








So, only 1 swap required.

The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value. 
So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer. Please refer below post to find minimum number of swaps required to get the array sorted.

Time Complexity: O(n log n).

Implementation:
// C++ program for Minimum swap required to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;
 
// Inorder Traversal of Binary Tree
void inorder(int a[], std::vector<int> &v,
                        int n, int index)
{
    // if index is greater or equal to vector size
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    // push elements in vector
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
 
// Function to find minimum swaps to sort an array
int minSwaps(std::vector<int> &v)
{
    std::vector<pair<int,int> > t(v.size());
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        t[i].first = v[i], t[i].second = i;
     
    sort(t.begin(), t.end());
    for(int i = 0; i < t.size(); i++)
    {
        // second element is equal to i
        if(i == t[i].second)
            continue;
        else
        {
            // swapping of elements
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }
         
        // Second is not equal to i
        if(i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}
 
// Driver code
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}
 
Output
3
Time Complexity: O(nlogn)
Auxiliary Space: O(n) because it is using extra space for array 

Check if Binary tree is Sum tree or not	
-----------------------------------------
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree. 

          26
        /   \
      10     3
    /    \     \
  4      6      3

Method 1 (Simple) 
Get the sum of nodes in the left subtree and right subtree. Check if the sum calculated is equal to the root’s data. Also, recursively check if the left and right subtrees are SumTrees.

// C++ program to check if Binary tree is sum tree or not
#include <iostream>
using namespace std;
 
// A binary tree node has data,
// left child and right child
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
// A utility function to get the sum
// of values in tree with root as root
int sum(struct node *root)
{
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data +
           sum(root->right);
}
 
// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(struct node* node)
{
    int ls, rs;
 
    // If node is NULL or it's a leaf
    // node then return true
    if (node == NULL ||
       (node->left == NULL &&
        node->right == NULL))
        return 1;
 
   // Get sum of nodes in left and
   // right subtrees
   ls = sum(node->left);
   rs = sum(node->right);
 
   // If the node and both of its
   // children satisfy the property
   // return 1 else 0
    if ((node->data == ls + rs) &&
          isSumTree(node->left) &&
          isSumTree(node->right))
        return 1;
 
   return 0;
}
 
// Helper function that allocates a new node
// with the given data and NULL left and right
// pointers.
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// Driver code
int main()
{
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
     
    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
 
    getchar();
    return 0;
}
 
Output
The given tree is a SumTree
Time Complexity: O(n2) in the worst case. The worst-case occurs for a skewed tree.
Auxiliary Space: O(n) for stack space

Method 2 (Tricky) 
Method 1 uses sum() to get the sum of nodes in left and right subtrees. Method 2 uses the following rules to get the sum directly. 
1) If the node is a leaf node then the sum of the subtree rooted with this node is equal to the value of this node. 
2) If the node is not a leaf node then the sum of the subtree rooted with this node is twice the value of this node (Assuming that the tree rooted with this node is SumTree).


// C++ program to check if Binary tree is sum tree or not
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
   left child and right child */
struct node
{
    int data;
    node* left;
    node* right;
};
 
/* Utility function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}
 
/* returns 1 if SumTree property holds for the given
    tree */
int isSumTree(node* node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree
 
    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL || isLeaf(node))
        return 1;
 
    if( isSumTree(node->left) && isSumTree(node->right))
    {
       
        // Get the sum of nodes in left subtree
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);
 
        // Get the sum of nodes in right subtree
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);
 
        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs);
    }
    return 0;
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
node* newNode(int data)
{
    node* node1 = new node();
    node1->data = data;
    node1->left = NULL;
    node1->right = NULL;
    return(node1);
}
 
/* Driver code */
int main()
{
    node *root  = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}
 
Output: 

The given tree is a SumTree
Time Complexity: O(n)

Auxiliary Space: O(n)

Method 3
Similar to postorder traversal iteratively find the sum in each step
Return left + right + current data if left + right is equal to current node data
Else return -1

// C++ program to check if Binary tree is sum tree or not
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
left child and right child */
struct node
{
    int data;
    node* left;
    node* right;
};
 
/* Utility function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}
 
/* returns data if SumTree property holds for the given
    tree else return -1*/
int isSumTree(node* node)
{
    if(node == NULL)
    return 0;
     
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree
     
     
    ls = isSumTree(node->left);
    if(ls == -1)            // To stop for further traversal of tree if found not sumTree
    return -1;
     
    rs = isSumTree(node->right);
    if(rs == -1)            // To stop for further traversal of tree if found not sumTree
    return -1;
     
     
    if(isLeaf(node) || ls + rs == node->data)
    return ls + rs + node->data;
    else
    return -1;
  
}
 
/* Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
node* newNode(int data)
{
    node* node1 = new node();
    node1->data = data;
    node1->left = NULL;
    node1->right = NULL;
    return(node1);
}
 
/* Driver code */
int main()
{
    node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);
     
    int total = isSumTree(root);
    if(total != -1 && total == 2*(root->data))
    cout<<"Tree is a Sum Tree";
    else
    cout<<"Given Tree is not sum Tree";
     
    return 0;
}
 
Time Complexity: O(n), since each element is traversed only once  
Auxiliary Space: O(n), due to recursive stack space

Check if all leaf nodes are at same level or not	
---------------------------------------------------
Given a Binary Tree, check if all leaves are at same level or not. 

          12
        /    \
      5       7       
    /          \ 
   3            1
  Leaves are at same level

          12
        /    \
      5       7       
    /          
   3          
Leaves are Not at same level


          12
        /    
      5             
    /   \        
   3     9
  /      /
 1      2
Leaves are at same level

The idea is to first find the level of the leftmost leaf and store it in a variable leafLevel. Then compare level of all other leaves with leafLevel, if same, return true, else return false. We traverse the given Binary Tree in a Preorder fashion. An argument leaflevel is passed to all calls. The value of leafLevel is initialized as 0 to indicate that the first leaf is not yet seen yet. The value is updated when we find first leaf. Level of subsequent leaves (in preorder) is compared with leafLevel. 

Implementation:
// C++ program to check if all leaves are at same level
#include <bits/stdc++.h>
using namespace std;
 
// A binary tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to allocate
// a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
/* Recursive function which checks whether
all leaves are at same level */
bool checkUtil(struct Node *root,
            int level, int *leafLevel)
{
    // Base case
    if (root == NULL) return true;
 
    // If a leaf node is encountered
    if (root->left == NULL &&
        root->right == NULL)
    {
        // When a leaf node is found
        // first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }
 
        // If this is not first leaf node, compare
        // its level with first leaf's level
        return (level == *leafLevel);
    }
 
    // If this node is not leaf, recursively
    // check left and right subtrees
    return checkUtil(root->left, level + 1, leafLevel) &&
            checkUtil(root->right, level + 1, leafLevel);
}
 
/* The main function to check
if all leafs are at same level.
It mainly uses checkUtil() */
bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}
 
// Driver Code
int main()
{
    // Let us create tree shown in third example
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    getchar();
    return 0;
}
 
Output
Leaves are at same level
Time Complexity: The function does a simple traversal of the tree, so the complexity is O(n).
Auxiliary Space: O(n) for call stack

Method 2 (Iterative): It can also be solved by an iterative approach.

The idea is to iteratively traverse the tree, and when you encounter the first leaf node, store its level in result variable, now whenever you encounter any leaf node, compare its level with previously stored result, they are the same then proceed for the rest of tree, else return false.

Implementation:
// C++ program to check if all leaf nodes are at same level of binary tree
#include <bits/stdc++.h>
using namespace std;
  
// tree node
struct Node {
    int data;
    Node *left, *right;
};
  
// returns a new tree Node
Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// return true if all leaf nodes are
// at same level, else false
int checkLevelLeafNode(Node* root)
{
    if (!root)
        return 1;
  
    // create a queue for level order traversal
    queue<Node*> q;
    q.push(root);
  
    int result = INT_MAX;
     int level = 0;
 
    // traverse until the queue is empty
    while (!q.empty()) {
        int size = q.size();
        level += 1;
 
        // traverse for complete level
        while(size > 0){
            Node* temp = q.front();
            q.pop();
         
            // check for left child
            if (temp->left) {
                q.push(temp->left);
 
                // if its leaf node
                if(!temp->left->right && !temp->left->left){
 
                    // if it's first leaf node, then update result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it's not first leaf node, then compare
                    // the level with level of previous leaf node
                    else if (result != level)
                        return 0;                   
                }
            }
              
             // check for right child
            if (temp->right){
                q.push(temp->right);
 
                // if it's leaf node
                if (!temp->right->left && !temp->right->right)
 
                    // if it's first leaf node till now,
                    // then update the result
                    if (result == INT_MAX)
                        result = level;
                     
                    // if it is not the first leaf node,
                    // then compare the level with level
                    // of previous leaf node
                    else if(result != level)
                        return 0;
                     
               }
               size -= 1;
        }   
    }
     
    return 1;
}
  
// driver program
int main()
{
    // construct a tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
  
    int result = checkLevelLeafNode(root);
    if (result)
        cout << "All leaf nodes are at same level\n";
    else
        cout << "Leaf nodes not at same level\n";
    return 0;
}
Output
All leaf nodes are at same level
Time Complexity: O(n)
Auxiliary Space: O(n)

Check if a Binary Tree contains duplicate subtrees of size 2 or more [ IMP ]	
-------------------------------------------------------------------------------
Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree of size 2 or more. 
Note : Two same leaf nodes are not considered as subtree size of a leaf node is one.

Input :  Binary Tree 
               A
             /    \ 
           B        C
         /   \       \    
        D     E       B     
                     /  \    
                    D    E
Output : Yes

Tree with duplicate Sub-Tree [ highlight by blue color ellipse ]

[ Method 1] 
A simple solution is that, we pick every node of tree and try to find is any sub-tree of given tree is present in tree which is identical with that sub-tree. Here we can use below post to find if a subtree is present anywhere else in tree. 

[Method 2 ]( Efficient solution ) 
An Efficient solution based on tree serialization and hashing. The idea is to serialize subtrees as strings and store the strings in hash table. Once we find a serialized tree (which is not a leaf) already existing in hash-table, we return true. 

// C++ program to find if there is a duplicate sub-tree of size 2 or more.
#include<bits/stdc++.h>
using namespace std;
 
// Separator node
const char MARKER = '$';
 
// Structure for a binary tree node
struct Node
{
    char key;
    Node *left, *right;
};
 
// A utility function to create a new node
Node* newNode(char key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
 
unordered_set<string> subtrees;
 
// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node *root)
{
    string s = "";
 
    // If current node is NULL, return marker
    if (root == NULL)
        return s + MARKER;
 
    // If left subtree has a duplicate subtree.
    string lStr = dupSubUtil(root->left);
    if (lStr.compare(s) == 0)
    return s;
 
    // Do same for right subtree
    string rStr = dupSubUtil(root->right);
    if (rStr.compare(s) == 0)
    return s;
 
    // Serialize current subtree
    s = s + root->key + lStr + rStr;
 
    // If current subtree already exists in hash
    // table. [Note that size of a serialized tree
    // with single node is 3 as it has two marker
    // nodes.
    if (s.length() > 3 &&
        subtrees.find(s) != subtrees.end())
    return "";
 
    subtrees.insert(s);
 
    return s;
}
 
// Driver program to test above functions
int main()
{
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');
 
    string str = dupSubUtil(root);
 
    (str.compare("") == 0) ? cout << " Yes ":
                            cout << " No " ;
    return 0;
}
Output: 
Yes

Check if 2 trees are mirror or not	
------------------------------------------
Given two n-ary trees, the task is to check if they are the mirror of each other or not. Print “Yes” if they are the mirror of each other else “No”.

Examples: 

Input : Node = 3, Edges = 2
Edge 1 of first N-ary: 1 2
Edge 2 of first N-ary: 1 3
Edge 1 of second N-ary: 1 3
Edge 2 of second N-ary: 1 2
Output : Yes

Input : Node = 3, Edges = 2
Edge 1 of first N-ary: 1 2 
Edge 2 of first N-ary: 1 3
Edge 1 of second N-ary: 1 2
Edge 2 of second N-ary: 1 3
Output : No

Approach  1: (Using Hashing)

The idea is to use an unordered map of stacks to check if given N-ary tree are mirror of each other or not. 
Let the first n-ary tree be t1 and the second n-ary tree is t2. For each node in t1, push its connected node in their corresponding stack in the map. Now, for each node in t2, their connected node match with the top of the stack, then pop elements from the stack.  

Otherwise, if the node does not match with the top of the stack then it means two trees are not mirror of each other. 

Now, for each corresponding node do the following:  

  1. Iterate over map of stack
      Push all connected nodes of each node of first tree in map of  stack.

  2. Again iterate over map for each node of second tree
      For example :     

      Let us take one node X of second tree 
      
      For this node X , check in map which stack is used

      a = Top of that stack for node X present in second tree;
      b = Connected node of X in second tree
      if (a != b)
           return false;
      pop node X from stack.

// C++ program to check if two n-ary trees are mirror.
#include <bits/stdc++.h>
using namespace std;
 
// Function to check given two trees are mirror of each other or not
int checkMirrorTree(int M, int N, int u1[ ],
                    int v1[ ] , int u2[], int v2[])
    {
        // Map to store nodes of the tree
        unordered_map<int , stack<int>>mp;
   
        // Traverse first tree nodes
        for (int i = 0 ; i < N ; i++ )
        {
           mp[u1[i]].push(v1[i]);
        }
         
        // Traverse second tree nodes
        for (int i = 0 ; i < N ; i++)
        {
            if(mp[u2[i]].top() != v2[i])
                  return 0;
            mp[u2[i]].pop();
        }
   
        return 1;
    }
 
// Driver code
int main()
{
    int M = 7, N = 6;
     
    //Tree 1
    int u1[] = { 1, 1, 1, 10, 10, 10 };
    int v1[] = { 10, 7, 3, 4, 5, 6 };
   
    //Tree 2
    int u2[] = { 1, 1, 1, 10, 10, 10 };
    int v2[] = { 3, 7, 10, 6, 5, 4 };
 
    if(checkMirrorTree(M, N, u1, v1, u2, v2))
       cout<<"Yes";
    else
       cout<<"No";
   
    return 0;
}
Output
Yes

Sum of Nodes on the Longest path from root to leaf node	
------------------------------------------------------------
Given a binary tree containing n nodes. The problem is to find the sum of all nodes on the longest path from root to leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.
Examples: 
 

Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output : 13

        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13

Approach: Recursively find the length and sum of nodes of each root to leaf path and accordingly update the maximum sum.
Algorithm: 

sumOfLongRootToLeafPath(root, sum, len, maxLen, maxSum)
    if root == NULL
        if maxLen < len
        maxLen = len
        maxSum = sum
    else if maxLen == len && maxSum is less than sum
        maxSum = sum
        return

    sumOfLongRootToLeafPath(root-left, sum + root-data,
                           len + 1, maxLen, maxSum)
    sumOfLongRootToLeafPath(root-right, sum + root-data,
                           len + 1, maxLen, maxSum)

sumOfLongRootToLeafPathUtil(root)
    if (root == NULL)
        return 0
    
    Declare maxSum = Minimum Integer
    Declare maxLen = 0
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum)
    return maxSum
 
// C++ implementation to find the sum of nodes on the longest path from root to leaf node
#include <bits/stdc++.h>
using namespace std;
 
// Node of a binary tree
struct Node {
    int data;
    Node* left, *right;
};
 
// function to get a new node
Node* getNode(int data)
{
    // allocate memory for the node
    Node* newNode = (Node*)malloc(sizeof(Node));
 
    // put in the data
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// function to find the sum of nodes on the
// longest path from root to leaf node
void sumOfLongRootToLeafPath(Node* root, int sum,
                      int len, int& maxLen, int& maxSum)
{
    // if true, then we have traversed a
    // root to leaf path
    if (!root) {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    // recur for left subtree
    sumOfLongRootToLeafPath(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);
 
    // recur for right subtree
    sumOfLongRootToLeafPath(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}
 
// utility function to find the sum of nodes on
// the longest path from root to leaf node
int sumOfLongRootToLeafPathUtil(Node* root)
{
    // if tree is NULL, then sum is 0
    if (!root)
        return 0;
 
    int maxSum = INT_MIN, maxLen = 0;
 
    // finding the maximum sum 'maxSum' for the
    // maximum length root to leaf path
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
 
    // required maximum sum
    return maxSum;
}
 
// Driver program to test above
int main()
{
    // binary tree formation
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*      /          */
    root->right->right = getNode(3); /*     6           */
    root->left->right->left = getNode(6);
 
    cout << "Sum = "
         << sumOfLongRootToLeafPathUtil(root);
 
    return 0;
}
Output
Sum = 13
Time Complexity: O(n) 

Another Approach: Using level order traversal

Create a structure containing the current Node, level and sum in the path.
Push the root element with level 0 and sum as the root’s data.
Pop the front element and update the maximum level sum and maximum level if needed.
Push the left and right nodes if exists.
Do the same for all the nodes in tree.

#include <bits/stdc++.h>
using namespace std;
//Building a tree node having left and right pointers set to null initially
struct Node
{
  Node* left;
  Node* right;
  int data;
  //constructor to set the data of the newly created tree node
  Node(int element){
     data = element;
     this->left = nullptr;
     this->right = nullptr;
  }
};
 
int longestPathLeaf(Node* root){
   
  /* structure to store current Node,it's level and sum in the path*/
  struct Element{
    Node* data;
    int level;
    int sum;
  };
   
  /*
    maxSumLevel stores maximum sum so far in the path
    maxLevel stores maximum level so far
  */
  int maxSumLevel = root->data,maxLevel = 0;
 
  /* queue to implement level order traversal */
   
  list<Element> que;
  Element e;
   
  /* Each element variable stores the current Node, it's level, sum in the path */
 
  e.data = root;
  e.level = 0;
  e.sum = root->data;
   
  /* push the root element*/
  que.push_back(e);
   
  /* do level order traversal on the tree*/
  while(!que.empty()){
 
     Element front = que.front();
     Node* curr = front.data;
     que.pop_front();
      
     /* if the level of current front element is greater than the maxLevel so far then update maxSum*/
     if(front.level > maxLevel){
        maxSumLevel = front.sum;
        maxLevel = front.level;
     }
     /* if another path competes then update if the sum is greater than the previous path of same height*/
     else if(front.level == maxLevel && front.sum > maxSumLevel)
        maxSumLevel = front.sum;
 
     /* push the left element if exists*/ 
     if(curr->left){
        e.data = curr->left;
        e.sum = e.data->data;
        e.sum +=  front.sum;
        e.level = front.level+1;
        que.push_back(e);
     }
     /*push the right element if exists*/
     if(curr->right){
        e.data = curr->right;
        e.sum = e.data->data;
        e.sum +=  front.sum;
        e.level = front.level+1;
        que.push_back(e);
     }
  }
 
  /*return the answer*/
  return maxSumLevel;
}
//Helper function
int main() {
   
  Node* root = new Node(4);        
  root->left = new Node(2);        
  root->right = new Node(5);       
  root->left->left = new Node(7);  
  root->left->right = new Node(1); 
  root->right->left = new Node(2);
  root->right->right = new Node(3);
  root->left->right->left = new Node(6);
   
  cout << longestPathLeaf(root) << "\n";
     
  return 0;
}
Output
13
Time Complexity: O(N)
Auxiliary Space: O(N)

Check if given graph is tree or not.  [ IMP ]	
--------------------------------------------------
Write a function that returns true if a given undirected graph is tree and false otherwise. For example, the following graph is a tree.
 





But the following graph is not a tree. 
 







Approach 1:

An undirected graph is tree if it has following properties. 

There is no cycle. 
The graph is connected.
For an undirected graph we can either use BFS or DFS to detect above two properties.

How to detect cycle in an undirected graph? 
We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle (See Detect cycle in an undirected graph for more details).

How to check for connectivity? 
Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices are reachable or not. If all vertices are reachable, then graph is connected, otherwise not.

Implementation: 

// A C++ Program to check whether a graph is tree or not
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
 
// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj; // Pointer to an array for adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isTree();   // returns true if graph is tree
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}
 
// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for
        // that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current
        // vertex, then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0
    // is cyclic. It also marks all vertices reachable
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;
 
    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
 
    return true;
}
 
// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}
Output
Graph is Tree
Graph is not Tree

Approach 2:

However if we observe carefully the definition of tree and its structure we will deduce that if a graph is connected and has n – 1 edges exactly then the graph is a tree.
Proof: 
Since we have assumed our graph of n nodes to be connected, it must have at least n – 1 edges inside it. Now if we try to add one more edge than the n – 1 edges already the graph will end up forming a cycle and thus will not satisfy the definition of tree. Therefore, it is necessary for a connected graph to have exactly n – 1 edges to avoid forming cycle. 

// A C++ Program to check whether a graph is tree or not
#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
 
// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
      int E;    // No. of edges
    list<int> *adj; // Pointer to an array for adjacency lists
    void dfsTraversal(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isConnected();   // returns true if graph is connected
    bool isTree();     // returns true of the graph is tree
};
 
Graph::Graph(int V)
{
    E = 0;
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    E++;                 // increase the number of edges
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}
 
// A recursive dfs function that uses visited[] and parent to
// traverse the graph and mark visited[v] to true for visited nodes
void Graph::dfsTraversal(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for
        // that adjacent
        if (!visited[*i])
        {
           dfsTraversal(*i, visited, v);
        }
    }
}
 
// Returns true if the graph is connected, else false.
bool Graph::isConnected()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Performing DFS traversal of the graph and marking
    // reachable vertices from 0 to true
    dfsTraversal(0, visited, -1);
 
    // If we find a vertex which is not reachable from 0
    // (not marked by dfsTraversal(), then we return false
    // since graph is not connected
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
 
    // since all nodes were reachable so we returned true and
    // and hence graph is connected
    return true;
}
 
bool Graph::isTree()
{
    // as we proved earlier if a graph is connected and has
    // V - 1 edges then it is a tree i.e. E = V - 1
    return isConnected() and E == V - 1;
}
// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}
Output
Graph is Tree
Graph is not Tree
Time Complexity: O(V + E) For performing the DFS traversal
Auxiliary Space: O(V) For storing the visited array

Find Largest subtree sum in a tree	
---------------------------------------
Given a binary tree, task is to find subtree with maximum sum in tree.

Examples:  

Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.
Approach : Do post order traversal of the binary tree. At every node, find left subtree value and right subtree value recursively. The value of subtree rooted at current node is equal to sum of current node value, left node subtree sum and right node subtree sum. Compare current subtree sum with overall maximum subtree sum so far.

Implementation :  

// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};
 
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
     
    // Subtree sum rooted at current node.
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
 
    // Return current subtree sum to
    // its parent node.
    return currSum;
}
 
// Function to find largest subtree sum.
int findLargestSubtreeSum(Node* root)
{
    // If tree does not exist,
    // then answer is 0.
    if (root == NULL)    
        return 0;
     
    // Variable to store maximum subtree sum.
    int ans = INT_MIN;
 
    // Call to recursive function to
    // find maximum subtree sum.
    findLargestSubtreeSumUtil(root, ans);
 
    return ans;
}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}
Output: 
7
Complexity Analysis:
Time Complexity: O(n), where n is number of nodes.
Auxiliary Space: O(n), function call stack size.

Maximum Sum of nodes in Binary tree such that no two are adjacent	
----------------------------------------------------------------------
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of selected nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected, that is, if we have taken a node in our sum then we can’t take any of its children in consideration and vice versa. 

Examples:  
















In the above binary tree, chosen nodes are encircled 
and are not directly connected, and their sum is
maximum possible.

Method 1 
We can solve this problem by considering the fact that both node and its children can’t be in sum at the same time, so when we take a node into our sum, we will call recursively for its grandchildren or if we don’t take this node then we will call for all its children nodes and finally we will choose maximum from both of the results. 
It can be seen easily that the above approach can lead to solving the same subproblem many times, for example in the above diagram node 1 calls node 4 and 5 when its value is chosen and node 3 also calls them when its value is not chosen so these nodes are processed more than once. We can stop solving these nodes more than once by memorizing the result at all nodes. 
In the below code, a map is used for memorizing the result, which stores the development of the complete subtree rooted at a node in the map so that if it is called again, the value is not calculated again instead stored value from the map is returned directly. 

// C++ program to find maximum sum from a subset of nodes of binary tree
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node structure */
struct node
{
    int data;
    struct node *left, *right;
};
 
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
//  Declaration of methods
int sumOfGrandChildren(node* node, map<struct node*, int>& mp);
int getMaxSum(node* node);
int getMaxSumUtil(node* node, map<struct node*, int>& mp);
 
// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node, map<struct node*, int>& mp)
{
    int sum = 0;
 
    //  call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
               getMaxSumUtil(node->left->right, mp);
 
    //  call for children of right child only if it is not NULL
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) +
               getMaxSumUtil(node->right->right, mp);
 
    return sum;
}
 
//  Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
    if (node == NULL)
        return 0;
 
    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];
 
    //  take current node value and call for all grand children
    int incl = node->data + sumOfGrandChildren(node, mp);
 
    //  don't take current node value and call for all children
    int excl = getMaxSumUtil(node->left, mp) +
               getMaxSumUtil(node->right, mp);
 
    //  choose maximum from both above calls and store that in map
    mp[node] = max(incl, excl);
 
    return mp[node];
}
 
// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
    if (node == NULL)
        return 0;
    map<struct node*, int> mp;
    return getMaxSumUtil(node, mp);
}
 
//  Driver code to test above methods
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
 
    cout << getMaxSum(root) << endl;
    return 0;
}
Output
11
Time complexity: O(n)
Auxiliary Space: O(n)

Method 2 (Using pair) 
Return a pair for each node in the binary tree such that the first of the pair indicates maximum sum when the data of a node is included and the second indicates maximum sum when the data of a particular node is not included. 

// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include<iostream>
using namespace std;
 
class Node
{
public:
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
pair<int, int> maxSumHelper(Node *root)
{
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;
 
    // This node is included (Left and right children
    // are not included)
    sum.first = sum1.second + sum2.second + root->data;
 
    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(sum1.first, sum1.second) +
                 max(sum2.first, sum2.second);
 
    return sum;
}
 
int maxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}
 
// Driver code
int main()
{
    Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << maxSum(root);
    return 0;
}
Output
21
Time complexity: O(n)
Auxiliary Space: O(n)

Print all “K” Sum paths in a Binary tree	
-------------------------------------------------
A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

Examples: 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

Kindly note that this problem is significantly different from finding k-sum path from root to leaves. Here each node can be treated as root, hence the path can start and end at any node.
The basic idea to solve the problem is to do a preorder traversal of the given tree. We also need a container (vector) to keep track of the path that led to that node. At each node we check if there are any path that sums to k, if any we print the path and proceed recursively to print each path.

// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;
  
// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
  
// binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
  
// This function prints all paths that have sum k
void printKPathUtil(Node* root, vector<int>& path, int k)
{
    // empty node
    if (!root)
        return;
  
    // add current node to the path
    path.push_back(root->data);
  
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
  
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
  
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--) {
        f += path[j];
  
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
  
    // Remove the current element from the path
    path.pop_back();
}
  
// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}
  
// Driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
  
    int k = 5;
    printKPath(root, k);
  
    return 0;
}
Output
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
Time Complexity: O(n*h*h)  , as maximum size of path vector can be h 
Space Complexity: O(h)

Find LCA in a Binary tree	
-------------------------------
What is Lowest Common Ancestor in Binary Tree?
The lowest common ancestor is the lowest node in the tree that has both n1 and n2 as descendants, where n1 and n2 are the nodes for which we wish to find the LCA. Hence, the LCA of a binary tree with nodes n1 and n2 is the shared ancestor of n1 and n2 that is located farthest from the root. 

Application of Lowest Common Ancestor(LCA):
To determine the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.
 







By Storing paths from root to n1 and root to n2: 
The idea of this approach is to store the path from the root to n1 and root to n2 in two separate data structures. Then look simultaneously into the values stored in the data structure, and look for the first mismatch.

Illustration:


















Path from root to 5 = { 1, 2, 5 }
Path from root to 6 = { 1, 3, 6 }

We start checking from 0 index. As both of the value matches( pathA[0] = pathB[0] ), we move to the next index.
pathA[1] not equals to pathB[1], there’s a mismatch so we consider the previous value. 
Therefore the LCA of (5,6) = 1
Follow the steps below to solve the problem:

Find a path from the root to n1 and store it in a vector or array. 
Find a path from the root to n2 and store it in another vector or array. 
Traverse both paths till the values in arrays are the same. Return the common element just before the mismatch. 
Following is the implementation of the above algorithm:


// C++ Program for Lowest Common Ancestor
// in a Binary Tree
// A O(n) solution to find LCA
// of two given values n1 and n2
 
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree node
struct Node {
    int key;
    struct Node *left, *right;
};
 
// Utility function creates a new binary tree node with
// given key
Node* newNode(int k)
{
    Node* temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Finds the path from root node to given root of the tree,
// Stores the path in a vector path[], returns true if path
// exists otherwise false
bool findPath(Node* root, vector<int>& path, int k)
{
    // base case
    if (root == NULL)
        return false;
 
    // Store this node in path vector. The node will be
    // removed if not in path from root to k
    path.push_back(root->key);
 
    // See if the k is same as root's key
    if (root->key == k)
        return true;
 
    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k))
        || (root->right && findPath(root->right, path, k)))
        return true;
 
    // If not present in subtree rooted with root, remove
    // root from path[] and return false
    path.pop_back();
    return false;
}
 
// Returns LCA if node n1, n2 are present in the given
// binary tree, otherwise return -1
int findLCA(Node* root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;
 
    // Find paths from root to n1 and root to n2. If either
    // n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1)
        || !findPath(root, path2, n2))
        return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}
 
// Driver program to test above functions
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
Output
LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(3, 4) = 1
LCA(2, 4) = 2
Time Complexity: O(N). The tree is traversed twice, and then path arrays are compared. 
Auxiliary Space: O(N). Extra Space for path1 and path2.

By Single Traversal:
The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). If the root doesn’t match with any of the keys, we recur for the left and right subtree. 

The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
If both keys lie in the left subtree, then the left subtree has LCA also, 
Otherwise, LCA lies in the right subtree.  

Illustration:













Root is pointing to the node with value 1, as its value doesn’t match with { 5, 6 }. We look for the key in left subtree and right subtree.

Left Subtree :
New Root = { 2 } ≠ 5 or 6, hence we will continue our recursion
New Root = { 4 } , it’s left and right subtree is null, we will return NULL for this call
New Root = { 5 } , value matches with 5 so will return the node with value 5
The function call for root with value 2 will return a value of 5
Right Subtree :
Root = { 3 } ≠ 5 or 6 hence we continue our recursion
Root = { 6 } = 5 or 6 , we will return the this node with value 6 
Root = { 7 } ≠ 5 or 6, we will return NULL
So the function call for root with value 3 will return node with value 6
As both the left subtree and right subtree of the node with value 1 is not NULL, so 1 is the LCA
Follow the steps below to solve the problem:

We pass the root to a helper function and check if the value of the root matches any of n1 and n2. 
If YES, return the root
else recursive call on the left and right subtree
Basically, we do pre-order traversal, at first we check if the root->value matches with n1 or n2. Then traverse on the left and right subtree.
If there is any root that returns one NULL and another NON-NULL value, we shall return the corresponding NON-NULL value for that node.
The node that returns both NON-NULL values for both the left and right subtree, is our Lowest Common Ancestor.

/* C++ Program to find LCA of n1 and n2 using one traversal
 * of Binary Tree */
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// This function returns pointer to LCA of two given values
// n1 and n2. This function assumes that n1 and n2 are
// present in Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one
    // key is present in once subtree and other is present
    // in other, So this node is the LCA
    if (left_lca && right_lca)
        return root;
 
    // Otherwise check if left subtree or right subtree is
    // LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
    return 0;
}
 
Output
LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(3, 4) = 1
LCA(2, 4) = 2
Time Complexity: O(N) as the method does a simple tree traversal in a bottom-up fashion. 
Auxiliary Space: O(H), where H is the height of the tree.

Note: The above method assumes that keys are present in Binary Tree. If one key is present and the other is absent, then it returns the present key as LCA (Ideally should have returned NULL). We can extend this method to handle all cases by checking if n1 and n2 are present in the tree first and then finding the LCA of n1 and n2. To check whether the node is present in the binary tree or not then traverse on the tree for both n1 and n2 nodes separately.

/* C++ program to find LCA of n1 and n2 using one traversal
   of Binary Tree. It handles all cases even when n1 or n2
   is not there in Binary Tree */
 
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// This function returns pointer to LCA of two given
// valuesn1 and n2.
struct Node* findLCAUtil(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root
    if (root->key == n1 || root->key == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node* left_lca = findLCAUtil(root->left, n1, n2);
    Node* right_lca = findLCAUtil(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL nodes,
    // then one key is present in once subtree and other is
    // present in other, So this node is the LCA
    if (left_lca and right_lca)
        return root;
 
    // Otherwise check if left subtree or right subtree is
    // LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}
 
// Returns true if key k is present in tree rooted with root
bool find(Node* root, int k)
{
    // Base Case
    if (root == NULL)
        return false;
 
    // If key is present at root, or in left subtree or
    // right subtree, return true;
    if (root->key == k || find(root->left, k)
        || find(root->right, k))
        return true;
 
    // Else return false
    return false;
}
 
// This function returns LCA of n1 and n2 only if both n1
// and n2 are present in tree, otherwise returns NULL;
Node* findLCA(Node* root, int n1, int n2)
{
    // Return LCA only if both n1 and n2 are present in tree
    if (find(root, n1) and find(root, n2))
        return findLCAUtil(root, n1, n2);
 
    // Else return NULL
    return NULL;
}
 
// Driver program to test above functions
int main()
{
    // Let us create a binary tree given in the above
    // example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    Node* lca = findLCA(root, 4, 5);
 
    if (lca != NULL)
        cout << "LCA(4, 5) = " << lca->key;
    else
        cout << "Keys are not present ";
 
    lca = findLCA(root, 4, 10);
 
    if (lca != NULL)
        cout << "\nLCA(4, 10) = " << lca->key;
    else
        cout << "\nKeys are not present ";
 
    return 0;
}

Output
LCA(4, 5) = 2
Keys are not present 
Time Complexity: O(N) as the method does a simple tree traversal in a bottom-up fashion. 
Auxiliary Space: O(H), where h is the height of the tree.

Find distance between 2 nodes in a Binary tree	
---------------------------------------------------
Find the distance between two keys in a binary tree, no parent pointers are given. The distance between two nodes is the minimum number of edges to be traversed to reach one node from another.















The distance between two nodes can be obtained in terms of lowest common ancestor. Following is the formula. 


Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) 
'n1' and 'n2' are the two given keys
'root' is root of given Binary Tree.
'lca' is lowest common ancestor of n1 and n2
Dist(n1, n2) is the distance between n1 and n2.
Following is the implementation of the above approach. The implementation is adopted from the last code provided in Lowest Common Ancestor Post. 

/* C++ program to find distance between n1 and n2 using one traversal */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Returns level of key k if it is present in tree,
// otherwise returns -1
int findLevel(Node *root, int k, int level)
{
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree
    // or right subtree, return true;
    if (root->key == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}
 
// This function returns pointer to LCA of two given
// values n1 and n2. It also sets d1, d2 and dist if
// one key is not ancestor of other
// d1 --> To store distance of n1 from root
// d2 --> To store distance of n2 from root
// lvl --> Level (or distance from root) of current node
// dist --> To store distance between n1 and n2
Node *findDistUtil(Node* root, int n1, int n2, int &d1,
                            int &d2, int &dist, int lvl)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1)
    {
         d1 = lvl;
         return root;
    }
    if (root->key == n2)
    {
         d2 = lvl;
         return root;
    }
 
    // Look for n1 and n2 in left and right subtrees
    Node *left_lca  = findDistUtil(root->left, n1, n2,
                                   d1, d2, dist, lvl+1);
    Node *right_lca = findDistUtil(root->right, n1, n2,
                                   d1, d2, dist, lvl+1);
 
    // If both of the above calls return Non-NULL, then
    // one key is present in once subtree and other is
    // present in other. So this node is the LCA
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2*lvl;
        return root;
    }
 
    // Otherwise check if left subtree or right subtree
    // is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 
// The main function that returns distance between n1
// and n2. This function returns -1 if either n1 or n2
// is not present in Binary Tree.
int findDistance(Node *root, int n1, int n2)
{
    // Initialize d1 (distance of n1 from root), d2
    // (distance of n2 from root) and dist(distance
    // between n1 and n2)
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2,
                                          dist, 1);
 
    // If both n1 and n2 were present in Binary
    // Tree, return dist
    if (d1 != -1 && d2 != -1)
        return dist;
 
    // If n1 is ancestor of n2, consider n1 as root
    // and find level of n2 in subtree rooted with n1
    if (d1 != -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
 
    // If n2 is ancestor of n1, consider n2 as root
    // and find level of n1 in subtree rooted with n2
    if (d2 != -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
 
    return -1;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the
    // above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
Output:  

Dist(4, 5) = 2
Dist(4, 6) = 4
Dist(3, 4) = 3
Dist(2, 4) = 1
Dist(8, 5) = 5
Time Complexity: Time complexity of the above solution is O(n) as the method does a single tree traversal.

Better Solution : 
We first find the LCA of two nodes. Then we find the distance from LCA to two nodes. 

/* C++ Program to find distance between n1 and n2
   using one traversal */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
Node* LCA(Node* root, int n1, int n2)
{
    // Your code here
    if (root == NULL)
        return root;
    if (root->key == n1 || root->key == n2)
        return root;
 
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}
 
// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(Node* root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->key == k)
        return level;
 
    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}
 
int findDistance(Node* root, int a, int b)
{
    // Your code here
    Node* lca = LCA(root, a, b);
 
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
 
    return d1 + d2;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in
    // the above example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
Output
Dist(4, 5) = 2
Dist(4, 6) = 4
Dist(3, 4) = 3
Dist(2, 4) = 1
Dist(8, 5) = 5

Another Better Solution (one pass):  

We know that distance between two node(let suppose n1 and n2) = distance between LCA and n1 + distance between LCA and n2.

A general solution using above formula that may come to your mind is  :  

int findDistance(Node* root, int n1, int n2) {

if (!root) return 0;

if (root->data == n1 || root->data == n2)

 return 1;

int left = findDistance(root->left, n1, n2);

int right = findDistance(root->right, n1, n2);

if (left  && right)

 return left + right;

else if (left || right)

 return max(left, right) + 1;

return 0;

}

But this solution has a flaw (a missing edge case)  when  n2 is Descendant of n1 or n1 is Descendant of n2.

Below is dry run of above code with edge case example :










In the above binary tree expected output is 2 but the function will give output as 3. This situation is overcome in the solution code given below :

Note : both n1 and n2 should be present in Binary Tree.
/* C++ Program to find distance between n1 and n2 using one traversal */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
//Global variable to store distance
//between n1 and n2.
int ans;
//Function that finds distance between two node.
int _findDistance(Node* root, int n1, int n2)
{
    if (!root) return 0;
    int left = _findDistance(root->left, n1, n2);
    int right = _findDistance(root->right, n1, n2);
      //if any node(n1 or n2) is found
    if (root->key == n1 || root->key == n2)
    {   
          //check if there is any descendant(n1 or n2)
          //if descendant exist then distance between descendant
          //and current root will be our answer.
        if (left || right)
        {
            ans = max(left, right);
            return 0;
        }
        else
            return 1;
    }
      //if current root is LCA of n1 and n2.
    else if (left && right)
    {   
        ans = left + right;
        return 0;
    }
      //if there is a descendant(n1 or n2).
    else if (left || right)
          //increment its distance
        return max(left, right) + 1;
    //if neither n1 nor n2 exist as descendant.
    return 0;
}
// The main function that returns distance between n1
// and n2.
int findDistance(Node* root, int n1, int n2)
{
    ans = 0;
    _findDistance(root, n1, n2);
    return ans;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in
    // the above example
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
Output
Dist(4, 5) = 2
Dist(4, 6) = 4
Dist(3, 4) = 3
Dist(2, 4) = 1
Dist(8, 5) = 5

Kth Ancestor of node in a Binary tree	
--------------------------------------
Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then print -1.
For example in the below given binary tree, the 2nd ancestor of 5 is 1. 3rd ancestor of node 5 will be -1. 

The idea of using DFS is to first find the given node in the tree and then backtrack k times to reach the kth ancestor. Once we have reached the kth parent, we will simply print the node and return NULL. 

/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;
 
// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)
{  
    // Base case
    if (!root)
        return NULL;
     
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--;
         
        else if (k == 0)
        {
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
             
            // return NULL to stop further backtracking
            return NULL;
        }
         
        // return current node to previous call
        return root;
    }
}
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    int k = 2;
    int node = 5;
 
    // print kth ancestor of given node
    Node* parent = kthAncestorDFS(root,node,k);
     
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";
     
    return 0;
}
Output
Kth ancestor is: 1
Time Complexity: O(n), where n is the number of nodes in the binary tree. 

Find all Duplicate subtrees in a Binary tree [ IMP ]	
---------------------------------------------------------
Given a binary tree, find all duplicate subtrees. For each duplicate subtree, we only need to return the root node of any one of them. Two trees are duplicates if they have the same structure with the same node values.

Examples: 

Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output : 
   2           
  /    and    4
 4
Explanation: Above Trees are two duplicate subtrees. 
Therefore, you need to return above trees root in the 
form of a list.

The idea is to use hashing. We store inorder traversals of subtrees in a hash. Since simple inorder traversal cannot uniquely identify a tree, we use symbols like ‘(‘ and ‘)’ to represent NULL nodes. 

We pass an Unordered Map in C++ as an argument to the helper function which recursively calculates inorder string and increases its count in map. If any string gets repeated, then it will imply duplication of the subtree rooted at that node so push that node in the Final result and return the vector of these nodes. 

// C++ program to find averages of all levels
// in a binary tree.
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node {
    int data;
    struct Node* left, *right;
};
 
string inorder(Node* node, unordered_map<string, int>& m)
{
    if (!node)
        return "";
 
    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";
 
    // Subtree already present (Note that we use
    // unordered_map instead of unordered_set
    // because we want to print multiple duplicates
    // only once, consider example of 4 in above
    // subtree, it should be printed only once.
    if (m[str] == 1)
        cout << node->data << " ";
 
    m[str]++;
 
    return str;
}
 
// Wrapper over inorder()
void printAllDups(Node* root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
 
/* Helper function that allocates a
new node with the given data and
NULL left and right pointers. */
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver code
int main()
{
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}
Output
4 2 
Time Complexity: O(N^2)  Since string copying takes O(n) extra time.
Auxiliary Space: O(N^2) Since we are hashing a string for each node and length of this string can be of the order N.

Tree Isomorphism Problem	
-----------------------------------
Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8. 














We simultaneously traverse both trees. Let the current internal nodes of two trees being traversed be n1 and n2 respectively. There are following two conditions for subtrees rooted with n1 and n2 to be isomorphic. 

Data of n1 and n2 is same. 
One of the following two is true for children of n1 and n2 
……a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2. 
……b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.
Implementation:
// A C++ program to check if two given trees are isomorphic
#include <iostream>
using namespace std;
 
/* A binary tree node has data, pointer to left and right children */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Given a binary tree, print its nodes in reverse level order */
bool isIsomorphic(node* n1, node *n2)
{
 // Both roots are NULL, trees isomorphic by definition
 if (n1 == NULL && n2 == NULL)
    return true;
 
 // Exactly one of the n1 and n2 is NULL, trees not isomorphic
 if (n1 == NULL || n2 == NULL)
    return false;
 
 if (n1->data != n2->data)
    return false;
 
 // There are two possible cases for n1 and n2 to be isomorphic
 // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
 // Both of these subtrees have to be isomorphic, hence the &&
 // Case 2: The subtrees rooted at these nodes have been "Flipped"
 return
 (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
 (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
 
/* Driver program to test above functions*/
int main()
{
    // Let us create trees shown in above diagram
    struct node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
 
    struct node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
 
    if (isIsomorphic(n1, n2) == true)
       cout << "Yes";
    else
      cout << "No";
 
    return 0;
}
Output
Yes
Time Complexity: The above solution does a traversal of both trees. So time complexity is O(min(m,n)*2) or O(min(m,n)) where m and n are number of nodes in given trees.
