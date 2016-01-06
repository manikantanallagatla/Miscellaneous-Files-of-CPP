#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> result;
vector<char> str;
void permute(string s,int size,int k){
    if(k == 0){
        for(int i = 0;i<result.size();i++){
            cout<<result[i];
        }
        cout<<endl;
    }
    for(int i = 0;i<size-k;i++){
        result.push_back(s[i]);
        permute(s,size,k-1);
        result.pop_back();
    }
}
int main(){
    string s;
    cin>>s;
    int size = s.length();
    for(int i = 0;i<size;i++){
        str.push_back(s[i]);
    }
    int k;
    cin>>k;
    permute(s,size,k);

}