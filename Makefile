.all: sutest

sutest:
	gcc -g -o sutest test.c
	sudo chown root sutest
	sudo chgrp root sutest
	sudo chmod u+s sutest

clean:
	rm -rf sutest
