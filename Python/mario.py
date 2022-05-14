#redefine print ("\n")

for i in range(4):
  print("#", end="!")  #print out ! after every "#"/ over writing "\n" with "!"

#----->> print out 4*4 brick of "#" <<-----
for i in range(4):
    print("#" * 4)