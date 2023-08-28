#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int mid)
{

    int l_size = mid - l + 1;
    int r_size = r - mid;

    int L[l_size];
    int R[r_size];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = nums[i];
    }
    
    L[l_size] = INT_MAX;
    R[r_size] = INT_MAX;

    int lp = 0;
    int rp = 0;

    for(int i = l; i <= r; i++){
        if(L[lp] <= R[rp]){
            nums[i] = L[lp];
            lp++;
        }
        else{
            nums[i] = R[rp];
            rp++;
        }
    }
}

void merge_sort(int l, int r)
{
    if (l == r)
    {
        return;
    }

    int mid = (l + r) / 2;

    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    merge(l, r, mid);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
