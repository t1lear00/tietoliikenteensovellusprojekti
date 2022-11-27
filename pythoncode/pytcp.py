import socket

host = "172.20.241.9"
port = 20000
con = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
con.connect((host,port))
con.sendall(b'62\n')

li = []
while True:
    data = con.recv(1024)
    if len(data) == 0:
        break
    li.append(data.decode('utf-8'))

for i in li:
    print(i,end = '')    

con.close()