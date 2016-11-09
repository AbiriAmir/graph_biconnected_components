// AbiriAmir [amir@abiri.info]
// Biconnected Component Search
// 2016 Nov. 9
// Advanced Graph Theory - University of Tehran
#include <iostream>
#include <vector>
#include <stack>
#include <ios>

using namespace std;

const int MAXN = 1000 * 1000;

vector<int> G[MAXN];
vector< pair<int, int> > components[MAXN];
int mark[MAXN];
int parent[MAXN];
int dfs_number[MAXN];
int lowest[MAXN];
stack< pair<int, int> > st;

int component_count = 0;

int dfs_num = 0;

int findAllComponents(int n);
int dfs(int v);

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	cin >> m;

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	findAllComponents(n);

	cout << "Components: " << component_count << endl;
	for(int i = 0; i < component_count; ++i) {
		cout << "	#" << i+1 << ": ";
		for(int j = 0; j < components[i].size(); ++j) {
			cout << "[" << components[i][j].first << ", " << components[i][j].second << "]  ";
		}
		cout << endl;
	}
}

int findAllComponents(int n) {
	for(int i = 0; i < MAXN; ++i) {
		mark[i] = 0;
		parent[i] = i;
		// dfs_number[i] = -1;
		// lowest[i] = MAXN;
	}

	for(int i = 0; i < n; ++i)
		if(!mark[i]) {
			dfs(i);

			if(!st.empty()) {
				while(!st.empty()) {
					components[component_count].push_back( st.top() );
					st.pop();
				}

				component_count++;
			}
		}
}

int dfs(int v) {
	// cerr << "Called dfs on node " << v << endl;
	mark[v] = 1;
	dfs_number[v] = dfs_num++;
	lowest[v] = dfs_number[v];

	for(int i = 0; i < G[v].size(); ++i) {
		int &u = G[v][i];
		if(!mark[u]) {
			parent[u] = v;

			st.push(make_pair(v, u));

			dfs(u);

			lowest[v] = min(lowest[v], lowest[u]);

			if(lowest[u] >= dfs_number[v]) { // new component
				pair<int, int> tmp;
				do {
					tmp = st.top();
					components[component_count].push_back( st.top() );
					st.pop();
				} while(tmp.first != v || tmp.second != u);
				component_count++;
			}



		} else {
			if(u != parent[v]) {
				lowest[v] = min(lowest[v], dfs_number[u]);
				
				if(dfs_number[v] > dfs_number[u])
					st.push(make_pair(v, u));
			}
		}
	}

	// cerr << "lowest " << v << " : " << lowest[v] << endl; 
}