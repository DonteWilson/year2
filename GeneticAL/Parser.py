import defines
from defines import *
import random

file = "CNFexpress.txt"
inFile = open(file, 'r')
for string in inFile:
	if(inFile):
		numofClauses = 0;
		literals = [];
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
		
		literals.sort();
		print(string);
		print('Literals: ', literals);
		print('Amount of Nots: ',nots);
		print('Amount of Ands:' ,ands);
		print('Amount of Ors: ',ors);
		print('Clauses: ',numofClauses);
		print("\n");
			
	
	