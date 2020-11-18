const int LEN = 8;

vector<int> next_state(vector<int> cells) {
    vector<int> state(LEN, 0);

    for (int i = 1; i + 1 < LEN; i++)
        if (cells[i - 1] == cells[i + 1])
            state[i] = 1;

    return state;
}

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> states;
        map<vector<int>, int> seen;
        states.push_back(cells);
        seen[cells] = 0;

        for (int i = 1; i <= N; i++) {
            cells = next_state(cells);

            if (seen.find(cells) != seen.end()) {
                int index = seen[cells];
                return states[index + (N - index) % (i - index)];
            }

            seen[cells] = i;
            states.push_back(cells);
        }

        return cells;
    }
};


//me
class Solution {
public:
    vector<int> ch(vector<int> &v)
    {
        int i,j,k,l,n=v.size();
        vector<int> st(8,0);
        for(i=1;i+1<n;i++)
            if(v[i-1]==v[i+1])
                st[i]=1;
        return st;
    }
    int len=8;
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int i,j,k,l;
        vector<vector<int>> st;
        st.push_back(cells);
        map<vector<int>,int> mp;
        mp[cells]=0;
        for(i=1;i<=N;i++)
        {
            cells= ch(cells);
            cout<<"i="<<i<<endl;
            for(j=0;j<8;j++)
                cout<<cells[j]<<" ";
            cout<<endl;
            if(mp.find(cells)!=mp.end())
            {
                int ind=mp[cells];
                cout<<"i="<<i<<" ind="<<ind<<endl;
                return st[ind+(N-ind)%(i-ind)];
            }
            mp[cells]=i;
            st.push_back(cells);
        }
        cout<<i<<endl;
        cout<<"ok\n";
        return cells;
        
    }
};  