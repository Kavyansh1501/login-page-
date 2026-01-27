#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username,password,Email;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signup();
    void forgot();
}obj;

int main(){
char choice;
cout<<"\n1- login";
cout<<"\n2- signup";
cout<<"\n3- forgot password";
cout<<"\n4- exit";
cout<<"\n enter your choice :: ";
cin>>choice;
cin.ignore();

switch(choice){  
      
 case '1' :  
      obj.login();
    break;  
      
 case '2' :  
      obj.signup();
    break;  
      
 case '3' :  
      obj.forgot();
    break;  
      
 case '4' :  
      return 0;
    break;  
      
    default:  
     cout<<"invalid selection";  
}
}
 void temp :: signup(){
     
     cout<<"\n enter your user name :: ";
     getline(cin,username);
    cout<<"\n enter your Email ::";
     getline(cin,Email);
    cout<<"\n enter your password ::";
     getline(cin, password);
     
     file.open("loginData.text", ios :: out | ios :: app);
     file<<username<<"*"<<Email<<"*"<<password<<endl;
     file.close();
 }
 void temp :: login(){
     
     cout<<"--------login-------"<<endl;
     cout<<"enter you user name"<<endl;
     getline(cin,searchName);
     cout<<"enter your password "<<endl;
     getline(cin,searchPass);
     
     file.open("loginData.txt",ios::in);
     getline(file,username,'*');
     getline(file,Email,'*');
     getline(file,password,'\n');
     while(!file.eof()){
         if (username==searchName){
             if(password==searchPass){
                 cout<<"\n account login successfully ";
                 cout<<"\n username"<<username<<endl;
                 cout<<"\n Email"<<Email<<endl;
             }
             else{
                 cout<<" cannot login page";
             }
         }
         getline(file,username,'*');
         getline(file,Email,'*');
         getline(file,password,'\n');
     }
     file.close();
 }
 void temp:: forgot(){
     cout<<"\n enter you user name"<<endl;
     getline(cin,searchName);
     cout<<"\n enter your Email "<<endl;
     getline(cin,searchEmail);
     
     file.open("loginData.txt",ios::in);
     getline(file,username,'*');
     getline(file,Email,'*');
     getline(file,password,'\n');
     
     while(!file.eof()){
         if (username==searchName){
             if(Email==searchEmail){
                 cout<<"your account found"<<endl;
                 cout<<"your password"<<password<<endl;
             }
             else{
                 cout<<"not found \n";
             }
             }else{
                 cout<<"not found \n";
             }
             
         }
         file.close();
     } 