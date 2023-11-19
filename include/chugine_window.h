#ifndef _CHUGINE_WINDOW_H
#define _CHUGINE_WINDOW_H

#include <chugine.h>
#include <chugine_vector.h>

#include <stdbool.h>

typedef void (*chugine_display_func)(struct __chugine_window_t* window);

typedef struct __chugine_window_t {
    const char*    window_title;
    chugine_vec2_t window_size;
    chugine_vec2_t window_pos;
    bool           window_fullscreen;

    chugine_display_func* window_display;
} chugine_window_t;


chugine_window_t* chugine_window_create(const char* window_title, chugine_vec2_t size);

CHUGINE_RETURN_CODE chugine_window_set_display_function(chugine_window_t* window, chugine_display_func* display);
CHUGINE_RETURN_CODE chugine_window_fullscreen_state    (chugine_window_t* window, bool state);
CHUGINE_RETURN_CODE chugine_window_set_position        (chugine_window_t* window, chugine_vec2_t pos);
CHUGINE_RETURN_CODE chugine_window_set_size            (chugine_window_t* window, chugine_vec2_t size);
CHUGINE_RETURN_CODE chugine_window_set_in_center       (chugine_window_t* window);
CHUGINE_RETURN_CODE chugine_window_loop                (chugine_window_t* window);

#endif /* _CHUGINE_WINDOW_H */
