class QF:
	def __init__(self, N):
		self.tree = [i for i in range(n)]

	def showTree(self):
		for i,x in enumerate(self.tree):
			print(i,x,sep=":", end='  ')
		print()

	def union(self, a, b):
		first = self.tree[a]
		second = self.tree[b]

		for x in range(len(self.tree)):
			if self.tree[x] == first:
				self.tree[x] = second

	def connected(self, a, b):
		print (self.tree[a] == self.tree[b])

