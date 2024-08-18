#include "closed_hash.h"
#include "member.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief ハッシュ関数
 *
 * @param key 鍵
 * @param size サイズ
 * @return int ハッシュ値
 */
static int hash(int key, int size) { return key % size; }

/**
 * @brief 再ハッシュ関数
 *
 * @param key 鍵
 * @param size サイズ
 * @return int ハッシュ値
 */
static int rehash(int key, int size) { return (key + 1) % size; }