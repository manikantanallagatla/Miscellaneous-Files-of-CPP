#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void findCommon(int ar1[],int ar2[],int ar3[],int n1,int n2,int n3){
    int index1 =0;
    int index2 =0;
    int index3 =0;
    cout<<"Common ELements are:"<<endl;
    while(index1<n1 and index2<n2 and index3<n3){
            //cout<<ar1[index1]<<" "<<ar2[index2]<<" "<<ar3[index3]<<endl;
        if(ar1[index1] == ar2[index2] and ar2[index2] == ar3[index3]){
            cout<<ar1[index1]<<" ";
        }
            if(ar1[index1] <= ar2[index2] and ar1[index1] <= ar3[index3]){
            index1++;
        }else{
            if(ar1[index1] >= ar2[index2] and ar2[index2] <= ar3[index3]){
            index2++;
        }else{
            if(ar1[index1] >= ar3[index3] and ar2[index2] >= ar3[index3]){
            index3++;
        }
        }
        }
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
