# Project_DSA

**Job Sequencing with Deadlines**

***1.	Mô tả bài toán***

Phương pháp sắp xếp công việc theo thời hạn (Job Sequencing with Deadlines) là một vấn đề tối ưu hóa trong cấu trúc dữ liệu và giải thuật, thường được sử dụng để tìm cách xếp lịch thực hiện các công việc sao cho tổng giá trị (profit) thu được là lớn nhất. Đây là một bài toán điển hình trong lập lịch (scheduling) và thường được giải quyết bằng các chiến lược tham lam (greedy).

***2. Mô tả giải thuật***

Bước 1: Sắp xếp các công việc theo lợi nhuận giảm dần.
        Mục tiêu là tối ưu hóa lợi nhuận bằng cách ưu tiên các công việc có lợi nhuận cao trước.

Bước 2: Duyệt qua từng công việc trong danh sách đã sắp xếp.
    for i = 1 to n do

Bước 3: Xác định vị trí slot tối đa có thể thực hiện công việc.
        Đặt k = min(dmax, DEADLINE(i))  // DEADLINE(i) là deadline của công việc thứ i

Bước 4: Kiểm tra các slot từ k về 1 để tìm slot trống.
        while k >= 1 do

Bước 5: Nếu slot trống, gán công việc vào slot và dừng vòng lặp.
            if timeslot[k] là EMPTY then
                timeslot[k] = job(i)  // Gán công việc thứ i vào timeslot k
                break
            endif

Bước 6: Nếu không tìm thấy slot trống, giảm k xuống 1 để kiểm tra slot trước đó.
            Đặt k = k - 1  // Giảm k xuống 1 để kiểm tra slot trước đó
        endwhile

    endfor

Sau khi hoàn thành: timeslot chứa danh sách các công việc được chọn, tối ưu lợi nhuận.

***3. Mã giả***

```plaintext
for i = 1 to n do
  Đặt k = min(dmax, DEADLINE(i))  // DEADLINE(i) là deadline của công việc thứ i

  while k >= 1 do
    if timeslot[k] là EMPTY then
      timeslot[k] = job(i)  // Gán công việc thứ i vào timeslot k
      break
    endif

    Đặt k = k - 1  // Giảm k xuống 1 để kiểm tra slot trước đó

  endwhile

endfor
```

***4. Độ phức tạp***

Việc sắp xếp thực hiện 𝑂(𝑛log𝑛), trong đó 𝑛 là số lượng công việc.
Tìm một vị trí trống cho mỗi công việc: Đối với mỗi công việc, trong trường hợp xấu nhất, chúng ta có thể cần kiểm tra n vị trí. O(n) này cho mỗi công việc, vì vậy n công việc, nó là O(n^2).
-> Độ phức tạp thời gian của bài toán này là O(n^2).
Không gian phụ trợ: O(N) của mảng kết quả và mảng slot