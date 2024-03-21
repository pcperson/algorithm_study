#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 5
#define LENGTH (100 + 1)


int main() {

    char table[HASH_SIZE][LENGTH];
    char moji[5] = "abc";


    for (int x = 0; x < HASH_SIZE; x++) {
        memset(table[x], '\0', LENGTH * sizeof(char));

    }

    // 文字列"abc"を登録する
    int ret = make(table, HASH_SIZE, moji);

    printf("登録結果 = %d", ret);


    // 文字列"abc"を検索する
    int search_ret = search(table, HASH_SIZE, moji);

    printf("検索結果 = %d", search_ret);

    return 0;

}


/**
 * @brief  hash  ハッシュ関数を計算する
 *
 * @param string    文字列
 * @param size      文字列のサイズ
 * @return int      計算されたハッシュ値
 */
int hash(char string[], int size) {

    int s = 0, k;

    for (k = 0; string[k] != '\0'; k++) {

        s = ((s << 1) + string[k]) % size;
    }

    return s;
}


/**
 * @brief next  データの登録位置を求める
 *
 * @param table     ハッシュ表の配列名(配列の先頭アドレス)
 * @param size      ハッシュ表の大きさ(配列の要素の個数)
 * @param string    登録したいデータ(文字列の先頭アドレス)
 * @return int      登録できるときはその位置を表す0以上の値、登録できない時は-1
 */
int next(char* table[], int size, char string[]) {

    int n, k;

    // ハッシュ値を計算する
    k = n = hash(string, size);
    do {
        // table[k]が未使用ならkを結果として返す
        if (table[k] == NULL) return k;

        // table[k]とstringが等しい場合は、kを結果として返す
        if (strcmp(table[k], string) == 0) return k;

        // (k+1)をsizeで割った余りをkに求める(ハッシュの最後まで到達したらハッシュの先頭に戻るため)
        k = (k + 1) % size;

    } while (k != n);

    return -1;
}



/**
 * @brief make     データを登録する
 *
 * @param table     ハッシュ表の配列名(配列の先頭アドレス)
 * @param size      ハッシュ表の大きさ(配列の要素の個数)
 * @param buf       登録したいデータ(文字列の先頭アドレス)
 * @return int      登録したとき、あるいは、すでに登録されているときは0、登録できない時は1
 */
int make(char* table[], int size, char buf[]) {

    int ret_code = 0;
    char* p = NULL;


    // データの登録位置を求める
    int k = next(table, size, buf);

    if (k >= 0) {
        // データの登録位置の値が0以上の場合

        if (table[k] == NULL) {
            // table[k]が未使用である

            // bufの文字列をコピーできるだけの大きさを持った記憶領域を動的に確保する
            char* p = (char*)malloc(strlen(buf) + 1);

            if (p == NULL) {
                // 動的な確保に失敗したときはret_code = 1を返す
                ret_code = 1;
            }
            else {

                // 上で動的に確保した領域にbufデータをコピーする
                strcpy_s(p, strlen(buf) + 1, buf);

                // コピー後のアドレスをtable[k]に代入する
                table[k] = p;
            }
        }

    }
    else {
        ret_code = 1;
    }

    return ret_code;
}


/**
 * @brief search データをサーチする
 *
 * @param table     ハッシュ表の配列名(配列の先頭アドレス)
 * @param size      ハッシュ表の大きさ(配列の要素の個数)
 * @param string    サーチしたいデータ(文字列の先頭アドレス)
 * @return int      サーチしたいデータが存在するときは、その要素の位置を表す0以上の値(配列の添え字の値)
                    サーチしたいデータが見つからないときは-1を返す
 */
int search(char* table[], int size, char string[]) {

    int n, k;

    // ハッシュ値を計算する
    k = n = hash(string, size);

    do {
        // table[k]が未使用ならstringの文字列は登録されていないので-1を返す
        if (table[k] == NULL) return -1;

        // table[k]の文字列とstringの文字列が等しい場合、kを返す
        if (strcmp(table[k], string) == 0) return k;

        // (k+1)をsizeで割った余りをkに求める(ハッシュの最後まで到達したらハッシュの先頭に戻るため)
        k = (k + 1) % size;


    } while (k != n);

    return -1;
}
