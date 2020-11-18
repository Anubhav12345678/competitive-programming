static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
#define mod 1000000007
class Solution 
{
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) 
    {
        //for an element there are 3 cases possible:
        //case 1 :element is greater than R. In this case,there will be no valid subarrays ending with this element
        //        because all the subarrays ending with this element will have a maximum value >=current element 
        //        hence will not be valid.
        //case 2: element is less than L. In this case element itself will not form a valid subarray but can append
        //        to all the valid subarrays ending with previous element.hence number of valid subarrays ending 
        //        with current element will be equal to the number of valid subarrays ending with previous element.
        //        this is possible because a valid subarray will have maximum value at least L and at most R and since
        //        current element's value is less than L,max value of the subarray will not be changed when this element
        //        is appended to the end.
        //case 3: element at least L and at most R.In this case element itself will form a valid subarray plus it will
        //        also form other valid subarrays as follows: we'll look for recent/latest element having value >R.all
        //        the elements between this element and current element(including current element) will form valid sub-
        //        -arrays ending with current element.
        
        int ans=0;
        int index=-1; //index of recent element having >R
        int prev=0;   //number of valid subarrays ending with previous element
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>R)  //case 1
            {
               prev=0;
               index=i; 
            }
            else if(A[i]<L) //case 2
            {
               ans+=prev;
               //prev=prev; 
            }
            else //if(A[i]>=L&&A[i]<=R) //case 3
            {
               ans+=i-index;
               prev=i-index; 
            }
        }
        return ans;
    }
};