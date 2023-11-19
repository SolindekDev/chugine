#include <chugine.h>

chugine_vec2_t
chugine_screen_get_resolution()
{
    int screen_width  = glutGet(GLUT_SCREEN_WIDTH);
    int screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    return CHUGINE_VEC2(screen_width, screen_height);
}

