#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool search(int nums[], int indexed_len, int needle) {

    indexed_len /= 2;

    if (nums[indexed_len] == needle) {
        printf("your number is found at index : %i\n", indexed_len);
        return true;
    }

    if (nums[indexed_len] < needle) {
        for(int i = 1; i < 11; i++) {
            if (nums[indexed_len - i] == needle) {
                printf("your number is found at index : %i\n", indexed_len);
                return true;
            }
        }
    }

    if (nums[indexed_len] > needle) {
        for(int i = 1; i < 11; i++) {
            if (nums[indexed_len + i] == needle) {
                printf("your number is found at index : %i\n", indexed_len);
                return true;
            }
        }
    }

    indexed_len = nums[indexed_len] < needle ? indexed_len/=2 : indexed_len + (indexed_len / 2);

    return search(nums, indexed_len, needle);
}


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("you need to write a number to search for\n");
        return false;
    }

    int needle  = atoi(argv[1]); // converting the number from char to int
    int nums[]      = {1,2,3,4,5,6,7,8,9,0};
    
    size_t nums_len = sizeof(nums) / sizeof(nums[0]);

    return search(nums, nums_len -1, needle);

}