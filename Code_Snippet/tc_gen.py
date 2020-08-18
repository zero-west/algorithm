from random import choice

s = [i for i in range(1, 10000)]
n = [i for i in range(3, 1001)]


def gen(sel):
    return choice(sel)


# curn = gen(n)
# k = [i for i in range(curn)]
#
# print(curn, gen(k))
# for i in range(curn):
#     print(gen(s), gen(s))

for _ in range(1000):
    print(gen(range(10)), gen(range(200)))
