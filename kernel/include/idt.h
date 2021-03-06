#ifndef IDT_H
#define IDT_H

#include <int.h>
#include <screen.h>
#include <pic8259.h>
#include <timer.h>
#include <keyboard.h>
#include <datetime.h>

#define IDT_CODE_SELECTOR (0x8)
// #define IDTR_BASE (0x9000)
#define IDT_ENTRY_COUNT (256)
#define IDT_ENTRY_FLAGS (0x8e)

#define IRQ_BASE (0x20)

typedef struct
    {
    u16 limit;
    u32 base;
} __attribute__((packed)) IDTR;

struct IDT_ENTRY {
    u16 offset_low; // offset 0-15
    u16 segment_selector;
    u8 reserved; // 0
    u8 attr;
    u16 offset_high; // offset 16-31
} __attribute__((packed));

typedef struct IDT_ENTRY idt_entry_t;

struct IDT_EXP_CONTEXT {
    u32 gs, fs, es, ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 isrno, errorno;
    u32 eip, cs, eflags, user_esp, ss;
} __attribute__((packed));

typedef struct IDT_EXP_CONTEXT exp_context_t;

struct IDT_IRQ_CONTEXT {
    u32 gs, fs, es, ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 irqno;
    u32 eip, cs, eflags, user_esp, ss;
} __attribute__((packed));

typedef struct IDT_IRQ_CONTEXT irq_context_t;

void idt_init();

void isr_setup(u8 idt_index, void* callback, u16 selector, u8 attribute);

void _exception_dispatch(exp_context_t* exp_context);

void _irq_dispatch(irq_context_t* irq_context);

extern void exp0_wrapper();
extern void exp1_wrapper();
extern void exp2_wrapper();
extern void exp3_wrapper();
extern void exp4_wrapper();
extern void exp5_wrapper();
extern void exp6_wrapper();
extern void exp7_wrapper();
extern void exp8_wrapper();
extern void exp9_wrapper();
extern void exp10_wrapper();
extern void exp11_wrapper();
extern void exp12_wrapper();
extern void exp13_wrapper();
extern void exp14_wrapper();
extern void exp15_wrapper();
extern void exp16_wrapper();

extern void irq0_wrapper();
extern void irq1_wrapper();
extern void irq2_wrapper();
extern void irq3_wrapper();
extern void irq4_wrapper();
extern void irq5_wrapper();
extern void irq6_wrapper();
extern void irq7_wrapper();
extern void irq8_wrapper();
extern void irq9_wrapper();
extern void irq10_wrapper();
extern void irq11_wrapper();
extern void irq12_wrapper();
extern void irq13_wrapper();
extern void irq14_wrapper();
extern void irq15_wrapper();

#endif