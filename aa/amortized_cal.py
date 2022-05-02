ds = {}

def getFile():
    PATH = './input.py'
    lines = open(PATH).read().split("\n")
    return lines


def getDS(lines):
    for line in lines:
        if "DynamicArray()" in line:
            datastructure = line.split("=")[0].strip()
            print("Dynamic Array:", datastructure)
            ds[datastructure] = []
        elif "=[]" in line:
            datastructure = line.split("=")[0].strip()
            print("Array:", datastructure)
            ds[datastructure] = []


def amortized():
    lines = getFile()
    cost = 0
    n =0 

    for line in lines:
        if '=[]' in line:
            print("Array:", line.split("=")[0].strip())
            stack=[]
        elif '.append' in line:
            cost+=1
            n+=1
            ins = line.split('(')[1]
            stack.append((ins[:len(ins)-1]))
            print("Push: ", stack)
        elif '.pop' in line:
            cost+=1
            stack.pop()
            print("Pop:  ", stack)


    print("\nAccounting Results:")
    print("Total Cost: ", cost)
    print("Aggregate Cost: ", cost//n)


def accounting():
    lines = getFile()
    actualc = 0
    n =0 
    amortizedcost=0

    for line in lines:
        if '[]' in line:
            print("Array:", line.split("=")[0].strip())
            stack=[]
        elif '.append' in line:
            actualc+=1
            n+=1
            amortizedcost+=2
            ins = line.split('(')[1]
            stack.append((ins[:len(ins)-1]))
            print("Push: ", stack)
        elif '.pop' in line:
            actualc+=1
            stack.pop()
            print("Pop:  ", stack)
        credit=amortizedcost-actualc

    print("\nAccounting  Results")
    print("actual Cost: ",actualc)
    print("Credits: ",credit,"\n\n")


def potential():
    lines = getFile()
    actualc = 0
    n =0 
    amortizedcost=0

    for line in lines:
        if '=[]' in line:
            print("Array:", line.split("=")[0].strip())
            stack=[]
        elif '.append' in line:
            pd+=1
            n+=1
            amortizedcost+=2
            ins = line.split('(')[1]
            stack.append((ins[:len(ins)-1]))
            print("Push: ", stack)
        elif '.pop' in line:
            actualc+=1
            stack.pop()
            print("Pop:  ", stack)
        pd=amortizedcost-actualc

    print("\nPotential  Results")
    print("Actual Cost: ",actualc)
    print("Potential: ",pd)


getDS()
amortized()
accounting()
potential()