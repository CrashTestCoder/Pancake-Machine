#ifndef __GLOBAL_VARIABLES__
#define __GLOBAL_VARIABLES__

#include "Flipper.hpp"
#include "Mixer.hpp"

extern Mixer mixer;
extern Flipper flipper;
extern int fd;

extern void setFD(int);

#endif /* __GLOBAL_VARIABLES__ */
