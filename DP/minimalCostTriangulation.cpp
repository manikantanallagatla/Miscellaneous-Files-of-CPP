#include<bits/stdc++.h>
#include<math.h>
#define MAX 1000000.0
#define ll long long int
using namespace std;
struct Point{
    int x,y;
};
double dist(Point p1,Point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
double cost(Point points[],int i,int j,int k){
    Point p1 = points[i];
    Point p2 = points[j];
    Point p3 = points[k];
    return dist(p1,p2)+dist(p2,p3)+dist(p3,p1);
}
double mTCDP(Point points[], int n){
    if(n<3){
        return 0;
    }
    double table[n][n];
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n-k;i++){
            int j = i+k;
            if(j<i+2){
                table[i][j] = 0.0;
            }else{
                table[i][j] = MAX;
                for(int dummy = i+1;dummy<j;dummy++){
                    double val = table[i][dummy]+table[dummy][j]+cost(points,i,j,dummy);
                    if(val<table[i][j]){
                        table[i][j] = val;
                    }
                }
            }
        }
    }
    return table[0][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = sizeof(points)/sizeof(points[0]);
    cout << mTCDP(points, n);
    return 0;
}
