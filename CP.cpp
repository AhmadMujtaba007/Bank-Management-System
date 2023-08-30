#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std ; 

///////////////////////////////////// CREATE ACC FUNCTION /////////////////////////////////////////
int   createacc(char n1[30],int balance , int an ,char type )
{					system("CLS") ;
					cout<<"                                ACCOUNT CREATION MENU      "  << endl ;
                    cout<<"ENTER YOUR  FIRST NAME :" ;
                    cin>> n1 ;                
   				    cout<< "ENTER YOUR ACCOUNT No   (MAX 5 DIGIT )  :" ;
  				    cin>> an  ;
  				    cout<< "ENTER THE TYPE OF ACCOUNT(c/s):  " ;
  				    cin>> type ;
  				    cout<< "YOUR FIRST CURRENT BALANCE IS $1000  :"<<endl  ;
  				    balance = 1000  ;
  				    ofstream accdetail ;
   					accdetail.open("acc.txt" ,ios::app) ;
  					accdetail<<  an  <<"     ";
					accdetail<<  n1 <<"     "    ;
					accdetail<< type <<"     "  ;	
					accdetail<<balance   <<endl ;  
		            accdetail.close() ;
  					cout<< endl ; 
					cout<<"                                 ACCOUNT CREATION SUCCESSFUL " <<endl<<endl<<endl ;	
                	system("pause") ;
}

//////////////////////////////////////DEPOSIT AMOUNT FUNCTION //////////////////////////////////////////
int deposit(char n2[30]  , int b2 , int a2 , char t2 )
{    system("CLS") ;
     cout<<"                       DEPOSIT MENU        " << endl ;
	int pin , depositamount ;
	char  str[100000] ;
	fstream deposit ;
	deposit.open("acc.txt" , ios:: in ) ;
	fstream  record ;
	record.open("temp.txt ", ios:: app ) ;
	cout <<" ENTER YOUR ACCOUNT NO : " ;
	cin>> pin ;
	cout<< endl ;
	while(deposit.is_open() ){
	deposit >> a2 >> n2 >> t2 >> b2  ; 
	if(pin == a2 )
	 {
	 	cout<< "ACOOUNT NO :"<< a2 <<endl ;
	 	cout<< "ACOOUNT HOLER NAME  :"<< n2 <<endl ;
	 	cout<< "ACOOUNT TYPE "<< t2 << endl ;
	 	cout<< "CURRENT BALANCE  :"<< b2 <<endl ;
	    cout<<endl << endl ; 
	    cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT :" ;
	    cin >> depositamount ;   
	    b2= b2+depositamount ;
		deposit <<	 a2 << n2 << t2 << b2 ; 
	    record << a2 <<"   "<< n2  << "   " << t2 <<"   " << b2 << endl ;
	    deposit.close();
		 }		     
	else if(pin!=a2 )
	{ record << a2 <<"   "<< n2  << "   " << t2 <<"   " << b2 << endl ;
	}

}   
    deposit.close() ;
	record.close() ;
	cout<< "RECORD UPDATED!  "  <<endl ;
	system("del acc.txt ") ;
	system("ren temp.txt acc.txt ") ;
	system("pause") ;
	
}
///////////////////////////////////////////////WITHDRAW AMOUNT FUNCTION/////////////////////////////////
int WITHDRAW(char n3[30] , int b3, int a3 , char t3 )
{	system("CLS") ; 
	 cout<<"                       WITHDRAW MENU         " << endl ;
	int pin , withdrawamount ;
	char  str[100000] ;
	fstream withdraw ;
	withdraw.open("acc.txt" , ios:: in ) ;
	fstream  record ;
	record.open("temp.txt ", ios:: app ) ;
	cout <<" ENTER YOUR ACCOUNT NO : " ;
	cin>> pin ;
	cout<< endl ;
	while(withdraw.is_open()) 
	{
	withdraw >> a3 >> n3 >> t3 >> b3  ; 
	if(pin == a3 )
	 {
		cout<< "ACOOUNT NO :"<< a3 <<endl ;
	 	cout<< "ACOOUNT HOLER NAME  :"<< n3 <<endl ;
	 	cout<< "ACOOUNT TYPE "<< t3 << endl ;
	 	cout<< "CURRENT BALANCE  :"<< b3 <<endl ;
	    cout<<endl << endl ; 
	    cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW :" ;
	    cin >> withdrawamount ; 
	    b3= b3-withdrawamount ;
		withdraw <<	 a3 << n3 << t3 << b3 ; 
		record << a3 <<"   "<< n3  << "   " << t3 <<"   " << b3 << endl ;
		withdraw.close() ;
		record.close() ;    
	}
	else 
	{ record << a3 <<"   "<< n3  << "   " << t3 <<"   " << b3 << endl ;
	}

}   
    withdraw.close() ;
	cout<< "RECORD UPDATED!  "  <<endl ;
	system("del acc.txt ") ;
	system("ren temp.txt acc.txt ") ;
	system("pause") ;
	
}
	 
