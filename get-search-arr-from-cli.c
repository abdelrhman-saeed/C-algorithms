
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void prerequestes(int argc, int search_nums_len) {

    if (argc < 3) {
        printf("you need to write a number to search for and a set of numbers you want to search in,"
                "seperated by a ','\nexample: 2 \"3,4,6,72,3,4,62,2\"\n");
        exit(1);
    }

    if (search_nums_len < 2) {
        printf("your search array is not well formed, its should be like : \nexample : \"3,4,6,72,3,4,62,2\"\n");
        exit(1);
    }
}


int get_search_arr_len(char search_arr_as_text[]) {

    int search_nums_len = 0;

    for(int i = 0; i < strlen(search_arr_as_text); i++) {
        if (search_arr_as_text[i] == ',') search_nums_len++;
    }

    return ++search_nums_len;
}


int *get_search_arr_from_cli(char search_arr_as_text[], int search_nums_len) {

    int *search_nums    = (int*) malloc(search_nums_len  * sizeof(int));
	char *splited_nums  = strtok(search_arr_as_text, ",");

    for(int i = 0; i < search_nums_len; i++)
    {
        search_nums[i]  = atoi(splited_nums);
        splited_nums    = strtok(NULL, ",");
    }

    return search_nums;
}