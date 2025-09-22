#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int main()
{
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *music = Mix_LoadMUS("../assets/musica.mp3");
    Mix_PlayMusic(music, -1);

    SDL_Delay(10000);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
