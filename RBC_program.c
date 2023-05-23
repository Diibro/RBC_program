#include<stdio.h>
#include <string.h>

struct Person{
    char name[20];
    int age;
    char diabetes_r[20];
    char bloodp_r[20];

};
struct Person p;

void record(){
    int choice;
    FILE *ptr;
    printf("\n\nWelcome to the recording part of the program\n");
    printf("Enter the name of the person:...");
    scanf("%s", p.name);
    printf("Enter the age:...");
    scanf("%d", &p.age);
    printf("Enter the diabetes results __Positive or Negative__:...");
    scanf("%s", p.diabetes_r);
    printf("Enter the results for blood pressure __Positive or Negative__ :...");
    scanf("%s", p.bloodp_r);
    ptr = fopen("testedPeople.txt", "a");
    if(ptr != NULL){
        if(strcmp(p.name, "") != 0 && (strcmp(p.bloodp_r, "Positive") == 0 || strcmp(p.bloodp_r, "Negative") == 0) && (strcmp(p.diabetes_r, "Positive") == 0 || strcmp(p.diabetes_r, "Negative") == 0)){
            fprintf(ptr, "%s\t%d\t%s\t%s\n", p.name, p.age, p.diabetes_r, p.bloodp_r);
            printf("\nThe recording has been done successfully\n");
        }else{
            printf("\nThe information entered is not valid for recording.\nPlease try again\n");
        }
    }else{
        printf("System Error");
    }
    fclose(ptr);

    printf("\nWould you like to record another person\nPress 1: yes \nPress 0: no");
    scanf("%d",&choice);
    if(choice){
        record();
    }else{
        printf("\nbyee\n");
    }

}

void display(){
    FILE *ptr;
    int p_no = 0;
    ptr = fopen("testedPeople.txt", "r");
    if(ptr != NULL){
        printf("\n____ DISPLAYING THE REULTS FOR ALL PEOPLE RECORD ___\n");
        printf("  ====================================================");
        printf("\nName\tAge\tDiabetes Results\tBlood Pressure Results");
        while(!feof(ptr) && fscanf(ptr, "%s\t%d\t%s\t%s", p.name, &p.age, p.diabetes_r, p.bloodp_r) == 4){
            printf("\n%s\t%d\t%s\t%s", p.name, p.age, p.diabetes_r, p.bloodp_r);
            p_no++;
        }
        if(p_no == 0){
            printf("No records available");
        }
    }else{
        printf("\n\nCurrently no related in our system\n");
    }
}

void displayOneDisease(){
    int p_no = 0;

    FILE *ptr;
    ptr = fopen("testedPeople.txt", "r");
    if(ptr != NULL){
        printf("\n____ DISPLAYING THE REULTS FOR ALL PEOPLE with only on DISEASE ___\n");
        printf("  ==================================================================");
        printf("\nName\tAge\tDiabetes Results\tBlood Pressure Results");
        while(!feof(ptr) && fscanf(ptr, "%s\t\t%d\t%s\t%s", p.name, &p.age, p.diabetes_r, p.bloodp_r) == 4){
            if((strcmp(p.diabetes_r, "Positive") == 0 && strcmp(p.bloodp_r, "Negative") == 0) || (strcmp(p.diabetes_r, "Negative") == 0 && strcmp(p.bloodp_r, "Positive") == 0) ){
               printf("\n%s\t%d\t%s\t%s", p.name, p.age, p.diabetes_r, p.bloodp_r);
            }
        }

    }else{
        printf("\nNo records available\n");
    }

}

void main(){
    int choice, cond = 1;
    printf("\n__Welcome to The RBC PATIENT SYSTEM____\n");
    while(cond){
        printf("\n\n\nTo use the system please use the menu below:");
        printf("\nPress 1: To record a new patient \nPress 2:To display all patients \nPress 3: To  display all patients with only one disease\nPress 0: To exit the program\n");
        printf("Choice:...");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                record();
                break;
            case 2:
                display();
                break;
            case 3:
                displayOneDisease();
                break;
            case 0:
                cond = 0;
                break;
            default:
                printf("\nEnter an invalid choice please\n");
        }
    }
}
