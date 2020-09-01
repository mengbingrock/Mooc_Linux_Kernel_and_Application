这种机制功能层面上看，进程调度仍然分成两个部分，第一个部分是通过负载均衡模块将各个就绪状态的任务根据负载情况平均分配到各个 CPU 就绪队列上去。第二部分的功能是在各个 CPU 的主调度器（ Main scheduler ）和（周期性调度器） Tick scheduler 的驱动下进行单个 CPU 上的调度。 
调度器处理的任务各不相同，有实时任务（ RT task),普通任务（ normal task ），最后期限任务 (Dead line task）. 但是无论哪一种任务，它们都有共同的逻辑，这部分被抽象成核心调度器层（ Core scheduler layer)
