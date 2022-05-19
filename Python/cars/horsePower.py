#Calculate the average horsepower for each car brand in the csv "cars"

#open the csv file
#read the file into a list[dictionaries]
#for each dictionary in the list, 
#access to data with car name & horse power(print)

import csv

#open the csv file and read into a list
with open("cars.csv", "r") as f:
  csv_read = csv.DictReader(f)
  car_list = list(csv_read)

def add_element(dict, key, value):
  if key not in dict:
    dict[key] = []
  dict[key].append(value)

#reorganize the list into one dictionary 同类型合并
car_brand = {}

for car in car_list:
  add_element(car_brand, car['Make'], int(car['Horsepower']))

#calculate the average and put inside of a new dictionary
car_average_hp = {}

for car, hp_list in car_brand.items():
  hp_sum = 0
  for hp in hp_list:
    hp_sum = hp_sum + hp
  car_average_hp[car] = hp_sum / len(hp_list)

print(car_average_hp)

