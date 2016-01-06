#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    char c;
    char array[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>array[i][j];
        }
    }
    int flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(array[i][j]=='E'){
                    int k,p = 0;
                for(k;k<n;k++){
                    if(array[k][j]=='L'){
                        break;
                    }
                }
                if(k==(n-1)){
                    for(p;p<m;p++){
                        if(array[i][k]=='L'){
                            break;
                        }
                    }
            if(p==(m-1)){
                flag = 1;
                i = n-1;
                j = m-1;
            }
                }
            }
        }
    }
    if(flag == 0){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }


    return 0;
}
