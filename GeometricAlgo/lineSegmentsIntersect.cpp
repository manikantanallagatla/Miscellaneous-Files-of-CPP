#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct Point{
    int x,y;
};
int sign(int a){
    if(a>0){
        return 1;
    }
    if(a<0){
        return -1;
    }
    return 0;
}
bool doIntersect(Point p1,Point q1,Point p2,Point q2){
    int a1 = (q1.x-p1.x)*(p2.y-p1.y) - (q1.y-p1.y)*(p2.x-p1.x);
    int a2 = (q1.x-p1.x)*(q2.y-p1.y) - (q1.y-p1.y)*(q2.x-p1.x);
    if(sign(a1) == sign(a2)){
        return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    struct Point p1 = {1, 1}, q1 = {10, 1};
    struct Point p2 = {1, 2}, q2 = {10, 2};

    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    return 0;
}

