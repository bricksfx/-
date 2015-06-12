#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef int dataType;

typedef struct node{
    dataType data;
    struct node *next;
}LinkNode;

LinkNode *create()
{
    int n;
    LinkNode *head, *p;
    cout<<"请输入链表长度"<<endl;
    cin>>n;
    head = new LinkNode;
    p = head;
    while(n--)
    {
        LinkNode* q = new LinkNode;
        int tmp;
        scanf("%d", &tmp);
        q->data = tmp;
        p->next = q;
        p = p->next;
        
    }
    p->next = NULL;
    return head;
}

void *OutPut(LinkNode* head)
{
    LinkNode *p = head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int length(LinkNode* head)
{
    LinkNode *p = head->next;
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{
    cout<<"test"<<endl;
    LinkNode *newList = create();
    cout<<"the length of the list is "<<length(newList)<<endl;
    OutPut(newList);
}
