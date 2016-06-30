#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

void Reach(map<int, set<int>> & my_map, vector<int> & g)
{
	int gid = 0;
	for (size_t i = 0; i < g.size(); ++i)
	{
		if (g[i] == 0)
		{
			++gid; 
			queue<int> reached_nodes;
			reached_nodes.push(i + 1); 
			g[i] = gid; 
			while (!reached_nodes.empty())
			{
				int node = reached_nodes.front();
				reached_nodes.pop();
				for (auto n : my_map.find(node)->second)
					if (g[n - 1] == 0)
					{
						reached_nodes.push(n);
						g[n - 1] = gid; 
					}
			}
		}
	}
}


int main()
{
	int n, e; 
	while (cin >> n >> e)
	{
		map<int, set<int>> my_map; 
		for (int i = 0; i < n; ++i)
			my_map.insert(pair<int, set<int>>(i + 1, set<int>())); 

		for (int i = 0; i < e; ++i)
		{
			int n1, n2; 
			cin >> n1 >> n2;

			my_map.find(n1)->second.insert(n2); 
			my_map.find(n2)->second.insert(n1); 
		}

		vector<int> g(n, 0);
		Reach(my_map, g);

		int max_group_id = 0;
		for (auto it : g)
			if (it > max_group_id)
				max_group_id = it;

		cout << max_group_id << endl;


	}
	return 0;
}