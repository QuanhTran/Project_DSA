// ====================== Mô tả bài toán sắp xếp công việc theo deadlines ==========================
/*
Có n công việc với các deadline {d1, d2, ..., dn} (di >= 0). 
Mỗi công việc i có lợi nhuận {p1, p2, ..., pn} (pi >= 0).
Nếu công việc ji được thực hiện trong deadline của nó, thì chỉ khi đó lợi nhuận của nó mới được tính vào.
Nhiệm vụ của chúng ta là tối đa hóa tổng lợi nhuận và tìm ra thứ tự thực hiện các công việc tối ưu.

Ví dụ, xét các công việc sau:
   J1  J2  J3  J4 J5
P  20  15  10  5  1
D  2   2   1   3  3

{J2, J1, J4} là thứ tự tối ưu để thực hiện các công việc và tổng lợi nhuận tối đa là 40.  
Giải pháp:

Phương pháp tham lam (greedy) thường được sử dụng để giải quyết bài toán này.
Bước 1: Sắp xếp các công việc theo thứ tự giảm dần của lợi nhuận.
Bước 2: Lần lượt chọn các công việc và kiểm tra xem có slot nào trống trước deadline hay không. Nếu có:
    - Phân công slot trống cuối cùng có sẵn và cộng lợi nhuận của công việc vào tổng lợi nhuận.
    - Thêm công việc vào slot trống đó.
Nếu không tìm thấy slot trống thì bỏ qua công việc này.
*/

// ====================== Code C ==========================

#include <stdio.h>
#include <stdlib.h>

// Cấu trúc lưu trữ thông tin công việc (số hiệu công việc, deadline, lợi nhuận)
typedef struct CongViec {
    int so;         // Số hiệu công việc
    int deadline;   // Deadline của công việc
    int loiNhuan;   // Lợi nhuận của công việc
} CongViec;

// Hàm tìm công việc có lợi nhuận cao nhất chưa được xét
int CongViecLoiNhuanCaoNhat(CongViec *congViec, int *daXet, int n) {
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!daXet[i] && (maxIndex == -1 || congViec[i].loiNhuan > congViec[maxIndex].loiNhuan)) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int n, t, i, tongLoiNhuan = 0;

    // Nhập số lượng công việc
    printf("Nhập số lượng công việc: ");
    scanf("%d", &n);

    // Khởi tạo mảng công việc
    CongViec *congViec = (CongViec *)malloc(n * sizeof(CongViec));
    int *daXet = (int *)malloc(n * sizeof(int));

    // Nhập deadline và lợi nhuận của từng công việc
    printf("Nhập deadline và lợi nhuận của từng công việc:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &congViec[i].deadline, &congViec[i].loiNhuan);
        congViec[i].so = i + 1;
        daXet[i] = 0;
    }

    // Tìm deadline lớn nhất
    int maxDeadline = congViec[0].deadline;
    for (int i = 1; i < n; i++) {
        if (maxDeadline < congViec[i].deadline) {
            maxDeadline = congViec[i].deadline;
        }
    }

    // Khởi tạo mảng slot để lưu thứ tự công việc
    int *slots = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = 0;
    }

    printf("Tổng lợi nhuận sau từng bước:\n");
    i = 1;
    while (i <= n) {
        // Tìm công việc có lợi nhuận cao nhất chưa được xét
        int maxIndex = CongViecLoiNhuanCaoNhat(congViec, daXet, n);
        daXet[maxIndex] = 1;

        // Tìm slot trống gần deadline nhất
        t = congViec[maxIndex].deadline - 1;
        while (t >= 0 && slots[t]) {
            t--;
        }

        // Nếu tìm được slot trống thì phân công công việc vào slot và cộng lợi nhuận
        if (t >= 0 && !slots[t]) {
            slots[t] = congViec[maxIndex].so;
            tongLoiNhuan += congViec[maxIndex].loiNhuan;
        }

        printf("%d\n", tongLoiNhuan);
        i++;
    }

    printf("Tổng lợi nhuận tối đa: %d\n", tongLoiNhuan);
    printf("Thứ tự thực hiện công việc tối ưu:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i]) {
            printf(" %d ", slots[i]);
        }
    }

    // Giải phóng bộ nhớ
    free(congViec);
    free(daXet);
    free(slots);

    return 0;
}
