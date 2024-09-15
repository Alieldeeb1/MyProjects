from StringDatabase import StringDatabase
from Guess import Guess

def main():
    frequencies = {"a": 8.17, "b": 1.49, "c": 2.78, "d": 4.25, "e": 12.70, "f": 2.23, "g": 2.02,
                   "h": 6.09, "i": 6.97, "j": 0.15, "k": 0.77, "l": 4.03, "m": 2.41, "n": 6.75,
                   "o": 7.51, "p": 1.93, "q": 0.10, "r": 5.99, "s": 6.33, "t": 9.06, "u": 2.76,
                   "v": 0.98, "w": 2.36, "x": 0.15, "y": 1.97, "z": 0.07} #this is a dictionary

    string_database = StringDatabase() 
    games = []
    new_game = True #setting this to true till the user quits

    while new_game:
        guess = Guess(string_database.get_random_word())#getting a random from the file
        guess.calculate_initial_score(frequencies)#setting score to all the letters
        games.append(guess)

        while True: #this will keep running till he enters q
            print("\n++\n++ The great guessing game\n++")    #DISPLAYING
            print(f"\nCurrent Word: {guess.name_to_guess}")
            print(f"Current Guess: {guess.name_guessed}")
            print(f"Letters guessed: {guess.letters_guessed}")
            print("g = guess, t = tell me, l for a letter, and q for quit")
            option = input("\nEnter Option: ")

            if option == 'q':
                new_game = False
                break

            if option not in ['g', 'l', 't']:#this will display a message and will not have to check the next ifs
                print("\nInvalid option. Please re-enter.")
                continue

            if option == 'g':
                final_word = input("\nMake your guess: ")#getting a guess from the user
                if final_word == guess.name_to_guess:
                    print("\n@@\n@@ FEEDBACK: You're right, Einstein!\n@@")
                    guess.status = "Success"
                    guess.finalize_score(guess.bad_guesses, guess.missed_letters)
                    break
                else:
                    if final_word not in guess.guesses_made:
                        print("\n@@\n@@ FEEDBACK: Try again, Loser!\n@@")
                        guess.guesses_made.append(final_word)
                        guess.bad_guesses += 1
                    else:
                        print("\n@@\n@@ FEEDBACK: You have entered that word before\n@@")

            elif option == 't':
                print(f"\n@@\n@@ FEEDBACK: You really should have guessed this... '{guess.name_to_guess}'")
                guess.status = "Gave-up"
                guess.score = -guess.score
                break

            elif option == 'l':
                letter = input("\nEnter a letter: ")
                if letter in guess.letters_guessed:
                    print("\n@@\n@@ FEEDBACK: You have guessed that letter before\n@@")
                    continue
                else:
                    guess.letters_guessed += letter + " "
                    matches = guess.update_guess(letter, frequencies)
                    if matches == 0:
                        print("\n@@\n@@ FEEDBACK: Not a single match, genius\n@@")
                        guess.missed_letters += 1
                    else:
                        print(f"\n@@\n@@ FEEDBACK: Woo hoo, you found {matches} letters\n@@")

        if new_game:
            print("Press any key to continue... ")
            input()
    

    # Game report
    print("\n\n++\n++ Game Report\n++\n")
    print("Game\t  Word\t   Status\t Bad Guesses\tMissed Letters\t Score")
    print("----\t  ----\t   ------\t -----------\t--------------\t -----")
    total_score = 0
    for idx, game in enumerate(games):
        if(game.status=="Success" or game.status=="Gave-up"):
            print(f"{idx + 1}\t  {game.name_to_guess}\t   {game.status}\t {game.bad_guesses}\t\t{game.missed_letters}\t\t {format(game.score, '.2f')}")
            total_score += game.score
    print("Final Score:", format(total_score, ".2f"))

if __name__ == "__main__":
    main()
