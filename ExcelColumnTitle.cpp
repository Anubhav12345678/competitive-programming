string Solution::convertToTitle(int A) {
    int i,j,k,l;
    if(A<=26)
    {
        char u = (char)(64+A);
    }
    string res="";
    while(A>0)
    {
        if(A<=26){
            char u=(char)(64+A);
            res.push_back(u);
            break;
        }
        int p = A%26;
        if(p!=0)
        {
            char u=(char)(64+p);
            res.push_back(u);
        }
        else
        {
            res+='Z';
            A = (A/26)-1;
            continue;
        }
        A/=26;
    }
    reverse(res.begin(),res.end());
    return res;
}
