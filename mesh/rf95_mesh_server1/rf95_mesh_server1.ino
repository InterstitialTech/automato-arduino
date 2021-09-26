// rf95_mesh_server1.ino
// -*- mode: C++ -*-
// Example sketch showing how to create a simple addressed, routed reliable messaging server
// with the RHMesh class.
// It is designed to work with the other examples rf95_mesh_*
// Hint: you can simulate other network topologies by setting the 
// RH_TEST_NETWORK define in RHRouter.h

// Mesh has much greater memory requirements, and you may need to limit the
// max message length to prevent wierd crashes

//(9/20/2019)   Contributed by Brody M. Based off rf22_mesh_server1.pde.
//              Raspberry Pi mods influenced by nrf24 example by Mike Poublon,
//              and Charles-Henri Hallard (https://github.com/hallard/RadioHead)

// (9/26/2021)  ported for Automato from the rpi version

#include <SPI.h>
#include <RHMesh.h>
#include <RH_RF95.h>

#define RH_MESH_MAX_MESSAGE_LEN 50

//Function Definitions
void sig_handler(int sig);

// In this small artifical network of 4 nodes,
#define CLIENT_ADDRESS 1
#define SERVER1_ADDRESS 2
#define SERVER2_ADDRESS 3
#define SERVER3_ADDRESS 4

//RFM95 Configuration
#define RFM95_FREQUENCY  915.00
#define RFM95_TXPOWER 14

// Singleton instance of the radio driver
RH_RF95 rf95(PIN_LORA_CS, PIN_LORA_IRQ); // Slave select, interrupt pin for Automato Sensor Module.

// Class to manage message delivery and receipt, using the driver declared above
RHMesh manager(rf95, SERVER1_ADDRESS);

//Flag for Ctrl-C
int flag = 0;

void setup() 
{
  pinMode(PIN_LORA_RST, INPUT); // Let the pin float.

  // Disable other automato SPI devices.
  pinMode(PIN_LCD_CS, OUTPUT);
  digitalWrite(PIN_LCD_CS, HIGH);
  pinMode(PIN_TCH_CS, OUTPUT);
  digitalWrite(PIN_TCH_CS, HIGH);
  pinMode(PIN_SD_CS, OUTPUT);
  digitalWrite(PIN_SD_CS, HIGH);
  
  Serial.begin(115200);
  //while (!Serial) ; // Wait for serial port to be available
  Serial.println("Initializing LoRa"); 
  if (!rf95.init())
    Serial.println("init failed");
  // Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
  rf95.setFrequency(915.0);

  // The default transmitter power is 13dBm, using PA_BOOST.
  // You can set transmitter powers from 5 to 23 dBm:
  //  driver.setTxPower(23);

  if (!manager.init())
  {
    Serial.println( "\n\nMesh Manager Failed to initialize.\n\n" );
    // return 1;
  }

  /* Begin Manager/Driver settings code */
  Serial.println("RFM 95 Settings:");

  Serial.print("Frequency="); 
  Serial.print(RFM95_FREQUENCY);
  Serial.println("MHz\n");

  Serial.print("Power= ");
  Serial.println(RFM95_TXPOWER);

  Serial.print("Client Address= ");
  Serial.println(CLIENT_ADDRESS);
  
  Serial.print("Server(This) Address 1= ");
  Serial.println( SERVER1_ADDRESS);

  Serial.print("Server Address 2= ");
  Serial.println( SERVER2_ADDRESS);

  Serial.print("Server Address 3= ");
  Serial.println( SERVER3_ADDRESS);

  Serial.println("Route: Client->Server 3 is automatic in MESH.\n");

  rf95.setTxPower(RFM95_TXPOWER, false);
  rf95.setFrequency(RFM95_FREQUENCY);
  /* End Manager/Driver settings code */

  Serial.println( "\nrf95_mesh_client startup OK.\n" );

}

uint8_t data[] = "And hello back to you from server1";
// Dont put this on the stack:
uint8_t buf[RH_MESH_MAX_MESSAGE_LEN];

//Main Function
void loop ()
{
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (manager.recvfromAck(buf, &len, &from))
    {
      Serial.print("got request from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);

      // Send a reply back to the originator client
      if (manager.sendtoWait(data, sizeof(data), from) != RH_ROUTER_ERROR_NONE)
        Serial.println("sendtoWait failed");
    }
}

