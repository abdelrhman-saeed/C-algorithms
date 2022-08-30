#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


// looking for the num 0 in the array [1,2,3,4,5,6,7,8,9,0]

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("you need to write a number to search for\n");
        return false;
    }

    int search_num  = atoi(argv[1]); // converting the number from char to int
    int nums[]      = {1,2,3,4,5,6,7,8,9,0};
    
    size_t nums_len = sizeof(nums) / sizeof(nums[0]);

    for(int i = 0; i < nums_len; i++) {
        if (nums[i] == search_num) {
            printf("Found, the index of your number is : %i\n", i);
            return true;
        }
    }
    printf("Not Found\n");
}