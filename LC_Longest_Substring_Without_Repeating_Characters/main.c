#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lengthOfLongestSubstring(char * s){
    int *ht = (int *)malloc(sizeof(int) * 128);
    for(int i = 0; i < 127; i++){
        ht[i] = -1;
    }
    int max=0,strsize=strlen(s),substring_start=0;
    for(int i=0;i<strsize;i++){
        printf("%d ",ht[s[i]]);
        if((ht[s[i]])>=substring_start){ //在子字串裡了
            substring_start=ht[s[i]]+1;
            ht[s[i]]=i;
        }
        else{  //不在子字串裡
            ht[s[i]]=i;
            if(i-substring_start+1>max)max=i-substring_start+1;
        }
    }
    printf("\n");
    return max;
}

int main(int argc,char *argv[]){
    char *input = "aaabbscb";
    int length = lengthOfLongestSubstring(input);
    printf("Number is: %d\n",length);   
}