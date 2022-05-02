datastructures = []
code  = []
amortized_cost = 0
count = 0
arr = []
capacity = 1

file = open('usage.py')
code_full = file.read()
file.close()
code = code_full.split("\n")
for line in code:
    if ".append" in line:
        if len(arr) == capacity:
            amortized_cost += len(arr)
            capacity *= 2
        amortized_cost += 1
        count += 1
        dynamic_array_name = line.split(".")[0]
        if f"Dynamic Array identified: {dynamic_array_name}" not in datastructures:
            datastructures.append(f"Dynamic Array identified: {dynamic_array_name}")
    if ".delete" in line:
        amortized_cost += 1
        count += 1

[print(datastructure) for datastructure in datastructures]
print(f"Average cost: {amortized_cost/count}")