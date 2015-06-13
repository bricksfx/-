#include<iostream>
#include<cstdio>
using namespace std;
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node *next;
}LinkNode;

LinkNode* create()
{
    LinkNode *head, *p, *q;
    head = new LinkNode;
    p = head;
    int n;
    printf("请输入链表长度:");
    scanf("%d", &n);
    if(n >= 1)
    {
        scanf("%d", &p->data);
    }
    --n;
    while(n--)
    {
        q = new LinkNode;
        scanf("%d", &q->data);
        p->next = q;
        p = q;
    }
    p ->next =  NULL;
    return head;
}

void reverseList(LinkNode* &head)
{
    LinkNode *n1, *n2, *n3;
    if(head != NULL && head->next != NULL)
    {
        n1 = head;
        n2 = n1->next;
        cout<<"reverse list begin"<<endl;
        while(n2)
        {
            n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        head->next = NULL;
        head = n1;
        cout<<"reverse list over"<<endl;
    }
}

void *reverse(LinkNode* head, LinkNode *& head_static)
{
    if(head)
    {
        LinkNode* cur = head;
        LinkNode* next = head->next;
        if(next)
        {
            reverse(next, head_static);
            next->next = cur;
        }
        else
        {
           cout<<cur->data<<' '<<endl;
           head_static->next = NULL;
           head_static = cur; 
        }
    }
}

bool insertNode(LinkNode* &head, int num, DataType x)
{
    LinkNode* q = new LinkNode;
    LinkNode* p = head;
    q->data = x;
    if(num == 1)
    {
        q->next = head;
        head = q;
    }
    else
    {
        int k = 0;
        while(k < num-1 && p != NULL)
        {
            p = p->next; 
            k++;
        }
        if(p == NULL && head != NULL)
        {
            cerr<<"无效的插入位置"<<endl;
            return false;
        }
        else{
            q->next = p->next;
            p->next = q;
            
        }
    }
    return true;
}

bool removeNode(LinkNode*&head, int num)
{
    if(num <= 0)
    {
        cerr<<"请输入一个大于0的正整数"<<endl;
        return false;
    }
    else{
        LinkNode* p = head;
        LinkNode* q = head->next;
        if(num == 1)
        {
            head = head->next;
            delete p;
        }
        else
        {
            num -= 2;
            while(num-- && q)
            {
               p = p->next;
            }
            
            if(p == NULL || p->next ==NULL)
            {
                cerr<<"无效的删除位置"<<endl;
                return false;
            }
            q = p->next;
            p->next = q->next;
            delete q;
        }
    }
    return true;
}
/*
bool remove(LinkNode*& head, int num)
{
    LinkNode*p, *q;
    int k;
    if(num <= 1)
    {
        q = head;
        head = head->next;
    }
    else{
        p = head;
        int k = 1;
        while(p != NULL && k < num-1)
        {
            p = p->next;
            k++;
        }
        if(p == NULL || p->next == NULL)
        {
            cerr<<"无效的删除位置"<<endl;
            return false;
        }
        q = p->next;
        p->next = q->next;
    }
    delete q;
    return true;
}
*/

LinkNode* OutPut(LinkNode *head)
{
    LinkNode*p = head;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkNode* p = create();
    /*
    removeNode(p, 1);
    OutPut(p);
    removeNode(p, 5);
    OutPut(p);
    insertNode(p, 3, 10);
    */
    OutPut(p);
    reverse(p, p);
    OutPut(p);
    return 0;
}
