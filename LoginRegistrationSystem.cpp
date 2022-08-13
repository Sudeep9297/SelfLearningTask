#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registeration();
void forgot();

int main()
{
    int choice;
    cout<<"____________________________________________________________________________________\n";
    cout<<"                                                                                    \n";
    cout<<"                           Welcome to the Login Page                                \n";
    cout<<"____________________________________________________________________________________\n";
    cout<<"                                    MENU                                            \n";
    cout<<"____________________________________________________________________________________\n";
    cout<<"\t| Press 1 to LOGIN                  |"<<endl;
    cout<<"\t| Press 2 to REGISTER               |"<<endl;
    cout<<"\t| Press 3 if forgot the credentials |"<<endl;
    cout<<"\t| Press 4 to EXIT                   |"<<endl;
    cout<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            login();
            break;
        
        case 2:
            registeration();
            break;
        
        case 3:
            forgot();
            break;
        
        case 4:
            cout<<"\t\t\t Thank You !!"<<endl;
            break;
        
        default:
            system("cls");
            cout<<"\t\t\t Please select valid options"<<endl;
            main();
    }
    return 0;
}

void login(){
    int count;
    string userId,password,uId,pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password\n";
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;

    ifstream input("register.txt");
    
    while(input>>uId>>pass){
        if(uId==userId && pass==password){
            count=1;
            system("cls");
        }
    }

    input.close();

    if(count==1){
        cout<<userId<<"\n You are successfully LOGGGED IN \n Thanks for loggging in \n";
        main();
    }else{
        cout<<"\n LOGIN ERROR \n Please check you login credentials again \n ";
        main();
    }
}

void registeration(){
    string ruserId,rpassword,ruId,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username: ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password: ";
    cin>>rpassword;

    ofstream f1("register.txt");
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t\t\t Registration is successful !!!!\n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password ??\n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to main menu "<<endl;
    cout<<"\t\t\t Enter your choice:";
    cin>>option;

    switch(option){
        case 1:
        {
            int count=0;
            string suserId,spassword,suId,spass;
            cout<<"\n\t\t\t Enter the last username you remember: ";
            cin>>suserId;

            ifstream f2("register.txt");
            while(f2>>suId>>spass){
                if(suId==suserId){
                    count=1;
                }
            }
            f2.close();

            if(count==1){
                cout<<"\n\n Your account is found !\n";
                cout<<" Your password is: "<<spass;
                main();
            }else{
                cout<<"\n\t Oops ,no such account is present! \n";
                main();
            }

            break;
        }

        case 2:
        {
            main();
        }

        default:
            cout<<"\t\t\t Kindly enter the right choice!!! "<<endl;
            forgot();
    }
}
