class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& boxes) {
        int i,j,k,l,n=status.size();
        bool ch=1;
        int res=0;
        while(!boxes.empty()&&ch)
        {
            ch=0;
            vector<int> nb;
            for(auto x:boxes)
            {
                if(status[x])
                {
                    ch=1;
                    res+=candies[x];
                    nb.insert(nb.end(),containedBoxes[x].begin(),containedBoxes[x].end());
                    for(auto y:keys[x]) status[y]=1;
                }
                else
                    nb.push_back(x);
            }
            swap(boxes,nb);
        }
        return res;
    }
};
/*
Given n boxes, each box is given in the format [status, candies, keys, containedBoxes] where:

status[i]: an integer which is 1 if box[i] is open and 0 if box[i] is closed.
candies[i]: an integer representing the number of candies in box[i].
keys[i]: an array contains the indices of the boxes you can open with the key in box[i].
containedBoxes[i]: an array contains the indices of the boxes found in box[i].
You will start with some boxes given in initialBoxes array. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.

 

Example 1:

Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
Output: 16
Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2. Box 1 is closed and you don't have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
Total number of candies collected = 7 + 4 + 5 = 16 candy.


*/