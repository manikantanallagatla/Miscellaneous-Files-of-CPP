#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct interval{
    int buy;
    int sell;
};
void stockBuySell(int price[],int n){
    if(n==1){
        return;
    }
    int count = 0;
    interval sol[n/2];
    int i = 0;
    while(i<(n-1)){
        while(i<(n-1) and price[i]>=price[i+1]){
            i++;
        }
        if(i == n-1){
            break;
        }
        sol[count].buy = i++;
        while(i<n and price[i]<=price[i+1]){
            i++;
        }
        sol[count].sell = i-1;
        count++;
    }
    if(count == 0){
        printf("There is no day when buying the stock will make profit\n");
    }else{
        for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", sol[i].buy, sol[i].sell);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    // stock prices on consecutive days
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);

    // fucntion call
    stockBuySell(price, n);
    return 0;
}

