//TC-- O(N^2)
 bool isBalanced(Node *root)
    {
      if(root==NULL) return true;
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);

        bool diff= abs(height(root-> left)- height(root->right))<=1;

        if(left && right && diff) return 1;
        else 
          return false;
     
    }


//Optimal solution
pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
  
