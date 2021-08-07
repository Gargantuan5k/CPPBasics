#include <iostream>
using namespace std;

int main()
{
    float netSalary, basicSalary, pDeduction, pAllowance;

    cout << "Enter Basic salary, % deduction and % allowance: ";
    cin >> basicSalary >> pAllowance >> pDeduction;

    netSalary =  basicSalary + basicSalary * pAllowance/100 - basicSalary * pDeduction/100 ;
    cout << "Net salary is " << netSalary << endl;

    return 0;
}