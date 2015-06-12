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
               return true;
           }
           p = p->next;
           count++;
       }
   }
}

int main()
{
    cout<<"test"<<endl;
    LinkNode *newList = initList();
    OutPut(newList);
    deleteNode(4, newList);
    OutPut(newList);
    return 0;
}
