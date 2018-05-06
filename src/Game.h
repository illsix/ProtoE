#pragma once
#include<SDL.h>
#include<stdio.h>
#include<memory>
#include<iostream>
#include<stdlib.h>

namespace sdl2 {
	struct SDL_Deleter {
		void operator()(SDL_Surface* ptr) { if (ptr)SDL_FreeSurface(ptr); }
		void operator()(SDL_Renderer* ptr) { if (ptr)SDL_DestroyRenderer(ptr); }
		void operator()(SDL_Window* ptr) { if (ptr)SDL_DestroyWindow(ptr); }
	};

	using WindowPtr = std::unique_ptr<SDL_Window, SDL_Deleter>;
	using RendererPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
}

class Game
{
public:
	explicit Game(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	~Game();

	void Init();

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running();
private:
	bool							m_isRunning;
	sdl2::WindowPtr					m_window;
	sdl2::RendererPtr				m_renderer;
};

