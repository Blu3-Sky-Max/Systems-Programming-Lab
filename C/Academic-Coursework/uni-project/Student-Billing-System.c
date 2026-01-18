#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Author: Blu3 Sky 
 * Title: Student Billing System 
 */
struct Student{
    int id;
    char name [50];
    char class [20];
    float tuitionfee;
    float uniformfee;
    float textbookfee;
    float otherexpenses;
    float totalfee;
    float paidamount;
    float balance;
};
 // function to add a new student
 void addStudent (struct Student Students[],int*count){
     printf("Enter your student details:\n: ");
     printf("id: ");
     scanf("%d",&Students[*count].id);
     printf("name: ");
     scanf("%s",Students[*count].name);
     printf("class: ");
     scanf("%s",Students[*count].class);
     printf("tuition fee: ");
     scanf("%f",&Students[*count].tuitionfee);
     printf("text book: ");
     scanf("%f",&Students[*count].textbookfee);
      printf("uniform fee: ");
     scanf("%f",&Students[*count].uniformfee);
     printf("other expenses: ");
     scanf("%f",&Students[*count].otherexpenses);
     
    Students[*count].totalfee=
   Students[*count].tuitionfee+ Students[*count].textbookfee+ Students[*count].uniformfee+ Students[*count].otherexpenses;
     
     Students[*count].paidamount=0;
    Students[*count].balance= Students[*count].totalfee;
     (*count)++;
     printf("student added successfully!\n");
     
 
     
 }
 
 void  GenerateBill (struct Student
 Students[],int count){
     int id;
     printf("Enter student id: ");
     scanf("%d",&id);
     for(int i=0;i<count; i++){
         if ( Students[i].id==id){
             printf("Bill for student ID: %d\n", Students[i].id);
             printf("name: %s\n", Students[i].name);
             printf("class: %s\n", Students[i].class);
             printf("tuition fee: $%.2f\n", Students[i].tuitionfee);
             printf("textbook fee: $%.2f\n", Students[i].textbookfee);
             printf("uniform fee: $%.2f\n", Students[i].uniformfee);
             printf("other expenses: $%.2f\n", Students[i].otherexpenses);
             printf("total fee: $%.2f\n", Students[i].totalfee);
             printf("paid amount: $%.2f\n", Students[i].paidamount);
             printf("balance : $%.2f\n", Students[i].balance);
             return;
         }
     }
     printf("student not found!\n");
 }
 
 void makepayment(struct Student  Students[],int count){
     int id;
     float amount;
     printf("Enter your student id: ");
     scanf("%d",&id);
     for(int i=0;i<count;i++){
         if ( Students[i].id==id){
             printf("Enter payment amount: ");
             scanf("%f",&amount); Students[i].paidamount+=amount;
             Students [i].balance -=amount;
             printf("payment recorded successfully !\n");
             return;
         }
     }
     printf("student not found!\n");
 }
 void generatereport(struct     Student  Students[],int count){
     printf("fee des report:\n ");
     for(int i=0;i<count;i++){
         if ( Students[i].balance>0){
         printf("student ID: %d\n", Students[i].id);
         printf("name : %s\n", Students[i].name);  
         printf("Balance : $%.2f\n", Students[i].balance);
         printf("---------------------\n");
         }
     }
 }
int main (){
    struct Student  Students[100];
    int count=0;
    int choice;
    while (1){
        printf("\n school Billing system\n");
        printf("1.Add Student\n");
        printf("2.Generate Bill\n");
        printf("3.Make payement\n");
        printf("4.Generate report\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        
        scanf ("%d",&choice);
        
        switch (choice){
            case 1:
            addStudent( Students,&count);
            break;
            case 2:
            GenerateBill( Students,count);
            break;
            case 3:
            makepayment( Students,count);
            break;
            case 4:
            generatereport( Students,count);
            break;
            case 5:
            exit(0);
            default:
            printf("invalid choice ! please try again.\n");
            
        }
    } return 0;
}




