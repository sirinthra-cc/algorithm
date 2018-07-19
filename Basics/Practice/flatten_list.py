def flatten_list(data):
	# Implement Here
	result = list()
	for d in data:
		if type(d) == list:
			result += flatten_list(d)
		else:
			result.append(d)
	return result

def flatten_list_test(data, correct_answer):
	flattened_list = flatten_list(data)
	assert(flattened_list == correct_answer)

data = [[1, [2]], [3, [4]], [5]]
correct_answer = [1, 2, 3, 4, 5]
flatten_list_test(data, correct_answer)

data = [[[[[[1, 2, 3, 4, 5, 1]]]]]]
correct_answer = [1, 2, 3, 4, 5, 1]
flatten_list_test(data, correct_answer)

data = [[[[[1]]]], [[[[2, 3]]]], [[4], 5]]
correct_answer = [1, 2, 3, 4, 5]
flatten_list_test(data, correct_answer)