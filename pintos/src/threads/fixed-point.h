#ifndef FIXED_POINT_H
#define FIXED_POINT_H

/* Sabit noktalı sayı sistemi: 17.14 formatı
   En sağdaki 14 bit = ondalık kısım
   1 = 1 << 14 = 16384 */

#define F (1 << 14)

/* Tam sayıyı fixed-point'e çevir */
#define INT_TO_FP(n)     ((n) * F)

/* Fixed-point'i tam sayıya çevir (aşağı yuvarla) */
#define FP_TO_INT(x)     ((x) / F)

/* Fixed-point'i tam sayıya çevir (en yakına yuvarla) */
#define FP_TO_INT_ROUND(x) ((x) >= 0 ? ((x) + F/2) / F : ((x) - F/2) / F)

/* İki fixed-point topla */
#define FP_ADD(x, y)     ((x) + (y))

/* Fixed-point'ten fixed-point çıkar */
#define FP_SUB(x, y)     ((x) - (y))

/* Fixed-point'e tam sayı ekle */
#define FP_ADD_INT(x, n) ((x) + (n) * F)

/* Fixed-point'ten tam sayı çıkar */
#define FP_SUB_INT(x, n) ((x) - (n) * F)

/* İki fixed-point çarp */
#define FP_MUL(x, y)     ((int64_t)(x) * (y) / F)

/* Fixed-point ile tam sayı çarp */
#define FP_MUL_INT(x, n) ((x) * (n))

/* İki fixed-point böl */
#define FP_DIV(x, y)     ((int64_t)(x) * F / (y))

/* Fixed-point'i tam sayıya böl */
#define FP_DIV_INT(x, n) ((x) / (n))

#endif /* fixed-point.h */