import mysql.connector as sql
import pandas as pd

db = sql.connect(
    host = '172.20.241.9', 
    database = 'measurements',
    username = 'dbaccess_ro', 
    password = 'vsdjkvwselkvwe234wv234vsdfas'
)
cursor = db.cursor()
cursor.execute("SELECT sensorvalue_a, sensorvalue_b, sensorvalue_c  FROM rawdata WHERE groupid = '62' ") #sensorvalue_a, sensorvalue_b, sensorvalue_c
lista = []
for i in cursor:
    print(i)
    lista.append(i)
  
testdata = pd.DataFrame([lista])
testdata.to_csv('sqldata.csv')