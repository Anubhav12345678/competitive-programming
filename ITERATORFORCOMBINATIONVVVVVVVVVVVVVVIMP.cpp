/*
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number 
combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


*/

class CombinationIterator {
public:
    string s;
    queue<string> q;
    void solve(int st,int l,string txt){
        if(l==0){
            q.push(txt);
            return;
        }
        for(int i=st;i<=(s.size()-l);i++){
            solve(i+1,l-1,txt+s[i]);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        string txt="";
        s= characters;
        solve(0,combinationLength,txt);
    }
    
    string next() {
        string st = q.front();
        q.pop();
        return st;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */