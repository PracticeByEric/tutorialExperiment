car_info = [{'Brand': 'Audi', 'Horsepower': '250'},
                  {'Brand': 'Audi', 'Horsepower': '280'},
                  {'Brand': 'BMW', 'Horsepower': '300'},
                  {'Brand': 'BMW', 'Horsepower': '350'}
                ]

print(car_info[0])

def add_element(dict, key, value):
  if key not in dict:
    dict[key] = []
  dict[key].append(value)

car_brand = {}

for car in car_info:
  add_element(car_brand, car['Brand'], car['Horsepower'])

print(car_brand)

# car_brand = {'Audi': ['250', '280'], 'BMW': ['300', '350']}
