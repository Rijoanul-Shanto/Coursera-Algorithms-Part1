// Rijoanul Hasan
// Path Compression
#include <bits/stdc++.h>
#define FIN freopen("in.txt", "rt", stdin)
#define MAX 1000000
#define endl '\n'
using namespace std;

int arr[MAX];
int weight[MAX];

int root(int n)
{
    // Making the root of all node on the way to root to root
    if(n != arr[n])
    {
        arr[n] = root(arr[n]);
    }
    return arr[n];
}

void union_UF(int p, int q)
{
    int rootp = root(p);
    int rootq = root(q);

    // If both node have same root
    if(rootp == rootq) return;

    // If weight of node p is equal to node q
    if(weight[p] == weight[q])
    {
        if(rootp < rootq)
        {
            arr[rootp] = rootq;
            weight[rootq] += weight[rootp];
        }
        else
        {
            arr[rootq] = rootp;
            weight[rootp] += weight[rootq];
        }
    }

    // If weight of node p is less than node q
    if(weight[p] < weight[q])
    {
        arr[p] = q;
        weight[q] += weight[p];
    }
    // If weight of node q is less than node p
    else
    {
        arr[q] = p;
        weight[p] += weight[q];
    }

    /*
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    */
}

bool find_UF(int p, int q)
{
    return (root(p) == root(q));
}

int main()
{
    FIN;

    memset(weight, 1, sizeof weight);

    int n, op, p, q;
    char c;
    bool res;
    // Number of maximum objects
    cin >> n;

    for(int i = 0; i < n; i++) arr[i] = i;

    // Number of operations
    cin >> op;

    while(op--)
    {
        cin >> c >> p >> q;

        if(c == 'U') union_UF(p, q);
        else
        {
            res = find_UF(p, q);
            if(res) cout << p << ' ' << q << " Connected" << endl;
            else cout << p << ' ' << q << " Not Connected" << endl;
        }
    }

    return 0;
}
