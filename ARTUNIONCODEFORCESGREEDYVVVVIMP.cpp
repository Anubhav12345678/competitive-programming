#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int m; cin >> m;
	int n; cin >> n;
	
	int paintingTime[m][n];
	for (int i = 0 ; i < m ; i++) {
		for (int j = 0 ; j < n ; j++) cin >> paintingTime[i][j];
	}
	
	vector<int> finishTime(m);
 
	for (int i = 0 ; i < n ; i++) {
		int freeAt = 0;
		for (int j = 0 ; j < m ; j++) {
			int start = max(freeAt, finishTime[j]);
			finishTime[j] = start + paintingTime[j][i];
			freeAt = finishTime[j];
		}
	}
	
	for (auto x : finishTime) cout << x << ' ';
}
/*
A well-known art union called "Kalevich is Alive!" manufactures objects d'art (pictures). The union consists of n painters who 
decided to organize their work as follows.

Each painter uses only the color that was assigned to him. The colors are distinct for all painters. Let's assume that the first 

painter uses color 1, the second one uses color 2, and so on. Each picture will contain all these n colors. Adding the j-th color 
to the i-th picture takes the j-th painter t ij units of time.

Order is important everywhere, so the painters' work is ordered by the following rules:

Each picture is first painted by the first painter, then by the second one, and so on. That is, after the j-th painter finishes 
working on the picture, it must go to the (j + 1)-th painter (if j < n);
each painter works on the pictures in some order: first, he paints the first picture, then he paints the second picture and so on;
each painter can simultaneously work on at most one picture. However, the painters don't need any time to have a rest;
as soon as the j-th painter finishes his part of working on the picture, the picture immediately becomes available to the next painter.
Given that the painters start working at time 0, find for each picture the time when it is ready for sale.

*/