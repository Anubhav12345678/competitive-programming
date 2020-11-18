
/*

Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.

Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.

 

Example 1:

Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 


*/


#define pb push_back
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int i,j,k,l,n=orders.size();
        set<string> s;
        map<int,map<string,int>> mp;
        // it[1] table number
        // it[2] food item
        for(auto it:orders)
        {
            s.insert(it[2]);
            mp[stoi(it[1])][it[2]]++;
        }
        
        vector<vector<string>> res;
        vector<string> v;
        v.pb("Table");
        for(auto it: s)
            v.pb(it);
        res.pb(v);
        for(auto it: mp)
        {
            vector<string> tmp;
            tmp.pb(to_string(it.first));
            for(auto it2:s)
            {
                tmp.pb(to_string(it.second[it2]));
                    
            }
            res.pb(tmp);
        }
        return res;
    }
};