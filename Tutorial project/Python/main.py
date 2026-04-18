# '#' is used for single line comments

# INTRODUCTION
print("Hello World") # Used for print a following input

# VARIABLES AND ITS FUNCTIONS
character_name = 'Goerge' # Variables where we store data
# '' or "" can be used for storing string data in a variable
character_age = '31'
print("There was a man named " + character_name + ", ")  
'''
Format for putting variables along with sentences
'''
# ''' used for multiple line comments
print('He is ' + character_age + ' years old')
x = "I like being alone"
print(x.lower()) # used for lowercase the variable
print(x.upper().isupper()) # upper() vice versa function for lower()
"""
.isupper() function for checking whether the value is in uppercase 
or not. Gives value in Boolean (True/False) value
"""
print(x.lower().islower()) 
"""
.islower() vice versa function for .isupper()
"""
print(len(x)) # Counts number of letters including spaces
print(x.index("being"))  
"""Finds the desired letter that appears first in the variable
"""
print(x.replace("I like", "Sandy likes")) 
# This function used for replacing a variable with the desired one

# NUMBERS AND ITS FUNCTIONS
print(2.854)
print((444 + 99) * 4 + 2 - 5 / 8) 
"""
will solve the calculation according to PEMDAS rule 
(Parenthesis,Exponential,Multiplication,Addition,Subtraction) 
in this order
"""
print(135 + 555)
pizza = 10
People = 3
print("leftover", pizza % People)  
''' 
This is modulus operator/ mod operator. 
the number before mod sign is divided by number after mod 
to give remainder
'''
print(str(1000) + " is a huge number")  
'''
converts the data type into string 
so that it can be used with strings
'''
a = -855
print(abs(a))     # Gives absolute value of a number
print(pow(5, 5))  # Gives the value of the power
print(max(8, -5)) # finds the largest value
print(min(8, -5)) # finds the smallest value
o = 852.845
print(round(o))   # Rounds of to whole number
e = float(input("Enter a number: ")) # input() used for taking input
# float() is used for adding any type of numbers (integers,decimals)
t = float(input("Enter a number: ")) 
q = e + t
print(q)

from math import *
from pickle import BINPUT
'''
Used to import all the functions from math module
pickle module is used for serializing and de-serializing a Python object structure
BINPUT is used for writing a pickled object to a file
'''
d = int(input("please type number :"))
s = int(input("Please type number :")) 
# int() is used to convert current data type to integer
z = pow(d, 2) + pow(s, 2)
print(sqrt(z))  # Squares the value
print(floor(695.288)) # Rounds the value DOWN the nearest integer
print(ceil(3.44))     # Rounds the value UP the nearest integer
print("Hello\nWorld") # Only prints unto the desired value
print("Hello\"World\"") # Used for adding quotation marks/ semicolon
#\n is used for adding a new line in the output
v = "Shafin"
print(v + " nice to meet you")
print(len(v)) # Counts the number of letters in the variable
print(len("nice to meet you"))
i = "Bolod Creed"
print(i.replace("Bolod", "Assassin's"))

# LIST AND ITS FUNCTIONS
foods = ["Tea", "Noodles", "Rice"] 
'''
list function where first element in the list is positioned as 0 
and so on
'''
print(foods)
print(foods[0:2]) 
'''
It will give desired element from the list 
starting from the initial position of the chosen data
(element before':') upto 
and not including the chosen position (element after ':')
'''
foods[2] = "Roast" 
'''
function used to change a particular element 
with the desired element in a list
'''
print(foods)
charm = ["strange", "strange", "anti-strange", "up"]
foods.extend(charm)  # Used to add one list at the end of other list
print(foods)
charm.append("Down") # Used to add element to the end of list
print(charm)
charm.insert(0, "anti-up") 
'''
used for placing element in a list 
at a particular position
'''
print(charm)
charm.remove("anti-up") 
# used to remove a particular element from a list
print(charm)
charm.pop()  # Used to remove the last element of a list
print(charm)
print(charm.count('strange'))  
# count() used to count how many of the same element is in the list
charm.sort() # sorts the elements in ascending order
print(charm)
charm.reverse() 
# Sorts the elements in descending order. / Vice versa of .sort()
print(charm)
charmx = charm.copy() 
'''used to create copy of elements of a list into new variable
'''
print(charmx)
charm.clear()
print(charm)

