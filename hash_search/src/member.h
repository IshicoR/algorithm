#ifndef ___Member
#define ___Member

/**
 * @brief 会員データ
 *
 */
typedef struct {
    int no;
    char name[20];
} Member;

/**
 * @brief メンバ定数値
 *
 */
#define MEMBER_NO 1
#define MEMBER_NAME 2

/**
 * @brief 会員番号の比較関数
 *
 * @param lhs 比較元メンバ構造体
 * @param rhs 比較先メンバ構造体
 * @return int
 */
int member_no_cmp(const Member* lhs, const Member* rhs);

/**
 * @brief 会員名の比較関数
 *
 * @param lhs 比較元メンバ構造体
 * @param rhs 比較先メンバ構造体
 * @return int
 */
int member_name_cmp(const Member* lhs, const Member* rhs);

/**
 * @brief 会員データの表示
 *
 * @param data メンバ構造体
 */
void print_member(const Member* data);

/**
 * @brief 会員データを改行表示
 *
 * @param data メンバ構造体
 */
void print_memberln(const Member* data);

/**
 * @brief 会員データの読み込み
 *
 * @param message
 * @param sw
 * @return Member
 */
Member scan_member(const char* message, int sw);

#endif