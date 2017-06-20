#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { ***, ***, ***, *** };
byte es[] = { 8, 8, 8, 8 };
byte gateway[] = { ***, ***, ***, *** };
byte subnet[] = { 255, 255, 252, 0 };
byte server[] = { ***, ***, ***, *** }; // Botanicapp

EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip, es, gateway, subnet); 
  //Ethernet.begin(mac, ip);
  Serial.begin(9600);
  
  //delay(1000);

  //Serial.println("connecting...");
  
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /cleyton/estagiarios/acesso.php?id=****&cod=**** HTTP/1.0"); //perceptron.php?id=*****
    client.println();
    delay(3000);
  } else {
    Serial.println("connection failed");
    delay(3000);
  }
 
}

void loop()
{
  
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    //for(;;)
    //  ;
  }

  if(Serial.available()>0){
    String a = Serial.readString(); 
    String b = a.substring(0,2);
    String c = a.substring(3,5);
    String d = a.substring(6,8);
    String e = a.substring(9,11);
    String dado = b+"%20"+c+"%20"+d+"%20"+e;
    enviaDado(dado);  
  }
  
}

int enviaDado(String id){
  Serial.println("connecting...");
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /cleyton/estagiarios/novoAcesso.php?id="+id+"&cod=***** HTTP/1.0"); //perceptron.php?id=*****
    client.println();
    client.stop();  
  } else {
    Serial.println("connection failed");
  }
  delay(4900);
}
