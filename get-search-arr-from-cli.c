#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int * get_search_arr_from_cli(int argc, char* argv[]) {

    if (argc < 3) {
        printf("you need to write a number to search for and a set of numbers you want to search in, seperated by a ','\nexample: 2 \"3,4,6,72,3,4,62,2\"\n");
        return false;
    }

    // getting the count of numbers to declare an array of nums with the coutn number
    int search_nums_len = 1;

    for(int i = 0; i < strlen(argv[2]); i++) {
        if (argv[2][i] == ',') search_nums_len++;
    }

    int search_nums[search_nums_len];
	char *ptr = strtok(argv[2], ",");

    for(int i = 0; i < search_nums_len; i++) {
        search_nums[i] = atoi(ptr);
        ptr = strtok(NULL, ",");
    }

    return search_nums;
}