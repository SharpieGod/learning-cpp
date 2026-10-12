#include <bits/stdc++.h> // every library

using namespace std;

void print() { cout << "darko"; }

int sum(int a, int b) { return a + b; }

void explainPair() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n"; // 1 3

    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << p2.first << " " << p2.second.second << "\n"; // 1 4

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second << "\n";
}

void explainVector() {
    // vector<int> v;
    // // same as Vector in rust.
    // // sized dynamically

    // v.push_back(1);
    // v.emplace_back(2);

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> intv(5, 100); // {100, 100, 100, 100, 100}

    vector<int> v1(5, 20); // {20,20,20,20,20}
    vector<int> v2(v1);

    vector<int> v = {20, 10, 15, 6, 7};

    vector<int>::iterator it = v.begin();

    // iterators are literal pointers :sob:

    it++;
    cout << *(it) << " "; // prints 10

    it += 2;
    cout << *(it) << " "; // prints 6

    v.end();    // points to address after the last element
    v.rend();   // points to address before the first element
    v.rbegin(); // points to address of last element
    // it++ would move reverse order

    cout << v.back() << " "; // last element

    cout << "\n";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    for (auto n : v) { // kinda like foreach
        cout << n << " ";
    }

    v.erase(v.begin() + 1); // erases the second element O(n)

    vector<int> cp(2, 50);

    v.insert(v.begin(), cp.begin(),
             cp.end()); // inserts elements of this into vector s tart

    v.pop_back(); // just like .pop()
    v.swap(v2);   // swaps vector
    v.clear();    // erases vector;
    v.empty();    // is it empty?
}

void explainList() {
    list<int> ls;
    // Front operations as well.
    // Doubly linked list.

    ls.push_back(2);
    ls.push_front(5);

    // rest same as vector
}

void explainDeque() {
    deque<int> dq; // just has some extra pointers for start and end
}

void explainStack() {
    stack<int> st; // LIFO Last In First Out
    // Has no indicies

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top();

    st.pop(); // pop doesnt return anything.
    // O(1)
}

void explainQueue() {
    queue<int> q;
    // FIFO First In First Out

    q.push(1);
    q.push(2);
    q.emplace(4);
}

void explainPQ() {
    priority_queue<int> pq;
    // This is like a MaxHeap

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);

    // Insertion is O(log n)

    // Minimum heap?

    priority_queue<int, vector<int>, greater<int>> mh;
}

void explainSet() {
    set<int> st;
    // sorted, no duplicates
    st.insert(1);
    st.insert(4);

    st.insert(2);
    st.insert(1);

    auto it = st.find(4); // returns pointer to 4;

    auto it2 = st.find(6); // if not in set, returns set.end()
}

void explainMS() {
    multiset<int> ms;
    // Sorted, but allows duplicates
    // Fully traversable, while PQ only stores top
}

int main() {
    // print();
    // cout << sum(1, 4);

    explainList();

    return 0;
}
