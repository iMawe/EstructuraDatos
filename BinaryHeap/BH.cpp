#include <iostream>
#include <fstream>
#include <string>


using namespace std;

template <class T, size_t cap = 100>
class BH|
{
    private:
        T * elems;
        size_t size;
        ofstream os;
        
    public:
        BH(): elems(new T[cap]), size(0), os("grap.dot") {};
        ~BH()
        {
            delete [] elems;
        }
        
        T operator [](int i){
            return elems[i];
        } 

        void push(T x)
        {
            elems[size] = x;
            
            UPDOWN(size, 0);
            size++;

        }
        
        void pop(){
            if(size == 0)
                return;
    
            elems[0] = elems[size];

            UPDOWN(0, 1);
            size--;
        }
        
        // min 
        T top()
        {
            return elems[0];
        }

        T PARENT(int i) 
        { 
            return (i - 1) / 2; 
        }

        T LR(int i, bool dir) 
        { 
            if (dir == 0)
                return (2 * i + 1);
            else
                return (2 * i + 2); 
        }

        void printGEGE(){
            os<<"graph {"<<endl;
            os<<elems[0]<<endl;
            printDeMachos();
            os<<"}"<<endl;
        }

        void printDeMachos(){
            int c=0;
            while(c<size){
                int l=LR(c, 0);
                int r=LR(c, 1);
                if(l<size){
                    os<<elems[c]<<"--"<<elems[l]<<endl;
                }
                if(r<size){
                    os<<elems[c]<<"--"<<elems[r]<<endl;
                }
                c++;
            }
        }
    
    private:
        void UPDOWN(int i, bool dir)
        {
            if(i == 0)
                return;
            else if (dir == 0){
                int parentIndex = PARENT(i);

                if(elems[parentIndex] > elems[i]){
                    swap(elems[parentIndex], elems[i]);
                    UPDOWN(parentIndex, 0);
                }
            }
            else if (dir == 1){
                int leftIndex = LR(i, 0);
                int rightIndex = LR(i, 1);

                if(leftIndex >= size)
                    return; //i is a leaf

                int minIndex = i;

                if(elems[i] > elems[leftIndex])
                    minIndex = leftIndex;
                
    
                if((rightIndex < size) && (elems[minIndex] > elems[rightIndex]))
                    minIndex = rightIndex;
                

                if(minIndex != i){
                    swap(elems[i], elems[minIndex]);
                    UPDOWN(minIndex, 1);
                }
            }
        }
}; 

int LR(int i, bool dir) 
        { 
            if (dir == 0)
                return (2 * i + 1);
            else
                return (2 * i + 2); 
        }

void Heapify(int arr[], int size,int i){ 
    int largest = i;
    int leftIndex = LR(i, 0);
    int rightIndex = LR(i, 1);
  
    if (leftIndex < size && arr[leftIndex] > arr[largest]) largest = leftIndex; 

    else if (rightIndex < size && arr[rightIndex] > arr[largest]) largest = rightIndex; 
  
    else if (largest != i){ 
        swap(arr[i], arr[largest]);
        Heapify(arr, size, largest); 
    } 
};


void HeapSort(int arr[], int size) 
{ 
    for (int i = size / 2 - 1; i >= 0; i--) 
        Heapify(arr, size, i); 
  
    for (int i = size-1; i >= 0; i--){ 
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0); 
    } 
};
    

int main()
{
    BH<int> h;
    int t;
    
    for(int i = 19; i > 0; i--)
        h.push(i);
    
    for(int i = 0; i < 19; i++){
        t = h[i];
        cout<<t<<" ";

    }
    cout<< endl;
    cout << h.top() << endl;
    cout<< endl;

    h.printDeMachos();


    

    int j[10] = {10,25,15,48,65,87,2,3,1,4};
    int size = sizeof(j)/sizeof(j[0]);

    HeapSort(j, size);

    for(int i = 0; i < 10; i++){
        t = j[i];
        cout<<t<<" ";

    }
    


    return 0;
}
