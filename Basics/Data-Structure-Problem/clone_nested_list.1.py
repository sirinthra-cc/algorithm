def deepcopy(x, visited):
    # "id(variable)"" to get address
    # "type(variable) is list" to check if a variable is a list
    if type(x) == list:
        x_deepcopy = list()
        visited[id(x)] = x_deepcopy
        for a in range(len(x)):
            i = x[a]
            if type(i) == list or type(i) == dict:
                if visited.get(id(i), None) == None:
                    i_deepcopy = deepcopy(i, visited)
                    x_deepcopy.append(i_deepcopy)
                else:
                    x_deepcopy.append(visited[id(i)])
            else:
                x_deepcopy.append(i)
    else:
        x_deepcopy = dict()
        visited[id(x)] = x_deepcopy
        for key in x:
            i = x[key]
            if type(i) == list or type(i) == dict:
                if visited.get(id(i), None) == None:
                    i_deepcopy = deepcopy(i, visited)
                    x_deepcopy[key] = i_deepcopy
                else:
                    x_deepcopy[key] = visited[id(i)]
            else:
                x_deepcopy[key] = i
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
y = {'a':2,'b':x}
z = [3,y]
w = [4,z]
x.append(w)
testDeepcopy(x)