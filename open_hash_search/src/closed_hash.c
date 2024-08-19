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

/**
 * @brief ノードにメンバ値を設定
 *
 * @param n 要素構造体
 * @param data メンバ構造体
 * @param status 状態列挙型
 */
static void set_bucket(Bucket* n, const Member* data, Status status) {
    n->data = *data;
    n->status = status;
}

int initialize(ClosedHash* h, int size) {
    if ((h->table = (Bucket*)calloc(size, sizeof(Bucket))) == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;

    for (int i = 0; i < size; i++) {
        h->table[i].status = Empty;
    }

    return 1;
}

Bucket* search(const ClosedHash* h, const Member* data) {
    int key = hash(data->no, h->size);
    Bucket* p = &h->table[key];

    for (int i = 0; p->status != Empty && i < h->size; i++) {
        if (p->status == Occupied && p->data.no == data->no) {
            return p;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }

    return NULL;
}

int add(ClosedHash* h, const Member* data) {
    int key = hash(data->no, h->size);
    Bucket* p = &h->table[key];

    if (search(h, data)) {
        return 1;
    }

    for (int i = 0; i < h->size; i++) {
        if (p->status == Empty || p->status == Deleted) {
            set_bucket(p, data, Occupied);
            return 0;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }

    return 2;
}

int removed(ClosedHash* h, const Member* data) {
    Bucket* p = search(h, data);

    if (p == NULL) {
        return 1;
    }

    p->status = Deleted;

    return 0;
}

void dump(const ClosedHash* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%02d : ", i);

        switch (h->table[i].status) {
        case Occupied:
            printf("%d (%s)\n", h->table[i].data.no, h->table[i].data.name);
            break;
        case Empty:
            printf("-- 未登録 --\n");
            break;
        case Deleted:
            printf("-- 削除済み --\n");
            break;
        }
    }
}

void clear(ClosedHash* h) {
    for (int i = 0; i < h->size; i++) {
        h->table[i].status = Empty;
    }
}

void terminate(ClosedHash* h) {
    clear(h);
    free(h->table);
    h->size = 0;
}