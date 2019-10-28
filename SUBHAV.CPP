#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<iomanip.h>
//Main Bank Class
class Bank
{

	    long double acntno;
	    long balance;
	    long pin;
	    char name[50];
	    char acnttyp;
	    long withdraw;
	    long deposit;
     public:

     //Function for opening account
      void openacnt()
	{
	    clrscr();
	    cout<<"\n===============Welcome to KVM Bank===============\n";
	    cout<<"\n*Please fill the following details torent Account open a bank account\n";
	    cout<<"\nName of the account holder:";
	      gets(name);
	    cout<<"\nPress any key to generate account number...";
	      randomize();
	       acntno=random(10000);
	       if(acntno<1000)
		 acntno=acntno+1000;
	    cout<<"\nAccount Number:"<<acntno;
	    cout<<"\nSelect Type of Account (S-For Savings & C-For Current):";
	      cin>>acnttyp;
	      acnttyp=toupper(acnttyp);
	    cout<<"\nPress any key to generate pin...";
	       pin=random(10000);
	       if(pin<1000)
		 pin=pin+1000;
	    cout<<"\nPin generated:"<<pin;
	    cout<<"\nEnter intial balance(Min:Rs1000-Savings,Rs1500-Current): Rs.";
	      cin>>balance;
	    cout<<"\n\t$ Account Created $\n*THANK YOU FOR BANKING WITH US*\n";
	      getch();
	}

     //function for showing accout details
      void showacnt()
	{
	     clrscr();
	     cout<<"\nAccount Number:"<<acntno;
	     cout<<"\nName of the account holder:"<<name;
	     cout<<"\nAccount Type:";

	    if(acnttyp=='S')
	      cout<<"Savings";
	    if(acnttyp=='C')
	      cout<<"Current";

	     cout<<"\nAccount Balance: Rs."<<balance;
	     cout<<"\n*THANK YOU FOR BANKING WITH US*\n";

	}

     //function to modify account
      void modifyacnt()
	{
	   clrscr();
	    cout<<"\n-----_Enter New details to change_-----\n";
	    cout<<"\nEnter Account Number:";
	      cin>>acntno;
	    cout<<"\nModify Name of the account holder:";
	      gets(name);
	    cout<<"\nModify Account Type -\n(S-For Savings & C-For Current):";
	      cin>>acnttyp;
	    cout<<"\nModify Account Balance:";
	      cin>>balance;
	    cout<<"\n\t $ Account Details Change $\n*THANK YOU FOR BANKING WITH US*\n";
	     getch();
	}


     //function to deposit money
       void depamt()
	 {
	     clrscr();
	     long x;
	     cout<<"\nEnter Deposit Amount:";
	      cin>>x;
	      balance=balance+x;
	      cout<<"\n$ Amount Deposited $\n*THANK YOU FOR BANKING WITH US*";

	 }

     //function to withdraw amount
       void witdamt()
	 {
	     clrscr();
	     long x=0;
	     cout<<"\n-----_Cash withdraw_-----\n"<<"Enter Amount to Withdraw: Rs.";
	      cin>>x;
	     if(x<=balance)
	       {
		  balance=balance-x;
		 cout<<"\n$ Amount Withdrawn $\n*THANK YOU FOR BANKING WITH US*";
	       }
	     else
	       {
		cout<<"\nInsufficient account balance\n"<<"\nYour current Account balance is: Rs"<<balance;
	       }


	 }

     //function to report
       void report()
	 {
	     clrscr();

	    cout<<acntno<<"\t"<<name<<"\t\t"<<acnttyp<<"\t\t"<<balance;
	      getch();
	 }

		 long retacntno()
		 {return acntno;}

		 float retbalance()
		 {return balance;}

		 char rettype()
		 {return acnttyp;}



};

//global declarations
fstream f;
Bank b1;

//funtion to write im file
void create_acnt()
{
   f.open("d://Bank.dat",ios::out|ios::app);
    b1.openacnt();
    f.write((char*)&b1,sizeof(b1));
    f.close();
}

//function to read account details from fili
void dispacnt()
{
      long double acno;
      int check=0;

      clrscr();

      f.open("d://Bank.dat",ios::in);
      cout<<"\nEnter Your Account Number:";
       cin>>acno;

     while(f.read((char*)&b1,sizeof(b1)))
       {

	  if(b1.retacntno()==acno)
	    {
		b1.showacnt();
		check=1;
	    }

      }
	  if(check==0)
	    cout<<"\nAccount does not exists";
	  f.close();

	    getch();

 }
void main()
 {
   clrscr();

     char ch;
      do
       {
	 clrscr();
	 cout<<"\n@@@@@@@@@@ Welcome to KVM Bank @@@@@@@@@@\n";
	 cout<<"\n!~~~~~~~~~~~~~~~MAIN MENU~~~~~~~~~~~~~~~!\n";
	 cout<<"\n\n1.Open New Account\n\n2.Deposit Amount\n\n3.Withdraw Amount\n\n4.Balance Enquiry\n\n5.All Account Holders List\n\n6.Close Existing Account\n\n7.Modify Existing Account\n\n8.Exit\n";
	 cout<<"\n-----------------------------------------\n";
	 cout<<"\nEnter Your Choice(1 to 8) ?:";
	   ch=getche();
	 cout<<"\n-----------------------------------------\n";

	 switch(ch)
	    {

		case '1': create_acnt();
			  break;
		case '2': b1.depamt();
			  break;
		case '3': b1.witdamt();
			  break;
		case '4': dispacnt();
			  break;
		case '5': b1.report();
			  break;
		case '6':break;
		case '7':break;
		case '8':break;
		default:cout<<"Enter again";

	    }

       }while(ch!='8');
       getch();
  }