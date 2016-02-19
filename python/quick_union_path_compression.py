class QU_C:
	def __init__(self, n):
		self.tree = [i for i in range(n)]
	
	def showTree(self):
		for i,x in enumerate(self.tree):
			print(i,x,sep=":", end='  ')
		print()

	def union(self, a, b):
		self.tree[self.__root(b)] = self.__root(a) 
			
	def __root(self, i):
		a = []
		while self.tree[i] != i:
			a.append(i)
			i = self.tree[i]

		for x in a:
			self.tree[x] = i
			
		return i

	def connected(self, a, b):
		return self.__root(a) == self.__root(b)