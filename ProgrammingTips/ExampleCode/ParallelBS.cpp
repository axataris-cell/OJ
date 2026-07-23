Lặp lại log(Q) lần:
    reset cấu trúc dữ liệu
    reset mảng check

    với mỗi cặp l[i], r[i] mà l[i] < r[i]:
        mid = (l[i] + r[i]) / 2
        thêm i vào check[mid]

    với mỗi cập nhật thứ q:
        thực hiện cập nhật thứ q vào cấu trúc dữ liệu
        với mỗi giá trị i thuộc check[q]:
            // thực hiện kiểm tra trên cấu trúc dữ liệu
            nếu điều kiện thứ i được thỏa mãn:
                r[i] = q
            nếu không:
                l[i] = q + 1