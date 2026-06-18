#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    InitWindow(1200, 700, "Distance Demo");
    SetTargetFPS(60);

    Point fixed{600, 350};

    while (!WindowShouldClose())
    {
        Point mouse{
            (float)GetMouseX(),
            (float)GetMouseY()
        };

        float distance =
            fixed.Distance(mouse);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawLine(
            fixed.x,
            fixed.y,
            mouse.x,
            mouse.y,
            WHITE
        );

        DrawCircle(
            fixed.x,
            fixed.y,
            20,
            GREEN
        );

        DrawCircle(
            mouse.x,
            mouse.y,
            20,
            RED
        );

        DrawText(
            TextFormat(
                "Distance: %.2f",
                distance
            ),
            20,
            20,
            30,
            WHITE
        );

        DrawText(
            "Move mouse around",
            20,
            60,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}