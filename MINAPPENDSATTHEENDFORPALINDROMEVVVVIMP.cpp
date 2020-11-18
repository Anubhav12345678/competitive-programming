int Solution::solve(string A) {
    int i,j,k,l,n=A.size();
    k=0;
  i=0;
  j=n-1;
  while(i<=j){
      if(A[i]!=A[j]){
          i++;
          j=n-1;
      }
      else{
          if(j==(n-1))
          k=i;
          i++;
          j--;
      }
  }
  return k;
}
/*
Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.
*/