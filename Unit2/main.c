#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_str_digit_to_int( char *input_data, int input_len,  int *output_value  )
{
    int idx = 0, retv = 0;
    while (idx < input_len && !retv) {
        if (idx == 0 && (input_data[idx] == '+' || input_data[idx] == '-')) {
            /* First digit + and - is a valid data. Do nothing. */
        } else if (input_data[idx] >= '0' && input_data[idx] <= '9') {
            /* Check every digit of string for valid data(only numbers). Do nothing. */
        } else {
            /* Code of mistake, 0 - string is correct, -1 - incorrect. */
            retv = -1;
        } 
        idx++;
    }
 
    if (!retv) {
        *output_value = atoi(input_data);
    }
    return retv;
}
int main( int argc, char *argv[] )
{
    int length_of_cables = 0;
    int number_of_spans, distance_between_spans, retv;
   
    if (argc != 3) {
        printf("Please enter 2 numbers\n");
        return 0;
    }
    retv = convert_str_digit_to_int(argv[1], strlen(argv[1]), &number_of_spans);
    if (retv < 0) {
        printf("Please enter valid values(only numbers)\n");
        return 0;
    } 

    retv = convert_str_digit_to_int(argv[2], strlen(argv[2]), &distance_between_spans);
    if (retv < 0) {
        printf("Please enter valid values(only numbers)\n");
        return 0;
    }
    
    if (number_of_spans < 0 || distance_between_spans < 0) {
        printf("These numbers cant be negative, please enter correct numbers\n");
        return 0;
    }

    length_of_cables = (( distance_between_spans + number_of_spans*distance_between_spans )*number_of_spans )>>1;
    /*This task can be solve by using math formula of aryphmetic progression*/

    printf("%d\n", length_of_cables);
    return 0;
}
