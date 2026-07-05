#include<iostream>
using namespace std;
int main()
{
    cout<<"Temprature is in which form"<<endl;
    cout<<"1. Celsius"<<endl;
    cout<<"2. Fahrenheit"<<endl;
    cout<<"3. Kelvin"<<endl;
    int choice;
    cin>>choice;  
    float c, f, k;  
    switch(choice)
    {
        case 1:
        {
            cout<<"Enter the temprature in Celsius"<<endl;         
            cin>>c;
            cout<<"Temprature in Fahrenheit is: "<<(c*9/5)+32<<endl;
            cout<<"Temprature in Kelvin is: "<<c+273.15<<endl;
            break; 
        }
        case 2:
        {
            cout<<"Enter the temprature in Fahrenheit"<<endl;           
            cin>>f;
            cout<<"Temprature in Celsius is: "<<(f-32)*5/9<<endl;
            cout<<"Temprature in Kelvin is: "<<(f-32)*5/9+273.15<<endl;
            break;
        }
        case 3:
        {
            cout<<"Enter the temprature in Kelvin"<<endl;
            cin>>k;
            cout<<"Temprature in Celsius is: "<<k-273.15<<endl;
            cout<<"Temprature in Fahrenheit is: "<<(k-273.15)*9/5+32<<endl;
            break; 
        }   
        default:
        {
            cout<<"Invalid choice"<<endl;    
        }
    }

}