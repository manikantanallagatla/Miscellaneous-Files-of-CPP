#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 3
#define N 3
using namespace std;
string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary)/sizeof(dictionary[0]);
map<string,int>dict;
int x[] = {0,0,1,-1,1,1,-1,-1};
int y[] = {1,-1,0,0,1,-1,-1,1};

bool isValid(int i,int j){
    if(i>=0 and i<M and j>=0 and j<N){
        return 1;
    }
    return 0;
}
bool isWord(string &str)
{
    // Linearly search all words
    for (int i=0; i<n; i++)
        if (str.compare(dictionary[i]) == 0)
          return true;
    return false;
}
void findWordsUtil(char boggle[M][N],int i,int j,string str,bool visited[M][N]){
    str = str+boggle[i][j];
    //cout<<str<<endl;

    visited[i][j] = 1;
    if (isWord(str))
        cout << str << endl;
    for(int k = 0;k<8;k++){
        int i_new = i+x[k];
        int j_new = j+y[k];

        if(isValid(i_new,j_new) ==1 and visited[i_new][j_new] == 0){
            findWordsUtil(boggle,i_new,j_new,str,visited);
        }
    }
    visited[i][j] = 0;
    str.erase(str.length()-1);
}
void findWords(char boggle[M][N]){
    string str = "";
    for(int i = 0;i<n;i++){
        dict[dictionary[i]] = 1;
    }
    bool visited[M][N];
    memset(visited,0,sizeof(visited));

    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){

                memset(visited,0,sizeof(visited));
                str = "";
            findWordsUtil(boggle,i,j,str,visited);
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};

    cout << "Following words of dictionary are present\n";
    findWords(boggle);
    return 0;
}



