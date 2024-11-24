#include <stdio.h>

/*
This program displays Pascal's Triangle to the user up to 28 levels

1. Ask the user how many levels they want
2. Make the triangle
3. Display the triangle to the user
*/
void makeTriangle(int levels, int triangle[levels][levels]) {
/*
This function creates Pascal's Triangle and stores it in a matrix
@levels: The number of levels in Pascal's Triangle we are making
@triangle[levels][levels]: The triangle/matrix where we are storing the values in

@i: iterating through the levels
@j: iterating through the columns of each row
*/
    for (int i=0; i<levels; i++) {
        /* First level should just be 1 */
        if (i == 0) {
            triangle[0][0] = 1;

        /* Second level should be 1 1*/
        } else if (i == 1) {
            triangle[1][0] = 1;
            triangle[1][1] = 1;

        /* For every other level*/
        } else {
            for (int j=1; j<i; j++) {
                /* The first index of every row should be 1 */
                triangle[i][0] = 1;
                /* The last index of every row should be 1 */
                triangle[i][i] = 1;
                /* Every other index should be the value of the last row's added together */
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }
}


void printTriangle(int levels, int triangle[levels][levels]) {
/*
This function displays the triangle to the user
@levels: the number of levels in Pascal's Triangle we are making
@triangle[levels][levels]: The triangle with the stored values that we are displaying

@i: iterations for the levels
@j: iteration for the columns (stops at the length of levels so we don't print those values)
*/
    for (int i = 0; i < levels; i++) {
        /* Doesn't print out zeros or past the length of levels*/
        for (int j = 0; j <= i; j++) {
            if (triangle[i][j] != 0) {
                printf("%d ", triangle[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    /*
    This function organizes the entire program
    1. Ask for user input
    2. Declare triangle size from input
    3. Create the triangle
    4. Display the triangle to the user
    @levels: the number of levels or rows the triangle will have
    @triangle[levels][levels]: the matrix that will store Pascal's Triangle
    */
    int levels;

    /* Ask for user input */
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf(" %d", &levels);

    /* Declare triangle size*/
    int triangle[levels][levels];

    /* Make the triangle */
    makeTriangle(levels, triangle);

    /* Display the triangle to the user */
    printTriangle(levels, triangle);


    return 0;
}