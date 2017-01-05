//
// Created by troy on 12/28/16.
//

#ifndef AIR_HOCKEY_GLOBAL_VARIABLES_H
#define AIR_HOCKEY_GLOBAL_VARIABLES_H

#include <native/event.h>
#include <native/queue.h>

typedef struct {
    double position;
    double velocity;
    char name[8];
} AxisStatus;

extern AxisStatus axis_x, axis_y;
extern AxisStatus ball_x, ball_y;

extern RT_EVENT event;
namespace event_mask {
    const unsigned long kNone = 0x0;
    const unsigned long kRequest = 0x01;
    const unsigned long kDone = 0x02;
    const unsigned long kTerminate = 0x04;
    const unsigned long kError = 0x80000000;
    const unsigned long kAny= 0xffffffff;
}

extern RT_QUEUE queue_axis_x, queue_axis_y;



void init_global_variables(void);

void delete_global_variables(void);

#endif //AIR_HOCKEY_GLOBAL_VARIABLES_H