# TUPLES
Numbers = (2, 3, "five")
print(Numbers[2]) # Used to print the desired element in a tuple
print(type(Numbers)) # Used to print the type of the variable
Coordinate = tuple(("four", "five")) 
print(Coordinate)

'''Tuples are immutable,so they cannot be modified, replaced. 
however len() function and type() can be used
'''

# FUNCTIONS
def say_hi():  # used for calling a function
    print("Hey there!!")
say_hi()

def Hola(name): # Setting Parameter
    print("Hello " + name)
Hola("Shaf")

# RETURN STATEMENT
def square(number):
    return number * number   
result = square(4)
print(result)

# IF STATEMENT
raining = True # Given input
if raining: 
   print("Wear your sunglass")
else:  
    """"
    Used when given input does not fulfil the condition 
    in 'if statement'
    """
    print("Grab an umbrella")
is_correct = True
is_long = False
if is_long or is_correct:  
    """Used when either of the parameters are true"""
    print("the math is either too long or it is correct or maybe both")
else:
    print("the math is either short or incorrect or maybe both")
if is_long and is_correct: # Used when both parameters are true
    print("The math is long and correct")
elif is_long and not is_correct:
    print("the math is long but incorrect") 
elif not is_long and is_correct: 
    """
    Used when the first parameter is false 
    and the second parameter is true
    """
    print("The math is short but correct")
else:
    print("The math is neither long nor correct")
    
 # USING COMPARISONS FROM IF STATEMENTS
def max(a, b, c):
    if a > b and a > c:
        return a
    elif b <= a and b <= c:
        return b
    elif b != a and b == c:
        return c
print(max(20, 10, 40)) 
"""
<, >, >=, <=,!=, == 
are comparison operators
"""
        
# DICTIONARY
general_things = {
    "food": "Chowmein", # it is in the format of (key : value) pair
    "car": 'Lamborghini', # , is used to add more (key : value) pairs
    "toy": "Baby doll"
}
print(general_things["toy"])
print(general_things.get("food")) # 
'''
[.get()] another method of calling a value from dictionary
'''
print(general_things.get("abc", "Unknown key")) 
''' 
Can be done to print a value for a certain key 
even though it is not in dictionary
'''

# LOOPS
l = int(input("Enter a Number: "))
while l <= 20:
    print(l)
    l += 8  
    '''
    (while)' used to execute a block of code 
    as long as the condition is true
    '''
    """
    (+=) is used to add the value to the current value. 
    It is same as l = l + 8.
    """
# this is the indexing variable
print("loop over")
Y = int(input("Enter a number: ")) 
while Y < 25:
    print(Y)
    if Y == 5:
        break # 'break' is used to stop the loop from running.
    Y += 5
print("loop done")
Z = int(input("Enter a number: "))
while Z < 30:
    Z += 5
    if Z == 15:
        continue # 
    '''
    (continue) is used to skip the current iteration 
    and continue with the next iteration
    '''
    print(Z)
print("Current objective is done")
foods = ["Tea", "Noodles", "Rice"]
for food in foods: # 'for' loop is used to iterate over a sequence
    print(food)
for index in range(5,15 ):
     print(index)
for index in range(len(foods)): 
    print(foods[index])
for index in range(7):
    if index == 3:
        print("Three")
        continue
    if index == 5:
        print("Five")
        break
    print(index) 
"""
range() function is used to generate 
a sequence of numbers from 0/given number 
upto the last given number 
excluding the last given number
"""
    
# EXPONENT FUNCTIONS
def raise_to_power(base, power):
    result = 1
    for index in range(power):
        result = result * base
    return result
