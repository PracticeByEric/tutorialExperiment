import csv

with open("NameRecords.csv", "r") as f:
  csv_reader = csv.DictReader(f)
  name_records = list(csv_reader) #list: name_records

  #for each dictionary in list "name_records"
  for record in name_records:
    #print items in each dictionary record through "keys"
    print(f"{record['First name']}{record['Last name']}: {record['Age']}")