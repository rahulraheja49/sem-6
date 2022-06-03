datastructures = []
code  = []
amortized_cost = 0
count = 0
curr_state = []

file = open('input.txt')
code_full = file.read()
file.close()
code = code_full.split("\n")

for line in code:
    if ".push" in line or ".pop" in line:
        amortized_cost += 1
        count += 1
        stack_name = line.split(".")[0]
        if f"Stack identified: {stack_name}" not in datastructures:
            datastructures.append(f"Stack identified: {stack_name}")
    if ".enqueue" in line or ".dequeue" in line:
        amortized_cost += 1
        count += 1
        queue_name = line.split(".")[0]
        if f"Queue identified: {queue_name}" not in datastructures:
            datastructures.append(f"Queue identified: {queue_name}")

[print(datastructure) for datastructure in datastructures]
print(f"Total Cost: {amortized_cost}")
print(f"Amortized Cost: {amortized_cost/count}")