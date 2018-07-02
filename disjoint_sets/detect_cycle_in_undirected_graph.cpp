#include<iostream>
#include<vector>
using namespace std;

class Graph {
    private:
        int V;
        pair<int, int> least_edge;
        vector<pair<int, pair<int, int> > > edges;
        int find(vector<pair<int, int> > &parent, int i);
        void Union(vector<pair<int, int> > &parent, int x, int y);
    public:
        Graph(int V);    // constructor
        void printMatrix();
        void addEdge(int a, int b, int w);
        bool isCycle();     // using union-find approach
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
    cout<<"The following graph -> ";
    if(g.isCycle())
        cout<<"contains cycle\n";
    else
        cout<<"doesn't contain cycle\n";
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

int Graph::find(vector<pair<int, int> > &parent, int i) {
    if(parent[i].first != i)
        parent[i].first = find(parent, parent[i].first);
    return parent[i].first;
}

void Graph::Union(vector<pair<int, int> > &parent, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if(parent[xroot].second < parent[yroot].second)
        parent[xroot].first = yroot;
    else if(parent[yroot].second < parent[xroot].second)
        parent[yroot].first = xroot;
    else{
        parent[yroot].first = xroot;
        parent[xroot].second++;
    }

}

// Naive approach
/*
int Graph::find(const vector<int> &parent, int i) {
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Graph::Union(vector<int> &parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
*/
bool Graph::isCycle() {
    vector<pair<int, int> > parent(V);      // this is an array which holds all the subsets for the edges' vertices lies in
    for(int i = 0; i < V; i++) {
        parent[i] = make_pair(i, 0);
    }
    for(int i = 0; i < edges.size(); i++) {
        int x = find(parent, edges[i].second.first);
        int y = find(parent, edges[i].second.second);
        if(x == y)
            return true;
        Union(parent, x, y);
    }
    return false;
}
