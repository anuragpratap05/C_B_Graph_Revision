# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

class dsu
{
	int * parent;
	int* rank;
public:
	dsu(int n)
	{
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if (parent[i] == -1)
		{
			return i;
		}

		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2)
		{
			if (rank[s1] < rank[s2])
			{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else
			{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};




class graph
{
	int v;
	vector<vector<int>> l;
public:
	graph(int v)
	{
		this->v = v;
	}

	void addedge(int x, int y, int wt)
	{
		l.push_back({wt, x, y});
	}

	int kruksal()
	{
		dsu h(v);
		sort(l.begin(), l.end());
		int ans = 0;
		for (auto edge : l)
		{
			int wt = edge[0];
			int i = edge[1];
			int j = edge[2];
			if (h.find(i) != h.find(j))
			{
				h.unite(i, j);
				ans += wt;
			}
		}
		return ans;

	}


};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g(4);
	g.addedge(0, 1, 1);
	g.addedge(1, 3, 3);
	g.addedge(3, 2, 4);
	g.addedge(2, 0, 2);
	g.addedge(0, 3, 2);
	g.addedge(1, 2, 2);

	cout << g.kruksal();
}
