// AbiriAmir [amir@abiri.info]
// Biconnected Component Search - Iterative Version
// 2016 Nov. 9
// Advanced Graph Theory - University of Tehran
#include <iostream>
#include <vector>
#include <stack>
#include <ios>

using namespace std;

const int MAXN = 1000 * 1000;


typedef pair<int, int> Edge;

class Node {
public:
	int lowest;
	int parent;
	int dfs_number;
	bool cut_vetex;
	int mark;
	vector<int> Edges;
};

vector< Node > G;
vector< pair<int, int> > components[MAXN];
vector<int> counter;

int cut_vetices = 0;
stack< pair<int, int> > st;

stack<int> dfs_stack;

int component_count = 0;

int dfs_num = 0;

int findAllComponents(int n);
int dfs();

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	cin >> m;

	G.resize(n);
	counter.resize(n, 0);

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		G[u].Edges.push_back(v);
		G[v].Edges.push_back(u);
	}

	findAllComponents(n);

	cout << "Cut vertices: " << cut_vetices << endl;
	cout << "Components: " << component_count << endl;
	for(int i = 0; i < component_count; ++i) {
		cout << "	#" << i+1 << ": ";
		for(int j = 0; j < components[i].size(); ++j) {
			cout << "[" << components[i][j].first << ", " << components[i][j].second << "]  ";
		}
		cout << endl;
	}

	cout << "Cut vertices: " << endl;
	for(int i = 0; i < n; ++i) {
		if(G[i].cut_vetex)
			cout << i+1 << " ";
	}
	cout << endl;
}

int findAllComponents(int n) {
	for(int i = 0; i < n; ++i) {
		G[i].mark = 0;
		G[i].parent = i;
		// dfs_number[i] = -1;
		// lowest[i] = MAXN;
	}

	for(int i = 0; i < n; ++i)
		if(!G[i].mark) {
			// dfs(i);
			dfs_stack.push(i);
			dfs();

			if(!st.empty()) {
				while(!st.empty()) {
					components[component_count].push_back( st.top() );
					st.pop();
				}

				component_count++;
			}
		}
}

int dfs() {
	int v;

	while(!dfs_stack.empty()) {	// Preorder
		v = dfs_stack.top();

		if(!G[v].mark) {
			G[v].mark = 1;
			G[v].dfs_number = dfs_num++;
			G[v].lowest = G[v].dfs_number;
		}

		bool flag = false;
		int& i = counter[v];

		int j = 0;

		for(i, j = 0; i < G[v].Edges.size(); ++i, ++j) {
			int &u = G[v].Edges[i];

			if(!G[u].mark) {
				G[u].parent = v;

				st.push(make_pair(v, u));
				dfs_stack.push(u);
				flag = true;
				break;
			}



			if(G[u].mark == 2) {
				G[v].lowest = min(G[v].lowest, G[u].lowest);

				if(j == 0)
					if(G[u].lowest >= G[v].dfs_number) { // new component
						if(!G[v].cut_vetex) {
							G[v].cut_vetex = 1;
							cut_vetices++;	
						}
						
						pair<int, int> tmp;
						do {
							tmp = st.top();
							components[component_count].push_back( st.top() );
							st.pop();
						} while(tmp.first != v || tmp.second != u);
						component_count++;
					}



			} else if(G[u].mark == 1) {
				if(u != G[v].parent) {
					G[v].lowest = min(G[v].lowest, G[u].dfs_number);
					
					if(G[v].dfs_number > G[u].dfs_number) {
						st.push(make_pair(v, u));
					}
				}
			}




		}
		if(flag)
			continue;

		G[v].mark = 2;
		dfs_stack.pop();
	}

}