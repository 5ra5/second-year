def string(l):
    new_string = []
    for word in l:
        new_string.append(word[::-1].capitalize())
    return new_string

s = ['cat', 'dog', 'bird']
print(string(s))