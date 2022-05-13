try:
  x = int(input("x: ")) #convert input to int
except ValueError: #if unable to execute the code
  print("That is not an int!")
  exit()

try:
  y = int(input("y: "))
except ValueError:
  print("That's not an int!")
  exit()

print(x+y)