#include <iostream>
#include <vector>
template <typename T>
class MinHeap {
    public:
    vector<T> a;

    // Get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Get left child index
    int left(int i) {
        return 2 * i + 1;
    }

    // Get right child index
    int right(int i) {
        return 2 * i + 2;
    }

    // Get minimum element (root) - O(1)
    int getMin() {
        return a[0];
    }

    // Insert element - O(log n)
    void insert(int k) {
        // Add element at the end
        a.push_back(k);
        int ind = a.size() - 1;

        // Heapify up: bubble up the element
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    // Heapify down - O(log n)
    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;

        // Find smallest among node and its children
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        // If parent is greater than smallest child, swap and continue
        if (a[i] > a[j]) {
            std::swap(a[i], a[j]);
            heapify(j);
        }
    }

    // Extract minimum element - O(log n)
    int extractMin() {
        int root_value = getMin();

        // Replace root with last element
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        // Heapify down from root
        if (a.size() > 0)
            heapify(0);

        return root_value;
    }
};
