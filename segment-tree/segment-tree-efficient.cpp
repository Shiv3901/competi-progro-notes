#include <bits/stdc++.h>

using namespace std;

// code for more efficient segment tree

// limiting the array size for now
const int N = 100000;

int n; // the given size of the array

// max size for the tree 
vector<int> tree(2 * N, 0);

// function to build the tree
void build( vector<int> arr )
{
    // insert leaf nodes in the tree
    for (int i = 0 ; i < n ; i++)
        tree[n + i] = arr[i];

    // build the tree by calculating parents
    for (int i = n - 1 ; i > 0 ; --i)
        tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

// function to update a tree node
void updateTreeNode(int p, int val) 
{

    // set value at position p
    tree[p+n] = val;
    p = p + n;

    // move upward and update the parents
    for (int i = p ; i > 1 ; i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];

}

// function to get sum on interval [left, right]
int query(int l, int r)
{

    int res = 0;

    // loop to find the sum in the range
    for (l += n, r += n ; l < r ; l >>= 1, r >>= 1)
    {

        if (l & l) res += tree[l++];
        if (r & l) res += tree[--r];

    }

    return res;

}


// driver program
int main() 
{
    vector<int> a {1, 2, 3, 4, 5, 6, 7, 8};

    int ri = ffs(a.size()) + 2;

    for (int i = 0 ; i < (1 << ri) ; i++)
        a.push_back(0);

    n = a.size();

    // cout << ri << " " << (1 << ri) << endl;

    build(a);

    cout << query(1, 3) << '\n';

    updateTreeNode(2, 1);

    cout << query(1, 3) << '\n';

    return 0;

}





