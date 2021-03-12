/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * This is from the Android Project,
 * Repository: https://android.googlesource.com/platform/system/core
 * File: libsparse/sparse_format.h
 * Commit: 28fa5bc347390480fe190294c6c385b6a9f0d68b
 * Copyright (C) 2010 The Android Open Source Project
 */

#ifndef _LIBSPARSE_SPARSE_FORMAT_H_
#define _LIBSPARSE_SPARSE_FORMAT_H_
#include "sparse_defs.h"

typedef struct sparse_header {
	__le32 magic; /* 0xed26ff3a */
	__le16 major_version; /* (0x1) - reject images with higher major versions */
	__le16 minor_version; /* (0x0) - allow images with higer minor versions */
	__le16 file_hdr_sz; /* 28 bytes for first revision of the file format */
	__le16 chunk_hdr_sz; /* 12 bytes for first revision of the file format */
	__le32 blk_sz; /* block size in bytes, must be a multiple of 4 (4096) */
	__le32 total_blks; /* total blocks in the non-sparse output image */
	__le32 total_chunks; /* total chunks in the sparse input image */
	__le32 image_checksum; /* CRC32 checksum of the original data, counting "don't care" */
	/* as 0. Standard 802.3 polynomial, use a Public Domain */
	/* table implementation */
} sparse_header_t;

#define SPARSE_HEADER_MAGIC 0xed26ff3a
#define SPARSE_HEADER_MAJOR_VER 1
#define CHUNK_TYPE_RAW 0xCAC1
#define CHUNK_TYPE_FILL 0xCAC2
#define CHUNK_TYPE_DONT_CARE 0xCAC3
#define CHUNK_TYPE_CRC32 0xCAC4

typedef struct chunk_header {
	__le16 chunk_type; /* 0xCAC1 -> raw; 0xCAC2 -> fill; 0xCAC3 -> don't care */
	__le16 reserved1;
	__le32 chunk_sz; /* in blocks in output image */
	__le32 total_sz; /* in bytes of chunk input file including chunk header and data */
} chunk_header_t;

/* Following a Raw or Fill or CRC32 chunk is data.
 *  For a Raw chunk, it's the data in chunk_sz * blk_sz.
 *  For a Fill chunk, it's 4 bytes of the fill data.
 *  For a CRC32 chunk, it's 4 bytes of CRC32
 */

#endif
