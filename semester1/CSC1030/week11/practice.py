def bubble_sort(lst):
    length = len(lst)

    for i in range(length - 1):
        swapped = False
        for j in range(length - i - 1):
            if lst[j + 1] < lst[j]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
                swapped = True
        if not swapped:
            break
    return lst

lst = [14, 78, 34, 65, 2, 5]
lst2 = [74, 43, 2, 5, 53, 6, 84]
lst3 = [45, 676, 23, 5, 43]

print(bubble_sort(lst))