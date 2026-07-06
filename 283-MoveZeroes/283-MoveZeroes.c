// Last updated: 06/07/2026, 11:59:25
void moveZeroes(int* nums, int numsSize) {
    int numindex=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[numindex++]=nums[i];
        }
    }
    for(int i=numindex;i<numsSize;i++){
        nums[i]=0;
    }
}