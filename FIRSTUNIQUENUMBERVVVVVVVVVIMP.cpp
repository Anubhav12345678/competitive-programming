/*

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.


*/



class FirstUnique {
public:
    queue<int> q;
    map<int,int> mp;
    FirstUnique(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        for(i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(i=0;i<n;i++)
        {
            if(mp[nums[i]]==1)
                q.push(nums[i]);
        }
    }
    
    int showFirstUnique() {
        
        if(q.empty())
            return -1;
        while(q.size()>0&&mp[q.front()]>1)
            q.pop();
        if(q.empty())
            return -1;
        return q.front();
    }
    
    void add(int value) {
        if(mp.find(value)==mp.end())
        {
            mp[value]++;
            q.push(value);
            return;
        }
        else
        {
            // while(q.size()>0&&mp)
            mp[value]++;
        }
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */