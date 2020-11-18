#include<bits/stdc++.h>
using namespace std;

bool checkIndex(int x, int y, int n, int m)
{
	if((x < 0)||(x >= n))
	return false;

	if((y < 0)||(y >= m))
	return false;

	return true;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int a, b;
		cin>>a>>b;

		char arr[a][b];
		int count[a][b];

		queue<int>antX;
		queue<int>antY;
		queue<char>direct;

		for(int i = 0 ; i < a ; i++)
		{
			for(int j = 0 ; j < b ; j++)
			{
				cin>>arr[i][j];

				if(arr[i][j] == '#')
				count[i][j] = 0;

				else if(arr[i][j] == '-')
				count[i][j] = 0;

				else
				{
					count[i][j] = 1;
					antX.push(i);
					antY.push(j);
					direct.push(arr[i][j]);
				}
			}
		}

		antX.push(-1);
		antY.push(-1);
		direct.push('\0');

		int antCounter = 0;

		while(true)
		{
			while(antX.size())
			{
				int x = antX.front();
				int y = antY.front();
				int d = direct.front();

				antX.pop();
				antY.pop();
				direct.pop();

				count[x][y]--;

				if((x == -1)&&(y == -1))
				{
					if(antX.size() != 0)
					{
						antX.push(-1);
						antY.push(-1);
						direct.push('\0');
					}

					break;
				}

				if(d == 'U')
				{
					x--;

					if((checkIndex(x, y, a, b))&&(arr[x][y] != '#'))
					{
						count[x][y]++;
						antX.push(x);
						antY.push(y);
						direct.push(d);
					}
				}

				else if(d == 'R')
				{
					y++;

					if((checkIndex(x, y, a, b))&&(arr[x][y] != '#'))
					{
						count[x][y]++;
						antX.push(x);
						antY.push(y);
						direct.push(d);
					}
				}

				else if(d == 'L')
				{
					y--;

					if((checkIndex(x, y, a, b))&&(arr[x][y] != '#'))
					{
						count[x][y]++;
						antX.push(x);
						antY.push(y);
						direct.push(d);
					}
				}

				else if(d == 'D')
				{
					x++;

					if((checkIndex(x, y, a, b))&&(arr[x][y] != '#'))
					{
						count[x][y]++;
						antX.push(x);
						antY.push(y);
						direct.push(d);
					}
				}
			}

			for(int i = 0 ; i < a ; i++)
			{
				for(int j = 0 ; j < b ; j++)
				{
					antCounter += ((count[i][j])*(count[i][j] - 1)/ 2);
				}
			}

			if(antX.size() == 0)
			break;
		}

		cout<<antCounter<<endl;
	}
}