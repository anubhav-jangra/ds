// also referred to as in+pre+post order transversal in trees
// This is for directed graphs
// Major applications include -> 
// 1. Spannig tree for a tree
// 2. All pair shortest path tree
// 3. Detect cycle in tree
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
        void DFSUtil(int s, vector<bool> &visited);
        bool hasCycleUtil(int s, vector<bool> &visited);
    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add edges in graph
        void printMatrix();
        // This is for type 1
        void DFS(int s); // prints from a given source s
        // For type 2
//        void DFS(); // prints from a given source s
        bool hasCycle();
};

int main() {
    // Create a graph given in the above diagram
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
    // cout << "Following is Depth First Traversal (Starting from 2)\n";
    // g.DFS(2);
    cout<<"Following graph -> ";
    if(g.hasCycle())
        cout<<"has a cycle\n";
    else
        cout<<"doesn't have a cycle\n";
 
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
void Graph::DFS(int s){
    vector<bool> visited(this->V, false);
    DFSUtil(s, visited);
}

// Whereas this one does a DFS for all node irrespective of its nature as connected or disconnected
/*
void Graph::DFS(){
    vector<bool> visited(this->V, false);

    for(int i = 0; i < V; i++)
        if(!visited[i])
            DFSUtil(i, visited);
}
*/

bool Graph::hasCycleUtil(int s, vector<bool> &visited) {
    visited[s] = true;
    list<int>::iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++) {
        if(!visited[*it]) {
            if(hasCycleUtil(*it, visited))
                return true;;
        } else 
            return true;
    }
    return false;
}

bool Graph::hasCycle() {
    for(int i = 0; i < V; i++) {
        vector<bool> visited(this->V, false);
        if(!visited[i])
            if( hasCycleUtil(i, visited) )
                return true;
    }
    return false;
}
