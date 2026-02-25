#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 12



int studentID [SIZE]; //an array to contain the student ID's of twelve students
int listSize = 0;


bool isEmpty(){
    if (listSize == 0){
        return true;
    }
    else{
        return false;
    }
}

int Listsize(){
    return listSize;
}

int get(int index){
    for (int i = 0; i < listSize; i++){

    if (studentID[index] == studentID[i]){
        return studentID[index];
        break;
    }}
    printf("Wrong index");
    }

void indexOf(int ID) {
    for (int i = 0; i < listSize-1 ; i++){
        if (studentID[i] == ID){
            printf("The index of the given student ID is %d\n", i);
            break;
        }
    }
        printf("The given ID does not exist\n");
    }


void delete(int index){
    if (index == SIZE-1){
        listSize--;
    }
    else{
        for(int i = index; i < listSize ; i++){
            studentID[i] = studentID[i+1];   
        }
        listSize--;
    }
}

void insert(int index, int x){
    if (index == listSize){
        studentID[index] = x;
        listSize++;
    }
    else{
        for (int i = listSize-1 ; i < index ; i++){
            studentID[i+1] = studentID[1];
            studentID[index] = x;
            listSize++;
        }

    }

}

void output(){
    for (int i = 0; i < listSize ; i++){
        printf("%d ", studentID[i]);
    }
    printf("\n");
}





int main(){
    if(isEmpty()){
        printf("The array is empty\n");
    }

    insert(0, 56);
    insert(1, 43);
    insert(2, 67);

    output();

    delete(2);
    output();


    return 0;
}