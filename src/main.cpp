//
// Created by troy on 12/28/16.
//

#include <sys/mman.h>
#include <signal.h>

#include <rtdk.h>
#include <native/task.h>

#include <common.h>
#include <tasks/all_tasks.h>

namespace AirHockey {
    RT_TASK rttask_trajectory_generator_x;
    RT_TASK rttask_trajectory_generator_y;
    RT_TASK rttask_strategy;
    RT_TASK rttask_physics_engine;

    void task_init(void) {
        rt_task_create(&rttask_trajectory_generator_x,
                       "trajectory generator x",
                       0, 95, T_JOINABLE);
        rt_task_create(&rttask_trajectory_generator_y,
                       "trajectory generator y",
                       0, 95, T_JOINABLE);
        rt_task_create(&rttask_strategy,
                       "strategy",
                       0, 93, T_JOINABLE);
        rt_task_create(&rttask_physics_engine,
                       "physics_engine",
                       0, 94, T_JOINABLE);
    }

    void task_start(void) {
        rt_task_start(&rttask_trajectory_generator_x, &task_trajectory_generator::main, (void *) &axis_x);
        rt_task_start(&rttask_trajectory_generator_y, &task_trajectory_generator::main, (void *) &axis_y);
        rt_task_start(&rttask_strategy, &task_strategy::main, NULL);
        rt_task_start(&rttask_physics_engine, &task_physics_engine::main, NULL);
    }

    void task_join(void) {
        rt_task_join(&rttask_trajectory_generator_x);
        rt_task_join(&rttask_trajectory_generator_y);
        rt_task_join(&rttask_strategy);
        rt_task_join(&rttask_physics_engine);
    }

    void task_delete(void) {
        rt_task_delete(&rttask_trajectory_generator_x);
        rt_task_delete(&rttask_trajectory_generator_y);
        rt_task_delete(&rttask_strategy);
        rt_task_delete(&rttask_physics_engine);
    }
}

void terminate_signal_handler(int n) {
    rt_printf("[main] catch signal: %d\n", n);
    rt_event_signal(&event, event_mask::kTerminate);
}

int main(int argc, char **argv) {
    using namespace AirHockey;

    mlockall(MCL_CURRENT | MCL_FUTURE);
    rt_print_auto_init(1);

    rt_printf("[main] init global variables\n");
    init_global_variables();

    signal(SIGINT, terminate_signal_handler);
    signal(SIGTERM, terminate_signal_handler);

    rt_printf("[main] init tasks\n");
    task_init();

    rt_printf("[main] start tasks\n");
    task_start();

    rt_printf("[main] running\n");
    task_join();

    rt_printf("[main] all tasks ended\n");
    task_delete();

    rt_printf("[main] delete global variables\n");
    delete_global_variables();
}
