#include <iostream>
using namespace std;

int main() {
	int budget,parties;cin>>budget>>parties;
	while(parties!=0 and budget!=0){
	    
	    int array[parties][2];
	    int going[parties];
	    for(int i = 0;i<parties;i++){
	        for(int j = 0;j<2;j++){
	            cin>>array[i][j];
	        }
	    }
	    for(int i = 0;i<parties;i++){
	        //for(int j = 0;j<2;j++){
	            going[i] = 0;
	    }
	    double division[parties];
	    for(int i = 0;i<parties;i++){
	        division[i] = (array[i][1]+0.0)/(0.0+array[i][0]);
	    }
	    int budgetPlanning = 0;int satisfaction = 0;int flag = 1;
	    while(budgetPlanning<=budget and flag ==1){
	        double max = 0;int index = 0;
	        for(int i = 0;i<parties;i++){
	            if(going[i]==0){
	                if(max<division[i]){
	                    max = division[i];index = i;
	                }
	            }
	        }
	        if((budget - budgetPlanning) >=array[index][0]){
	            budgetPlanning+=array[index][0];
	            going[index] = 1;
	            satisfaction+=array[index][1];
	        }else{
	            going[index] = 1;
	        }
	        int everything = 1;
	        for(int i = 0;i<parties and everything == 1;i++){
	            if(going[i] == 0){
	                everything = 0;
	            }
	        }
	        if(everything == 1){
	            flag = 0;
	        }else{
	            flag = 1;
	        }
	    }
	    cout<<budgetPlanning<<" "<<satisfaction<<endl;
	    cin>>budget>>parties;
	}
	return 0;
}

