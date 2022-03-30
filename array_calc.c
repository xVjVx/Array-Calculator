#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(){
    char buffer[16];
    double array[10];
    int counter = 0;
    double auxiliary;

    double max = -DBL_MAX;
    double min = DBL_MAX;

    double sum = 0; 
    double product = 1;
    double average = 0;

    char positives = 0;
    char negatives = 0;

    int numbers = 0;

    for (counter = 0; counter < 10; counter++) {
        do{
            fgets(buffer, 16, stdin);
        }while (sscanf(buffer,"%lg",&auxiliary) != 1);

        array[counter] = auxiliary;
        if (array[counter] > max){
            max = array[counter];
        }
        if (array[counter] < min){
            min = array[counter];
        }   
        if (array[counter] < 0) {
            negatives++;
        }
        if (array[counter] > 0) {
            positives++;
        }
    }
    for (counter = 0; counter < 10; counter++){
        for (numbers = counter + 1; numbers < 10; numbers++){
            if (array[counter] > array[numbers]){
                auxiliary = array[counter];
                array[counter] = array[numbers];
                array[numbers] = auxiliary;
            }
        }
    }
    printf("The numbers in ascending order: ");
    for (counter = 0; counter < 10; counter++){
        printf("%lg%s", array[counter], counter < 9 ? ", " : "\n");
        sum += array[counter];
        product *= array[counter];
    }
    average = sum /10;
    printf("Exist %hhd numbers negatives and %hhd numbers positives\n", negatives, positives);
    printf("Max: %lg\nMin: %lg\n", max, min);
    printf("The average is: %lg\n", average);
    printf("The sum of values is: %lg\n", sum);
    printf("The product of values is: %lg\n", product);
}