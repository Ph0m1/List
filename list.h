#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 单链表节点定义
struct Node
{
    int data;
    struct Node *next;
};

void showLinked_list(struct Node *head)
{
    struct Node *pMove = head;
    while (pMove != NULL)
    {
        printf("%d -> ", pMove->data);
        pMove = pMove->next;
    }
    printf("NULL\n");
}

// 在链表头部插入节点
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// 在链表末尾插入节点
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return;
    struct Node *pMove = *head;
    while (pMove->next != NULL)
    {
        pMove = pMove->next;
    }
    pMove->next = newNode;
}

// 在指定位置插入节点
void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *pMove = *head;
    while (pMove->next != NULL && position-- > 2)
    {
        pMove = pMove->next;
    }
    newNode->data = data;
    newNode->next = pMove->next;
    pMove->next = newNode;
}

// 在链表起始删除
void deleteAtBeginning(struct Node **head)
{
    struct Node *pos = *head;
    (*head)->next = pos->next;
    free(pos);
}

// 在链表末尾删除
void deleteAtEnd(struct Node **head)
{
    struct Node *pos = *head;
    struct Node *beforePos = NULL;
    while (pos->next != NULL)
    {
        beforePos = pos;
        pos = pos->next;
    }
    beforePos->next = NULL;
    free(pos);
}

// 删除第一个匹配的节点
void deleteNode(struct Node **head, int key)
{
    struct Node *pMove = *head;
    struct Node *beforePos = NULL;
    while (pMove->next != NULL && key != pMove->data)
    {
        if (pMove->next == NULL)
            return;
        beforePos = pMove;
        pMove = pMove->next;
    }
    beforePos->next = pMove->next;
    free(pMove);
}

// 删除指定位置的节点
void deleteNodeAtPosition(struct Node **head, int position)
{
    struct Node *pMove = *head;
    struct Node *beforePos = NULL;
    while (pMove->next != NULL && position-- > 1)
    {
        if (pMove->next == NULL)
            return;
        beforePos = pMove;
        pMove = pMove->next;
    }
    beforePos->next = pMove->next;
    free(pMove);
}

// 拼接链表
struct Node *merge(struct Node *left, struct Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct Node *result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// 链表排序
void sortList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *left;
    struct Node *right;

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    struct Node *slow = current;
    struct Node *fast = current->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    left = *head;
    right = slow->next;
    slow->next = NULL;
    sortList(&left);
    sortList(&right);
    *head = merge(left, right);
}

// 反转链表
void reverseList(struct Node **head)
{
    struct Node *pos = *head, *lPos = NULL, *nex = NULL;
    while (pos != NULL)
    {
        nex = pos->next;
        pos->next = lPos;
        lPos = pos;
        pos = nex;
    }
    *head = lPos;
}

void free_linked_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}
