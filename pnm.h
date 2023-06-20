#ifndef __PNM_H__
#define __PNM_H__

#include <stddef.h>
#include <stdint.h>

typedef struct pnm_info_t pnm_info_t;

typedef enum pnm_type_t
{
   PNM_TYPE_ERROR,
   PNM_TYPE_P1=1,
   PNM_TYPE_P2=2,
   PNM_TYPE_P3=3,
   PNM_TYPE_P4=4,
   PNM_TYPE_P5=5,
   PNM_TYPE_P6=6
} pnm_type_t;

extern pnm_info_t* pnm_info_init(void);

extern void pnm_load(const char* f, uint8_t ** data, pnm_info_t* info);

extern void pnm_save(const char* f ,const uint8_t* data, const size_t width, const size_t height, pnm_type_t type);

extern void pnm_probe(const char* f, pnm_info_t* info);

extern int pnm_info_valid(const pnm_info_t* info);

extern size_t pnm_info_width(const pnm_info_t* info);

extern size_t pnm_info_height(const pnm_info_t* info);

extern size_t pnm_info_channel(const pnm_info_t* info);

extern size_t pnm_info_depth(const pnm_info_t* info);

extern size_t pnm_info_maximum(const pnm_info_t* info);

extern pnm_type_t pnm_info_type(const pnm_info_t* info);

extern void pnm_info_destroy(pnm_info_t* info);

#endif // __PNM_H__
