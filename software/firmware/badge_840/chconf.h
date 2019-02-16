/*
    Copyright (C) 2016 Stephane D'Alu

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    templates/chconf.h
 * @brief   Configuration file template.
 * @details A copy of this file must be placed in each project directory, it
 *          contains the application specific kernel settings.
 *
 * @addtogroup config
 * @details Kernel related settings and hooks.
 * @{
 */

#ifndef _CHCONF_H_
#define _CHCONF_H_

#define _CHIBIOS_RT_CONF_
#define _CHIBIOS_RT_CONF_VER_5_0_
#define _CHIBIOS_RT_CONF_VER_5_1_

/*
 * Disable advanced kernel mode so that ChibiOS doesn't use the
 * SVC vector. This is used to make API calls to the SoftDevice.
 */

/*
 * ChibiOS supports two context switching mode on Cortex-M4: 'compact' mode
 * and 'advanced' mode. In compact mode, thread context switches are
 * requested using a PendSV trap. In advanced mode, the SVCall trap is
 * used instead.
 *
 * One major difference between the two approaches is that issuing a PendSV
 * can only be done by accessing a register in the System Control Block
 * (SCB), which is a privileged operation. That is, you can only access
 * the SCB (along with the NVIC and generic timer) in the following
 * conditions:
 *
 * - The CPU is executing in an exception handler
 * - The CPU is executing in a thread, and bit 0 of the CONTROL
 *   register is cleared
 *
 * Setting bit 0 of the CONTROL register is useful in cases where we want
 * to limit the access rights of threads for security purposes. Whether
 * this is useful or not in an RTOS context where there is only one shared
 * address space depends on the circumstances.
 *
 * Ideally we should be able to use either mode, and for the most part we
 * _except_ when the Nordic SoftDevice is enabled.
 *
 * In order to use the SVCall handler, the rule is that the current CPU
 * priority (as specified in the basepri register) must be less than the
 * SVC handler priority as specified in System Handler Priority Register 2
 * (SHPR2). If the current thread's priority is higher than the SVC handler
 * priority, executing the 'svc' instruction triggers a hard fault.
 *
 * Normally, when using advenced kernel mode, the basepri value is 0.
 * When a context switch is performed, ChibiOS changes this to the
 * CORTEX_BASEPRI_KERNEL value, 0x40, which is supposed to be higher
 * priority than all interrupt handlers except for SVCALL. This is
 * intended to prevent the context switch code from being preempted.
 * During startup, ChibiOS sets the priority of the SVCALL handler by
 * writing 0x20 to the SHPR2 register in the system control block (SCB);
 *
 * The problem is, when sd_softdevice_enable() is called, the SoftDevice
 * code changes the SHPR2 value to 0x80. The SoftDevice also makes use of
 * system calls, however it allows application code to use them as well, 
 * with certain restrictions (the system call number must be between 0x0
 * and 0xF). But with the higher SHPR2 value, the ChibiOS context switch
 * code will now execute at a higher priority than the SVCALL handler,
 * and now we'll get a trap when we try to execute an svc instruction.
 *
 * Fortunately, we can adjust the ChibiOS SVCall priority value to
 * compensate for this. If advanced mode is enabled, we change the SVCall
 * priority to 4 (normally it's 2), so that the rule is once again
 * obeyed.
 *
 * Unfortunately, there's still one more problem: the SoftDevice
 * programs the radio interrupt with the highest priority of all, which
 * allows it to preempt ChibiOS context switch code. Technically, as
 * long as we have enough stack space we can accomodate this, but I'm
 * not comfortable with the ChibiOS context switch code potentially
 * being slowed down like that at arbitrary times, so for now we're
 * going to stick with compact kernel mode, which masks off all
 * interrupts during a context switch.
 */

/* Force the SVCALL priority to match the SoftDevice. */

#define CORTEX_PRIORITY_SVCALL 4

/* Force compact kernel mode. */

#define CORTEX_SIMPLIFIED_PRIORITY TRUE

/*
 * We would like the idle thread to put the CPU to sleep during idle
 * periods instead of busy-waiting. This saves power.
 */

#define CORTEX_ENABLE_WFI_IDLE TRUE

/*
 * Don't remap the interrupt vector table. The SoftDevice greedily wants
 * to filter all interrupts.
 */

#define CRT0_VTOR_INIT FALSE

/*===========================================================================*/
/**
 * @name System timers settings
 * @{
 */
/*===========================================================================*/

/**
 * @brief   System time counter resolution.
 * @note    Allowed values are 16 or 32 bits.
 */
#define CH_CFG_ST_RESOLUTION                32

/**
 * @brief   System tick frequency.
 * @details Frequency of the system timer that drives the system ticks. This
 *          setting also defines the system tick time unit.
 */
#define CH_CFG_ST_FREQUENCY                 1000

