

for i in range(26):
    t = chr(ord('A') + i)
    fout = open(t + ".txt", 'w')
    for j in range(45):
        if j != 0:
            print("", file=fout)
        for k in range(45):
            print(0, end=" ", file = fout)
        