#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define N 4
using namespace std;
int numberManFree;
bool isManFree(){
    if(numberManFree == 0){
        return 0;
    }
    return 1;
}
int getFreeman(bool isFree[2*N]){
    for(int i = 0;i<N;i++){
        if(isFree[i] == 1){
            return i;
        }
    }
}
int getPreference(int prefer[2*N][N],int womenIndex,int freeMan){
    for(int i= 0;i<N;i++){
        if(prefer[womenIndex][i] == freeMan){
            return i;
        }
    }
    return INT_MAX;
}
void stableMarriage(int prefer[2*N][N]){
    //Man indices are from 0 to N
    //Women indices are from N to 2*N
    bool isFree[2*N];
    int ans[2*N];
    fill(isFree,isFree+2*N,1);
    numberManFree = N;
    while(isManFree() == 1){
        int freeMan = getFreeman(isFree);
        for(int j = 0;j<N;j++){
            int womenIndex = prefer[freeMan][j];
            if(isFree[womenIndex] == 1){
                 isFree[womenIndex] = 0;
                 ans[womenIndex] = freeMan;
                 ans[freeMan] = womenIndex;
                 break;
            }else{
                int currentPartner = ans[womenIndex];
                int preferenceFreeman = getPreference(prefer,womenIndex,freeMan);
                int preferenceCurrentpartner = getPreference(prefer,womenIndex,currentPartner);
                if(preferenceFreeman<preferenceCurrentpartner){
                    isFree[currentPartner] = 1;
                    numberManFree++;
                    ans[womenIndex] = freeMan;
                    isFree[womenIndex] = 0;
                    ans[freeMan] = womenIndex;
                    break;
                }else{

                }
            }

        }
        isFree[freeMan] = 0;
        numberManFree--;
    }
    for(int i = 0;i<2*N;i++){
        cout<<isFree[i]<<" ";
    }cout<<endl;
    for(int i = 0;i<2*N;i++){
        cout<<i<<" ";
    }cout<<endl;
    for(int i = 0;i<2*N;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int prefer[2*N][N] = {
        {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);
    return 0;
}

