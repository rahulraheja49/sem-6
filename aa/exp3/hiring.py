import random
 
jobs = ["Software Engineer", "HR", "Devops Engineer", "Production Engineer"]
 
vals = []
n = int(input("Enter number of applicants: "))
for i in range(n):
	vals.append({random.randint(0, n)})
 
print(vals)
curr = -1
cost = 0
i_cost = 5
hf_cost = 15
while len(vals) > 0:
	ind = random.randint(0, len(vals)-1)
	cost += i_cost
	if curr < vals[ind]:
		curr = vals[ind]
		cost += hf_cost
	vals.pop(ind)
 
print(curr)
print(cost)
