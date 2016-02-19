class QU_WC:
	def __init__(self, n):
		self.tree = [i for i in range(n)]
		self.tree_size = [1 for i in range(n)]
	
	def showTree(self):
		for i,x in enumerate(self.tree):
			print(i,x,sep=":", end='  ')
		print()

	def union(self, a, b):
		root_a = self.__root(a)
		root_b = self.__root(b)

		if self.tree_size[root_a] >= self.tree_size[root_b]: 
			self.tree[root_b] = root_a 
			self.tree_size[root_a]+=self.tree_size[root_b]
		else:
			self.tree[root_a] = root_b 
			self.tree_size[root_b]+=self.tree_size[root_a]
			
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

qu_wc = QU_WC(10)