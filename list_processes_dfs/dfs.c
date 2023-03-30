#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

void dfs(struct task_struct *task) {
	if(task==NULL)
	return;	
	
	struct task_struct *child;
	struct list_head *list;
	
	printk(KERN_INFO "PID: %d  Name: %s\n", task->pid, task->comm);
	
	list_for_each(list, &task->children) {
		child=list_entry(list, struct task_struct, sibling);
		dfs(child);
	}
}

static int dfs_init(void) {
	
	printk(KERN_INFO "Listing all processes in DFS order:\n");
	
	dfs(&init_task);
	
	return 0;
}

static void dfs_exit(void) {
	printk(KERN_INFO "Finished listing all processes in dfs order!");	
}

module_init(dfs_init);
module_exit(dfs_exit);
