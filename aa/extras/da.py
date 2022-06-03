import random

# stack = []

def push(stack,element):
    stack.append(element)


# while True:
#   print("1.Push",end = "\n","2.pop", end = "\n", "3.exit", end = "\n")
#   choice = int(input("Enter your choice:"))

#   if choice == 1:
#     push(random.randint(1,10))
#   elif choice == 2:
#     pop()

#   else:
#     break



#dynamic table

dynamic_table_array = [1]
# inp_sequence = [1,2,3,4,5,6,7,8,9,10]
count = 1
actual_cost = 0
amortized_cost = 0


while True:
  print("1.Push 2.exit", end = "\n")
  choice = int(input("Enter your choice:"))

  if choice == 1:
   

    print(len(dynamic_table_array))

    if len(dynamic_table_array) == 1:
      prev_potential = 0
      potential = 2 * len(dynamic_table_array)
      amortized_cost = amortized_cost + actual_cost + potential - prev_potential
      ele = int(input("Enter the element value:"))

      push(dynamic_table_array,ele)
      actual_cost+=1

    else:
      previous_potential = potential
      potential = 2 * len(dynamic_table_array)
      amortized_cost = amortized_cost + actual_cost + potential - prev_potential
      ele = int(input("Enter the element value:"))

      push(dynamic_table_array,ele)
      actual_cost+=1
  
  else:
    break



print("The amortized cost is",amortized_cost)