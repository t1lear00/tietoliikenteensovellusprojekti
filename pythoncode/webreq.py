import requests as r
import pandas as pd

get = r.get("http://172.20.241.9/luedataa_kannasta_groupid_csv.php?groupid=62")
#print (get.text)
testdata = pd.DataFrame([get.text])
testdata.to_csv('testdata.csv')


