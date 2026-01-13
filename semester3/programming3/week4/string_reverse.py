def s_reverse(s):
    if s == "":
        return s
    else:
        return s_reverse(s[1:]) + s[0]

# print(s_reverse('hello'))