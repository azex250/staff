class QU:
	def __init__(self, N):
		self.tree = [i for i in range(n)]

	def showTree(self):
		for i,x in enumerate(self.tree):
			print(i,x,sep=":", end='  ')
		print()

	def __root(self, i):
		while self.tree[i] != i:
			i = self.tree[i]
		return i
			

	def union(self, a, b):
		self.tree[self.__root(b)] = self.__root(a)

	def connected(self, a, b):
		print(self.__root(a) == self.__root(b))

