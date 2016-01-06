#include<iostream>
using namespace std;
class bank{
private:
    int balance,accountNo;
    string name,type;
public:
    void enterData(void){
        cout<<"enter name of person";
        cin>>name;
        cout<<"enter type of account";
        cin>>type;
        cout<<"enter account no.";
        cin>>accountNo;
        cout<<"enter balance";
        cin>>balance;
    }
    void deposit(void){
        int n;
        cout<<"enter amount to deposit";
        cin>>n;
        cout<<"total is:"<<balance+n;
        balance=balance+n;
    }
    void withdraw(void)
	{
        int w;
        cout<<"balance is:"<<balance;
        cin>>w;
        cout<<"balance is:"<<balance-w;
        balance=balance-w;
	}
	void dispdata(void)
	{
        cout<<"name:"<<name;
        cout<<"balance left:"<<balance;
	}
};
int main(){
    bank b1;
    int choice;
    while(choice != 5)
    {
        cout<<"\n1.To assign the initial values\n";
		cout<<"2.To deposit an amount\n";
		cout<<"3.To withdraw an amount\n";
		cout<<"4.To display name and balance\n";
		cout<<"5.Exit\n";
		cin>>choice;
		switch(choice)
		{
		    case 1: b1.enterData();
		    break;
		    case 2: b1.deposit();
		    break;
		    case 3: b1.withdraw();
	        break;
            case 4: b1.dispdata();
	        break;
		}
    }
return 0;
}
