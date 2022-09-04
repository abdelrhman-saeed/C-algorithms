
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int *get_search_arr_from_cli(int argc, char* argv[]) {

    if (argc < 3) {

        printf("you need to write a number to search for and a set of numbers you want to search in,"
                "seperated by a ','\nexample: 2 \"3,4,6,72,3,4,62,2\"\n");
        exit(0);
    }

    // getting the count of numbers to declare an array of nums with the coutn number
    int search_nums_len = 2;

    for(int i = 0; i < strlen(argv[2]); i++) {
        if (argv[2][i] == ',') search_nums_len++;
    }

    int *search_nums = (int*) malloc(search_nums_len  * sizeof(int));

	char *splited_nums = strtok(argv[2], ",");

    for(int i = 0; i < search_nums_len; i++) {
        search_nums[i]  = atoi(splited_nums);
        splited_nums    = strtok(NULL, ",");
    }

    search_nums[search_nums_len] = search_nums_len;
    return search_nums;
}