# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

class graph
{
	int v;
	vector<pair<int, int>> *l;
public:
	graph(int v)
	{
		this->v = v;
		l = new vector<pair<int, int>>[v];
	}

	void addedge(int x, int y, int wt)
	{

		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}

	int prim_mst()
	{
		priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>>Q;
		bool *visited = new bool[v];
		int ans = 0;
		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
		}

		Q.push(make_pair(0, 0));
		//visited[0] = true;
		while (!Q.empty())
		{
			auto best = Q.top();
			Q.pop();
			int to = best.second;
			int wt = best.first;
			if (visited[to])
			{
				continue;
			}
			ans += wt;
			visited[to] = true;
			for (auto x : l[to])
			{
				if (!visited[x.first])
				{
					Q.push(make_pair(x.second, x.first));
				}
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
	g.addedge(3, 2, 3);
	g.addedge(2, 0, 2);
	g.addedge(0, 3, 2);
	g.addedge(1, 2, 2);

	cout << g.prim_mst ();
}
