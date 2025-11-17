def insertion_sort(lst):
    length = len(lst)

    # range is (1, length) because we're starting from the second element in the list
    # assuming that the first element is already sorted
    for i in range(1, length):
        # lst[i] because we're comparing values of the list
        current = lst[i]
        j = i - 1 # the last element in the sorted part of the list

        # while j is not 0 and the current value is smaller than the element to the left
        while j >= 0 and current < lst[j]:
            lst[j + 1] = lst[j] # moving the larger value one step to the right
            j -= 1
        # once we get to the end or find an element that is smaller than current
        # the element that is larger than lst[j] is inserted at position [j + 1]
        # this position was previously empty, or containing a duplicate of the value we moved to the right
        # [j + 1] represents the last element of the sorted part of the list, just like i - 1 previously
        lst[j + 1] = current
    return lst

lst = [10, 25, 2, 16, 12, 9]
print(insertion_sort(lst))