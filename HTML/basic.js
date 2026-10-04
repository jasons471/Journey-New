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
