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

	bool cycle_helper(int node, bool* visited, bool* Stack)
	{
		visited[node] = true;
		Stack[node] = true;

		for (auto nbr : l[node])
		{
			if (Stack[nbr] == true)
			{
				return true;
			}

			else if (visited[nbr] == false)
			{
				bool cycle_mila = cycle_helper(nbr, visited, Stack);
				if (cycle_mila == true)
				{
					return true;
				}
			}
		}



		Stack[node] = false;
		return   false;
	}

	bool is_cyclic()
	{
		bool* visited = new bool[10];
		bool* Stack = new bool[10];
		for (int i = 0; i < 10; i++)
		{
			visited[i] = Stack[i] = false;
		}

		return cycle_helper(0, visited, Stack);
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
	g.addedge(4, 5);
	g.addedge(5, 6);
	g.addedge(1, 5);
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
