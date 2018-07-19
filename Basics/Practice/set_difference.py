def func(list_a, list_b):
    dict_a = dict()
    for a in list_a:
        if dict_a.get(a, None) == None:
            dict_a[a] = 1
        else:
            dict_a[a] += 1
    for b in list_b:
        dict_a[b] -= 1
    i = 0
    while i < len(list_a):
        a = list_a[i]
        if dict_a[a] == 0:
            list_a.pop(i)
        else:
            dict_a[a] -= 1
            i += 1


def list_difference_test(A, B, correctAnswer):
    func(A, B)
    print(A)
    assert(A == correctAnswer)


A = [1, 2, 3, 4, 5]
B = [1, 3, 5]
correctAnswer = [2, 4]
list_difference_test(A, B, correctAnswer)

A = [5, 4, 3, 2, 1]
B = [1, 3, 5]
correctAnswer = [4, 2]
list_difference_test(A, B, correctAnswer)

A = [1, 2, 3, 2, 1]
B = [2, 2]
correctAnswer = [1, 3, 1]
list_difference_test(A, B, correctAnswer)

A = [2, 1, 1, 1, 1]
B = [1, 1, 1]
correctAnswer = [2, 1]
list_difference_test(A, B, correctAnswer)

A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
B = [1, 1, 2, 2, 3, 3, 4, 4]
correctAnswer = [5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5]
list_difference_test(A, B, correctAnswer)