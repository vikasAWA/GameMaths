#include "math/GameMath.h"
#include <raylib.h>

int main()
{
    InitWindow(1200, 700, "Lerp vs Approach");
    SetTargetFPS(60);

    Point approachPos{400, 300};
    Point lerpPos{400, 400};

    while(!WindowShouldClose())
    {
        float dt = GetFrameTime();

        float mouseX = GetMouseX();
        float mouseY = GetMouseY();

        // Green circle
        approachPos.x =
            Approach(
                approachPos.x,
                mouseX,
                200 * dt
            );

        approachPos.y =
            Approach(
                approachPos.y,
                mouseY,
                200 * dt
            );

        // Blue circle
        lerpPos.x =
            Lerp(
                lerpPos.x,
                mouseX,
                0.03f
            );

        lerpPos.y =
            Lerp(
                lerpPos.y,
                mouseY,
                0.03f
            );

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText(
            "Move Mouse Around",
            20,
            20,
            30,
            WHITE
        );

        DrawText(
            "GREEN = Approach",
            20,
            60,
            20,
            GREEN
        );

        DrawText(
            "BLUE = Lerp",
            20,
            90,
            20,
            BLUE
        );

        DrawCircle(mouseX, mouseY, 8, RED);

        DrawCircle(
            approachPos.x,
            approachPos.y,
            25,
            GREEN
        );

        DrawCircle(
            lerpPos.x,
            lerpPos.y,
            25,
            BLUE
        );

        EndDrawing();
    }

    CloseWindow();
}