#include<stdio.h>
#include<stdlib.h>

int *twoSum(int *nums, int numSize, int target,int *returnSize);
void twoSumTest(int *nums,int numSize,int target, int *returnSize);
int *sum(int *p, int *q);
int main(int argc,char *argv[]){
    /*int *nums;
    nums = (int *)malloc(sizeof(int) * 4);
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;*/
    int nums[4] = {2,7,11,15};
    //int numsarr[4] = {2,7,11,15};
    //nums = &numsarr;
    
    /*for(int i = 0; i < 4; i++){
        printf("%p ",&nums[i]);
    }
    printf("\n");
    */
    int target = 9;
    int numSize = 4;
    //int *returnSize = NULL;
    int returnSize = 0;
    int *result = NULL;
    result = twoSum(nums,numSize,target,&returnSize);
    //int *result = twoSum(nums,numSize,target,returnSize);
    printf("Result: [%d,%d]\n]",result[0],result[1]);
    twoSumTest(nums,numSize,target,&returnSize);
    printf("return size %d\n",nums[0]);
    free(result);

    int a = 1,b = 2;
    int *ans = NULL;
    ans = sum(&a,&b);
    printf("Sum: %d",*ans);
    free(ans);

}
int *sum(int *p,int *q){
    int *res = malloc(sizeof(int));
    *res = *p + *q;
    return res;
}
void twoSumTest(int *nums,int numSize,int target, int *returnSize){
    for(int i = 0; i < 4; i++){
        printf("%p ",&nums[i]);
    }
    printf("\n");
    int *ret = (int *)malloc(2*sizeof(int));
    printf("res[0]: %d\n",ret[0]);
}
/*int *twoSum(int *nums,int numSize, int target, int *returnSize){
    *returnSize = 2;
    int *ret = (int *)malloc(2*sizeof(int));
    //int *ret = malloc(2*sizeof(int));
    //printf("%p\n",&ret);
    return ret;
}*/
int *twoSum(int *nums,int numSize,int target, int *returnSize){
    *returnSize = 2;
    int *ret = (int*)malloc(2*sizeof(int)),tmp;
    for(int i =0 ;i < numSize;i++){
        tmp = target - nums[i];
        for(int j = i+1; j < numSize; j++){
            if(tmp == nums[j]){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    return ret;
}