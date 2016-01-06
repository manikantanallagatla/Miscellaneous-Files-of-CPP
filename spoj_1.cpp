#include <iostream>
#define ll long long int 
using namespace std;

int main() {
	ll t;
	cin>>t;
	ll n,inter;
	int index = 0;
	while(t--){
	    cin>>n>>inter;
	    int se[n+1] = {0};
	    int a,b;
	    int flag = 0;
	    for(int i = 0;i<inter and flag == 0;i++){
	        cin>>a>>b;
	       // a--;b--;
	        if(se[a] == 0 and se[b] == 0){
	            se[a] = 1;
	            se[b] = 2;
	            continue;
	        }
	        if(se[a]!=0 and se[b] == 0){
	            if(se[a] == 1){
	                se[b] = 2;
	            }
	            else{
	                se[b] = 1;
	            }
	            continue;
	        }
	        if(se[b]!=0 and se[a] == 0){
	            if(se[b] == 1){
	                se[a] = 2;
	            }
	            else{
	                se[a] = 1;
	            }
	            continue;
	        }
	        if(se[a]!=0 and se[b]!=0){
	            if(se[a] == se[b]){
	                cout<<"Scenario #"<<index<<":"<<endl;
	                index++;
	                cout<<"Suspicious bugs found!"<<endl;
	                flag = 1;
	               /* for(int i = 0;i<=n;i++){
	                    cout<<se[i]<<" ";
	                }*/
	            }
	        }
	    }
	    if(flag == 0){
	        cout<<"Scenario #"<<index<<":"<<endl;
	        index++;
	    cout<<"No suspicious bugs found!"<<endl;
	    /*for(int i = 0;i<=n;i++){
	                    cout<<se[i]<<" ";
	                }*/}
	}
	return 0;
}

