#include <iostream>
#include <vector>
#include <set>

using namespace std;

int path_length[100][100];

int min_tree_length(int node_count)
{
	int min_length_sum = 0;

	set<int> reached_nodes;

	reached_nodes.insert(0);

	while (true)
	{
		int next_node = -1;
		int min_add_length = INT32_MAX;

		for (int node = 0; node < node_count; ++node)
		{
			if (reached_nodes.find(node) != reached_nodes.end())
				continue;
			for (auto it : reached_nodes)
			{
				if (path_length[it][node] != -1 && path_length[it][node] < min_add_length)
				{
					min_add_length = path_length[it][node];
					next_node = node;
				}
			}
		}
		if (next_node == -1)
			break;
		reached_nodes.insert(next_node);
		min_length_sum += min_add_length;
	}

	return min_length_sum;
}

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n * (n - 1) / 2; ++i)
		{
			int node1, node2, value;
			cin >> node1 >> node2 >> value;
			path_length[node1 - 1][node2 - 1] = path_length[node2 - 1][node1 - 1] = value;
		}
		cout << min_tree_length(n) << endl;
	}
	return 0;
}