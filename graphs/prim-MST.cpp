// This is for undirected and weighted graphs
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

class Graph {
    private:
        int V;
        pair<int, int> least_edge;
        bool started;
        vector<vector<int> > matrix;
        int costUtil(int a, int b);
    public:
        Graph(int V);    // constructor
        void printMatrix();
        void addEdge(int a, int b, int w);
        vector<pair<int, int> >MST_prime();
};

int main()
{
    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    Graph g(n);
    cout<<"Gimme some edges in between the nodes\n";
    cout<<"PS - enter -1 when you wanna stop\n";
    int a, b, w;
    while(true) {
        // cout<<"First node : ";
        cin>>a;
        if(a == -1)
            break;
        // cout<<"Second node : ";
        cin>>b;
        if(b == -1)
            break;
        // cout<<"Now the weight: ";
        cin>>w;
        g.addEdge(a, b, w);
        // g.printMatrix();
    }
    cout<<"Final matrix is -> \n";
    g.printMatrix();
    cout<<"Now Minimum Spanning tree by prim's algorithm is -> \n";
    g.MST_prime();
    return 0;
}

Graph::Graph(int V) {
    this->V = V;
    matrix = vector<vector<int> >(V, vector<int>(V, 0) );
    this->started = false;
}

void Graph::addEdge(int a, int b, int w) {
    if(a > matrix.size() || b > matrix.size()) {
        cout<<"OUT OF BOUNDS\n";
        return;
    }
    if(!started) {
        least_edge.first = a;
        least_edge.second = b;
        started = true;
    } else if(matrix[least_edge.first][least_edge.second] > w) {
        least_edge.first = a;
        least_edge.second = b;
    }
    matrix[a][b] = w;
    matrix[b][a] = w;
}

void Graph::printMatrix() {
    cout<<"   ";
    for(int i = 0; i < matrix.size(); i++) {
        cout<<" "<<setw(3)<<right<<i;
    }
    cout<<endl;
    for(int i = 0; i < matrix.size(); i++) {
        cout<<setw(3)<<right<<i;
        for(int j = 0; j < matrix[0].size(); j++) {
            cout<<" "<<setw(3)<<right<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<"LEAST ELEMENT -> "<<matrix[least_edge.first][least_edge.second]<<endl;
}

int Graph::costUtil(int a, int b) {
    if(matrix[a][b] == 0)
        return numeric_limits<int>::max();
    return matrix[a][b];
}

vector<pair<int, int> >Graph::MST_prime() {
    int k = least_edge.second, l = least_edge.first, minCost = matrix[least_edge.first][least_edge.second];
    vector<pair<int, int> >ans;
    ans.push_back(make_pair(k, l));
    vector<int> near(V);
    pair<int, int> min_edge;
    for(int i = 0; i < V; i++) {
        if(costUtil(i, l) < costUtil(i, k)) near[i] = l;
        else near[i] = k;
    }
    near[k] = near[l] = -1;
    for(int i = 2; i < V; i++) {
        int j = 0;
        while(near[j] == 0)
            j++;
        min_edge = make_pair(j, near[j]);
        for(j++; j < V; j++) {
            if(near[j] != -1)
                if(costUtil(j, near[j]) < costUtil(min_edge.first, min_edge.second))
                    min_edge = make_pair(j, near[j]);
        }
        ans.push_back(make_pair(min_edge.first, min_edge.second));
        near[min_edge.first] = -1;
        minCost += costUtil(min_edge.first, min_edge.second);
        near[j] = 0;
        for(int p = 0; p < V; p++) {
            if(near[p] != -1 && (costUtil(p, near[p]) > costUtil(p, min_edge.first) ))
                near[p] = min_edge.first;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout<<matrix[ans[i].first][ans[i].second]<<" ";
    }
    cout<<endl;
    return ans;
}
