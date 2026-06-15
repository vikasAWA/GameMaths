#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Dot Product Demo");
    SetTargetFPS(60);

    int ox = 400;
    int oy = 300;

    Vector fixed{200, 0};

    while (!WindowShouldClose())
    {
        Vector mouse{
            (float)GetMouseX() - ox,
            (float)GetMouseY() - oy
        };

        Vector a = fixed.Normalize();
        Vector b = mouse.Normalize();

        float dot = a.dotProduct(b);

        Color resultColor;

        if (dot > 0.3f)
            resultColor = GREEN;
        else if (dot < -0.3f)
            resultColor = RED;
        else
            resultColor = YELLOW;

        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircle(ox, oy, 5, WHITE);

        // Fixed vector
        DrawLine(
            ox,
            oy,
            ox + fixed.x,
            oy + fixed.y,
            GREEN
        );

        // Mouse vector
        DrawLine(
            ox,
            oy,
            ox + mouse.x,
            oy + mouse.y,
            BLUE
        );

        DrawText(
            TextFormat("Dot Product: %.2f", dot),
            20,
            20,
            30,
            resultColor
        );

        DrawText(
            "Move Mouse Around",
            20,
            60,
            20,
            WHITE
        );

        DrawText(
            "Green = Fixed Vector",
            20,
            90,
            20,
            GREEN
        );

        DrawText(
            "Blue = Mouse Vector",
            20,
            120,
            20,
            BLUE
        );

        EndDrawing();
    }

    CloseWindow();
}