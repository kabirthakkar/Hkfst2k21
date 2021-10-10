

## Simple Menu for Hacktoberfest 2021


# 1 - Program that requests a number and generates the multiplication table up to 12 of said number.
# 2 - Program that you request Enter a number from 1 to 7 and say to which day of the week it corresponds, 1 being Sunday.
# 3 - A program that asks for a number and tells you if it is odd or even.
# 4 - A program that requests a string of characters and tells you the number of characters entered.
# 5 - Exit

def generateMultTable(number):
    for i in range(13):
        print(f'{i} x {number} = {i*number}')

def dayOfWeek(number):
    match number:
        case 1: 
            print("Sunday")
        case 2: 
            print("Monday")
        case 3: 
            print("Tuesday")
        case 4: 
            print("Wednesday")
        case 5: 
            print("Thursday")
        case 6: 
            print("Friday")
        case 7: 
            print("Saturday")


def isImparOrPar(number):
    if(number % 2 == 0):
        print(f"{number} is Par")
    else :
        print(f"{number} is Impar")


def inputLength(string):
    print(f'\nThe length of your sentence is {len(string)}')



while(1):
    print('\nWelcome to the Menu, Select your Desired Program with the corresponding number\n')
    print('1 - Multiplication table up to 12')
    print('2 - Day of the Week')
    print('3 - Number is par or Impar')
    print('4 - Number of characters entered')
    print('5 - Exit\n')
   
    x = int(input("Enter the desired number: "))
   
    if x == 5 :
        break
    elif x == 4:         
        inputLength(string = str(input('\nEnter a phrase: ')))
    elif x == 3:         
        isImparOrPar(number = int(input('\nEnter a number: ')))
    elif x == 2:         
        dayOfWeek(number = int(input('\nEnter a number: ')))
    elif x == 1:         
        generateMultTable(number = int(input('\nEnter a number: ')))
    else:
        print('Invalid Number')
        continue
    