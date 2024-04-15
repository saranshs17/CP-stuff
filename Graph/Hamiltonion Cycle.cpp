#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n;
bool hascycle;
bool isSafe(int node, vector<vector<int>> g, vector<int> path, int pos)
{
	if (g[path[pos - 1]][node] == 0)
	{
		return false;
	}
	for (int i = 0; i < pos; ++i)
	{
		if (path[i] == node)
			return false;
	}
	return true;
}
void findcycle(vector<vector<int>> g, int pos, vector<int> path, int vis[], int n)
{
	if (pos == n)
	{
		if (g[path[path.size() - 1]][path[0]] ==1)
		{
			path.push_back(0);
			for (int i = 0; i < path.size(); ++i)
			{
				cout << path[i] << " ";
			}
			cout << '\n';
			path.pop_back();
			hascycle = true;
		}
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (isSafe(i, g, path, pos) && !vis[i])
		{
			path.push_back(i);
			vis[i] = 1;
			findcycle(g, pos + 1, path, vis, n);
			vis[i] = 0;
			path.pop_back();
		}
	}
}
int main()
{
	cin >> n;
	vector<vector<int>> g = {
		{0, 1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 1},
		{1, 1, 0, 0, 1, 0},
	};
	hascycle = false;
	vector<int> path;
	path.push_back(0);
	int vis[n];
	for (int i = 0; i < n; ++i)
	{
		vis[i] = 0;
	}
	vis[0] = 1;
	findcycle(g, 1, path, vis, n);
	if (!hascycle)
	{
		cout << "No hamiltonion cycle\n";
	}
}
