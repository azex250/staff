class Stack:
	class item:
		def __init__(self, content):
			self.content = content

	def __init__(self):
		self.head = None;

	def push(self, content):
		old_head = self.head;
		self.head = self.item(content)
		self.head.next = old_head

	def pop(self):
		content = self.head.content
		self.head = self.head.next
		return content

	def isEmpty(self):
		return self.head == None


class Queue:
	class item:
		def __init__(self, content):
			self.content = content
			self.next = None

	def __init__(self):
		self.head = None
		self.tail = None

	def enqueue(self, content):
		new_head = self.item(content)
		if self.head:
			self.head.next = new_head
		else:
			self.tail = new_head
		self.head = new_head;


	def dequeue(self):
		content = self.tail.content
		self.tail = self.tail.next
		if self.tail == None:
			self.head = None;
		return content;

	def isEmpty(self):
		return self.tail == None
