#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
unsigned getNthUglyNo(unsigned n){
    unsigned ugly[151];
    ugly[0] = 1;
    unsigned i2(0),i3(0),i5(0);
    unsigned next_2 = ugly[i2]*2;
    unsigned next_3 = ugly[i3]*3;
    unsigned next_5 = ugly[i5]*5;
    for(int i = 1;i<=150;i++){
        unsigned next_ugly = min(next_2,min(next_3,next_5));
        if(next_ugly == next_2){
            i2++;
            next_2 = ugly[i2]*2;
        }
        if  (next_ugly  == next_3)
    {
        i3 = i3 + 1;
        next_3 = ugly[i3]*3;
     }
     if  (next_ugly  == next_5)
     {
        i5 = i5 + 1;
        next_5 = ugly[i5]*5;
     }
     ugly[i] =  next_ugly;
    }
    return ugly[150];
}
int main(){
    ios_base::sync_with_stdio(false);
    unsigned no = getNthUglyNo(150);
    printf("%dth ugly no. is %d ", 150, no);
    return 0;
}
