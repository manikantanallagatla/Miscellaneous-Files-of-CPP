#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printResult(map<string,string> dataset){
    map<string,string> dataset2;
    map<string,string> :: iterator it = dataset.begin();
    while(it!= dataset.end()){
        dataset2[it->second] = it->first;
        it++;
    }
    bool foundStartingPoint = 0;
    string answer;
    it = dataset.begin();
    while(foundStartingPoint == 0 and it!=dataset.end()){
        if(dataset2[it->first]!=""){

        }else{
            answer = it->first;
            foundStartingPoint = 1;
        }
        it++;
    }
    if(foundStartingPoint ==1){
        while(dataset[answer] !=""){
            cout<<answer<<"->"<<dataset[answer]<<", ";
            answer = dataset[answer];
        }cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    map<string, string> dataSet;// = new HashMap<String, String>();
    dataSet["Chennai"] = "Bangalore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";
    printResult(dataSet);
    return 0;
}

