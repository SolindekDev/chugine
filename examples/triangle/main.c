#include <chugine.h>

void
display_func(chugine_window_t* window)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
        glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
        glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
    glEnd();

    glFlush();
}

int
main(int argc, char** argv)
{
    chugine_engine_init(argc, argv);
    chugine_window_t* window = chugine_window_create("Example window", CHUGINE_VEC2(1280, 720));

    chugine_vec2_t screen_resolution = chugine_screen_get_resolution();
    printf("screen_resolution.x=%ld, screen_resolution.y=%ld\n", screen_resolution.x, screen_resolution.y);

    chugine_window_set_display_function(window, display_func);
    chugine_window_loop(window);
}