vja: 
	gcc vja.c -o vja

install: vja
	sudo cp vja /usr/local/bin/vja

uninstall: 
	sudo rm /usr/local/bin/vja
