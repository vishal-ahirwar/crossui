#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
inline void drawRoundedRect(SDL_Renderer *renderer, SDL_Rect rect, int radius)
{
    // Clamp radius
    if (radius > rect.w / 2)
        radius = rect.w / 2;
    if (radius > rect.h / 2)
        radius = rect.h / 2;

    // Draw center
    SDL_Rect center = {rect.x + radius, rect.y + radius, rect.w - 2 * radius, rect.h - 2 * radius};
    SDL_RenderFillRect(renderer, &center);

    // Draw sides
    SDL_Rect top = {rect.x + radius, rect.y, rect.w - 2 * radius, radius};
    SDL_Rect bottom = {rect.x + radius, rect.y + rect.h - radius, rect.w - 2 * radius, radius};
    SDL_Rect left = {rect.x, rect.y + radius, radius, rect.h - 2 * radius};
    SDL_Rect right = {rect.x + rect.w - radius, rect.y + radius, radius, rect.h - 2 * radius};

    SDL_RenderFillRect(renderer, &top);
    SDL_RenderFillRect(renderer, &bottom);
    SDL_RenderFillRect(renderer, &left);
    SDL_RenderFillRect(renderer, &right);

    // Draw corners (quarter circles)
    for (int w = 0; w < radius; ++w)
    {
        for (int h = 0; h < radius; ++h)
        {
            if ((w * w + h * h) <= (radius * radius))
            {
                // Top-left
                SDL_RenderDrawPoint(renderer, rect.x + radius - w, rect.y + radius - h);
                // Top-right
                SDL_RenderDrawPoint(renderer, rect.x + rect.w - radius + w - 1, rect.y + radius - h);
                // Bottom-left
                SDL_RenderDrawPoint(renderer, rect.x + radius - w, rect.y + rect.h - radius + h - 1);
                // Bottom-right
                SDL_RenderDrawPoint(renderer, rect.x + rect.w - radius + w - 1, rect.y + rect.h - radius + h - 1);
            }
        }
    }
}
