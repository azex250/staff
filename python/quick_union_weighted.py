class QU_W:
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
		while self.tree[i] != i:
			i = self.tree[i]		
		return i

	def connected(self, a, b):
		return self.__root(a) == self.__root(b)
