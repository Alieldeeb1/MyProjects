class Guess:
    def __init__(self, word):
        self.name_to_guess = word  #this is the random word
        self.name_guessed = "----" #this is the user's current guess
        self.guesses_made = [""]   #this is the guesses made
        self.bad_guesses = 0       #this is the number of bad guesses made
        self.missed_letters = 0    #this is the number of bad letter guesses made
        self.status = ""           #this gets set to succes or giveup depending on if he got the word right
        self.score = 0             #this is just the score that I will explained how it works down
        self.letters_guessed = ''  #this will display the letters guessed

    def calculate_initial_score(self, frequencies): #this sets the score to the scores of all letters
        self.score = sum(frequencies.get(l, 0) for l in self.name_to_guess)

    def update_guess(self, letter, frequencies): #this updates the current guess strig if a letter gussed is correct
        matches = 0
        for i, l in enumerate(self.name_to_guess): 
            if letter == l:
                self.name_guessed = self.name_guessed[:i] + letter + self.name_guessed[i + 1:]
                matches += 1
                self.score -= frequencies.get(letter, 0) #this minuses the value of the correct letter guessed from the score
        return matches

    def finalize_score(self, bad_guesses_count, missed_letters_count):
        if self.missed_letters != 0: #if missed letters are more than zero divide the score with the number of missed letters
            self.score /= missed_letters_count
        self.score *= ((100 - (10 * bad_guesses_count)) / 100)
 