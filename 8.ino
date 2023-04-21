#include <SPI.h>

const int SPI_SCLK = 2;
const int SPI_MOSI = 3;
const int SPI_MISO = 4;
const int SPI_CS = 5;

short DA, spiData;
char channel = 0;
int t = 0;
int i,j;
float v;
float Hz[8] = {1, 2, 3, 4, 5, 6, 7, 8};
float sin_ha[8][1000];
//unsigned long time;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.setRX(SPI_MISO);
  SPI.setCS(SPI_CS);
  SPI.setSCK(SPI_SCLK);
  SPI.setTX(SPI_MOSI);
  SPI.begin(true);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  initializeData();

}

void loop() {
  // put your main code here, to run repeatedly:
  t = (t+1)%1000;
  for(i = 0; i < 8; i++){
    DAout(i, sin_ha[i][t]);
  }
}


void initializeData(){
  for(i = 0; i < 8; i++){
    for(j = 0; j < 1000; j++){
      sin_ha[i][j] = 0;
    }
  }

  for(i = 0; i < 8; i++){
    for(j = 0; j < 1000; j++){
      sin_ha[i][j] = 2.0*(sin(2.0*PI*Hz[i]*j/1000.0));
    }
  }
}

void DAout(char channel, float voltage){
  
  DA = (voltage/5.0) * 1023;
  spiData = (((channel&0x07)+1)<<12) | ((int)(DA&0x3FF)<<2);
  SPI.transfer16(spiData);
}
