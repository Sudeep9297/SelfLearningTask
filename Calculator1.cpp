#include <iostream>
#include <cmath>
using namespace std;

class Calculator{
        float a;
        float b;
    public:
        void total(){
            cout<<"Enter the first number: ";
            cin>>a;
            cout<<"Enter the second number: ";
            cin>>b;
        }

        float add();
        float subtract();
        float multiply();
        float division();
};

float Calculator ::add(){
    return a+b;
}

float Calculator ::subtract(){
    return a-b;
}

float Calculator ::multiply(){
    return a*b;
}

float Calculator ::division(){
    if (b==0){
        return INFINITY;
    }else{
         return a/b;
    }
}

int main()
{
    char oper;
    Calculator calc;
    cout<<"Enter the choice of operation:('+','-','*','/')"<<endl;
    cout<<"Press (+) for addition"<<endl;
    cout<<"Press (-) for subtraction"<<endl;
    cout<<"Press (*) for multiplication"<<endl;
    cout<<"Press (/) for division"<<endl;
    cout<<endl;

    do{
        cout<<"\n Enter the operator: ";
        cin>>oper;

       switch (oper)
       {
       case '+':
        calc.total();
        cout<<"The addition is:"<<calc.add()<<endl;
        break;
       
       case '-':
        calc.total();
        cout<<"The subtraction is:"<<calc.subtract()<<endl;
        break;

       case '*':
        calc.total();
        cout<<"The multiplication is:"<<calc.multiply()<<endl;
        break;
    
       case '/':
        calc.total();
        cout<<"The division is:"<<calc.division()<<endl;
        break;

       default:
        cout<<"OOPS!!! Enter the valid operator"<<endl;
        break;
       } 
    }while(oper);

    return 0;
}