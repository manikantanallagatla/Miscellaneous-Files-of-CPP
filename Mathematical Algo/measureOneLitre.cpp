#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct Vessel{
    int capacity;
    int current;
};
void makeOneLitre(Vessel V1,Vessel V2){
        V1.current = 0;
        V2.current = 0;
        while(V1.current!=1){
//            count++;
                //0
            if(V1.current == 0){
                V1.current = V1.capacity;
            }
        cout<<"Vessel 1: "<<V1.current<<" Vessel 2: "<<V2.current<<endl;//
            if((V2.current + V1.current)<V2.capacity){
                V2.current = (V2.current + V1.current);
                V1.current = 0;
            }else{
               if((V2.current + V1.current)==V2.capacity){
                V2.current = 0;//(V2.current + V1.current);
                V1.current = 0;
            } else{
                if((V2.current + V1.current)>V2.capacity){
                //(V2.current + V1.current);
                V1.current = (V2.current + V1.current)-V2.capacity;V2.current = 0;
            }
            }
            }
        }
        cout<<"Until Here executed!"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int a = 3, b = 7;  // a must be smaller than b

    // Create two vessels of capacities a and b
    Vessel V1;
    Vessel V2;
    if(a<b){
        V1.capacity = a;
        V2.capacity = b;
        makeOneLitre(V1,V2);
    }else{
        V1.capacity = b;
        V2.capacity = a;
        makeOneLitre(V2,V1);

    }
    // Get 1 litre in first vessel
//    V1.makeOneLitre(V2);
    return 0;
}

