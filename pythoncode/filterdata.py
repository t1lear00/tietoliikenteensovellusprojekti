import pandas as pd
import numpy as np

df = pd.read_csv('C:\\GITHUB\\tietoliikenteensovellusprojekti\\sqldata.csv',
    header=0,
    delimiter= ",")
    #names=['x','y','z'])
    #usecols=['x','y','z',])
#print(df,"df")
df=df.astype(np.int64)
#df= df.drop("")
npxyz = df.to_numpy()
npxyz = np.delete(npxyz, 0).reshape(555,1)
print(np.count_nonzero(npxyz <1024),"np")
print(npxyz)
#filterd = pd.DataFrame([npxyz])
#filterd.to_csv('fixdata.csv')
#rsdf = df[(df['x']>100) & (df['y']>100) & (df['z']>100)]
with open('filtereddata.txt', 'w') as f:
    f.write(str(npxyz))