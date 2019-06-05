#include<Adafruit_NeoPixel.h>
SoftPixel strip(24,6,NEO_GRB + NEO_KHZ800);
uint32_t count = 0;
uint8_t burst = 0, burst_count = 0;
uint32_t shades[] = {0xff, 0x140fff, 0x3326ff, 0x523dff, 0x7054ff, 
			   0x8f6bff, 0xad82ff, 0xcc99ff	};
uint32_t burst_shades[] = {0x544fff,0x7366ff,  0x927dff, 0xb094ff, 0xcfabff, 
			   0xedc2ff, 0xffd9ff, 0xffd9ff	};
uint32_t cos_coeff = 0;
void setup()
{
       pinMode(13, OUTPUT);
       Serial.begin(9600);
	//strip.begin();
}

void loop(){

   
       
       for(uint8_t i = 0; i < 24; i++)
		strip.setPixelColor(i, 0x550000);


	/*
      strip.setPixelColor(0, 0x0099ff); // cyan
      strip.setPixelColor(1, 0x1aa3e6);
      strip.setPixelColor(2, 0x4cb8b2);
      strip.setPixelColor(3, 0x8cd173);
      strip.setPixelColor(4, 0xcceb33);
      strip.setPixelColor(5, 0xffff00); // yellow
      strip.setPixelColor(6, 0xffcc00);  
      strip.setPixelColor(7, 0xff8c00);
      strip.setPixelColor(8, 0xff5900);
      strip.setPixelColor(9, 0xff4000);
      strip.setPixelColor(10, 0xff1a00);	
      strip.setPixelColor(11, 0xff0000); //red
      strip.setPixelColor(12, 0xcc0014); 
      strip.setPixelColor(13, 0x990029); 
      strip.setPixelColor(14, 0x730038); 
      strip.setPixelColor(15, 0x4d0047); 
      strip.setPixelColor(16, 0x260057);
      strip.setPixelColor(17, 0x000066);//blue*/

           
      for(uint8_t i = 0; i < 24; ++i){
      cos_coeff = (uint32_t)(((uint8_t)(10 + 245 * (0.5 + 0.5 * sin((2.0 * M_PI * i + count)/ 4)))) << 16);
      //0.5 + 0.5 * cos(2 * M_PI * i / 11);
      strip.setPixelColor(i, cos_coeff);
      }
    /*  strip.setPixelColor(0, 0x00ffff); // cyan
      strip.setPixelColor(1, 0x00a6ff); //0 110 253
      strip.setPixelColor(2, 0xff);
      strip.setPixelColor(3, 0x5400ff);
      strip.setPixelColor(4, 0xff00ff);
      strip.setPixelColor(5, 0xff02e1);
      strip.setPixelColor(6, 0xff0000);	
      strip.setPixelColor(7, 0xff5b01);
      strip.setPixelColor(8, 0xffff00);
      strip.setPixelColor(9, 0xa4ff00);
      strip.setPixelColor(10, 0x00ff00);*/

      /*strip.setPixelColor(5, 0x0099ff);
      strip.setPixelColor(6, 0x0099ff);
      strip.setPixelColor(7, 0x0099ff);
      strip.setPixelColor(8, 0x0099ff);
      strip.setPixelColor(9, 0x0099ff);
      strip.setPixelColor(10, 0x0099ff);
      strip.setPixelColor(11, 0x0099ff);
      */
       
     
       strip.show();
       count++;
      
       delay(70);
}
