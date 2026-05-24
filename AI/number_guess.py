import random

class GuessTheNumberGame:
    def __init__(self, max_attempts=5, min_num=1, max_num=100):
        self.min_num = min_num
        self.max_num = max_num
        self.secret_number = random.randint(min_num, max_num)
        self.max_attempts = max_attempts
        self.attempts = 0

    def play(self):
        print("Welcome to Guess the Number Game!")
        print(f"I'm thinking of a number between {self.min_num} and {self.max_num}.")

        while self.attempts < self.max_attempts:
            guess = self.get_guess()
            
            if guess == self.secret_number:
                print(f"Congratulations! You guessed the number {self.secret_number} correctly!")
                break
            elif guess < self.secret_number:
                print("Too low! Try again.")
            else:
                print("Too high! Try again.")
                
            # FIXED: Moved outside the else block to track all attempts
            self.attempts += 1 
        else:
            print(f"Sorry, you've run out of attempts! The correct number was {self.secret_number}.")

    def get_guess(self):
        while True:
            try:
                guess = int(input(f"Guess the number ({self.min_num} - {self.max_num}): "))
                if self.min_num <= guess <= self.max_num:
                    return guess
                else:
                    print(f"Please enter a number between {self.min_num} and {self.max_num}.")
            except ValueError:
                print("Please enter a valid number.")

# Demonstration
if __name__ == "__main__":
    game = GuessTheNumberGame()
    game.play()
