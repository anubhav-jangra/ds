#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<algorithm>
using namespace std;

class MaxHeap {
    private:
        int heap_size;
        vector<int> hp;

        void max_heapify(int i) {
            int l = 2*i + 1, r = 2*i + 2, largest = i;
            if(l < this->heap_size && hp[i] < hp[l])
                largest = l;
            if(r < this->heap_size && hp[largest] < hp[r])
                largest = r;
            if(largest != i) {
                swap(this->hp[i], this->hp[largest]);
                this->max_heapify(largest);
            }
        }
        
        void build_heap() {
            for(int i = floor(this->heap_size/2)-1; i >= 0; i--)
                this->max_heapify(i);
        }

        void increase_key(int key, int val) {
            this->hp[key] = val;
            for(int i = key; i >= 0; i = (i-1)/2) {
                if(hp[i] > hp[(i-1)/2])
                    swap(hp[i], hp[(i-1)/2]);
                else
                    return;
            }
        }
        
        void decrease_key(int key, int val) {
            this->hp[key] = val;
            this->max_heapify(key);
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
        MaxHeap(const vector<int> &vec) {
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
 
        void print_as_array() {
            for(int i = 0; i < heap_size; i++) {
                cout<<i<<": "<<this->hp[i]<<endl;
            }
        }
        
        int pop_max() {
            if(this->heap_size < 1) {
                cout<<"CURRENTLY HEAP IS EMPTY!!\n";
                    return -1;
            }
            swap(hp[0], hp[--heap_size]);
            max_heapify(0);
            return hp[heap_size - 1];
        }

        void change(int key, int val) {
            if(hp[key] > val)
                this->decrease_key(key, val);
            else if(hp[key] < val)
                this->increase_key(key, val);
        }

        void insert(int val) {
            if(this->heap_size > this->hp.size())
                this->hp[heap_size] = numeric_limits<int>::min();
            else
                this->hp.push_back(numeric_limits<int>::min());
            this->increase_key(heap_size++, val);
        }

        void heap_sort() {
            int temp = heap_size;
            for(int i = this->heap_size - 1; i > 0; i--) {
                swap(this->hp[i], this->hp[0]);
                heap_size--;
                max_heapify(0);
            }
            heap_size = temp;
        }
};

int main()
{
    int n, key, val;
    cout<<"Gimme the size of data: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the "<<n<<" elements: ";
    for(int i = 0; i < n; i++)
        cin>>vec[i];
    MaxHeap heap(vec);
    heap.print();
    /*
    cout<<"\nNow let's pop the max element\n";
    heap.pop_max();
    heap.print();
    cout<<"\nNow onto changing a value\nThese are the key-value pairs\n";
    heap.print_as_array();
    cout<<"Gimme a key: ";
    cin>>key;
    cout<<"Now it's new value: ";
    cin>>val;
    heap.change(key, val);
    cout<<"The heap after the change in this new value is ->\n";
    heap.print();
    cout<<"\nNow onto insertion\n";
    cout<<"Gimme a value: ";
    cin>>val;
    heap.insert(val);
    heap.print();
    */
    cout<<"\nNow the sorted heap is -> \n";
    heap.heap_sort();
    heap.print_as_array();
}
