#include <stdio.h>
#include <stdlib.h>
#include <time.h> //using for random generation
#include <string.h> //using in question 6.

struct node {
    int data;
    struct node* next;
};
typedef struct node node;

struct student{
	int no;
	char name[50];
	int age;
	struct student* next;
};
typedef struct student student;

student *head;

/*QUESTION 1
Write a function that adds all odd numbers to the beginning of the list and all even 
numbers to the end of the list until -1 is entered from the keyboard.*/

node* createlist() {
	printf("\033[1;1H\033[2J");
    int num;
    node* head=NULL;
    node* tail=NULL;

    printf("Enter numbers and enter -1 to stop.\n");
    while (1) {
        scanf("%d", &num);
        if (num==-1) {  
       	node* current=head;
       		if(current==NULL) {
			    printf("List is empty");
				break;
				}
       	printf("List:\n");
    			while (current!=NULL) {
        			printf("%d\t",current->data); 
        			current=current->next;
    } 
            break;
        }

        node* newnode=(node*)malloc(sizeof(node)); 
        newnode->data=num;
        newnode->next=NULL;

        if (num%2==1) { 
            if (head==NULL) {
                head=newnode;
                tail=newnode;
            } else {
                newnode->next=head; //adding odds beginning of the list 
                head=newnode;
            }
        } else {
            if (head==NULL) {
                head=newnode;
                tail=newnode;
            } else {
                tail->next =newnode; //adding evens end of the list 
                tail=newnode;
            }
        }
    }

    return head;
}

/*QUESTION 2
Add 100 randomly generated numbers to the list, write the c code that sorts all the 
numbers entered from largest to smallest and print them on the screen.*/

void bigtosmall(){
	printf("\e[1;1H\e[2J");
	node *head=NULL;
	srand(time(NULL));
	int i,random;
	for(i=0;i<=100;i++){
		node* newnode=(node *)malloc(sizeof(node));
		random=rand()%100 + 1;
		newnode->data=random;
		if(head==NULL || newnode->data>head->data){
			newnode->next=head;
			head=newnode;
		}
		else{
			node *temp=head;
			while(temp->next!=NULL && temp->next->data>newnode->data){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

/*QUESTION 3
Write a function that stores the student number, name and age, traverses all the nodes in 
the list, writes all the student information on the screen and counts it.*/

student* studentsystem(){
	printf("\e[1;1H\e[2J");
	int n,k;
	student *p;
	printf("How many students you are going to add:");scanf("%d",&n);
for (k = 0; k < n; k++) {
        student* new_student = (student*)malloc(sizeof(student));
        if (k == 0) {
            head = new_student;
            p = head;
        } else {
            p->next = new_student;
            p = p->next;
        }
        printf("Enter %d.student's name:",k+1);
        scanf("%s", p->name);
        printf("Enter %d.student's student number:",k+1);
        scanf("%d", &p->no);
        printf("Enter %d.student's age:",k+1);
        scanf("%d", &p->age);
    }
    p->next = NULL;
    int count=1;
	student* current=head;
	while(current!=NULL){
		printf("%d-%d %s %d\n",count,current->no,current->name,current->age);
		current=current->next;
		count++;
	}
	return head;
}

/*QUESTION 4
Write the function that searches records by student name in the list.*/

student *searchname(student *head){
	printf("\e[1;1H\e[2J");
	char search[50];
	printf("Enter student's name that you are searching:");scanf("%s",search);
	student *current=head;
	while(current!=NULL){
		if(strcmp(current->name,search)==0){
			return current;
		}
		current=current->next;
	}
}

/*QUESTION 5
Write the function that deletes the next node from the node 
with the searched student name in the list.*/

void deletenext(student *head){
	printf("\e[1;1H\e[2J");
	char search[50];
	printf("Enter the student's name that you want to delete next student of it:");scanf("%s",search);
	student *current=head;
	while(current!=NULL){
		if(strcmp(current->name,search)==0 && current->next!=NULL){
			student *temp=current->next;
			current->next=temp->next;
			free(temp);
			return;
		}
		current=current->next;
	}
}

/*QUESTION 6
Write the function that prints the record with the longest name in the list. */

void longest(student* head){
	printf("\e[1;1H\e[2J");
	student *current=head;
	student *longeststudent=NULL;
	int max=0;
	while(current!=NULL){
		int currentlength=strlen(current->name);
		if(currentlength>max){
			max=currentlength;
			longeststudent=current;
		}
		current=current->next;
	}
	if(longeststudent!=NULL){
		printf("Longest name:%s\n",longeststudent->name);
		printf("Length:%d",max);
	}
	else{
		printf("Students cannot be found.");
	}
}

//Menu function

int main() {
	student* head;
	int choice;
	while(1){
		printf("\n~~~ You have to choose 3 and create a list for question 4-5-6 . ~~~\n\n1-First question\n2-Second question\n3-Third question\n4-Fourth question\n5-Fifth question\n6-Sixth question\n7-Exit\nEnter your choice:");scanf("%d",&choice);
		switch(choice){
			case 1:{
			 node* list = createlist();
    				while (list != NULL) {
        			struct node* temp = list;
        			list = list->next;
        			free(temp);
    }
    break;
		}
			case 2:{
				bigtosmall();
				break;
			}
			case 3:{
				head=studentsystem();
				break;
			}
			case 4:{
				student* found=searchname(head);
				if(found!=NULL){
					printf("Student found.\n%d %s %d",found->no,found->name,found->age);
				}
				else{
					printf("Student is not exist.");
				}
				break;
			}
			case 5:{
				deletenext(head);
				break;
			}
			case 6:{
				longest(head);
				break;
			}
			case 7:{
				exit(0);
				break;
			}
	}             

    }		
}
