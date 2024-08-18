#include "chain_hash.h"
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
 * @brief ノードの各メンバに値を設定
 *
 * @param n ノード構造体
 * @param data メンバ構造体
 * @param next ノード構造体
 */
static void set_node(Node* n, const Member* data, const Node* next) {
    n->data = *data;
    n->next = (Node*)next;
}

int initialize(ChainHash* h, int size) {
    if ((h->table = (Node**)calloc(size, sizeof(Node*))) == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;

    for (int i = 0; i < size; i++) {
        h->table[i] = NULL;
    }

    return 1;
}

Node* search(const ChainHash* h, const Member* data) {
    int key = hash(data->no, h->size);
    Node* p = h->table[key];

    while (p != NULL) {
        if (p->data.no == data->no) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

int add(ChainHash* h, const Member* data) {
    int key = hash(data->no, h->size);
    Node* p = h->table[key];
    Node* tmp;

    while (p != NULL) {
        if (p->data.no == data->no) {
            return 1;
        }
        p = p->next;
    }

    if ((tmp = (Node*)calloc(1, sizeof(Node))) == NULL) {
        return 2;
    }

    set_node(tmp, data, h->table[key]);
    h->table[key] = tmp;

    return 0;
}

int removed(ChainHash* h, const Member* data) {
    int key = hash(data->no, h->size);
    Node* p = h->table[key];
    Node** pp = &h->table[key];

    while (p != NULL) {
        if (p->data.no == data->no) {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }

    return 1;
}

void dump(const ChainHash* h) {
    for (int i = 0; i < h->size; i++) {
        Node* p = h->table[i];
        printf("%02d  ", i);

        while (p != NULL) {
            printf("-> %d (%s)", p->data.no, p->data.name);
            p = p->next;
        }
        putchar('\n');
    }
}

void clear(ChainHash* h) {
    for (int i = 0; i < h->size; i++) {
        Node* p = h->table[i];

        while (p != NULL) {
            Node* next = p->next;
            free(p);
            p = next;
        }
        h->table[i] = NULL;
    }
}

void terminate(ChainHash* h) {
    clear(h);
    free(h->table);
    h->size = 0;
}