#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *intArray2Str(int *a, int size);
static int *str2IntArray(char *str);
static char *mul(char *str1, char *str2);
static char *raisePower(char *base, int power);

int main(void) {
    char base[7], *result, *number;
    int power, i, fraction, trailZeros, j, len;
    int hasDot = 1;
    while (fscanf(stdin, "%s %d", base, &power) != EOF) {
        hasDot = 1;
        number = malloc(7);
        i = 0;
        j = 0;
        while (base[i] == '0') {
            i++;
        }
        for (; base[i] != '.' && base[i]; i++) {
            number[j++] = base[i];
        }
        if (!base[i]) {
            hasDot = 0;
        }
        fraction = i;
        for (; base[i]; i++) {
            number[j++] = base[i + 1];
        }
        fraction = i - fraction - 1;
        result = raisePower(number, power);
        len = strlen(result);
        i = len - 1;
        trailZeros = 0;
        while (result[i] == '0') {
            i--;
            trailZeros++;
        }
        fraction *= power;
        if (!hasDot) {
            trailZeros = 0;
            fraction = 0;
        }
        if (fraction <= len) {
            for (i = 0; i < len - fraction; i++) {
                printf("%c", result[i]);
            }
            if (i < len - trailZeros) {
                printf(".");
            }
            for (; i < len - trailZeros; i++) {
                printf("%c", result[i]);
            }
            printf("\n");
        }
        else {
            printf(".");
            for (i = 0; i < fraction - len; i++) {
                printf("0");
            }
            for (i = 0; i < len - trailZeros; i++) {
                printf("%c", result[i]);
            }
            printf("\n");
        }
        free(result);
        free(number);
    }
    return 0;
}
static char *mul(char *str1, char *str2) {
    int len1, len2, *data1, *data2, *result, len, carry, i, j;
    len1 = strlen(str1);
    len2 = strlen(str2);
    len = len1 + len2;
    data1 = str2IntArray(str1);
    data2 = str2IntArray(str2);
    result = malloc(len * sizeof(int));
    for (i = 0; i < len; i++) {
        result[i] = 0;
    }
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            result[i + j] += data1[i] * data2[j];
        }
    }
    carry = 0;
    for (i = 0; i < len; i++) {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    free(data1);
    free(data2);
    return intArray2Str(result, len);
}

static char *raisePower(char *base, int power) {
    if (power == 0) {
        return "1";
    }
    else if (power == 1) {
        return base;
    }
    if (power % 2 != 0) {
        return mul(raisePower(mul(base, base), power / 2), base);
    }
    else {
        return raisePower(mul(base, base), power / 2);
    }
}

static char *intArray2Str(int *a, int size) {
    int i = size - 1;
    char *result;
    int j;
    while (a[i] == 0) {
        i--;
    }
    size = i + 1;
    result = malloc(size + 1);
    for (i = size - 1, j = 0; i >= 0; i--, j++) {
        result[j] = a[i] + '0';
    }
    result[j] = '\0';
    free(a);
    return result;
}

static int *str2IntArray(char *str) {
    int len = strlen(str);
    int *a = malloc(len * sizeof(int));
    int j, i = len - 1;
    for (j = 0; i >= 0; i--, j++) {
        a[j] = str[i] - '0';
    }

    return a;
}