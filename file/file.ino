#include "SPI.h"
#include "Ethernet.h"

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

char server[] = "https://4cloud.pro"; 

EthernetClient client;

void setup ()
{
  Ethernet.begin (mac);
}

void loop ()
{
  
}

int GetData ()
{
  int sym = 0;

  int res = 0;
  
  client.connect (server, 80);

  client.print ("GET /version.php HTTP/1.1");

  sym = client.read();

  while(sym != -1)
  {
     res *= 10;

     res += sym - '0';

     sym = client.read();
  }

  return res;
}
