// also referred to as in+pre+post order transversal in trees
// This is for directed graphs
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
        void DFSUtil(int s, vector<bool> &visited);
    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add edges in graph
        // This is for type 1
//        void DFS(int s); // prints from a given source s
        // For type 2
        void DFS(); // prints from a given source s
        
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
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
 
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

// recursive helper function for DFS
void Graph::DFSUtil(int s, vector<bool> &visited) {
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++)
        if(!visited[*it])
            DFSUtil(*it, visited);
}

// This is a function if you wanna do DFS from a particular node
/*
void Graph::DFS(int s){
    vector<bool> visited(this->V, false);
    DFSUtil(s, visited);
}
*/

// Whereas this one does a DFS for all node irrespective of its nature as connected or disconnected
void Graph::DFS(){
    vector<bool> visited(this->V, false);

    for(int i = 0; i < V; i++)
        if(!visited[i])
            DFSUtil(i, visited);
}
