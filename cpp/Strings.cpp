#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string a, b;
    
    getline(cin, a);
    getline(cin, b);
    
    cout << a.length() << " " << b.length() << endl;
    cout << a+b << endl;
    cout << b[0] + a.substr(1) << " " << a[0] + b.substr(1) << endl;
    
    return 0;
}
