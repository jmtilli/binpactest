a.out: http_pac.cc test.cc
	c++ -I. -O3 -fpermissive test.cc http_pac.cc -lbinpac -lpcre -g

a.out.pcre2: http_pac.cc test.cc
	c++ -o a.out.pcre2 -I. -O3 -fpermissive test.cc http_pac.cc -lbinpac -lpcre2-8 -g

http_pac.cc: http
	binpac http
