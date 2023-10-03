extern "C"
{
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_revision.h>
}
#include <boost/multi_array.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <spdlog/spdlog.h>
namespace orail
{
    namespace detail
    {
        enum class pathway_type
        {
            OPEN,
            BLOCKED,
            WAITING,
        };
    }
    class pathway : boost::array<detail::pathway_type, 8>
    {
    public:
        using type = detail::pathway_type;
    };
    class router
    {
    public:
        enum class type
        {
            CONNECTION,
            TURNOUT,
            SIGNAL
        };
    };
    class tile
    {
    public:
    private:
        boost::optional<router> m_router;
        pathway                 inbound_pathway;
        pathway                 outbound_pathway;
    };
    class map
    {
    public:
        using array_type = boost::array<boost::array<tile, 128>, 128>;

    private:
        array_type m_data;

    public:
        map(){};
    };
} // namespace orail
using namespace orail;
int main()
{
    spdlog::info("Openrail beta version.");
    spdlog::info("Copyright (C) 2023 AlanCui4080");
    // clang-format off
    spdlog::info("This is free software; see the source for copying conditions.");
    spdlog::info("There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.");
    // clang-format on

    SDL_version compiled;
    SDL_version linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    spdlog::info("SDL Library version: {}.{}.{} ({})", compiled.major,
                 compiled.minor, compiled.patch, SDL_REVISION);
    spdlog::info("SDL Runtime version: {}.{}.{} ({})", linked.major,
                 linked.minor, linked.patch, SDL_GetRevision());

    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        spdlog::error("SDL_Init Error:{}", SDL_GetError());
    }
    auto handle_windows = SDL_CreateWindow(
        "Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (!handle_windows)
    {
        spdlog::error("SDL_CreateWindow Error:{}", SDL_GetError());
    }
    auto handle_renderer = SDL_CreateRenderer(handle_windows, -1, 0);
    if (!handle_renderer)
    {
        spdlog::error("SDL_CreateRenderer Error:{}", SDL_GetError());
    }
    if (SDL_RenderSetLogicalSize(handle_renderer, 1600, 900))
    {
        spdlog::error("SDL_RenderSetLogicalSize Error:{}", SDL_GetError());
    }
    SDL_SetRenderDrawColor(handle_renderer, 255, 255, 255, 127);
    if (SDL_RenderDrawLine(handle_renderer, 160, 90, 192, 108))
    {
        spdlog::error("SDL_RenderDrawLine Error:{}", SDL_GetError());
    }
    while (1)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            spdlog::info("exiting...");
            SDL_DestroyWindow(handle_windows);
            SDL_Quit();
            return 0;
        }
    }
}
