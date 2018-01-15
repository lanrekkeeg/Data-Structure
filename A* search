/*
Author:Faisal khan
implementation of A*
Cordinate Value are used fo heuristic approach.

*/
/*
How to give input:
->give number of vertices/node n and edges m
->each n line contain cordinates of each vertic/node
->each m line contain two vertices and their path cost
->now give t input for test cases
->each t line contain two vertice for shortest path finding

output of the test file is:
1328188

*/

#include<fstream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <cmath>
#include<functional>
#include<iostream>
using namespace std;


using Adj = vector<vector<int> >;
using Long = long long;
using Queue = priority_queue< pair<Long, int>, vector<pair<Long, int> >, greater <pair<Long, int> > >;

const Long big = INT64_MAX;

class AStar {

	int n_;
	Adj adj_;
	Adj cost_;
	vector<Long> distance_;
	vector<bool> visited_;
	// Coordinates of the nodes
	vector<pair<Long, Long> > xy_;

public:
	AStar(int n, Adj adj, Adj cost, vector<pair<Long, Long> > xy)
		: n_(n), adj_(adj), cost_(cost), distance_(vector<Long>(n_, big)), visited_(n), xy_(xy)
	{}
	void clear() {
		for (int i = 0; i < n_; ++i) {

			distance_[i] = big;
			visited_[i] = false;
		}

	}
	void check_visited(int v) {
		if (!visited_[v])
			visited_[v] = true;
	}
	// Relaxation function
	void visit(Queue& q, int v, Long dist, Long heuristic) {
		if (distance_[v] > dist) {
			distance_[v] = dist;
			q.push({ dist + heuristic,v });
		}
	}
	//calculate the euclidean distance
	Long euclidean(int v_1, int v_2) {
		pair<Long, Long> t_1 = xy_[v_1];
		pair<Long, Long> t_2 = xy_[v_2];

		return sqrt((t_1.first - t_2.first)*(t_1.first - t_2.first) + (t_1.second - t_2.second)*(t_1.second - t_2.second));
	}
	// Returns the distance from s to t in the graph
	Long query(int s, int t) {
		clear();
		Queue q;
		visit(q, s, 0, euclidean(s, t));

		while (!q.empty()) {
			pair<long, int> node = q.top();
			int vert = node.second;
			q.pop(); // clear the element

			if (vert == t) {
				return distance_[t];
				break;
			}
			auto path_cost = cost_[vert].begin();
			if (visited_[vert] == false) {
				for (auto it = adj_[vert].begin(); it != adj_[vert].end(); it++) {
					if (visited_[*it] == false) {
						Long cal_distance = distance_[vert] + *path_cost;
						Long heuristic = euclidean(*it, t);
						visit(q, *it, cal_distance, heuristic);

					}
					path_cost++;
				}
			}
			check_visited(vert);
		}
		return -1;
	}
};

int main() {
	
	int n, m;
	ifstream in("Test.txt");
	in >> n >> m;
	vector<pair<Long, Long> > xy(n);
	for (int i = 0; i<n; ++i) {
		int a, b;
		in >> a >> b;
		xy[i] = make_pair(a, b);
	}
	Adj adj(n, vector < int>());
	Adj cost(n, vector<int>());
	for (int i = 0; i<m; ++i) {
		int u, v, c;
		in >> u >> v >> c;
		adj[u - 1].push_back(v - 1);
		cost[u - 1].push_back(c);
	}
	// create the object of class AStar
	AStar astar(n, adj, cost, xy);
	// Query
	int t;
	in >> t;
	cout << "Results are " << endl;
	for (int i = 0; i<t; ++i) {
		int u, v;
		in >> u >> v;
		cout << astar.query(u - 1, v - 1) << endl;

	}

}
