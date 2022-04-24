#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string str;
    
    getline(cin, str);
    
    stringstream ss(str);
    
    char ch;
    int temp;
    vector<int> pInt;
    
    while (str.length() > ss.tellg())
    {
        ss >> temp >> ch;
        pInt.push_back(temp);
        cout << temp << endl;
    }
    return 0;
}
