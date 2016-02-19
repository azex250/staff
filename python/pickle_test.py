import pickle;

dict_db = {
	'bob':	{'name': 'Bob Smith', 'age': 42, 'salary': 40000, 'position': 'sowtware'},
	'sam':	{'name': 'Sam Loh', 'age': 12, 'salary': 4000, 'position': 'web'},
	'stue':	{'name': 'Stue MkRonald', 'age': 33, 'salary': 20000, 'position': 'system'}
}

fd = open('hello', 'wb');
pickle.dump(dict_db, fd);
fd.close()
fd = open('hello', 'rb');
dict_loaded = pickle.load(fd)
print(dict_db==dict_loaded)
print(dict_loaded)
