// This is for undirected and weighted graphs
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <cmath>
#include <map>
using namespace std;

class MinHeap {
    private:
        int heap_size;
        vector<vector<int> > hp;
        void min_heapify(int i);
        void build_heap();
        void increase_key(int index, int key, int parent);
        int findV(int v);
        string do_padding (unsigned index, unsigned mlength);
        void printer (unsigned index, unsigned mlength);
    public:
        MinHeap(const vector<pair<int, int> > &vec);
        bool isEmpty();
        vector<int> extractMin();
        void decrease_key(int index, int key, int parent);
        void insert(int key, int parent);
        void updateStuff(int u, int v, int cost);
        void print ();
        void print_as_array();
};

class Graph {
    private:
        int V;
        pair<int, int> least_edge;
        bool started;
        vector<vector<int> > matrix;
    public:
        Graph(int V);    // constructor
        void printMatrix();
        void addEdge(int a, int b, int w);
        int costUtil(int a, int b);
        vector<vector<int> >MST_prime(int root);                     // for minHeap approach
//        vector<pair<int, int> >MST_prime(int root);       // for O(V^2) approach
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
    cout<<"Gimme the starting point: ";
    int start_point;
    cin>>start_point;
    cout<<"Now Minimum Spanning tree by prim's algorithm is -> \n";
    g.MST_prime(start_point);
    /*
    int n;
    cout<<"Gimme the size of data: ";
    cin>>n;
    vector<pair<int, int> > vec(n);
    cout<<"Enter the "<<n<<" element pairs: ";
    for(int i = 0; i < n; i++)
        cin>>vec[i].first>>vec[i].second;
    MinHeap heap(vec);
    heap.print_as_array();
    heap.print();
    pair<int, int> pr = heap.extractMin();
    cout<<"\n Now to extract minimum element : ("<<pr.first<<","<<pr.second<<")\n";
    heap.print();
    cout<<"\nNow time to insert a new element, gimme a pair: ";
    int key, parent;
    cin>>key>>parent;
    heap.insert(key, parent);
    cout<<"After insertion the heap is -> \n";
    heap.print_as_array();
    heap.print();
    cout<<"Now to decrease an element\n";
    cout<<"Gimme an index: ";
    int index, val1, val2;
    cin>>index;
    cout<<"Now its new value pair: ";
    cin>>val1>>val2;
    heap.decrease_key(index, val1, val2);
    heap.print();*/
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

// T-O(V^2)
/*
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
*/

// T-O(ElogV)
// Using min_heap
// first is key
// second is parent
vector<vector<int> > Graph::MST_prime(int root = 0) {
    vector<pair<int, int> > vec(V, make_pair(numeric_limits<int>::max(), -1));
    vector<vector<int> > ans;
    vector<bool> pushed(V, false);
    vec[root].first  = 0;
    vec[root].second = 0;
    MinHeap Q(vec);
    vector<int> u = Q.extractMin();
    ans.push_back(u);
    pushed[u[0]] = true;
    while(!Q.isEmpty()) {
        for(int v = 0; v < V; v++)    // v is node adjacent to u
            if(matrix[u[0]][v] != 0 && pushed[v] != true)
                Q.updateStuff(u[0], v, costUtil(u[0], v));
        u = Q.extractMin();
        ans.push_back(u);
        pushed[u[0]] = true;
    }
    for(int i = 0; i < ans.size(); i++) {
        cout<<"("<<ans[i][0]<<", "<<ans[i][1]<<", "<<ans[i][2]<<")\t";
    }
    cout<<endl;
    return ans;
}

// =========================================------------ MINHEAP - STUFF ----------====================================

void MinHeap::min_heapify(int i) {
    int l = 2*i + 1, r = 2*i + 2, smallest = i;
    if(l < this->heap_size && hp[i][1] > hp[l][1])
        smallest = l;
    if(r < this->heap_size && hp[smallest][1] > hp[r][1])
        smallest = r;
    if(smallest != i) {
        swap(this->hp[i], this->hp[smallest]);
        this->min_heapify(smallest);
    }
}

void MinHeap::build_heap() {
    for(int i = floor(this->heap_size/2); i >= 0; i--)
        this->min_heapify(i);
}

void MinHeap::decrease_key(int index, int key, int parent) {
    this->hp[index][1] = key;
    this->hp[index][2] = parent;
    for(int i = index; i >= 0; i = (i-1)/2) {
        if(this->hp[i][1] < this->hp[(i-1)/2][1]) {
            swap(this->hp[i], this->hp[(i-1)/2]);
        } else {
            return;
        }
    }
}

string MinHeap::do_padding (unsigned index, unsigned mlength){
    string padding;
    if (int((index-1)/2) != 0){
        return (int((index-1)/2) % 2 == 0) ?
        (do_padding(int((index-1)/2),mlength) + string(mlength+4,' ') + " ")  :
        (do_padding(int((index-1)/2),mlength) + string(mlength+3,' ') + " |") ;
    }
    return padding;
}

void MinHeap::printer (unsigned index, unsigned mlength){
    auto last  = heap_size - 1 ;
    auto left  = 2 * index + 1 ;
    auto right = 2 * index + 2 ;
    cout << " (" << this->hp[index][0]<<","<<this->hp[index][1]<< "," << this->hp[index][2] << ") ";
    if (left <= last){
        auto llength = (to_string(this->hp[left][0]) + to_string(this->hp[left][1]) + to_string(this->hp[left][2]) + "(,,)").size();
        cout << "---" << string(mlength - llength,'-');
        printer(left,mlength);
        if (right <= last) {
            auto rlength = (to_string(this->hp[right][0]) + to_string(this->hp[right][1]) + to_string(this->hp[right][2]) + "(,,)").size();
            cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " | ";
            cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " └" <<
            string(mlength - rlength,'-');
            printer(right,mlength);
        }
    }
}

MinHeap::MinHeap(const vector<pair<int, int> > &vec) {
    this->heap_size = vec.size();
    hp = vector<vector<int> >(heap_size, vector<int>(3, -1));
    for(int i = 0; i < heap_size; i++) {
        hp[i][0] = i;
        hp[i][1] = vec[i].first;
        hp[i][2] = vec[i].second;
    }
    this->build_heap();
}

vector<int> MinHeap::extractMin() {
    swap(this->hp[0], this->hp[--heap_size]);
    min_heapify(0);
    return this->hp[heap_size];
}

void MinHeap::insert(int key, int parent) {
    if(this->hp.size() > this->heap_size)
        this->hp[heap_size][0] = numeric_limits<int>::max();
    else {
        this->hp.push_back(vector<int>(3));
        this->hp[heap_size][0] = numeric_limits<int>::max();
    }
    this->decrease_key(this->heap_size++, key, parent);
}

void MinHeap::updateStuff(int u, int v, int cost) {
    int i = 0;
    while(this->hp[i][0] != v)
        i++;
    if(cost < this->hp[i][1])
        decrease_key(i, cost, u);
}

bool MinHeap::isEmpty() {
    if(heap_size > 0)
        return false;
    return true;
}

void MinHeap::print (){
    cout<<"\n";
    unsigned mlength = 0;
    for (vector<int> &element : this->hp){
        auto clength = (to_string(element[0]) + to_string(element[1]) + to_string(element[2]) + "(,,)").size();
        if (clength > mlength) {
            mlength = (to_string(element[0]) + to_string(element[1]) + to_string(element[2]) + "(,,)").size();
        }
    }
    cout <<  string(mlength - (to_string(this->hp[0][0]) + to_string(this->hp[0][1]) + to_string(this->hp[0][2]) + "(,,)").size(),' ');
    printer(0,mlength);
    cout<<endl;
}

void MinHeap::print_as_array() {
    for(int i = 0; i < hp.size(); i++)
        cout<<"("<<this->hp[i][0]<<","<<this->hp[i][1]<<","<<this->hp[i][2]<<") ";
    cout<<endl;
}
