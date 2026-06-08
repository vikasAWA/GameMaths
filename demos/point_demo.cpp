#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    Point p{400, 300};

    InitWindow(800, 600, "Point Demo");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        if (IsKeyDown(KEY_RIGHT))
            p.x += 200 * GetFrameTime();

        if (IsKeyDown(KEY_LEFT))
            p.x -= 200 * GetFrameTime();

        if (IsKeyDown(KEY_UP))
            p.y -= 200 * GetFrameTime();

        if (IsKeyDown(KEY_DOWN))
            p.y += 200 * GetFrameTime();

        DrawCircle(
            p.x,
            p.y,
            8,
            RED
        );

        DrawText(
            "This red dot is a Point",
            20,
            20,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}