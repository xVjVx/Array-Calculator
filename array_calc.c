#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

bool ascending(double a, double b){
    return a > b;
}

bool descending(double a, double b){
    return a < b;
}

int main(int argc, char** argv){
    char buffer[16];
    double array[10];
    int counter = 0;
    int counter2 = 0;
    double auxiliary;

    double max = -DBL_MAX;
    double min = DBL_MAX;

    double sum = 0; 
    double product = 1;
    double average = 0;

    char positives = 0;
    char negatives = 0;
    char msg[12];
    
    bool (*predicate)(double, double);

    if (argc > 1 && strcmp(argv[1], "descending") == 0) {
        predicate = descending;
        sprintf(msg, "descending");
    }else{
        predicate = ascending;
        sprintf(msg, "ascending");
    }
    printf("Write 10 numbers:");
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
        for (counter2 = counter + 1; counter2 < 10; counter2++){
            if (predicate(array[counter], array[counter2])){
                auxiliary = array[counter];
                array[counter] = array[counter2];
                array[counter2] = auxiliary;
            }
        }
    }
    printf("The numbers in %s order: ", msg);
    for (counter = 0; counter < 10; counter++){
        printf("%lg%s", array[counter], counter < 9 ? ", " : "\n");
        sum += array[counter];
        product *= array[counter];
    }
    average = sum /10;
    printf("There are %hhd negative numbers and %hhd positive numbers\n", negatives, positives);
    printf("Max: %lg\nMin: %lg\n", max, min);
    printf("The average is: %lg\n", average);
    printf("The sum of values is: %lg\n", sum);
    printf("The product of values is: %lg\n", product);
}