/////////////////////////////////BALANCE INQUIRY FUNTION//////////////////////////////////////////////// 
int BE(char n1[30] , int b1 , int a1 , char t1  )
{    system("CLS") ;
 cout<<"           BALANCE INQUIRY MENU  " << endl ; 
	 int pin ;
	 fstream be ;
	 be.open("acc.txt",ios::in) ;
	 cout<<"ENTER YOUR ACCOUNT NO :" ;
	 cin>>pin ;
	cout<<endl ; 
	while(be.is_open() ){
	be>> a1 >> n1 >> t1 >>b1  ; 
	 if(pin== a1 )
	{
	    cout<< "ACOOUNT NO :"<<a1<<endl ;
	 	cout<< "ACOOUNT HOLER NAME  :"<<n1 <<endl ;
	 	cout<< "ACOOUNT TYPE "<<t1<<endl ;
	 	cout<< "CURRENT BALANCE  :"<<b1 <<endl ;
	 	be.close() ;
	 }
	 else if(pin!=a1)
	 { continue ;
	 }
     }
	 	
be.close();
cout<<endl <<endl <<endl ;	
system("pause") ;
	
}
		



//////////////////////////////////////LIST OF ACC HOLERS///////////////////////////////////////////////////
int LISTOFACC() 
{   system("CLS") ;
        cout<<"                      LIST OF ALL THE ACCOUNT HOLDERS    "   <<endl ;
    string content;
    ifstream openfile ("acc.txt");
    if(openfile.is_open())
    {   cout<<"----------------------------------------------------------"<< endl ; 
        while(! openfile.eof())
        {
            getline(openfile, content);
            cout << content << endl;
			 
			
        }
    }
}
//////////////////////////////////////DELETE AN ACCOUNT FUNCTION //////////////
int DELACOUNT(char n5[30] , int b5, int a5 , char t5)
{	system("CLS") ;
    cout<<"                         ACCOUT DELETION MENU " << endl ;
    int pin ;
    string name ;
	 fstream deleteaccount  ;
	 deleteaccount.open("acc.txt",ios::in) ;
	fstream record  ;
	 record.open("temp.txt",ios::app) ;
	 
	 cout<<"ENTER YOUR ACCOUNT NO :" ;
	 cin>>pin ;
	 cout<<"ENTER YOUR FIRST NAME :" ;
	 cin >> name ; 
   	cout<<endl ; 
    while(deleteaccount >> a5 ){
	   deleteaccount  >> n5 >> t5 >>  b5  ; 
	    if(name.compare(n5)!=0)
	   {    record << a5 <<"   "<< n5  << "   " << t5 <<"   " << b5 << endl ;
  	}
}
deleteaccount.close();  	    	
record.close();
system("del acc.txt ") ;
system("ren temp.txt acc.txt ") ;
cout<<"                 ACCOUNT DELETED THANK U FOR YOUR TIME TILL NOW  " << endl ;
cout<<endl <<endl <<endl ;		
	system("pause") ;
}

