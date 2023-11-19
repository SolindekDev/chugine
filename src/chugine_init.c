#include <chugine.h>

CHUGINE_RETURN_CODE
chugine_engine_init(int argc, char** argv)
{
    /* Init glut and other important libraries */
    glutInit(&argc, argv);

    return CHUGINE_SUCCESS;
}