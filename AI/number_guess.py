import random

class GuessGame:
    def __init__(self, attempts=5, lo=1, hi=100):
        self.lo, self.hi = lo, hi
        self.secret = random.randint(lo, hi)
        self.attempts = attempts

    def play(self):
        print(f"Guess a number between {self.lo} and {self.hi}. {self.attempts} attempts.")
        for _ in range(self.attempts):
            try:
                guess = int(input("Guess: "))
            except ValueError:
                print("Invalid input."); continue
            if guess == self.secret: print("Correct!"); return
            print("Too low!" if guess < self.secret else "Too high!")
        print(f"Out of attempts! It was {self.secret}.")

if __name__ == "__main__":
    GuessGame().play()
