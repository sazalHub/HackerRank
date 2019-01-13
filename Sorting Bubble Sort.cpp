#include <bits/stdc++.h>
using namespace std;

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int swaps = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
    }

    printf("Array is sorted in %d swaps.\n",swaps);
    printf("First Element: %d\n",a[0]);
    printf("Last Element: %d\n",a[n-1]);
}

int main(){
    int n;
    vector<int>a;

    cin >> n;
    a.resize(n);

    for (int i=0;i<n;i++) scanf("%d",&a[i]);

    countSwaps(a);

    return 0;
}


