
gcc server.c -o server  
./server  
  
in another terminal:  
gcc client.c -o client  
./client 127.0.0.1  
./client 0.0.0.0  
  
to see both server and client are running:  
sudo lsof -i -P -n  
  
for running client from IDE  
uncomment only client.c in CMakeLists.txt  
and add argument 0.0.0.0  

![](pics/Screenshot from 2022-04-20 12-10-19.png)


gcc main.c -o test
./test

gcc pingTest.c -o pingTest
/.pingTest




