#include<iostream>
using namespace std;

struct game{
 double amount;
 double bidamount;
 int guess;
 int dice;
};
game g;
cout<<"Enter amount"<<endl;
cin>>g.amount;
cout<<"Enter bidamount"<<endl;
cin>>g.bidamount;

while(g.bidamount>g.amount){
	 cout<<You entered greater amount. re enter<<endl;
	 cim>>bidamount;
}

 cout<<"Enter number 1 to 10"<<endl;
 cin>>guess;
 
 whilr(guess<1||guess>10)
{
	cout<<reenter number<<endl;
	cin>>guess;
}
dice = (rand()% 10)+1;

if(guess==dice){
	cout<<you won<<endl;
	amount=amount+(bidamount *2);
	cout<<"your amount now is: "<<amount;
}
else{
	cout<<you lose<<
	amount=amount-bidamount;
	cout<<"your amount is now: "<<amount
}


int main()
{
	
}
