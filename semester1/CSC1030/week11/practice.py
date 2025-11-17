def partition(lst, low, high):
    pivot = lst[high]
    i = low - 1

    for j in range(low, high):
        if lst[j] <= pivot:
            i += 1
            lst[i], lst[j] = lst[j], lst[i]
    lst[i + 1], lst[high] = lst[high], lst[i + 1]
    return i + 1

def quicksort(lst, low=0, high=None):
    if high is None:
        high = len(lst) - 1

    if low < high:
        pivot = partition(lst, low, high)
        quicksort(lst, low, pivot - 1)
        quicksort(lst, pivot + 1, high)

    return lst

def selection_sort(lst):
    length = len(lst)
    for i in range(length - 1):
        lowest = i
        for j in range(i + 1, length):
            if lst[j] < lst[lowest]:
                lowest = j
        lst[i], lst[lowest] = lst[lowest], lst[i]
    return lst

lst = [14, 78, 34, 65, 2, 5]
lst2 = [74, 43, 2, 5, 53, 6, 84]
lst3 = [45, 676, 23, 5, 43]

print(quicksort(lst))
print(selection_sort(lst2))