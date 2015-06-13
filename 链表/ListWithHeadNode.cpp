#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef int dataType;

typedef struct Node{
    dataType data;
    struct Node *next;
}LinkNode;

LinkNode* initList()
{
    LinkNode *head, *p, *q;
    int n;
    printf("请输入链表长度:");
    scanf("%d", &n);
    head = new LinkNode;
    head->data = n;
    p = head;
    while(n--)
    {
        q = new LinkNode;
        scanf("%d", &q->data);
        p->next = q;
        p = q;
    }
    p->next = NULL;
    return head;
}

void OutPut(LinkNode* head)
{
    LinkNode *p = head->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

bool insertNode(LinkNode* head, int num, dataType x)
{
    LinkNode* p = head;
    LinkNode* q = new LinkNode;
    q->data = x;
    if(num < 1)
    {
        cerr<<"插入位置不合理"<<endl;
    }

    else
    {
        int k = 0;
        while(p != NULL && k < num-1)
        {
            p = p->next;
            k++;
        }
        if(p == NULL)
        {
            cerr<<"插入位置不合理"<<endl;
            return false;
        }
        q->next = p->next;
        p->next = q;
    }
    return true;
}

void sortList(LinkNode* head)
{
    LinkNode* p = head->next;
    LinkNode* q;
    while(p != NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(q->data < p->data)
            {
                int tmp = q->data;
                q->data = p->data;
                p->data = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void reverseNode(LinkNode*& head)
{
    LinkNode* n1, *n2, *n3;
    if(head ->next != NULL && head->next->next != NULL)
    {
        n1 = head->next;
        n2 = head->next->next;
        n1->next = NULL;
        while(n1 && n2)
        {
            n3 = n2->next;
            n2->next = n1;
            if(n3 == NULL)
                break;
            n1 = n2;
            n2 = n3;
        }
        head->next = n2;
    }

}

bool deleteNode(int num, LinkNode* head)
{
   int len = head->data;
   if(num <= 0 || num > len)
   {
       cerr<<"删除位置错误,请输入一个大于1或者小于等于链表长度的数字"<<endl;
   }
   else{
       LinkNode* p = head;
       int count = 1;
       while(p->next)
       {
           if (count == num) 
           {
               LinkNode* q = p->next;
               p->next = q->next;
               delete q;
               head->data--;
               return true;
           }
           p = p->next;
           count++;
       }
   }
}

int main()
{
    LinkNode *newList = initList();
    OutPut(newList);
    insertNode(newList,3, 10);
    insertNode(newList, 1,  10);
    OutPut(newList);
    sortList(newList);
    OutPut(newList);
    reverseNode(newList);
    OutPut(newList);
    return 0;
}