/**
 * @brief   Time delta constant for the tick-less mode.
 * @note    If this value is zero then the system uses the classic
 *          periodic tick. This value represents the minimum number
 *          of ticks that is safe to specify in a timeout directive.
 *          The value one is not valid, timeouts are rounded up to
 *          this value.
 */
#define CH_CFG_ST_TIMEDELTA                 2

/**
 * @brief   Time intervals data size.
 * @note    Allowed values are 16, 32 or 64 bits.
 */
#define CH_CFG_INTERVALS_SIZE               32

/**
 * @brief   Time types data size.
 * @note    Allowed values are 16 or 32 bits.
 */
#define CH_CFG_TIME_TYPES_SIZE              32

/** @} */

/*===========================================================================*/
/**
 * @name Kernel parameters and options
 * @{
 */
/*===========================================================================*/

/**
 * @brief   Round robin interval.
 * @details This constant is the number of system ticks allowed for the
 *          threads before preemption occurs. Setting this value to zero
 *          disables the preemption for threads with equal priority and the
 *          round robin becomes cooperative. Note that higher priority
 *          threads can still preempt, the kernel is always preemptive.
 * @note    Disabling the round robin preemption makes the kernel more compact
 *          and generally faster.
 * @note    The round robin preemption is not supported in tickless mode and
 *          must be set to zero in that case.
 */
#define CH_CFG_TIME_QUANTUM                 0

/**
 * @brief   Managed RAM size.
 * @details Size of the RAM area to be managed by the OS. If set to zero
 *          then the whole available RAM is used. The core memory is made
 *          available to the heap allocator and/or can be used directly through
 *          the simplified core memory allocator.
 *
 * @note    In order to let the OS manage the whole RAM the linker script must
 *          provide the @p __heap_base__ and @p __heap_end__ symbols.
 * @note    Requires @p CH_CFG_USE_MEMCORE.
 */
#define CH_CFG_MEMCORE_SIZE                 0

/**
 * @brief   Idle thread automatic spawn suppression.
 * @details When this option is activated the function @p chSysInit()
 *          does not spawn the idle thread. The application @p main()
 *          function becomes the idle thread and must implement an
 *          infinite loop.
 */
#define CH_CFG_NO_IDLE_THREAD               FALSE

/** @} */

/*===========================================================================*/
/**
 * @name Performance options
 * @{
 */
/*===========================================================================*/

/**
 * @brief   OS optimization.
 * @details If enabled then time efficient rather than space efficient code
 *          is used when two possible implementations exist.
 *
 * @note    This is not related to the compiler optimization options.
 * @note    The default is @p TRUE.
 */
#define CH_CFG_OPTIMIZE_SPEED               TRUE

/** @} */

/*===========================================================================*/
/**
 * @name Subsystem options
 * @{
 */
/*===========================================================================*/

/* This group of definitions is new for ChibiOS kernel 5.x.x */

#define CH_CFG_USE_OBJ_FIFOS FALSE
#define CH_CFG_USE_FACTORY FALSE
#define CH_CFG_FACTORY_MAX_NAMES_LENGTH     0
#define CH_CFG_FACTORY_OBJECTS_REGISTRY     FALSE
#define CH_CFG_FACTORY_GENERIC_BUFFERS      FALSE
#define CH_CFG_FACTORY_SEMAPHORES           FALSE
#define CH_CFG_FACTORY_MAILBOXES            FALSE
#define CH_CFG_FACTORY_OBJ_FIFOS            FALSE

#define CH_CFG_SYSTEM_EXTRA_FIELDS
#define CH_CFG_SYSTEM_INIT_HOOK(tp) {                                       \
  /* Add threads initialization code here.*/                                \
}

/**
 * @brief   Time Measurement APIs.
 * @details If enabled then the time measurement APIs are included in
 *          the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_TM                       FALSE

/**
 * @brief   Threads registry APIs.
 * @details If enabled then the registry APIs are included in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_REGISTRY                 TRUE

/**
 * @brief   Threads synchronization APIs.
 * @details If enabled then the @p chThdWait() function is included in
 *          the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_WAITEXIT                 TRUE

/**
 * @brief   Semaphores APIs.
 * @details If enabled then the Semaphores APIs are included in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_SEMAPHORES               TRUE

/**
 * @brief   Semaphores queuing mode.
 * @details If enabled then the threads are enqueued on semaphores by
 *          priority rather than in FIFO order.
 *
 * @note    The default is @p FALSE. Enable this if you have special
 *          requirements.
 * @note    Requires @p CH_CFG_USE_SEMAPHORES.
 */
#define CH_CFG_USE_SEMAPHORES_PRIORITY      FALSE

