#include <stdio.h>

struct node{
    int val;
    struct node *next;
};

void print_list(struct node *head);
void insert_node(int value);
void delete_node(int value);

struct node *head = NULL;

void print_list(struct node *head){
    struct node *iterator = head;
    while(iterator != NULL){
        printf("%d ", iterator -> val);
        iterator = iterator -> next;
    }
    printf("\n");
}

void insert_node(int value){
    struct node *new_node = malloc(sizeof(struct node));
    
    new_node -> val = value;
    new_node -> next = NULL;

    if(head == NULL){
        head = new_node;
        return;
    }

    struct node *iterator = head;
    while(iterator -> next != NULL)
        iterator = iterator -> next;

    iterator -> next = new_node;
}

void delete_node(int value){

    if(head == NULL)
        return;

    struct node *iterator = head;
    while(iterator -> next != NULL){
        if(iterator -> next -> val == value){
            struct node *temp = iterator -> next;
            iterator -> next = iterator -> next -> next;
            free(temp);
            return;
        }
        iterator = iterator -> next;
    }
}

int main(){

    insert_node(2);
    insert_node(4);
    insert_node(10);
    insert_node(15);

    printf("Initial list:\n");
    print_list(head);

    insert_node(3);

    printf("List after inserting 3:\n");
    print_list(head);

    delete_node(10);
    
    printf("List after deleting 10\n");
    print_list(head);

    return 0;
}