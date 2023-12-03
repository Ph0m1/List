//来自marevilspirit的测试菜单
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define STARS "********************************************" 

int main(void)
{
    struct Node * head = NULL;
    struct Node * previous, *current;
    int n = 0;
    printf("%s\n\t\t创建一个链表\n%s\n",STARS,STARS);

    for(int i = 1; n != -1; i++)
    {
        printf("第%d个节点(输-1退出):",i);
        scanf("%d",&n);
        if(n == -1)
            break;
        current = (struct Node *)malloc(sizeof(struct Node));
        if(head == NULL)
        { 
            head = current;
        }
        else
        {
            previous->next = current;
        }
        current->next = NULL;
        current->data = n;
        previous = current;
    }
    printf("\n这是你创建的链表: \n"); 
    showLinked_list(head);
    printf("\n");
    char ch;
    printf("\n[B]:头插 [E]:尾插 [P]:特定位置插入 [s]:当前链表 [L]:特值删除\n");
    printf("[b]:头删 [e]:尾删 [p]:特定位置删除 [X]:链表排序 [R]:反转链表\n");
    printf("[q]:退出 [h]:help \n"); 
    printf("按任意键进入指令模式：");
    while((ch = getchar()) != 'q')
    {
        switch (ch)
        {
            case 'B': 
                printf("\nOK,那就让我们进行头插吧！(输入-1退出)\n");
                int isBen = 0;
                while (isBen != -1) 
                {
                    scanf("%d",&isBen);
                    if(isBen == -1)
                        break;
                    insertAtBeginning(&head, isBen);
                }
                break;
            case 'E':
                printf("\nOK,那就让我们进行尾插吧！(输入-1退出)\n");
                int isEnd = 0;
                while (isEnd != -1)
                {
                    scanf("%d",&isEnd);
                    if(isEnd == -1)
                        break;
                    insertAtEnd(&head, isEnd);
                }
                break;
            case 'P':
                printf("\nOK,那就让我们进行特定位置插入吧！(输入-1退出)\n");
                int isPos = 0, positionP;
                while (isPos != -1)
                {
                    printf("\n输入值 要插入的位置：");
                    scanf("%d %d",&isPos,&positionP);
                    if(isPos == -1)
                        break;
                    insertAtPosition(&head, isPos, positionP);
                }
                break;
            case 's':
                printf("\n这是当前的链表：\n");
                showLinked_list(head);
                printf("\n");
                break;
            case 'L':
                printf("\nOK,那就让我们进行特数值删除吧！(输入-1退出)\n");
                int key;
                printf("请输入你想删除的值：");
                scanf("%d",&key);
                deleteNode(&head, key);
                break;
            case 'b':
                printf("\nOK,那就让我们进行头删吧：\n");
                printf("你要进行头删的次数：");
                int countb;
                scanf("%d",&countb);
                for(int i = 0; i < countb &&  head != NULL; i++)
                {
                    deleteAtBeginning(&head);
                }
                break;
            case 'e':
                printf("\nOK,那就让我们进行尾删吧：\n");
                printf("你要进行尾删的次数：");
                int counte;
                scanf("%d",&counte);
                for(int i = 0;i < counte && head != NULL; i++)
                {
                    deleteAtEnd(&head);
                }
                break; 
            case 'p':
                printf("\nOK,那就让我们进行特定位置删除吧！(输入-1退出)\n");
                printf("你要删除的位置是: ");
                int positionp;
                scanf("%d",&positionp);
                deleteNodeAtPosition(&head, positionp);
                break;
            case 'X':
                printf("\nOK,那就让我们给链表排序吧！(输入-1退出)\n");
                printf("当前链表长这样：\n");
                showLinked_list(head);
                printf("\nOK，排完了，现在长这样：\n");
                sortList(&head);
                showLinked_list(head);
                break;
            case 'R':
                printf("\nOK,那就让我们反转链表吧！(输入-1退出)\n");
                printf("当前链表长这样：\n");
                showLinked_list(head);
                printf("\nOK，排完了，现在长这样：\n");
                reverseList(&head);
                showLinked_list(head);
                break;
            case 'h':
                printf("\n[B]:头插 [E]:尾插 [P]:特定位置插入 [s]:当前链表 [L]:特值删除\n");
                printf("[b]:头删 [e]:尾删 [p]:特定位置删除 [X]:链表排序 [R]:反转链表\n");
                printf("[q]:退出 [h]:help \n");
                break;
        }
        while(getchar() != '\n')
            continue;
        printf("\n请输入指令: ");
    }
    free_linked_list(head);
    printf("%s\n\t\t欢迎下次游玩\n%s\n",STARS,STARS);
    return 0;

}  