/**
 * @brief   Mutexes APIs.
 * @details If enabled then the mutexes APIs are included in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_MUTEXES                  TRUE

/**
 * @brief   Enables recursive behavior on mutexes.
 * @note    Recursive mutexes are heavier and have an increased
 *          memory footprint.
 *
 * @note    The default is @p FALSE.
 * @note    Requires @p CH_CFG_USE_MUTEXES.
 */
#define CH_CFG_USE_MUTEXES_RECURSIVE        FALSE

/**
 * @brief   Conditional Variables APIs.
 * @details If enabled then the conditional variables APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_MUTEXES.
 */
#define CH_CFG_USE_CONDVARS                 FALSE

/**
 * @brief   Conditional Variables APIs with timeout.
 * @details If enabled then the conditional variables APIs with timeout
 *          specification are included in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_CONDVARS.
 */
#define CH_CFG_USE_CONDVARS_TIMEOUT         TRUE

/**
 * @brief   Events Flags APIs.
 * @details If enabled then the event flags APIs are included in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_EVENTS                   TRUE

/**
 * @brief   Events Flags APIs with timeout.
 * @details If enabled then the events APIs with timeout specification
 *          are included in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_EVENTS.
 */
#define CH_CFG_USE_EVENTS_TIMEOUT           TRUE

/**
 * @brief   Synchronous Messages APIs.
 * @details If enabled then the synchronous messages APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_MESSAGES                 TRUE

/**
 * @brief   Synchronous Messages queuing mode.
 * @details If enabled then messages are served by priority rather than in
 *          FIFO order.
 *
 * @note    The default is @p FALSE. Enable this if you have special
 *          requirements.
 * @note    Requires @p CH_CFG_USE_MESSAGES.
 */
#define CH_CFG_USE_MESSAGES_PRIORITY        FALSE

/**
 * @brief   Mailboxes APIs.
 * @details If enabled then the asynchronous messages (mailboxes) APIs are
 *          included in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_SEMAPHORES.
 */
#define CH_CFG_USE_MAILBOXES                FALSE

/**
 * @brief   I/O Queues APIs.
 * @details If enabled then the I/O queues APIs are included in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_QUEUES                   TRUE

/**
 * @brief   Core Memory Manager APIs.
 * @details If enabled then the core memory manager APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_MEMCORE                  TRUE

/**
 * @brief   Heap Allocator APIs.
 * @details If enabled then the memory heap allocator APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_MEMCORE and either @p CH_CFG_USE_MUTEXES or
 *          @p CH_CFG_USE_SEMAPHORES.
 * @note    Mutexes are recommended.
 */
#define CH_CFG_USE_HEAP                     TRUE

/**
 * @brief   Memory Pools Allocator APIs.
 * @details If enabled then the memory pools allocator APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 */
#define CH_CFG_USE_MEMPOOLS                 TRUE

/**
 * @brief   Dynamic Threads APIs.
 * @details If enabled then the dynamic threads creation APIs are included
 *          in the kernel.
 *
 * @note    The default is @p TRUE.
 * @note    Requires @p CH_CFG_USE_WAITEXIT.
 * @note    Requires @p CH_CFG_USE_HEAP and/or @p CH_CFG_USE_MEMPOOLS.
 */
#define CH_CFG_USE_DYNAMIC                  TRUE

/** @} */

/*===========================================================================*/
/**
 * @name Debug options
 * @{
 */
/*===========================================================================*/

/**
 * @brief   Debug option, kernel statistics.
 *
 * @note    The default is @p FALSE.
 */
#define CH_DBG_STATISTICS                   FALSE

/**
 * @brief   Debug option, system state check.
 * @details If enabled the correct call protocol for system APIs is checked
 *          at runtime.
 *
 * @note    The default is @p FALSE.
 */
#define CH_DBG_SYSTEM_STATE_CHECK           FALSE

/**
 * @brief   Debug option, parameters checks.
 * @details If enabled then the checks on the API functions input
 *          parameters are activated.
 *
 * @note    The default is @p FALSE.
 */
#define CH_DBG_ENABLE_CHECKS                FALSE

/**
 * @brief   Debug option, consistency checks.
 * @details If enabled then all the assertions in the kernel code are
 *          activated. This includes consistency checks inside the kernel,
 *          runtime anomalies and port-defined checks.
 *
 * @note    The default is @p FALSE.
 */
#define CH_DBG_ENABLE_ASSERTS               FALSE

/**
 * @brief   Debug option, trace buffer.
 * @details If enabled then the context switch circular trace buffer is
 *          activated.
 *
 * @note    The default is @p CH_DBG_TRACE_MASK_NONE.
 */
#define CH_DBG_TRACE_MASK                   CH_DBG_TRACE_MASK_DISABLED

/**
 * @brief   Trace buffer entries.
 * @note    The trace buffer is only allocated if @p CH_DBG_TRACE_MASK is
 *          different from @p CH_DBG_TRACE_MASK_NONE.
 */