print(raise_to_power(3, 3)) 
    
print(raise_to_power(3, 3)) 
"""
This loop is used to multiply the base by itself 
for the number of times the power is given
"""
    
# 2D LISTS AND NESTED LOOPS
grid = [
    [5, 2, 3],
    [6, 5, 8],
    [7, 0, 9],
    [1]
]
print(grid[0][1]) # Used to print the desired element from the list
for row in grid:
    for column in row:
        print(column) # Used to print all the elements in the list

# COMMENTS
# This is a single line comment
'''
Comments can also be presented in multiple lines
using triple/ double quotation marks
'''

# TRY AND EXCEPT
try: # Used to test a block of code for errors
   value = 10 / 0
   NUMBER_1 = int(input("Enter a number: "))
   NUMBER_2 = int(input("Enter a number: "))
   R = NUMBER_1 + NUMBER_2
   print(R)
except ZeroDivisionError as err: # type: ignore 
    print(err) #'as' is used to print the error message
except ValueError:
    # Used to handle the error
    print("Not correct input") 

# READING FILES
"""
MODES
'r' is used to read the file
'w' is used to overwrite the file
'a' is used to append the file 
or add new data to the file
'r+' is used to read and write the file
"""
# open("[file name with file type]", "[mode]")
personal_file = open("Python/personal.txt","r")
# for opening the file
print(personal_file.read())
# used to read the file
print(personal_file.readable())
'''
used to check whether the file is readable 
or not
'''
print(personal_file.readline())
# used to read the first line of the file
personal_file.seek(0) 
# used to reset the reading position of the file
print(personal_file.readlines()[0])
'''
used to read multiple lines in a 
list and print the desired line
'''
personal_file.seek(0)
for line in personal_file:
    print(line)
personal_file.close() # used to close the file

# WRITING TO FILES
personal_file = open("Python/personal.txt", "a")
personal_file.write(" Unip - Ally \n")
# used to add data to the file
# \n is used to add a new line
personal_file.write("Kelly - Customer Care")
personal_file.close()
personal_file = open("Python/personal.txt", "w")
personal_file.write("Ovi - Peasant")
personal_file.close()
personal_file = open("Python/personal for testing.txt", "w")
# used to create a new file
personal_file.close()
'''
reading and writing to files can be done in the same file using 'r+' mode
r is used for reading and writing to the file.
w is used for overwriting the file. 
a is used for appending the file.
w+ is used for overwriting and reading the file.
a+ is used for appending and reading the file.
'''

# MODULES AND PIP
import Useful 
print(Useful.roll_dice(3))
# useful is the name of the module and roll_dice is the function in that module
'''
useful module is used for generating random numbers between 1 and 6 for the number of times given in the parameter
roll_dice is the function in the useful module that generates random numbers between 1 and 6 for the number of times given in the parameter
'''

# CLASS AND ITS FUNCTIONS
class Horse: # used to create a class
    sound = "neigh" # class variable
horse1 = Horse() # used to create an object
print(horse1.sound) # used to access the class variable

class student:
    def __init__(self, name, gpa, major): 
        # used to initialize the object
        self.name = name # instance variable
        self.gpa = gpa
        self.major = major
    def on_honor_roll(self): 
        # used to create a function
        if self.gpa >= 3.5:
            return True
        else:
            return False
student1 = student("Shafin", 3.4, "CSE")
student2 = student("Shahriar", 3.8, "EEE")
print(student1.name)
print(student1.on_honor_roll())

# INHERITANCE
class Chef:
    def make_beef(self):
        print("The chef makes beef")
    def make_salad(self):
        print("The chef makes salad")
    def make_special_dish(self):
        print("The chef makes sphagetti")
myChef = Chef()
myChef.make_special_dish()
class SpanishChef(Chef): # used to inherit the class
    def make_churros(self):
        print("The chef makes churros")
mySpanishChef = SpanishChef()
mySpanishChef.make_special_dish()
mySpanishChef.make_churros()   
       