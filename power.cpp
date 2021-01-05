# C_B_Graph_Revision#include<bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	int xnm1 = power(x, n - 1);
	int xn = x * xnm1;
	return xn;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	int x, n;
	cin >> x >> n;
	cout << power(x, n);
}
