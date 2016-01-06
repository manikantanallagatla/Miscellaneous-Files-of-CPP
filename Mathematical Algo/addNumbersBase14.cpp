#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
int char2Num(char x){
    switch(x){
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    }
}
string num2Char14(int result){
    switch(result){
    case 0:
        return "00";
    case 1:
        return "01";
    case 2:
        return "02";
    case 3:
        return "03";
    case 4:
        return "04";
    case 5:
        return "05";
    case 6:
        return "06";
    case 7:
        return "07";
    case 8:
        return "08";
    case 9:
        return "09";
    case 10:
        return "0A";
    case 11:
        return "0B";
    case 12:
        return "0C";
    case 13:
        return "0D";
    }
}
string num2Char(int result){
    if(result<14){
        return num2Char14(result);
    }
    //cout<<result<<endl;
    int first = 1;
    int second = result-14;
    string answer = "1";
    string temp = num2Char14(second);
    answer = answer+temp[1];
    cout<<"Answer is "<<answer<<endl;
    return answer;
}
string add2Num(char x,char y,char z){
    string temp = "";
    int xNum = char2Num(x);
    int yNum = char2Num(y);
    int zNum = char2Num(z);
    int result = xNum+yNum+zNum;
    //cout<<result<<endl;
    return num2Char(result);
}
string add(string first,string second){
    int size = first.length();
    //cout<<size<<endl;
    string answer = "";
    char third = '0';
    for(int i = size-1;i>=0;i--){
        //cout<<answer<<endl;
        string temp = add2Num(first[i],second[i],third);
        //cout<<temp<<endl;
        answer = temp[1]+answer;
        third = temp[0];
    }
    return answer;
}
string sumBase14(char *num1,char *num2){
    int m = strlen(num1);
    int n = strlen(num2);
    if(m<=n){
        string first;
        string second;
        for(int i = 0;i<n;i++){
            second += num2[i];
        }
        for(int i = 0;i<(n-m);i++){
            first += '0';
        }
        for(int i = 0;i<m;i++){
            first += num1[i];
        }
        cout<<first<<" "<<second<<endl;
        //cout<<"Until Here Executed!"<<endl;
        return add(first,second);
    }else{
        string first;
        string second;
        for(int i = 0;i<m;i++){
            first += num1[i];
        }
        for(int i = 0;i<(m-n);i++){
            second += '0';
        }
        for(int i = 0;i<n;i++){
            second += num2[i];
        }
        cout<<first<<" "<<second<<endl;
        //cout<<"Until Here Executed!"<<endl;
        return add(first,second);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    char *num1 = "C";
    char *num2 = "3";
    sumBase14(num1,num2);
    //printf("Result is %s", sumBase14(num1, num2));
    return 0;
}

