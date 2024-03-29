import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sklearn
from mpl_toolkits.mplot3d import Axes3D

numberofrows = 185
#df = pd.read_csv('C:\\GITHUB\\tietoliikenteensovellusprojekti\\sqldata.csv')
#print(df)
te = np.loadtxt('filtereddata.txt')
ar = np.array(te).reshape(numberofrows,3)
kp =np.random.randint(420, size= (4,3))
counts = np.zeros(4).reshape(1,4)
distance = np.arange(4).reshape(1,4)
#print(distance, distance[0,0],distance[0,1], distance[0,2])
centerpoint = np.zeros(12).reshape(4,3)
x, y, z = ar[::, 0], ar[::, 1], ar[::, 2]
x1, y1, z1 = kp[::, 0], kp[::, 1], kp[::, 2]
#print(ar, "array")
print(kp, "kp alku")

def getdistance(a,b):
    dis = np.linalg.norm(a-b)
   # print(dis)
    return dis


dd = getdistance(kp[0],ar[1])
#distance2 = np.linalg.norm(ar[0]-ar[1])
print("distance = ",dd)
x = 0
lap = 1
loop = 0
while loop < 200:
    for i in  range(numberofrows):
      
      #counts = np.zeros(4).reshape(1,4)
      distance[0,0] = getdistance(kp[0],ar[x]) #mitataan distance
      distance[0,1] = getdistance(kp[1],ar[x])
      distance[0,2] = getdistance(kp[2],ar[x])
      distance[0,3] = getdistance(kp[3],ar[x])
      min = np.amin(distance)
      if min == distance[0,0]:
       centerpoint[0] = ar[x]+centerpoint[0]    #lasketaan voitetut pisteet
       counts[0,0] = counts[0,0]+1

      if min == distance[0,1]:
       centerpoint[1] = ar[x]+centerpoint[1]
       counts[0,1] = counts[0,1]+1

      if min == distance[0,2]:
       centerpoint[2] = ar[x]+centerpoint[2]
       counts[0,2] = counts[0,2]+1

      if min == distance[0,3]:
       centerpoint[3] = ar[x]+centerpoint[3]
       counts[0,3] = counts[0,3]+1

      x = x+1
      #loop = loop +1
      
      #fixed centerpoints centerpointsum / count
      while x == numberofrows:
        #print(x)
        if counts[0,0] == 0:
            kp[0] =np.random.randint(420, size= (3))
            counts = np.zeros(4).reshape(1,4)
            centerpoint = np.zeros(12).reshape(4,3)
            x=0
    
        if counts[0,1] == 0:
            kp[1] =np.random.randint(420, size= (3))
            counts = np.zeros(4).reshape(1,4)
            centerpoint = np.zeros(12).reshape(4,3)
            x = 0
        
        if counts[0,2] == 0:
            kp[2] =np.random.randint(420, size= (3))
            counts = np.zeros(4).reshape(1,4)
            centerpoint = np.zeros(12).reshape(4,3)
            x = 0
        
        if counts[0,3] == 0:
            kp[3] =np.random.randint(420, size= (3))
            counts = np.zeros(4).reshape(1,4)
            centerpoint = np.zeros(12).reshape(4,3)
            x = 0
            
        else :
         kp[0] = centerpoint[0] / counts[0,0]
         kp[1] = centerpoint[1] / counts[0,1]
         kp[2]= centerpoint[2] / counts[0,2]
         kp[3] = centerpoint[3] / counts[0,3]
         #counts = np.zeros(4).reshape(1,4)
         #centerpoint = np.zeros(12).reshape(4,3)
         x = 0
         loop = loop +1
         

print(counts,centerpoint)
print(kp,"x =", x)
np.append(ar, kp)
#print()
fig = plt.figure()
ax = fig.add_subplot(1,1,1, projection='3d')
ax.scatter3D(x, y, z, color = 'red')

plt.title("data points")
plt.show()
