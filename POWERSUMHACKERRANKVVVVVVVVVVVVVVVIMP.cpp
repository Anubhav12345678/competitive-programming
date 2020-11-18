int powerSum(int X, int N,int num=1) {
    if(pow(num,N)<X)
      return powerSum(X,N,num+1)+
powerSum(X-pow(num,N),N,num+1);
    else if(pow(num,N)==X) return 1;
    return 0;
}
/*

Find the number of ways that a given integer, X , can be expressed as the sum of the Nth powers of unique, natural numbers.

For example, if X=13 and N=2, we have to find all combinations of unique squares adding up to 13. The only solution is 2^2+3^2.


*/