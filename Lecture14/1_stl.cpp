#include <iostream>
#include <array>
#include <vector>
using namespace std;
/*
// Array
// Array is static we cannot increase its size when required
int main()
{
    array<int, 7> a = {9, 7, 6, 8, 1, 2, 3};
    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout<< "At position 2 is " << a.at(2) << endl;
    cout<<"is a Empty " << a.empty() << endl;
    cout<<"Front value of a " << a.front() << endl;
    cout<<"Last value of a " << a.back() << endl;
}

*/

/*
Vector

Vector is Dynamic and it's size can increase or decrease according to requirement
Vecotr's capacity Keeps on increasing as we insert more elemtns into it (doubles every time it reaches its capacity)

int main()
{
    vector<int> v;

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(1);

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(2);

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(3);

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(4);

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(5);

    cout << "Capacit of v " << v.capacity() << " and size is " << v.size() << endl;
    v.push_back(6);

    cout << "v at 2 "<< v.at(2) << endl;
    cout<< " Before POP "<<endl;
    for(int i = v.front();i<=v.back();i++){
        cout << i <<"  ";
    }

    v.pop_back();
    cout<< " After POP "<<endl;
    for(int i = v.front();i<=v.back();i++){
        cout << i <<"  ";
    }

    // Different ways of Initialization
    vector<int> a(5,1); // vector of size 5 with all1's
    vector<int> new_vec(a); // new_vec is a vecotr of a




}

*/

/*
Dequeue


#include <deque>
int main()
{
    deque<int> d;
    d.push_back(1),
        d.push_front(0),
        d.push_back(2);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    d.pop_back(); // pop_front

    for (int i : d)
    {
        cout << i << " ";
    }

    cout << " " << endl;
    cout << " Element at 1 is " << d.at(1) << endl;

    // d.empty(), d.size()
    // d.erase(d.begin(), d.begin()+1) helps in erasing the 1st element

}


*/

/*
LIST - normally it is doubly linked list


#include <list>

int main()
{
    list<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_front(0);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    a.erase(a.begin());
    cout << " After Erasing " << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    // a.size(), a.pop_front(), a.pop_back()
}

*/

/*
Stack -


#include <stack>

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl; //(LIFO - Last In First Out)
    //s.empty(), s.top(), s.size()
}

*/

/*
Queue


#include <queue>
int main()
{

    queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);

    // FIFO
    cout << a.front() << endl;

    //a.size(), a.pop(), a.empty(),

}

*/

/*
Priority Queue - so whenever we take element out
- (if it is a Max Heap) it will take maximum element out
- (if it is a Min Heap) it will take minimum element out


#include <queue>
int main()
{
    priority_queue<int> maxheap; // by default it will create Max Heap

    priority_queue<int, vector<int>, greater<int>> minheap; // min heap

    maxheap.push(9);
    maxheap.push(1);
    maxheap.push(11);
    maxheap.push(7);
    maxheap.push(2);
    int n = maxheap.size();
    cout << " Max Heap :- " ;
    for (int i = 0; i < n; i++)
    {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }
    cout << " " << endl;

    minheap.push(9);
    minheap.push(1);
    minheap.push(11);
    minheap.push(7);
    minheap.push(2);
    n = minheap.size();
    cout << " Min Heap :- " ;
    for (int i = 0; i < n; i++)
    {
        cout << minheap.top() << " ";
        minheap.pop();
    }
    cout << " " << endl;

    // maxheap.empty(), minheap.empty(),
}

*/

/*
Set
- It will store only unique elements
- Internal Implementation is based on BST
- output elements will always be in sorted order


#include <set>
int main()
{
    set<int> s;
    s.insert(7);
    s.insert(7);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(9); // O(logn) is time complexity of insertion

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    // deleting 1st element
    s.erase(s.begin());

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    // deleting 2nd element now
    set<int>::iterator it = s.begin(); // assigning itterator so that we can traverse to desired elem position

    s.erase(it);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << " " << endl;

    // to see if element it present or not s.count(element)

    set<int>::iterator itr = s.find(9); // finds the iterator of element

    // cout <<itr << endl;
}
*/

/*
Map -

Search complexity is O(logn) in ordered map because it's implementation is done using red-black tree
Whereas complexity of search in unorderd map is O(1) as it is implemented using Hash Table



#include <map>
int main()
{
    map<int, string> m;
    m[1] = "Ishan";
    m[2] = "Anand";
    m[3] = "Kumar";
    m.insert({6, "Veer"});
    for (auto i : m)
    {
        cout << i.first << "-" << i.second << endl;
    }

    // m.count(9) to check if that ke is present
    // m.erase(10) deleting 10th index and it's value

    //Find element

    auto it = m.find(2);

    for(auto i = it; i != m.end();i++){
        cout << (*i).first<<endl;
    }
}

*/

/*
STL -  Some Algo's
*/

#include <algorithm>
#include <vector>
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
 
    cout << "Binary Search Number 3 " << binary_search(v.begin(), v.end(), 3) << endl;
    // lower_bound(), upper_bound(), max(), min(), swap(), reverse(string.begin(), string.end())
    // rotate(v.begin(), rotate_pointer,v.end())
    // sort(v.begin(), v.end()) --> based on intro sort (quick sort, heap sort, insertion sort)
    // 


}