import random

def MyIndex(list, case):
	int = 0
	for items in list:
		if items == case:
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
	
def RV(literalss):
	value = []
	for value in range(0,4):
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
	
	
	def Evaluate(self, clauses, literals, value):
