


#include <iostream>
using namespace std;

int main() 
{
    char op;
    int a,b;

    // Displaying operations and taking input from user
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Switch case to perform calculation based on operator
    switch(op) 
    {
        case '+':
            cout <<"addition of two numbers = "<< a + b;
            break;

        case '-':
            cout << "sub of two numbers = " << a - b;
            break;

        case '*':
            cout << "multiplication of two numbers = " << a * b;
            break;

        case '/':
            if(b == 0) 
            {
                cout << "Error! Division by zero.";
            } else 
            {
                cout << "division of two numbers = " << a / b;
            }
            break;

        default:
            // If the operator is not one of the specified options
            cout << "Error! Invalid operator.";
            break;
    }

    return 0;
}

























