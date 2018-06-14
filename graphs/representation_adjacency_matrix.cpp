#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void addEdge(vector<vector<int> > &matrix, int a, int b) {
    if(a > matrix.size() || b > matrix.size()) {
        cout<<"OUT OF BOUNDS\n";
        return;
    }
    if(matrix[a][b] == 0) {
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
}

void printMatrix(vector<vector<int> > &matrix) {
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
}

int main()
{
    int n;
    cout<<"Gimme the size of graph: ";
    cin>>n;
    vector<vector<int> > matrix(n, vector<int>(n, 0));
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
