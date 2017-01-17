dicts_from_file = []
with open('CNFexpress.txt','r') as inf:
	for line in inf:
		dicts_from_file.append(eval(line))