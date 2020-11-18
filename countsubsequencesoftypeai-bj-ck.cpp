#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string a;
	    cin >> a;
	    int n = a.size();
	    int ac=0, bc=0, cc=0;
	    for (int i=0; i < n; i++) {
	        char ch = a[i];
	        if (ch == 'a') ac = 1 + 2*ac;
	        else if (ch == 'b') bc = ac + 2*bc;
	        else if (ch == 'c') cc = bc + 2*cc;
	    }
	    cout << cc << "\n";
	}
	return 0;
}