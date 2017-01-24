import defines
from defines import *
import time

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



numofClauses = 0;
maxpop = 4;
expression = ""
clauses = []
literals = []
population = []
checkClause = "false";
clausesString = "";
		#ors = 0;
		#nots = 0;
		#ands = 0;
		#a = 1;
		#b = 1;
		#c = 1;
		#e = 1;
		#f = 1;
				
for char in string:
	if char == '!' and checkClause == "true":
		clausesString += '~';
			
	elif char =='|' and checkClause == "true":
		clausesString += char;
			
	elif char == '&':
		clausesString += char;
			
	elif char == ' ':
		continue;
			
	elif char == '(' and checkClause == "false":
		checkClause = "true";
		clausesString += '(';
				
			
	elif char == '\n':
		continue;
				
	elif char == ')' and checkClause == "true":
		checkClause = "false";
		clausesString += ')';
		clauses.append(clausesString);
		clausesString = "";
				
			
	elif checkClause == "true":
		clausesString += char;
		if char in literals:
			continue;				
		literals.append(char);

for string in clauses:
	expression += string 

#Mutation / Candidates
population = RV(len(literals), maxpop) #uses the random value function created in defines.py to create population
num = 0
data +=("Population:" + "\n")

for p in population:
	num += 1
	data +=("Candidate " + str(num) + ":" + str(p.value) + "\n")

data += "\n"
start = time.time()
end = None 
FS = 0;
S = None
generations = 0
while(FS == 0 and generations < 3000):
	generations += 1
	data +=("\n" + "Generations " + str(generations) + "\n")
	for can in population:
		if can.Evaluate(expression, literals, can) >= 1:
			end = time.time()
			S = can
			FS = 1;
			break


print(data)  #prints the data obtained and puts it on the screen.

literals.sort();
print(string);
print('Literals: ', literals);
print('Amount of Nots: ',nots);
print('Amount of Ands:' ,ands);
print('Amount of Ors: ',ors);
print('Clauses: ',numofClauses);
print("\n");
			
	
	