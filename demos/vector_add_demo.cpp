#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Head-To-Tail Vector Addition");
    SetTargetFPS(60);

    Vector a{200, 100};
    Vector b{100, 150};

    while (!WindowShouldClose())
    {
        float speed = 200 * GetFrameTime();

        // Move A with arrow keys
        if (IsKeyDown(KEY_RIGHT))
            a.x += speed;

        if (IsKeyDown(KEY_LEFT))
            a.x -= speed;

        if (IsKeyDown(KEY_UP))
            a.y -= speed;

        if (IsKeyDown(KEY_DOWN))
            a.y += speed;

        Vector c = a + b;

        int ox = 400;
        int oy = 300;

        // Tip of A
        float ax = ox + a.x;
        float ay = oy + a.y;

        BeginDrawing();

        ClearBackground(BLACK);

        // Origin
        DrawCircle(ox, oy, 5, WHITE);

        // A (green)
        DrawLine(
            ox,
            oy,
            ax,
            ay,
            GREEN
        );

        // B starts from tip of A (blue)
        DrawLine(
            ax,
            ay,
            ax + b.x,
            ay + b.y,
            BLUE
        );

        // Result A+B (red)
        DrawLine(
            ox,
            oy,
            ox + c.x,
            oy + c.y,
            RED
        );

        // Draw endpoints
        DrawCircle(ax, ay, 4, GREEN);

        DrawCircle(
            ax + b.x,
            ay + b.y,
            5,
            RED
        );

        DrawText(
            TextFormat("A = (%.0f, %.0f)", a.x, a.y),
            20,
            20,
            20,
            GREEN
        );

        DrawText(
            TextFormat("B = (%.0f, %.0f)", b.x, b.y),
            20,
            50,
            20,
            BLUE
        );

        DrawText(
            TextFormat("A + B = (%.0f, %.0f)", c.x, c.y),
            20,
            80,
            20,
            RED
        );

        DrawText(
            "Arrow Keys Move Vector A",
            20,
            130,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}