# in place: yes
# stable: no
# best and worst time complexity: O(n^2)

def selection_sort(lst):
    length = len(lst)

    for i in range(length - 1):
        lowest = i

        # range starts from i + 1 because we want to iterate through the unsorted part of the list
        for j in range(i + 1, length):
            if lst[j] < lst[lowest]: # comparing values of these elements
                lowest = j
        lst[i], lst[lowest] = lst[lowest], lst[i] # swapping elements
    return lst

lst = [10, 25, 2, 16, 12, 9]
print(selection_sort(lst))
