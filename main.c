#include <stdio.h>
#include <stdlib.h>
struct Array{
    int *A;
    int size;  // actual size of the length.
    int length;   //  for how many elements are in the list.
};
void createList(struct Array *arr){
    printf("Enter the size of list: ");
    scanf("%d", &arr->size);

    arr->A = (int *)malloc(arr->size*sizeof(int));  // creates the array in heap;

    if(arr->A==NULL){
        printf("List creation unsuccessful!!\n");
        return;
    }
    arr->length=0; // will tell how many task are currently stored.
    printf("List created successfully");
}
void addTask(struct Array *arr){
    
    while(arr->length < arr->size){
        printf("Enter task %d:", arr->length+1);
        scanf("%d", &arr->A[arr->length]);

        arr->length++; 
        printf("Task Added Successfully!\n");
    }
}
void displayList(struct Array *arr){
    int i;
    printf("No. of pending tasks are: \n");
    for(i=0; i<arr->length; i++){
        printf("%d\n", arr->A[i]);
    }
}
int main(){
    struct Array arr;  // structure variable declaration.
    int choice;

    while(1){
        printf("\n===== Task Manager =====\n");
        printf("1) Create List\n");
        printf("2) Add Tasks\n");
        printf("3) Display the Tasks\n");
        printf("10) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                 createList(&arr);
                 break;
            case 2:
                 addTask(&arr);
                 break;
            case 3:
                 displayList(&arr);
                 break;
            case 10:
                 printf("Have a nice day!....\n");
                 exit(0);
                 break;
            default:
                 printf("Invalid choice!\n");
        }
    }
    return 0;
}