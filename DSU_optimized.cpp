#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	list<pair<int, int>> l;
public:
	graph(int v)
	{
		this->v = v;

	}

	void addedge(int x, int y)
	{
		l.push_back(make_pair(x, y));
	}

	int findset(int i, int parent[])
	{
		if (parent[i] == -1)
		{
			return i;
		}
		return parent[i] = findset(parent[i], parent);
	}

	void unite(int x, int y, int parent[], int* rank)
	{
		int s1 = findset(x, parent);
		int s2 = findset(y, parent);
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

	bool is_cyclic()
	{
		int *parent = new int[v];
		int* rank = new int[v];


		for (int i = 0; i < v; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : l)
		{
			int i = edge.first;
			int j = edge.second;

			int s1 = findset(i, parent);
			int s2 = findset(j, parent);
			if (s1 != s2)
			{
				unite(i, j, parent, rank);
			}
			else
			{
				cout << "same parent" << s1 << " " << s2;
				return true;
			}
		}

		return false;

	}
};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g(4);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(2, 3);
	g.addedge(3, 0);

	if (g.is_cyclic())
	{
		cout << " cycle";
	}
	else
	{
		cout << " not cycle ";
	}
}
