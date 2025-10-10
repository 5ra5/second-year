def l_reverse(l):
    if not l:
        return []
    return [l.pop()] + l_reverse(l)

print(l_reverse([1, 2, 3, 4]))