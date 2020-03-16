#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int main() {
    oset os; // ordered_set
    os.insert(10);
    os.insert(20);
    os.insert(30);
    os.insert(40);
    os.insert(50);
    cout << os.size() << endl; // size : 5
    cout << os.order_of_key(25) << endl; // the number of elements<25 : 2
    cout << os.order_of_key(30) << endl; // the number of elemnets<30 : 2
    
    auto it = os.find_by_order(2);
    cout << *it << endl; // 2nd element : 30
    os.erase(it); // delete 2nd element
    cout << os.size() << endl; // size : 4
    cout << *os.find_by_order(2) << endl; // 2nd element: 40
}
