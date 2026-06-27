my_array = ['Pete', 'Jones', 'Lisa', 'Bob', 'Siri']
# create 10 buckets
my_hash_set = [[] for _ in range(10)]
def hash_function(value):
    sum_of_chars = 0
    for char in value:
        sum_of_chars += ord(char)
    return sum_of_chars % 10

def add(value):
    index = hash_function(value)
    bucket = my_hash_set[index]

    if value not in bucket:
        bucket.append(value)

def contains(value):
    index = hash_function(value)
    bucket = my_hash_set[index]
    return value in bucket

# insert values
for name in my_array:
    add(name)

print(my_hash_set)
print("'Bob' has hash code:", hash_function('Bob'))
print("'Pete' is in the Hash Set:", contains('Pete'))

add('Stuart')

print(my_hash_set)
print('Contains Stuart:', contains('Stuart'))