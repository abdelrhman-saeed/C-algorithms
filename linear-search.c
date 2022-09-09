#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void prerequestes(int argc, int search_nums_len);

int get_search_arr_len(char search_arr_as_text[]);
int *get_search_arr_from_cli(char search_arr_as_text[], int search_nums_len);


bool search(int nums[], int nums_len , int target) {

    for(int i = 0; i < nums_len; i++)
    {
        if (nums[i] == target) {
            printf("Found, the index of your number is : %i\n", i);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;

}

int main(int argc, char* argv[]) {

    int nums_len = get_search_arr_len(argv[2]); // passing the search array from the cli, formated as "1,2,3,4,5"
    prerequestes(argc, nums_len); // executing the prerequests so if the input is invalid formatted the execution stops with a warning

    int * nums = get_search_arr_from_cli(argv[2], nums_len); // passing the search array with its length

    search(nums, nums_len, atoi(argv[1])); // executing the linear search algorithm
}