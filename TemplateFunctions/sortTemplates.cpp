#include <iostream>
#include <vector>

namespace sortTemplate
{

template <typename T>
bool ascSorting(T a, T b){
    return a < b;
}

template <typename T>
bool descSorting(T a, T b){
    return a > b;
}

template <typename T>
void merge(std::vector<T> &arr, int left, int mid, int right){
    //calcuate sizes for temp vectors
    int n1 = mid - left + 1;
    int n2 = right - mid; 

    //crate temp vectors
    std::vector<int> L(n1), R(n2);

    //copy data from main arr into temp vectors
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + i + 1];
    }


    int i = 0, j = 0; int k = left;
    
    //insert data into main arr in sorted order
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){ //right there we can change order (ASC order or DESC order) just replace: L[i] <= R[j] by bool function
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy remaining data from L and R vectors into main arr
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T> &arr, int left, int right){
    if(left >= right){
        return;
    }

    int mid = (left + right) / 2;
    //at first we put left part and right part into mergeSort function and do merge 
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void quickSort(std::vector<T> &s, int left, int right) {
    if (left >= right) return;

    int i = left;
    int j = right;
    int p = (int)s[(left + right) / 2]; 

    while (i <= j) {
        while ((int)s[i] < p) i++;
        while ((int)s[j] > p) j--;
        if (i <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(s, left, j);
    if (i < right) quickSort(s, i, right);
}

}
