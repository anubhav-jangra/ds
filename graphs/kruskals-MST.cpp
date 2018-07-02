#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    private:
        int V;
        pair<int, int> least_edge;
        vector<pair<int, pair<int, int> > > edges;
        int find(vector<pair<int, int> > &parent, int i, vector<pair<int, pair<int, int> > > &graph);
        void Union(vector<pair<int, int> > &parent, int x, int y, vector<pair<int, pair<int, int> > > &graph);
    public:
        Graph(int V);    // constructor
        void printMatrix();
        void addEdge(int a, int b, int w);
        bool isCycle(vector<pair<int, pair<int, int> > > &graph); // using union-find approach by rank
        vector<pair<int, pair<int, int> > > kruskalsMST();
};

int main() {
    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    Graph g(n);
    cout<<"Gimme some edges in between the nodes\n";
    cout<<"PS - enter -1 when you wanna stop\n";
    int a, b, w;
    while(true) {
        cout<<"First node : ";
        cin>>a;
        if(a == -1)
            break;
        cout<<"Second node : ";
        cin>>b;
        if(b == -1)
            break;
        cout<<"Now the weight: ";
        cin>>w;
        g.addEdge(a, b, w);
        g.printMatrix();
    }
    g.kruskalsMST();
    return 0;
}

Graph::Graph(int V) {
    this->V = V;
}


void Graph::addEdge(int a, int b, int w) {
    if(a > V || b > V) {
        cout<<"OUT OF BOUNDS\n";
        return;
    }
    edges.push_back({w, {a, b}});
}

void Graph::printMatrix() {
    for(int i = 0; i < edges.size(); i++) {
        cout<<"{"<<edges[i].second.first<<", "<<edges[i].second.second<<"}: "<<edges[i].first<<endl;
    }
}

int Graph::find(vector<pair<int, int> > &parent, int i, vector<pair<int, pair<int, int> > > &graph) {
    if(parent[i].first != i)
        parent[i].first = find(parent, parent[i].first, graph);
    return parent[i].first;
}

void Graph::Union(vector<pair<int, int> > &parent, int x, int y, vector<pair<int, pair<int, int> > > &graph) {
    int xroot = find(parent, x, graph);
    int yroot = find(parent, y, graph);

    if(parent[xroot].second < parent[yroot].second)
        parent[xroot].first = yroot;
    else if(parent[yroot].second < parent[xroot].second)
        parent[yroot].first = xroot;
    else {
        parent[yroot].first = xroot;
        parent[xroot].second++;
    }

}

bool Graph::isCycle(vector<pair<int, pair<int, int> > > &graph) {
    vector<pair<int, int> > parent(V);      // this is an array which holds all the subsets for the edges' vertices lies in
    for(int i = 0; i < V; i++)
        parent[i] = make_pair(i, 0);

    for(int i = 0; i < graph.size(); i++) {
        int x = find(parent, graph[i].second.first, graph);
        int y = find(parent, graph[i].second.second, graph);
        if(x == y)
            return true;
        Union(parent, x, y, graph);
    }
    return false;
}

vector<pair<int, pair<int, int> > > Graph::kruskalsMST() {
    vector<pair<int, pair<int, int> > > temp_graph = this->edges, ans_graph;
    sort(temp_graph.begin(), temp_graph.end(), [](pair<int, pair<int, int> > x, pair<int, pair<int, int> > y){ return x.first < y.first;});
    int count = 0, index = 0;
    while(count < V-1 && index <V) {
        ans_graph.push_back(temp_graph[index++]);
        if(this->isCycle(ans_graph)) {
            ans_graph.pop_back();
        } else {
            count++;
        }
    }
    cout<<"ans graph is -> \n";
    for(int i = 0; i < ans_graph.size(); i++) {
        cout<<"{"<<ans_graph[i].second.first<<", "<<ans_graph[i].second.second<<"}: "<<ans_graph[i].first<<endl;
    }
}

