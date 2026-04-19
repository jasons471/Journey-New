# Application for making simple calculator
num1 = input("Enter a number: ")
num2 = input("Enter another number: ")
result = int(num1) + int(num2)  # used for converting string to integer type variables
print(result)
x = input("Enter a Number: ")
y = input("Enter another Number: ")
final_answer = float(x) + float(y)  # Used for adding any type of numbers (integers,decimals)
print(final_answer)

# Upgrade time!!
N1 = float(input("Enter the first number: "))
Operator = input("Enter the desired operator: ")
N2 = float(input("Enter the second number: "))
if Operator == "+":
    print(N1 + N2)
elif Operator == "-":
    print(N1 - N2)
elif Operator == "/":
    print(N1/N2)
elif Operator == "*":
    print(N1 * N2)
else:
    print("Invalid Operator")
