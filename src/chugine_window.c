#include <chugine.h>

/* Useful resource: 
 *  - https://www.opengl.org/resources/libraries/glut/spec3/node15.html */

chugine_window_t* 
chugine_window_create(const char* window_title, chugine_vec2_t size)
{
    if (size.x == 0 || size.y == 0) CHUGINE_ERROR(NULL, "size.x/size.y == 0. Incorrect window size");
    if (window_title == NULL)       CHUGINE_ERROR(NULL, "window_title=NULL. Incorrect window title");

    /* We want a RGBA display with double buffering 
     *  - GLUT_DOUBLE - Double buffering 
     *  - GLUT_RGBA - Red, Green, Blue, Alpha pixel color */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    chugine_window_t* window = calloc(1, sizeof(chugine_window_t));
    window->window_title     = window_title;

    chugine_window_set_size(window, size);
    chugine_window_set_in_center(window);
    glutCreateWindow(window->window_title);

    return window;
}

CHUGINE_RETURN_CODE
chugine_window_set_display_function(chugine_window_t* window, chugine_display_func* display)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    window->window_display = display;
    glutDisplayFunc(window->window_display);

    return CHUGINE_SUCCESS;
}

CHUGINE_RETURN_CODE
chugine_window_loop(chugine_window_t* window)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    glutMainLoop();
    return CHUGINE_SUCCESS;
}

CHUGINE_RETURN_CODE 
chugine_window_set_in_center(chugine_window_t* window)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    /* Very simple function, just get screen resolution and 
     * then calculate the window position */
    chugine_vec2_t screen_resolution = chugine_screen_get_resolution();
    window->window_pos = CHUGINE_VEC2(screen_resolution.x / 2 - window->window_size.x / 2,
                                      screen_resolution.y / 2 - window->window_size.y / 2);

    return CHUGINE_SUCCESS;
}

CHUGINE_RETURN_CODE 
chugine_window_fullscreen_state(chugine_window_t* window, bool state)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    /* FIXME: Glut specifications says that glutFullScreen is very limited
     *        function and doesn't work like a proper fullscreen. We need
     *        to implement it on our own */

    /* https://www.opengl.org/resources/libraries/glut/spec3/node24.html */
    window->window_fullscreen = !window->window_fullscreen;
    glutFullScreen();

    return CHUGINE_SUCCESS;
}

CHUGINE_RETURN_CODE 
chugine_window_set_position(chugine_window_t* window, chugine_vec2_t pos)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    /* glutInitWindowPosition is used when the window is 
     * not created yet. glutPositionWindow is used when
     * the window is created and we are in the window loop */
    if (window->window_pos.x == 0 && window->window_pos.y == 0)
        glutInitWindowPosition(pos.x, pos.y);
    else 
        glutPositionWindow(pos.x, pos.y);

    window->window_pos = pos;
    return CHUGINE_SUCCESS;
}

CHUGINE_RETURN_CODE 
chugine_window_set_size(chugine_window_t* window, chugine_vec2_t size)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    /* glutInitWindowSize is used when the window is 
     * not created yet. glutReshapeWindow is used when
     * the window is created and we are in the window loop */
    if (window->window_size.x == 0 && window->window_size.y == 0)
        glutInitWindowSize(size.x, size.y);
    else 
        glutReshapeWindow(size.x, size.y);

    window->window_size = size;
    return CHUGINE_SUCCESS;
}

int
chugine_window_get_uptime(chugine_window_t* window)
{
    if (window == NULL) CHUGINE_ERROR(CHUGINE_FAILURE, "window is null. Incorrect pointer");

    return glutGet(GLUT_ELAPSED_TIME);
}