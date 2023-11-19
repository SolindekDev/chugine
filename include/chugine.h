#ifndef _CHUGINE_H
#define _CHUGINE_H

#include <chugine_init.h>
#include <chugine_window.h>
#include <chugine_vector.h>
#include <chugine_screen.h>

#define GL_SILENCE_DEPRECATION

/* Since MacOS have glut already installed it's 
 * in a different include path than on Windows 
 * or Unix-like systems */
#if defined __APPLE__ || defined TARGET_OS_MAC
    #include <GLUT/glut.h>
    #include <OpenGL/OpenGL.h>
#else
    #include <GL/glut.h>
#endif 

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define CHUGINE_ERROR(return_value, msg) ({                           \
    printf("[\e[42mCHUGINE\e[0;0m] [\e[41mERROR\e[0;0m]: %s", msg);   \
    return return_value;                                              \
})

typedef unsigned char CHUGINE_RETURN_CODE;

#define CHUGINE_SUCCESS 1
#define CHUGINE_FAILURE 0

#endif /* _CHUGINE_H */
