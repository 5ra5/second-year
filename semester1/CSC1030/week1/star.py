def filter_star(d, i):
    d2 = {}
    for k, v in d.items():
        if len(v) == i:
            d2[k] = v
    if d2:
        print(d2)
    else:
        print("No result found!")