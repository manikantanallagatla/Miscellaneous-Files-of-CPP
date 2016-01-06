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
    int size,sheep;
    int try1 = 0;
    cin>>size;
    int a[size];
    for(int i = 0;i<size;i++){
        cin>>a[i];
    }

    for(int i = 0;i<size;i++){
        try1 = 0;
        for(int j = i ;j<size;j++){
            if(a[i] == a[j]){
                try1 = 0;
                 //continue;
            }
            if(j ==(size-1)){
                if(try1 == 1){
                    sheep = a [i];
                }
            }
        }
    }

    cout<<sheep;

    return 0;
}
