#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int *get_search_arr_from_cli();

bool search(int target, int nums[], int start, int end) {


    if (nums[start] == target) {
        printf("target found at index : %i", start);
        return true;
    }


    if (target < nums[start]) {
        return search(target, nums, start / 2, start);
    }

    if (target > nums[start]) {
        return search(target, nums, start + (end - start) / 2, end);
    }

    printf("target not found");
    return false;

}

int main(int argc, char* argv[]) {

    int *nums = get_search_arr_from_cli(argc, argv);

    int nums_len = sizeof(nums) / sizeof(nums[0]);

    return search(atoi(argv[1]), nums, nums_len / 2, nums_len);
}