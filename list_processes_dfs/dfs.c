#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

void dfs(struct task_struct *task, int indent) {
    struct task_struct *child;
    struct list_head *list;
    int i;

    for (i = 0; i < indent; i++) {
        printk(KERN_CONT "\t");
    }
    printk(KERN_CONT "|--%s[%d]\n", task->comm, task->pid);

    list_for_each(list, &task->children) {
        child = list_entry(list, struct task_struct, sibling);
        dfs(child, indent + 1);
    }
}

static int dfs_init(void) {
	
	printk(KERN_INFO "Listing all processes in DFS order:\n");
	
	dfs(&init_task, 0);
	
	return 0;
}

static void dfs_exit(void) {
	printk(KERN_INFO "Finished listing all processes in dfs order!");	
}

module_init(dfs_init);
module_exit(dfs_exit);
