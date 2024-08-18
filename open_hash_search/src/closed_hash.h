#ifndef ___ClosedHash
#define ___ClosedHash

#include "member.h"

/**
 * @brief 要素の状態
 *
 */
typedef enum { Occupied, Empty, Deleted } Status;

/**
 * @brief 要素
 *
 */
typedef struct {
    Member data;
    Status status;
} Bucket;

/**
 * @brief ハッシュ表
 *
 */
typedef struct {
    int size;
    Bucket* table;
} ClosedHash;

/**
 * @brief ハッシュ表初期化
 *
 * @param h ハッシュ表構造体
 * @param size ハッシュ表サイズ
 * @return int
 */
int initialize(ClosedHash* h, int size);

/**
 * @brief 探索
 *
 * @param h ハッシュ表構造体
 * @param data メンバ構造体
 * @return Bucket*
 */
Bucket* search(const ClosedHash* h, const Member* data);

/**
 * @brief データ追加
 *
 * @param h ハッシュ表構造
 * @param data メンバ構造体
 * @return int
 */
int add(ClosedHash* h, const Member* data);

/**
 * @brief データ削除
 *
 * @param h ハッシュ表構造
 * @param data メンバ構造体
 * @return int
 */
int removed(ClosedHash* h, const Member* data);

/**
 * @brief ハッシュ表をダンプ
 *
 * @param h ハッシュ表構造体
 */
void dump(const ClosedHash* h);

/**
 * @brief 全データ削除
 *
 * @param h ハッシュ表構造体
 */
void clear(ClosedHash* h);

/**
 * @brief ハッシュ表削除
 *
 * @param h ハッシュ表構造体
 */
void terminate(ClosedHash* h);

#endif