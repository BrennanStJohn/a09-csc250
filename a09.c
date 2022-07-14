#include <stdlib.h>
#include <stdio.h>

struct node {

    int data;
    struct node *next;
    struct node *prev;


};
typedef struct node node;

node* insertFront(node *head, int d);
node* insertBack(node *head, int d);
node* removeNode(node *head, int d);
void print(node *head);
void printRev(node *head);
int max(node *head);
int min(node *head);
int locInList(node *head, int x);

int main(){

    node* head = NULL;

    head = insertFront(head, 5);
    head = insertFront(head, 4);
    head = insertBack(head, 6);
    head = insertBack(head, 7);
    print(head);
    printRev(head);

    printf("Max: %d\n", max(head));
    printf("Min: %d\n", min(head));
    printf("locInList 5: %d\n", locInList(head, 5));
    printf("locInList 9: %d\n", locInList(head, 9));

    head = removeNode(head, 6);
    print(head);
    head = removeNode(head, 4);
    print(head);
    head = removeNode(head, 7);
    print(head);

}

node* insertFront(node *head, int d){

    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    tmp->next = head;
    tmp->data = d;
    tmp->prev = NULL;
    if(head != NULL){
        head->prev = tmp;
    }
    head = tmp;
    return head;
}

node* insertBack(node *head, int d){

    node *tmp = NULL;
    node *tail = head;
    tmp = malloc(sizeof(node));
    tmp->data = d;
    tmp->next = NULL;
    if (head == NULL){
        tmp->prev = NULL;
        head = tmp;
    }
    while (tail->next != NULL){

    tail = tail->next;
    }
    tail->next = tmp;
    tmp->prev = tail;
    return head;
}

node* removeNode(node *head, int d){

    node *tmp = head;

    if(tmp != NULL && tmp->data == d){
        head = tmp->next;
        free(tmp);
        return head;
    }
    while(tmp != NULL && tmp->data != d){
        tmp->prev = tmp->next;
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return head;
    }
    if(tmp->next != NULL){
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
    return head;
    }
    if(tmp->next == NULL){
        tmp->prev->next = tmp->next;
        free(tmp);
        return head;
    }
}

void print(node *head){

    node *tmp = NULL;
    tmp = head;

    while (tmp != NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
    }
    puts("");
}

void printRev(node *head){

    node *tail;

    while(head != NULL){

        tail = head;
        head = head->next;
    }

    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    puts("");
}

int max(node *head){

    node *tmp = head;
    int max = tmp->data;

    while (tmp != NULL){

        if (tmp->data > max){
            max = tmp->data;
        }
        tmp = tmp->next;
        }
        return max;
}

int min(node *head){

    node *tmp = head;
    int min = tmp->data;

    while (tmp != NULL){

        if (tmp->data < min){
            min = tmp->data;
        }
        tmp = tmp->next;
        }
        return min;
}

int locInList(node *head, int x){

    node *tmp = NULL;
    tmp = head;
    int i = 0;

    if (head->data == x){
            return i;
    }
    while (head->data != x) {

        head = head->next;
        i++;
        if (head->data == x){
            return i;
            break;
        }
        else if (head->next == NULL){
            return -1;
        }
    }
}