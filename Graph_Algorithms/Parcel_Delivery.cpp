#include <bits/stdc++.h>
#define int long long

using namespace std;

class edge{
	public:
		edge(int _next, int _c, int _f, double _cost, int _rev){
			next = _next;
			capacity = _c;
			flow = _f;
			cost = _cost;
			rev = _rev;
		}
		int next;
		int capacity;
		int flow;
		double cost;
		int rev;
};

void add_edge(int now, int next, tuple<int, int, double> t, vector<vector<edge>> &graph){
	int capacity = get<0>(t), flow = get<1>(t);
	double cost = get<2>(t);
	graph[now].push_back(edge(next, capacity, flow, cost, graph[next].size()));
	graph[next].push_back(edge(now, 0, 0, 1e9, graph[now].size() - 1));
}

int change_capacity(int start, int end, int flow, vector<int> &pre, vector<vector<edge>> &graph){

	int now = end;

	// cout << "change capacity \n";

	// for(int i = 0; i < pre.size(); i++){
	// 	cout << pre[i] << " ";
	// }

	// cout << "\n";

	// for(int i = 0; i < graph.size(); i++){
	// 	cout << "node " << i << '\n';
	// 	for(int j = 0; j < graph[i].size(); j++){
	// 		cout << graph[i][j].next << " " << graph[i][j].capacity << " " << graph[i][j].flow << " " << graph[i][j].cost << "\n";
	// 	}
	// 	cout << "\n";
	// }

  int count = 0;

	while(now != start){
    
		int index = graph[now][pre[now]].rev;
		int node = graph[now][pre[now]].next;
		graph[now][pre[now]].capacity += flow;
		graph[node][index].capacity -= flow;

    count += flow * graph[node][index].cost;
		graph[node][index].flow += flow;
		now = node;
	}

	return count;
}

vector<int> SPFA(int start, int end, vector<vector<edge>> &graph){
	int flow = 1e9;
	vector<double> dist(graph.size(), 1e9);
	vector<int> pre(graph.size(), -1);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 0; i < graph[now].size(); i++){
			if(graph[now][i].capacity != 0 and dist[graph[now][i].next] > dist[now] + graph[now][i].cost){
				dist[graph[now][i].next] = dist[now] + graph[now][i].cost;
				q.push(graph[now][i].next);
				flow = min(flow, graph[now][i].capacity);
				pre[graph[now][i].next] = graph[now][i].rev;
			}
		}	
	}
  int count;
  vector<int> v(2);
	if(dist[end] != 1e9) count = change_capacity(start, end, flow, pre, graph);
  v[0] = flow;
  v[1] = count;
  if(dist[end] == 1e9){
    v[0] = 48763;
    v[1] = 48763;
  }
	return v;
}

int MCMF(int start, int end, vector<vector<edge>> &graph, int k){
	int cost = 0, flow = 0;
	while(1){
		auto f = SPFA(start, end, graph);

		// cout << "f = " << f << "\n";

		if(f[0] == 48763 and f[1] == 48763) break;
    flow += f[0];
		cost += f[1];
	}

  cout << flow << ' ';
	return cost;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;

  cin >> n >> m >> k;

  vector<vector<edge>> graph(n + 1);
}