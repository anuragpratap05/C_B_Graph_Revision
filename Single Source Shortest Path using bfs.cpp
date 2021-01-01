# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

class graph
{
	map<int, list<int>> l;
public:
	void addedge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(int src)
	{
		queue<int >q;
		map<int, int> dist;

		for (auto p : l)
		{
			int node = p.first;
			dist[node] = INT_MAX;
		}

		q.push(src);
		//visited[src] = true;
		dist[src] = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			//cout << node << " ";
			for (auto nbr : l[node])
			{
				if (dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}
			}
		}

		for (auto x : dist)
		{
			cout << x.first << " " << x.second << endl;
		}
	}


	/*void print()
	{
		for (auto p : l)
		{
			auto city = p.first;
			cout << city << "-> ";
			auto nbrs = p.second;
			for (auto nbr : nbrs)
			{
				cout << nbr.first << " " << nbr.second << ",";
			}
			cout << endl;
		}
	}*/
};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g;

	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(2, 3);
	g.addedge(3, 0);
	g.addedge(3, 4);
	g.addedge(4, 5);
	//g.print();
	g.bfs(0);
}
