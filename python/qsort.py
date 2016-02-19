from random import randint


a = [randint(0, 10) for x in range(10)]

def part(seq, lo, hi):
	i = lo
	j = hi + 1
	while True:
		i += 1
		j -= 1 
		while seq[i] < seq[lo]:
			if i == hi: 
				break
			i += 1

		while seq[j] > seq[lo]:
			if j == lo: 
				break
			j -= 1

		if i >= j: break
		seq[i], seq[j] = seq[j], seq[i]

	seq[lo], seq[j] = seq[j], seq[lo]

	print(seq[lo:j])
	print(seq[j:hi + 1])
		
		




print(a)
part(a, 0, 9)
print(a)
	



