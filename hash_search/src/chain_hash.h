#ifndef ___ChainHash
#define ___ChainHash

#include "member.h"

/**
 * @brief パケットを表すノード
 *
 */
typedef struct __node {
    Member data;
    struct __node* next;
} Node;

/**
 * @brief ハッシュ表
 *
 */
typedef struct {
    int size;     // ハッシュ表サイズ
    Node** table; // ハッシュ表の先頭要素へのポインタ
} ChainHash;

/**
 * @brief ハッシュ表初期化
 *
 * @param h ハッシュ表構造体
 * @param size ハッシュ表サイズ
 * @return int
 */
int initialize(ChainHash* h, int size);

/**
 * @brief 探索
 *
 * @param h ハッシュ表構造体
 * @param data メンバ構造体
 * @return Node*
 */
Node* search(const ChainHash* h, const Member* data);

/**
 * @brief データ追加
 *
 * @param h ハッシュ表構造体
 * @param data メンバ構造体
 * @return int
 */
int add(ChainHash* h, const Member* data);

/**
 * @brief データ削除
 *
 * @param h ハッシュ表構造体
 * @param data メンバ構造体
 * @return int
 */
int removed(ChainHash* h, const Member* data);

/**
 * @brief ハッシュ表をダンプ
 *
 * @param h ハッシュ表構造体
 */
void dump(const ChainHash* h);

/**
 * @brief 全データ削除
 *
 * @param h ハッシュ表構造体
 */
void clear(ChainHash* h);

/**
 * @brief ハッシュ表削除
 *
 * @param h ハッシュ表構造体
 */
void terminate(ChainHash* h);

#endif