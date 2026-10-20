#include "raylib.h"
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 650
#define PARTICLE_COUNT 100

// Particle rng parameters

#define MIN_V_X -100
#define MAX_V_X 100

#define MIN_V_Y -100
#define MAX_V_Y 100

#define MIN_RADIUS 5
#define MAX_RADIUS 15

// Defining the struct for a particle

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
    float radius;
} Particle;

int main(void) {

    // Creates the graphical window
    InitWindow(WIDTH, HEIGHT, "Particle Garden");
    // Sets a target of 60fps
    SetTargetFPS(60);

    Particle particles[PARTICLE_COUNT];
    for (int i = 0; i < PARTICLE_COUNT; i++) {
        particles[i].x = GetRandomValue(MAX_RADIUS, WIDTH - MAX_RADIUS);
        particles[i].y = GetRandomValue(MAX_RADIUS, HEIGHT - MAX_RADIUS);
        particles[i].vx = GetRandomValue(MIN_V_X, MAX_V_X);
        particles[i].vy = GetRandomValue(MIN_V_Y, MAX_V_Y);
        particles[i].radius = GetRandomValue(MIN_RADIUS, MAX_RADIUS);
    }

    // Checks for a close request (like Esc)
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        for (int i = 0; i < PARTICLE_COUNT; i++) {
            Particle *p = &particles[i];
            // Update particle i
            // Update particle position
            p->x += dt * p->vx;
            p->y += dt * p->vy;

            // Check for wall collisions
            if (p->x + p->radius >= WIDTH) {
                p->x = WIDTH - p->radius;
                p->vx *= -1;
            }
            if (p->x - p->radius <= 0) {
                p->x = 0 + p->radius;
                p->vx *= -1;
            }
            if (p->y + p->radius >= HEIGHT) {
                p->y = HEIGHT - p->radius;
                p->vy *= -1;
            }
            if (p->y - p->radius <= 0) {
                p->y = 0 + p->radius;
                p->vy *= -1;
            }
        }

        BeginDrawing();
        ClearBackground((Color){8, 12, 24, 255});

        for (int i = 0; i < PARTICLE_COUNT; i++) {
            Particle *p = &particles[i];
            // Draw particle i
            DrawCircleV((Vector2){p->x, p->y}, p->radius, SKYBLUE);
        }

        EndDrawing();
    }
    // Releases the window resources
    CloseWindow();
    return 0;
}
