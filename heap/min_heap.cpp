
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

        void decrease_key(int key, int val) {
            this->hp[key] = val;
            for(int i = key; i >= 0; i /= 2) {
                cout<<"i is -> "<<i<<endl;
                if(this->hp[i] < this->hp[(i-1)/2])
                    swap(this->hp[i], this->hp[(i-1)/2]);
                else
                    return;
            }
        }

        void increase_key(int key, int val) {
            this->hp[key] = val;
            this->min_heapify(key);
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

        int extractMin() {
            swap(this->hp[0], this->hp[--heap_size]);
            min_heapify(0);
            return this->hp[heap_size];
        }

        void insert(int val) {
            if(this->hp.size() > this->heap_size)
                this->hp[heap_size] = numeric_limits<int>::max();
            else
                this->hp.push_back(numeric_limits<int>::max());
            this->decrease_key(this->heap_size++, val);
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

        void print_as_array() {
            for(int i = 0; i < heap_size; i++)
                cout<<this->hp[i]<<" ";
            cout<<endl;
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
    heap.print_as_array();
    heap.print();
    cout<<"\nNow time to insert a new element, gimme a value: ";
    int val;
    cin>>val;
    heap.insert(val);
    cout<<"After insertion the heap is -> \n";
    heap.print_as_array();
    heap.print();
    return 0;
}
