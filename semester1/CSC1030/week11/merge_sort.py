# in place: no
# stable: yes
# best and worst case time complexity: O(n log n)

def merge_sort(lst):
    # Base case: a list of 0 or 1 elements is already sorted
    if len(lst) <= 1:
        return lst

    # Divide step: split into left and right halves
    mid = len(lst) // 2
    left = merge_sort(lst[:mid])
    right = merge_sort(lst[mid:])

    # Merge step: combine the two sorted halves
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    # Compare and merge elements from both halves
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Append any remaining elements
    result.extend(left[i:])
    result.extend(right[j:])

    return result

lst = [352, 3, 532, 64, 36]
print(merge_sort(lst))