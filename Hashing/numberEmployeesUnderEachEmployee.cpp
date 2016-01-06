#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
map<string, int> dataSet;
void insert(string x,string y){
    if(dataSet[x]==0){
        cout<<x<<" "<<0<<endl;
        dataSet[y]++;
    }else{
        if(x == y){
            int sum = 0;
                map<string, int> ::iterator it = dataSet.begin();
                while(it!=dataSet.end()){
                        if(it->second!=0 and it->first!=x){
                    sum++;
                    sum+=it->second;}
                    it++;
                }
                cout<<x<<" "<<sum<<endl;
                dataSet[y] = sum;
        }else{
        cout<<x<<" "<<dataSet[x]<<endl;
        dataSet[y]+=dataSet[x];}
    }
}
int main(){
    ios_base::sync_with_stdio(false);
// = new HashMap<String, String>();

        insert("A", "C");
        insert("B", "C");
        insert("C", "F");
        insert("D", "E");
        insert("E", "F");
        insert("F", "F");

        //populateResult(dataSet);
        //System.out.println("result = " + result);
    return 0;
}

