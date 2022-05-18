# #print out each element in Python for loop
# a = ["banana", "apple", "peach"]

# for fruit in a:
#   print(fruit)

# #incremental add up in Python
# b = [1, 4, 7]
# sum = 0

# for element in b:
#   sum =  sum + element
# print(sum)

# #range function
#converting range into a list
# c = list(range(1, 5))
# print(c)

# total = 0

# for i in range(1, 5):
#   total = total + i
# print(total)

# #in list 1 to 8, add up all the number can be multiply of 3
# total = 0

# for i in range(1, 8):
#   if (i % 3 == 0):
#     total += i
# print(total)

#compute all multiples of 3 and 5
#that are less than 100

total = 0

for i in range(1, 100):
  if i % 3 == 0 or i % 5 == 0:
    total = total + i
print(total)