#include "http_pac.h"

using namespace binpac;
using namespace binpac::HTTP;

int main(int argc, char **argv)
{
  char http[] =
    "GET /foo/bar/baz/barf/quux.html HTTP/1.1\r\n"
    "Host: www.google.fi\r\n"
    //"\twww.google2.fi\r\n"
    "User-Agent: Mozilla/5.0 (Linux; Android 7.0; SM-G930VC Build/NRD90M; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/58.0.3029.83 Mobile Safari/537.36\r\n"
    "Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,image/jpeg,image/gif;q=0.2,*/*;q=0.1\r\n"
    "Accept-Language: en-us,en;q=0.5\r\n"
    "Accept-Encoding: gzip,deflate\r\n"
    "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n"
    "Keep-Alive: 300\r\n"
    "Connection: keep-alive\r\n"
    "Referer: http://www.google.fi/quux/barf/baz/bar/foo.html\r\n"
    "Cookie: PHPSESSID=298zf09hf012fh2; csrftoken=u32t4o3tb3gg43; _gat=1;\r\n"
    "\r\n";

  HTTP_Request req;
  FlowBuffer buf;
  int i;
  for (i = 0; i < 100*1000; i++)
  {
    req = HTTP_Request();
    buf = FlowBuffer();
    buf.NewData(http, http+sizeof(http));
    req.ParseBuffer(&buf);
  }
}
