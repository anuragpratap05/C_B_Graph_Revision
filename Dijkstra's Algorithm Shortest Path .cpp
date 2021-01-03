# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

class graph
{
	//int v;
public:
	//this->v=v;

	map<int, list<pair<int, int>>> l;
	void addedge(int x, int y, int wt)
	{
		l[x].push_back(make_pair(y, wt));
		l[y].push_back(make_pair(x, wt));
	}

	void dijkstra(int src)
	{
		set<pair<int, int>> s;
		map<int, int> dist;

		for (auto p : l)
		{
			dist[p.first] = INT_MAX;
		}

		dist[src] = 0;
		s.insert(make_pair(0, src));

		while (!s.empty())
		{
			auto p = *(s.begin());
			int node = p.second;
			int nodedist = p.first;
			s.erase(s.begin());
			for (auto nbr : l[node])
			{
				if (nodedist + nbr.second < dist[nbr.first])
				{
					int dest = nbr.first;

					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end())
					{
						s.erase(f);
					}
					dist[dest] = nodedist + nbr.second;
					s.insert(make_pair(dist[dest], dest));

				}
			}


		}
		for (auto d : dist)
		{
			cout << d.first << " is located at distance " << d.second << endl;
		}
	}



};

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	graph g;

	g.addedge(1, 2, 1);
	g.addedge(2, 3, 1);
	g.addedge(3, 4, 2);
	g.addedge(1, 3, 4);
	g.addedge(1, 4, 7);

	g.dijkstra(1);

	//g.addedge(4, 0);
	//g.addedge(5, 6);
	//g.addedge(1, 5);
	//g.addedge(4, 2);//back edge





}
