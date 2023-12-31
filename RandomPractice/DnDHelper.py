import random
import sys
while True:
    print('Input below what program you would like to activate')
    print('Current programs are: AbilityScores, Dice, Characters, CharacterCreation(Under Construction)')
    def AbilityScores():
        for i in range (6):
            One = random.randint (1, 6)
            print ( One )
            Two = random.randint (1, 6)
            print ( Two )
            Three = random.randint (1, 6)
            print ( Three )
            Four = random.randint (1, 6)
            print ( Four )
            Rolls = [One, Two, Three, Four]
            print('Enter the smallest roll.')
            print('Type "One" for the first roll, "Two" for the second roll and so on')
            SmallNum = input()
            SmallNum = SmallNum.lower()
            if SmallNum == 'one' or SmallNum == '1':
                del Rolls[0]
            if SmallNum == 'two' or SmallNum == '2':
                del Rolls[1]
            if SmallNum == 'three' or SmallNum == '3':
                del Rolls[2]
            if SmallNum == 'four' or SmallNum == '4':
                del Rolls[3]
            Score = sum(Rolls)
            print('Ability Score #' + str(i + 1) + ' is:')
            print(Score)
            if i == 0:
                First = Score
            if i == 1:
                Second = Score
            if i == 2:
                Third = Score
            if i == 3:
                Fourth = Score
            if i == 4:
                Fifth = Score
            if i == 5:
                Sixth = Score
            if i < 5:
                print("Next Rolls")
            if i == 5:
                ABscores = [First,Second,Third,Fourth,Fifth,Sixth]
                print('Here are your ability scores:')
                print(ABscores)
    def Dice():
        while True:
            print("Type a number to roll a die with that many faces or type exit to leave")
            Die = input()
            if Die.lower() == 'exit':
                break
            elif Die.isdecimal() != True:
                print('Please enter an actual number')
                continue   
            else:
                print('How many dice do you need to roll?')
                NumOfDie = input()
                Rolls = []
                if NumOfDie == 1:
                    print( random. randint(1, int(Die)))
                    continue
                else:
                    for i in range(int(NumOfDie)):
                        Score = random. randint(1, int(Die))
                        print(Score)
                        Rolls.append(Score)
                    Total = sum(Rolls)
                    print('Here is the total amount')
                    print(Total)
    def Characters():
        print('Current Characters are: Navi')
        character = input()
        def Navi():
            print('What would you like to do/know?')
            Command = input()
            if '?' in Command:
                if 'BAB' in Command:
                    print("Navi's base attack bonus is 4")
                if 'AttackBonus' in Command:
                    print("Navi's bow attack bonus is 13")
            else:
                if 'BowAttack' in Command:
                    Roll = random.randint(1,20) + 13
                    print(Roll)
                if 'ConcentrationCheck' in Command:
                    Roll = random.randint(1,20) + 12
                    print(Roll)
                if 'Save' in Command:
                    if 'Fort' in Command:
                        print('3')
        if character == 'Navi':
            Navi()
                    
    def CharacterCreation():
        print('Ability Scores')
        Scores = []
        for i in range(6):
            Rolls = []
            for l in range(4):
                Roll = random.randint(1,6)
                Rolls.append(Roll)
            print(Rolls)
            #Lowest = input()
            #Rolls.remove(int(Lowest)) #removes lowest roll
            Rolls.remove(min(Rolls))
            Score = sum(Rolls)
            Scores.append(Score)
        print(Scores)
        AS = {}
        print('Input the order on the list that you would like applied for each ability.')
        h = 0
        while h < 6: # Applies the ability scores... Hopefully
            if h == 0:
                print('Dexterity?')
            elif h == 1:
                print('Constitution?')
            elif h == 2:
                print('Intelligence?')
            elif h == 3:
                print('Wisdom?')
            elif h == 4:
                print('Strength?')
            elif h == 5:
                print('Charisma?')
            i = input()
            i = int(i)
            if h == 0:
                AS['Dex'] = Scores[i - 1]
            elif h == 1:
                AS['Con'] = Scores[i - 1]
            elif h == 2:
                AS['Int'] = Scores[i - 1]
            elif h == 3:
                AS['Wis'] = Scores[i - 1]
            elif h == 4:
                AS['Str'] = Scores[i - 1]
            elif h == 5:
                AS['Cha'] = Scores[i - 1]    
            h = h + 1
        AC = 1
        for i in AS.items():
            print(i)
            

    Program = input()
    if Program == 'AbilityScores':
        AbilityScores()
    elif Program == 'Dice':
        Dice()
    elif Program == 'd20' or Program == 'D20':
        print(random.randint(1,20))
    elif Program.upper() == 'EXIT' or Program == '':
        break
    if Program == 'Characters':
        Characters()
    if Program == 'CharacterCreation' or Program.upper() == 'CC':
        CharacterCreation()
    else:
        print("There's no program called " + repr(Program) + ".")
    
          

        
    