//////////////////////////////////MODIFY //////////////////////////////////////
int MODIFY(char n4[30] , int b4, int a4 , char t4)
 {

	system("CLS") ;
	cout<<"           ACCOUNT MODIFY MENU  " << endl ; 
	 int pin ;
	 fstream modify  ;
	 modify.open("acc.txt",ios::in) ;
	 fstream record  ;
	 record.open("temp.txt",ios::app) ;
	 cout<<"ENTER YOUR ACCOUNT NO :" ;
	 cin>>pin ;
   	 cout<<endl ; 
    while(modify.is_open())
	{   modify >> a4 >> n4 >> t4 >>  b4  ; 
	    if(pin== a4)
	{
	    cout<< "ACOOUNT NO :"<<a4<<endl ;
	 	cout<< "ACOOUNT HOLER NAME  :"<<n4 <<endl ;
	 	cout<< "ACOOUNT TYPE "<<t4<<endl ;
	 	cout<< "CURRENT BALANCE  :"<<b4 <<endl ;
	 	cout<<endl <<endl <<endl ;
	 	cout<<"                          THESE ARE YOUR PREVIOUS DETAILS NOW YOU CAN EDIT UR DATA :" << endl ;
		cout<<"ENTER YOUR  FIRST NAME :" ;
        cin>> n4 ;                
   	    cout<< "ENTER YOUR ACCOUNT No  :" ;
  	    cin>> a4  ;
  		cout<< "ENTER THE TYPE OF ACCOUNT(c/s):  " ;
  	    cin>> t4 ;
  	    record <<  a4 <<"   "<< n4  << "   " << t4 <<"   " << b4 << endl ;
  	    modify.close() ;
  	    record.close() ;
	    }
	else 
	{ record << a4 <<"   "<< n4  << "   " << t4 <<"   " << b4 << endl ;
	}

}	
modify.close();
record.close();
cout<< "RECORD UPDATED!  "  <<endl ;
system("del acc.txt ") ;
system("ren temp.txt acc.txt ") ;
cout<<endl <<endl <<endl ;	
system("pause") ;	
}

/////////////////////////////////MAIN FUNCTION ////////////////////////
int main()
{  
	int noofcase ;
	int withdrawamount , remainingamount ,firstdeposit ;
	do {
	system("CLS") ;
	cout<<"                                   HI !!! WELCOME TO ASH  BANK  " << endl ;
	cout<<endl<<endl << endl ;
	cout<< "HOW CAN WE HELP YOU  :" << endl ;
	cout<<"1 for CREATE  ACCOUNT " << endl ;
	cout<<"2 for DEPOSIT MONEY   " << endl ;
	cout<<"3 for WITHDRAW MONEY " << endl ;
    cout<<"4 for BALANCE ENQUIRY  " << endl ;
	cout<<"5 for LIST OF ALL ACC HOLDERS " << endl ; 
	cout<<"6 for CLOSE AN ACCOUNT  " << endl ;
	cout<<"7 for MODIFY ACC " << endl ;
    cout<<"8 for EXIT " << endl ; 
	cout<<endl<<endl << endl ;
	cout<<"ENTER YOUR DESIRED NO " <<endl ;
	cin>> noofcase ;
	cout<<endl <<endl <<endl ;
	switch(noofcase)
	{
		case 1 :    
					 system("CLS") ;
					 char     name[30]  ;
                     int  balance;
                    char type ;
                    int an ;
                    createacc( name, balance, an , type) ;
                   
		break ;
		case 2 : 	
					system("CLS") ;
					char n1[30] ;
					int b1 ;
					char t1 ;
					int a1 ;
					deposit(n1,b1,a1,t1) ;
		break ;
		case 3 : 
					system("CLS") ;
					char n2[30] ;
					int b2 ;
					char t2 ;
					int a2 ;
					WITHDRAW(n2,b2,a2,t2) ;
		break ;
					
		case 4 :
					system("CLS") ;
					 
					 char    n[30]  ;
                     int  b;
                    char t ;
                    int a ;
					BE(n , b ,a ,t ) ;
		break ;
		case 5 :   system("CLS") ;
		           
	              LISTOFACC() ;
	              system("pause") ;
	              break ;
	    case 6 : 
	    		system("CLS") ;
	    		char na[30] ;
	    		int ba;
	    		char ty ;
	    		int ac;
	    		DELACOUNT(na,ba,ac,ty) ;
	    break;
	    case 7: 
	    		system("CLS") ;
	    			char n3[30] ;
					int b3 ;
					char t3 ;
					int a3 ;
					MODIFY(n3,b3,a3,t3) ;	    		
	    break ;
	   
	 }
}  while(noofcase<=7) ;
	system("CLS") ;
	cout<<"PRESS ENTER TO EXIT ." << endl << endl ; 
return 0 ;	
}
