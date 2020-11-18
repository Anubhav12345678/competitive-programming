int Solution::solve(int A, vector<int> &B) { 
	vector<int>cnt(A,0);
	 int s=0;
	  for(int i=0 ; i<A ; i++)
	  	{ s+=B[i]; }
	  	 if(s%3 != 0){ return 0; } 
	  	 int ss=0;
	  	  s=s/3;
	  	   for(int i=A-1 ; i>=0 ; i--)
	  	   	{ ss+=B[i]; if(ss == s){ cnt[i]=1; } } 
	  	   for(int i=A-2 ; i>=0 ; i--){ cnt[i]+=cnt[i+1]; }
	  	    int ans=0; ss=0;
	  	     for(int i=0 ; i+2<A ; i++){ ss+=B[i]; if(ss == s){ ans+=cnt[i+2]; } } return ans; }
	  	     	/*


You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3
 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])

	  	     	*/