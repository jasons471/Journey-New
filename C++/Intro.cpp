#include <bits/stdc++.h>
/*this header file allows to call all variables
for use in the code instead of calling one 
particular header file at a time.*/
using namespace std; 
/* 'Using' function is a directive 
that allows the program to use the standard namespace. */
/* namespace is a declarative region that provides a scope 
for identifiers such as types, functions and variables.
Its primary purpose is to organize code into logical groups 
and prevent name collisions, especially in large projects or 
when using multiple libraries */
void printhello() { // Function definition
    cout << "Hello from a function!" << endl;
    /* This is a simple function that prints a message to the 
    console. It demonstrates how to define 
    and call a function in C++.*/
}
int hello() { // function with return type
    cout << "Hello World!" << endl;
    return 8; // Return statement returns a value from the function
    
}
int my_max(int n8, int n9) {
    return (n8 < n9) ? n9 : n8;
}
int power(int base, int exponent){ // function with parameters
    int p = 1; // p is the result
    for (int i = 0; i < exponent; ++i) {
        p *= base;
    }
    return p;
}
// call by reference definition
void swap(int *a, int *b);

void PrintNum(int x) { // Recursive function
        if (x <= 0) return;
        cout << "The number is: " << x << endl;
        if (x == 1) return;
        PrintNum(x - 1);
}

