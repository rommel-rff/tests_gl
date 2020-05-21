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
    int steps = 0;
    int number_of_stairs, giant_step, retv;
   
    if (argc != 3) {
        printf("Please enter 2 numbers\n");
        return 0;
    }
    retv = convert_str_digit_to_int(argv[1], strlen(argv[1]), &number_of_stairs);
    if (retv < 0) {
        printf("Please enter valid values(only numbers)\n");
        return 0;
    } 

    retv = convert_str_digit_to_int(argv[2], strlen(argv[2]), &giant_step);
    if (retv < 0) {
        printf("Please enter valid values(only numbers)\n");
        return 0;
    }
    
    if (number_of_stairs < 0 || giant_step < 0) {
        printf("These numbers cant be negative, please enter correct numbers\n");
        return 0;
    }

    while (number_of_stairs > 0)
    {
        number_of_stairs = number_of_stairs - giant_step - 1;
        steps++;
    }
    
    printf("%d\n", steps);
    return 0;
}
