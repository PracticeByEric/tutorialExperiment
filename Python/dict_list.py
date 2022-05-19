#1_using += to append list in Python dictionary
# #dictionary of person properties
# person = {"name": "Eric", "age": 25, "Hobby": ["hiking", "coding", "drawing"]}

# #to add Hobby "running" into the list
# person["Hobby"] += ["running"]

# print(person)

#----->>>>>-----<<<<<-----

#2_using if statement to append list in Python dictionary
# person = {}
# person["age"] = [20] #to add a list into dictionary key "age"
# print(person)

# if "age" in person:
#   person["age"].append("twenty")
#   print(person)

# #2_1 dictionary of person properties
# person = {"name": "Eric", "hobby": ["hiking", "coding", "drawing"]}

# #to add hobby "running" into the list
# if "hobby" in person:
# 	person["hobby"].append("running")
# 	print(person)

#----->>>>>-----<<<<<-----

# #3_Using defaultdict() method
# from collections import defaultdict

# person = defaultdict(list)

# person["hobby"].append("hiking")
# person["hobby"].append("jogging")

# print(person)

#----->>>>>-----<<<<<-----

#4_Using update function
person = {}
person["hobby"] = []
person.update({"hobby": ["hiking", "jogging", "coding"]})
print(person)