class Solution {    
public:
    /*
Given a list of airline tickets represented by pairs of departure and arrival
 airports [from, to], reconstruct the itinerary in order. All of the tickets 
 belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has 
the smallest lexical order when read as a single string. For example, the itinerary
 ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.






    */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        int n=tickets.size();
        //Make graph
        for(int i=0;i<n;++i)
            adj[tickets[i][0]].insert(tickets[i][1]);
        
        stack<string> mystack;
        mystack.push("JFK");    //JFK is our fixed starting point
        while(!mystack.empty())
        {
            string src = mystack.top();
            if(adj[src].size()==0)  //No further travel possible
            {
               ans.push_back(src);
               mystack.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();