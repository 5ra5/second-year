def move_vow(s):
    vowels = 'aeiouAEIOU'
    s1 = "" #vowels
    s2 = "" #consonants
    for c in s:
        if c in vowels:
            s1 += c
        else:
            s2 += c
    print(s1 + s2)