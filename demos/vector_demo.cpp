#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    Vector v{200,100};

    InitWindow(800,600,"Vector Demo");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        if (IsKeyDown(KEY_RIGHT))
            v.x += 100 * GetFrameTime();

        if (IsKeyDown(KEY_LEFT))
            v.x -= 100 * GetFrameTime();

        if (IsKeyDown(KEY_UP))
            v.y -= 100 * GetFrameTime();

        if (IsKeyDown(KEY_DOWN))
            v.y += 100 * GetFrameTime();
                

        DrawLine(
            400,
            300,
            400 + v.x,
            300 + v.y,
            GREEN
        );
        DrawText(
            TextFormat("Length: %.2f", v.Length()),
            20,
            20,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}