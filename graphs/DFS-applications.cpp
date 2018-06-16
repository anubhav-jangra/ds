// also referred to as in+pre+post order transversal in trees
// This is for directed graphs
// Major applications include -> 
// 1. Spannig tree for a tree
// 2. All pair shortest path tree
// 3. Detect cycle in tree
// 4. To find a path between two connected nodes
// 5. Topological Sorting of nodes
// 6. To check if the graph is is bipartite (---pending---)
// 7. To find all the Strongly Connected Components of a graph
// 8. To solve Maze problems
#include<iostream>
#include<iomanip>
#include<list>
#include<vector>
#include<queue>
#include<iterator>
#include<stack>
using namespace std;

// implementation using adjacency lists
class Graph{
    private:
        int V; // number of vertices
        list<int> *adj; // pointer to array containing adjecency lists
        void DFSUtil(int s, vector<bool> &visited);
        bool hasCycleUtil(int s, vector<bool> &visited);
        void pathDetectionUtil(int u, int v, vector<bool> &visited, vector<int> &path);
        void topologicalSortingUtil(int s, vector<bool> &visited, stack<int> &path);
        list<int> *transposeGraph();
        void printReverseMatrix(list<int> *T_adj);
        void SCCUtil(int s, vector<bool> &visited, list<int> *T_adj);
    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add edges in graph
        void printMatrix();
        // This is for type 1
        void DFS(int s); // prints from a given source s
        // For type 2
//        void DFS(); // prints from a given source s
        bool hasCycle();
        vector<int> pathDetection(int u, int v);
        stack<int> topologicalSorting();
        void SCC();
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
/*
    int p;
    cout<<"Gimme the starting point for DFS: ";
    cin>>p;
    cout << "Following is Depth First Traversal: \n";
     g.DFS(p);
*/
/*    cout<<"Following graph -> ";
    if(g.hasCycle())
        cout<<"has a cycle\n";
    else
        cout<<"doesn't have a cycle\n";
*/

/*    int u, v;
    cout<<"Gimme the start point: ";
    cin>>u;
    cout<<"Gimme the end point: ";
    cin>>v;
    cout<<"The iteration from u to v is -> ";
    vector<int> path = g.pathDetection(u, v);
    for(int i = 0; i < path.size(); i++)
        cout<<path[i]<<" ";
    cout<<endl;
*/
/*    cout<<"Topological Sort for the following graph is -> ";
    stack<int> stk = g.topologicalSorting();
    while(!stk.empty()) {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
*/
    cout<<"The Strongly connected components of the given graph are -> \n";
    g.SCC();
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

void Graph::pathDetectionUtil(int u, int v, vector<bool> &visited, vector<int> &path) {
    path.push_back(u);
    visited[u] = true;
    if(u == v)
        return;
    list<int>::iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); it++)
        if(!visited[*it]) {
            while(path.back() != u)
                path.pop_back();
            return pathDetectionUtil(*it, v, visited, path);
        }
}

vector<int> Graph::pathDetection(int u, int v) {
    vector<bool> visited(V, false);
    vector<int> path;
    pathDetectionUtil(u, v, visited, path);
    return path;
}

void Graph::topologicalSortingUtil(int s, vector<bool> &visited, stack<int> &path) {
    visited[s] = true;
    list<int>::iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++)
        if(!visited[*it])
            topologicalSortingUtil(*it, visited, path);
    path.push(s);
}

stack<int> Graph::topologicalSorting() {
    vector<bool> visited(V, false);
    stack<int> path;
    for(int i = 0; i < V; i++) {
        if(!visited[i])
        topologicalSortingUtil(i, visited, path);
    }
    return path;
}


// Pending
/*
bool Graph::isBipartite() {
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            isBipartiteUtil(i, visited);
    }
}
*/

void Graph::printReverseMatrix(list<int> *T_adj) {
    cout<<"   ";
    for(int i = 0; i < V; i++) {
        cout<<" "<<setw(3)<<right<<i;
    }
    cout<<endl;
    for(int i = 0; i < V; i++) {
        cout<<setw(3)<<right<<i;
        vector<int> vec(V, 0);
        list<int>::iterator it;
        for(auto e : T_adj[i]) {
            vec[ e ] = 1;
        }
        for(int j = 0; j < vec.size(); j++) {
            cout<<" "<<setw(3)<<right<<vec[j];
        }
        cout<<endl;
    }
}

list<int> * Graph::transposeGraph() {
    list<int> *T_adj = new list<int>[V];
    for(int i = 0; i < V; i++) {
        list<int>::iterator it;
        for(auto e : adj[i]) {
            // important stuff goes here
            T_adj[e].push_back(i);
        }
    }
    printReverseMatrix(T_adj);
    return T_adj;
}

void Graph::SCCUtil(int s, vector<bool> &visited, list<int> *T_adj) {
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it = T_adj[s].begin(); it != T_adj[s].end(); it++)
        if(!visited[*it])
            SCCUtil(*it, visited, T_adj);
}

// Kosaraju's algorithm
// SCC -> Strongly Connected Components
void Graph::SCC() {
    stack<int> stk = topologicalSorting();
    list<int> *T_adj = transposeGraph();
    vector<bool> visited(V, false);
    while(!stk.empty()) {
        if(!visited[stk.top()]) {
            SCCUtil(stk.top(), visited, T_adj);
            cout<<endl;
        }
        stk.pop();
    }
}
