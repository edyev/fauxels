#include<Adafruit_NeoPixel.h>
SoftPixel strip(24,6,NEO_GRB + NEO_KHZ800);
uint32_t count = 0;
uint8_t burst = 0, burst_count = 0;
uint32_t shades[] = {0xff, 0x140fff, 0x3326ff, 0x523dff, 0x7054ff, 
			   0x8f6bff, 0xad82ff, 0xcc99ff	};
uint32_t burst_shades[] = {0x544fff,0x7366ff,  0x927dff, 0xb094ff, 0xcfabff, 
			   0xedc2ff, 0xffd9ff, 0xffd9ff	};
void setup()
{
       pinMode(13, OUTPUT);
       Serial.begin(9600);
	//strip.begin();
}

void loop()
{
   
       
       for(uint8_t i = 0; i < 24; i++)
		strip.setPixelColor(i, 0);



       strip.setPixelColor((count + 7) % 24, shades[7]);
       strip.setPixelColor((count + 6) % 24, shades[6]);
       strip.setPixelColor((count + 5) % 24, 0x8f6bff);
       strip.setPixelColor((count + 4) % 24, 0x7054ff);
       strip.setPixelColor((count + 3) % 24, 0x523dff);
       strip.setPixelColor((count + 2) % 24, 0x3326ff);
       strip.setPixelColor((count + 1) % 24, 0x140fff);
       strip.setPixelColor(count % 24, 0xff);
       
       if(!(count % 3))
		burst = 1;
       if(burst){
                strip.setPixelColor((count + 7 - burst_count) % 24,/* 0xcc99ff */burst_shades[7 - burst_count]);
		++burst_count;
		
	}

       if(burst_count > 7){
		burst = 0;
		burst_count = 0;
			
	}       

     
       strip.show();
       
      	count++;
       delay(70);
}
