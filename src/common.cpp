//
// Created by troy on 12/28/16.
//

#include <common.h>
#include "interpolation/interpolation.h"

RT_QUEUE queue_axis_x, queue_axis_y;
AxisStatus axis_x, axis_y;
AxisStatus ball_x, ball_y;
RT_EVENT event;

void init_global_variables(void) {
    axis_x.position = 0;
    axis_x.velocity = 0;
    strcpy(axis_x.name, "axis_x");

    axis_y.position = 0;
    axis_y.velocity = 0;
    strcpy(axis_y.name, "axis_y");

    ball_x.position = 0;
    ball_x.velocity = 0;
    strcpy(ball_x.name, "ball_x");

    ball_y.position = 0;
    ball_y.velocity = 0;
    strcpy(ball_y.name, "ball_y");

    rt_event_create(&event, "event: command", event_mask::kNone, EV_FIFO);

    rt_queue_create(&queue_axis_x, "axis_x", 64 * sizeof(InterpolationConfigure *), 64, Q_FIFO | Q_SHARED);
    rt_queue_create(&queue_axis_y, "axis_y", 64 * sizeof(InterpolationConfigure *), 64, Q_FIFO | Q_SHARED);
}

void delete_global_variables(void) {
    rt_event_delete(&event);
}
