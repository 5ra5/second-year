# in place: yes
# stable: yes
# best time complexity: O(n)
# worst time complexity: O(n^2)

def bubble_sort(lst):
    length = len(lst)

    # range is length - 1 because we want to loop through one less value each time
    for i in range(length-1):
        swapped = False # at the start swapped is False
        for j in range(length - i - 1):
            # if the current value is greater than the next one, swap them
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
                swapped = True # swapped is true because a swap happened
        # if we swapped nothing in the iteration we stop the loop
        if not swapped:
            break
    return lst



lst = [10, 25, 2, 16, 12, 9]
print(bubble_sort(lst))