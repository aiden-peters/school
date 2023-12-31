def count_letters(string):
    letter_count = {}
    
    for letter in string:
        if letter.isalpha():
            letter = letter.lower()  # Convert to lowercase to count regardless of case
            if letter in letter_count:
                letter_count[letter] += 1
            else:
                letter_count[letter] = 1
    
    return letter_count

# Example usage:
input_string = "Peters Macneil henry mckenna renaud ashick fallows chocorlan hamptondavies burnham walc hamilton eisner howe"
result = count_letters(input_string)

for letter, count in sorted(result.items()):
    print(f"'{letter}' : {count}")
