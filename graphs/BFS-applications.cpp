// also referred to as level order transversal
// This is for directed and unweighted graphs
// Major applications include -> 
// 1. Shortest Path
#include<iostream>
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
        void addEdge(int v, int w); // function to add edges in graph
        void BFS(int s); // prints from a given source s
};

int main() {

    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; // this will create an array of lists initially empty
    // whereas new list<int>(V) would have just created a list with V elements
    // and also list<int>V just creates an empty list named V
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // adds w to v's list
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
