//implementation of Trees using array
#include<stdio.h>
#include<stdlib.h>
#define Max 100
struct TreeNode{

    int data;
};
struct TreeNode tree[Max];
void insert(int value,int index){
    if(index<Max){
        tree[index].data=value;
    }
    else{
        printf("Tree is full/n");
    }
}
int getLeftchild(int index){
    int leftindex=2*index;
    if(leftindex<Max){
        return leftindex;
    }
    else
        return -1;
   
}
int getRightchild(int index){
    int rightindex=2*index+1;
    if(rightindex<Max){
        return rightindex;
    }
    else
        return -1;
}
void printTree(int index){
    if(index<Max && tree[index].data!=0){
        printf("%d",tree[index].data);
        printTree(getLeftchild(index));
        printTree(getRightchild(index));
    }
}
int main()
{
    int value,index;
    printf("Enter the value for the root node: ");
    scanf("%d",&value);
    insert(value,1);
    printf("Enter value and index for addiional nodes(O to stop):\n");
    while(1){
        printf("value: ");
        scanf("%d",&value);
        if(value==0){
            break;
        }
        printf("Index: ");
        scanf("%d",&index);
    }
    printf("Tree elements: ");
    printTree(1);
    printf("\n");
    return 0;
}
