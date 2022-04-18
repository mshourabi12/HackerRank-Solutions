#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, k, i, j, temp;
    
    scanf("%d %d\n", &n, &q);
    
    vector<int> *a[n];
    
    // recording the n subsequent lines
    for(int idx1 = 0; idx1 < n ; idx1++)
    {
        a[idx1] = new vector<int>();
        
        scanf("%d ", &k);
        
        for(int idx2 = 0; idx2 < k; idx2++)
        {
            scanf("%d ", &temp);
            
            a[idx1]->push_back(temp);
        }
    }
    
    // parsing the queries
    for(int idx = 0; idx < q; idx++)
    {
        scanf("%d %d", &i, &j);
        
        printf("%d\n",(* a[i])[j]);
    }
    return 0;
}
