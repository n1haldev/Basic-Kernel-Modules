#include <linux/sched/signal.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int my_init(void)
{
    struct task_struct *task;
    printk(KERN_INFO "Listing all processes:\n");
    for_each_process(task) {
        printk(KERN_INFO "PID: %d, Name: %s\n", task->pid, task->comm);
    }
    return 0;
}

static void my_exit(void)
{
    printk(KERN_INFO "Exiting...\n");
}

module_init(my_init);
module_exit(my_exit);
