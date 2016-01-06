#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int getMedian(int ar1[], int ar2[], int n){
    sort(ar1,ar1+n);
    sort(ar2,ar2+n);
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    while(index<n-1 and index1<n and index2<n){
        if(ar1[index1]<ar2[index2]){
            index1++;
            index++;
        }else{
            if(ar1[index1] == ar2[index2]){
                index1++;
                index++;
            }else{
                index2++;
                index++;
            }
        }
    }
    while(index<n-1 and index1<n){
        index1++;
        index++;
    }
    while(index<n-1 and index2<n){
        index2++;
        index++;
    }
    if(index1<n and index2<n){

        return (ar1[index1]+ar2[index2])/2;
    }
    if(index1<n){

        return (ar1[index1]+ar1[index1+1])/2;
    }

    return (ar2[index2]+ar2[index2+1])/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    int ar1[] =  { 12, 11, 15, 10, 20 };
    int ar2[] = { 10, 11, 12, 15, 20 };

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}
