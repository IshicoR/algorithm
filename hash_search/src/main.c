#include "chain_hash.h"
#include "member.h"
#include <stdio.h>

/**
 * @brief メニュー
 *
 */
typedef enum { TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP } Menu;

/**
 * @brief メニュー選択
 *
 * @return Menu
 */
Menu select_menu() {
    int ch;

    while (1) {
        printf("(1)追加 (2)削除 (3)探索 (4)全削除 (5)ダンプ (0)終了 : ");
        scanf("%d", &ch);

        if (ch >= TERMINATE && ch <= DUMP) {
            break;
        }
    }

    return (Menu)ch;
}

int main() {
    Menu menu;
    ChainHash hash;

    if (!(initialize(&hash, 13))) {
        printf("メモリの確保に失敗しました\n");
        return 0;
    }

    while (1) {
        int result;
        Member data;
        Node* tmp;

        switch (menu = select_menu()) {
        case ADD:
            data = scan_member("追加", MEMBER_NO | MEMBER_NAME);
            result = add(&hash, &data);

            if (result) {
                printf("\aエラー : 追加に失敗しました (%s)。\n",
                       (result == 1) ? "登録済み" : "メモリ不足");
            }
            break;
        case DELETE:
            data = scan_member("削除", MEMBER_NO);
            result = removed(&hash, &data);

            if (result == 1) {
                printf("\aエラー : その番号のデータは存在しません。\n");
            }
            break;
        case SEARCH:
            data = scan_member("探索", MEMBER_NO);
            tmp = search(&hash, &data);

            if (tmp == NULL) {
                printf("\a探索に失敗しました。\n");
            } else {
                printf("探索に成功しました : ");
                print_memberln(&tmp->data);
            }
            break;
        case CLEAR:
            clear(&hash);
            break;
        case DUMP:
            dump(&hash);
            break;
        case TERMINATE:
            terminate(&hash);
            return 0;
        }
    }

    return 0;
}