a.out: http_pac.cc test.cc
	c++ -I. -O3 -fpermissive test.cc http_pac.cc -lbinpac -lpcre -g

http_pac.cc: http
	binpac http
