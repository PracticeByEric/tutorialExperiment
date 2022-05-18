# #dictionary of student properties
# student = {'name': 'John', 'age': 25, 'courses': ['Math', 'CompSci']}

# # new entry to the student dictionary
# student['Phone'] = '555-5555'

# print(student.get('Phone', 'Not Found'))

# #dictionary of student properties
# student = {'name': 'John', 'age': 25, 'courses': ['Math', 'CompSci']}

# #update 
# student.update({'name': 'Eric', 'age': 26, 'Phone': '555-555'})

# print(student)

#delete item in dictionary
student = {'name': 'John', 'Age': 25, 'Courses': ['Math', 'Science']}

age = student.pop('Age')

print(student)
print(age)