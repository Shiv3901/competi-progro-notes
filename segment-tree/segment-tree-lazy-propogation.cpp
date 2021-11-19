#include <bits/stdc++.h>

using namespace std;

// code for segment tree with lazy propogation

#define N 5 * 1e6
#define ll long long int 

vector<ll> tree(2 * N, 0);
vector<ll> lazy(2 * N, 0);

int n;

/*
    si -> index of the current node in the segment tree
    ss and se -> starting and ending indexes of elements for which current nodes stores the sum
    us and ue -> starting and ending indexes of the update query
    diff -> which we need to add in the range us to ue

*/
void updateRangeUtil(int si, int ss, int se, int us, int ue, ll diff) 
{

    if (lazy[si] != 0) {

        tree[si] += (se - ss + 1) * lazy[si];

        if (ss != se) 
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }

        lazy[si] = 0;
 
    }

    if (ss > se || ss > ue || se < us) return; // out of range

    // current segment is fully in range
    if (ss >= us && se <= ue) 
    {
        tree[si] += (se - ss + 1) * diff;

        if (ss != se) 
        {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    int mid = (ss + se) / 2;

    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];


}

void updateRange(int n, int us, int ue, ll diff) 
{
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

// get the range query answer
ll getSumUtil(int ss, int se, int qs, int qe, int si) 
{
    if (lazy[si] != 0) {

        tree[si] += (se - ss + 1) * lazy[si];

        if (ss != se) 
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }

        lazy[si] = 0;
 
    }

    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss >= qs && se <= qe) return tree[si]; // the entire segment lies in the range

    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, si * 2 + 1) + getSumUtil(mid+1, se, qs, qe, si * 2 + 2);

}

ll getSum(int n, int qs, int qe) 
{
    return getSumUtil(0, n-1, qs, qe, 0);
}

// recursive function to construct the segment tree
void constructSTUtil(vector<ll> vec, int ss, int se, int si) 
{
    if (ss > se) return;

    if (ss == se) 
    {
        tree[si] = vec[ss];
        return;
    }

    int mid = (ss + se) / 2;
    constructSTUtil(vec, ss, mid, si * 2 + 1);
    constructSTUtil(vec, mid + 1, se, si * 2 + 2);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];

}

void constructST(vector<ll> vec, int n) 
{
    constructSTUtil(vec, 0, n-1, 0);
}

// driver program
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ; cin >> t;

    n = (1 << 8);

    vector<ll> ans;

    for (int i = 0 ; i < t ; i++) {
    
        char test; cin >> test;

        if (test == 'C') 
        {
            int idx; cin >> idx;
            ans.push_back(getSum(n, idx, idx));
        }    
        else 
        {
            int st, ed, r ; cin >> st >> ed >> r;
            updateRange(n, st, ed, r);
        }

    }

    for (auto a : ans)
        cout << a << '\n';

    return 0;

}