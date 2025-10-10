def has_duplicate_pairs(l):
    duplicates = 0
    numbers = set()
    for n in l:
        if n in numbers:
            duplicates += 1
        else:
            numbers.add(n)
    if duplicates >= 1:
        return True
    return False