int main() {
cout << "Hello World!"<<endl;
// cout is used to print the desired string to the console
// The << operator is used to insert the string into the output stream
// endl is used to insert a newline character much like \n
 cout << "This is a C++ program." << " Basic"<<endl;
int a = 5;
 a+= 10;
 cout << "The value of a is " << a << endl;
cout << sizeof(a) << endl;
/* sizeof operator is used to get the 
size of the variable in bytes */
float pi = 3.14f; // must use 'f' to indicate float literal
cout << "The value of pi is " << pi << endl;
bool isTrue = true; // boolean variable
cout << "The value of isTrue is " << isTrue << endl;
//true is 1 and false is 0

// Type casting
char ch = 'a';// character variable
int value = ch; // implicit conversion from char to int
cout << "The ASCII value of " << ch << " is " << value << endl;

double d = 3.14159; // double variable
int value2 = int(d); 
// explicit conversion from double to int
/*Number here do not round off even if there is number
above 5 after the decimal. It just prints value before
decimal */
cout << "The integer value of " << d << " is " << value2 << endl;
// declare two integer variables together
int answer = 49/ double(7);
// explicit conversion from int to double
cout << "The value of answer is " << answer << endl;

int age;
cout << "Enter your age: ";
cin >> age; // cin is used to take input from the user
cout << "Your age is " << age << endl;
 int a1,b;
cout << "Enter two numbers: ";
cin >> a1 >> b; // taking input of two variables in one line
cout << "The sum of " << a1 << " and " << b << " is " << (a1 + b) << endl;
cout << "modulo " << (a1 % b) << endl;
// % operator is used to get the remainder of the division
/* for improper fraction, the value is the one 
before decimal be printed no matter whether the number
is  or above after the decimal */
cout << "The value of a1/b is " << (a1 / b) << endl;
int c = 10;
int d1 = 20;
if (c > d1 ) {
    cout << "c is greater than d1" << endl;
} else if (c < d1) {
    cout << "c is less than d1" << endl;
} else if (c == d1) {
    cout << "c is equal to d1" << endl;
} else {
    cout << "This will never be printed" << endl;
}
int w,x;
cout << "Enter two numbers: ";
cin >> w >> x;
cout << (w > x) << endl;
cout << (w < x) << endl;
cout << (w == x) << endl;
int y = 10;
int z = y%3; // modulo operator
cout << "The value of z is " << z << endl;

// Unary operators
 int f;
cout << "Enter a number: ";
cin >> f;
f++; // Post increment operator
cout << "The value of f after incrementing is " << f << endl;
f--; // Post decrement operator
cout << "The value of f after decrementing is " << f << endl;
/* For post increment and post decrement,
the value is printed first and then incremented or decremented.
*/
int g = ++f; // pre increment operator
cout << "The value of g after pre incrementing f is " << g << endl;
g = --f; // pre decrement operator
cout << "The value of g after pre decrementing f is " << g << endl;
/* for pre increment and pre decrement,
the value is incremented or decremented first and then printed.
*/
double h = 5.25515;
cout << std::fixed << std::setprecision(3) << h << endl; 
/* set precision to 3 decimal places. 
:: is called scope resolution
*/
string s = "Hello, World!";
int length = s.size(); 
/* size() function returns the length of the string
including spaces and punctuation.
Alternatively, you can use s.length() which is equivalent.
but length is a member function of the string class
whereas size is a member function of the vector class. and
can be used in most of the cases.
*/
cout << "The length of the string is " << length << endl;
char valueChar = 'A'; 
char lowercaseValue = tolower(valueChar); // convert to lowercase
cout << "The lowercase value of " << valueChar << " is " << lowercaseValue << endl;
char uppercaseValue = toupper(lowercaseValue); 
// convert back to uppercase
cout << "The uppercase value of " << lowercaseValue << " is " << uppercaseValue << endl;
string str = "Hello World!";
transform(str.begin(), str.end(), str.begin(), ::toupper);
// convert the string to uppercase using transform function
/*string begin to end, it scans the variable, and then
applies the function to each character in the string from
begin to end.
*/
cout << "The uppercase string is " << str << endl;
if (str.empty()) { 
// empty() function returns true if the string is empty
    cout << "The string is empty" << endl;
} else {
    cout << "The string is not empty" << endl;
}
if (isupper(valueChar)) { 
// isupper() function checks if the character is uppercase
    cout << valueChar << " is an uppercase character" << endl;
} else if (islower(valueChar)) { 
    // islower() function checks if the character is lowercase
    cout << valueChar << " is a lowercase character" << endl;   
} else {
    cout << valueChar << " is not an uppercase character" << endl;
}
string str2;
cout << "Enter a string: ";
cin >> str2; 
int value3 = 0;
try {
    value3 = stoi(str2);
    cout << "The integer value of the string is " << value3 << endl;
} catch (const invalid_argument &e) {
    cout << "Invalid integer string: '" << str2 << "'" << endl;
} catch (const out_of_range &e) {
    cout << "Integer out of range for string: '" << str2 << "'" << endl;
}

//logical operators
// && (logical AND), || (logical OR), ! (logical NOT)
if (w > 0 && x > 0) { // use of if else if and else
    cout << "Both w and x are positive" << endl;
} else if (w < 0 || x < 0) {
    cout << "At least one of w or x is negative" << endl;
} else {
    cout << "Neither w nor x is positive or negative" << endl;
} 

// loops
for (int i = 0; i < 5; i++) { 
    cout << "This is iteration number " << i + 1 << endl;
}   
int count = 0;
while (count < 5) { // while loop
    cout << "This is iteration number " << count + 1 << endl;
    count++;
}
do{ // do-while loop
    cout << "This is iteration number " << count + 1 << endl;
    count++;
} while (count < 10); // condition for do-while loop
int value8;
cout << "Enter a number: ";
cin >> value8; 
cout << (value8 >= 0 ? "n is positive" : "n is not positive") << endl;
/* Ternary operator (conditional operator) 
is used to check a condition and return a value*/
printhello(); 
// Function call / Invoke
int returnValue = hello();
// Function call with return value
cout << "The return value of the hello function is " << returnValue << endl;
int n8, n9, maximum;
cout<<"Enter two numbers to find the maximum: ";
cin >> n8 >> n9;
maximum = my_max(n8, n9);
cout<<"Maximum = "<<maximum<<endl;
int b4, e4;
cout << "Enter base and exponent: ";
cin >> b4 >> e4;
cout << "Result using power function: " << power(b4, e4) << endl;
//call by reference invoke
int a2 = 5, b2 = 10;
cout << "Before swap: a2 = " << a2 << ", b2 = " << b2 << endl;
swap(&a2, &b2); // Call by reference  
// & is the alias operator, it is used to get the address of the variable
// Call by reference means passing the address of the variable to the function
cout << "After swap: a2 = " << a2 << ", b2 = " << b2 << endl;
// Recursive function call
PrintNum(5); // Call the recursive function with an argument

// Nested loops
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << "i: " << i << ", j: " << j << endl;
    }
}

