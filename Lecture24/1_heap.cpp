#include<iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

/*

    It is a complete Binary Tree(Every level is completely filled except the last level)
    Nodes always lean towards the left
    - Manage Dynamc Memory allocation
    - It is a contiguous Memory Allocation, also it is fast memory allocation 

    - Max Heap {Parent is bigger than the child}
    - Mean Heap {Parent is smaller than the child}

    Implementation of Heap is done by Array


    all left Nodes will be present at index 2 * i
    all right Nodes will be present at index 2 * i + 1
    all parent will be found at i / 2
    
    Insertion - O(logn)
        - If Max Heap {Max element is on top root Node }
        - If Min Heap {Min element is on top root Node }


    Deletion (Always deleting the root Node) O(logn)
        - put the last Node to root Node
        - and then remove the last Node
        - Heapify Operation where parent is > child Node

    Heapify 
        - In Complete Binary Tree all the Leaf Nodes are present in (n/2 + 1) --> n range 

    Heap Sort (O(nlogn))

*/

class Heap{

    int arr[100];
    int size;
    public:
        Heap(){
            arr[0] = -1;
            size = 0;
        }

        void insertNode(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){

                int parentIdx = index / 2;

                if(arr[parentIdx] < arr[index]){
                    swap(arr[parentIdx], arr[index]);
                    index = parentIdx;
                }else{
                    return ;
                }
            }

        }

        void deleteNode(){ // it will always delete the root Node
            
            if(size == 0){
                cout << "Nothing to Delete, Heap is Empty" << endl;
            }
            //swap last and root
            swap(arr[1], arr[size]);
            size = size - 1;

            int i = 1;

            while(i <= size){
                int lidx = 2 * i;
                int ridx = 2 * i + 1;

                if(arr[lidx] > arr[i] && arr[ridx] > arr[i]){ // both are bigger
                    if(arr[lidx] > arr[ridx]){ // left node is bigger
                        swap(arr[i], arr[lidx]);
                        i = lidx;
                    }else{ // right Node is bigger  
                        swap(arr[i], arr[ridx]);
                        i = ridx;
                    }
                }else if(lidx < size && arr[lidx] > arr[i]){
                    swap(arr[i], arr[lidx]);
                    i = lidx;
                }else if (ridx < size && arr[ridx] > arr[i]){
                    swap(arr[i], arr[ridx]);
                    i = ridx;
                }else{
                    return ;
                }

            }

        }

        void print(){
            for(int i =1; i <= size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

};


void heapify(int arr[], int size, int idx){ // heapifying idxthe Node

    // assume idx Node is the largest
    int largest = idx;
    int leftidx = 2 * idx;
    int rightidx = 2 * idx + 1;

    if(leftidx <= size && rightidx <= size && arr[leftidx] > arr[largest] && arr[rightidx] > arr[largest]){ // both are bigger
        if(arr[leftidx] > arr[rightidx]){ // left node is bigger
            largest = leftidx;
        }else{ // right Node is bigger  
            largest = rightidx;
        }
    }else if(leftidx <= size && arr[leftidx] > arr[largest]){
        largest = leftidx;
    }else if(rightidx <= size && arr[rightidx] > arr[largest]){
        largest = rightidx;
    }

    if(largest != idx){
        swap(arr[largest], arr[idx]); // this means that largest idx is updated hence swap it with idx Node
        heapify(arr, size, largest);
    }

}

/*
Procedure
    {-1, 90, 50, 70, 20, 35}

    itr1 -> swap {-1, 35, 50, 70, 20, | 90} and heapify {-1, 35, 50, 70, 20} --> {-1, 70, 35, 50, 20, 90}
    itr2 -> swap {-1, 20, 35, 50,| 70,  90} and heapify {-1, 20, 35, 50} --> {-1, 50, 35, 20, 70, 90}
    itr3 -> swap {-1, 20, 35 | 50, 70, 90} and heapify {-1, 20, 35} -->  {-1, 35, 20, 50, 70, 90}
    itr3 -> swap {-1, 20, | 35, 50, 70, 90} and heapify {-1, 20} -->  {-1, 20, 35, 50, 70, 90}
    itr 4 -> size = {-1, | 20, 35, 50, 70, 90}, size= 1 break the loop
    
*/

void heapSort(int arr[], int n){ 
    int size = n;

    while(size > 1){
        swap(arr[size], arr[1]); // top element will always be largest
        size = size - 1;
        heapify(arr, size, 1);
    }
    return;
}



// Function to calculate the sum of digits of a number
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Custom comparator for the priority queue
struct CompareSumOfDigits {
    bool operator()(int a, int b) {
        // Compare the sum of digits
        return sum_of_digits(a) < sum_of_digits(b);
    }
};

int main(){

    Heap h;
    h.insertNode(10);
    h.insertNode(5);
    h.insertNode(20);
    h.insertNode(50);
    h.insertNode(35);
    h.insertNode(70);
    h.print();
    h.deleteNode();
    h.print();

    // int arr[] = {-1, 50, 55, 53, 52, 54};
    int arr[] = {-1, 35, 50, 20, 90, 70};


    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout <<" Print Sorted Array using Heap " << endl;
    heapSort(arr, n);
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    cout << "Custom Comparator: --------------------------------------------------- " << endl;
    // Define the priority queue with the custom comparator
    std::priority_queue<int, std::vector<int>, CompareSumOfDigits> pq;

    // Push some numbers into the priority queue
    pq.push(12);  // Sum of digits = 1 + 2 = 3
    pq.push(34);  // Sum of digits = 3 + 4 = 7
    pq.push(5);   // Sum of digits = 5
    pq.push(76);  // Sum of digits = 7 + 6 = 13

    // Pop elements from the priority queue and print them
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        std::cout << top << " (Sum of digits: " << sum_of_digits(top) << ")\n";
    }

    return 0;

}


/*
TO USE Heapify in C++

#include<queue>
priority_queue<int> maxHeap ; // maxHeap

priority_queu<int, vector<int>, greater<int>> minHeap; // min Heap Declaration

*/