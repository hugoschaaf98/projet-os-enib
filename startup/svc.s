    
		.syntax unified
		.thumb
		
		.global SVC_Handler
		.global PendSV_Handler

/***************************************************************
 * SVC_Handler
 *  get the svc call number in the svc instruction
 ***************************************************************/
		.section	.text.SVC_Handler
		.type		SVC_Handler, %function
SVC_Handler:
		push		{lr}			// Save the EXC_RETURN code
		tst			lr, #4			// if lr[2]==0
		mrseq		r2, msp			//   svc was called from handler mode, 
									//     so the context is on msp stack
		addeq		r2, #4			// update msp because of the push
		mrsne		r2, psp			//   svc was called from thread mode, 
		ldr			r0, [r2, #24]	// get stacked PC from the stack frame
		ldrb		r0, [r0, #-2]	// get SVC_NUMBER by reading the LSB
									//   of the svc instruction code
		mov			r1, r2			// make r1 point to the parameter list
		push		{r2}			// remember the stack used (r2)
		bl			svc_dispatch	// process svc according to SVC_NUMBER
		pop			{r2}			// write the result (r0) to the stack
		str			r0, [r2]		//   used when svc was called
		pop			{pc}			// back the svc caller
		.size		SVC_Handler, .-SVC_Handler

/***************************************************************
 * PendSV_Handler
 *  make the context switching
 ***************************************************************/
		.section	.text.PendSV_Handler
		.type		PendSV_Handler, %function
PendSV_Handler:
		cpsid		i					// disable IRQ handling
		ldr			r1, =tsk_prev
		ldr			r0, [r1]			// get tsk_prev
		mov			r2, #0
		str			r2, [r1]			//  and reset it
		cpsie		i					// enable IRQ handling
		ldr			r2, =tsk_running	// 
		ldr			r2, [r2]			// get tsk_running
		cmp			r0, r2				// if tsk_prev==tsk_running
		bxeq		lr					//   exit
		cmp			r0, #0				// if tsk_prev != NULL
		beq			1f					//   save ctx:
		mrs			r1, psp				//     get psp
		stmdb		r1!, {r4-r11}		//     save ctx on psp stack
		mrs			r3, control			//     save control register
		stmdb		r1!, {r3,lr}		//      and EXC_RETURN to the stack
		str			r1, [r0, #16]		//     store sp in Task struct
1:		ldr			r1, [r2, #16]		// get sp and restore ctx
		ldmia		r1!, {r3,lr}		//     get back EXC_RETURN and control
		ldmia		r1!, {r4-r11}		//     reload ctx in registers
		msr			psp, r1				//     set psp
		ldr			r1, [r2, #20]		//
		msr			psplim, r1			//     set psplim
		msr			control, r3			//     set control
		bx			lr 
		.size		PendSV_Handler, .-PendSV_Handler
