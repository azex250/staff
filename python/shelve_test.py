import shelve
d = shelve.open("dict")
d['test'] = 123234
d['bob'] = {'name': 'Bob Smith', 'age': 66}
for key in d.keys():
  print(key)
name = d['bob']['name'].split(' ')
name[-1] = 'Jonson'
name = ' '.join(name)
print(name)
bob = d['bob']
bob['name'] = name
d['bob'] = bob
print(d['bob'])
