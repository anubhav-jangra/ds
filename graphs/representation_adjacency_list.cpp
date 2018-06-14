// This is for undirected graphs
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void addEdge(vector<int> matrix[], int a, int b, int n) {
    if(a > n || b > n) {
        cout<<"OUT OF BOUNDS\n";
        return;
    }
    matrix[a].push_back(b);
    matrix[b].push_back(a);
}

void printMatrix(const vector<int> matrix[], int n) {
    cout<<"   ";
    for(int i = 0; i < n; i++) {
        cout<<" "<<setw(3)<<right<<i;
    }
    cout<<endl;
    for(int i = 0; i < n; i++) {
        cout<<setw(3)<<right<<i;
        vector<int> vec(n, 0);
        for(int j = 0; j < matrix[i].size(); j++) {
            vec[ matrix[i][j] ] = 1;
        }
        for(int j = 0; j < vec.size(); j++) {
            cout<<" "<<setw(3)<<right<<vec[j];
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    vector<int> matrix[n];
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
        addEdge(matrix, a, b, n);
        printMatrix(matrix, n);
    }
    return 0;
}


// Useless stuff
/*#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

struct node{
    int data;
    struct node *next;
};

bool find_in_list(node * head, int x) {
    while(head) {
        if(head -> data == x)
            return true;
    }
    return false;
}

void addEdge(node **head, int val) {
    node * nod = new (nothrow) (node);
    nod -> data = val;
    nod -> next = nullptr;
    if(*head == nullptr) {
        (*head) = nod;
    }
    else {
        nod -> next = *head;
        *head = nod;
    }
}

void addEdge(vector<node*> &matrix, int a, int b) {
    if(a > matrix.size() || b > matrix.size()) {
        cout<<"OUT OF BOUNDS\n";
        return;
    }
    if(!(find_in_list(matrix[a], b))) {
        addEdge(&matrix[a], b);
        addEdge(&matrix[b], a);
    }
}

void printMatrix(const vector<node*> &matrix) {
    cout<<"   ";
    for(int i = 0; i < matrix.size(); i++) {
        cout<<" "<<setw(3)<<right<<i;
    }
    cout<<endl;
    for(int i = 0; i < matrix.size(); i++) {
        cout<<setw(3)<<right<<i;
        vector<int> vec(matrix.size(), 0);
        node *temp = matrix[i];
        while(temp) {
            vec[temp->data] += 1;
            temp = temp->next;
        }
        for(int j = 0; j < vec.size(); j++) {
            cout<<" "<<setw(3)<<right<<vec[j];
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    vector<node*> matrix(n, nullptr);
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
        addEdge(matrix, a, b);
        printMatrix(matrix);
    }
}
*/
