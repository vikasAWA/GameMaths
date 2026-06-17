#include "math/GameMath.h"
#include <raylib.h>
#include <vector>
int main()
{
    InitWindow(800, 600, "Jump Demo");
    SetTargetFPS(60);

    Point position{100, 500};

    Vector velocity{0, 0};

    Vector gravity{0, 980};

    std::vector<Point> trail;

    bool onGround = true;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        if (trail.empty() ||
            position.x != trail.back().x ||
            position.y != trail.back().y)
            {
            trail.push_back(position);
            }

        // Jump
        if (IsKeyPressed(KEY_SPACE) && onGround)
        {
            velocity.y = -700;
            velocity.x = 100;
            onGround = false;
        }

        // Physics
        velocity = velocity + gravity * dt;

        position = position + velocity * dt;

        // Ground collision
        if (position.y > 500)
        {
            position.y = 500;
            velocity.y = 0;
            velocity.x = 0;
            onGround = true;
        }
        if(IsKeyPressed(KEY_R))
        {
            trail.clear();
            position = Point(100,500);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawLine(0, 520, 800, 520, WHITE);

        for(const Point& p : trail)
        {
            DrawCircle(p.x, p.y, 2, YELLOW);
        }

        DrawCircle(
            position.x,
            position.y,
            20,
            GREEN
        );

        DrawText(
            TextFormat("Velocity Y: %.2f", velocity.y),
            20,
            20,
            20,
            WHITE
        );

        DrawText(
            TextFormat("Position Y: %.2f", position.y),
            20,
            50,
            20,
            WHITE
        );

        DrawText(
            "SPACE = Jump",
            20,
            80,
            20,
            YELLOW
        );
        DrawText(
            "R = CLEAR",
            20,
            100,
            20,
            PINK
        );
        DrawText(
            TextFormat("Trail Size: %i", trail.size()),
            20,
            150,
            20,
            WHITE
        );

        EndDrawing();
    }

    CloseWindow();
}