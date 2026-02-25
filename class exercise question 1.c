#include <stdio.h>


int main(){
    //starting population = 2000
    //increasing at a rate of 15% every six months
    //number of years it would take for the population size to exceed two million
    //2000000
    //30% every year or 12 months
    int yearCounter = 0;


    double population = 2000;
    while(population < 2000000){
            population = (0.3*population) + population;
            yearCounter++;

    }
    printf("The number of years it takes for the population size to exceed two million is %d", yearCounter);

return 0;

}