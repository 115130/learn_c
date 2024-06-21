#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void handle_sigalrm(int sig) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    // 使用\r回到行首，并更新时间显示，不换行
    printf("\rCurrent time: %02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);
    fflush(stdout); // 确保输出立即刷新

    // 重新设置alarm，每隔1秒触发一次
    alarm(1);
}

int main() {
    // 设置信号处理函数
    signal(SIGALRM, handle_sigalrm);

    // 首次设置alarm，1秒后触发
    alarm(1);

    // 使程序持续运行，等待信号处理
    while(1) {
        pause();  // 等待下一个信号到来
    }

    return 0;
}
