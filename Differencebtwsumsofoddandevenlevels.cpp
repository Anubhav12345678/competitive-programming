/ return difference of 
// sums of odd level  
// and even level 
int evenOddLevelDifference(Node* root) 
{ 
    if (!root) 
        return 0; 
  
    // create a queue for 
    // level order traversal 
    queue<Node*> q; 
    q.push(root); 
  
    int level = 0; 
    int evenSum = 0, oddSum = 0; 
  
    // traverse until the 
    // queue is empty 
    while (!q.empty())  
    { 
        int size = q.size(); 
        level += 1; 
  
        // traverse for  
        // complete level 
        while(size > 0) 
        { 
            Node* temp = q.front(); 
            q.pop(); 
  
            // check if level no. 
            // is even or odd and 
            // accordingly update 
            // the evenSum or oddSum 
            if(level % 2 == 0) 
                evenSum += temp->data; 
            else
                oddSum += temp->data; 
          
            // check for left child 
            if (temp->left)  
            { 
                q.push(temp->left); 
            } 
              
            // check for right child 
            if (temp->right) 
            { 
                q.push(temp->right); 
            } 
            size -= 1; 
        }  
    } 
      
    return (oddSum - evenSum); 
} 