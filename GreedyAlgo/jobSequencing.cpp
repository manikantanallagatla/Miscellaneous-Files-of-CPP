#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
struct job{
    char id;
    int deadline;
    int profit;
};
bool comparision(job a,job b){
    return (a.profit>b.profit);
}
void printJobScheduling(job arr[], int n){
    sort(arr,arr+n,comparision);
    int presentTime = 0;
    int profit = 0;
    vector<char> sequence;
    for(int i = 0;i<n;i++){
        presentTime++;
        if(arr[i].deadline>=presentTime){
            profit+=arr[i].profit;
            sequence.push_back(arr[i].id);
        }else{
            presentTime--;
        }
    }
    cout<<"Maximum profit attainable is "<<profit<<endl;
    cout<<"This is the sequence ";
    for(int i = 0;i<sequence.size();i++){
        cout<<sequence[i]<<" ";
    }cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    job arr[5] = { {'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40},
                   {'d', 1, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;
}
