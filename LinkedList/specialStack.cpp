#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct SpecialStack{
    stack<int> original;
    stack<int> auxiliary;
    static const int max = 100;
};
void push(SpecialStack *obj,int data){
    (obj->original).push(data);
    if((obj->auxiliary).empty() == 0){
        if(data<=(obj->auxiliary).top()){
            (obj->auxiliary).push(data);
        }else{

        }
    }else{
        (obj->auxiliary).push(data);
    }
}
void pop(SpecialStack *obj){
    if(obj->original.empty() == 1){

    }else{
        int dummy = obj->original.top();
        obj->original.pop();
        if(obj->auxiliary.top() == dummy){
            obj->auxiliary.pop();
        }else{

        }
    }
}
bool isEmpty(SpecialStack *obj){
    return obj->original.empty();
}
bool isFull(SpecialStack *obj){
    if(obj->original.size() == obj->max){
        return 1;
    }
    return 0;
}
int getMin(SpecialStack *obj){
    return obj->auxiliary.top();
}
int main(){
    ios_base::sync_with_stdio(false);
    SpecialStack *s = new SpecialStack;
    push(s,10);
    pop(s);
    push(s,20);
    push(s,30);

    cout<<getMin(s)<<endl;

    push(s,5);
    cout<<getMin(s);
    return 0;
}
