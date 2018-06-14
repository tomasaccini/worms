#ifndef __SDL_WINDOW_H__
#define __SDL_WINDOW_H__

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include "../common/common_Thread.h"
#include "../common/common_SafeQueue.h"
#include "client_Area.h"
#include "src/client/client_SdlTexture.h"
#include "client_IDrawable.h"
#include "client_BeamDrawable.h"
#include "client_ClosedConnectionDrawable.h"
#include "client_DynamiteDrawable.h"
#include "client_DynamiteExplosionDrawable.h"
#include "client_EndTurnDrawable.h"
#include "client_RadiocontrolledDrawable.h"
#include "client_RadiocontrolledExplosionDrawable.h"
#include "client_StageDrawable.h"
#include "client_StartTurnDrawable.h"
#include "client_TurnTimeDrawable.h"
#include "client_WormDrawable.h"

#define WORM_SIZE 40
#define DYNAMITE_SIZE 40
#define RADIOCONTROLLED_SIZE 40
#define DYNAMITE_ID -1

class SdlWindow;
class SdlTexture;
class Area;
class IDrawable;
class BeamDrawable;
class ClosedConnectionDrawable;
class DynamiteDrawable;
class DynamiteExplosionDrawable;
class EndTurnDrawable;
class RadiocontrolledDrawable;
class RadiocontrolledExplosionDrawable;
class StageDrawable;
class StartTurnDrawable;
class TurnTimeDrawable;
class WormDrawable;

using std::map;

class SdlWindow : public Thread {
private:
    SafeQueue<IDrawable*>& safe_queue;
    int width;
    int height;
    bool connected;
    SDL_Window* window;
    SDL_Renderer* renderer;
    map<int, SdlTexture*> worms_textures;
    map<int, SdlTexture*> weapons_textures;
    std::vector<SdlTexture*> static_textures;
    void draw(IDrawable* drawable);

    SdlWindow(const ConsoleDrawer&) = delete;
    SdlWindow& operator=(const ConsoleDrawer&) = delete;
public:
    SdlWindow(SafeQueue<IDrawable*>& _safe_queue, int width, int height);
    SdlWindow(SdlWindow&& other) = default;
    void draw(StartTurnDrawable* drawable);
    void draw(EndTurnDrawable* drawable);
    void draw(TurnTimeDrawable* drawable);
    void draw(WormDrawable* drawable);
    void draw(StageDrawable* drawable);
    void draw(BeamDrawable* drawable);
    void draw(DynamiteDrawable* drawable);
    void draw(DynamiteExplosionDrawable* drawable);
    void draw(RadiocontrolledDrawable* drawable);
    void draw(RadiocontrolledExplosionDrawable* drawable);
    void draw(ClosedConnectionDrawable* drawable);
    void run() override;
    void stop();
    bool is_connected();
    void fill();
    void fill(int r, int g, int b, int alpha);
    void render();
    SDL_Renderer* getRenderer() const;
    ~SdlWindow();
};

#endif
