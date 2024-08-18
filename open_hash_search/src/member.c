#include "member.h"
#include <stdio.h>
#include <string.h>

int member_no_cmp(const Member* lhs, const Member* rhs) {
    return lhs->no < rhs->no ? -1 : lhs->no > rhs->no ? 1 : 0;
}

int member_name_cmp(const Member* lhs, const Member* rhs) {
    return strcmp(lhs->name, rhs->name);
}

void print_member(const Member* data) { printf("%d %s", data->no, data->name); }

void print_memberln(const Member* data) {
    printf("%d %s\n", data->no, data->name);
}

Member scan_member(const char* message, int sw) {
    Member member;

    printf("%sするデータを入力してください。\n", message);
    if (sw & MEMBER_NO) {
        printf("番号 : ");
        scanf("%d", &member.no);
    }
    if (sw & MEMBER_NAME) {
        printf("氏名 : ");
        scanf("%s", member.name);
    }

    return member;
}