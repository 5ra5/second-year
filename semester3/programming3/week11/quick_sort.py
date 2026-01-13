# in place: no
# stable: yes (depending on implementation)
# best and average case time complexity: O(n log n)
# worst case time complexity: 0(n^2)

def partition(lst, low, high):
    # high is the last element of the sub-list - chosen as pivot
    # low is the index we're starting from
    pivot = lst[high]
    i = low - 1 # keeps track of the last value that's lower than pivot

    # looping from the current low to the current high
    for j in range(low, high):
        # if the current element is less than pivot move forward
        if lst[j] <= pivot:
            i += 1 # expanding the less sub-list
            # including the j value in the less sub-list
            lst[i], lst[j] = lst[j], lst[i]
    lst[i + 1], lst[high] = lst[high], lst[i + 1]
    return i + 1

def quicksort(lst, low=0, high=None):
    # This is used at the first iteration to set the high
    # High is the right-most element of the list
    # Low is set to 0 because we start from that position first
    if high is None:
        high = len(lst) - 1

    # base case: there is at least 2 elements in the list
    # if low >= high, there is 0 or 1 elements left, so we can stop
    if low < high:
        # call the partition function to pick a pivot, split the lists and put elements into
        # greater than or less than pivot sub-lists
        pivot = partition(lst, low, high)
        quicksort(lst, low, pivot - 1) # sort the left side - less than pivot
        quicksort(lst, pivot + 1, high) # sort the right side - greater than pivot

    return lst


lst = [10, 25, 2, 16, 12, 9]
print(quicksort(lst))