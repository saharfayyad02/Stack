//1190119 sahar fayyad
#include <stdio.h>
#include <accctrl.h>
#include <string.h>
#define MAX 100
int l = 0 ;

struct node;
typedef struct node *ptr;

struct node{
    char buffer[MAX];//Maximum size of Stack
    ptr next;
};

typedef ptr stack;
stack p;


stack creat(){//creat a stack
    stack s;
    s=(stack)malloc(sizeof(struct node));
    if(s != NULL){
        s->next=NULL;
    }
    else{
        printf("out of the mem");
    }
    return s;
}


int isempty(stack s){//check if the stack is empty
    return(s->next==NULL);
}


void push(stack s,char b[]){//insert a stack
    ptr temp;
    temp=(ptr)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("out of the mem");
    }else{
        strcpy(temp->buffer, b);
        temp->next=s->next;
        s->next=temp;
    }
}


void pop(stack s){//Remove an element from the top of a stack
    ptr temp;
    if(isempty(s)){
        printf("the mem already empty");
    }else {
        temp = s->next;
        s->next = s->next->next;
        free(temp);
    }
}


char *top(stack s){// Get the value of the top element without removing it
    if(! isempty(s)){
        return s->next->buffer;
    }else{
        printf("the stack is empty\n");
    }
}


void undo(stack s) {//remove the top of the stack and save it in another stack first
    if (isempty(s)) {
        printf("the mem already empty");
    } else{
        push(p, top(s));
        pop(s);
    }
}


void redo(stack s){//re add the last node deleted
    if(isempty(s)){
        printf("the mem already empty");
    }else{
        push(s,top(p));
        pop(p);
    }
}


void print(stack s){//print the stack
    stack k= creat();
    if(s->next==NULL){
        printf("the stack is empty");
        return;
    }
    stack temp = s;
    while (!isempty(temp)) {
        push(k,temp->next->buffer);
        temp=temp->next;
    }
    while (!isempty(k)){
        printf("%s\n",k->next->buffer);
        k=k->next;
    }
}


void fprint(stack s,FILE *f){//print the stack in the file
    l++;
    stack k= creat();
    if(s->next==NULL){
        fprintf(f,"the stack is empty");
        return;
    }
    stack temp = s;
    while (!isempty(temp)) {
        push(k,temp->next->buffer);
        temp=temp->next;
    }
    while (!isempty(k)){
        fprintf(f,"%s\n",k->next->buffer);
        k=k->next;
    }
}


// Driver program to test above functions
int main() {
    stack s = creat();
    p=creat();

    printf("choose an operation \n");
    printf("1.undo \n");
    printf("2.redo \n");
    printf("3.print \n");
    printf("4.save \n");
    printf("5.quit \n\n");
    char ar[MAX];

    FILE *f = fopen("C:\\Users\\user\\Desktop\\A2_1190119_SaharFayyad_1.c\\output.txt","w");
    while(1){

        printf("MYCommand >");
        gets(ar);

        if(strcmp(ar,"undo")==0){ // remove top element in stack
            printf("result >\n");
            undo(s);
            print(s);
        }
        else if(strcmp(ar,"redo")==0){//re add elements in stack
            printf("result >\n");
            redo(s);
            print(s);
        }
        else if(strcmp(ar,"print")==0){//print all elements in stack :
            printf("result >\n");
            print(s);
        }
        else if(strcmp(ar,"save")==0){//save to the file
            fprintf(f,"result >\n");
            fprint(s,f);
        }
        else if(strcmp(ar,"quit")==0){//out from the system
            if(l==0){
                fprintf(f,"result >\n");
                fprint(s,f);
            }
            printf("result >\n");
            printf("Good Bye :)");
            break;
        }else{//push to the stack
            push(s,ar);
        }
    }
    fclose(f);

    return 0;
}
