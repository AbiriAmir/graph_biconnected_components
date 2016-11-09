#include <iostream>
#include <set>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;

int main() {
	int n, m;
	set< pair<int, int> > edges;
	srand (time(NULL));

	cin >> n >> m;

	cout << n << endl << m << endl;


	while(edges.size() < m) {
		pair<int, int> tmp;
		tmp.first = rand() % n;
		tmp.second = rand() % n;

		if(tmp.first == tmp.second ||
			edges.find(make_pair(tmp.second, tmp.first)) != edges.end())
			continue;

		edges.insert(tmp);
	}

	for(set< pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}