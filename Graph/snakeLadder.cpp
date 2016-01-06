#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};
int getMinDiceThrows(int move[],int N){
    bool visited[N];
    memset(visited,0,sizeof(visited));
    queue<queueEntry> q;
    visited[0] = 1;
    queueEntry s = {0,0};
    q.push(s);
    queueEntry qe;
    while(q.empty() == false){
        qe = q.front();
        int v = qe.v;
        if(v == N-1){
            break;
        }
        q.pop();
        for(int j = v+1;j<=(v+6) and j<N;j++){
            if(visited[j] == 0){
                queueEntry a;
                a.dist = qe.dist+1;
                visited[j] = 1;
                if(move[j]!=-1){
                    a.v = move[j];
                }else{
                    a.v = j;
                }
                q.push(a);
            }
        }
    }
    return qe.dist;
}
int main(){
    ios_base::sync_with_stdio(false);
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
}

