import pygraph.algorithms.generators as Gen
import random
n = random.randint(10, 1000)
g = Gen.generate(n, n+1, True)
for e in g.edges():
    src, dest = e
    print src, dest
