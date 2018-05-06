#include "Game.h"



Game::Game(const char * title, int xPos, int yPos, int width, int height, bool fullScreen) :
	m_isRunning(false),
	m_window(nullptr),
	m_renderer(nullptr)
{
	int flags = 0;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized!..." << std::endl;

		m_window = sdl2::WindowPtr(SDL_CreateWindow(title, xPos, yPos, width, height, flags));

		if (m_window.get())
		{
			std::cout << "Window created!" << std::endl;
		}

		m_renderer = sdl2::RendererPtr(SDL_CreateRenderer(m_window.get(), -1, 0));

		if (m_renderer.get())
		{
			SDL_SetRenderDrawColor(m_renderer.get(), 0xff, 0xff, 0xff, 0xff);
			std::cout << "Renderer created!" << std::endl;
		}

		m_isRunning = true;
	}
	else
	{
		m_isRunning = false;
	}
}


Game::~Game()
{
}

void Game::Init()
{

}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;

	default:
		break;
	}
}

void Game::Update()
{
}

void Game::Render()
{
	SDL_RenderClear(m_renderer.get());
	SDL_RenderPresent(m_renderer.get());
}

void Game::Clean()
{
	SDL_DestroyWindow(m_window.get());
	SDL_DestroyRenderer(m_renderer.get());
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

bool Game::Running()
{
	return m_isRunning;
}
