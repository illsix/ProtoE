#include "Game.h"

std::unique_ptr<Game> GameInst = nullptr;

int main(int argc, char** argv)
{
	GameInst = std::make_unique<Game>("ProtoEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	const auto pGameInst = GameInst.get();
	pGameInst->Init();

	while (pGameInst->Running())
	{
		pGameInst->HandleEvents();
		pGameInst->Update();
		pGameInst->Render();
	}

	pGameInst->Clean();
	return 0;
}