cin.ignore();
 // to clear the newline character from the input buffer
string name;
    getline(cin, name);
/* getline() function is used to take input of string 
with spaces */
cout << name;
 
//Arrays
int marks[5] = {90, 85, 78, 92, 88}; 
// Array declaration and initialization
/*setting values in array is not necessary but for mentioning
how many space are we going to take for the array
*/
cout<< marks[1] << endl; // Accessing array elements
/* Array index starts from 0, 
so marks[1] is the second element*/
int size = sizeof(marks) / sizeof(marks[0]);
// sizeof operator is used to get the size of the array
/* sizeof(marks[0]) gives the size of one element of the array
and sizeof(marks) gives the size of the entire array.
So, dividing the size of the entire array by the size 
of one element gives the number of elements in the array.
*/
// Looping through the array
for (int i = 0; i < size; i++) {
    cout << "marks[" << i << "] = " << marks[i] << endl;
}
int sz = 6;
vector<int> arr(sz); // Array declaration using vector for portability
for (int i = 0; i < sz; i++) {
    cout << "Enter element " << i + 1 << ": ";
    cin >> arr[i]; 
}
for (int i = 0; i < sz; i++) {
    cout << arr[i] << " "; 
}
cout<<endl;
//Nested Arrays
int nestedArray[2][3] = { {1, 2, 3}, {4, 5, 6} };
/* the first element is in 0th array 
and its position is 0th index within 0th array */
// 2D array declaration and initialization
for (int i = 0; i < 2; i++) { // to loop through rows
    for (int j = 0; j < 3; j++) { // to loop through columns
        // Accessing elements of the 2D array
        cout << "nestedArray[" << i << "][" << j << "] = " << nestedArray[i][j] << endl;
    }
}

// Vectors
vector<int> vec = {25, 69, 96}; // Vector declaration
cout << "Vector elements: ";
for (int i :vec) { 
    // Range-based for loop to iterate through vector
  cout<< i <<endl; // Accessing vector elements
}
vector<float> vec2(5, 7.0); 
// Vector declaration with float values on 5 elements
cout << "Vector 2 elements: ";
for (int i = 0; i < vec2.size(); i++) {
    cout << vec2[i] << " "<<endl; // Accessing vector elements
}

cout<< vec[0] << endl; 
// Accessing particular element of vector

cout << "Size of vec: " << vec.size() << endl;
// size() function returns the number of elements in the vector
vector<int> vec3; // Empty vector declaration
vec3.push_back(10); // Adding an element to the vector
vec3.push_back(20); 
vec3. pop_back(); // Removing the last element from the vector
cout << "Elements in vec3 after push_back and pop_back: ";  
for (int i : vec3) {
    cout << i << " "; 
}
cout<< vec.front()<< endl;
// front() function returns the first element of the vector
cout<< vec.back()<< endl;
// back() function returns the last element of the vector
cout<<vec2.at(2) << endl;
// at() function returns the element at the specified index
return 0;
}
//Call by reference function 
void swap(int *a, int *b) {
    int temp = *a; // dereference the pointers to get the values
    *a = *b; // assign the value of b to a (* variable is used to dereference the pointer)
    *b = temp; // assign the value of temp to b
    // This swaps the values of a and b using pointers
}


