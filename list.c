#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 单链表节点定义
typedef struct Node {
    int data;
    struct Node* next;
};

void showLinked_list(struct Node *head,struct Node* current);

// 在链表头部插入节点
void insertAtBeginning(struct Node** head, int data);

// 在链表末尾插入节点
void insertAtEnd(struct Node** head, int data);

// 在指定位置插入节点
void insertAtPosition(struct Node** head, int data, int position);

// 在链表起始删除 
void deleteAtBeginning(struct Node** head);

// 在链表末尾删除
void deleteAtEnd(struct Node** head);

// 删除第一个匹配的节点
void deleteNode(struct Node** head, int key);

// 删除指定位置的节点
void deleteNodeAtPosition(struct Node** head, int position);

//链表排序
void sortList(struct Node** head);

// 反转链表
void reverseList(struct Node** head);

void free_linked_list(struct Node * head,struct Node* current);

int main(int argc,char*argv[]){

}