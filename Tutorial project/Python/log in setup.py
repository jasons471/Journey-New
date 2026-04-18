Password = "I am the password"
guess = ""
guess_count = 0
attempts = 2
while guess != Password and guess_count < attempts: 
    guess = (input("Enter password: "))
    guess_count += 1
if guess == Password:
    print("You have successfully logged in")
else:
    print("Incorrect password")