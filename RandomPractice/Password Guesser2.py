#Brute Force Password Guesser
import string
import random
import time
guesses = 0
def PSWD_Guesser(PSWD):
    global guesses
    while True:     
        Size = len(PSWD)
        chars = string.ascii_letters + string.digits
        Guess = ''.join(random.choice(chars) for _ in range(Size))
        #print(Guess)
        guesses += 1
        if Guess == PSWD:
            break
        continue
   #print('After '+ str(guesses) +' guesses the password is ' + PSWD)
chars = string.ascii_letters + string.digits
s = ''.join(random.choice(chars) for _ in range(4))
#Gathers Average Time
AverageTime = []
for i in range(0, 100):
    start = time.clock()
    PSWD_Guesser(s)
    timer = time.clock() - start
    AverageTime.append(timer)
print(sum(AverageTime)/len(AverageTime))
    #f.write(timer)
    #print('That password took ' + (timer)) + ' seconds.')
