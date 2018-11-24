def gdc(a, b):
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a
    return a

x = int(input())
y = int(input())
print("Greatest common divisor: %d" % gdc(x, y))
