#include<stdlib.h>
#include<stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode listnode;


int main(int argc, char *argv[]){
    listnode *l1Ptr = (struct ListNode* )malloc(sizeof(struct ListNode));
    listnode *l2Ptr = (struct ListNode* )malloc(sizeof(struct ListNode));
    listnode l1,l2,l31,l32,l41,l42,l5;
    l1Ptr = &l1;
    l1.val = 1;
    l1.next = &l2;
    l2.val = 2;
    l2.next = &l31;
    l31.val = 3;
    l31.next = &l32;
    l32.val = 3;
    l32.next = &l41;
    l41.val = 4;
    l41.next = &l42;
    l42.val = 4;
    l42.next = &l5;
    l5.next = NULL;
    l5.val = 5;
    /*while(l1Ptr!=NULL){
        printf("%d\n",l1Ptr->val);
        l1Ptr = l1Ptr->next;
    }*/
    listnode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = l1Ptr;
    /*while(dummy!=NULL){
        printf("%p\n",dummy);
        dummy = dummy->next;
    }*/
    listnode *prev = dummy;
    listnode *cur = l1Ptr;
    
    //If there are duplicated element, remove these elements
    /*while(cur != NULL){
        while(cur->next != NULL && cur->val == cur->next->val){
            cur = cur->next;     
        }

        if(prev->next == cur){
            prev = prev->next;
            printf("%d ",prev->val);

        }
        else{
            prev->next = cur->next;
        }

        cur = cur->next;
    }
    printf("\n");
    while(dummy!=NULL){
        printf("%d ",dummy->val);
        dummy = dummy->next;
    }
    printf("\n");*/

    //If there are duplicated elements, left one element and remove others
    while(cur != NULL && cur->next != NULL){
        if(cur->val == cur->next->val){
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
    }

    while(l1Ptr!=NULL){
        printf("%d ",l1Ptr->val);
        l1Ptr = l1Ptr->next;
    }

    printf("\n");
}




