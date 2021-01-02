# C_B_Graph_Revision
#include<bits/stdc++.h>
using namespace std;

class graph
{
	map<string, list<string>> l;
public:
	void addedge(string x, string y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);
	}

	/*void bfs(int src)
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
	}*/


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

	void dfs_helper(string src, map<string, bool> &visited, list<string> &lst)
	{
		//cout << src << " ";
		visited[src] = true;
		for (auto nbr : l[src])
		{
			if (!visited[nbr])
			{
				dfs_helper(nbr, visited, lst);
			}
		}

		lst.push_front(src);
		return;
	}

	void dfs()
	{

		map<string, bool> visited;
		list<string> lst;
		for (auto p : l)
		{
			visited[p.first] = false;
		}
		//int cnt = 0;

		for (auto p : l)
		{
			auto node = p.first;
			if (!visited[node])
			{
				//cout << "componenet " << cnt << "-->";
				dfs_helper(node, visited, lst);
				//cnt++;
			}
		}
		for (auto x : lst)
		{
			cout << x << " ";
		}

		return;

	}
};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g;

	g.addedge("python", "data preprocessing");
	g.addedge("python", "pytorch");
	g.addedge("python", "ML");
	g.addedge("data preprocessing", "ML");
	g.addedge("pytorch", "DL");
	g.addedge("ML", "DL");
	g.addedge("DL", "face recognition");
	g.addedge("data set", "face recognition");
	//g.print();
	g.dfs();
}
