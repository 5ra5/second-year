def s_length(s):
    if s == "":
        return 0
    return 1 + s_length(s[1:])

# print(s_length("abcdefgh"))