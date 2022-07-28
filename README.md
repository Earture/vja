# vja
Convert japanese sentence from horizontal to vertical

# usage

`git clone` \
`gcc vja.c -o vja` \
## Please make sure that the text you enter is utf8 encoded Japanese full width characters
`./vja  < xxx.txt` or `cat xxx.txt | ./vja` 

Of course, you can also customize the number of text contained in each column \
`./vja 10 < xxx.txt` or `cat xxx.txt | ./vja 10` 
