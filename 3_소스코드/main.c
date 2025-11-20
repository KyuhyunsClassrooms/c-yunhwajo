#include <stdio.h>

int main() {
    int A, B, C;
    char choice;

    printf("🎔 논리 회로 시뮬레이터 🎔\n");
    printf("이 프로그램은 A B C의 세 가지 값을 입력받아\n");
    printf("논리 연산을 이용해 두 개의 출력 X와 Y를 계산합니다.\n\n");

    printf("<사용 방법>\n");
    printf("A, B, C에 0 또는 1을 입력하세요!\n");
    printf("다음 논리식에 따라 X와 Y가 계산됩니다:\n");
    printf("  X = (A AND B) OR (NOT B AND C)\n");
    printf("  Y = (A OR C) AND (NOT B)\n");
    printf("반드시 띄어쓰기를 지켜주세요!\n\n");

    do {
        printf("A B C 입력 (각각 0 또는 1): ");
        scanf("%d %d %d", &A, &B, &C);

        if ((A != 0 && A != 1) || (B != 0 && B != 1) || (C != 0 && C != 1)) {
            printf("잘못된 입력입니다! 0 또는 1만 입력해주세요.\n\n");
            continue;
        }

        int X = (A && B) || ((!B) && C);
        int Y = (A || C) && (!B);

        printf("\n=== 결과 ===\n");
        printf("X = %d\n", X);
        printf("Y = %d\n\n", Y);

        printf("다시 실행할까요? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    printf("프로그램을 종료합니다.\n");
    return 0;
}
