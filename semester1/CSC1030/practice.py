def insertion_sort(lst):
    length = len(lst)

    for i in range(1, length):
        current = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > current:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = current
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

lst = [10, 25, 2, 16, 12, 9]
print(insertion_sort(lst))
print(selection_sort(lst))