//printing
console.log("Hello, World!");
//this allows you to print messages to the console for debugging purposes
console.log("%cThis is a basic JavaScript file.", "color: blue; font-size: 16px; font-weight: bold;");
//you can also style your console messages using CSS

//Variables
var name = "Abdul";
// create a variable called name and assign it a value.
console.log("Hello " + name + "!");

//Operators
var num1 = 10;
var num2 = 5;
var sum = num1 + num2;
console.log("The sum of " + num1 + " and " + num2 + " is: " + sum);
console.log("The difference of " + num1 + " and " + num2 + " is: " + (num1 - num2));
console.log("The product of " + num1 + " and " + num2 + " is: " + (num1 * num2));
console.log("The quotient of " + num1 + " and " + num2 + " is: " + (num1 / num2));
console.log(3 % 2); 
console.log(3>2); 
console.log(3==2);
console.log(3!=2);
console.log(3>=2);
console.log(4**2);
var x = 5+20*(60*4)+892-55;
//this calculation is followed using PEMDAS principle
console.log(x);

//Functions
function add(a, b) {
    return a + b;
}
console.log(add(5, 10));
// the values passed to the function are called arguments, and the values defined in the function are called parameters
//Arrays
var num = [1, 2, 3, 4, 5];
function sumArray(arr) {
    var total = 0; //initialize a variable to hold the sum of the array elements
    //loop through the array and add each element to the total
    for (var i = 0; i < arr.length; i++) {
        total += arr[i]; //add each element of the array to the total
    }
    return total;
}
console.log(sumArray(num));

// Nested Loops
for (var i = 1; i <= 5; i++) { //outer loop
    for (var j = 1; j <= 5; j++) { //inner loop
        console.log(i + " " + j); //print the values of i and j
    }
}
while (true) { //infinite loop
    console.log("This is an infinite loop.");
    break; //break statement allows you to exit the loop
}

// Conditional Statements
var age = 18;
if (age >= 18) { //check if the condition is true or false
    console.log("You are an adult.");
} else { // if the condition is false, execute this block of code
    console.log("You are a minor.");
}
while (age < 21) { //while loop will continue to execute as long as the condition is true
    console.log("You are not old enough to drink.");
    age++; //++ increment operator
}
if (age >= 21) {
    console.log("You are old enough to drink.");
}
else if (age >= 18) {//else if statement allows you to check multiple conditions
    console.log("You are old enough to vote.");
}
else {
    console.log("You are a minor.");
}
switch (age) { //switch statement allows you to check multiple conditions
    case 18: 
    //case statement are individual conditions that are checked against the value of the switch statement
        console.log("You are 18 years old.");
        break; //break statement allows you to exit the switch statement
    case 21:
        console.log("You are 21 years old.");
        break;  
    default: 
    // similar to else statement, it will execute if none of the cases match the value of the switch statement
        console.log("You are neither 18 nor 21 years old.");
}

// Objects
var person = { //object literal
    name: "Abdul",
    age: 18,   
    //can hold any type of data, including other objects and functions
    greet: function() { // used to define a method within the object
        console.log("Hello, my name is " + this.name + " and I am " + this.age + " years old.");
    }
};
person.greet();

//Math Object
console.log(Math.PI);
var randomNum = Math.floor(Math.random() * 10) + 1; //generate a random number between 1 and 10
console.log(randomNum);
// there are many other methods available in the Math object, such as Math.sqrt(), Math.pow(), Math.abs(), etc.

//typeof operator
console.log(typeof name);//typeof operator allows you to check the data type of a variable 
console.log(typeof age);

//Throw, Try, and Catch blocks
try { //try block allows you to test a block of code for errors
    throw new Error("This is a custom error message."); 
    //throw statement allows you to create a custom error message
}
catch (error) { //catch block allows you to handle the error
    console.log(error.message); //error object contains information about the error that occurred
}
console.log("This code will still run even if an error occurs in the try block.");

//undefined null &empty values
var undefinedVar; //undefined variable
console.log(undefinedVar);  
var nullVar = null; //null variable
console.log(nullVar);  
var emptyString = "";
console.log(emptyString);
 //Error handling
try {
    var result = 10 / 0; //this will not throw an error, but will return Infinity
    if (!isFinite(result)) { //isFinite() method checks if the value is finite
        throw new Error("Division by zero is not allowed."); //throw statement allows you to create a custom error message
    }
} catch (error) {
    console.log(error.message);
}