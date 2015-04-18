#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int nbCases;
    cin>>nbCases;
    
    while (nbCases--) {
        string myString;
        cin>>myString;

        int i;
        for (i = myString.size()-1; i > 0 ;--i)
        {           
            if (myString[i] > myString[i-1]) {
                myString.push_back(myString[i-1]);
                myString.erase(i-1, 1);
                break;
            }
        }
        
        if (i==0) cout<<"no answer"<<endl;
        else cout<<myString<<endl;
    }
    return 0;
}

