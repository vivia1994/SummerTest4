#include <iostream>
#include <vector>
#include <set>

using namespace std;

int path_length[50][50];

vector<int> dijkstra(int start_node, int node_count)
{
	vector<int> min_length_to_start_node;

	for (int i = 0; i < node_count; ++i)
		min_length_to_start_node.push_back(INT32_MAX);

	min_length_to_start_node[start_node] = 0;

	set<int> reached_nodes;

	reached_nodes.insert(start_node);

	while (true)
	{
		int min_lengh = INT32_MAX;
		int next_node = -1;
		for (int node = 0; node < node_count; ++node)
		{
			if (reached_nodes.find(node) != reached_nodes.end())
				continue;
			for (auto it : reached_nodes)
			{
				if (path_length[it][node] != -1 && min_length_to_start_node[it] + path_length[it][node] < min_lengh)
				{
					min_lengh = min_length_to_start_node[it] + path_length[it][node];
					next_node = node;
				}
			}
		}
		if (next_node == -1)
			break;
		reached_nodes.insert(next_node);
		min_length_to_start_node[next_node] = min_lengh;
	}

	return min_length_to_start_node;
}

int main()
{
	int n;
	int count = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				path_length[i][j] = -1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				int input;
				cin >> input;
				if (input != -1)
					path_length[i][j] = path_length[j][i] = input;
			}
		int start, end;
		cin >> start >> end;
		vector<int> result = dijkstra(start - 1, n);
		cout << "Case " << ++count << endl;
		cout << result[end - 1] << endl;
	}
	return 0;
}