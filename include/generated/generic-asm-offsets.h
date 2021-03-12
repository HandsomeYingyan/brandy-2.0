#ifndef __GENERIC_ASM_OFFSETS_H__
#define __GENERIC_ASM_OFFSETS_H__
/*
 * DO NOT MODIFY.
 *
 * This file was generated by Kbuild
 */

#define GENERATED_GBL_DATA_SIZE 320 /* (sizeof(struct global_data) + 15) & ~15	@ */
#define GENERATED_BD_INFO_SIZE 80 /* (sizeof(struct bd_info) + 15) & ~15	@ */
#define GD_SIZE 320 /* sizeof(struct global_data)	@ */
#define GD_BD 0 /* offsetof(struct global_data, bd)	@ */
#define GD_RELOCADDR 56 /* offsetof(struct global_data, relocaddr)	@ */
#define GD_RELOC_OFF 76 /* offsetof(struct global_data, reloc_off)	@ */
#define GD_START_ADDR_SP 72 /* offsetof(struct global_data, start_addr_sp)	@ */
#define GD_NEW_GD 80 /* offsetof(struct global_data, new_gd)	@ */

#endif
