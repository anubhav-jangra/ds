// also referred to as level order transversal
// This is for undirected graphs
// cycle detection for undirected graphs can be done by either BFS or DFS
#include<iostream>
#include<iomanip>
#include<list>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
// implementation using adjacency lists
class Graph{
    private:
        int V; // number of vertices
        list<int> *adj; // pointer to array containing adjecency lists
    public:
        Graph(int V); // Constructor
        void printMatrix();
        void addEdge(int v, int w); // function to add edges in graph
        void BFS(int s); // prints from a given source s
};

int main() {

    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    Graph g(n);
    cout<<"Gimme some edges in between the nodes\n";
    cout<<"PS - enter -1 when you wanna stop\n";
    int a, b;
    while(true) {
        cout<<"First node : ";
        cin>>a;
        if(a == -1)
            break;
        cout<<"Second node : ";
        cin>>b;
        if(b == -1)
            break;
        g.addEdge(a, b);
        g.printMatrix();
    }
    int p;
    cout<<"Gimme the starting node: ";
    cin>>p;
    cout<<"Breadth first search -> ";
    g.BFS(p);
    return 0;
}

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; // this will create an array of lists initially empty
    // whereas new list<int>(V) would have just created a list with V elements
    // and also list<int>V just creates an empty list named V
}

void Graph::printMatrix() {
    cout<<"   ";
    for(int i = 0; i < V; i++) {
        cout<<" "<<setw(3)<<right<<i;
    }
    cout<<endl;
    for(int i = 0; i < V; i++) {
        cout<<setw(3)<<right<<i;
        vector<int> vec(V, 0);
        list<int>::iterator it;
        for(auto e : adj[i]) {
            vec[ e ] = 1;
        }
        for(int j = 0; j < vec.size(); j++) {
            cout<<" "<<setw(3)<<right<<vec[j];
        }
        cout<<endl;
    }
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // adds w to v's list
    adj[w].push_back(v); // adds v to w's list
}

void Graph::BFS(int s){
    vector<bool> visited(this->V, false);
    queue<int> que;
    visited[s] = true;
    que.push(s);
    list<int>::iterator it;
    while(!que.empty()) {
        // Dequeue a vertex from the queue and print it
        s = que.front();
        cout<<s<<" ";
        que.pop();
        for(it = adj[s].begin(); it != adj[s].end(); it++) {
            if(!visited[*it]) {
                visited[*it] = true;
                que.push(*it);
            }
        }
    }
}
