# vja
Convert japanese sentence from horizontal to vertical 
![image](https://github.com/Earture/vja/blob/main/vja.png)

# usage
### running it on macos\linux\wsl
`git clone https://github.com/Earture/vja` \
`cd vja` \
`gcc vja.c -o vja` 
### Please make sure that the text you enter is utf8 encoded Japanese full width characters， if not you can use [fja](https://github.com/Earture/fja) to convert it first.
`./vja  < xxx.txt` or `cat xxx.txt | ./vja` 

Of course, you can also customize the number of text contained in each column \
`./vja 10 < xxx.txt` or `cat xxx.txt | ./vja 10` 
