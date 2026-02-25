#include <stdio.h>
#include <string.h>
 //jb and sons are paid on an hourly basis at the end of every week
    //<= 40 hours a weeek, regular
    //>40 overtime
    //regular hours are paid at 500 cedis for male, 550 for female
    //overtime rate 1 and a half times the regular rate per hour for the different sexes
    //all employees are to pay 15% of their gross pay as income tax
    //2.5% as National Health contribution levy
    //1% as District Tax
    //employees who have more than three children are to pay 10 and 20 cedis per child in excess of three towards Educational Fund for all males and females
    //respectively
    //computer plan to devise the net pay of employees
int hoursWorked;

void clearInputBuffer(void){
    int ch;
    while ((ch = getchar()) != "\n");


}

double regularPay(int hours){
        printf("Is the employee Male or Female? Input is case sensitive\n");
        char employeeGender[8];
        scanf("\n%c", &employeeGender);
        clearInputBuffer();
        if (strcmp(employeeGender, "Male") == 0){
            return hours*500;
        }
        else if (strcmp(employeeGender, "Female") == 0) {
            return hours*550;
        }

}

double overtimePay(int hours){
    printf("Is the employee Male or Female? Input is case sensitive\n");
        char employeeGender[8];

         scanf("\n%c", &employeeGender);
        if (strcmp(employeeGender, "Male") == 0){
            getchar() != '\n';
            return hours* (1.5*500);
        }
        else if (strcmp(employeeGender, "Female") == 0) {
            getchar() != '\n';
            return hours* (1.5*550);
        }
        else {printf("Please enter a valid input");}

}

double incomeTax(double calculatedGrossPay){
    0.15 * calculatedGrossPay;


}

double nHL(double calculatedGrossPay){
    0.025 * calculatedGrossPay;
}

double districtTax(double calculatedGrossPay){
    0.01 * calculatedGrossPay;
}

double educationalFund(){
    char answer[3];
    int maleChildCounter;
    int femaleChildCounter;
    printf("Does the employee have children? Please enter Yes/No (case sensitive)\n");
    scanf("%s", &answer);
    if (strcmp(answer, "Yes") == 0){
        printf("Please enter the number of male children the employee has\n");
        scanf("%d", &maleChildCounter);
        printf("\n Please enter the number of female children the employee has\n");
        scanf("%d", &femaleChildCounter);
        return (maleChildCounter*10) + (femaleChildCounter*20);


     }
    else if (strcmp(answer, "No") == 0){
        return 0.0;
    }
    else {printf("Please enter a valid input");}



    



}




int main(){
    double calculatedPay;
    double netPay;
   
    printf("Please enter the number of hours the employee worked\n");
    scanf("%d", &hoursWorked);
    if (hoursWorked >40){
        calculatedPay = overtimePay(hoursWorked);
        netPay = calculatedPay - (incomeTax(calculatedPay)+ nHL(calculatedPay) + districtTax(calculatedPay) + educationalFund());
        printf("The student's Net Pay is %.2lf", netPay);

    }
    else{
        calculatedPay = regularPay(hoursWorked);
        netPay = calculatedPay - (incomeTax(calculatedPay)+ nHL(calculatedPay) + districtTax(calculatedPay) + educationalFund());
        printf("The student's Net Pay is %.2lf", netPay);


    }


   

    return 0;
}