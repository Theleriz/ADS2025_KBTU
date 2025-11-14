#include <vector>

template <typename T>
class heap{
public:
    std::vector<T> heap;
    int parent(int i){
        return (i-1) / 2;
    }

    int left(int i){
        return i*2 + 1;
    }

    int right(int i){
        return i*2 + 1;
    }

    int getMin(){
        return heap[0];
    }
    
    void inser(int k) {
        heap.push_back(k);
        int index = heap.size() - 1;
        while(index > 0 && heap[index] < heap[parent(index)]){
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int i){
        if(left(i) > heap.size() - 1){
            return;       
        }

        int j = left(i);
        if(right(i) < heap.size() && heap[right(i)] < heap[left(i)]){
            j = right(i);
        }

    }
};