#define CH_DBG_TRACE_BUFFER_SIZE            128

/**
 * @brief   Debug option, stack checks.
 * @details If enabled then a runtime stack check is performed.
 *
 * @note    The default is @p FALSE.
 * @note    The stack check is performed in a architecture/port dependent way.
 *          It may not be implemented or some ports.
 * @note    The default failure mode is to halt the system with the global
 *          @p panic_msg variable set to @p NULL.
 */
#define CH_DBG_ENABLE_STACK_CHECK           TRUE

/* Since we have an MPU, we can enable this too. */

#define PORT_ENABLE_GUARD_PAGES             TRUE

/**
 * @brief   Debug option, stacks initialization.
 * @details If enabled then the threads working area is filled with a byte
 *          value when a thread is created. This can be useful for the
 *          runtime measurement of the used stack.
 *
 * @note    The default is @p FALSE.
 */
#define CH_DBG_FILL_THREADS                 FALSE

/**
 * @brief   Debug option, threads profiling.
 * @details If enabled then a field is added to the @p thread_t structure that
 *          counts the system ticks occurred while executing the thread.
 *
 * @note    The default is @p FALSE.
 * @note    This debug option is not currently compatible with the
 *          tickless mode.
 */
#define CH_DBG_THREADS_PROFILING            FALSE

/** @} */

/*===========================================================================*/
/**
 * @name Kernel hooks
 * @{
 */
/*===========================================================================*/

/**
 * @brief   Threads descriptor structure extension.
 * @details User fields added to the end of the @p thread_t structure.
 */
#define CH_CFG_THREAD_EXTRA_FIELDS                                          \
  /* Add threads custom fields here.*/

/**
 * @brief   Threads initialization hook.
 * @details User initialization code added to the @p chThdInit() API.
 *
 * @note    It is invoked from within @p chThdInit() and implicitly from all
 *          the threads creation APIs.
 */
#define CH_CFG_THREAD_INIT_HOOK(tp) {                                       \
  /* Add threads initialization code here.*/                                \
}

/**
 * @brief   Threads finalization hook.
 * @details User finalization code added to the @p chThdExit() API.
 */
#define CH_CFG_THREAD_EXIT_HOOK(tp) {                                       \
  /* Add threads finalization code here.*/                                  \
}

/**
 * @brief   Context switch hook.
 * @details This hook is invoked just before switching between threads.
 */
#define CH_CFG_CONTEXT_SWITCH_HOOK(ntp, otp) {                              \
	/* Context switch code here.*/					\
}

/**
 * @brief   ISR enter hook.
 */
#define CH_CFG_IRQ_PROLOGUE_HOOK() {                                        \
  /* IRQ prologue code here.*/                                              \
}

/**
 * @brief   ISR exit hook.
 */
#define CH_CFG_IRQ_EPILOGUE_HOOK() {                                        \
  /* IRQ epilogue code here.*/                                              \
}

/**
 * @brief   Idle thread enter hook.
 * @note    This hook is invoked within a critical zone, no OS functions
 *          should be invoked from here.
 * @note    This macro can be used to activate a power saving mode.
 */
#define CH_CFG_IDLE_ENTER_HOOK() {                                          \
  /* Idle-enter code here.*/                                                \
}

/**
 * @brief   Idle thread leave hook.
 * @note    This hook is invoked within a critical zone, no OS functions
 *          should be invoked from here.
 * @note    This macro can be used to deactivate a power saving mode.
 */
#define CH_CFG_IDLE_LEAVE_HOOK() {                                          \
  /* Idle-leave code here.*/                                                \
}

/**
 * @brief   Idle Loop hook.
 * @details This hook is continuously invoked by the idle thread loop.
 */
#define CH_CFG_IDLE_LOOP_HOOK() {                                           \
  /* Idle loop code here.*/                                                 \
}

/**
 * @brief   System tick event hook.
 * @details This hook is invoked in the system tick handler immediately
 *          after processing the virtual timers queue.
 */
#define CH_CFG_SYSTEM_TICK_HOOK() {                                         \
  /* System tick event code here.*/                                         \
}

/**
 * @brief   System halt hook.
 * @details This hook is invoked in case to a system halting error before
 *          the system is halted.
 */
#define CH_CFG_SYSTEM_HALT_HOOK(reason) {                                   \
  /* System halt code here.*/                                               \
}

/**
 * @brief   Trace hook.
 * @details This hook is invoked each time a new record is written in the
 *          trace buffer.
 */
#define CH_CFG_TRACE_HOOK(tep) {                                            \
  /* Trace code here.*/                                                     \
}

/** @} */

/*===========================================================================*/
/* Port-specific settings (override port settings defaulted in chcore.h).    */
/*===========================================================================*/

#endif  /* _CHCONF_H_ */

/** @} */
