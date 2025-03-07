#ifndef INSTRUCT_H
#define INSTRUCT_H

#include <stdint.h>

#include "memory.h"

#define FLAG_Z 0x80
#define FLAG_N 0x40
#define FLAG_H 0x20
#define FLAG_C 0x10

void ld(uint8_t *r, uint16_t value);
void ld_r1_r2(void *r1, uint8_t r2, uint8_t size);
void ld_nn(uint16_t *r, uint16_t *pc);
void ld_n(uint8_t *r, uint16_t value);

void add(void *r, uint16_t value, uint8_t size, uint8_t *flags);
void adc(uint8_t *r, uint16_t value, uint8_t *flags);
void sub(uint8_t *r, uint16_t value, uint8_t *flags);
void sbc(uint8_t *r, uint16_t value, uint8_t *flags);

void funcAnd(uint8_t *r, uint16_t value, uint8_t *flags);
void funcOr(uint8_t *r, uint16_t value, uint8_t *flags);
void funcXor(uint8_t *r, uint16_t value, uint8_t *flags);
void funcCp(uint8_t *r, uint16_t value, uint8_t *flags);

void inc(void *n, uint8_t size, uint8_t *flags);
void dec(void *n, uint8_t size, uint8_t *flags);

void swap(void *r, uint8_t size, uint8_t *flags);
void dda(uint8_t *a, uint8_t *flags);
void cpl(uint8_t *a, uint8_t *flags);
void ccf(uint8_t *flags);
void scf(uint8_t *flags);
void nop(void);
void halt(void);
void stop(void);
void di(void);
void ei(void);

void rlc(void *n, uint8_t size, uint8_t *flags);
void rl(void *n, uint8_t size, uint8_t *flags);
void rrc(void *n, uint8_t size, uint8_t *flags);
void rr(void *n, uint8_t size, uint8_t *flags);

void sla(void *n, uint8_t size, uint8_t *flags);
void sra(void *n, uint8_t size, uint8_t *flags);
void srl(void *n, uint8_t size, uint8_t *flags);

void bit(uint8_t b, void *r, uint8_t size, uint8_t *flags);
void set(uint8_t b, void *r, uint8_t size);
void res(uint8_t b, void *r, uint8_t size);

void jp(uint16_t *pc);
void jr(uint16_t *pc);
void jp_hl(uint16_t *pc, uint16_t *hl);

void call(uint16_t *pc, uint16_t *sp);
void rst(uint8_t opcode, uint16_t *pc, uint16_t *sp);
void ret(uint16_t *pc, uint16_t *sp);

#endif /* !INSTRUCT_H */
