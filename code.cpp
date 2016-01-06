#include <iostream>
#include<string>
#include<limits.h>
using namespace std;
int compute(string a,string b,bool &isPossible){
    int length = a.length();
    int steps = 0;
    int switches = 0;int present = -1;char lane;
    if(a[0] == '#' and b[0] == '#'){
        isPossible = false;
        return INT_MAX;
    }else{
        if(a[0] == '.'){
            lane = 'a';
            present = 0;
            steps++;
        }else{
            lane = 'b';
            present = 0;
            steps++;
        }
    }
    while(steps != length){
        if(lane == 'a'){
            if(a[present+1] == '.'){
                present++;steps++;
            }else{
                if(b[present+1] == '.'){
                    present++;steps++;switches++;lane = 'b';
                }else{
                    if(b[present] == '.'){
                        switches++;lane = 'b';
                    }else{
                        isPossible = false;
                        return INT_MAX;
                    }
                }
            }
        }else{
            if(b[present+1] == '.'){
                present++;steps++;
            }else{
                if(a[present+1] == '.'){
                    present++;steps++;switches++;lane = 'a';
                }else{
                    if(a[present] == '.'){
                        switches++;lane = 'a';
                    }else{
                        isPossible = false;
                        return 0;
                    }
                }
            }
        }
    }
    isPossible = true;
    return switches;
}
int main() {
	int t;
	string a,b;
	cin>>t;
	while(t--){
	    cin>>a>>b;bool isPossible1,isPossible2;//Need to update for minimum steps by selecting btw initial step
	    int switches1 = compute(a,b,isPossible1);
	    int switches2 = compute(b,a,isPossible2);
	    if(isPossible1 == true or isPossible2 == true){
        cout<<"Yes"<<endl;
        cout<<min(switches1,switches2)<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
