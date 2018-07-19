def deepcopy(x, visited):
    # "id(variable)"" to get address
    # "type(variable) is list" to check if a variable is a list
    x_deepcopy = list()
    visited[id(x)] = x_deepcopy
    copied_id = dict()
    print(id(x))
    for a in range(len(x)):
        i = x[a]
        if type(i) == list:
            if visited.get(id(i), None) == None:
                i_deepcopy = deepcopy(i, visited)
                x_deepcopy.append(i_deepcopy)
            else:
                x_deepcopy.append(visited[id(i)])
        else:
            x_deepcopy.append(i)
    return x_deepcopy

def testDeepcopy(x):
    visited = dict()
    x_deepcopy = deepcopy(x, visited)
    for i,j in zip(x, x_deepcopy):
        if(type(i) is list):
            assert(id(i) != id(j))
    #assert(x == x_deepcopy)
    print(x)
    print(x_deepcopy)


# testDeepcopy([1, 2, 3, 4, 5])
# testDeepcopy([1, 2, [3, 4], 5])
# testDeepcopy([1, [2, [3, [4, [5]]]]])
# testDeepcopy([[1,[2],[3, 4],[[[5]]]]])
# x = [1, 2, 3]
# y = x
# x.append(y)
# testDeepcopy(x)

x = [[1,5]]
y = [2,x]
z = [3,y]
w = [4,z]
x.append(w)
testDeepcopy(x)