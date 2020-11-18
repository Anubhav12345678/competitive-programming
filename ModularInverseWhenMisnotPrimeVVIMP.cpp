int modInverse(int a, int m)
{
    int i,j,k,num=-1;
    for(i=1;i<=m;i++)
    if((i*a)%m==1)
    {
        num=i;
        break;
    }
    return num;
    //Your code here
}