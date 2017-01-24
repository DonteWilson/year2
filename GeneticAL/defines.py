import random

def MyIndex(list, case):
	int = 0
	for item in list:
		if item == case:
			return int;
		
		else:
			int += 1;

def Print(list):
	for items in list:
		print(item)

		

def AddCanidate(can):
	list = []
	for char in can.value:
		list.append(char)
	return list
	
def RV(literalss, max):
	values = []
	for value in range(0, max):
		tempBitString = Cdate("")
		for bit in range(0,literalss):
			rand = random.randrange(0, 100, 1)
			if rand < 49:
				tempBitString.value += '1'
			else: 
				tempBitString.value += '0'
		values.append(tempBitString)
	return values

class Cdate(object):
	def __init__(self, string):
		bitstring = ""
		for bit in string:
			bitstring += bit
		self.value = bitstring
	
	def Swap(self, literals, value):
		for bit in range(len(lierals) / 2, len(literals)):
			if value[bit] == '0':
				value[bit - (len(literals) / 2)] = '1'
			elif value[bit] == '1':
				value[bit - (len(literals) / 2)] = '0'
		return value
	
	def Mutation(self, mChance):
		finalList = []
		bitstring = ""
		for bit in self.value: 
			if random.randrange(1, 101, 1) <= mChance:
				if bit == '1':
					finalList.append('0')
				elif bit == '0':
					finalList.append('1')
			else:
					finalList.append(bit)
		for bit in finalList:
			bitstring += bit
		return bitstring
	
	
	def Evaluate(self, expression, literals, can):
		tempInfo = ""
		clauses = []
		chroeval = 0
		for string in expression:
			for char in string:
				if char == ')':
					tempInfo += char
					clauses.append(tempInfo)
					tempInfo = ""
				
				elif char == '&':
					continue
				
				else:
					if char != '-' and char != '(' and char != '|' and char != '&':
						tempInfo += can.value[MyIndex(literals, char)]					
					else:
						tempInfo += char
		
		finalString = ""
		swap = 0
		for string in clauses:
			for char in string:
				if flip == 1:
					if char == '1':
						finalString += '0'
					
					elif char == '0':
						finalString += '1'
					flip = 0
				else:
					if char == '~':
						flip = 1
					else:
						finalString += char
			clauses[MyIndex(clauses, string)] = finalString
			finalString = ""
		
		for c in clauses:
			chroeval += eval(c)
		
		return chroeval / float(len(clauses))
		
	
