#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int size,sheep = 0;
    int try1 = 0;
    cin>>size;
    int a[size];
    for(int i = 0;i<size;i++){
        cin>>a[i];
    }

    for(int i = 0;i<size;i++){
        try1 = 0;
        cout <<" i = "<<i;
        for(int j = i ;j<size;j++){
        	cout <<" j = "<<j;
            if(a[i] == a[j]){
                try1 = 1;
                cout<<"i = j";
                 continue;
            }
            if(j == (size-1)){
                if(try1 == 0){
                	cout<<"sheep = a[i]";
                    sheep = a [i];
                }
            }
        }
    }

    cout<<sheep;

    return 0;
}
