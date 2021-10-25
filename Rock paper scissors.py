Real Python

Make Your First Python Game: Rock, Paper, Scissors!
Make Your First Python Game: Rock, Paper, Scissors!
by Chris Wilkerson  Jan 18, 2021 4 Comments  basics gamedev python
Tweet Share Email
Table of Contents

What Is Rock Paper Scissors?
Play a Single Game of Rock Paper Scissors in Python
Take User Input
Make the Computer Choose
Determine a Winner
Play Several Games in a Row
Describe an Action With enum.IntEnum
The Flow(chart) of Your Program
Split Your Code Into Functions
Rock Paper Scissors … Lizard Spock
Conclusion
 Remove ads
 Watch Now This tutorial has a related video course created by the Real Python team. Watch it together with the written tutorial to deepen your understanding: Rock, Paper, Scissors With Python: A Command Line Game

Game programming is a great way to learn how to program. You use many tools that you’ll see in the real world, plus you get to play a game to test your results! An ideal game to start your Python game programming journey is rock paper scissors.

In this tutorial, you’ll learn how to:

Code your own rock paper scissors game
Take in user input with input()
Play several games in a row using a while loop
Clean up your code with Enum and functions
Define more complex rules with a dictionary
Free Bonus: 5 Thoughts On Python Mastery, a free course for Python developers that shows you the roadmap and the mindset you’ll need to take your Python skills to the next level.

What Is Rock Paper Scissors?
You may have played rock paper scissors before. Maybe you’ve used it to decide who pays for dinner or who gets first choice of players for a team.

If you’re unfamiliar, rock paper scissors is a hand game for two or more players. Participants say “rock, paper, scissors” and then simultaneously form their hands into the shape of a rock (a fist), a piece of paper (palm facing downward), or a pair of scissors (two fingers extended). The rules are straightforward:

Rock smashes scissors.
Paper covers rock.
Scissors cut paper.
Now that you have the rules down, you can start thinking about how they might translate to Python code.


 Remove ads
Play a Single Game of Rock Paper Scissors in Python
Using the description and rules above, you can make a game of rock paper scissors. Before you dive in, you’re going to need to import the module you’ll use to simulate the computer’s choices:

import random
Awesome! Now you’re able to use the different tools inside random to randomize the computer’s actions in the game. Now what? Since your users will also need to be able to choose their actions, the first logical thing you need is a way to take in user input.

Take User Input
Taking input from a user is pretty straightforward in Python. The goal here is to ask the user what they would like to choose as an action and then assign that choice to a variable:

user_action = input("Enter a choice (rock, paper, scissors): ")
This will prompt the user to enter a selection and save it to a variable for later use. Now that the user has selected an action, the computer needs to decide what to do.

Make the Computer Choose
A competitive game of rock paper scissors involves strategy. Rather than trying to develop a model for that, though, you can save yourself some time by having the computer select a random action. Random selections are a great way to have the computer choose a pseudorandom value.

You can use random.choice() to have the computer randomly select between the actions:

possible_actions = ["rock", "paper", "scissors"]
computer_action = random.choice(possible_actions)
This allows a random element to be selected from the list. You can also print the choices that the user and the computer made:

print(f"\nYou chose {user_action}, computer chose {computer_action}.\n")
Printing the user and computer actions can be helpful to the user, and it can also help you debug later on in case something isn’t quite right with the outcome.

Determine a Winner
Now that both players have made their choice, you just need a way to decide who wins. Using an if … elif … else block, you can compare players’ choices and determine a winner:

if user_action == computer_action:
    print(f"Both players selected {user_action}. It's a tie!")
elif user_action == "rock":
    if computer_action == "scissors":
        print("Rock smashes scissors! You win!")
    else:
        print("Paper covers rock! You lose.")
elif user_action == "paper":
    if computer_action == "rock":
        print("Paper covers rock! You win!")
    else:
        print("Scissors cuts paper! You lose.")
elif user_action == "scissors":
    if computer_action == "paper":
        print("Scissors cuts paper! You win!")
    else:
        print("Rock smashes scissors! You lose.")
By comparing the tie condition first, you get rid of quite a few cases. If you didn’t do that, then you’d need to check each possible action for user_action and compare it against each possible action for computer_action. By checking the tie condition first, you’re able to know what the computer chose with only two conditional checks of computer_action.

And that’s it! All combined, your code should now look like this:

import random

user_action = input("Enter a choice (rock, paper, scissors): ")
possible_actions = ["rock", "paper", "scissors"]
computer_action = random.choice(possible_actions)
print(f"\nYou chose {user_action}, computer chose {computer_action}.\n")

if user_action == computer_action:
    print(f"Both players selected {user_action}. It's a tie!")
elif user_action == "rock":
    if computer_action == "scissors":
        print("Rock smashes scissors! You win!")
    else:
        print("Paper covers rock! You lose.")
elif user_action == "paper":
    if computer_action == "rock":
        print("Paper covers rock! You win!")
    else:
        print("Scissors cuts paper! You lose.")
elif user_action == "scissors":
    if computer_action == "paper":
        print("Scissors cuts paper! You win!")
    else:
        print("Rock smashes scissors! You lose.")
