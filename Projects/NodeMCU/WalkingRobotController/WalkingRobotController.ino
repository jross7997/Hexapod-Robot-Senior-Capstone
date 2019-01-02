//Code for Hexapod Capstone Cotroller
//Written for NODEMCU 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "index.h"

const char *ssid = "CAPSTONE";
const char *password = "SUNY2018";
const int max_connection = 1;

String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String page = MAIN_page;
String request = "";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password,max_connection);
  IPAddress myIP = WiFi.softAPIP();
  server.begin();
}

void loop() {
    WiFiClient client = server.available();
    if (!client)  { 
      return; 
    }
    request = client.readStringUntil('\r');

  if ( request.indexOf("STOP") > 0 ) { 
                Serial.print('S');
                client.print( header );
                client.print( "Stop was Pressed" );  
  }else if ( request.indexOf("UP") > 0 ) { 
                Serial.print('U');
                client.print( header );
                client.print( "Up was Pressed" );             
   }else if  ( request.indexOf("DOWN") > 0 ) { 
                Serial.print('D');   
                client.print( header );
                client.print( "Down was Pressed" ); 
   }else if  ( request.indexOf("LEFT") > 0 ){  
                Serial.print('L'); 
                client.print( header );
                client.print( "Left was Pressed" ); 
   }else if  ( request.indexOf("RIGHT") > 0 ) { 
                Serial.print("R");
                client.print( header );
                client.print( "Right was Pressed" );             
   }else if  ( request.indexOf("HELLO") > 0 ) {
                Serial.print("H");
                client.print( header );
                client.print( "Hello World!" ); 
   }else if (request.indexOf("WAVE") > 0) {
                Serial.print("W");
                client.print( header );
                client.print( "Hello World!" );    
   }else if (request.indexOf("CONT") > 0){
                Serial.print("C");
                client.print( header );
    }else if (request.indexOf("FAST") > 0){
                Serial.print("F");
                client.print( header );
//                //client.print( "Hello World!" );             
////Uncomment these if you need to test each leg
//   }else if  ( request.indexOf("LF") > 0 ) { 
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("1");
//                client.print( header );
//                client.print( "LF" );             
//   }else if  ( request.indexOf("LM") > 0 ) { 
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("2");
//                client.print( header );
//                client.print( "LM" );             
//   }else if  ( request.indexOf("LB") > 0 ) { 
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("3");
//                client.print( header );
//                client.print( "LB" );             
//   }else if  ( request.indexOf("RF") > 0 ) { 
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("4");
//                client.print( header );
//                client.print( "RF" );             
//   }else if  ( request.indexOf("RM") >0) {
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("5");
//                client.print( header );
//                client.print( "RM" );             
//   }else if  ( request.indexOf("RB") > 0 ) { 
//                //digitalWrite(LED_Pin, HIGH);  
//                Serial.print("6");
//                client.print( header );
//                client.print( "RB" );             
   }else {
                client.flush();
                client.print( header );
                client.print( page );    
                delay(5);
    }
}

