a.out: http_pac.cc
	c++ -O3 -fpermissive test.cc http_pac.cc -L. -lbinpac -Wl,-rpath,. -lpcre -g

http_pac.cc: http
	./binpac http
