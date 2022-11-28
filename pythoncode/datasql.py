import mysql.connector as sql
import pandas as pd

db = sql.connect(
    host = '172.20.241.9', 
    database = 'measurements',
    username = 'dbaccess_ro', 
    password = 'vsdjkvwselkvwe234wv234vsdfas'
)
cursor = db.cursor()
cursor.execute("SELECT * FROM rawdata WHERE groupid = '62' ")
lista = []
for i in cursor:
    print(i)
    lista.append(i)
  
testdata = pd.DataFrame([lista])
testdata.to_csv('sqldata.csv')