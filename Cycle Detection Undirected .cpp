# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

class graph
{
	//int v;
public:
	//this->v=v;

	map<int, list<int>> l;
	void addedge(int x, int y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);
	}

	bool cycle_helper(int node, bool* visited, int parent)
	{
		visited[node] = true;
		//Stack[node] = true;
		for (auto nbr : l[node])
		{
			if (!visited[nbr])
			{
				bool cyclemila = cycle_helper(nbr, visited, node);
				if (cyclemila)
				{
					return true;
				}
			}
			else if (nbr != parent)
			{
				return true;
			}
		}

		return false;
	}

	bool is_cyclic()
	{
		bool* visited = new bool[10];
		//bool* Stack = new bool[10];
		for (int i = 0; i < 10; i++)
		{
			visited[i] = false;
		}

		return cycle_helper(0, visited, -1);
	}



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
	g.addedge(3, 4);
	//g.addedge(4, 0);
	//g.addedge(5, 6);
	//g.addedge(1, 5);
	//g.addedge(4, 2);//back edge



	if (g.is_cyclic ())
	{
		cout << " cycle";
	}
	else
	{
		cout << " not cycle";
	}

}
