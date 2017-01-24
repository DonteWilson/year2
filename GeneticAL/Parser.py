import defines
from defines import *
import random

file = "CNFexpress.txt"
inFile = open(file, 'r')

print("Select an Expression: \n")
lineNum = 1
CNFexpress = []  #contains a the list of CNF expressions
for string in inFile:
	print(str(lineNum) + ". " + string)
	CNFexpress.append(string)
	lineNum += 1

data = ""     #will store the data that will be presented
input = input()     #takes input from the user 
input = int(input)

if input >= 0 and input < len(CNFexpress):
	string = CNFexpress[input]  #makes the string of the input choice of the user.
else:
	selection = random.randrange(0, len(CNFexpress), 1)
	string = CNFexpress(selection)


data += (string + "\n" + "\n")   #format of the data being presented.


if(inFile):
		numofClauses = 0;
		literals = [];
		population = [];
		clausesOpen = 0;
		ors = 0;
		nots = 0;
		ands = 0;
		a = 1;
		b = 1;
		c = 1;
		e = 1;
		f = 1;
				
		for char in string:
			if char == '!':
				nots += 1;
			
			elif char =='|':
				ors += 1;
			
			elif char == '&':
				ands += 1;
			
			elif char == ' ':
				continue;
			
			elif char == '(':
				clausesOpen = 1;
			
			elif char == '\n':
				continue;
				
			elif char == ')' and clausesOpen == 1:
				numofClauses += 1;
				clausesOpen = 0;
			
			else:
				if char in literals:
					continue;
				
				literals.append(char);

#Mutation / Candidates
population = RV(len(literals), 4) #uses the random value function created in defines.py to create population
num = 0
data +=("Population:" + "\n")

for p in population:
	num += 1
	data +=("Candidate " + str(num) + ":" + str(p.value) + "\n")

print(data)  #prints the data obtained and puts it on the screen.

literals.sort();
print(string);
print('Literals: ', literals);
print('Amount of Nots: ',nots);
print('Amount of Ands:' ,ands);
print('Amount of Ors: ',ors);
print('Clauses: ',numofClauses);
print("\n");
			
	
	