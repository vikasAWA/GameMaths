#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Normalize Demo");
    SetTargetFPS(60);

    Vector v{200, 100};

    while (!WindowShouldClose())
    {
        float speed = 200 * GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
            v.x += speed;

        if (IsKeyDown(KEY_LEFT))
            v.x -= speed;

        if (IsKeyDown(KEY_UP))
            v.y -= speed;

        if (IsKeyDown(KEY_DOWN))
            v.y += speed;

        Vector n = v.Normalize();

        BeginDrawing();

        ClearBackground(BLACK);

        // Origin
        int ox = 400;
        int oy = 300;

        DrawCircle(ox, oy, 5, WHITE);

        // Original vector
        DrawLine(
            ox,
            oy,
            ox + v.x,
            oy + v.y,
            GREEN
        );

        // Normalized vector (scaled so we can see it)
        DrawLine(
            ox,
            oy,
            ox + n.x * 100,
            oy + n.y * 100,
            RED
        );

        DrawText(
            TextFormat("Original Length: %.2f", v.Length()),
            20,
            20,
            20,
            GREEN
        );

        DrawText(
            TextFormat("Normalized Length: %.2f", n.Length()),
            20,
            50,
            20,
            RED
        );

        DrawText(
            "Arrow Keys = Move Vector",
            20,
            90,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}