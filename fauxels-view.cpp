#include <stdint.h>
#include <stdio.h>
extern "C"
{
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
}

const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window*   window   = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

// List of leds per view and of view sizes
uint16_t fauxel_leds[256]       = {0};
uint16_t fauxel_view_size [256] = {0};
uint16_t fauxel_view_start[256] = {0};
uint8_t fauxel_view_count = 0;
uint32_t n_leds = 0;
extern "C" {
	void register_view(uint16_t start, uint16_t length)
	{
		// Track instances and assign leds to each view once.
		// TODO use static lists on the view classes.
		fauxel_view_count++;
		fauxel_view_size [fauxel_view_count] = length;
		fauxel_view_start[fauxel_view_count] = start;
		printf("In register view !!!\n");
		for(int i = start; i < start + length; i++)
		{
			if(fauxel_leds[i] == 0)
			{
				fauxel_leds[i] = fauxel_view_count;
			}
		}
	}

	void render_pixel(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
	{
		
		
		
		uint16_t x_center = SCREEN_WIDTH  / 2;
		uint16_t y_center = SCREEN_HEIGHT / 2;

		//printf("Rendering index:%u", index);
		
		// x_angle = index / n_leds * 360; x = cos(x_angle * M_PI / 360)
		uint16_t x = x_center + 150.0 * cos(index *1.0f / n_leds * M_PI * 2.0);
		uint16_t y = y_center + 150.0 * sin(index * 1.0f / n_leds * M_PI * 2.0);
		//printf("{x,y} = {%f, %f}\n", index *1.0f / n_leds * 360.0, sin(index * 1.0f / n_leds * 360.0));
		// Could derive from # of views and led count to squeeze into space
		uint16_t radius = 12;
		
		filledCircleRGBA( renderer, x, y, radius, r, g, b, 0xFF );
		//printf("Done rendering\n");
		// Alpha might be useful for simulating low color on leds (since its not black).
		// Could also draw overlapping alpha shapes since leds are individual colors.
		//SDL_SetRenderDrawColor( renderer, r, g, b, 0xFF );
		//SDL_Rect fillRect = { (SCREEN_WIDTH / 40) * index, SCREEN_HEIGHT / 2, 15, 15};
		//SDL_RenderFillRect( renderer, &fillRect );
	}

	// TODO drawing loop could be handled here instead of per pixel. Just need a local copy of the color buffer as each color is set
	void show_pixels()
	{
		//printf("[0] show_pixels()\n");

		//Update screen
		SDL_RenderPresent( renderer );

		// Clear for next?
		SDL_SetRenderDrawColor( renderer, 0x10, 0x10, 0x10, 0xFF );
		SDL_RenderClear( renderer );

		// Clear out events
		while( SDL_PollEvent( &event ) != 0 )
		{
			if( event.type == SDL_QUIT )
			{
				exit(0);
			}
		}
	}

	void initialize_pixels(uint16_t count)
	{
		printf("[0] initialize_pixels(%d)\n", count);

		SDL_Init( SDL_INIT_VIDEO );
		window = SDL_CreateWindow( "fauxel pixels", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( renderer );
		SDL_RenderPresent( renderer );
		n_leds = count;
	}
}
