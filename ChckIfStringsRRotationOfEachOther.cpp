bool areRotations(string s1,string s2)
{
    if(s1.size()!=s2.size())
    return false;
    string s = s1+s1;
    return (s.find(s2)!=-1);
    // Your code here
}