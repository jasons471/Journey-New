#include <stdio.h>
// Include the standard input/output library
int main()  // Main function
{
    printf("Hello World!\n");
    // Print the desired string to the console
    // The \n is a newline character
    int a = 5;
    // Declare an integer variable  
    a = 10;
    // Assign the new desired string to update the existing variable 
    float pi = 3.14;
    // float variable 
    printf("The value of a is %d\n", a);
    // Print the value of the variable with the string 
    // %d is a format specifier for integers
    printf("The value of pi is %f\n", pi);
    /* %f is a format specifier for floats
    & is used to access the value of the variable */
    int b;
    printf("Enter a number: ");
    scanf("%d", &b);
    /* The scanf function is used to take input 
    from the user and store it in a variable*/
    printf("The value of b is %d\n", b);
    int c, d;
    // Declare two integer variables together
     printf("Enter the value of c: ");
     // after every line of code, there is a semicolon
    scanf("%d", &c);
    printf("Enter the value of d: ");
    scanf("%d", &d);
    int sum = c + d;
    printf("The sum of c and d is %d\n", sum);
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age >= 18)
   /*If the condition is true, 
   the code inside the block will be executed*/
    {
        printf("You are eligible to vote\n");
    }
    else
    /*If the condition is false,
    the code inside the block will be executed*/
    {
        printf("You are not eligible to vote\n");
    }
int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);
    if (marks >= 90)
    {
        printf("Grade A\n");
    }
    else if (marks >= 80)
    /* if the first condition is false,
    the code inside the else if block will be 
    executed*/
    {
        printf("Grade B\n");
    }
    else if (marks >= 70)
    {
        printf("Grade C\n");
    }
    else if (marks >= 60)
    {
        printf("Grade D\n");
    }
    else if (marks >= 40)
    {
        printf("Grade E\n");
    }
    else
    {
        printf("Grade F\n");
    }
   // Example of nested if-else statement 
    int m1;
  printf("Enter your marks: ");
  scanf("%d", &m1);
  if (m1 >= 90){
      if (m1 <= 100) {
          printf("Grade: A\n");
      } else if (m1 >= 75) {
          printf("Grade: B\n");
      } else if (m1 >= 60) {
          printf("Grade: C\n");
      }else {
          printf("grade: D\n");
      }
      } else {
              printf("Failed \n");
      }
    
    int mark;
    printf("Enter your subject mark: ");
    scanf("%d", &mark);
    switch (mark)
    /* The switch statement is used to execute
    one block of code from multiple blocks of code.
    Alternative to if-else-if ladder */
    {
    case 10:
    // functions similar to if statement
        printf("You got full marks\n");
        printf("Outstanding\n");
        // Desired output
        break;
/*Break statement is used to exit the switch 
statement*/
    case 9:
        printf("You got 9 marks\n");
        printf("Excellent\n");
        case 8:
        case 7:
/*Two cases can be clubbed together for the 
same output*/
        printf("Good\n");
        break;
    case 6:
        printf("Acceptable\n");
        break;
    case 5:
        printf("Passed by an inch\n");
        break;
    case 4:
    case 3:
    case 2:
    printf("Disastrous\n");
    break;
        case 1:
        printf("Better luck next time\n");
        break;
    default:
    // If no case matches the switch statement
    // much like else statement
        printf("Invalid marks\n");
    }
    
    // Example of nested switch statement
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    int j;
    printf("Enter another number: ");
    scanf("%d", &j);
    switch (i)
    {case 1:
        switch (j)
        {
        case 1:
            printf("The sum is 2\n");
            break;
        case 0:
            printf("The sum is 1\n");
            break;
        default:
            printf("Invalid\n");
        }
        break;
        case 0:
        switch (j)
        {  
        case 1:
            printf("The sum is 1\n");
            break;
        case 0:
            printf("The sum is 0\n");
            break;
        }
        default:
        printf("Invalid\n");
        break;
        }
    for (int j = 0; j <= 25; j = j + 5){
        printf("The value of j is %d\n", j);
        /* The for loop is used to execute 
        a block of code multiple times */
    
    }
    int z = 1;
    printf("The value of z is %d\n", z++);
/*The value of z is printed and 
then incremented by 1 */
    printf("The value of z is %d\n", ++z);
    /**The value of z is incremented by 1 and 
    then printed*/
    /* ++variable,--variable is a pre increment 
    decrement operator respectively*/
    // variable--,is a post decrement operator
    // variable++,is a post increment operator
    int k = 1;
    printf("The value of k is %d\n", k--);
    //Vice versa function of z++//
    printf("The value of k is %d\n", --k);
    // Vice versa function of z++
    int l = 0;
    while (l<= 10)
    /* The while loop is used to execute a block of 
    code as long as the condition is true */
    {
        printf("%d\n", l);
        l++;
    }
    l = 10;
    // Reset the value of l to 10
    while (l >= 0) {
        printf("%d", l);
        l--;
    }
    int m = 0;
    do {
        printf("%d\n", m);
        m++;
    } while (m <= 10); 
      {
        printf("%d\n", m);
        m--;
      }
    /*The do-while loop is used to execute a block of code at least once 
    even if the condition is false*/

    // Example of a nested loop
    int n, n1;
    printf("Enter the value: \n");
    scanf("%d %d", &n , &n1);
    if (n == 200){
        if (n1 == 100){
            printf("The value of n is 200 and n1 is 100\n");
        }
        else if (n1 == 200){
            printf("The value of n is 200 and n1 is 200\n");
        }
        else {
            printf("The value of n is 200 and n1 is neither 100 nor 200\n");
        }
    }
    
   // Example of using infinite loop
    int n2;
  int s5 = 0;
  printf("Enter a number (0 to stop)");
  while (1) {  /* This is a infinite loop until a break statement is encountered*/
      printf("Input a number: ");
      scanf("%d", &n2);
      if (n2 == 0) {
        break; // Exit the loop if the user enters 0
      }
      if (n2 > 0) {
        
      s5 += n2;
      }
}
    printf(" Sum of positive numbers: %d\n", s5);
    
int i6;
/* In for loop, declare the variable and initialize it, then
 we specify the condition to be checked, and finally
 we specify the increment or decrement operation 
 to be performed */
    for (i6=1; i<=10; i++) {
        printf ("%d ",i6);
    }
    
    // Example of a nested for loop
    int i1, j1, rows;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &rows);
    for (i1 = 1; i1 <= rows; i1++) { //Column loop
        for (j1 = 1; j1 <= i1; j1++) { // Row loop
        
            printf("* ");
        printf("\n");
        }
    }
return 0;
    // Return zero error to the operating system
}
