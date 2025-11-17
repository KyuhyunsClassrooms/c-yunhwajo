#include <stdio.h>
#include <stdbool.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct CircuitInput {
    bool A;
    bool B;
    bool C;
};

struct CircuitOutput {
    bool X;
    bool Y;
};

struct CircuitInput getValidInput() {
    struct CircuitInput input;
    int a, b, c;

    while (1) {
        printf("A, B, C 입력 (0 또는 1): ");
        scanf("%d %d %d", &a, &b, &c);

        if ((a == 0 || a == 1) &&
            (b == 0 || b == 1) &&
            (c == 0 || c == 1)) {

            input.A = a;
            input.B = b;
            input.C = c;
            clearBuffer();
            return input;
        }

        printf("잘못된 입력입니다. A, B, C는 0 또는 1이어야 합니다.\n");
        clearBuffer();
    }
}

struct CircuitOutput compute(struct CircuitInput in) {
    struct CircuitOutput out;

    bool X1 = in.A && in.B;
    bool X2 = (!in.B) && in.C;
    out.X = X1 || X2;

    bool Y1 = in.A || in.C;
    out.Y = Y1 && (!in.B);

    return out;
}

void printOutput(struct CircuitOutput out) {
    printf("X = %d\n", out.X);
    printf("Y = %d\n", out.Y);
}

int main() {
    char choice;

    do {
        struct CircuitInput input = getValidInput();
        struct CircuitOutput output = compute(input);
        printOutput(output);

        printf("다시 실행할까요? (y/n): ");
        scanf(" %c", &choice);
        clearBuffer();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

