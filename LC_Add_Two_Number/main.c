#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode listnode;
struct ListNode *newNode(int data){
    struct ListNode *NewNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    NewNode->val = data;
    NewNode->next = NULL;
    return NewNode;
}
struct ListNode *addTwoNumbers(struct ListNode *l1,struct ListNode *l2){
    struct ListNode *head    = NULL;
    struct ListNode *current = NULL;
    struct ListNode *rear    = NULL;
    int temp    = 0 , result = 0;
    
    while (l1 != NULL || l2 != NULL)
    {
        // 計算總合
        result = temp + (l1? l1->val: 0) + (l2? l2->val: 0);
        
        // 進位處理
        temp   = (result >= 10)? 1 : 0;
        result = (result >= 10)? (result-10):result;
        
        // 節點串連
        current = newNode(result);
        if (!head)
            head = current;
        else
            rear-> next = current;

        rear = current;
        
        //指標後移 
        if (l1) 
            l1 = l1->next;
        if (l2) 
            l2 = l2->next;    

        //最後的進位處理   
        if (temp == 1)
            rear->next = newNode(1);
    }
    return head;
    
}
int main(int argc, char *argv[]){
    listnode  *l1Ptr;
    listnode  *l2Ptr;
    listnode  l1a,l1b,l1c;
    listnode  l2a,l2b,l2c;
    l1a.val = 2;
    l1Ptr = &l1a;
    l1b.val = 4;
    l1a.next = &l1b;
    l1c.val = 3;
    l1b.next = &l1c;
    l1c.next = NULL;
    while(l1Ptr!=NULL){
        printf("%p ",l1Ptr);
        l1Ptr = l1Ptr->next;
    }
    printf("\n");

    l2a.val = 5;
    l2Ptr = &l2a;
    l2b.val = 6;
    l2a.next = &l2b;
    l2c.val = 4;
    l2b.next = &l2c;
    l2c.next = NULL;
    while(l2Ptr!=NULL){
        printf("%p ",l2Ptr);
        l2Ptr = l2Ptr->next;
    }
    printf("\n");
    listnode *res;
    listnode resa,resb,resc;
    res = &resa;
    printf("%p ",&resa);
    resa.next = &resb;
    printf("%p ",&resb);
    resb.next = &resc;
    printf("%p ",&resc);
    resc.next = NULL;
    printf("\n");
    /*while(res!=NULL){
        printf("%p\n",res);
        res = res->next;
    }*/
    res = addTwoNumbers(l1Ptr,l2Ptr);
    printf("%p\n",res);
    //printf("%p\n",res->next->next);

    free(l1Ptr);
    free(l2Ptr);
    /*l1Ptr = &l1;
    l2Ptr = &l2;*/
    
    
}