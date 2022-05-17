from csv import DictReader

#DictReader use the first row of the cvs
#as the key to access data

f = open("weather.csv", "r") #open file for read

#DicReader will produce iterable result (able to use "for loop")
reader = DictReader(f)
#rememebr the first line of the CSV file "key"
#each subsiquent line is producing an object

#read each row from csv "weather.csv" into dictionary row
#key is the column: 'hight', 'low' 'precipitation'
for row in reader:
  print(row) #print each dictionary row
  #a new dictionary, hold dict[str for keys, float: for values]
  float_row: Dict[str, float] = {}

  for column in row:


f.close() #cloe file after opening

#----->>> TO DO<<<-----