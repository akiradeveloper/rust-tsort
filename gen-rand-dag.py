import pygraph.algorithms.generators as Gen
import random

n = random.randint(10, 1000)
# e = n * (n-1) / 2 # number of edges
perms = list(range(0, n))
random.shuffle(perms)

edges = []
for i in range(0, n):
	for j in range(0, n):
		if i < j:
			edges.append((perms[i], perms[j]))

for x in edges:
	print "%d %d" % x
