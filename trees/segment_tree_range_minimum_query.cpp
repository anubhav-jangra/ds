#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

class SegmentTree {
    private:
        int n;          // size of array for which ST is to be formed
        int h;          // height of ST
        int max_size;   // max size of array for the segment tree
        vector<int> st; // array for ST
        vector<int> hist;   // array of the histogram given

        int getMid(int s, int e) { return s + (e - s)/2; }
   

        int constructSTUtil(int ss, int se, int si) {
            // cout<<"ss -> "<<ss<<" se -> "<<se<<" si -> "<<si<<endl;
            // If there is one element in array, store it in current node of
            // segment tree and return
            if(ss == se) {
                this->st[si] = hist[ss];
                return hist[ss];
            }
            
            // If there are more than one elements, then recur for left and
            // right subtrees and store the minimum of two values in this node
            int mid = this->getMid(ss, se);
            this->st[si] = min(this->constructSTUtil(ss, mid, 2*si + 1), 
                               this->constructSTUtil(mid+1, se, 2*si + 2));
            // this is where you modify to get desired ST results
            return this->st[si];
        }
        int RMQUtil(int ss, int se, int qs, int qe, int si) {
            // If segment of this node is a part of given range, then return
            //  the min of the segment
            if(qs <= ss && qe >= se)
                return this->st[si];
            if(se < qs || ss > qe)
                return INT_MAX;;
            int mid = this->getMid(ss, se);
            return min(this->RMQUtil(ss, mid, qs, qe, si),
                       this->RMQUtil(mid+1, se, qs, qe, si));
        }

    public:
        SegmentTree(vector<int> arr) {      // to initialize the ST(formation)
            this->hist = arr;
            this->n = arr.size();
            this->h = (int)ceil(log2(n));
            this->max_size = 2*(int)pow(2, n) - 1;
            for(int i = 0; i < max_size; i++)
                this->st.push_back(-1);
            this->constructSTUtil(0, n-1, 0);
        }
    
        int RMQ(int qs, int qe) {
            // Check for erroneous input values
            if(qs < 0 || qe > n - 1 || qs > qe) {
                cout<<"Invalid Input\n";
                return -1;
            }
            return this->RMQUtil(0, n - 1, qs, qe, 0);
        }
};

int main()
{
    int n;
    cout<<"Gimme value of n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    SegmentTree segTree(arr);
    int qs, qe;
    cout<<"Gimme the starting value: ";
    cin >> qs;
    cout<<"Gimme the ending value: ";
    cin>>qe;
    cout<<"minimum in "<<qs<<" to "<<qe<<" is -> "<<segTree.RMQ(qs, qe);
}
