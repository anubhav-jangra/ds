#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class MinHeap {
    private:
        int heap_size;
        vector<int> hp;

        void min_heapify(int i) {
            int l = 2*i + 1, r = 2*i + 2, smallest = i;
            if(l < this->heap_size && hp[i] > hp[l])
                smallest = l;
            if(r < this->heap_size && hp[smallest] > hp[r])
                smallest = r;
            if(smallest != i) {
                swap(this->hp[i], this->hp[smallest]);
                this->min_heapify(smallest);
            }
        }
        
        void build_heap() {
            for(int i = floor(this->heap_size/2); i >= 0; i--)
                this->min_heapify(i);
        }

        string do_padding (unsigned index, unsigned mlength){
            string padding;
            if (int((index-1)/2) != 0){
                return (int((index-1)/2) % 2 == 0) ?
                (do_padding(int((index-1)/2),mlength) + string(mlength+4,' ') + " ")  :
                (do_padding(int((index-1)/2),mlength) + string(mlength+3,' ') + " |") ;
            }
            return padding;
        }


        void printer (unsigned index, unsigned mlength){
            auto last  = heap_size - 1 ;
            auto left  = 2 * index + 1 ;
            auto right = 2 * index + 2 ;
            cout << " " << this->hp[index] << " ";
            if (left <= last){
                auto llength = to_string(this->hp[left]).size();
                cout << "---" << string(mlength - llength,'-');
                printer(left,mlength);
                if (right <= last) {
                    auto rlength = std::to_string(this->hp[right]).size();
                    cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " | ";
                    cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " └" <<
                    string(mlength - rlength,'-');
                    printer(right,mlength);
                }
            }
        }

    public:
        MinHeap(const vector<int> &vec) {
            this->heap_size = vec.size();
            this->hp = vec;
            this->build_heap();
        }

        void print (){
            cout<<"\n";
            unsigned mlength = 0;
            for (int &element : this->hp){
                auto clength = to_string(element).size();
                if (clength > mlength) {
                    mlength = to_string(element).size();
                }
            }
            cout <<  string(mlength - to_string(this->hp[0]).size(),' ');
            printer(0,mlength);
        }


};

int main()
{
    int n;
    cout<<"Gimme the size of data: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the "<<n<<" elements: ";
    for(int i = 0; i < n; i++)
        cin>>vec[i];
    MinHeap heap(vec);
    heap.print();
}
