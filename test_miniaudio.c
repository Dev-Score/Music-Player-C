#include <stdio.h>
#include <miniaudio.h>

int main() {
    ma_context context;
    ma_result result = ma_context_init(NULL, 0, NULL, &context);
    if (result != MA_SUCCESS) {
        printf("miniaudio initialization failed\n");
        return -1;
    }

    printf("miniaudio is installed and initialized successfully!\n");

    ma_context_uninit(&context);
    return 0;
}
