#include <linux/sched/signal.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

char * str_state(unsigned int state) {
    switch(state) {
        case TASK_RUNNING:return "RUNNING";
        break;
        case TASK_INTERRUPTIBLE:return "INTERRUPTIBLE";
        break;
        case TASK_UNINTERRUPTIBLE:return "UNINTERRUPTIBLE";
        break;
        case __TASK_STOPPED:return "STOPPED";
        break;
        case __TASK_TRACED:return "TRACED";
        break;
        case TASK_PARKED:return "PARKED";
        break;
        case TASK_DEAD:return "DEAD";
        break;
        case TASK_WAKEKILL:return "WAKEKILL";
        break;
        case TASK_WAKING:return "WAKING";
        break;
        case TASK_NOLOAD:return "NOLOAD";
        break;
        case TASK_NEW:return "NEW";
        break;
        case TASK_RTLOCK_WAIT:return "RTLOCK_WAIT";
        break;
        case TASK_FREEZABLE:return "FREEZABLE";
        break;
        case TASK_KILLABLE:return "KILLABLE";
        break;
        case TASK_STOPPED:return "STOPPED";
        break;
        case TASK_IDLE:return "IDLE";
        break;
        case TASK_NORMAL:return "NORMAL";
        break;
        case TASK_REPORT:return "REPORT";
        break;
        default:return "NORMAL";
        break;
    }
    return "NORMAL";
}

static int my_init(void)
{
    struct task_struct *task;
    printk(KERN_INFO "Listing all processes:\n");
    for_each_process(task) {
        printk(KERN_INFO "PID: %d, Name: %s State: %s", task->pid, task->comm, str_state(task->__state));
    }
    return 0;
}

static void my_exit(void)
{
    printk(KERN_INFO "Exiting...\n");
}

module_init(my_init);
module_exit(my_exit);
