class BrowserHistory {
public:
    int n,m;
    string a[5005];
    BrowserHistory(string homepage) {
        n=0,m=0;
        a[0]=homepage;
    }
    
    void visit(string url) {
        a[n=m=m+1] = url;//n=m as it  It clears up all the forward history.
    }
    
    string back(int steps) {
        steps = min(steps,m);
        m-=steps;
        return a[m];
    }
    
    string forward(int steps) {
        steps = min(steps,n-m);
        m+=steps;
        return a[m];
    }
};
/*

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history
 number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x,
 you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x,
 you will forward only x steps. Return the current url after forwarding in history at most steps.





*/
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */