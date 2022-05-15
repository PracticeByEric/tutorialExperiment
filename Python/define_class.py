#example of defining a class in Python

class Student(): #create a class called Student

    def __init__(self, name, id):  #constructor: initilization function
        #include "self" to indicate what object being invoked
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))

jane = Student("Jane", 10)
#have a new student object called jane: jane's name filed is "Jane"/ jane's id field is "10"
jane.print()
jane.changeID(11)
jane.print()
