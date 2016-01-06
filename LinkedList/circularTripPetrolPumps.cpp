#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct petrolPump{
    int petrol,distance;
};
int printTour(petrolPump arr[],int n){
    int start = 0;
    int end = 1;
    int curr_petrol = arr[start].petrol - arr[start].distance;
    //try with and
    while(start!=end or curr_petrol<0){
        while(curr_petrol<0 and start!=end){
            curr_petrol -= (arr[start].petrol - arr[start].distance);
            start = (start+1)%n;
            if(start == 0){
                return -1;
            }
        }
        curr_petrol += (arr[end].petrol - arr[end].distance);
        end = (end+1)%n;
    }
    return start;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1)? printf("No solution"): printf("Start = %d", start);

    return 0;
}

