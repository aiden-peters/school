import random
import string
print('Please input the password to be guessed:')
PSWD = input()
characters = string.ascii_uppercase + string.digits
len(PSWD) = Length
while True:
    Guess = ''.join[random.choice(characters) for _ in range(int(Length))]
    print(Guess)
    if Guess == PSWD:
        break
    continue
print('CONGRATS COMPUTER! \n You\'ve beat the password!')
    
